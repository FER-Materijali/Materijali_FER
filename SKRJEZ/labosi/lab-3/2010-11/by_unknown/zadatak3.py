import string, re, os;

studenti = dict();
file = open('studenti.txt','rb');

#prolazak kroz sve linije datoteke studenti
#i ucitavanje u rjecnik
for line in file:
	
	line = line.rstrip();
	
	jmbag,ime,prezime = line.split();
	
	#ako je student dvaput upisan, prijavljujemo gresku i ignoriramo dupli zapis
	if(jmbag in studenti):
		print "Greska: Student vec postoji";
	else:
		studenti[jmbag] = {'ime': ime, 'prezime': prezime}
	
	
file.close();

#najvisa vjezba pamti koji je najvisi redni broj lab. vjezbe
najvisa_vj = 0;

dat = os.listdir('.');

for filename in dat:

	m = re.search('^Lab_([0-9]+)_g([0-9]+)\.',filename);

	if(m != None):
		
		vjezba = int(m.group(1));
		grupa = int(m.group(2));
		
		if(vjezba > najvisa_vj): najvisa_vj = vjezba;
		
		file = open(filename,'rb');
		
		for line in file:
			
			line = line.rstrip();
			jmbag, bodovi = line.split();
			
			#ako su definirani bodovi za nepostojeceg studenta, prijavi gresku i nastavi
			if(not jmbag in studenti):
				print "Student ne postoji!", jmbag
				continue;
			
			if(vjezba in studenti[jmbag]):
				print "Greska: Za studenta %s vec su definirani bodovi vjezbe %d" % (jmbag, vjezba);
			else:
				studenti[jmbag][vjezba] = bodovi;
			
		file.close();
		
	#end if m!= none

print ;
	
print "%10s %10s, %10s" % ('JMBAG', 'Prezime', 'Ime'),;

for i in range(1, najvisa_vj+1):
	print "L%d" % i,
	
print;

for k,v in studenti.iteritems():
	
	print "%10s %10s, %10s" % (k,v['prezime'],v['ime']),;
	
	for i in range(1, najvisa_vj+1):
		
		if(i in v): print v[i],;
		else: print "--",;
	
	print;



			
		
	
