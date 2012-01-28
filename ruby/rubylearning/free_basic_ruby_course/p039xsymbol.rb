class Test  
  puts :Test.object_id.to_s  
  def test  
   puts :test.object_id.to_s  
   @test = 10  
   puts :test.object_id.to_s  
  end  
end  
t = Test.new  
t.test  