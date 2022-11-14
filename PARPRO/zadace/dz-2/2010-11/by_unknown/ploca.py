from __future__ import print_function

class Ploca():
    # vanjski pozivi rade s brojevima stupaca 1-7
    # interno, radi se s indeksima
    
    OZNAKA_CPU = 1
    OZNAKA_IGRAC = 2
    
    def _dodaj_redak(self):
        self.polje.append([0] * 7)
    
    def _ukupno_redaka(self):
        return len(self.polje)
    
    def __init__(self):
        self.privremena_oznaka = 't'
        # napravi 6*7 polje nula
        self.polje = []
        i = 0
        while (i < 6):
            self._dodaj_redak()
            i += 1
    
    """ ******** VANJSKE ***************"""
        
    def odigraj_potez(self, oznaka, stupac):
        if stupac > 7 or stupac < 1:
            return
        
        # provjeri treba li povecati polje
        if self.polje[len(self.polje)-1][stupac - 1] != 0:
            self._dodaj_redak()
        
        #pronadi zadnju oznaku i dodaj iznad nje    
        i = len(self.polje) -1
        while (i >=0):
            if self.polje[i][stupac - 1] != 0:
                self.polje[i + 1][stupac - 1] = oznaka
                break
            i -= 1
        else:
            # inace, ako nema, dodaj na dno polja
            self.polje[0][stupac - 1] = oznaka
    
    def ponisti_potez(self, stupac):
        if stupac > 7 or stupac < 1:
            return
        # ukloni oznaku
        i = self._ukupno_redaka() - 1
        while (i >= 0):
            if self.polje[i][stupac-1] != 0:
                self.polje[i][stupac-1] = 0
                break
            i -= 1
        
        # provjeri treba li smanjiti polje
        # ispusteno, zasad
            
    def ispisi_polje(self):
        for x in range(1,8):
            print(x, sep=' ', end=' ')
        print()
        print('-' * 14)
        
        for x in reversed(self.polje):
            i = 0
            while (i < len(x)):
                print(x[i], sep=' ', end=' ')
                i += 1
            print() # \n
        print()
            
    def provjeri_kraj(self, zadnji_potez):
        # vanjska! - prima 1-7
        # vraca poruku oblika (bool gotovo, oznaka)
        
        # provjera ulaznog argumenta
        if zadnji_potez<1 or zadnji_potez>7:
            return
        
        # ima li ista u stupcu?
        if self.polje[0][zadnji_potez - 1] == 0:
            return (False, 0)
        
        # pronadi indekse zadnje plocice (stupac vec imamo)
        i = len(self.polje) -1
        while(i >= 0):
            if self.polje[i][zadnji_potez - 1] != 0:
                break
            i -= 1
        
        indeksi = (i, zadnji_potez - 1)
        oznaka = self.polje[indeksi[0]][indeksi[1]]
        
        # provjera vodoravno
        (lista, indeks) = self._dohvati_redak(indeksi)
        if self._provjeri_listu(lista, indeks) == True:
            return (True, oznaka)
        
        # provjera okomito
        (lista, indeks) = self._dohvati_stupac(indeksi)
        if self._provjeri_listu(lista, indeks) == True:
            return (True, oznaka)
        
        # provjera dijagonalno /
        (lista, indeks) = self._dohvati_lijevu_dijagonalu(indeksi)
        if self._provjeri_listu(lista, indeks) == True:
            return (True, oznaka)
        # provjera dijagonalno \
        
        (lista, indeks) = self._dohvati_desnu_dijagonalu(indeksi)
        if self._provjeri_listu(lista, indeks) == True:
            return (True, oznaka)

        # inace
        return (False, 0)
    
    
    
    
    """ ********** Provjere dovrsenosti *********** """
    
    def _provjeri_listu(self, lista, indeks):
        # provjerava listu od indeksa u potrazi za 4 slijedna znaka
        
        oznaka = lista[indeks]
        
        # pomici se ulijevo koliko mozes
        i = indeks
        while i > 0 and lista[i - 1] == oznaka:
            i -= 1

        #print (lista, indeks, oznaka, i)

        # provjeri niz
        if lista[i : i + 4] == [oznaka] * 4:
            return True
        else:
            return False
            
    
    def _dohvati_redak(self, indeksi):
        # indeksi su redak i stupac elementa ciji redak trazimo
        # povratne vrijednosti su lista elemenata retka (udesno) i indeks 
        # trazenog elementa u listi
        # manje vise ovo je tu samo zbog preglednosti i logicke organizacije
        
        if indeksi[0] < 0 or indeksi[0] >= self._ukupno_redaka():
            return
        
        redak = self.polje[indeksi[0]]
        indeks = indeksi[1]
        
        return (redak, indeks)
    
    def _dohvati_stupac(self, indeksi):
        # indeksi su redak i stupac elementa ciji stupac trazimo
        # povratne vrijednosti su lista elemenata stupca (odozdo) i indeks 
        # trazenog elementa u listi
        
        if indeksi[0] < 0 or indeksi[0] >= self._ukupno_redaka():
            return
        
        # radi jednostavnosti elementu cemo pridjeliti privremenu oznaku

        oznaka = self.polje[indeksi[0]][indeksi[1]]
        self.polje[indeksi[0]][indeksi[1]] = self.privremena_oznaka
    
        stupac = []
        i = 0
        j = self._ukupno_redaka()
        while (i < j):
            stupac.append(self.polje[i][indeksi[1]])
            i += 1
        
        indeks = stupac.index(self.privremena_oznaka)
        self.polje[indeksi[0]][indeksi[1]] = oznaka
        stupac[indeks] = oznaka
        
        return (stupac, indeks)
    
    def _dohvati_lijevu_dijagonalu(self, indeksi):
        # lijeva dijagonala je /
        
        i = indeksi[0]
        j = indeksi[1]
        
        # privremena vrijednost
        oznaka = self.polje[indeksi[0]][indeksi[1]]
        self.polje[indeksi[0]][indeksi[1]] = self.privremena_oznaka
        
        dijagonala = []
        
        # spusti se do pocetka
        while i > 0 and j > 0:
            i -= 1
            j -= 1
            
        # napuni dijagonalu prema vrhu
        i_max = self._ukupno_redaka()
        j_max = 7
        while i < i_max and j < j_max:
            dijagonala.append(self.polje[i][j])
            i += 1
            j += 1
        
        # makni temp vrijednost
        indeks = dijagonala.index(self.privremena_oznaka)
        self.polje[indeksi[0]][indeksi[1]] = oznaka
        dijagonala[indeks] = oznaka
    
        return (dijagonala, indeks)
    
    def _dohvati_desnu_dijagonalu(self, indeksi):
        # desna dijagonala je \
        
        i = indeksi[0]
        j = indeksi[1]
        
        # privremena vrijednost
        oznaka = self.polje[indeksi[0]][indeksi[1]]
        self.polje[indeksi[0]][indeksi[1]] = self.privremena_oznaka
        
        dijagonala = []
        
        # spusti se do pocetka
        while i > 0 and j < 6:
            i -= 1
            j += 1

        # napuni dijagonalu prema vrhu
        i_max = self._ukupno_redaka()
        while i < i_max and j >= 0:
            dijagonala.append(self.polje[i][j])
            i += 1
            j -= 1
        
        # makni temp vrijednost
        indeks = dijagonala.index(self.privremena_oznaka)
        self.polje[indeksi[0]][indeksi[1]] = oznaka
        dijagonala[indeks] = oznaka
    
        return (dijagonala, indeks)
        
        """ **********************************************   """
    
    @staticmethod        
    def ucitaj():
        fin = open('ploca.txt', 'r')
        fst = fin.read()

        lines = fst.split("\n")
        if lines[-1] == '':
             lines.pop() # zadnji element je neki zbrckani
        polje = []

        for x in reversed(lines):
            polje.append( [int(p) for p in x.split(" ")] )

        p = Ploca()

        for x in polje:
            i = 0
            while i < 7:
                if x[i] != 0:
                    p.odigraj_potez(x[i], i+1)
                i += 1

        return p
