# Create a new file and write to it  
def updatestring line
 line.insert(line.index('word'),'inserted ')   
end

f1 = IO.readlines('plaintext.txt')
updatestring(f1[5])
File.open('plaintext.txt','w'){|f|f.puts f1}

=begin
File.open('plaintext.txt', 'r+') do |fil|  
  while line = fil.gets
    if fil.lineno == 5
      line.split('word').join('inserted word')
    end
    nfile = line.concat("#{line}")
  end
  fil.rewind
  fil.puts "#{line}"
end  
=end