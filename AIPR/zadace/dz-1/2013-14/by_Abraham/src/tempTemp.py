import math
# OVA VERZIJA IMA TRY EXCEPT ERROR!!!
class Node( object ):
    data = None
    left, right = None, None
    def __init__( self, el ):
        self.data = el

class DSW(object):
    def __init__(self):
        self.root = None
    def getRoot(self):
        return self.root
    
    def algorithm(self):
        if None != self.root:
            self.backbone()  
            self.createPerfectTree()
    
#jednostavne rotacije
    def rightRotation(self, gr, par, ch):
        if None != gr: 
            gr.right = ch
        else:
            self.root = ch 
        par.left = ch.right
        ch.right = par
        return gr
    def leftRotation(self, gr, par, ch):
        if None != gr:
            gr.right = ch
        else:
            self.root = ch     
        par.right = ch.left
        ch.left = par
        
        
    def backbone(self):
        parent = None
        temp = self.root
        leftChild = None
     
        while None != temp:
            leftChild = temp.left
            if None != leftChild:
                parent = self.rightRotation(parent, temp, leftChild)
                temp = leftChild
            else:
                parent = temp
                temp = temp.right
                
    def makeLeftRotations(self, limit):
        gr = None
        temp = self.root
        ch = temp.right
        while (limit>0):
            try:
                if None != ch:
                    self.leftRotation(gr, temp, ch);
                    gr = ch;
                    temp = gr.right;
                    ch = temp.right;
                else:
                    break
            except AttributeError:
                print "error"
                break
            limit-= 1
                
    def createPerfectTree(self):
        temp = self.root
        n = 0
        while (temp!=None):
            n += 1
            temp = temp.right
        h = int(math.log( n+1, 2)) #broj razina u potpunom stablu
        k = int(math.pow(2, h)-1) #broj cvorova u punim razinama
        self.makeLeftRotations(n-k)
        while (k>1):
            k /= 2
            self.makeLeftRotations(k)
        
        
        
        
   
novaLista = []
lista = [] 
stablo = DSW()
print "Ako cvor nema neko dijete ukucaj \"x\"!\nA ako je cvor list ukucaj \"l\" kao list!"
stablo.root = Node(raw_input("Korijen je?"))
temp = raw_input("Lijevo dijete korijena?")
if (temp != 'x'):    stablo.root.left = Node(temp); lista.append(stablo.root.left)
temp = raw_input("Desno dijete korijena?")
if (temp != 'x'):    stablo.root.right = Node(temp); lista.append(stablo.root.right)
while (lista):
    for cvor in lista:
        temp=raw_input("koje je lijevo dijete od: "+ cvor.data)
        if (temp!='x' and temp!='l'): cvor.left = Node (temp); novaLista.append(cvor.left)
        if (temp == 'l'): continue
        temp=raw_input("koje je desno dijete od: "+ cvor.data)
        if (temp!='x'): cvor.right= Node (temp); novaLista.append(cvor.right)
    lista = novaLista
    novaLista = []   
stablo.algorithm()

print "FIN"
