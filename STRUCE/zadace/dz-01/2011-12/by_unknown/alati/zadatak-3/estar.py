import math

def f(vc,n,mi):
	return math.sqrt((vc*(math.log(2*n/vc)+1) - math.log(mi/4))/n)

data=[28.00,28.00,28.00,28.75,30.25,30.75,18.25,11.75,11.50,10.00]

cnt=1
for i in data:
#	print i+f(cnt+1,400.0,0.05)*100
	print "h" + str(cnt) + "\t",i,'\t',i+f(cnt+1,400.0,0.05)*100
	cnt+=1
