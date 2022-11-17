import sys

def take_element(values, q):
    return values[int(q*len(values))]

def calculate(values):
    arr = []
    for q in range(10, 100, 10):
        arr.append(take_element(values, q / 100))
    
    return arr

print("Hyp#Q10#Q20#Q30#Q40#Q50#Q60#Q70#Q80#Q90")
lines = [line.rstrip('\n') for line in open(sys.argv[1])]
for i in range(len(lines)):
    values = sorted([float(x) for x in lines[i].split(' ')])
    line = "%03d" % (i + 1)
    for val in calculate(values):
        line += "#%.2f" % val
    print(line)
