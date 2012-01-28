# program1.rb
for i in [1,2,3,4]
  puts i
end

a = 0
b = [1,2,3,4]
while a < b.length
  puts b[a]
  a += 1
end

def unnamed_method(i)
  puts i
end

[1,2,3,4].each(unnamed_method)

=begin
# program2.rb
[1,2,3,4].each { |i| puts i }

[1,2,3,4].each do |i|
  puts i
end
=end

