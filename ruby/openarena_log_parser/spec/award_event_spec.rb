require 'spec_helper'

describe AwardEvent do
  should_belong_to :player
  should_belong_to :award

  it "should create a new instance given valid attributes" do
    AwardEvent.create!(:player_id => 1, :award_id => 1)
  end
end
