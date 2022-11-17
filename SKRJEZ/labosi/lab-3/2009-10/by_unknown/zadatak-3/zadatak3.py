import os
import re
import sys

def error( poruka ):
	print poruka
	sys.exit(0)	

fStudenti = open("studenti.txt", 'r')
stud = {}
for redovi in fStudenti.readlines():
	split = redovi.split()	
	stud[split[0]] = ', '.join([split[2],split[1]])

prisustva = {}
for st in stud:
	prisustva[st] = {};
	
bodovi = {}
for st in stud:
	bodovi[st] = {};
	
vjezbe = {}

for fajla in os.listdir("."):
	if re.match("(Lab_[0-9]*_g[0-9]*.txt)", fajla):
		labFajl = open(fajla, 'r')
		grupa = fajla.split('_')[2].split('.')[0]		
		vjezba = fajla.split('_')[1]
		if not vjezbe.has_key(vjezba):
			vjezbe[vjezba] = 1
		for redovi in labFajl.readlines():
			split = redovi.split()
			if not prisustva.has_key(split[0]):
				error(''.join(["Student ", split[0], " u datoteci ", fajla, " ne postoji u datoteci studenata."]))
			if prisustva[split[0]].has_key(vjezba):
				error(''.join(["Student ", split[0], " ima dvostruko prisustvo u grupi ", prisustva[split[0]][vjezba]," i ", grupa, " na vjezbi ", vjezba]) )
			prisustva[split[0]][vjezba] = grupa
			bodovi[split[0]][vjezba] = split[1]

print "     JMBAG        Prezime, Ime",
for lab in sorted(vjezbe):
	for jmbag in bodovi:
		if not bodovi[jmbag].has_key(lab):
			bodovi[jmbag][lab] = 0.0
	print "  L%s" % lab,
print

for jmbag in bodovi:
	print "%10s%20s" % (jmbag, stud[jmbag]),	
	for lab in sorted(bodovi[jmbag]):
		print "%5s" % bodovi[jmbag][lab],
	print
