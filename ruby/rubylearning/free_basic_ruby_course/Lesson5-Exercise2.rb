=begin
  r = Rectangle.new(23.45, 34.67)
  puts 'Area is = ' + r.area().to_s
  puts 'Perimeter is = ' + r.perimeter.to_s
=end

class Rectangle
  def initialize(b,h)
   @b = b
   @h = h
  end
  
  def area
    @b*@h
  end

  def perimeter
    2*@b + 2*@h
  end
end


r = Rectangle.new(23.45, 34.67)
puts 'Area is = ' + r.area().to_s
puts 'Perimeter is = ' + r.perimeter.to_s



#Exemplo interessante
=begin
class Rectangle
def initialize(width, height)
@area = width*height
@perimeter = 2*(width + height)
end

attr_reader :area, :perimeter
end
=end