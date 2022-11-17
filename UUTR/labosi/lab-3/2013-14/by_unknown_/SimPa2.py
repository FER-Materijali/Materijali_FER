import fileinput
import re

#ulaz = fileinput.input()
ulaz=open("ulaz.txt", "r")
ulazni_nizovi = [x.split(',') for x in ulaz.readline().strip().split('|')]
Q = ulaz.readline().strip().split(',')
E = ulaz.readline().strip().split(',')
mstog = ulaz.readline().strip().split(',')
prihvatjivastanja = ulaz.readline().strip().split(',')
q0= ulaz.readline().strip()
pstog=ulaz.readline().strip()
##print(ulazni_nizovi,"\n", Q,"\n", E,"\n", mstog,"\n", prihvatjivastanja,"\n", q0,"\n",pstog,"\n")
tablicaPrijelaza = {}
stog=[]
for linija in ulaz:
    prijelaz = re.match(r'(.*),(.*),(.*)->(.*)',linija)
    bla=prijelaz.group(4).split(',')
    tablicaPrijelaza[(prijelaz.group(1),prijelaz.group(2),prijelaz.group(3))]=(bla[0],bla[1])

#print(tablicaPrijelaza)

trenutno_stanje=[]
##trenutno_stanje.append(q0)
for ulazni_niz in ulazni_nizovi:
    #print("".join(q0+'#'+pstog))
    print "novi niz"
    bzvz=""    
    trenutno_stanje=q0
    stog.append(pstog)
    for znak in ulazni_niz:
##        print(znak)
        if not(len(stog) ==0):
            a=stog.pop()
        else:
            a='$'
        print stog
        if (trenutno_stanje,znak,a) in tablicaPrijelaza.keys():
##            print(1)    
            prosla=tablicaPrijelaza[(trenutno_stanje,znak,a)][0]
            stog.append(tablicaPrijelaza[(trenutno_stanje,znak,a)][1])
            for i in range(0,len(stog)):
                bzvz+=stog[i]
            
            zapis=tablicaPrijelaza[(trenutno_stanje,znak,a)][0]+'#'+bzvz
            if zapis==None:
                zapis='0'
        print('|'+"".join(zapis))
    
        trenutno_stanje=prosla
        
    

