import sys

def error( poruka ):
	print poruka
	sys.exit(0)	

def ucitaj( data ):
	matrica = {}
	for redak in data:
		s = redak.split();
		matrica[' '.join([s[0],s[1]])] = float(s[2]);
	return matrica

inMatrix = open('matrice.txt', 'r');
inML = inMatrix.readlines();

dimP = inML[0].split();
prvaR = int(dimP[0]);
prvaS = int(dimP[1]);

mat1 = ucitaj( inML[1:prvaR*prvaS+1] )
	
if (prvaR*prvaS) != len(mat1):
	error("Neispravna datoteka, prva matrica nema ispravan broj elemenata.")

inML = inML[prvaR*prvaS+2:]
dimP = inML[0].split();
drugaR = int(dimP[0]);
drugaS = int(dimP[1]);

mat2 = ucitaj( inML[1:drugaR*drugaS+1] )
for x in mat1:
	print x,' ', mat1[x]
print '\n'
for x in mat2:
	print x,' ', mat2[x]

if (drugaR*drugaS) != len(mat2):
	error("Neispravna datoteka, druga matrica nema ispravan broj elemenata.")
	
print "Datoteka učitana."

if prvaS != drugaR:
	error("Neispravne dimenzije matrica!")
else:
	print "Dimenzije matrica odgovaraju, počinjem množti."
	
rez = {}
for i in range(prvaR):
	for j in range(drugaS):
		iS = '%d'%(i+1)
		jS = '%d'%(j+1)
		rez[ ' '.join([iS,jS])] = 0.0


for el in mat1:
	spl = el.split()
	redP = spl[0]
	stupacP = spl[1]	
	broj1 = mat1[el]
	for i in range(drugaS):
		ind = '%d' % (i+1)
		kljuc = ' '.join([stupacP,ind])
		if mat2.has_key(kljuc):
			broj2 = mat2[kljuc]
			rez[ ' '.join([redP,ind]) ] += broj1*broj2
		else:
			error("Greška u definiranim matricama, postoje neispravni elementi!")

print "Množenje gotovo, rezultat:"
outFajl = open('rezultat.txt', 'w')
outFajl.write('%d %d\n' % (prvaR, drugaS))	
for x in rez:
	redak = '%s %f\n' % (x, rez[x])
	print x,' ',rez[x]
	outFajl.write(redak)
outFajl.close()
print "Upisano u datoteku rezultat.txt"