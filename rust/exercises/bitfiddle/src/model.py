# Return true if n is a positive power of two.
def is_power_of_two(n):
    return n != 0 and (n - 1) & n == 0

assert not is_power_of_two(0)
assert     is_power_of_two(1)
assert     is_power_of_two(2)
assert not is_power_of_two(3)
assert     is_power_of_two(4)
assert not is_power_of_two(5)
assert not is_power_of_two(6)
assert not is_power_of_two(7)
assert     is_power_of_two(8)

# If n is a positive integer, return the exponent of the largest power of two
# less than or equal to n.
def floor_log2(n):
    assert n > 0
    log = 0
    while n > 1:
        n = n >> 1
        log = log + 1
    return log

assert floor_log2(1) == 0
assert floor_log2(2) == 1
assert floor_log2(3) == 1
assert floor_log2(4) == 2
assert floor_log2(5) == 2
assert floor_log2(7) == 2
assert floor_log2(8) == 3
assert floor_log2(9) == 3
assert floor_log2(255) == 7
assert floor_log2(256) == 8
