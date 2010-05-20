def poeLInha(str)
  arrayStr = str.split("\n")
  arrayStr.length.times do |c|
    puts "Line" + c.to_s + ": " + arrayStr[c]
  end
end

poeLInha("Welcome to the forum.\nHere you can learn Ruby.\nAlong with other members.\n")


=begin
#Exemplo bizarro...
s = "Welcome to the forum.\nHere you can learn Ruby.\nAlong with other members.\n"
i=0
s.split(/\n/).each {
|j|
puts "Line #{i=i+1}: #{j}"
}
=end