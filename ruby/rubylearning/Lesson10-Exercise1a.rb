#------------------------------------------------- 
#Lesson10-Exercise1a.rb
#------------------------------------------------- 

require 'Lesson10-Exercise1'
o = Klass.new("hello")
puts o.sayHello

#Using a file to Marshal
m = File.open('save','w'){|f|Marshal.dump(o,f)}
ml = File.open('save','r'){|f1|puts Marshal.load(f1).sayHello}

#The Julien's Idea....I have not found a better way to do this...This is the shortest code i think. =)
m = Marshal.dump(o)
lm = Marshal.load(m) 
puts lm.sayHello

