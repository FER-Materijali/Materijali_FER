## Authors: hrckov
## Desc: Dio komunikacijskog sustava
## Date: 21.12.2010
## Location: University of Zagreb, Faculty of Electrical Engineering and Computing
## Version: 1.0.2


import random

class generiraj:
	def pokreni(self,n,vjerojatnosti):
		self.izlaz=''
		for i in range(0, n):
			a=0
			b=0
			x=random.randint(1,100)
			for j in vjerojatnosti:
				b+=vjerojatnosti[j]*100
				if(x>a and x<(b+1)):
					self.izlaz+=j
				a=b
	

#d={'a':0.4,'b':0.1,'c':0.1,'d':0.2,'e':0.2}
#a=generiraj()
#a.pokreni(100,d)
#print a.izlaz

