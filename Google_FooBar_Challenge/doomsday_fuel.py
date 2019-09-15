def findDivisor(a, b):
    return a if not b else findDivisor(b, a % b)

def calculateRow(matrix, a, b):
    length = len(matrix)
    res = sum(matrix[b])
    gcd = 0
    array = (set(range(length)) - {a, b})
    output = [0 for i in matrix[a]]
    
    for i in array:
        output[i] = res * matrix[a][i] + matrix[a][b] * matrix[b][i]
    
    length = len(output)
    for i in range(length):
        gcd = findDivisor(gcd, output[i])
    output = [i / gcd for i in output]
    return output


def answer(m):
    height = len(m); width = len(m[0])
    if height != width:
        return
    
    for i, row in enumerate(m):
        row[i] = 0

    results = [sum(i) for i in m]                       # counts the results of all rows and puts them in an array
    terminals = [i for i, res in enumerate(results) if not res]
    stages = list(set(range(height)) - set(terminals))  # "active" stages
    nb_stages = len(stages)

for i in range(nb_stages):
    a = stages[i]
    for j in range(nb_stages):
        b = stages[j]
        m[b] = calculateRow(m, b, a)
    
    ret = []
    for i in terminals:
        ret.append(m[0][i])
    
    res = sum(ret)
    if res != 0:
        ret.append(res)
    else:
        ret = [1 for i in terminals]
        ret.append(len(terminals))
    return ret

