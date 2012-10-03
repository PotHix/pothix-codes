class AwardEvent < ActiveRecord::Base
  belongs_to :player
  belongs_to :award
end
