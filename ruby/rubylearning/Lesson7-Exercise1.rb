class Person
  attr_reader :balance
  alias :show_bal :balance #Stealing the Satoshi's idea! Very good Satoshi!
  def initialize(balance = 0)
    show_balance(balance)
  end
  
  def show_balance(add)
    @balance == nil ? @balance = 0 
    @balance += add
  end
end

#Using what Satish says on the exercise
p = Person.new(40000)
p.show_bal(5)
puts p.show_bal # calling the method