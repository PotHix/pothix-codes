 p047zclassaccess.rb  
class Person  
  def initialize(age)  
    @age = age  
  end  
  def age  
    @age  
  end  
  def compare_age(c)  
    if c.age > age  
      "The other object's age is bigger."  
    else  
      "The other object's age is the same or smaller."  
    end  
  end  
  protected :age  
end  
  
chris = Person.new(25)  
marcos = Person.new(34)  
puts chris.compare_age(marcos)  
#puts chris.age  