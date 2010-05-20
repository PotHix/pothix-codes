#!C:\ruby\bin\ruby.exe
# web_server02.rb
# Lesson 12 Exercise 01

require 'socket'
require 'CGI'
server = TCPServer.new('localhost', 12321)

def convert(temperatureFahrenheit)
  t = Time.now  
  result=(32+(9.0/5)*temperatureFahrenheit.to_f)
  "input #{temperatureFahrenheit} Fahrenheit output #{result} Centigrade on #{t}."
end

while (session = server.accept)
  request = session.gets
  puts request
  index = request.index("convert=") + 8
  index2 = request.index(" HTTP")
  query = request[index..index2]
  # puts query
  answer = CGI.unescape(convert(query.to_f))
  session.print "HTTP/1.1 200/OK\rContent-type: text/xml\r\n\r\n"
  session.puts "#{answer}"
  session.close
end

