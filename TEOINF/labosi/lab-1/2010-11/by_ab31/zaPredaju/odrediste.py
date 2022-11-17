## Authors: hrckov
## Desc: /
## Date: 21.12.2010
## Location: University of Zagreb, Faculty of Electrical Engineering and Computing
## Version: 1.0.2


#################################################################
#Odrediste							#
#Program ispisuje primljeni niz i usporedjuje ga sa pocetnim	#
#################################################################
import sys
ulaz = open (sys.argv[1],'r')
x=ulaz.readline()
if(len(x.rstrip())!=0):
	print "Primljen je niz na odredistu."
else:
	print "Niz nije stigao na odrediste."
	


