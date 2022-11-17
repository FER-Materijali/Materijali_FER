import sys, os
from datetime import datetime

for file in os.listdir():
    if (('.txt' in file) and ('IZLAZ' not in file)):
        print(file)
        start = datetime.now()
        ulaz=open(file,'r')
        h=open(file.split('.')[0]+'_IZLAZ.txt','w+')

        #VAS PROGRAM (kako bi indentirali
        #cijeli program za dva mjesta, mozete oznaciti program i
        #Format->Indent region)

        print(datetime.now()-start)
        h.close()

#
nepod='Ne podudara se u\n'
for file in os.listdir():
    if ('IZLAZ' in file):
        print('Provjeravam file: '+file)
        a=open(file,'r').readlines()
        b=open('B/'+file,'r').readlines()
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
