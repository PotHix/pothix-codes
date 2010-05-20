# You can provide parameters to the call to yield:  
# these will be passed to the block  
def call_block  
  yield('hello', 99)  
end  
call_block {|str, num| puts str + ' ' + num.to_s}