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
	print '[%.2f %.2f %.2f]' % tuple(scale(mult(lst)))


fmult([ 1, 1,-1,-1,-1])
fmult([-1,-1, 1, 1,-1])
fmult([-1,-1,-1,-1, 1])
