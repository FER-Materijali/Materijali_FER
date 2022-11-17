import sys

arr=[]

i=0
for line in sys.stdin:
    arr.insert(i,line)
    i=i+1

dict = {}

#arr=['p1,p2,p3,p4,p5,p6,p7\n', 'c,d\n', 'p5,p6,p7\n', 'p7\n', 'p1,c->p6\n', 'p1,d->p3\n', 'p2,c->p7\n', 'p2,d->p3\n', 'p3,c->p1\n', 'p3,d->p5\n', 'p4,c->p4\n', 'p4,d->p6\n', 'p5,c->p7\n', 'p5,d->p3\n', 'p6,c->p4\n', 'p6,d->p1\n', 'p7,c->p4\n', 'p7,d->p2\n']

def findKey(key):
    if key in dict:
        t = dict.get(key)
        return t
    return None

def ispitaj(a, b):

    for stupac in multIList:
        if a in stupac and b in stupac:
            return True
    return False

visited = set()

def dfs(state):
        if state in visited:
            return

        visited.add(state)

        for ulazniZnak in ulazniOkidaci.split(','):
            dfs(dict.get(state+','+ulazniZnak))



#for line in sys.stdin:
#    arr.insert(i, line)
#    i = i + 1

ulazniZnakovi = arr[0].strip().split(',')
ulazniOkidaci=arr[1].strip()
states = arr[4:]
prihvatljiva = arr[2].strip().split(',')
pocetno=arr[3].strip()
#x = ulaz.split('|')


for i in states:
    i = i.strip()  # makni \n

    y = i.split('->')
    z = y[0].split(',')
    z1 = y[1].split(',')

    dict[y[0]] = y[1]

dfs(arr[3].strip())

temp=dict.copy()

#for stanje in dict:

#    spl=stanje.split(',')
#    if spl[0] not  in visited:
#        temp.pop(stanje,None)



dict.clear()

dict=temp

multIList= []

prviStupac=[]
drugiStupac=[]

for x in ulazniZnakovi:
    if x not in prihvatljiva:
        prviStupac.append(x)
    else:
        drugiStupac.append(x)

multIList.append(prviStupac)
multIList.append(drugiStupac)

while True:

    izmjena=False  # nemoj zaboravit breakat

    brojacStupaca = 0

    for stupac in multIList:

        brojOduzetih=0
        for i in stupac:
            k=0
            l=len(stupac)-stupac.index(i)-brojOduzetih

            prvi=True
            temp=[]

            for c in range(0,l-1):

                j=stupac[stupac.index(i)+1+k-brojOduzetih]
                k=k+1

                for ulazniZnak in ulazniOkidaci.split(','):
                    a = findKey(i + ','+ulazniZnak)
                    b = findKey(j + ','+ulazniZnak)

                    if a!=b and ispitaj(a,b)==False:
                        izmjena=True
                        if i<j:

                            temp.append(j)
                            if (prvi ==True):
                                multIList.append(temp)
                                prvi=False

                            multIList[brojacStupaca].remove(j)
                            brojOduzetih=brojOduzetih+1
                            break

                        else:
                            temp.append(i)
                            if prvi ==True:
                                multIList.append(temp)
                                prvi=False
                            multIList.remove(i)
                            multIList[brojacStupaca].remove(i)
                            brojOduzetih = brojOduzetih + 1
                            break
        brojacStupaca=brojacStupaca+1

    if izmjena==False:
       break

konLista=[]

multIList.sort()  #woah , ovo radi haha

for i in range(0,len(multIList)):

        if multIList[i]!=[]:
            konLista.append(multIList[i][0])

parsanDict={}

for stupac in multIList:

        if stupac!=[]:
            prvoStanje =stupac[0]
            ostatak = stupac[1:]

            for stanja in ostatak:
                parsanDict[stanja] = prvoStanje

konDict={}

for key in dict:
    t=key.split(',')
    if t[0] not in parsanDict:

            vrijed=dict.get(key)

            if vrijed in parsanDict:
                konDict[key]=parsanDict.get(vrijed)
            else:
                konDict[key]=dict.get(key)

for stanje in konLista.copy():
    if stanje not in visited:
        konLista.remove(stanje)

for key in parsanDict:
    t=key.split(',')
    if t[0]  in prihvatljiva:
        prihvatljiva.remove(t[0])


for stanje in prihvatljiva.copy():
    if stanje not in visited:
        prihvatljiva.remove(stanje)

if pocetno in parsanDict:
    pocetno=parsanDict.get(pocetno)

print(','.join(konLista))
print(ulazniOkidaci)
print(','.join(prihvatljiva))
print(pocetno)


for key in konDict:
        spl =key.split(',')
        if spl[0] in visited:
            v=konDict.get(key)
            print(key+"->"+v)
