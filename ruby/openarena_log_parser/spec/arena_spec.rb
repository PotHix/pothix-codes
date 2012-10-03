require 'spec_helper'

describe Arena do
  should_have_many :games

  it "should create a new instance given valid attributes" do
    Arena.create!(:name => "Valley of death")
  end
end
