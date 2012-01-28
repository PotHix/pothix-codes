=begin
  If you call rand, you'll get a float greater than or equal to 0.0 
  and less than 1.0. If you give it an integer parameter (by calling rand(5) ), 
  you will get an integer value greater than or equal to 0 and less than 5 
=end

 
# The program below makes three lists of words, and then randomly picks one word 
# from each of the three lists and prints out the result 
word_list_one = ['24/7', 'multi-Tier', '30,000 foot', 'B-to-B', 'win-win', 'front-end','web-based', 'pervasive', 'smart', 'six-sigma', 'critical-path', 'dynamic'] 
word_list_two = ['empowered', 'sticky', 'value-added', 'oriented', 'centric', 'distributed', 'clustered', 'branded', 'outside-the-box', 'positioned', 'networked', 'focused', 'leveraged', 'aligned', 'targeted', 'shared', 'cooperative', 'accelerated'] 
word_list_three = ['process', 'tipping-point', 'solution', 'architecture', 'core competency', 'strategy', 'mindshare', 'portal', 'space', 'vision', 'paradigm', 'mission']  
  
one_len = word_list_one.length  
two_len = word_list_two.length  
three_len = word_list_three.length  
  
rand1 = rand(one_len)  
rand2 = rand(two_len)  
rand3 = rand(three_len)  
  
phrase = word_list_one[rand1] + " " + word_list_two[rand2] + " " + word_list_three[rand3]  
  
puts phrase  