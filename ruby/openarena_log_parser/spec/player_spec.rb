require 'spec_helper'

describe Player do
  should_have_many :scores
  should_have_many :award_events

  it "should create a new instance given valid attributes" do
    Player.create!(:name => "PotHix", :description => "The best player ever")
  end
end
