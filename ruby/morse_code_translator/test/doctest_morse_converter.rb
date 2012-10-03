=begin
doctest: Setup
>> require File.dirname(__FILE__) + '/../lib/morse_code'
>> morse = MorseConverter.new
doctest: Should return .- for letter a
>> morse.to_morse 'a'
=> '.-'
doctest: Should return  for letter b
>> morse.to_morse 'b'
=> '-...'
doctest: Should return -.-. for letter c
>> morse.to_morse 'c'
=> '-.-.'
doctest: Should return -.. for letter d
>> morse.to_morse 'd'
=> '-..'
doctest: Should return . for letter e
>> morse.to_morse 'e'
=> '.'
doctest: Should return ..-. for letter f
>> morse.to_morse 'f'
=> '..-.'
doctest: Should return --. for letter g
>> morse.to_morse 'g'
=> '--.'
doctest: Should return .... for letter h
>> morse.to_morse 'h'
=> '....'
doctest: Should return .. for letter i
>> morse.to_morse 'i'
=> '..'
doctest: Should return .--- for letter j
>> morse.to_morse 'j'
=> '.---'
doctest: Should return -.- for letter k
>> morse.to_morse 'k'
=> '-.-'
doctest: Should return .-.. for letter l
>> morse.to_morse 'l'
=> '.-..'
doctest: Should return -- for letter m
>> morse.to_morse 'm'
=> '--'
doctest: Should return -. for letter n
>> morse.to_morse 'n'
=> '-.'
doctest: Should return --- for letter o
>> morse.to_morse 'o'
=> '---'
doctest: Should return .--. for letter p
>> morse.to_morse 'p'
=> '.--.'
doctest: Should return --.- for letter q
>> morse.to_morse 'q'
=> '--.-'
doctest: Should return .-. for letter r
>> morse.to_morse 'r'
=> '.-.'
doctest: Should return ... for letter s
>> morse.to_morse 's'
=> '...'
doctest: Should return - for letter t
>> morse.to_morse 't'
=> '-'
doctest: Should return ..- for letter u
>> morse.to_morse 'u'
=> '..-'
doctest: Should return ...- for letter v
>> morse.to_morse 'v'
=> '...-'
doctest: Should return .-- for letter w
>> morse.to_morse 'w'
=> '.--'
doctest: Should return -..- for letter x
>> morse.to_morse 'x'
=> '-..-'
doctest: Should return -.-- for letter y
>> morse.to_morse 'y'
=> '-.--'
doctest: Should return --.. for letter z
>> morse.to_morse 'z'
=> '--..'
doctest: Should return ----- for number 0
>> morse.to_morse '0'
=> '-----'
doctest: Should return .---- for number 1
>> morse.to_morse '1'
=> '.----'
doctest: Should return ..--- for number 2
>> morse.to_morse '2'
=> '..---'
doctest: Should return ...-- for number 3
>> morse.to_morse '3'
=> '...--'
doctest: Should return ....- for number 4
>> morse.to_morse '4'
=> '....-'
doctest: Should return ..... for number 5
>> morse.to_morse '5'
=> '.....'
doctest: Should return -.... for number 6
>> morse.to_morse '6'
=> '-....'
doctest: Should return --... for number 7
>> morse.to_morse '7'
=> '--...'
doctest: Should return ---.. for number 8
>> morse.to_morse '8'
=> '---..'
doctest: Should return ----. for number 9
>> morse.to_morse '9'
=> '----.'
=end
