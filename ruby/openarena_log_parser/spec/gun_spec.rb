require 'spec_helper'

describe Gun do
  should_have_many :kill_events

  it "should create a new instance given valid attributes" do
    Gun.create!(:name => "rocket launcher")
  end
end
