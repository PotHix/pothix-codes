require 'spec_helper'

describe KillEvent do
  should_belong_to :gun

  should_belong_to :killer, :class_name => "Player", :foreign_key => :killer_id
  should_belong_to :frag,   :class_name => "Player", :foreign_key => :frag_id
end
