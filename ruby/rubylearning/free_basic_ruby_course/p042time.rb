t = Time.now  
# to get day, month and year with century  
# also hour, minute and second  
puts t.strftime("%d/%m/%Y %H:%M:%S")  
  
# You can use the upper case A and B to get the full  
# name of the weekday and month, respectively  
puts t.strftime("%A")  
puts t.strftime("%B")  
  
# You can use the lower case a and b to get the abbreviated  
# name of the weekday and month, respectively  
puts t.strftime("%a")  
puts t.strftime("%b")  
  
# 24 hour clock and Time zone name  
puts t.strftime("at %H:%M %Z")  