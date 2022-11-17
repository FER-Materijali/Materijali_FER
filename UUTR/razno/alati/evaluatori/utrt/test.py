import os, sys, time, subprocess
from subprocess import Popen, PIPE, STDOUT, DEVNULL

def getTests() :
	t = [] # Get all directories from current folder
	for item in list(filter(os.path.isdir, os.listdir( os.curdir ))) :
		# Check if they contain appropriate test files
		if os.path.exists(os.curdir+'/'+item+'/test.a') and os.path.exists(os.curdir+'/'+item+'/test.b') :	
			# If they do, add them to the list
			t.append(item)
	return t

def execute(tests) :
	if not tests :
		print('There are no tests to be run! Check your setup.')
		return

	execution, correct = 0, 0
	printString = 'Results for test : >[ {0:6s} ]< | Execution time : {1:1.3f}ms | {2}'

	print('These tests will be run :\n' + ','.join(tests), end='\n\n')

	for test in tests :
		runString = sys.argv[1] + ' < ' + test + '/test.a > ' + test + '/test.u'

		execution = time.time()
		subprocess.call(runString, shell=True, stdin=PIPE, stdout=DEVNULL, stderr=STDOUT)
		execution = round(time.time() - execution, 3)

		with open (test+'/test.b', 'U') as myfile :
			text1 = myfile.read()
		with open (test+'/test.u', 'U') as myfile :
			text2 = myfile.read()

		ok = text1 == text2

		if ok : correct += 1
		print(printString.format(test,execution,('pass' if ok else 'fail - x')))

	print('\nStats : {0}/{1} | {2}%'.format(correct, len(tests), round(correct*100/len(tests),2)))

# Let's run this motherfucker!!!
execute(getTests())