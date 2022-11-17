# helper skripta koju sam napisao da si olaksam rjesavanje ovog zadatka

# ispit:
#    pismeni 001
#    usmeni  010
#    oboje   100
#
# projekt:
#    da:  001
#    ne:  010
#    opt: 100
#
# predavanja
#    obavezna:   01
#    neobavezna: 10
#
# labosi
#    da: 01
#    ne: 10
#
# prosjek
#    nizak:   001
#    srednji: 010
#    visok:   100
# ------------------------
# 
# 1) |001|001|01|10|100|1
# 2) |010|001|10|10|010|0
# 3) |100|100|01|01|001|0
# 4) |100|010|10|10|100|1
# 5) |001|010|01|01|010|0
# 6) |010|100|10|10|010|1
# 7) |001|010|01|01|001|0
# 8) |001|010|10|10|100|1

from operator import itemgetter

data = ["0010010110100",
        "0100011010010",
        "1001000101001",
        "1000101010100",
        "0010100101010",
        "0101001010010",
        "0010100101001"]

klase = [1,0,0,1,0,1,0]

def euklidska(a, b):
	suma = 0
	for i in range(0,len(a)):
		if a[i] != b[i]: suma += 1
	return suma

def jaccard(a, b):
	x = 0.0
	y = 0.0
	for i in range(0,len(a)):
		if a[i] == "1" and b[i] == "1": x += 1.0
		if a[i] == "1" or b[i] == "1":  y += 1.0

	return 1.0 - x/y
	
def _3nn(x,fja):
	udaljenosti = []
	for i in range(0, len(data)):
		udaljenosti.append([i, fja(x,data[i])])
	udaljenosti.sort(key = itemgetter(1))
	udaljenosti = udaljenosti[:3]
	
	pozitivni = 0
	negativni = 0
	for i in udaljenosti:	
		if klase[i[0]] == 1: pozitivni += 1
		else: negativni += 1
	
	print "3nn: (",pozitivni,negativni,udaljenosti," ) klasifikacija:",
	if pozitivni > negativni: return 1
	else: return 0
	
print jaccard("1100000001111100000","1000000001111100000")

print "euklidska udaljenost:", _3nn("0010101010100",euklidska)
print "jaccardova udaljenost:", _3nn("0010101010100",jaccard)
