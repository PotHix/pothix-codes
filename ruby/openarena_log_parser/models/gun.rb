class Gun < ActiveRecord::Base
  has_many :kill_events
end
