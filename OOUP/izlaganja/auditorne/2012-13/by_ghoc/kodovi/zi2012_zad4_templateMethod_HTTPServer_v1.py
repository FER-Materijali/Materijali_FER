import time
import sys

class HTTPServerBase:
    
    def serve(self):
        print("Pozvana okvirna metoda \'serve()\' definirana u apstraktnoj klasi HTTPServerBase")
        print("-Klasa iz koje je pozvana: " + self.__class__.__name__)
        
        ''' nekakav niz naredbi za koje ne znamo konkretnosti '''
        time.sleep(1)
        print("Obavljam neki posao ", end = '')
        for n in range (5):
            print(".", end = '')
            time.sleep(.5)
        print("\n")

        time.sleep(1)
        print("Iz okvirne metode pozivam metodu \'doGet()\'")
        time.sleep(1)
        self.doGet() #!!!
        
        print("Obavljam neki posao ", end = '')
        for n in range (5):
            print(".", end = '')
            time.sleep(.5)
        print("\n")

        time.sleep(1)
        print("Iz okvirne metode pozivam metodu \'doPost()\'")
        time.sleep(1)
        self.doPost() #!!!
        
        print("Obavljam neki posao ", end = '')
        for n in range (5):
            print(".", end = '')
            time.sleep(.5)
        print("\n")
        print("Kraj metode \'serve()\'\n\n")
        time.sleep(2)
        
    def doGet(self):
        raise NotImplementedError

    def doPost(self):
        raise NotImplementedError


class MyServer(HTTPServerBase):

    def doGet(self):
        print("  - Pozvana je metoda za obradu zahtjeva GET (v1)")
        print("  - Klasa iz koje je pozvana: " + str(self.__class__.__name__))

    def doPost(self):
        print("  - Pozvana je metoda za obradu zahtjeva POST (v1)")
        print("  - Klasa iz koje je pozvana: " + str(self.__class__.__name__))

              
class YourServer(HTTPServerBase):

    def doGet(self):
        print("  - Pozvana je metoda za obradu zahtjeva GET (v2)")
        print("  - Klasa iz koje je pozvana: " + str(self.__class__.__name__))

    def doPost(self):
        print("  - Pozvana je metoda za obradu zahtjeva POST (v2)")
        print("  - Klasa iz koje je pozvana: " + str(self.__class__.__name__))

              
class My2ndServer(HTTPServerBase):

    def doGet(self):
        print("  - Pozvana je metoda za obradu zahtjeva GET (v3)")
        print("  - Klasa iz koje je pozvana: " + str(self.__class__.__name__))

    def doPost(self):
        print("  - Pozvana je metoda za obradu zahtjeva POST (v3)")
        print("  - Klasa iz koje je pozvana: " + str(self.__class__.__name__))


def test():

    S4 = HTTPServerBase()
    try:
        S4.serve()
    except:
        '''Nepotrebna komplikacija samo da izbaci naziv Errora i nastavi dalje'''
        e = sys.exc_info()[0]
        print( " (!!!) Greska %s (!!!) \n\n" % str(e.__name__))

            
    S1 = MyServer()
    S1.serve()

    S2 = My2ndServer()
    S2.serve()

    S3 = YourServer()
    S3.serve()


        

test()
