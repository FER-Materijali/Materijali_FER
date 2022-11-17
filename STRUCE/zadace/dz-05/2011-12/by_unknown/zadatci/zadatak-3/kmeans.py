import random, math, tga
K = 5
X = []

class Primjer:
	def __init__(self, x, y, klasa):
		self.x = float(x)
		self.y = float(y)
		self.prava_klasa = int(klasa)
		self.klasa = 0
		self.prosla_klasa = 0
		
	def udaljenost(self, centroid):
		return (self.x - centroid[0])**2 + (self.y - centroid[1])**2

	def odredi_klasu(self, lst):
		self.prosla_klasa = self.klasa
		mindist = 5000000000
		index = 1
		for k in lst:
			dist = self.udaljenost(k)
			if dist < mindist:
				mindist = dist
				self.klasa = index
			index += 1
	
	def promjenio_klasu(self):
		return self.klasa != self.prosla_klasa

def kriterijska():
	J = 0.0
	for x in X:
		J += (x.x - centroidi[x.klasa-1][0])**2 + (x.y - centroidi[x.klasa-1][1])**2
	return J

f = open('primjeri.txt','r')
for i in f:
	a,b,c = i.replace('\n','').split(' ')
	X.append(Primjer(a,b,c))

# postavimo centroide na random pozicije
#centroidi = [[random.random()*100,random.random()*100] for i in range(0,5)]
# alternativa, izracunamo srednju vrijednost svih primjera
# pa u smjerovima pobacamo centroide
centroidi = []
cx, cy,minx,maxx,miny,maxy = 0, 0,1000,-1000,1000,-1000

for x in X:
	if x.x < minx: minx = x.x
	if x.y < miny: miny = x.y
	if x.x > maxx: maxx = x.x
	if x.y > maxx: maxy = x.y
	cx += x.x
	cy += x.y
cx /= len(X); cy /= len(X)
radijus = math.sqrt((maxx-minx)**2 + (maxy-miny)**2)/2
for i in range(0,K):
	centroidi.append([cx + math.sin((i+random.random()*0.5-0.25)*math.pi*2/K)*(radijus*(0.75+random.random()*0.25)),
	                  cy + math.cos((i+random.random()*0.5-0.25)*math.pi*2/K)*(radijus*(0.75+random.random()*0.25))])
#print radijus,centroidi

iteracija = 1
while 1:
	gotovo = 1
	print 'iteracija %d, J = %.2f' % (iteracija, kriterijska())
	
	# pronadji za svaki primjer najblizi centroid
	for x in X:
		x.odredi_klasu(centroidi)
		
	# provjeri je li se stanje promjenilo od prosle iteracije
	for x in X:
		if x.promjenio_klasu():
			gotovo = 0
			break
	# ako nije, gotovi smo
	if gotovo: break
	# u suprotnom, azurirati centroide
	klasa = 1
	print 'novi centroidi:',
	for c in centroidi:
		c[0] = 0; c[1] = 0
		n = 0
		for x in X:
			if x.klasa == klasa:
				c[0] += x.x
				c[1] += x.y
				n += 1
		if n > 0:
			c[0] /= n;
			c[1] /= n
		print '(%.1f, %.1f, %d primjera), ' % (c[0],c[1],n),
		klasa += 1
	print ''
	iteracija += 1
	
#crtanje
for k in range(0,K):
	tga.circle(centroidi[k][0],centroidi[k][1],20,(220,220,220))

tga.emptyrect(0,0,799,799,(0,0,0)) # obrub

# odredimo koje nove grupe odgovaraju originalnima
grupe =  [0.0 for i in range(0,100)]
ngrupe = [0   for i in range(0,100)]

for x in X:
	grupe[x.klasa] += x.prava_klasa
	ngrupe[x.klasa] += 1
for i in range(0,len(grupe)):
	if ngrupe[i] > 0:
		grupe[i] /= ngrupe[i]
		grupe[i] = int(round(grupe[i],0))

#print grupe
for x in X:
	k = x.prava_klasa
	for y in X:
		if grupe[x.klasa] != x.prava_klasa:
		   	k = 505 # crna boja
		   	break
#	if x.prava_klasa != klasa: k = 6
	tga.draw(x.x,x.y,k)

tga.save('kmeans_out.tga')


print 'GOTOVO!'
print '----------------'
print 'J(K): %.1f' % (kriterijska(),)
print 'AIC : %.1f' % (kriterijska() + 2*2*K,)




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
