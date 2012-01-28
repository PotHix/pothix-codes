class Dog
  def initialize(dogName)
    @dogName = dogName
  end
  
  def bark()
    puts "Ruff! Ruff!"
  end
  
  def eat()
    puts "ruzzzzzzz!"
  end
  
  def chase_cat(catName)
    puts "You: #{@dogName}! Chase #{catName}!"
    puts "#{@dogName}: Ruuuuffff!"
  end
end

d = Dog.new('Nino')
d.bark
puts "-----" #just a separator
d.chase_cat('biao')
puts "-----" #just a separator
d.eat