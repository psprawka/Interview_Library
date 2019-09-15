def modulo(start, end):
    res_start = [start, 1, start + 1, 0]
    res_end = [end, 1, end + 1, 0]
    return  res_end[end % 4] ^ res_start[start % 4]

def answer(start, length):
    xor = 0
    for x in xrange(length):
        res = modulo(start - 1, start + length - x - 1)
        xor = xor ^ res
        start = start + length
    return xor

print "\n10, 5:\n", answer(10, 5)
print "\n17, 4:\n", answer(17, 4)
print "\n0, 3:\n", answer(0, 3)
print "\n15, 2:\n", answer(15, 2)