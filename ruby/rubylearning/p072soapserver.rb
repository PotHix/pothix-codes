require 'logger'  
require 'soap/rpc/standaloneServer'  
class MyServer < SOAP::RPC::StandaloneServer  
  def initialize(* args)  
    super  
    add_method(self, 'sayhelloto', 'username')  
    #create a log file  
    @log = Logger.new("soapserver.log", 5, 10*1024)  
  end  
  def sayhelloto(username)  
    t = Time.now  
    @log.info("#{username} logged on #{t}")  
    "Hello, #{username} on #{t}."  
  end  
end  
  
server = MyServer.new('RubyLearningServer','urn:mySoapServer','localhost',12321)  
trap('INT') {server.shutdown}  
server.start