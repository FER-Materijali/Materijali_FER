## Authors: hrckov
## Desc: /
## Date: 21.12.2010
## Location: University of Zagreb, Faculty of Electrical Engineering and Computing
## Version: 1.0.2




#################################################################
#Kanal sustava							#
#Program generira pseudoslucajne brojeve i ovisno		#
#o njihovoj vrijednosti mijenja ili ne mijenja ulazne bitove	#
#################################################################


import sys








ulaz=open (sys.argv[1],'r')
izlaz=open ('45.txt','w')

err_vec=''
x=ulaz.readline()
s=0
#########################################
#Unosenje vjerojatnosti pojave greske	#
#########################################


niz=''
err=open(sys.argv[2],'r')
tmp=err.readline()
err_vec=tmp.rstrip()
if(len(err_vec)!=len(x)):
	sys.exit('Vektor greske je krive duljine, ostatak programa ce se krivo izvesti')
	
for i in range(0,len(x)):
	if x[i]=='1' and err_vec[i]=='1':
		niz+='0'
		s+=1
	elif x[i]=='0' and err_vec[i]=='1':
		niz+='1'
		s+=1
	else:
		niz+=x[i]
izlaz.write(niz)			

print 'Smetnjama je promjenjeno',s,'bita'


