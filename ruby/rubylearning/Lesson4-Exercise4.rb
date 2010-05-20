puts "You are in #{Dir.getwd}"
Dir.mkdir 'tmp'
puts "The tmp/ directory was created!"
Dir.chdir 'tmp'
puts "Your working directory was changed to /tmp"
puts "Now, you are in #{Dir.getwd}"
Dir.chdir '../'
puts "Back to your old directory #{Dir.getwd}"
Dir.rmdir 'tmp'
puts "/tmp diretory was removed!"