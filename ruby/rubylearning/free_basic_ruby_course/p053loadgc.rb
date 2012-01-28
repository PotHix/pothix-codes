# p053loadgc.rb  
require 'p051gamecharacters.rb'  
File.open('game') do |f|  
  @gc = Marshal.load(f)  
end  
  
puts @gc.power.to_s + ' ' + @gc.type + ' '  
@gc.weapons.each do |w|  
  puts w + ' '  
end