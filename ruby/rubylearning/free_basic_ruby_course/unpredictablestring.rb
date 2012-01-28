class UnpredictableString < String
  def scramble(phrase)
    puts phrase.split(//).sort_by{rand}.join()
  end  
end

a = UnpredictableString.new
a.scramble("It was a dark and stormy night.")


#Outro exemplo
class Unpredictablestring < String
  def scramble(tobescrambled)
    a = tobescrambled.split(//)
    a.length.times do |i|
      pick_item = rand(a.length)
      print a[pick_item]
      a.slice!(pick_item) #O slice tira algum elemento do array e retorna o que foi tirado
    end
  end
end
c = Unpredictablestring.new
c.scramble("It was a dark and stormy night.")