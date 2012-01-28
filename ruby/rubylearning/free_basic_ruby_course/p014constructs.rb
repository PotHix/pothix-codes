# In Ruby, nil and false evaluate to false,  
# everything else (including true, 0) means true  
# nil is an actual object  
# if else end  
var = 5  
if var > 4  
  puts "Variable is greater than 4"  
  puts "I can have multiple statements here"  
  if var == 5  
    puts "Nested if else possible"  
  else  
   puts "Too cool"  
  end  
else  
 puts "Variable is not greater than 5"  
 puts "I can have multiple statements here"  
end  