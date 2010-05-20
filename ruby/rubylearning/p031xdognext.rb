require 'p029dog.rb'  
# define class Dog  
class Dog  
  def big_bark  
    puts 'Woof! Woof!'  
  end  
end  
# make an object  
d = Dog.new('Labrador', 'Benzy')  
d.bark  
d.big_bark  
d.display  