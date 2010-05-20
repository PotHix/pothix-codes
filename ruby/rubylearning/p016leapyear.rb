def anobiss(ano)
  result= ( ano % 4 == 0 or ano % 400 == 0 and 100 != 0 ) ? "Leap Year!" : "Not Leap Year!"
  puts result
end

puts "Input a year:"
STDOUT.flush
anobiss(gets.to_i)