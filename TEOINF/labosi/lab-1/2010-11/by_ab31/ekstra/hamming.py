## Authors: hrckov
## Desc: Dio komunikacijskog sustava
## Date: 21.12.2010
## Location: University of Zagreb, Faculty of Electrical Engineering and Computing
## Version: 1.0.2


import math
class hamming_algoritam:
	def paritetna_matrica(self,n,m):
		self.h=[]
		l=[]
		k=n-m
		for i in range(0,k):
			s=0
			g=0
			for j in range(0,n-1):
				if((j+1==2**i) and (s==0)):
					l.append(1)
					s=1
					g=1
				elif(s==0):
					l.append(0)
				
				if((s==1) and (g<2**i)):
					l.append(1)
					g+=1
				elif((s==1) and (g<2*(2**i))):
					l.append(0)
					g+=1
				elif(s==1):
					l.append(1)
					g=1
			self.h.append([])
			self.h[i].extend(l)
			l=[]


	def generirajuca_matrica(self,h):
		x=len(h[0])
		for i in range (0,len(h)):
			s=0
			for j in range(0,len(h)):
				del h[i][(2**j)-s-1]
				s+=1

		l=[]
		for i in range (0,x):
			l.append([])
		for i in range (0,len(h)):
			l[2**i-1].extend(h[i])
		s=0
		for i in range (0,len(l)):
			if(l[i]==[]):
				for j in range (0,len(l[0])):
					l[i].append(0)
				l[i][s]=1
				s+=1
		self.g=[]
		for i in range (0,len(l[0])):
			self.g.append([])
			for j in range (0,len(l)):
				self.g[i].append(l[j][i])
		
class hamming_koder:
	def mnozenje_matrica(self,g,y):
		kod=[]
		for i in range(0, len(g[0])):
			x=0
			for j in range(0,len(g)):
				x+=int(y[j])*int(g[j][i])
			kod.append(str(x%2))
			x=0
		return kod


	def pokreni(self, g, ulaz):
		self.izlaz=''
		s=0
		y=''
		kod=[]
		for i in ulaz:
			if (i=='#'):
				s=len(y)
				y+='0'*(len(g)-len(y))
				kod=self.mnozenje_matrica(g,y)
				m=0
				n=0
				for k in range(0,len(kod)):
					if (k==(2**m-1)):
						self.izlaz+=kod[k]
						m+=1
					elif (n==s):
						self.izlaz+="&"+kod[k]
						n+=1
					else:
						self.izlaz+=kod[k]
						n+=1
				break
			if s!=len(g):
				y+=i
				s+=1
			else:
				kod=self.mnozenje_matrica(g,y)
				self.izlaz+=''.join(kod)
				y=i
				s=1
				del kod
				kod=[]
		self.izlaz+='#'

class hamming_dekoder:
	def mnozenje_matrica(self, h, y):
		syn=[]
		for red in range (0, len(h)):
			x=0
			for stup in range(0,len(h[0])):
				x+=int(y[stup])*int(h[red][stup])
			syn.append(str(x%2))
			x=0
		return syn

	def syn_ispravljanje(self,h,y):
		syn=self.mnozenje_matrica(h,y)
		syn.reverse()
		z=''.join(syn)
		y=list(y)
		if (int(z,2)!=0):
#			print "Pronadjena greska u nizu:",''.join(y),"na indeksu",int(z,2)
			if(y[int(z,2)-1]=='0'):
				y[int(z,2)-1]='1'
			else:
				y[int(z,2)-1]='0'
#			print "Greska ispravljena:      ",''.join(y)
		y=''.join(y)
		return y

	def dekod(self,h,y):
		x=self.syn_ispravljanje(h,y)
		x=list(x)
		k=math.log(float(len(x)),2)+1
		for i in range(0,int(k)):
			del x[2**i-1-i]
		x=''.join(x)
		return x
	
	def pokreni(self,h,ulaz):
		self.izlaz=''
		s=0
		y=''
		l=len(h[0])

		for z in ulaz:

			if(z=='&'):
				
				y=ulaz[len(ulaz)-l-2:len(ulaz)-1]

				y=list(y)

				for i in range(0, len(y)):
					if(y[i]=='&'):

						del y[i]
						break
				i=i-int(math.log(float(i),2))-1
				y=''.join(y)

				y=self.dekod(h,y)
				self.izlaz+=y[:i]
				break
			if(s!=l):

				y+=z
				s+=1
			else:

				self.izlaz+=self.dekod(h,y)
			
				y=z
				s=1
			if(z=="#"):
				break
				

		
		
	





#a=hamming_algoritam()
#a.paritetna_matrica(15,11)

#s=[]
#g=[]
#for i in range (0,len(a.h)):
#	for j in range(0,len(a.h[0])):
#		g.append(a.h[i][j])
#	s.append(g)
#	g=[]
#a.generirajuca_matrica(a.h)
#b=hamming_koder()
#b.pokreni(a.g,'101111#')
#print b.izlaz
#c=hamming_dekoder()
#c.pokreni(s,b.izlaz)
#print c.izlaz
