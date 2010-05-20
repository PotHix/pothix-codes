s="99 bottles of beer on the wall...".split(" ")
s.length.times do |a|
   if s[a] == "bottles" or s[a] == "beer" or s[a] == "wall..." then print s[a].capitalize + " " else print s[a] + " " end
end