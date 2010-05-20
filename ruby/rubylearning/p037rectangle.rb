# The Rectangle constructor accepts arguments in either  
# of the following forms:  
#   Rectangle.new([x_top, y_left], length, width)  
#   Rectangle.new([x_top, y_left], [x_bottom, y_right])  
 class Rectangle  
  def initialize(*args)  
    if args.size < 2  || args.size > 3  
      # modify this to raise exception, later  
      puts 'This method takes either 2 or 3 arguments'  
    else  
      if args.size == 2  
        puts 'Two arguments'  
      else  
        puts 'Three arguments'  
      end  
    end  
  end  
end  
Rectangle.new([10, 23], 4, 10)  
Rectangle.new([10, 23], [14, 13]) 