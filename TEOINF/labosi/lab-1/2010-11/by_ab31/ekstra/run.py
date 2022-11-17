## Authors: hrckov
## Desc: Dio komunikacijskog sustava
## Date: 21.12.2010
## Location: University of Zagreb, Faculty of Electrical Engineering and Computing
## Version: 1.0.2


from Tkinter import *
from hamming import *
from huffman import *
from izvor import *
from kanal import *
from odrediste import *

class Sucelje:
	def __init__(self,master):
		
		self.izv=generiraj()
		self.huff_ko=huffman_koder()
		self.huff_de=huffman_dekoder()
		self.huff_alg=huffman_algoritam()
		self.hamm_ko=hamming_koder()
		self.hamm_de=hamming_dekoder()
		self.hamm_alg=hamming_algoritam()
		self.kan=kanal()
		self.odr=odrediste()

		Label(master,text="Vjerojatnost\nizvora").grid(row=0, column=0,sticky=W)
		self.t1=Text(master, width=10, height=10)
		self.t1.grid(row=1, column=0, rowspan=5, columnspan=1, sticky=W)

		Label(master, text="Vjerojatnost\nkanala").grid(row=6, column=0, sticky=W)
		self.e7=Entry(master, width=10)
		self.e7.grid(row=7, column=0, sticky=W)

		Label(master, text="Tip Hammingovog\nkodera").grid(row=8, column=0, sticky=W)
		self.e8=Entry(master, width=10)
		self.e8.grid(row=9, column=0, sticky=W)

		Label(master, text="Broj znakova za\ngenerirati").grid(row=10, column=0, sticky=W)
		self.e9=Entry(master, width=10)
		self.e9.grid(row=11, column=0, sticky=W)

			
		Label(master,text="Generirani niz").grid(row=0, column=1, sticky=W)
		self.e1=Entry(master, width=100)
		self.e1.grid(row=1, column=1, rowspan=1, columnspan=10)

		Label(master,text="Niz kodiran Huffmanovim kodom").grid(row=2, column=1, sticky=W)
		self.e2=Entry(master, width=100)
		self.e2.grid(row=3, column=1, rowspan=1, columnspan=10)
		
		Label(master, text="Niz kodiran Hammingovim kodom").grid(row=4, column=1, sticky=W)
		self.e3=Entry(master, width=100)
		self.e3.grid(row=5, column=1, rowspan=1, columnspan=10)
		
		Label(master, text="Niz na izlazu kanala").grid(row=6, column=1, sticky=W)
		self.e4=Entry(master, width=100)
		self.e4.grid(row=7, column=1, rowspan=1, columnspan=10)
		
		Label(master, text="Niz dekodiran Hammingovim dekoderom").grid(row=8, column=1, sticky=W)
		self.e5=Entry(master, width=100)
		self.e5.grid(row=9, column=1, rowspan=1, columnspan=10)
		
		Label(master, text="Niz dekodiran Huffmanovim dekoderom").grid(row=10, column=1, sticky=W)
		self.e6=Entry(master, width=100)
		self.e6.grid(row=11, column=1, rowspan=1, columnspan=10)
		
		self.smetnje=IntVar()
		self.c1=Checkbutton(master, text="Kanal sa smetnjama", variable=self.smetnje)
		self.c1.grid(row=13, column=0, sticky=W)

		Label(master, text="Generirajuca matrica").grid(row=12, column=1, sticky=W)
		Label(master, text="Matrica provjere pariteta").grid(row=12, column=3, sticky=W)
		Label(master, text="Broj znakova").grid(row=12, column=5, sticky=W)
		Label(master, text="Huffmanov kod").grid(row=12, column=7, sticky=W)
		self.t2=Text(master, width=30, height=10)
		self.t2.grid(row=13, column=1, rowspan=5, columnspan=1, sticky=W)
		self.t3=Text(master, width=30, height=10)
		self.t3.grid(row=13, column=3, rowspan=5, columnspan=1, sticky=W)
		self.t4=Text(master, width=20, height=10)
		self.t4.grid(row=13, column=5, rowspan=5, columnspan=1, sticky=W)
		self.t5=Text(master, width=10, height=10)
		self.t5.grid(row=13, column=7, rowspan=5, columnspan=1, sticky=W)
		
		Label(master, text="Broj promijenjenih bita").grid(row=12, column=10, sticky=W)
		self.e10=Entry(master)
		self.e10.grid(row=13, column=10, sticky=W)
		Label(master, text="Rezultat").grid(row=15, column =10, sticky=W)
		self.e11=Entry(master, width=30)
		self.e11.grid(row=16, column=10, columnspan=2, sticky=W)		
		
		Button(master, text="Pokreni", fg="blue", command=self.pokreni).grid(row=1, column=11, sticky=E)
		Button(master, text="Pomoc", fg="black", command=self.help).grid(row=3, column=11, sticky=E)		
		Button(master, text="Reset", fg="black", command=self.reset).grid(row=5, column=11, sticky=E)
		Button(master, text="Izlaz", fg="red", command=quit).grid(row=7, column=11, sticky=E)
		


		self.t1.insert(INSERT,"a 0.4\nb 0.1\nc 0.1\nd 0.2\ne 0.2")
		self.e7.insert(INSERT,"1 20")
		self.e8.insert(INSERT,"15 11")
		self.e9.insert(INSERT,"100")
		
	def pokreni(self):
		self.reset()
		n=int(self.e9.get())
		a=self.t1.get(1.0,END)
		a=a.split()
		vjero={}		
		for i in range(0,len(a)/2):
			vjero[a[2*i]]=float(a[2*i+1])
		self.izv.pokreni(n,vjero)
		self.huff_alg.pokreni(vjero)
		self.huff_ko.pokreni(self.izv.izlaz, self.huff_alg.k)

		a=self.e8.get()
		a=a.split()
		self.hamm_alg.paritetna_matrica(int(a[0]), int(a[1]))
		s=[]
		g=[]
		for i in range (0,len(self.hamm_alg.h)):
			for j in range(0,len(self.hamm_alg.h[0])):
				g.append(self.hamm_alg.h[i][j])
			s.append(g)
			g=[]
		self.hamm_alg.generirajuca_matrica(self.hamm_alg.h)
		self.hamm_ko.pokreni(self.hamm_alg.g,self.huff_ko.izlaz)
		
		a=self.e7.get()
		a=a.split()
		self.kan.pokreni(self.hamm_ko.izlaz, self.smetnje.get(), int(a[0]),int(a[1]))
		self.hamm_de.pokreni(s, self.kan.izlaz)
		self.huff_de.pokreni(self.hamm_de.izlaz, self.huff_de.val_to_key(self.huff_alg.k))

		self.odr.vjerojatnost_i=self.odr.pokreni(self.izv.izlaz)
		self.odr.vjerojatnost_o=self.odr.pokreni(self.huff_de.izlaz)

		self.e1.insert(INSERT,self.izv.izlaz)
		self.e2.insert(INSERT,self.huff_ko.izlaz)
		self.e3.insert(INSERT,self.hamm_ko.izlaz)
		self.e4.insert(INSERT,self.kan.izlaz)
		self.e5.insert(INSERT,self.hamm_de.izlaz)
		self.e6.insert(INSERT,self.huff_de.izlaz)

		for i in range(0,len(self.hamm_alg.g)):
			for j in self.hamm_alg.g[i]:
				self.t2.insert(CURRENT,j)
			self.t2.insert(CURRENT,"\n")

		for i in range(0,len(s)):
			for j in s[i]:
				self.t3.insert(CURRENT,j)
			self.t3.insert(CURRENT,"\n")

		for i in self.odr.vjerojatnost_i:
			self.t4.insert(CURRENT,(str(i)+" "+str(self.odr.vjerojatnost_i[i])+" "+str(self.odr.vjerojatnost_o[i])+"\n"))

		for i in self.huff_alg.k:
			self.t5.insert(CURRENT,(str(i)+" "+str(self.huff_alg.k[i])+"\n"))
		self.e10.insert(INSERT, self.kan.br_promjena)


		if(self.izv.izlaz==self.huff_de.izlaz):
			self.e11.insert(INSERT, "Dekodirani niz je jednak ulaznom")
		else:
			self.e11.insert(INSERT, "Dekodirani niz nije jednak ulaznom")



	def help(self):
		pomoc=Toplevel()
		pomoc.title("Pomoc")
		pomoc.minsize(100, 100)
		pt=Text(pomoc)
		pt.grid(row=0, column=0, sticky=W)
		ulaz=open('readme.txt','r')		
		x=ulaz.readline()
		while(x):
			pt.insert(CURRENT,x)
			x=ulaz.readline()
		pt.state=DISABLED
		Button(pomoc, text="Izlaz", fg="red", command=pomoc.destroy).grid(row=1, column=1, sticky=W)

	def reset(self):
		self.e1.delete(0, END)
		self.e2.delete(0, END)
		self.e3.delete(0, END)
		self.e4.delete(0, END)
		self.e5.delete(0, END)
		self.e6.delete(0, END)
		self.e10.delete(0, END)
		self.e11.delete(0, END)
		
		self.t2.delete(1.0, END)
		self.t3.delete(1.0, END)
		self.t4.delete(1.0, END)
		self.t5.delete(1.0, END)



root=Tk()
root.title("Simulator komunikacijskog sustava")
root.minsize(500,500)
nes=Sucelje(root)
root.mainloop()

