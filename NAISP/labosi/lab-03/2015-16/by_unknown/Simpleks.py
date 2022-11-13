from __future__ import division
import numpy as np

class Tablica:

	def __init__(self, obj):

		self.obj = [1] + obj # zj-cj
		self.redovi = [] # red
		self.uvjet = [] # uvjeti

	def uvjeti(self, izraz, vrijednost): # dodavanje uvjeta
		self.redovi.append([0] + izraz) # dodaj jednadzbu uvjeta
		self.uvjet.append(vrijednost) # dodaj vrijednost

	def _stupac_pivot(self):
		min = 0 # trazimo stupac pivota
		idstup = 0 # id stupca za pivot		
		for i in range(1, len(self.obj)-1): # idemo po svim stupcima
			if self.obj[i] < min: 
				min = self.obj[i] # ako je manji spremi min i idstupca
				idstup = i
		if idstup == 0: return -1 # ako je idstup 0, nismo nasli stupac pivota
		return idstup # vrati stupac pivota

	def _redovi_pivot(self, col): # trazimo redovi pivot
		rezultatdesno = [self.redovi[i][-1] for i in range(len(self.redovi))] # desni rezultat, rhs
		vrijednostlijevo = [self.redovi[i][col] for i in range(len(self.redovi))] #lijevi lhs
		omjer = [] # omjeri kad dijelimo
		for i in range(len(rezultatdesno)): # koliko ima vrijednosti s desne strane
			if vrijednostlijevo[i] == 0: # ako je vrijednost lijevo 0, bazicna vrijednost
				omjer.append(99999999 * abs(max(rezultatdesno))) # omjer je jako veliki broj, trazimo najmanji
				continue
			omjer.append(rezultatdesno[i]/vrijednostlijevo[i]) # izracunaj tocni omjer
		return np.argmin(omjer) # vrati min od svih omjera, to je red pivota

	def prikaz(self): # ispis matrice s numpy
		print '\n', np.matrix(self.redovi + [self.obj])

	def _element_pivot(self, red, col): #trazenje novog pivot elementa
		trenutna_vrijednost = self.redovi[red][col] # trenutni pivot je u red i stupcu
		self.redovi[red] /= trenutna_vrijednost # dijelimo cijeli red s pivotom, s tim redom radimo matricne operacije
		for r in range(len(self.redovi)): # idemo po svim redovima matricne operacije oduzimanja
			if r == red: continue # ako je red pivota preskacemo
			#print self.redovi[r]
			#print '\n'
			#print self.redovi[r][col]*self.redovi[red]
			#raw_input("PAUZA ODUZIMANJE")
			self.redovi[r] = self.redovi[r] - self.redovi[r][col]*self.redovi[red] # radimo oduzimanje za jedinicu matricu, matricne operacije
		self.obj = self.obj - self.obj[col]*self.redovi[red] # racunanje zj-cj


	def _provjera(self):
		if min(self.obj[1:-1]) >= 0: return 1 # ako imam bilo koji broj veci od u zj-cj idemo na sljedecu iteraciju
		return 0

	def izracunaj(self):
		#print self.obj
		#raw_input("PAUZA self obj")
		for i in range(len(self.redovi)): # po svim redovima
			self.obj += [0] # dodaj nulu za svaki red, zj-cj
			#print self.obj
			#raw_input("PAUZA self obj dodana nula")
			ident = [0 for r in range(len(self.redovi))] # u ident dodaj nula koliko imamo pomocnih varijabla
			#print ident
			#raw_input("PAUZA ident u nule")
			ident[i] = 1 #postavi ga u 1 za trenutni red
			#print ident
			#print self.redovi[i]
			#raw_input("PAUZA ident postavljen 1")
			self.redovi[i] += ident + [self.uvjet[i]] # dodajemo ident za jedinicu matricu te rhs iz uvjeta
			#print self.redovi[i]
			#print self.uvjet[i]
			#raw_input("PAUZA self.redovi[i]")
			self.redovi[i] = np.array(self.redovi[i], dtype=float) # napravi float polje, gotov red
			#print self.redovi[i]
			#raw_input("PAUZA self.redovi[i] 2")
		self.obj = np.array(self.obj + [0], dtype=float) # racunanje zj-cj, zapis u self.obj
		#print self.redovi 
		#print '\n'
		#print [self.obj]
		#raw_input("PAUZA")
		self.prikaz() # prikazi iteraciju

		
		while not self._provjera(): # dok imamo brj veci od 1, sljedeca iteracija, vidi _provjera
			pstupac = self._stupac_pivot() # novi stupac pivota
			pred = self._redovi_pivot(pstupac) # novi red pivota 
			self._element_pivot(pred, pstupac) # imamo pivot, izracunaj novu iteraciju
			print '\npivot stupac: %s\npivot red: %s'%(pstupac+1,pred+1) # ispis stupca i reda
			self.prikaz() # prikaz iteracije



if __name__ == '__main__':

	izracun = Tablica([-1,-3,-2]) # 2x,3y,2z
	izracun.uvjeti([1, 1, 1], 10) # prvi uvjet
	izracun.uvjeti([1, 1, 0], 8) # drugi uvjet
	izracun.uvjeti([2, 1, 1], 10) # treci uvjet
	izracun.uvjeti([0, 0, 1], 5) # cetvrti uvjet

	izracun.izracunaj() # izracunaj