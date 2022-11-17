import sys

arr=[]

z=0
for line in sys.stdin:
    arr.insert(z, line)
    z = z + 1

ulaz = arr[0].strip()

s=[]

s=ulaz


i = 0

def S():
    global i
    print("S",end='')

    if(i<len(s)):
        if(s[i]=='a'):
            i=i+1
            A()
            B()
        elif (s[i]=='b'):
            i=i+1
            B()
            A()
        else:
            print("\nNE")
            exit()
    else:
        print("\nNE")
        exit()


def A():
    global i
    print("A",end='')
    if(i<len(s)):
        if(s[i]=='b'):
            i=i+1
            C()
        elif (s[i]=='a'):
            i=i+1
        else:
            print("\nNE")
            exit()
    else:
        print("\nNE")
        exit()

def B():
    global i
    print("B",end='')

    if(i+1<len(s) and s[i]=='c' and s[i+1] =='c'):
        i=i+2
        S()
    if(i+1<len(s) and s[i]=='b' and s[i+1]=='c'):
        i=i+2

def C():
    print("C",end='')
    A()
    A()

S()
if(i== len(s)):
    print("\nDA")
else:
    print("\nNE")
