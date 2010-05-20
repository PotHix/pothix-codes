# p052dumpgc.rb  
require 'p051gamecharacters.rb'  
gc = GameCharacter.new(120, 'Magician', ['spells', 'invisibility'])  
puts gc.power.to_s + ' ' + gc.type + ' '  
gc.weapons.each do |w|  
  puts w + ' '  
end  
  
File.open('game', 'w+') do |f|  
  Marshal.dump(gc, f)  
end