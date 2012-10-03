require File.expand_path(File.dirname(__FILE__) + '/../lib/morse_code')
STDOUT.sync = TRUE

morse = MorseConverter.new
input = 'Initial string'
puts "Type in a phrase in either morse code or plain text (plain text not starting with a - or .)"

input = gets
until input =~ /^quit$/
  if input[0] == '.' or input[0] == '-' then
    puts morse.to_plain(input)
  else
    puts morse.to_morse(input)
  end
  input = gets
end

