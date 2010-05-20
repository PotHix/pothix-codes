# define class Dog  
class Dog  
  def initialize(breed, name)  
    # Instance variables  
    @breed = breed  
    @name = name  
  end  
  
  def bark  
    puts 'Ruff! Ruff!'  
  end  
  
  def display  
    puts "I am of #{@breed} breed and my name is #{@name}"  
  end  
end  
  
# make an object  
# method new used to create object  
d = Dog.new('Labrador', 'Benzy')  
puts d.methods.sort  
puts "The id of obj is #{d.object_id}."  
  
if d.respond_to?("talk")  
  d.talk
else  
  puts "Sorry, the object doesn't understand the 'talk' message."  
 end  
  
d.bark  
d.display  
  
d1 = d  
d1.display  
 
d = nil  
d.display