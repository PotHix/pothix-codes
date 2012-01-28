# p055constalter.rb  
A_CONST = "Doshi"  
B_CONST = A_CONST  
A_CONST[0] = "J" # alter string referenced by constant  
puts A_CONST # displays Joshi  
puts B_CONST # also displays Joshi