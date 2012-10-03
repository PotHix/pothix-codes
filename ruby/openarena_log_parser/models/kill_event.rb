class KillEvent < ActiveRecord::Base
  belongs_to :gun

  belongs_to :killer, :class_name => "Player", :foreign_key => :killer_id
  belongs_to :frag,   :class_name => "Player", :foreign_key => :frag_id
end
