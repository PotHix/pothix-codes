# p063stuffusage.rb  
require 'p062stuff'     # loads Stuff module from Stuff.rb  
# $: is a system variable -- contains the path for loads  
class D  
  include Stuff     # refers to the loaded module  
  puts Stuff.m(4)  
end  
  
d = D.new  
puts d.p(5)         # method p from Stuff  
puts $:             # array of folders to search for load  
$: << "c:/"         # add a folder to the load path  
puts $:  
puts Stuff.m(5)     # Stuff class methods not called from D object