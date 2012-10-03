require 'spec_helper'

describe Score do
  should_belong_to :game
  should_belong_to :player

  it "should create a new instance given valid attributes" do
    Score.create!(:game_id => 1, :player_id => 1, :score => 1)
  end
end
