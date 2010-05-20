=begin  
  Ruby Code blocks are chunks of code between braces or  
  between do- end that you can associate with method invocations  
=end  
def call_block  
  puts 'Start of method'  
  # you can call the block using the yield keyword  
  yield  
  yield  
  puts 'End of method'  
end  
# Code blocks may appear only in the source adjacent to a method call  
call_block {puts 'In the block'} 