class Game
  def initialize
    @num_of_hits = 0
    @errors = 0
    @arr = []
    @found = []
  end
  
  def presentation(name)
    puts "Hi #{name}!"
    puts "----------------------------------------"
    puts "This game was created by Willian Molinari"
    puts "----------------------------------------"
    puts "And He hope that you enjoy!\n"
  end
  
  def doRand
    num = (1..5).to_a #I know that the range is wrong, but it will be 0 to 6 on the array
    num1 = rand(num.size)
    num1 == 1 || num1 == 0 ? @arr = [ num1, num1+1, num1+2] : @arr = [ num1 -1, num1, num1+1]
  end
  
  def doGame
    puts "So...I chose 3 numbers between 0 and 6 in a sequence, and you have to find what are these numbers!"
    while not @found.size == 3 do
      puts "Please enter a number between 0 and 6:"
      STDOUT.flush
      try = gets.to_i
      if @arr.include?(try) && !@found.include?(try) then
        @found.concat([try])
        puts "Yes! This was a HIT!"
      else
        case
          when @found.include?(try) : puts "You already hit this number!" # Tks Satoshi! =)
          when try < 0 || try > 6 : puts "Ops...This number is not between 0 and 6! ¬¬"
          else puts "Ops...You have got a error! =)"
        end
        @errors += 1
      end
      
    end
    printResult
  end
    
  def printResult
    attemps = @found.size + @errors
    puts "You have these results:"
    puts "#{@errors} errors of #{attemps} attemps" 
    printf("Your rating is: %.2f%", (@found.size.to_f  / attemps.to_f * 100.00))
  end
end

x = "Y"
puts "Please enter your name:"
STDOUT.flush
g = Game.new
g.presentation(gets.chomp)

while x=="Y" do
  g = Game.new
  g.doRand
  g.doGame
  puts "\nWant to Play again? Say Y to yes and N to no."
  STDOUT.flush
  x = gets.chomp.upcase
end

