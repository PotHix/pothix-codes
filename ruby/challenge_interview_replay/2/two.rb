def solution(a)
  offered  = a.uniq
  shortest = -1

  for index in 0..a.size-1
    for subindex in index..a.size-1
      hypothesis = a[index..subindex]
      if (offered - hypothesis).empty?
        if shortest == -1 || (subindex - index) < shortest
          shortest = hypothesis.size
        end
      end
    end
  end

  shortest
end

puts "--> solutions"
p solution([7,3,7,3,1,3,4,1]) == 5
p solution([7,3,7,3,3,4,7,3,7,3,1,7,3,1,4]) == 4
p solution([7,3,1,4,7,3,3,4,7,3,7,3,1,7,3,1]) == 4
p solution([7,3,4,7,3,3,4,7,3,7,3,1,7,3,1]) == 6
p solution([]) == -1

puts "--> done"
