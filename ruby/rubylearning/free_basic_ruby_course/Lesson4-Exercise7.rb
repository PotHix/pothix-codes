said = ""
while said != "BYE"
  puts "Say something to yout grandma..."
  STDOUT.flush
  said = gets.chomp
  if said != "BYE" then
    if said == said.upcase then
      puts "NO, NOT SINCE #{1930+rand(20)}"
    else
      puts "HUH?!  SPEAK UP, SONNY!"
    end
  end
end