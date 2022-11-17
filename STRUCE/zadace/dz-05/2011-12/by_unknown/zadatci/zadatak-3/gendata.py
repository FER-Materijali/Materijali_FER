import tga, random, math

f = open('primjeri.txt','w')

klase = [
(0,0,0),
(30,30,13),
(70,70,33),
(50,50,40),
(30,70,22),
(70,30,31),
]

def primjer(klasa):
	while 1:
		x = klase[klasa][0]+random.gauss(0,math.sqrt(klase[klasa][2]))
		y = klase[klasa][1]+random.gauss(0,math.sqrt(klase[klasa][2]))
		if x < 0.5 or y < 0.5 or x > 99.5 or y > 99.5: continue
		else: break
	tga.draw(x,y,klasa)
	f.write("%.2f %.2f %d\n" % (x,y,klasa))


for k in range(1,6):
	tga.circle(klase[k][0],klase[k][1],klase[k][2],(220,220,220))

tga.emptyrect(0,0,799,799,(0,0,0)) # obrub

for k in range(0,5):
	for i in range(0,100):
		primjer(k+1)
tga.save('out.tga')

f.close()