import sys, os
from datetime import datetime

for file in os.listdir('.'):
    if (('.ul' in file) and ('IZLAZ' not in file)):
        print(file)
        start = datetime.now()
        ulaz=open(file,'r')
        h=open(file.split('.')[0]+'_IZLAZ.iz','w+')

        #ulaz je ulazni file. Umjesto npr. sys.stdin stavite ulaz   - prije ovog komentara nista ne mijenjate
        #h je izlazni file. Vas izlazni fileovi imaju _IZLAZ u naslovu.
        #Umjesto npr. sys.stdout.write stavite h.write
        #VAS PROGRAM, PAZITE NA INDENTACIJU:



        linije = ulaz.readlines()        #-primjer Ovaj dio obrisite
        h.write(''.join(linije))     #-primjer Ovaj dio obrisite

                    
                    
            
        #ZAVRSETAK VASEG PROGRAMA - nakon ovog komentara nista ne mijenjate

        print(datetime.now()-start)
        h.close()

#

nepod='Ne podudara se u\n'
for file in os.listdir('.'):
    if ('_IZLAZ.iz' in file):
        print('Provjeravam file: '+file)
        a=open(file,'r').readlines()
        b=open(file.replace("_IZLAZ",""),'r').readlines()
        br=0
        for lin in range(len(a)):
            try:
                if(a[lin]==b[lin]):
                    br+=1
                else:
                    br+=1
                    nepod+='File: '+file+'\n'+'Redak: '+str(br)+'. redak\n'
            except IndexError:
                nepod+='File: '+file+'\nBroj linija u fileovima se ne podudara!\nPrvi ima vise od drugog.\n'
                break
if (nepod == 'Ne podudara se u\n'):
    print('Podudara se u svim linijama svih fileova!')
else:
    print('Nepodudara se u svim linijama svih fileova!\n'+nepod)

