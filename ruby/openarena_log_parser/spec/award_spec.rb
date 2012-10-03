require 'spec_helper'

describe Award do
  should_have_many :award_events

  it "should create a new instance given valid attributes" do
    Award.create!(:name => "IMPRESSIVE")
  end
end
