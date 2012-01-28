s = 'key=value'
s = s.split("=")
s1 = s[0]
s2 = s[1]
puts "Result s1=#{s1} e s2=#{s2}"



#Exemplo legal de uso
s1, s2 = 'key=value'.split('=')

puts s1
puts s2