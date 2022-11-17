import re
import sys

ulaz=sys.stdin.readlines()
s=""
for i in ulaz:
    s=s+i
ulaz=s.strip()

def S(rez):
    global ulaz
    rez+="S"
    if (len(ulaz)>0):
        znak=ulaz[0]
    else:
        return rez+"NE"
    if (znak != 'a' and znak != 'b'):
        return rez+"NE"
    s=""
    for i in range(0, len(ulaz)):
        if i != 0:
            s+=ulaz[i]
    ulaz=s
    if znak=='a' :
        rez=A(rez)
        uv=1
        for i in range(0,len(rez)):
            if rez[i] =="N":
                uv=0
        if uv ==1:
            rez=B(rez)
    else:
        rez=B(rez)
        uv=1
        for i in range(0,len(rez)):
            if rez[i] =="N":
                uv=0
        if uv ==1:
            rez=A(rez)
    return rez

def A(rez):
    global ulaz
    rez+="A"
    blabla=0
    if (len(ulaz)>0):
        znak=ulaz[0]
        s=""
        for i in range(0, len(ulaz)):
            if i != 0:
                s+=ulaz[i]
        blabla=1
        ulaz=s
    else: znak=""
    if znak=="b":
        s=""
        if blabla !=1:
            for i in range(0, len(ulaz)):
                if i != 0:
                    s+=ulaz[i]
            ulaz=s
        rez=C(rez)
    elif znak=="a":
        return rez
    else:
        return rez+"NE"
    return rez

def B (rez):
    global ulaz
    rez+="B"
    if len(ulaz)<1:
        return rez
    if len(ulaz)==1:
        if ulaz[0]=="c":
            ulaz=""
            if (rez[len(rez)-1] !="E"):
                return rez+"NE"
            else:
                return rez
        else:
            return rez
    else:
        if (ulaz[0]=="c" and ulaz[1]=="c"):
            s=""
            for i in range(0, len(ulaz)):
                if (i != 0 and i !=1):
                    s+=ulaz[i]
            ulaz=s
            rez=S(rez)
            if (len(ulaz)>1):
                if (ulaz[0]=="b") and ulaz[1]=="c":
                    s=""
                    for i in range(0, len(ulaz)):
                        if (i != 0 and i !=1):
                            s+=ulaz[i]
                    ulaz=s
                else:
                    if (rez[len(rez)-1] !="E"):
                        return rez+"NE"
                    else: return rez
            else:
                if (rez[len(rez)-1] !="E"):
                    return rez+"NE"
                else: return rez
        elif (ulaz[0]=="c" and ulaz[1] != "c"):
            return rez+"NE"
        else:
            return rez
            
    return rez

def C(rez):
    global ulaz
    rez+="C"
    rez=A(rez)
    uv=1
    for i in range(0,len(rez)):
        if rez[i] =="N":
            uv=0
    if uv !=0:        
        rez=A(rez)
                
    return rez

rez=""
rez=S(rez)
rezuk=""
rezneda=""

if (len(ulaz)==0 and (rez[len(rez)-1] !="E")):
    rez+="DA"
elif (rez[len(rez)-1] !="E"):
    rez+="NE"
for i in range(0,len(rez)):
    if (i<len(rez)-2):
        rezuk=rezuk+rez[i]
    else:
        rezneda=rezneda+rez[i]

    
print rezuk
print rezneda
