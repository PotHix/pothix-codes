require 'logger'  
require 'soap/rpc/standaloneServer'  
class Server < SOAP::RPC::StandaloneServer
  def initialize(* args)
    super
    add_method(self,'convert','f')
    # create a log file
    @log = Logger.new("soapserver.log", 5, 10*1024)  
  end
  
  def convert(f) #Using my exercise 1 of lesson 2 ( modified )...=P
    c = 5.0*(f.to_f-32.0)/9.0
    @log.info("Logged on #{Time.now} - Class:#{self.class.name} - Inserted value:#{f} - Result:#{c}")    
    "#{f} converted to Celcius is #{"%.2f" % c}"
  end
end

server = Server.new('bestServer','urn:mySoapServer','localhost',12321)  
trap('INT') {server.shutdown}  
server.start 