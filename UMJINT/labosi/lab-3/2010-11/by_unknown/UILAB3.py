# -*- coding: utf-8 -*-

ulaz = open('./ulaz.txt','r')


i=0
x=[[]]
t=[]
temp=[]
l=0

for line in ulaz.readlines():
    stringLine=line.split()
    if l==1:
        temp=[]
        for j in range(len(stringLine)-1):
            temp.append(float(stringLine[j]))
        x[0]=temp
        t.append(int(float(stringLine[j+1])))
        l=0
    elif i==0:
        brUlaza=int(stringLine[0])
        i=1
        l=1
    else:
        temp=[]
        for j in range(len(stringLine)-1):
            temp.append(float(stringLine[j]))
        x.append(temp)
        t.append(int(float(stringLine[j+1])))

w=[]
for i in range(int(brUlaza)):
    w.append(int(0))

#stopa=float(raw_input("Koju stopu ucenja zelite?\n"))
#ITER=int(raw_input("broj iteracija?\n"))

stopa=int(2)
ITER=1000

stop=0
j=0
bezGr=0
iteracija=0
net=0

while stop<1:
    iteracija=iteracija+1
    #print iteracija
    
    for k in range(brUlaza):
        net=net+w[k]*x[j][k]

    if net<0:
        o=-1
    else:
        o=1

    if o==t[j]:
        bezGr=bezGr+1
    else:
        bezGr=0
    #print o,t[j]

    for i in range(brUlaza):
        w[i]=int(w[i]+stopa*(t[j]-o)*x[j][i])

    if iteracija==ITER or bezGr==len(t):
        stop=1

    net=0
    j=j+1
    if j==len(t):
        j=0

print "ucenje je zavrseno nakon",iteracija,"iteracija!\n\n"
print("tezinski faktori redom iznose:\n")
for i in range(len(w)):
    print "w(",i,") =",w[i]/100.


while 1:
    noviUl=raw_input("\nunesi neki novi ulaz! ")
    noviUl=noviUl.split()
    for i in range(len(noviUl)):
        noviUl[i]=int(noviUl[i])

    net=0
    for k in range(brUlaza):
        net=net+w[k]*noviUl[k]
    if net<0:
        o=-1
    else:
        o=1
        
    print "izlaz prethodno naucenog perceptrona jest:",o

    
    
        



            
 
