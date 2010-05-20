class Mp3Info
  def PrintInfo(arq)
    f = File.open(arq)
    f.seek(-128, IO::SEEK_END)
    if f.read(3).to_sym == :TAG then
      puts "Title: #{f.read(30)} \n Artist: #{f.read(30)} \n Album: #{f.read(30)} \n Year: #{f.read(5)}"
    else
      puts "Nothing to do with this file!"
    end    
  end
end

m = Mp3Info.new
m.PrintInfo('song.mp3')