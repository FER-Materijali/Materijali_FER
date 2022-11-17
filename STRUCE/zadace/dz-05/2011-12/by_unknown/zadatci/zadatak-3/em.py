import random, math, tga, sys
K = 5
X = []
korjen_2_pi = math.sqrt(2 * math.pi)


class Primjer:
	def __init__(self, x, y, klasa):
		self.x = float(x)
		self.y = float(y)
		self.klasa = 0
		self.prava_klasa = int(klasa)
		self.h = [0.0 for i in range(0,K)]

	def izracunaj_odgovornosti(self):
		maxh = -1.0
		nazivnik = 0.0
		for j in xrange(0,K):
			nazivnik += grupe[j].vjerojatnost(self.x, self.y)
		for i in xrange(0,K):
			self.h[i] = grupe[i].vjerojatnost(self.x, self.y) / nazivnik
			if self.h[i] > maxh:
				maxh = self.h[i]
				self.klasa = i
		#print nazivnik
		#print "%.1f %.1f %.1f %.1f %.1f" % tuple(self.h)
		#sys.exit()



klase = [
(30,30,13),
(70,70,33),
(50,50,40),
(30,70,22),
(70,30,31)
]
class Grupa:
	def __init__(self, index):
		self.x = klase[index][0]
		self.y = klase[index][1]
		#self.x = random.random() * 100
		#self.y = random.random() * 100
		self.r = 10#math.sqrt(10 + (random.random() * 10))
		self.t = 1.0/K # pi
		self.index = index
		
	def procijeni_parametre(self):
	# procjeni centar distribucije
		xbrojnik, nazivnik, ybrojnik, rbrojnik = 0.0, 0.0, 0.0, 0.0
		for x in X:
			h = x.h[self.index]
			xbrojnik += h * x.x
			ybrojnik += h * x.y
			nazivnik += h
		if nazivnik < 0.001:
			self.r = 0.0
			self.t = 0.0
			return
		self.x = xbrojnik / nazivnik
		self.y = ybrojnik / nazivnik
	# procijeni radijus gaussa
		for x in X:
			#z = x.h[self.index] * ((self.x - x.x)**2 + (self.y - x.y)**2)
			#if x.h[self.index] > 0.01:
				#print "%d: %.1f [ %.1f %.1f - %.2f]" % (self.index, z,x.x, x.y, x.h[self.index])
			rbrojnik += x.h[self.index] * ((self.x - x.x)**2 + (self.y - x.y)**2)
	
		#print self.x, self.y
		#print "r:",rbrojnik,nazivnik
		#sys.exit()
		prevr = self.r
		self.r = rbrojnik / (2*nazivnik)
		print self.index,'(',nazivnik,') :',prevr,"->",self.r
	# procijeni pi faktor grupe
		self.t = nazivnik / len(X)

		
	def vjerojatnost(self, x, y):
		if self.r < 0.001: return 0
		dist = ((x-self.x)**2 + (y-self.y)**2)/(2*self.r)
		ret = math.exp(-dist) / (korjen_2_pi * math.sqrt(self.r))
		#if ret < 1e-100: ret = 1e-100
#		print x,y,self.x,self.y,self.r, 2*(self.r**2), dist, ret
#		sys.exit()
		return ret * self.t
		
	def ispisi(self):
		print "x = %.1f, y = %.1f, r = %.1f, t = %.2f" % (self.x,self.y,self.r,self.t)
		
def izglednost():
	izg = 0.0
	for x in X:
		suma = 0.0
		for g in grupe:
			suma += g.vjerojatnost(x.x, x.y)
		izg += math.log(suma)
	return -izg

f = open('primjeri.txt','r')
for i in f:
	a,b,c = i.replace('\n','').split(' ')
	X.append(Primjer(a,b,c))

# postavimo parametre na random vrijednosti
grupe = [Grupa(i) for i in range(0,K)]
for g in grupe:
	g.ispisi()
	#print g.vjerojatnost(g.x,g.y)/g.vjerojatnost(g.x,g.y)

iteracija = 1
prosla_izglednost = 0
while 1:
	print 'iteracija %d, izglednost = %.2f' % (iteracija, prosla_izglednost)	
# E korak
	for x in X:
		x.izracunaj_odgovornosti()
# M korak
	for g in grupe:
		g.procijeni_parametre()

# provjera konvergencije
	izg = izglednost()
	if abs(izg - prosla_izglednost) < 0.01: break
	prosla_izglednost = izg
#	for g in grupe:
#		g.ispisi()

	iteracija += 1
	
print 'GOTOVO!'
print '--------------------------------------'
print 'izglednost = %.2f' % (izglednost(),)
for g in grupe:
	if g.t > 0.01:
		g.ispisi()
print '--------------------------------------'


#crtanje
for g in grupe:
	tga.circle(g.x,g.y,math.sqrt(g.r)*2,(220,220,220))

tga.emptyrect(0,0,799,799,(0,0,0)) # obrub

# odredimo koje nove grupe odgovaraju originalnima
_grupe =  [0.0 for i in range(0,100)]
ngrupe = [0   for i in range(0,100)]

for x in X:
	_grupe[x.klasa] += x.prava_klasa
	ngrupe[x.klasa] += 1
for i in range(0,len(_grupe)):
	if ngrupe[i] > 0:
		_grupe[i] /= ngrupe[i]
		_grupe[i] = int(round(_grupe[i],0))

#print grupe
for x in X:
	k = x.prava_klasa
	for y in X:
		if _grupe[x.klasa] != x.prava_klasa:
		   	k = 505 # crna boja
		   	break
#	if x.prava_klasa != klasa: k = 6
	tga.draw(x.x,x.y,k)

tga.save('em_out.tga')


# izracun rand-ovog indexa

a,b,n = 0,0,0
for x in xrange(0,len(X)):
	for y in xrange(x+1,len(X)):

		if X[x].klasa == X[y].klasa and X[x].prava_klasa == X[y].prava_klasa:
			a+=1
		if X[x].klasa != X[y].klasa and X[x].prava_klasa != X[y].prava_klasa:
			b+=1
		n+=1

print "Randov index: %.3f" % ((a+b)/float(n),)
