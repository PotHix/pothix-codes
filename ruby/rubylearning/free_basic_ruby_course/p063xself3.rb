# p063xself3.rb  
obj = Object.new  
def obj.show  
  print 'I am an object: '  
  puts "here's self inside a singleton method of mine:"  
  puts self  
end  
obj.show  
print 'And inspecting obj from outside, ' 
puts "to be sure it's the same object:"  
puts obj