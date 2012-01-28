# variable number of parameters example  
# The asterisk is actually taking all arguments you send to the method  
# and assigning them to an array named my_string as shown below  
# The do end is a Ruby block which we talk in length later  
def foo(*my_string)  
  my_string.each do |words|  
    puts words  
  end  
end  
foo('hello','world')  
foo()