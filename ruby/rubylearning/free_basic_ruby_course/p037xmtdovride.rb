class A  
  def a  
    puts 'In class A'  
  end  
end  
  
class B < A  
  def a  
    puts 'In class B'  
  end  
end  
  
b = B.new  
b.a  