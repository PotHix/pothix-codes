require 'spec_helper'

describe Game do
  should_belong_to :arena
  should_have_many :scores

  it "should create a new instance given valid attributes" do
    Game.create!(:duration_time => Time.now, :game_date => Date.today, :arena_id => 1)
  end
end
