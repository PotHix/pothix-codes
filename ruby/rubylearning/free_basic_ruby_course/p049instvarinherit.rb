# p049instvarinherit.rb  
class C  
  def initialize  
    @n = 100  
  end  
  
  def increase_n  
    @n *= 20  
  end  
end  
  
class D < C  
  def show_n  
    puts "n is #{@n}"  
  end  
end  
  
d = D.new  
d.increase_n  
d.show_n  