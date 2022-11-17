## Authors: hrckov
## Desc: Dio komunikacijskog sustava
## Date: 21.12.2010
## Location: University of Zagreb, Faculty of Electrical Engineering and Computing
## Version: 1.0.2


class Cvor:
	vrijednost=''
	vjerojatnost=0
	cvor1='NULL'
	cvor2='NULL'
	kod=''

class huffman_algoritam:

	def minimumi_rjecnika(self,r):
		self.min1=min(r)
		self.min2=min(r)
		if(len(r)==2):
			c=[]
			for x in r:
				c.append(x)
			if r[c[0]]<r[c[1]]:
				self.min1=c[0]
				self.min2=c[1]
			else:
				self.min1=c[1]
				self.min2=c[0]
		else:
			for x in r:
				if r[x].vjerojatnost<=r[self.min1].vjerojatnost:
					if(len(self.min1)<=len(x)):
						self.min1=x
			for x in r:		
				if (r[x].vjerojatnost<=r[self.min2].vjerojatnost and x!=self.min1):
					if(len(self.min2)<=len(x)):
						self.min2=x

	def kod_trazi(self,l,x,kod):
		if(l[x].cvor1=="NULL"):
			self.k[l[x].vrijednost]=kod+l[x].kod
		else:
			self.kod_trazi(l,l[x].cvor1,kod+l[x].kod)
			self.kod_trazi(l,l[x].cvor2,kod+l[x].kod)


	def pokreni(self, vjerojatnosti):
		lista={}
		for i in vjerojatnosti:
			lista[i]=Cvor()
			lista[i].vrijednost=i
			lista[i].vjerojatnost=int(float(vjerojatnosti[i])*100)
		self.min1=''
		self.min2=''
		p=0
		lista1={}
		lista1.update(lista)
		while(p<100):
			p=0
			self.minimumi_rjecnika(lista)
			p=lista[self.min1].vjerojatnost+lista[self.min2].vjerojatnost
			lista[self.min1+self.min2]=Cvor()
			lista[self.min1+self.min2].vjerojatnost=p
			lista[self.min1+self.min2].cvor1=self.min1
			lista[self.min1+self.min2].cvor2=self.min2
			lista[self.min1].kod+='0'
			lista[self.min2].kod+='1'
			lista1.update(lista)
			del lista[self.min1]
			del lista[self.min2]
		self.k={}
		self.kod_trazi(lista1,self.min1+self.min2,'')
		

class huffman_koder:
	def pokreni(self, ulaz, rjecnik):	
		self.izlaz=''
		for i in ulaz:
			self.izlaz+=rjecnik[i]
		self.izlaz+='#'
	
class huffman_dekoder:
	def pokreni(self, ulaz, rjecnik):
		self.izlaz=''
		niz=''
		for i in ulaz:
			niz+=i
			if(rjecnik.has_key(niz)):
				self.izlaz+=rjecnik[niz]
				niz=''
	def val_to_key(self,rjecnik):
		tmp={}
		for i in rjecnik:
			tmp[rjecnik[i]]=i
		return tmp











#d={'a':0.4,'b':0.1,'c':0.1,'d':0.2,'e':0.2}
#a=huffman_algoritam()
#a.pokreni(d)
#b=huffman_koder()
#print a.k
#b.pokreni('aaaaaaabbbbbbbbbbbbcccccccccdddddddddddabcdeeeeeeee', a.k)
#print b.izlaz
#c=huffman_dekoder()
#c.pokreni(b.izlaz,c.val_to_key(a.k))
#print c.izlaz













