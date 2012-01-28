=begin
def recebestring(str)
  myArray = str.split
  myArray.reverse
  c = myArray.length
  c -= 1
  puts c
  while c >= 0
    print myArray[c] + " "
    c-=1
  end
end
recebestring(gets)
=end

  
puts "Welcome to the forum.Here you can learn Ruby. Along with other members.".split(' ').reverse.join(' ')
  

#puts "Welcome to the forum.Here you can learn Ruby. Along with other members.".split(/\s/).reverse!.join(" ")
