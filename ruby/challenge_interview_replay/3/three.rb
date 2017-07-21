def solution(n)
  d = Array.new(30)
  l = 0
  while (n > 0)
    d[l] = n % 2
    n /= 2
    l += 1
  end
  p d

  for p in 1 .. l
    p "p -> #{p}"
    ok = true
    p  "  i -> #{0 .. l - p - 1}"

    for i in 0 .. l - p - 1
      p "    compare i #{i} -> ip #{i+p}"
      if (d[i] != d[i  +  p]) then
        ok = false
        break
      end
    end
    if (ok) then
      return p
    end
  end

  return -1
end

p "solution #{solution(955)}"
p "solution #{solution(999)}"
