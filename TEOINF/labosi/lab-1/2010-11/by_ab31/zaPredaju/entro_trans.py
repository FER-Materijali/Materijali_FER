## Authors: hrckov
## Desc: /
## Date: 21.12.2010
## Location: University of Zagreb, Faculty of Electrical Engineering and Computing
## Version: 1.0.2


import math
import sys

izvor=open(sys.argv[1],'r')
odred=open(sys.argv[2],'r')
#################################
#Prosjecna duljina kodne rijeci
##################################
vjer={'a':40,'b':10, 'c':10, 'd':20, 'e':20}
kod={'a': '0', 'c': '1101', 'b': '1100', 'e': '10', 'd': '111'}
l=0
for i in kod:
	l+=vjer[i]*len(kod[i])/100.0
	
print "Prosjecna duljina kodne rijeci:",l


######################################33
#entropija
###############################
vjOdred={'a':0, 'b':0, 'c':0,'d':0, 'e':0}
y=odred.readline()
for i in y:
	if i=='#':
		break
	vjOdred[i]+=1
print "Znakovi na odredistu:",vjOdred
entOdred=0
for i in vjOdred:
	tmp=vjOdred[i]/10000.0
	tmp1=math.log(tmp,2)
	entOdred-=tmp*tmp1
print "Entropija odredisnog skupa:",entOdred	
#############
vjIzvor={'a':0, 'b':0, 'c':0,'d':0, 'e':0}
x=izvor.readline()
for i in x:
	if i=='#':
		break
	vjIzvor[i]+=1
print "Znakovi na izvoru:",vjIzvor
entIzv=0
for i in vjIzvor:
	tmp=vjIzvor[i]/10000.0
	tmp1=math.log(tmp,2)
	entIzv-=tmp*tmp1
print "Entropija izvorisnog skupa:",entIzv


##########################3
#transinformacija
#############################

uvjVjero={}
if(len(x.rstrip())!=len(y.rstrip())):
	sys.exit("Doslo je do raspada kanala")
#racunanje uvjetnih vjerojatnosti
for i in range (0, len(x)):
	if x[i]=='#':
		break
	if(uvjVjero.has_key(y[i]+'|'+x[i])):
		uvjVjero[y[i]+'|'+x[i]]+=1
	else:
		uvjVjero[y[i]+'|'+x[i]]=1
#racunanje uvjetne entropije
znakovi=['a','b','c','d','e']
ent=0
for i in znakovi:
	for j in uvjVjero:
		if(j[2]==i):
			tmp=uvjVjero[j]/float(vjIzvor[i])
			tmp1=math.log(tmp,2)
			ent-=(vjIzvor[i]/10000.0)*tmp*tmp1
			
print "Transinformacija je:",entOdred-ent
			
			
	
	
