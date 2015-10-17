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

# This is the heart of the game!
#
# Given fs, a list of fractions of the form [(numerator, denominator), ...],
# return the product of n and the first fraction in the list where said product
# is an integer. Return None if no fraction in the list produces an integer when
# multiplied by n.
#
# Assume n is an integer, and that all fractions are in lowest terms (the
# numerator and denominator have no common integer divisors other than 1).
def step(fs, n):
    for f in fs:
        if n % f[1] == 0:
            return n // f[1] * f[0]
    return None

assert step([], 0) == None
assert step([(1,1)], 0) == 0
assert step([(1,2)], 1) == None
assert step([(3,2)], 2) == 3
assert step([(3,2), (2,45)], 27 * 25) == 2 * 3 * 5
assert step([(3,2), (2,45)], 11) == None

# Given fs, a list of fractions in the form step likes, and an initial
# integer n, apply step to fs and n repeatly, taking the result as the next
# iteration's value for n.
#
# If step returns None, return. Run at most limit steps.
def run(fs, n, limit):
    for i in range(0, limit):
        n = step(fs, n)
        if not n:
            return
        # print(str(i) + ": " + str(n))
        if is_power_of_two(n):
            print("****" + str(floor_log2(n)))

# Each pair (n, d) represents the fraction n/d.
# These fractions are all in lowest terms.
v = [(17, 91),
     (78, 85),
     (19, 51),
     (23, 38),
     (29, 33),
     (77, 29),
     (95, 23),
     (77, 19),
     (1, 17),
     (11, 13),
     (13, 11),
     (15, 14),
     (15, 2),
     (55, 1)]

run(v, 2, 100000);

print("okay")
