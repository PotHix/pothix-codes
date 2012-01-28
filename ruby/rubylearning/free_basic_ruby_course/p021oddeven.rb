collection = [12, 23, 456, 123, 4579].each{
|el|
puts el.to_s + " is #{el % 2 == 0 ? "even" : "odd"}"
}