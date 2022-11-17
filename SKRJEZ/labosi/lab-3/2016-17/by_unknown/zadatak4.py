import sys
import re

if len(sys.argv) !=2: print('Krivi broj argumenata.')
dat = sys.argv[1]
try:
    file = open(dat, 'r', encoding='utf8')
except IOError: print('Nije uspjesno otvoren file.')


try:
    out = open('knjige.bib', 'w', encoding='utf8')
except IOError: print('Nije uspjesno otvoren file za pisanje.')

while(file):
    S = file.readline()
    if not S: break
    if '<LI>' in S:
        podaci = re.sub('<[^<]+?>', '', S)
        podaci = podaci.split(',')
        author = podaci[0].strip()
        title = podaci[1]
        publisher = podaci[2]
        podaci2 = podaci[3].strip();
        podaci2 = podaci2.split(' ')
        year = podaci2[0]
        oznaka = podaci2[1][1:len(podaci2[1])-1]

        print('@book{'+oznaka+',')
        out.write('@book{'+oznaka+',')
        print('\t author = "' + author + '",' )
        out.write('\t author = "' + author + '",')
        print('\t title = "' + title + '",')
        out.write('\t title = "' + title + '",')
        print('\t publisher = "' + publisher + '",')
        out.write('\t publisher = "' + publisher + '",')
        print('\t year = "' + year+ '",' + '\n')
        out.write('\t year = "' + year+ '",' + '\n')
file.close()
out.close()
