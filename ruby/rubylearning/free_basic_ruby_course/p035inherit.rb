class GF  
  @m =10  
  puts @m.object_id  
  def initialize  
    puts 'In GF class'  
  end  
  def gfmethod  
    puts 'GF method call'  
  end  
end  
  
# class F sub-class of GF  
class F < GF  
  def initialize  
    super  
    puts 'In F class'  
  end  
end  
 
# class S sub-class of F  
class S < F  
  def initialize  
    super  
    puts @m  
    puts @m.object_id  
    puts 'In S class'  
  end  
end  
son = S.new  
son.gfmethod  