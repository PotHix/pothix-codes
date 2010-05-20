require 'thread'
 
class Dangerous
  def initialize
    @a, @b, @c = 0, 0, 0
	@lock = Mutex.new
  end
  
  def m
    @lock.synchronize do
      a = 2; b = 3; c = 4
      puts "a = #{a}, b = #{b}, c = #{c}"
      b = 30; c = 40; a = 20
      puts "a = #{a}, b = #{b}, c = #{c}"
	end
  end
end
 
d = Dangerous.new
Thread.new { d.m }
Thread.new { d.m }