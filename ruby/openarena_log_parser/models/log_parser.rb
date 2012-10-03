class LogParser
  AWARDPATTERN    = /^.*Award.* (.*) gained the (.*) award/
  INITGAMEPATTERN = //
  KILLPATTERN     = /^.*Kill.* (.*) killed (.*) by (.*)/
  SCOREPATTERN    = /^.*score.*\s(\d*.)  ping. \d.* client. \d.* (.*)/

  class << self
    def parse file_path
      file = File.open(file_path)
      file.each do |file_line|
        read_and_distinguish file_line.to_s
      end
    end

    def read_and_distinguish(file_line)
      if kill?(file_line)
        kill_info = kill_informations_for(file_line)

        KillEvent.create!(
          :killer => player_by(kill_info[:killer]),
          :frag   => player_by(kill_info[:frag]),
          :gun    => gun_by(kill_info[:gun])
        )

      elsif award?(file_line)
        award_info = award_informations_for(file_line)

        AwardEvent.create!(
          :player   => player_by(award_info[:award_receiver]),
          :award    => award_by(award_info[:award])
        )

      elsif score?(file_line)
        true
      end
    end

    def award_informations_for line
      result = line.match(AWARDPATTERN)
      {:award_receiver => result[1], :award => result[2]}
    end

    def kill_informations_for line
      result = line.match(KILLPATTERN)
      {:killer => result[1], :frag => result[2], :gun => result[3]}
    end

    def score_informations_for line
      result = line.match(SCOREPATTERN)
      {:score => result[1], :player => result[2]}
    end

    def init_game? line
      !!line.match(INITGAMEPATTERN)
    end

    def kill? line
      !!line.match(KILLPATTERN)
    end

    def award? line
      !!line.match(AWARDPATTERN)
    end

    def score? line
      !!line.match(SCOREPATTERN)
    end

    def player_by player_name
      Player.find_by_name(player_name)|| Player.create!(:name => player_name)
    end

    def gun_by gun_mod_name
      Gun.find_by_mod_name(gun_mod_name)|| Gun.create!(:name => gun_mod_name)
    end

    def award_by award_name
      Award.find_by_name(award_name)|| Award.create!(:name => award_name)
    end
  end
end
