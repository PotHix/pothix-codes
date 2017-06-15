def fib(n)
  return 1 if n <= 1
  fib(n-1)+fib(n-2)
end

n = gets.chomp.to_i
puts fib(n)
