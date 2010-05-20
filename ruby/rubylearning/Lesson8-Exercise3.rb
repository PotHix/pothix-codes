def interval_repeat(cycle_time)
  loop do
    yield
    sleep(cycle_time)
  end
end
 
def what_repeated
  puts "I just ran again the time was #{Time.now}"
  STDOUT.flush
end
 
interval_repeat(5) { what_repeated }