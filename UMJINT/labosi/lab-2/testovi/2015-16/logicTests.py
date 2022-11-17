import logic
import os

correct = 0

"""
Rjesava jedan test i vraca string zapis rjesenja i stvarnog rjesenja.
"""
def resolveTest(path):
    global correct
    f = open(path)
    premises = set()
    
    solution = f.readline().strip()
    for line in f:
        literals = set()
        lineSplit = line.split()
        for lit in lineSplit:
            if lit.startswith('-'):
                literals.add(logic.Literal(lit[1:], (0, 0), True))
	    else:
		literals.add(logic.Literal(lit, (0, 0), False))
        last = logic.Clause(literals)
        premises.add(last)
    goal = last
    premises.remove(last)
    resolution = logic.resolution(premises, goal)
    if str(resolution) == solution:
	correct += 1
    return str(resolution) + ' | Correct solution: ' + solution


if __name__ == '__main__':
    total = 0
    for subdir, dirs, files in os.walk('./test/'):
	for file in files:
	    filename = subdir + os.sep + file	    
	    print filename
	    print resolveTest(filename)
	    print
	    total += 1
    print
    print 'Test results: ' + str(correct) + '/' + str(total)
