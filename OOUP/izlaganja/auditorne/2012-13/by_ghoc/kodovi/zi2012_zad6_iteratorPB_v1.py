class Iterator: #Sucelje
    def nextItem(self):
        raise NotImplementedError

    def hasNext(self):
        raise NotImplementedError


class IteratorPB(Iterator):   #Iterator parnih brojeva
    def __init__(self, prvi, brUzastopnih):
        self.trenutni = prvi
        self.granica = prvi + 2*brUzastopnih 

    def nextItem(self):
        if self.hasNext():
            rv = self.trenutni
            self.trenutni += 2
            return rv

        else:
            raise ValueError


    def hasNext(self):
        return self.trenutni < self.granica



class SkupniObjekt:
    def iterator(self):
        raise NotImplementedError


class ParniBrojevi(SkupniObjekt):
    def __init__(self, prvi, brUzastopnih):
        self.prviParni = prvi
        self.brojUzastopnihParnih = brUzastopnih

    
    def iterator(self): #metoda tvornice
        return IteratorPB(self.prviParni, self.brojUzastopnihParnih)


def test():
    pb = ParniBrojevi(2, 100)
    it = pb.iterator()
    while(it.hasNext()):
        print(it.nextItem())

test()
