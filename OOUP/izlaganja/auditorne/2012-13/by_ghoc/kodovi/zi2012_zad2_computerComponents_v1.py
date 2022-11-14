import time
brInt = 0

class Component:
    def cijena(self):
        raise NotImplementedError

    def clone(self):
        raise NotImplementedError


    def __repr__(self):
        
        global brInt
        str1 = "Skup kompomenenti -- uk. cijena: " + str(self.cijena()) +  "kn\n"
        str1 += brInt * '  ' + "{\n"
        brInt += 1
        for p in self.parts:
            str1 +=  brInt * '  ' + repr(p) + "\n"
        brInt -= 1
        str1 += brInt * '  ' + '}\n'
        return str1
    

class Motherboard(Component):
    def __init__(self, socket, price):
        self.price = price
        self.socket = socket # string npr. '478'

    def cijena(self):
        return self.price

    def clone(self):
        return Motherboard(self.socket, self.price)

    def __repr__(self):
        return "Maticna ploca: socket" + self.socket + ", -- " + str(self.price) + "kn"

    
class ComputerCase(Component):
    def __init__(self, size, price):
        self.size = size # string mini/midi/full tower
        self.price = price

    def cijena(self):
        return self.price

    def clone(self):
        return ComputerCase(self.size, self.price)

    def __repr__(self):
        return "Kuciste: " + self.size + ", -- " + str(self.price) + "kn"


class CPU(Component):
    def __init__(self, clkRate, cores, price):
        self.clockRate = clkRate # float frekvencija(brzine)
        self.cores = cores # int broj jezgri
        self.price = price

    def cijena(self):
        return self.price

    def clone(self):
        return CPU(self.clockRate, self.cores, self.price)

    def __repr__(self):
        return "Procesor: " + str(self.clockRate) + "GHz, " +\
    "jezgri: " + str(self.cores) + ", -- " + str(self.price) + "kn"


class RAM(Component):
    def __init__(self, memory, price):
        self.memory = memory # gigabajti memorije
        self.price = price

    def cijena(self):
        return self.price

    def clone(self):
        return RAM(self.memory, self.price)

    def __repr__(self):
        return "Plocica RAM-a: " + str(self.memory) + "GB, -- " + str(self.price) + "kn"

    
class Speaker(Component):
    def __init__(self, power, price):
        self.power = power # int Watti
        self.price = price

    def cijena(self):
        return self.price

    def clone(self):
        return Speaker(self.power, self.price)

    def __repr__(self):
        return "Zvucnik: " + str(self.power) + "W, --  " + str(self.price) + "kn"


class Woofer(Component):
    def __init__(self, power, price):
        self.power = power # int watti
        self.price = price

    def cijena(self):
        return self.price

    def clone(self):
        return Woofer(self.power, self.price)

    def __repr__(self):
        return "Woofer: " + str(self.power) + "W, -- " + str(self.price) + "kn"


class Monitor(Component):
    def __init__(self, diagonal, price):
        self.diagonal = diagonal # int inči
        self.price = price

    def cijena(self):
        return self.price

    def clone(self):
        return Monitor(self.diagonal, self.price)

    def __repr__(self):
        return "Monitor: " + str(self.diagonal) + "\'\', -- " + str(self.price) + "kn"

    
''' složeni artikl - kompozit'''    
class Bundle(Component):
    def __init__(self):
        self.parts = list() # self.parts = []

    def add(self, component):
        self.parts.append(component)

    def cijena(self):
        rw = 0
        for part in self.parts:
            rw += part.cijena()
        return rw

    def clone(self):
        pb = Bundle()
        for part in self.parts:
            pb.add(part.clone())  # ili pb.add(part)
        return pb
    


''' ispitni dio programa '''
class Ponuda:
    def __init__(self):
        print("stvaranje instance po jednog od svih željenih jednostavnih artikala")
        
        maticna1 = Motherboard("478", 950)
        maticna2 = Motherboard("939", 800)
        maticna3 = Motherboard("370", 1100)
        kuciste1 = ComputerCase("mini-tower", 150)
        kuciste2 = ComputerCase("mid-tower", 280)
        kuciste3 = ComputerCase("mid-tower", 480)
        kuciste4 = ComputerCase("full-tower", 450)
        proc1 = CPU(2.4, 2, 1050)
        proc2 = CPU(2.8, 2, 1600)
        proc3 = CPU(3.2, 1, 1300)
        proc4 = CPU(2.7, 4, 2100)
        ram1 = RAM(1, 190)
        ram2 = RAM(2, 305)
        ram3 = RAM(4, 420)
        zvulja1 = Speaker(25, 180)
        zvulja2 = Speaker(35, 250)
        woofer1 = Woofer(50, 290)
        monitor1 = Monitor(17, 900)
        monitor2 = Monitor(19, 1200)
        monitor3 = Monitor(21, 1500)
        monitor4 = Monitor(22, 1900)
                     
        self.artikliUPonudi = [maticna1, maticna2, maticna3,
                               kuciste1, kuciste2, kuciste3, kuciste4,
                               proc1, proc2, proc3, proc4,
                               ram1, ram2, ram3,
                               zvulja1, zvulja2, woofer1,
                               monitor1,monitor2, monitor3, monitor4]

        konfa1 = Bundle()
        konfa1.add(maticna2)
        konfa1.add(kuciste2)
        konfa1.add(proc2)
        konfa1.add(ram2)
        konfa1.add(ram2)

        ozvucenje1 = Bundle()
        ozvucenje1.add(zvulja1)
        ozvucenje1.add(zvulja1)

        desktopKonfig1 = Bundle()
        desktopKonfig1.add(konfa1)
        desktopKonfig1.add(ozvucenje1)
        desktopKonfig1.add(monitor2)

        konfa2 = Bundle()
        konfa2.add(maticna3)
        konfa2.add(kuciste3)
        konfa2.add(proc4)
        konfa2.add(ram3)

        ozvucenje2 = Bundle()
        ozvucenje2.add(zvulja1)
        ozvucenje2.add(zvulja1)
        ozvucenje2.add(zvulja2)
        ozvucenje2.add(zvulja2)
        ozvucenje2.add(woofer1)

        desktopKonfig2 = Bundle()
        desktopKonfig2.add(konfa2)
        desktopKonfig2.add(ozvucenje2)
        desktopKonfig2.add(monitor4)

        self.gotoveKonfe = [konfa1, konfa2]
        self.ozvucenja = [ozvucenje1, ozvucenje2]
        self.desktopKonfe = [desktopKonfig1, desktopKonfig2]

    def printajPonudu(self):
        self.printajOsnovneArtikle()
        print("\n")
        self.printajOzvucenja()
        print("\n")
        self.printajKonfe()
        print("\n")
        self.printajDesktopKonfe()
        
    def printajOsnovneArtikle(self):
        print("Pojedinacni artikli: ")
        for art in self.artikliUPonudi:
            print(repr(art))

    def printajOzvucenja(self):
        print("Ozvucenja: ")
        for ozv in self.ozvucenja:
            print(repr(ozv))

    def printajKonfe(self):
        print("Gotova racunala: ")
        for konfa in self.gotoveKonfe:
            print(repr(konfa))

    def printajDesktopKonfe(self):
        print("Desktop konfiguracije")
        for konfa in self.desktopKonfe:
            print(repr(konfa))


class Kupovina:
    def __init__(self, ponuda):
        self.ponuda = ponuda
        '''##################'''
        '''Radi jednostavnosti, sve artikle koje je
korisnik izabrao tijekom jedne kupovine također treba predstaviti
složenim artiklom. '''
        self.kosarica = Bundle()


    def printKosarice(self):
        print("*************STANJE KOŠARICE******************\n")

        print("Komponente koje kupujete: ")
        print(self.kosarica)
        print("**********************************************\n")

    def dodajUKosaricu(self, komp):
        print("Dodajem u kosaricu")
        time.sleep(1)
        print(repr(komp))
        for a in range(5): 
            time.sleep(.5)
            print(".", end = "")
        print(".\n")
        time.sleep(1.5)
        
        ''' KLONIRANJE '''
        '''jednostavno stvaranje složenog artikla iz postojećeg'''
        self.kosarica.add(komp.clone())
        time.sleep(2)


def test():
    ponuda = Ponuda()
    kupovina = Kupovina(ponuda)
    kupovina.printKosarice()
    #kupovina.ponuda.printajPonudu()

    kupovina.dodajUKosaricu(ponuda.artikliUPonudi[2])
    kupovina.dodajUKosaricu(ponuda.ozvucenja[1])
    kupovina.dodajUKosaricu(ponuda.desktopKonfe[1])
    kupovina.printKosarice()
    
test()
        
