import time

class Izbornik:
    def __init__(self):
        self.skupNaredbi = list()

    def dodajNaredbu(self, naredba):
        self.skupNaredbi.append(naredba)

    def ukloniNaredbu(self, index):
        del(self.skupNaredbi[index])

    def printajIzbornik(self):
        print("{:-^22}".format("izbornik"))
        for stavka in self.skupNaredbi:
            print("{:-^22}".format(""))
            print("|"+"{:^20}".format("("+str(self.skupNaredbi.index(stavka)+1)+")")+"|")
            print("|"+'{:^20}'.format(stavka.ime())+"|")
        print("{:-^22}".format(""))


    def odabranaNaredba(self, index):
        self.skupNaredbi[index-1].execute()
        

    def pokreni(self):
        while True:
            
            self.printajIzbornik()
            br = int(input("Odaberi broj izborničke stavke (0 za prekid):\n"))

            if br == 0:
                break
        
            elif br not in range (len(self.skupNaredbi)+1):
                print ("Pogresan unos!\n")
                self.pokreni()

            else:
                self.odabranaNaredba(br)

            time.sleep(2)
                        
class Command:
    def __init__(self, ime, receiver):
        self.imeNaredbe = ime
        self.receiver = receiver

    def ime(self):
        return self.imeNaredbe

    def execute(self):
        raise NotImplementedError
    

class CopyCommand(Command):
    def execute(self):
        print(" (!!) COPY (!!) ")
        self.receiver.copyAction()


class PasteCommand(Command):
    def execute(self):
        print(" (!!) PASTE (!!) ")
        self.receiver.pasteAction()


class CutCommand(Command):
    def execute(self):
        print(" (!!) CUT (!!) ")
        self.receiver.cutAction()

        

'''malo nedefinirani receiver'''
class Receiver:
    def __init__(self):
        print("--Stvoren je zajednički receiver--\n")

    def copyAction(self):
        print("Kopiram sadržaj u memorijski međuspremnik\n")

    def pasteAction(self):
        print("Lijepim sadržaj međuspremnika u dokument\n")

    def cutAction(self):
        print("Izrezujem sadržaj dokumenta i privremeno ga pohranjujem u memoriji\n")

def test():
    izbornik = Izbornik()
    dokument = Receiver()
    izbornik.dodajNaredbu(CopyCommand("COPY", dokument))
    izbornik.dodajNaredbu(PasteCommand("PASTE", dokument))
    izbornik.dodajNaredbu(CutCommand("CUT", dokument))

    izbornik.pokreni()

    
test()
                          
