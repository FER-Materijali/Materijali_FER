import sys

ulaz = open('ulaz.txt', 'r')
sys.stdout.write("Hyp:Q10#Q20#Q30#Q40#Q50#Q60#Q70#Q80#Q90\n")
rb = 1;
for hip in ulaz.readlines():
	sys.stdout.write("%003d" % rb)
	brojevi = []
	for num in hip.split():
		brojevi.append( float(num) )	
	brojevi.sort()
	l = len(brojevi)-1
	for i in range(9):
		index = int( l*(i+1)/10.0 )
		sys.stdout.write("#%.2f" % brojevi[ index ])
	print
	rb+=1