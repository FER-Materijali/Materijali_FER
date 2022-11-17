## Authors: hrckov
## Desc: Dio komunikacijskog sustava
## Date: 21.12.2010
## Location: University of Zagreb, Faculty of Electrical Engineering and Computing
## Version: 1.0.2


import random
class kanal:
	def smetnje(self,ulaz,n,m):
		for i in ulaz:
			a=random.randint(1,m)
			if(a<=n and i=='1'):
				i='0'
				self.br_promjena+=1
			elif(a<=n and i=='0'):
				i='1'
				self.br_promjena+=1
			self.izlaz+=i
	def pokreni(self,ulaz,smet,n,m):
		self.br_promjena=0
		self.izlaz=''
		if (smet==0):
			self.izlaz=ulaz
		else:
			self.smetnje(ulaz,n,m)

#a=kanal()
#a.pokreni('01111111110000000000000000000001111111111111111111111110000000000000000', 0,0,0)
#print a.izlaz+"a"
#a.pokreni('01111111110000000000000000000001111111111111111111111110000000000000000', 1,1,20)
#print a.izlaz+"b"

