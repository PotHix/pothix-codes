# p069dtclient.rb  
require 'socket'  
streamSock = TCPSocket.new( "127.0.0.1", 20000 )  
#streamSock.send( "Hello\n" )  
str = streamSock.recv( 100 )  
print str  
streamSock.close