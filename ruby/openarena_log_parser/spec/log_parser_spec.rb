require File.expand_path(File.dirname(__FILE__) + '/../spec_helper')

describe LogParser do
  KILL     = "  0:48 Kill: 0 2 10: PotHix killed NovoHomem by MOD_RAILGUN"
  AWARD    = "  0:46 Award: 0 2: PotHix gained the IMPRESSIVE award!"
  SCORE    = " 11:15 score: 20  ping: 0  client: 0 PotHix"
  INITGAME = " 11:16 InitGame: \dmflags\0\fraglimit\0\timelimit\30\sv_hostname\ikwa\sv_maxclients\6\sv_minRate\0\sv_maxRate\0\sv_minPing\0\sv_maxPing\0\sv_floodProtect\1\g_redTeam\Stroggs\g_blueTeam\Pagans\g_maxGameClients\0\capturelimit\8\g_delagHitscan\0\elimination_roundtime\90\elimination_ctf_oneway\0\version\ioq3+oa 1.35 linux-i386 May  2 2009\g_gametype\4\protocol\71\mapname\OA_CTF2\sv_privateClients\0\sv_allowDownload\0\bot_minplayers\0\g_instantgib\0\g_rockets\0\gamename\baseoa\g_needpass\0\g_obeliskRespawnDelay\10\g_humanplayers\4"

  it 'should return killer, frag and gun for a line' do
    result = {:killer => 'PotHix', :frag => 'NovoHomem', :gun => 'MOD_RAILGUN'}
      
    LogParser.kill_informations_for(KILL).should == result
  end

  it 'should return award_receiver and award' do
    result = {:award_receiver => 'PotHix', :award => 'IMPRESSIVE'}
    LogParser.award_informations_for(AWARD).should == result
  end

  it 'should return the player and his score' do
    result = {:score => '20', :player => 'PotHix'}
    LogParser.score_informations_for(SCORE).should == result
  end

  context 'when verifying if a log line is refering to a kill event' do
    it 'should return true for a line refering to a kill event' do
      LogParser.kill?(KILL).should be_true
    end

    it 'should return false for a line refering to a award event' do
      LogParser.kill?(AWARD).should be_false
    end
  end

  context 'when verifying if a log line is refering to an award event' do
    it 'should return true for a line refering to a award event' do
      LogParser.award?(AWARD).should be_true
    end

    it 'should return false for a line refering to a kill event' do
      LogParser.award?(KILL).should be_false
    end
  end

  context 'when verifying if a log line is refering to a score event' do
    it 'should return true for a line refering to a score event' do
      LogParser.score?(SCORE).should be_true
    end

    it 'should return false for a line refering to a kill event' do
      LogParser.score?(KILL).should be_false
    end
  end

  context 'when parsing player log data' do
    it 'should create a player if he not exist in database' do
      player_name = 'PotHix'
      Player.expects(:find_by_name).with(player_name).returns(nil)
      LogParser.player_by(player_name).name.should == player_name
    end

    it 'should return the correct player from database' do
      player_name = 'Mateus'
      player_instance = mock_model(Player, :name => player_name)
      Player.expects(:find_by_name).with(player_name).returns(player_instance)
      LogParser.player_by(player_name).name.should == player_name
    end
  end

  context 'when parsing gun log data' do
    it 'should create a gun if it not exist in database' do
      gun_mod_name = 'MOD_RAILGUN'
      Gun.expects(:find_by_mod_name).with(gun_mod_name).returns(nil)
      LogParser.gun_by(gun_mod_name).name.should == gun_mod_name
    end

    it 'should return the correct gun from database' do
      gun_mod_name = 'MOD_SHOTGUN'
      gun_instance = mock_model(Gun, :name => gun_mod_name)
      Gun.expects(:find_by_mod_name).with(gun_mod_name).returns(gun_instance)
      LogParser.gun_by(gun_mod_name).name.should == gun_mod_name
    end
  end

  context 'when parsing award log data' do
    it 'should create an award if it not exist in database' do
      award_name = 'IMPRESSIVE'
      Award.expects(:find_by_name).with(award_name).returns(nil)
      LogParser.award_by(award_name).name.should == award_name
    end

    it 'should return the correct award from database' do
      award_name = 'IMPRESSIVE'
      gun_instance = mock_model(Award, :name => award_name)
      Award.expects(:find_by_name).with(award_name).returns(gun_instance)
      LogParser.award_by(award_name).name.should == award_name
    end
  end

  it 'should save a KillEvent register on database for a kill log line' do
    LogParser.read_and_distinguish(KILL)

    KillEvent.last.killer.name.should == 'PotHix'
    KillEvent.last.frag.name.should   == 'NovoHomem'
    KillEvent.last.gun.name.should    == 'MOD_RAILGUN'
  end

  it 'should save a AwardEvent register on database for a award log line' do
    LogParser.read_and_distinguish(AWARD)

    AwardEvent.last.player.name.should == 'PotHix'
    AwardEvent.last.award.name.should  == 'IMPRESSIVE'
  end
end
