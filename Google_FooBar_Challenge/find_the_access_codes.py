def answer(l):
    res = 0
    length = len(l)

    for x in xrange(length):
        left = 0
        right = 0
        for i in xrange(x):
            if not (l[x] % l[i]):
                left = left + 1
        for i in xrange(x + 1, length):
            if not (l[i] % l[x]):
                right = right + 1
        res = res + left * right

    return res


# Provided test cases.
assert(answer([1, 1, 1]) == 1)
assert(answer([1, 2, 3, 4, 5, 6]) == 3)

# Custom test cases.
assert(answer([1]) == 0)
assert(answer([1, 2]) == 0)
assert(answer([2, 4]) == 0)
assert(answer([1, 1, 1, 1]) == 4)
assert(answer([1, 1, 1, 1, 1]) == 10)
assert(answer([1, 1, 1, 1, 1, 1]) == 20)
assert(answer([1, 1, 1, 1, 1, 1, 1]) == 35)
assert(answer([1, 1, 2]) == 1)
assert(answer([1, 1, 2, 2]) == 4)
assert(answer([1, 1, 2, 2, 2]) == 10)
assert(answer([1, 1, 2, 2, 2, 3]) == 11)
assert(answer([1, 2, 4, 8, 16]) == 10)
assert(answer([2, 4, 5, 9, 12, 34, 45]) == 1)
assert(answer([2, 2, 2, 2, 4, 4, 5, 6, 8, 8, 8]) == 90)
assert(answer([2, 4, 8]) == 1)
assert(answer([2, 4, 8, 16]) == 4)
assert(answer([3, 4, 2, 7]) == 0)
assert(answer([6, 5, 4, 3, 2, 1]) == 0)
assert(answer([4, 7, 14]) == 0)
assert(answer([4, 21, 7, 14, 8, 56, 56, 42]) == 9)
assert(answer([4, 21, 7, 14, 56, 8, 56, 4, 42]) == 7)
assert(answer([4, 7, 14, 8, 21, 56, 42]) == 4)
assert(answer([4, 8, 4, 16]) == 2)