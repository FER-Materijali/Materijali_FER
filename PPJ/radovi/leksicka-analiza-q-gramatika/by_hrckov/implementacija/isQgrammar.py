## Author: hrckov
## Desc: SSP iz PPJ; Provjera da li je gramatika Q-gramatika 
## Date: 21.12.2010
## Location: University of Zagreb, Faculty of Electrical Engineering and Computing
## Version: 1.0.0

import sys

def str_u_niz(ulaz):
	s=''
	niz=[]
	z=0
	for i in ulaz:
		if i=='<':
			s+=i
			z=1
		elif i=='>':
			s+=i
			niz.append(s)
			s=''
			z=0
		elif i!=':' and i!='=' and z==0:
			niz.append(i)
		elif z==1:
			s+=i
	return niz

def provjeri_prvi_lijevi_znak(produkcija):
	if len(produkcija[1])!=1:
		izlaz()

def grupirajProdukcije(primjeni):
	for i in primjeni:
		for j in primjeni:
			if primjeni[i][1]==primjeni[j][1] and i!=j:
				#print i,j
				for k in primjeni[i][0]:
					for l in primjeni[j][0]:
						#print k,l
						if k==l:
							izlaz()
		



def racunajPrimjeni(nizProd):
	if nizProd[1]!='$':
		return nizProd[1]
	else:
		return racunajSlijedi(nizProd[0])

def SlijediPrimjeni(kljuc):
	k=[]
	global prod
	for i in prod:
		if i[0]==kljuc:
			k.append(racunajPrimjeni(i))
	return k

def racunajSlijedi(kljuc):
	global prod
	k=[]
	for pr in prod:
		for i in range(1,len(pr)-1):
			if pr[i]==kljuc:
				if len(pr[i+1])!=1:
					k.extend(SlijediPrimjeni(pr[i+1]))				
				else:
					k.append(pr[i+1])


	return ''.join(list(set(k)))
				



def pretvori(ulaz):
	izlaz=[]
	print ulaz
	for j in ulaz:
		tmp=[]
		tmp.append(j[0])
		if len(j)==1:
			tmp.append('$')
			izlaz.append(tmp)
			tmp=[]
			continue
		if(j[len(j)-1]=='|'):
			tmp.append('$')
			izlaz.append(tmp)
			tmp=[]
			tmp.append(j[0])
		for i in range(1,len(j)):
			if j[i]!='|':
				tmp.append(j[i])
			else:
				izlaz.append(tmp)
				tmp=[]
				tmp.append(j[0])
		if j[len(j)-1]!='|':
			izlaz.append(tmp)
	return izlaz



def izlaz():
	print "Zadana gramatika nije Q-gramatika"
	sys.exit()


if len(sys.argv)!=2:
	print "Krivo pokrenut program!\nNije definirana datoteka sa gramatikom."
	sys.exit()

fajl=open(sys.argv[1],'r')
ulaz=fajl.readlines()
produkcije=[]
primjeni={}

print "Produkcije:"
for i in ulaz:
	print i.rstrip()
	produkcije.append(str_u_niz(i.rstrip()))
print "Ekvivalentne produkcije:"


prod=[]
prod.extend(pretvori(produkcije))
for i in prod:
	print i[0],"::=",''.join(i[1:])
	provjeri_prvi_lijevi_znak(i)
	primjeni[''.join(i)]=racunajPrimjeni(i),i[0]
print "Skup primjeni pojedine produkcije je:"
for i in primjeni:
	print "PRIMJENI[",i.rstrip(),"]={",primjeni[i][0],"}"

grupirajProdukcije(primjeni)

print "Zadana gramatika je Q-gramatika"


