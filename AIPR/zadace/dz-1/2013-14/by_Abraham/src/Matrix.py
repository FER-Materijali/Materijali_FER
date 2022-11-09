'''
Created on 5. 11. 2013.

@author: Abraham
'''
import sys
class Matrix:
    konstantaUsporedbe = 0.0001
    
    # Konstruktor
    def __init__(self, brojRed=0, brojStup=0):
        self.brojRedaka, self.brojStupaca = brojRed, brojStup
        self. matrica = []
        if (brojRed>0 and brojStup>0):
            for i in range(brojRed):
                self.matrica.append([None] * brojStup)
    def setEl(self, i, j, el):
        #print(i,j)
        self.matrica[i][j] = float(el)
    def getEl(self, i, j):
        return self.matrica[i][j]   
    
    def subEl(self, i, j, el):
        self.matrica[i][j] -= el
    def addEl(self, i, j, el):
        self.matrica[i][j] += el
    def divEl(self, i, j, el):
        self.matrica[i][j] /= el
        
    def ucitajNovuMatricu(self, fajl):
        brojStup,brojRed = 0, 1
        f = open(fajl, 'r')
        l = f.readline()        
        for x in l.split():
            brojStup += 1
        while (f.readline()):
            brojRed +=1        
        novaMatrica = Matrix(brojRed, brojStup)
        i, j = 0, 0
        #f = open(file, 'r')
        with open(fajl) as f:
            for ln in f:
                j=0
                for el in ln.split():
                    novaMatrica.setEl(i, j, el)
                    j+=1
                i += 1      
        return novaMatrica
                    
    def isprintaj(self):
        print(' matrica:')
        for i in range(self.brojRedaka):
            for j in range(self.brojStupaca):
                sys.stdout.write("%6.2f" % self.getEl(i, j))
                #print( "%5.2f" % self.getEl(i, j))
            print('')
            
    def isprintajUDatoteku(self, file):
        f = open(file, 'w')
        for i in range(self.brojRedaka):
            for j in range(self.brojStupaca):
                f.write((" %.2f" % self.getEl(i, j)).rstrip('0').rstrip('.'))
            f.write('\n')
            
    def zbrojiMatricu(self, matrica):
        for i in range(self.brojRedaka):
            for j in range(self.brojStupaca):
                self.setEl(i, j, self.getEl(i, j) + matrica.getEl(i,j))
    def oduzmiMatricu(self,matrica):
        for i in range(self.brojRedaka):
            for j in range(self.brojStupaca):
                self.setEl(i, j, self.getEl(i, j) - matrica.getEl(i,j))
    def pomnoziSkalarom(self, skalar):
        for i in range(self.brojRedaka):
            for j in range(self.brojStupaca):
                self.setEl(i, j, self.getEl(i, j) * skalar)
    #Vraca kopiju same sebe
    def newCopy(self):
        newMatrix = Matrix(self.brojRedaka, self.brojStupaca)
        for i in range(self.brojRedaka):
            for j in range(self.brojStupaca):
                newMatrix.setEl(i, j, self.getEl(i, j))
        return newMatrix
    # Matrica napravi deep-copy druge matrice
    def copyOf(self, matrix):
        for i in range(self.brojRedaka):
            for j in range(self.brojStupaca):
                self.setEl(i, j, matrix.getEl(i, j))
                
    def pomnoziMatricom(self, matrix):
        if (self.brojStupaca != matrix.brojRedaka):
            print ("Matrice nisu komp. za mnozenje!")
            return
        new = Matrix(self.brojRedaka, matrix.brojStupaca)
        for i in range(self.brojRedaka):
            for j in range(matrix.brojStupaca):
                new.setEl(i, j, 0)
                for k in range(self.brojStupaca):
                    new.setEl(i, j, new.getEl(i, j) + self.getEl(i, k)*matrix.getEl(k,j))
        return new
    def transponiranuVrati(self):
        new = Matrix(self.brojStupaca, self.brojRedaka)
        for i in range(self.brojRedaka):
            for j in range(self.brojStupaca):
                new.setEl(j, i, self.getEl(i, j))
        return new
    def supstitucijaUnaprijed(self, b):
        if (b.brojStupaca > 1):
            print ("Ulazni parametar supstitucije unaprijed mora biti 'okomiti' vektor (dimenzija nx1)!")
        if (b.brojRedaka != self.brojRedaka):
            print("Ulazni vektor supstitucije unaprijed nije valjane dimenzije!")
        vektorY = b.newCopy()
        for i in range (self.brojRedaka - 1):
            for j in range(i+1, self.brojRedaka):
                vektorY.subEl(j, 0, self.getEl(j, i) * vektorY.getEl(i,0))
        return vektorY
    
    def supstitucijaUnatrag(self, y):
        if (y.brojStupaca > 1):
            raise Exception("Ulazni parametar supstitucije unatrag mora biti ''okomiti'' vektor (dimenzija nx1)!");
        if (y.brojRedaka != self.brojRedaka):
            raise Exception("Ulazni vektor supstitucije unatrag nije valjane dimenzije!");

        vektorX = y.newCopy();
        for i in range ( self.brojRedaka-1, -1, -1):
            if(abs(self.getEl(i, i)) < self.konstantaUsporedbe):
                raise Exception("Postupak zaustavljen u supstituciji unatrag jer je pivot manji od zadane granice! - Izgleda da je matrica singularna!!!")
            vektorX.divEl(i,0, self.getEl(i, i))
            for j in range(i):
                vektorX.subEl(j, 0, self.getEl(j, i) * vektorX.getEl(i, 0))
        return vektorX
    def dekompozicijaLU(self):
        if (self.brojRedaka != self.brojStupaca):
            raise Exception("LU dekompozicija izvediva je samo na kvadratnoj matrici!");
        radnaMatrica = self.newCopy()
        for i in range( self.brojRedaka - 1):
            for j in range(i+1, self.brojStupaca):
                if ( abs(radnaMatrica.getEl(i, i)) < self.konstantaUsporedbe):
                    raise Exception("LU dekompozicija je zaustavljena jer je detektiran stozerni element manji od zadane granice!");
                radnaMatrica.divEl(j, i, radnaMatrica.getEl(i, i))
                for k in range(i+1, self.brojRedaka):
                    radnaMatrica.subEl(j, k, radnaMatrica.getEl(j, i) * radnaMatrica.getEl(i, k))
        return radnaMatrica
    
    def zamijeniRetke(self,i,j):
        nova = self.newCopy()
        for k in range(self.brojStupaca):
            nova.setEl(i, k, self.getEl(j, k))
            nova.setEl(j, k, self.getEl(i, k))
        return nova
    
    def zamijeniStupce(self, i, j):
        nova = self.newCopy()
        for k in range(self.brojRedaka):
            nova.setEl(k, i, self.getEl(k, j))
            nova.setEl(k, j, self.getEl(k, i))
        return nova
    
    def vratiMatricuL(self ):
        matricaL = Matrix(self.brojRedaka, self.brojStupaca)
        for i in range(self.brojRedaka):
            for j in range(self.brojStupaca):
                if (i == j ):
                    matricaL.setEl(i, j, 1)
                elif (i > j):
                    matricaL.setEl(i, j, self.getEl(i, j))
                else:
                    matricaL.setEl(i, j, 0)
        return matricaL
    
    def vratiMatricuU(self ):
        matricaU = Matrix(self.brojRedaka, self.brojStupaca)
        for i in range(self.brojRedaka):
            for j in range(self.brojStupaca):
                if (i <= j):
                    matricaU.setEl(i, j, self.getEl(i, j))
                else:
                    matricaU.setEl(i, j, 0)
        return matricaU
    def vratiPermutiraniVektor(self, vektorPermutacije):
        radniVektor = self.newCopy()
        for i in range(self.brojRedaka):
            el = int(vektorPermutacije.getEl(0,i))
            e= self.getEl(el, 0)
            radniVektor.setEl(i, 0, e)
        return radniVektor
    
    
    
    
    
    def dekompozicijaLUP(self):
        permutacijskiVektor = Matrix(1, self.brojRedaka);
        radnaMatrica = self.newCopy();
        for i in range(self.brojRedaka):
            permutacijskiVektor.setEl(0, i, i)
        for i in range(self.brojRedaka - 1):
            pivot = i
            for j in range(i+1, self.brojRedaka):
                if ( abs(radnaMatrica.getEl(j,i)) > abs(radnaMatrica.getEl(pivot,i))):
                    pivot = j
            if( abs(radnaMatrica.getEl(pivot, i)) < self.konstantaUsporedbe):
                raise Exception("LUP dekompozicija je zaustavljena jer je detektiran stozerni element manji od zadane granice!");
            
            radnaMatrica = radnaMatrica.zamijeniRetke(i, pivot);
            permutacijskiVektor = permutacijskiVektor.zamijeniStupce(i, pivot);
            
            for j in range(i+1, self.brojRedaka):
                radnaMatrica.divEl(j,i, radnaMatrica.getEl(i,i))
                for k in range (i+1, self.brojRedaka):
                    radnaMatrica.subEl(j,k,  radnaMatrica.getEl(j,i) * radnaMatrica.getEl(i,k))

        return radnaMatrica, permutacijskiVektor;

            
    
    
m = Matrix(2,2)
A = m.ucitajNovuMatricu('A.txt')
B = m.ucitajNovuMatricu('B.txt')
#C = A.pomnoziMatricom(B)

#AA = A
#A.zbrojiMatricu(AA)
print ('LUP')
Adek, permvekt = A.dekompozicijaLUP()
print ('A dekomponirani:')
Adek.isprintaj()
print ('Perm. vektor:')
permvekt.isprintaj()
L = Adek.vratiMatricuL()
U = Adek.vratiMatricuU()
print ('P*B:')
B.vratiPermutiraniVektor(permvekt).isprintaj()

Y = L.supstitucijaUnaprijed(B.vratiPermutiraniVektor(permvekt))
print ('Y:')
Y.isprintaj()
X = U.supstitucijaUnatrag(Y)
print ('X:')
X.isprintaj()
#print ('C')
#C.isprintaj()
