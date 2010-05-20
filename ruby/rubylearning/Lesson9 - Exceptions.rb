class Name  
  # Define default getter methods, but not setter methods.  
  attr_reader :first, :last  
  # When someone tries to set a first name, enforce rules about it.  
  def first=(first)  
    if first == nil or first.size == 0  
      raise ArgumentError.new('Everyone must have a first name.')  
    end  
    first = first.dup  
    first[0] = first[0].chr.capitalize  
    @first = first  
  end  
  
  # When someone tries to set a last name, enforce rules about it.  
  def last=(last)  
    if last == nil or last.size == 0  
      raise ArgumentError.new('Everyone must have a last name.')  
    end  
    @last = last  
  end  
  
  def full_name  
    "#{@first} #{@last}"  
  end  
  # Delegate to the setter methods instead of setting the instance  
  # variables directly.  
  def initialize(first, last)  
    self.first = first  
    self.last = last  
  end  
end  
   
jacob = Name.new('Jacob', 'Berendes')  
jacob.first = 'Mary Sue'  
jacob.full_name # => "Mary Sue Berendes"  
john = Name.new('john', 'von Neumann')  
john.full_name # => "John von Neumann"  
john.first = 'john'  
john.first # => "John"  
john.first = nil  
# ArgumentError: Everyone must have a first name.  
Name.new('Kero, international football star and performance artist', nil)  
# ArgumentError: Everyone must have a last name.