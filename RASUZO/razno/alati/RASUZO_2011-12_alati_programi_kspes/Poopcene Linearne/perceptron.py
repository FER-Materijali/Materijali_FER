# ovo je helper skripta koja ispisuje korake u postupku perceptrona
# koristite ovo kako bi provjerili korake na papiru.
# ako imate viseklasni perceptron, pokrenite skriptu vise puta
# tako da pomnozite uzorke drugih razreda sa -1 za svaki razred posebno


#X = [[0,0,0,0,0,1],
#     [4,0,0,2,0,1],
#     [1,1,-1,-1,1,1],
#     [1,1,1,1,1,1]]


X = [[0,0,0,0,0,-1],
     [-4,0,0,-2,0,-1],
     [-1,-1,1,1,-1,-1],
     [1,1,1,1,1,1]]
    
def add(a,b):
	for i in range(0,len(a)):
		a[i] += b[i]

def mul(a,b):
	r = 0.0
	for i in range(0,len(a)):
		r += a[i] * b[i]
	return r
	
def write(a, newline = 1):
	print "[",
	for i in a:
		print "%6.2f" % (i,),
	if newline:
		print "]"
	else:
		print "]",
     
w = [0] * len(X[0])

iter = 1

ok = 0
while 1:
	for x in X:
		print "%3i" % (iter,),
		iter += 1
		m = mul(w,x)
		write(w,0)
		print "*",
		write(x,0)
		print "= %5.2f" % (m,),
		if m > 0.001:
			print "--> OK"
			ok += 1
			if ok == len(X): break
		else:
			ok = 0
			add(w,x)
			print "--> w =",
			write(w)
	if ok == len(X):
		break
			
print '----------------------'
write(w)