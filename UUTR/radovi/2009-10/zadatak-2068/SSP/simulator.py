defi = open("definicija.txt", "r").read().split("\n")
defi.pop()

tablica = {}
strelica = ["^"]

for x in defi:
	
	tablica[x.split("=")[0]] = x.split("=")[1]

ulaz = open("ulaz.txt", "r").read()
	
traka = list(ulaz.rstrip("\n"))
traka.append("B")
stanje = "q0"
glava = 0
izbor = 0

for x in range(len(traka)-1):
	
	strelica.append(" ")
	
print "Pocetno stanje: " + stanje + " Glava: " + traka[glava]
print "".join(traka)
print "".join(strelica[glava])

while izbor not in [1,2,3]:

	try:
		
		izbor = input("\nOdaberite nacin izvodjenja:\n\n1: Odjednom\n2: Korak po korak\n3: Nakon promjene stanja\n\n==> ")
		if izbor not in [1,2,3]: print "\nPonovite upis"
	
	except:
	
		print("\nPonovite upis")
		
while ((stanje + "," + traka[glava]) in tablica):

	staro = stanje
	unos = traka[glava]
	pomak = tablica[stanje + "," + unos].split(",")[2]
	traka[glava] = tablica[stanje + "," + unos].split(",")[1]
	stanje = tablica[stanje + "," + unos].split(",")[0]
	strelica[glava] = " "
		
	if (pomak == "R"):
			
		glava = glava + 1
			
	else:
			
		glava = glava - 1
		
	if (izbor == 1) or (izbor == 2):
			
		print "Novo stanje: " + stanje + " Glava: " + str(traka[glava])
		print "".join(traka)
		strelica[glava] = "^"
		print "".join(strelica)
		
	if izbor == 2:
			
		raw_input()
		
	if (staro != stanje) and (izbor == 3):
		
		print "Novo stanje: " + stanje + " Glava: " + str(traka[glava])
		print "".join(traka)
		strelica[glava] = "^"
		print "".join(strelica)
		raw_input()
	
	if (((stanje + "," + traka[glava]) in tablica)):
			
		pass
			
	elif glava < 0:
			
		raw_input("\nDokument je ispravan\n\nPritisni ENTER za kraj")
		exit()
		
	else:
		
		raw_input("\nDokument nije ispravan\n\nPritisni ENTER za kraj")
		exit()
		
raw_input("\nDokument nije ispravan\n\nPritisni ENTER za kraj")
exit()
