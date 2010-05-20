def swapFiles(a,b)
  begin
    f1, f2 = IO.readlines(a),IO.readlines(b)
    File.open(a,'w') {|f|f.puts f2}
    File.open(b,'w') {|f|f.puts f1}
  rescue => err
    puts "An error occured on line #{__LINE__}" #__LINE__ is stolen of Julien's Program...=)...Tks Julien! I Not knew this method
    puts err.message
  end
end

if __FILE__ == $0
  if ARGV.size < 2
    puts "Use: #{$0} file1 file2"
    exit
  end
  a = Swap.new
  a.swapFiles(ARGV[0],ARGV[1])
end
