# p073prclient.rb  
require 'soap/rpc/driver'  
driver = SOAP::RPC::Driver.new('http://127.0.0.1:12321/', 'urn:mySoapServer')  
driver.add_method('sayhelloto', 'username')  
puts driver.sayhelloto('PotHix')