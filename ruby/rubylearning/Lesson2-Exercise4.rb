0.upto(100) do |teste|
  n=teste
  n="Fizz" if teste%3 == 0
  n="Buzz" if teste%5 ==0
  n="FizzBuzz" if ( teste%5 ==0 and teste%3 ==0)
  puts n
  
end
#=end

=begin
(1.100).each do |x|
printed=false
(print 'Fizz'; printed=true) if x%3 == 0
(print 'Fuzz'; printed=true) if x%5 == 0
print x if not printed
puts
end
=end


=begin
1.upto(100){|n|
 s = nil
 print s="Fizz" if n%3 == 0
 print s="Buzz" if n%5 == 0
 print n if s == nil
 print "\n"
}
=end


=begin
#exemplo bem interessante...
(1..100).each do |n|
r = n % 3 == 0 ? 'Fizz' : ''
r << 'Buzz' if n % 5 == 0
puts r.empty? ? n : r #verifica se r está vazio...se estiver ele printa n caso contrário printa r
end
=end