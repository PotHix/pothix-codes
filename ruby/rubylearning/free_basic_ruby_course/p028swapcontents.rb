# Com um arquivo intermediário
def itwrites(name,arq)
  File.open(name.to_s+'.txt','w') do |wrt|
    while line = arq.gets
      wrt.puts "#{line}"
    end
  wrt.close
  end  
end

File.open('a.txt','r') do |a|
  itwrites('i',a)
end

File.open('b.txt','r') do |b|
    itwrites('a',b)
end

File.open('i.txt','r') do |i|
    itwrites('b',i)
end

File.delete('i.txt')


#Código menor e mais robusto
f1, f2 = IO.readlines('a.txt'),IO.readlines('b.txt')
File.open('a.txt','w') {|f|f.puts f2}
File.open('b.txt','w') {|f|f.puts f1}