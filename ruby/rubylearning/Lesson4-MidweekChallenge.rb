f = IO.readlines("text.txt") #seems more simply to me
text = ""
f.each do |line|
  text += line.chomp
end
puts "Number of lines: #{f.length}"
puts "Number of characters: #{text.size}"


=begin
# Código sugerido pelo Brad, pois meu código pode ser ineficaz para grandes arquivos
# But if you wanted to keep your code, with only a few updates
f=IO.readlines('text.txt')
# this is basically what you're doing now, but w/o the overhead of 
# rebuildnig the data file.
textSize = f.join.gsub("\n","").length
puts "Number of lines: #{f.length}"
puts "Number of characters: #{textSize}"
=end