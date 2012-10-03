class Game < ActiveRecord::Base
  belongs_to :arena
  has_many :scores
end
