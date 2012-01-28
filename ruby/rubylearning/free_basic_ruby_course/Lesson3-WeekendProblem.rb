quiz = [0,0,0,1,0,0,1,1,0,1]
puts "The number of participants who did not attempt Quiz 1 are #{quiz.inject(0){|notAt, el|el == 1 ? notAt+1 : notAt}} out of #{quiz.length} participants"



