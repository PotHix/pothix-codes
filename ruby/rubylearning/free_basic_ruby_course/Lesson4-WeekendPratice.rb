def load_game(file)
  stats = File.stat(file)
  f = IO.readlines(file)
  puts stats.mtime.to_i == f[1].to_i ? "Your score is #{f[0]}" : "RuntimeError: I suspect you of cheating."
end

def save_game(file)
 score = 1000
 open(file, "w") do |f|
 f.puts(score)
 f.puts(Time.new.to_i)
 end
end

save_game("game.sav")
load_game("game.sav")




