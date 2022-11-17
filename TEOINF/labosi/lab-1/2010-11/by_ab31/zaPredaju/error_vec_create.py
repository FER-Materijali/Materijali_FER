## Authors: hrckov
## Desc: /
## Date: 21.12.2010
## Location: University of Zagreb, Faculty of Electrical Engineering and Computing
## Version: 1.0.2



import random
import sys


def stvori_vektor():
#########################################################
#Za svaki ucitani bit funkcija generira pseudoslucajni	#
#broj iz intervala [1,20] i ako broj pada u podinterval	#
#[1,a] mijenja mu vrijednost 0->1, 1->0			#
#########################################################

	global x
	global err_vec
	for i in x:
		n=random.randint(1,20)
		if(n<=1):
			err_vec+='1'
		else:
			err_vec+='0'

#########################################################
#Funkcija stvara prazan vektor pogreske(sve 0)		#
#########################################################		
def prazan_vektor():
	global x
	global err_vec
	for i in x:
		err_vec+='0'
		
err_vec=''		
ulaz=open (sys.argv[2],'r')
x=ulaz.readline()
if(sys.argv[1]=='0'):
	prazan_vektor()
else:
	stvori_vektor()
	
izlaz1=open(sys.argv[3],'w')
izlaz1.write(err_vec)












