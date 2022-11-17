#izraz=['V','x','E','y','(','F','(','x',')','<>','~','~','(','G','(','x',')','&','F','(','y',')',')',')']

#izraz=['V','x','E','y','(','F','(','x',')','->','~','G','(','x',',','y',')',')','&','E','z','(','G','(','z',')',')']

#izraz=['V','x','E','y','(','F','(','x',')','<>','~','~','(','G','(','x',')','||','F','(','y',')',')',')']

izraz=['(','V','x','E','y','(','F','(','x',')','->','~','G','(','x',',','y',')',')','&','E','y','(','G','(','y',')',')','||','V','x','E','y','(','x','y',')',')','&','E','x','(','x',')']

#izraz=['V','x','E','y','(','F','(','x',')','->','~','G','(','x',',','y',')',')','&','E','y','(','G','(','y',')',')']


def makniImplikaciju(formula):
    for i in range(len(formula)):
        if formula[i]=='->':            
            imp=i
    #print "IMPLIKACIJA NA",imp
    nbrZag=0
    for i in range(imp,len(formula)):
        if formula[i]==')' and nbrZag==0:
            end=i
            break
        if formula[i]=='(':
            nbrZag+=1
        if formula[i]==')':
            nbrZag-=1
    nbrZag=0; start=0
    for i in range(imp,0,-1):
        if formula[i]=='(' and nbrZag==0:
            start=i
            break
        if formula[i]==')':
            nbrZag+=1
        if formula[i]=='(':
            nbrZag-=1

    formula[imp]='||'
    formula.insert((start+1),'~')

    return formula


def makniEkvivalenciju(formula):

    for i in range(len(formula)):
            if formula[i]=='<>':
                ekv=i
    nbrZag=0
    for i in range(ekv,len(formula)):
        if formula[i]==')' and nbrZag==0:
            end=i
            break
        if formula[i]=='(':
            nbrZag+=1
        if formula[i]==')':
            nbrZag-=1
    nbrZag=0; start=0
    for i in range(ekv,0,-1):
        if formula[i]=='(' and nbrZag==0:
            start=i
            break
        if formula[i]==')':
            nbrZag+=1
        if formula[i]=='(':
            nbrZag-=1
    zamjena=['(','~']
    zamjena.extend(formula[(start+1):(ekv)])
    zamjena.append('||')
    zamjena.extend(formula[(ekv+1):(end)])

    zamjena.extend([')','&','(','~'])
    zamjena.extend(formula[(ekv+1):(end)])

    zamjena.append('||')


    zamjena.extend(formula[(start+1):(ekv)])
    zamjena.append(')')
           
    del formula[(start+1):end]
    temp=formula[start+1:len(formula)]
    del formula[(start+1):len(formula)]
    map(formula.append, zamjena)
    map(formula.append, temp)
 
    return formula


def dosegNegacije(formula):
    i=0;j=0
    for i in range(len(formula)):
        if (formula[i]=='~' and (formula[i+1]=='V' or formula[i+1]=='E')):

            negacija=i
            for j in range(i+1, len(formula),2):
                if formula[j]<>'E' and formula[j]<>'V':
                    formula.insert(j,'~')

                    del formula[negacija]
                    if formula[negacija]=='V':
                        formula[negacija]='E'
                    else:
                        formula[negacija]='V'
                    break

        if (formula[i]=='~' and formula[i+1]=='('):
            zag=0
            ok=0
            for j in range(i+2,len(formula)):
                if zag==0 and (formula[j]=='&' or formula[j]=='||'):
                    ok=1
                    break
            if ok==1:
                if formula[j]=='&':
                    formula[j]='||'
                else:
                    formula[j]='&'
                formula.insert(j+1,'~')
                formula.insert(i+2,'~')
                del formula[i]
    return formula



def dvostrukaNegacija(formula):
    for i in range(len(formula)-3):
        if ((formula[i]=='~' and formula[i+1]=='~')):
            del formula[i:i+1]
            del formula[i]
        if (formula[i]=='~' and formula[i+1]=='(' and formula[i+2]=='~'):
            del formula[i:i+2]
            zag=0
            for j in range(i,len(formula)):
                if zag==0 and formula[j]==')':
                    del formula[j]
                    break
                if formula[j]=='(' : zag+=1
                if formula[j]==')' : zag-=1
    return formula

def preimenovanjeVarijabli(formula):
    vezani=[]
    nevezani=['x','y','z','u','v','p','q','s','r','t']
    for i in range(len(formula)):
        if formula[i]=='V' or formula[i]=='E':
            if formula[i+1] in vezani:
                zag=0
                mijenjani=formula[i+1]
                formula[i+1]=nevezani[0]
                for j in range(i+3,len(formula)):
                    if formula[j]==')' and zag==0:
                        break
                    if formula[j]==mijenjani:
                        formula[j]=nevezani[0]
                    if formula[j]=='(':
                        zag+=1
                    if formula[j]==')':
                        zag+=1
                vezani.append(nevezani[0])
                del nevezani[0]
                
                
            else:
                vezani.append(formula[i+1])
                del nevezani[nevezani.index(formula[i+1])]
    return formula


def skolemizacija(formula):
    atom=['x','y','z','u','v','p','q','s','r','t']
    funkcija=['f','g','h','i','j','k','l']
    konstanta=['a','b','c','d','e']
    univerzalne=[[]]
    brisi=[]
    Nun=0 #broj univerzalnih

    for i in range(len(formula)):
        if formula[i]=='V':
            univerzalne[Nun].append(formula[i+1])
            univerzalne[Nun].append(0)
            Nun+=1            
        if formula[i]=='E':
            if Nun>0:
                brisi.append(i)
            if Nun==0:
                for j in range(i+2,len(formula)):
                    if formula[j]==formula[i+1]:
                        formula[j]=konstanta[0]
                brisi.append(i)
                del konstanta[0]
            elif len(univerzalne)>0:
                zamjena=funkcija[0]+'('
                for j in range(Nun):
                    #print len(univerzalne)
                    #print univerzalne
                    if j==0: zamjena+=univerzalne[j][0]
                    else:
                        zamjena+=','+univerzalne[j][0]
                zamjena+=')'
                for j in range(i+2,len(formula)):
                    if formula[j]==formula[i+1]:
                        formula[j]=zamjena
                
                del funkcija[0]
        if formula[i]=='(':
            for j in range(Nun):
                univerzalne[j][1]+=1
        if formula[i]==')':            
            for j in range(Nun):
                univerzalne[j][1]-=1
                if univerzalne[j][1]==0:
                    del univerzalne[j]
                    Nun-=1
        if len(univerzalne)==0:
            #print univerzalne
            Nun=0
            univerzalne=[[]]

        
            
    #print brisi
    for i in range(len(brisi)-1,-1,-1):
        del(formula[brisi[i]:brisi[i]+2])
        
    return formula

def prenex(formula):
    brisi=[]
    trazi=0
    poc=0
    izbaci=[]
    for i in range(len(formula)):
        if formula[i]=='(' and poc==0:
            poc=i
            trazi=1
        if formula[i]=='V' and trazi==1:
            izbaci.append(i)
    temp=[]
    for i in range(len(izbaci)):

        temp.append(formula[izbaci[i]])
        temp.append(formula[izbaci[i]+1])

    for i in range(len(izbaci)-1,-1,-1):
        #print formula[izbaci[i]:izbaci[i]+2]
        del formula[izbaci[i]:izbaci[i]+2]
    for i in range(len(izbaci)):
        formula.insert(0,temp[i*2+1])
        formula.insert(0,temp[i*2])
        
    return formula


def eliminirajPrefix(formula):
    while formula[0]=='V':
        del formula[0:2]
    return formula

def KonjunkcijaDisjunkcija(formula):
    for i in range(len(formula)):


    #(( G /\ H ) V F )
                
        if formula[i]=='||' and formula[i-1]==')':
            Or=i
            zag=0;ok=0;
            for j in range(i-2,-1,-1):
                if formula[j]=='(' and zag==0:
                    start=j
                    break
                if formula[j]=='&' and zag==0:
                    And=j
                    ok=1
                if formula[j]=='(': zag-=1
                if formula[j]==')': zag+=1
                
            zag=0
            for j in range(Or, len(formula)):
                if formula[j]==')' and zag==0:
                    end=j
                    break
                if formula[j]=='(': zag+=1
                if formula[j]==')': zag-=1
                
            if ok==1:
                zamjena=['(']
                zamjena.extend(formula[start+1:And])
                zamjena.append('||')
                zamjena.extend(formula[Or+1:end])
                zamjena.append(')')
                zamjena.append('&')                           
                zamjena.append('(')
                zamjena.extend(formula[And+1:Or-1])
                zamjena.append('||')
                zamjena.extend(formula[Or+1:end])            
                zamjena.append(')')
                
                del formula[start:end]
                temp=formula[start:len(formula)]
                del formula[(start):len(formula)]
                map(formula.append, zamjena)
                map(formula.append, temp)

            i-=1
    #(F V ( G /\ H ) )
        if formula[i]=='||' and formula[i+1]=='(':
            Or=i
            zag=0;ok=0;
            for j in range(i+2,len(formula)):
                if formula[j]==')' and zag==0:
                    end=j
                    break
                if formula[j]=='&' and zag==0:
                    And=j
                    ok=1
                if formula[j]=='(': zag+=1
                if formula[j]==')': zag-=1
                
            zag=0
            for j in range(Or-1,-1,-1):
                if formula[j]=='(' and zag==0:
                    start=j
                    break
                if formula[j]=='(': zag-=1
                if formula[j]==')': zag+=1
                
            if ok==1:
                zamjena=['(']
                zamjena.extend(formula[start+1:Or])
                zamjena.append('||')
                zamjena.extend(formula[Or+2:And])
                zamjena.append(')')
                zamjena.append('&')                           
                zamjena.append('(')
                zamjena.extend(formula[start+1:Or])
                zamjena.append('||')
                zamjena.extend(formula[And+1:end])            
                zamjena.append(')')
                
                del formula[start+1:end+1]
                temp=formula[start+1:len(formula)]
                del formula[(start+1):len(formula)]
                map(formula.append, zamjena)
                map(formula.append, temp)
            i-=1

                       
    return formula

def PrintSkupKlauzula(formula):
    print "Skup klauzula:\n"
    zag=0
    start=-1
    for i in range(len(formula)):
        if formula[i]=='(': zag+=1
        if formula[i]==')': zag-=1
        if formula[i]=='&':
            if zag>0:
                print " ".join(formula[start+1+zag:i])
            elif zag<0:
                print " ".join(formula[start+1:i+zag])
            elif zag==0:
                print " ".join(formula[start+1:i])
            start=i
            zag=0
        
        
    print " ".join(formula[start+1:(len(formula)+zag)])    



def FinStandardizacija(formula):
    atom=['x','y','z','u','v','p','q','s','r','t','a','b','c','d','e']

    nekoristeni=['x','y','z','u','v','p','q','s','r','t','f','g','h','i','j','k','l','a','b','c','d','e']

    start=-1
    skup=[]
    Nr=0
    mijenjaj=[]
    sada=[]
    izlaz=0
    for i in range(len(formula)):
        j=0
        while j<len(nekoristeni):

            if nekoristeni[j] in formula[i]:
                sada.append(nekoristeni[j])
                del nekoristeni[j]
            j+=1
            

        for k in range(len(atom)):
            
            if (atom[k] in formula[i]) and(atom[k] not in nekoristeni) and (atom[k] not in sada):            
                for l in range(i,len(formula)):

                    formula[l]=formula[l].replace(atom[k],nekoristeni[0])
                    if formula[l]=='&':
                        break
                    
                sada.append(nekoristeni[0])
                del nekoristeni[0]
        if formula[i]=='&':
            sada=[]
        j+=1
    return formula


#GLAVNI PROGRAM
print "Formula jest: "," ".join(izraz)
for i in range(len(izraz)):
    if izraz[i]=='->':
        izraz=makniImplikaciju(izraz)
        print "\nMicanja implikacije: "," ".join(izraz)

izraz=dvostrukaNegacija(izraz)

for i in range(len(izraz)):
    if izraz[i]=='<>':
        izraz=makniEkvivalenciju(izraz)
        print "\nmicanje ekvivalencije: "," ".join(izraz)
izraz=dvostrukaNegacija(izraz)

izraz=dosegNegacije(izraz)

print "\nprovjera dosega negacije: "," ".join(izraz)

izraz=dvostrukaNegacija(izraz)

izraz=preimenovanjeVarijabli(izraz)
print "\nprovjera preimenovanja varijabli: "," ".join(izraz)

izraz=skolemizacija(izraz)
print "\nprovjera i radnje skolemizacije: "," ".join(izraz)

izraz=prenex(izraz)
print "\n prenex: "," ".join(izraz)

izraz=eliminirajPrefix(izraz)
print "\n Bez Prefixa: "," ".join(izraz)

izraz=KonjunkcijaDisjunkcija(izraz)
print "\n oblik konjunkcija disjunkcija: "," ".join(izraz)

PrintSkupKlauzula(izraz)


print "\Nakon standardizacije: "
izraz=FinStandardizacija(izraz)

PrintSkupKlauzula(izraz)



