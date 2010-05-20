def last_modified(file)
  puts "file was last modified #{((Time.now-File.mtime(file))/(24*60*60))} days ago"
end

last_modified('test.rb')