## Authors: hrckov
## Desc: Dio komunikacijskog sustava
## Date: 21.12.2010
## Location: University of Zagreb, Faculty of Electrical Engineering and Computing
## Version: 1.0.2


class odrediste:
	vjerojatnost_i={}
	vjerojatnost_o={}
	def pokreni(self,ulaz):
		vjerojatnosti={}
		for i in ulaz:
			if(vjerojatnosti.has_key(i)):
				vjerojatnosti[i]+=1
			else:
				vjerojatnosti[i]=1
		return vjerojatnosti
#a=odrediste()
#a.vjerojatnost_i=a.pokreni('aaaaddddeeecccc')
#print a.vjerojatnost_i
#a.vjerojatnost_o=a.pokreni('aaaaddddddeeeeaaaaaaaaabdeeecccc')
#print a.vjerojatnost_o
