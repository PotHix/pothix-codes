=begin
my_string = 'Hello Ruby World'
def my_string
 'Hello World'
end
puts my_string

my_string = 'Hello Ruby World'
def my_string
'Hello World'
end
puts my_string
puts my_string()


#-----
my_string = "Hello Ruby World"
def my_string
puts 'Hello World'
end
puts self.class
puts my_string.class
puts my_string().class
puts my_string
Object.send('my_string')
#-----

my_string = 'Hello Ruby World'
def my_string
'Hello World'
end
puts '============'
puts my_string or my_string()
puts '============'
puts my_string() or my_string
puts '============'
puts my_string() and my_string
puts '============'
puts my_string and my_string()
puts '============'
#my_string.call

puts my_string.object_id
puts my_string().object_id
#puts my_string
#puts my_string()
=end


