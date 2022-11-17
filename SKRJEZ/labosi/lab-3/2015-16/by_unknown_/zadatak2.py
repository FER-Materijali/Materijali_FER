ulazi=[]
koef=list(range(10,100,10))
with open('ulaz.txt','r') as dat:
    for line in dat:
        ulazi.append([float(broj) for broj in line.split(" ")])

s="Hyp"
for q in koef:
    s+="#Q"+str(q)
print(s)

i=1
for niz in ulazi:
    temp=sorted(niz)
    k="{0:03}".format(i)
    for q in koef:
        poz=int(len(temp)*q/100)
        broj=temp[poz]
        k+="#"+str(broj)
    print(k)
    i+=1
        
        