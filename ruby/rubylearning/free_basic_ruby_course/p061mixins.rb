# p061mixins.rb  
module D  
  def initialize(name)  
    @name =name  
  end  
  def to_s  
    @name  
  end  
end  
  
module Debug  
  include D  
  # Methods that act as queries are often  
  # named with a trailing ?  
  def who_am_i?  
    "#{self.class.name} (\##{self.object_id}): #{self.to_s}"  
  end  
end  
  
class Phonograph  
  # the include statement simply makes a reference to a named module  
 # If that module is in a separate file, use require to drag the file in  
  # before using include  
  include Debug  
   # ...  
end  
  
class EightTrack  
  include Debug  
  # ...  
end  
  
ph = Phonograph.new("West End Blues")  
et = EightTrack.new("Real Pillow")  
puts ph.who_am_i?  
puts et.who_am_i?