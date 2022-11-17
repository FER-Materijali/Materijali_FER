## Authors: hrckov
## Desc: /
## Date: 21.12.2010
## Location: University of Zagreb, Faculty of Electrical Engineering and Computing
## Version: 1.0.2



import sys
import math

##################################################################
#Stvaranje paritetne matrice H					 #
#Matrica H ima n-k stupaca i n redova. Svaki red ima za potenciju#
#broja 2 vise '1' i '0' u nizu					 #
##################################################################


n=15
m=11
h=[]
l=[]

k=n-m
for i in range(0,k):
	s=0
	g=0
	for j in range(0,n-1):
		if((j+1==2**i) and (s==0)):
			l.append(1)
			s=1
			g=1
		elif(s==0):
			l.append(0)
		
		if((s==1) and (g<2**i)):
			l.append(1)
			g+=1
		elif((s==1) and (g<2*(2**i))):
			l.append(0)
			g+=1
		elif(s==1):
			l.append(1)
			g=1
	h.append([])
	h[i].extend(l)
	l=[]



#########################################################
#Hammingov dekoder					#
#Program dekorira ulazni niz kodiran hammingovim kodom	#
#na temelju matrice provjere pariteta H			#
#########################################################


#########################################################
#Funkcija mnozi ulazni vektor i matricu 		#
#provjere pariteta H. Funkcija vraca vektor sindroma	#
#########################################################

def mnozenje_matrica():
	global y
	global h
	global syn
	for red in range (0, len(h)):
		x=0
		for stup in range(0,len(h[0])):
			x+=int(y[stup])*int(h[red][stup])
		syn.append(str(x%2))
		x=0

#################################################################
#Funkcija pretvara sindrom u brojevnu vrijednost -> indeks	#
#neispravno prenesenog bita, te ispravlja pogresku.		#
#Sindrom je nul-vektor ukoliko je niz ispravan, a binarna 	#
#vrijednost indeksa krivo neispravno prenesenog bita ako nije	#
#################################################################
def syndrom_ispravljanje():
	global y
	global syn
	global suma
	mnozenje_matrica()
	syn.reverse()
	z=''.join(syn)
	y=list(y)
	if (int(z,2)!=0):
		#print "Pronadjena greska u nizu:",''.join(y),"na indeksu",int(z,2)
		if(y[int(z,2)-1]=='0'):
			y[int(z,2)-1]='1'
		else:
			y[int(z,2)-1]='0'
		#print "Greska ispravljena:      ",''.join(y)
		suma+=1
	y=''.join(y)
#################################################################
#Funkcija uklanja zastitne bitove iz ispravljenog izlaznog niza.#
#Zastitni bitovi se nalaze na lokacijama potencija broja 2.	#
#################################################################
def dekod():
	global y
	syndrom_ispravljanje()
	y=list(y)
	k=math.log(float(len(y)),2)+1
	for x in range(0,int(k)):
		del y[2**x-1-x]
	y=''.join(y)

#########################################################################
#Glavni dio programa, ulaze generirana matrica provjere pariteta H	#
#i niz sa izlaza kanala, a izlazi dekodirani niz.			#
#########################################################################

ulaz=open(sys.argv[1],'r')
izlaz=open('56.txt','w')
suma=0
l=len(h[0])
#########################
#Ulaz ulaznog niza	#
#########################
x=ulaz.readline()
s=0
syn=[]
y=''
#########################################################
#Razdvajanje ulaznog niza na manje dijelove(15 bita 	#
#za hammingov kod [15 11 3]) koji se dekodiraju		#
#########################################################
for z in x:
#########################################################################
#S obzirom da hammingov kod zahtjeva kod odredjene duljine, koder je 	#
#po potrebi prosirio zadnji niz nulama i prije prosirenja dodao znak '&'#
#Kada dekoder naidje na taj znak ucitava ostatak ulaznog niza u buffer,	#
#uklanja znak '&', no pamti mu indeks. Nakon dekodiranja uklanja se 	#
#visak niza ovisno o indeksu umanjenom za broj zastitnih bitova.	#
#########################################################################
	if(z=='&'):
		y=x[len(x)-l-2:len(x)-1]
		y=list(y)
		for i in range(0, len(y)):
			if(y[i]=='&'):
				del y[i]
				break
		i=i-int(math.log(float(i),2))-1
		y=''.join(y)
		dekod()
		izlaz.write(y[:i])
		break
#########################################
#Dekodiranje svih nizova osim zadnjeg	#
#########################################
	if(s!=l):
		y+=z
		s+=1
	else:
		dekod()
		izlaz.write(y)
		y=z
		s=1
		del syn
		syn=[]
	if (y=='#'):
		izlaz.write('#')
		break
izlaz.write('#')
print "Ispravljeno",suma,"gresaka"
