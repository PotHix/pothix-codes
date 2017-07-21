def solution(a, b)
  /#{a}/ =~ b.to_s
end


solution(53, 1953786) == 2
