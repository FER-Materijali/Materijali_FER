m1={}
m2={}
m3={}
dim=[]

def multiply():
    print("Mnozim matrice.")
    for i in range(int(dim[0][0])): #A matrica redovi
        for j in range(int(dim[1][1])): #B matrica stupci
            for k in range(int(dim[0][1])): #A matrica stupci
                if (i,j) in m3:
                    m3[i,j] += m1.get((i,k),0) * m2.get((k,j),0)
                else:
                    m3[i,j] = m1.get((i,k),0) * m2.get((k,j),0)

def readMatrix(dat):
    print("Citam matrice.")
    lines=[]
    for line in dat:
        lines.append(line.rstrip()) 
    mat1=lines[:lines.index('')]
    mat2=lines[lines.index('')+1:]
    dim.append(mat1[0].split(" "))
    dim.append(mat2[0].split(" "))  
    mat1.pop(0)
    mat2.pop(0)
    for item in mat1:
        lok=item.split(" ")
        m1[int(lok[0]),int(lok[1])]=float(lok[2])
    for item in mat2:
        lok=item.split(" ")
        m2[int(lok[0]),int(lok[1])]=float(lok[2])

with open('matrice.txt','r') as dat:
    readMatrix(dat)
if dim[0][1] != dim[1][0]:
    print("Nejednak broj stupaca i redaka!")
else:
    multiply()
    for n in [k for k,v in m3.items() if v==0]:
        del m3[n]
    with open('multiply.txt','w') as dat:
        print("Zapisujem rjesenje.")
        dat.write(dim[0][0]+" "+dim[1][1]+"\n")
        for (k,v) in m3.items():
            s= str(k[0])+" "+str(k[1])+" "+str(round(m3[k],3))+"\n"
            dat.write(s)  