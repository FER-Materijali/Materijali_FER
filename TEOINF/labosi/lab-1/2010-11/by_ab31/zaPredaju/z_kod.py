## Authors: hrckov
## Desc: /
## Date: 21.12.2010
## Location: University of Zagreb, Faculty of Electrical Engineering and Computing
## Version: 1.0.2


import sys

#######################################################################
#Generator hammingovih matrica					      #
#Program na temelju ulaznog tipa hammingovog koda 		      #
#izradjuje paritetnu i generirajucu matricu 			      #
#######################################################################



n=15
m=11
##################################################################
#Stvaranje paritetne matrice H					 #
#Matrica H ima n-k stupaca i n redova. Svaki red ima za potenciju#
#broja 2 vise '1' i '0' u nizu					 #
##################################################################
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

			
###################################################################
#Brisanje paritetnih clanova					  #
#Prvi korak u izradi G-a je brisanje paritetnih clanova matrice H.# 
#Paritetni clanovi se nalaze na lokacijama potencija broja 2	  #
###################################################################
g=[]
x=len(h[0])
for i in range (0,len(h)):
	s=0
	for j in range(0,len(h)):
		del h[i][(2**j)-s-1]
		s+=1
		
##################################################################
#Formiranje G^T							 #
#Drugi korak je postaviti redove novodobivene matrice na lokacije#
#potencije broja 2, a ostalo popuniti jedinicnom matricom	 #
##################################################################
l=[]
for i in range (0,x):
	l.append([])
for i in range (0,len(h)):
	l[2**i-1].extend(h[i])
s=0
for i in range (0,len(l)):
	if(l[i]==[]):
		for j in range (0,len(l[0])):
			l[i].append(0)
		l[i][s]=1
		s+=1
#################################################################
#Transponiranje G^t						#
#Transporniranjem nastaje generirajuca matrica G 		#
#################################################################		
for i in range (0,len(l[0])):
	g.append([])
	for j in range (0,len(l)):
		g[i].append(l[j][i])
		
		



######################################################################
#Hammingov koder						     #
#Program kodira ulazni niz hammingovim kodom 			     #
#na temelju ulazne generirajuce matrice G			     #
######################################################################



###############################################################
#Funkcija mnozi generirajucu matricu G i vektor ulaznog niza Y#
#Izvodi se matematicko mnozenje matrica, no vrijednosti se    #
#zaokruzuju na najnizi bit(mod 2)			      #
###############################################################
def mnozenje_matrica():
	global y
	global g
	global kod
	for stup in range (0, len(g[0])):
		x=0
		for red in range(0,len(g)):
			x+=int(y[red])*int(g[red][stup])
		kod.append(str(x%2))
		x=0				
############################################################
#Glavni dio programa: ulaze vec generirana matrica G i niz #
#kodiran huffmanovim kodom, a izlazi kodirani niz          # 
############################################################ 


ulaz2=open(sys.argv[1],'r')
izlaz=open('34.txt','w')

kod=[]

l=len(g)
############################################################
#Ulaz cijelog ulaznog niza				   #
############################################################
x=ulaz2.readline()
s=0
y=''
############################################################
#Razdvajanje ulaznog niza na manje dijelove (11 znakova u  #
#   nasem zadatku) koji se kodiraju hammingovim kodom      #
############################################################
for z in x:
#############################################################
#S obzirom da hammingov kod zahtjeva niz odredjene duljine, # 
#trazimo zavrsni znak naseg ulaznog niza('#') i pamtimo     #
#njegov indeks. Iza zadnjeg znaka nadodamo nizu za kodiranje#
#onoliko '0' koliko treba da duljina niza bude pogodna 	    #
#kodiranju. Nakon sto iskodiramo nadopunjeni niz, prije     #
#prvog nadodanog znaka nadodajemo znak & 		    #
#kako bi dekoder znao koji dio niza zanemariti		    #
#############################################################
	if (z=='#'):
		s=len(y)
		y+='0'*(l-len(y))
		mnozenje_matrica()
		m=0
		n=0
		for k in range(0,len(kod)):
			if (k==(2**m-1)):
				izlaz.write(kod[k])
				m+=1
			elif (n==s):
				izlaz.write("&"+kod[k])
				n+=1
			else:
				izlaz.write(kod[k])
				n+=1
		izlaz.write('#')
		break
############################################################
#Razdvajanje i kodiranje svih znakova osim zadnjeg niza	   #
############################################################
	if s!=l:
		y+=z
		s+=1
	else:
		mnozenje_matrica()
		for k in kod:
			izlaz.write(k)
		y=z
		s=1
		del kod
		kod=[]

	
