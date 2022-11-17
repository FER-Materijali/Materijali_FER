## Authors: hrckov
## Desc: /
## Date: 21.12.2010
## Location: University of Zagreb, Faculty of Electrical Engineering and Computing
## Version: 1.0.2


import sys
#################################################################################################################################
#Generator huffmanovog koda													#
#Program na temelju ulaznih vjerojatnosti i znakova stvara kod									#
#################################################################################################################################

#########################################################
#Klasa cvor predstavlja cvor binarnog stabla koje	#
#generira huffmanov kod					#
#########################################################
class Cvor:
	vrijednost=""
	vjerojatnost=0
	cvor1="NULL"
	cvor2="NULL"
	kod=""
#################################################################
#Funkcija minimumi_rjecnika pronalazi 2 clana sa najmanjim	#
#vjerojatnostima, prednost dobivaju duzi nizovi			#
#(ab[0.1] ima prednost nad c[0.1]) 				#
#################################################################
def minimumi_rjecnika(r):
	global min1
	min1=min(r)
	global min2
	min2=min(r)
	if(len(r)==2):
		c=[]
		for x in r:
			c.append(x)			
		if r[c[0]]<r[c[1]]:
			min1=c[0]
			min2=c[1]
		else:
			min1=c[1]
			min2=c[0]



	else:
		for x in r:

			if r[x].vjerojatnost<=r[min1].vjerojatnost:
				if(len(min1)<=len(x)):
					min1=x

		for x in r:

	
			if (r[x].vjerojatnost<=r[min2].vjerojatnost and x!=min1):
				if(len(min2)<=len(x)):
					min2=x
#########################################################################
#Funkcija kod_trazi rekurzivno pretrazuje sve cvorove			# 
#do listova(sljedeci cvor=NULL) i pridruzuje kod jednog cvora iducem	#			
#time se stvara huffmanov kod						#
#########################################################################
def kod_trazi(l,x,kod):
	global k
	if(l[x].cvor1=="NULL"):
		k[l[x].vrijednost]=kod+l[x].kod
	else:
		kod_trazi(l,l[x].cvor1,kod+l[x].kod)
		kod_trazi(l,l[x].cvor2,kod+l[x].kod)



#########################################
#Ulaz u program				#
#########################################

ulaz_vjero={'a':40,'b':10, 'c':10, 'd':20, 'e':20}

d={}

#################################################################
#Stvaranje listova						#
#Vjerojatnosti su spremljene kao integer radi lakseg rada	#
#Program prihvaca ulaz sa dvostrukom preciznosti (0.xy)		#
#################################################################

for i in ulaz_vjero:
	d[i]=Cvor()
	d[i].vrijednost=i
	d[i].vjerojatnost=ulaz_vjero[i]

min1=''
min2=''
p=0
l={}
l.update(d)
#################################################################
#Stvaranje cvorova binarnog stabla				#
#U rjecniku d su pohranjeni cvorovi sa kojima trenutno radimo,	#
#dok su u rjecniku l pohranjeni svi cvorovi.			#
#Iz rjecnika d uzimamo dva clana sa najmanjim vjerojatnostima, 	#
#pridodajemo im kodne bitove, te od njih stvaramo novi cvor sa 	#
#zbrojenim vjerojatnostima, dok njih premjestamo u rjecnik l	#
#################################################################
while(p<100):

	p=0
	minimumi_rjecnika(d)
	p=p+d[min1].vjerojatnost+d[min2].vjerojatnost
	d[min1+min2]=Cvor()
	d[min1+min2].vjerojatnost=p
	d[min1+min2].cvor1=min1
	d[min1+min2].cvor2=min2	
	d[min1].kod+='0'
	d[min2].kod+='1'
	l.update(d)
	del d[min1]
	del d[min2]

#########################################
#Pozivamo funkciju trazenja koda	#
#########################################
x=min1+min2
k={}
kod_trazi(l,x,"")



#########################################################################################################################################
#Huffmanov koder															#
#Program na temelju ulaznog niza znakova 												#
#i ulaznog niza kodova zapisuje kodirani niz												#
#########################################################################################################################################


ulaz=open(sys.argv[1],'r')
izlaz=open('23.txt','w')
x=ulaz.readline()


y=""
#################################
#Kodiranje niza			#
#################################
for s in x:
	if(s!="#\n" and s!='#'):
		y+=k[s]
y+='#';
izlaz.write(y)

