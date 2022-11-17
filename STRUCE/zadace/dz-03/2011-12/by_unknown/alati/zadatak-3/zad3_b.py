import math

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
	
def sigma(x):
	# zastita od overflow-a
	if -x < -20: return 0.999999999
	if -x >  20: return 0.000000001
	return 1.0 / (1.0 + math.exp(-x))

def hipoteza(_w, primjer):
	acc = 0
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

		diff = h - y_lst[index]
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

	for i in w:
		e += ( lam / 2 ) * i * i

	return e

##############################################################
stopa = 0.01
lam = 0
x_train = read_x('X_train.txt')
y_train = read_y('y_train.txt')

w = [0] * (len(x_train[0])) # inicijaliziramo w na onolko dimenzija kolko ima prvi vektor
w0 = 0

niter = 0
prev_err = 10000000000000

while 1:
	niter += 1
	nerr, e0, e = classify(x_train,y_train)
	err = calc_err(x_train,y_train)
	w0 -= stopa * e0
	for j in range(0,len(w)):
		w[j] = w[j] * (1 - stopa * lam) - stopa * e[j]

	print 'iteracija',niter,'; krivo klasificiranih:',nerr,", funkcija pogreske: %.2f" % (err,)
	if abs(err - prev_err) < 0.00000001 or niter > 30: break
	prev_err = err

print 'klasifikator naucen!'

f = open('w_a.txt','w')
f.write('%f\n' % (w0,))

for i in w:
	f.write('%f\n' % (i,))
f.close()
	
print 'gotovo!'


