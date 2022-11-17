import os
import re

studenti={}
bodovi={}
rezultat={}
maxlab=0

with open('studenti.txt','r') as dat:
    for line in dat:
        temp=line.rstrip().split(" ")
        studenti[temp[0]]=[temp[1],temp[2]]

files=os.listdir(".")
for fileName in files:
    match = re.match(r'^Lab_([\d]{2})_g([\d]{2})',fileName)
    if match:
        lab,grupa=int(match.group(1)),int(match.group(2))
        if maxlab < lab: maxlab=lab
        with open(fileName,'r') as f:
            # print("Labos: {} Grupa: {}".format(lab,grupa))
            for line in f:
                temp=line.rstrip().split(" ")
                if temp[0] not in bodovi:
                    bodovi[temp[0]]={} #inicijalizacija
                bodovi[temp[0]][lab]=temp[1]
                # print("{} {} {}".format(temp[0],lab,temp[1]))

s="{0:10} {1:18}".format("JMBAG","Prezime, Ime")
for i in range(1,5):
    s+= "L{0:4}".format(str(i))
print(s)

for jmbag,v in studenti.items():
    pi=v[0]+", "+v[1]
    s="{0:10} {1:18}".format(jmbag,pi)
    for i in range(1,maxlab+1):
        try:
            bod=bodovi[jmbag][i]
            s += "{0:4} ".format(bod)
        except:
            s += "{0:4}".format(" ")
    print(s)
    