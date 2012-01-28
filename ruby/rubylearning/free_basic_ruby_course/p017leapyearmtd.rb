def anobiss(ano)
  result= ( ano % 4 == 0 or ano % 400 == 0 and ano %  100 != 0 ) ? "Is a Leap Year and have #{366*24*60} minutes" : "Is not a Leap Year and Have #{365*24*60} minutes"
  puts result
end

puts "Input a year:"
STDOUT.flush
anobiss(gets.to_i)