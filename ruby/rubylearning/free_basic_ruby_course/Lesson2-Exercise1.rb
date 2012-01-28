=begin
#Convert de farenheight para Celsius
f = gets
c = 5*(f.to_f-32)/9
puts "Are #{"%.2f" % c} ºC"
=end

def convert(f)
  c = 5.0*(f.to_f-32.0)/9.0
  puts "So...Here we are on #{"%.2f" % c} ºC"
end

convert(gets)
