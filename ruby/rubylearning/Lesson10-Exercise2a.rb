# -------------------------------------------
# Lesson10-Exercise2a.rb
# Fixed code
# -------------------------------------------

require 'Lesson10-Exercise2'

m = DTRConvertor.new
def m.convert(dollar_amount)
  dollar_amount * 38.0 # Bug here
end

puts m.convert(100.0)