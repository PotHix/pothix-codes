# Blocks are not objects  
# they can be converted into objects of class Proc by calling lambda method  
prc = lambda {puts 'Hello'}  
# method call invokes the block  
prc.call  
  
# another example  
toast = lambda do  
  puts 'Cheers'  
end  
toast.call 