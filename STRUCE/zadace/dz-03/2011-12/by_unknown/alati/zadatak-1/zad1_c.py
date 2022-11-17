import math

inv = ((3245/15668.  , 4193/15668. , 763/3917. , 3661/15668.  , 1517/15668.),\
       (755/15668.   , 879/15668.  , -82/3917. , -645/15668.  , -661/15668.),\
       (427/15668.   , -665/15668. , -36/3917. , -1143/15668. , 1525/15668.))

def mult(lst):
	
	result = []
	for i in range(0,3):
		acc = 0
		index = 0
		for j in inv[i]:
			acc += j * lst[index]
			index+=1
		result.append(acc)
			
	return result

def scale(lst):
	l = math.sqrt(lst[1]*lst[1]+lst[2]*lst[2])
	return (lst[0]/l,lst[1]/l,lst[2]/l)


def fmult(lst):
	return scale(mult(lst))


a=fmult([ 1, 1,-1,-1,-1])
b=fmult([-1,-1, 1, 1,-1])
c=fmult([-1,-1,-1,-1, 1])

def sigma(x):
	return 1/(1.0 + math.exp(x))
	
print sigma(1*a[0] + 1 * a[1] + 3 * a[2])
print sigma(1*b[0] + 1 * b[1] + 3 * b[2])
print sigma(1*c[0] + 1 * c[1] + 3 * c[2])

# ovo je ekspriment da vidim kakve bi izlaze dala
# logisticka regresija, nije bitno za zadatak
# ostavih tu, mozda ce mi zatrebati jos tokom rjesavanja