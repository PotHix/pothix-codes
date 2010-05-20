#!C:\ruby\bin\ruby.exe
# web_server01.rb
# Lesson 12 Exercise 01

require 'logger'  
require 'soap/rpc/standaloneServer'  
class MyServer < SOAP::RPC::StandaloneServer  
  def initialize(* args)  
    super  
    add_method(self, 'convert', 'temperatureFahrenheit')
    # create a log file  
    @log = Logger.new("soapserver.log", 5, 10*1024)  
  end  
  def convert(temperatureFahrenheit)
    t = Time.now  
    result = (32+(9.0/5)*temperatureFahrenheit)
    @log.info("logged on #{t} : class #{self.class.name} method #{self.object_id})/#{self.to_s} : input #{temperatureFahrenheit} Fahrenheit output #{result} Centigrade")  
    "input #{temperatureFahrenheit} Fahrenheit output #{result} Centigrade on #{t}."
  end  
end  
server = MyServer.new('RubyLearningServer','urn:mySoapServer','localhost',12321)  
trap('INT') {server.shutdown}  
server.start  
#----
#!C:\ruby\bin\ruby.exe
# web_client01.rb
# Lesson 12 Exercise 01

require 'soap/rpc/driver'  
driver = SOAP::RPC::Driver.new('http://127.0.0.1:12321/', 'urn:mySoapServer')  
driver.add_method('convert', 'temperatureFahrenheit')  
puts driver.convert(70)  
