require File.expand_path(File.dirname(__FILE__) + '/../lib/morse_code')
STDOUT.sync = TRUE

morse = MorseConverter.new

puts 'Converting from morse to plain text:'
puts morse.to_plain("-- --- .-. ... . / -.-. --- -.. . / - .... . / -. . .-- / -.. . .- -.. / .-.. .- -. --. ..- .- --. . .-.-.-")
puts morse.to_plain("--- -- --.  .. ...  -- --- .-. ... .  -.-. --- -..")
puts morse.to_plain("- .-- . . - ... / .- .-. . / . ...- . -. / ... .... --- .-. - . .-. / .-- .. - .... / -- --- .-. ... . / -.-. --- -..")
puts morse.to_plain("-- --- .-. ... .   -.-. --- -.. .   .. ...   -... .- -..   ..-. --- .-.   - .-- . . - .. -. --")
puts morse.to_plain(".. - /  .. ... /  .- /  .--. .-.. . .- ... ..- .-. . /  - --- /  -- . . - /  -.-- --- ..- /  .- ... /  .-- . .-.. .-.")
puts

# testing syntactic sugar
puts 'Syntactic sugar for converting single words to morse:'
puts morse.to_morse('RubyLearning')
puts morse.rubylearning
puts

puts 'Converting to morse:'
mc = morse.to_morse('HAHAHA Interesting! Thx PotHix.')
puts mc
puts morse.to_plain(mc)
input = 'nil'
puts "Type in what you would like to have converted to morse (type quit to exit)."

until input.chomp == 'quit'
  input = gets
  puts input
  puts morse.to_morse(input)
end

