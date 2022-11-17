## Authors: hrckov
## Desc: /
## Date: 21.12.2010
## Location: University of Zagreb, Faculty of Electrical Engineering and Computing
## Version: 1.0.2




#################################################
#Izvor ulaznog niza				#
#Program na temelju vjerojatnosti znakova	#
#generira n znakova				#
#################################################
import math
import random
import sys

izlaz = open ('12.txt','w')

vjerojatnosti={'a':40,'b':10, 'c':10, 'd':20, 'e':20}
broj=10000


gen=""
#################################################
#Program generira pseudoslucajni broj izmedju	#
#1 i 100 te na temelju intervala u kojem se broj#
#nalazi odredjuje koji znak generira		#
#################################################
while (broj!=0):
	a=0
	b=0
	x=random.randint(1,100)
	for n in vjerojatnosti:
		b+=vjerojatnosti[n]
		if(x>a and x<(b+1)):
			gen+=n
		a=b
	broj-=1
gen+='#'
izlaz.write(gen)

