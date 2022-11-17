import re
import sys

ulaz=sys.stdin.readlines()
s=""
for i in ulaz:
    s=s+i
ulaz=s.strip()

def S(ulaz,rez):
    rez+="S"
    if (len(ulaz)>0):
        znak=ulaz[0]
    else:
        znak=""
    if ((znak != "a") and (znak != "b")):
        return rez+"NE"
    #uzmi prvi znak s lijeva iz niza, ako nije ni a ni b vrati rez
    #ako je duzina veca od 1 uzmi sve osim prvog za slanje
    #ako je tocno jedan posalji prazan niz dalje,ako je 0 onda se vrati
    if (len(ulaz)>1):
        ulaz=ulaz[1:]
    elif (len(ulaz)==1):
        ulaz=""
    else:
        return rez+"NE"
    #ako je znak a odi u produkciju A, pa u B
    if (znak=='a') :
        rez=A(ulaz[1:],rez)
        if (len(ulaz)>2):
            ulaz=ulaz[2:]
        else:
            ulaz=""
        print "salje ovo", ulaz
        rez=B(ulaz,rez)
    #ako nije a, a ako je b onda onda idi u produkciju B, pa onda u A
    elif (znak=='b') :
        print ulaz,"idemo dalje"
        rez=B(ulaz[1:],rez)
        if (len(ulaz)>1):
            ulaz=ulaz[1:]
        else:
            ulaz=""
        rez=A(ulaz,rez)
    if len(ulaz)>0:
        return rez+"NE"
    else:
        rez=rez+"DA"
    return rez

def A(ulaz,rez):
    rez+="A"
    if (len(ulaz)>0):
        znak=ulaz[0]
    else:
        znak=""
    print ulaz
    print rez,"ovo je reza"
    if ((znak != "a") and (znak != "b")):
        print "tu sjebe"
        return rez+"NE"
    if (len(ulaz)>1):
        ulaz=ulaz[1:]
    elif (len(ulaz)==1):
        ulaz=""
    else:
        return rez+"NE"
    
    return rez

def B (ulaz,rez):
    rez+="B"
    return rez

def C(ulaz):

    return

ulaz=sys.stdin.readlines()
s=""
for i in ulaz:
    s=s+i
ulaz=s.strip()
rez=""
rez=S(ulaz,rez)
rezuk=""
rezneda=""
for i in range(0,len(rez)):
    if (i<len(rez)-2):
        rezuk=rezuk+rez[i]
    else:
        rezneda=rezneda+rez[i]

    
print rezuk
print rezneda
