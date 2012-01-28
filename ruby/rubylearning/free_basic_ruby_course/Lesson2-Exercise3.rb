def convert(f)
  c = 5.0*(f-32.0)/9.0
  puts "So...#{f.round} F is equal to #{"%.2f" % c} ºC"
end

puts "Input a temperature in Fahrenheit:"
STDOUT.flush
convert(gets.chomp.to_f)