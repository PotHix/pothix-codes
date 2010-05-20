# p063xself1.rb  
class S  
  puts 'Just started class S'  
  puts self  
  module M  
    puts 'Nested module S::M'  
     puts self  
  end  
  puts 'Back in the outer level of S'  
  puts self  
end