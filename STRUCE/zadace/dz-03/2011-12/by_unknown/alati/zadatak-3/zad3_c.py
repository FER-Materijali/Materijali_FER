import math, sys

def read_x(x):
	_x = []
	f = open(x,'r')
	for i in f:
		_x.append([float(j) for j in i.split(' ')])
	f.close()
	return _x

def read_y(y):
	_y = []
	f = open(y,'r')
	for i in f:
		_y.append(int(i))
	f.close()
	return _y
	
def read_rjecnik(path):
	_r = []
	f = open(path, 'r')
	for i in f:
		_r.append(i.replace('\n','').replace('\r',''))
	f.close()
	return _r
	
def sigma(x):
	# zastita od overflow-a
	if -x < -20: return 0.999999999
	if -x >  20: return 0.000000001
	return 1.0 / (1.0 + math.exp(-x))

def hipoteza(_w, primjer):
	acc = 0.0
	index = 0
	for i in _w:
		acc += i * primjer[index]
		index += 1
	s = sigma(acc)
	return s

def classify(x_lst, y_lst):
	nerr = 0
	index = 0
	e0 = 0
	e = [0] * (len(x_lst[0]))
	for i in x_lst:
		h = hipoteza(w, i)
		if h >= 0.5: c = 1 # diskretna klasifikacija
		else: c = 0

		diff = h - float(y_lst[index])
		e0 += diff
		for j in range(0,len(w)):
			e[j] += diff * i[j]
		nerr += abs(c - y_lst[index])
		index += 1
	return nerr, e0, e

def calc_err(x_lst, y_lst):
	e = 0.0
	index = 0

	for i in x_lst:
		h = hipoteza(w, i)
		e -= y_lst[index] * math.log(h) + (1.0 - y_lst[index]) * math.log(1.0 - h)
		index += 1

	xx = 0
	for i in w:
		xx += i * i

	return e + (lam/2) * xx

##############################################################
stopa = 0.001
maxiter = 20
lam = 0
if len(sys.argv) > 1:
	lam = float(sys.argv[1])
	xstopa = float(sys.argv[2])
	stopa = xstopa
	maxiter = int(sys.argv[3])
	print 'lambda: %.2f, stopa: %.2f, maxiter: %d' % (lam,stopa,maxiter)

x_train = read_x('X_train.txt')
y_train = read_y('y_train.txt')
x_validate = read_x('X_validate.txt')
y_validate = read_y('y_validate.txt')

w = [0.0] * (len(x_train[0])) # inicijaliziramo w na onolko dimenzija kolko ima prvi vektor
w0 = 0

niter = 0

while 1:
	niter += 1
	nerr, e0, e = classify(x_train,y_train)
	err = calc_err(x_train,y_train)
	w0 -= stopa * e0
	for j in range(0,len(w)):
		w[j] = w[j] * (1 - stopa * lam) - stopa * e[j]


	vnerr, ve0, ve = classify(x_validate,y_validate)
	print 'iteracija',niter,'; krivo klasificiranih:',nerr,", funkcija pogreske: %.2f" % (err,),'greska na skupu za provjeru: %.2f%%' % ((float(vnerr) / len(x_validate)) * 100,)
	if niter == maxiter: break
	if err > 5: stopa = xstopa * err # adaptivna stopa
	else: stopa = xstopa

print 'klasifikator naucen!'	
print 'gotovo!'

rjecnik = read_rjecnik('rjecnik.txt')

for i in range(0,50):
	max = -100000000
	selected = 0
	index = 0
	for _w in w:
		if _w > max:
			max = _w
			selected = index
			
		index += 1
	print rjecnik[selected],
	w[selected] = -10000000
	







