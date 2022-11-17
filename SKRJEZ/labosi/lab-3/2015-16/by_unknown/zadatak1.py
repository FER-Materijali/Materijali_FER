import sys

def parse_matrix(lines):
    matrix = {}
    matrix['rows'], matrix['cols'] = rows, columns = [int(x) for x in lines[0].split(' ')]
    for line in lines[1:]:
        values = [float(x) for x in line.split(' ')]
        if not len(values) == 3:
            sys.exit(1)
 
        row, column, value = int(values[0]), int(values[1]), values[2]

        matrix[(row, column)] = value

    return matrix        

def calculate_element(first, second, i, j):
    sum = .0
    for k in range(1, first['cols'] + 1):
        a_val = 0 if not (i, k) in first else first[(i,k)]
        b_val = 0 if not (k, j) in second else second[(k,j)]
        
        sum += a_val * b_val
    
    return sum

def multiply(first, second):
    if(first['cols'] != second['rows']):
        sys.exit(2)

    result = {}
    result['rows'], result['cols'] = first['cols'], second['rows']
    for i in range(1, first['cols'] + 1):
        for j in range(1, second['rows'] + 1):
            value = calculate_element(first, second, i, j)
            if not value == 0:
                result[(i, j)] = value

    return result
    
with open(sys.argv[1], "r") as f:
    array = []
    for line in f:
        array.append(line.strip())
    
    separator = array.index("")
    
    first = parse_matrix(array[0:separator])
    second = parse_matrix(array[separator + 1:])

res = multiply(first, second)

with open(sys.argv[2], "w") as f:
    print("{0} {1}".format(res['rows'], res['cols']), file = f)
    print("{0} {1}".format(res['rows'], res['cols']))

    for i in range(1, res['cols'] + 1):
        for j in range(1, res['rows'] + 1):
            if((i, j) in res):
                print("{0} {1} {2}".format(i, j, res[(i,j)]), file = f)
                print("{0} {1} {2}".format(i, j, res[(i,j)]))
            else:
                print("{0} {1} {2}".format(i, j, 0))
