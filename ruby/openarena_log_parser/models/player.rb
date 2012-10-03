class Player < ActiveRecord::Base
  has_many :scores
  has_many :award_events
end
