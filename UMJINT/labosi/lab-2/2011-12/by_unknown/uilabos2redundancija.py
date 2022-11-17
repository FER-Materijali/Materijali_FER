ie = [ '->', '<->']
operatori = ['|', '&', '~']
import copy
import time
normalanIspis = list()
def ekviImp(formula):

    
    if formula[0] in ie:
        if formula[0] == '->':
            formula[0], formula[1], formula[2] = remove_implication(formula[1], formula[2])
        else:
            formula[0], formula[1], formula[2] = remove_equivalency(formula[1], formula[2])

    if len(formula) > 1 and isinstance(formula[1], list):
        ekviImp(formula[1])
    if len(formula) == 3 and isinstance(formula[2], list):
        ekviImp(formula[2])

    return formula

##
def move_not(formula):


    if len(formula) == 2 and formula[0] == '~' and isinstance(formula[1], str):
        return formula
    
    if formula[0] == '~' and not formula[1][0]=="~":
        formula = copy.deepcopy(remove_not(formula[1:]))

    if len(formula) > 1 and isinstance(formula[1], list):

        if isinstance(formula[1][1], list) :
            formula[1] = move_not(formula[1])

    if len(formula) == 3 and isinstance(formula[2], list) :

        if isinstance(formula[2][1], list) :
            formula[2] = move_not(formula[2])
    

    return formula


def remove_not(izraz):
    izraz = copy.deepcopy(izraz[0])

    if izraz[0] == '|':
        izraz[0] = '&'
    elif izraz[0] == '&':
        izraz[0] = '|'


    if len(izraz) == 3:
        if izraz[1][0] == '~':
            izraz[1] = copy.deepcopy(izraz[1][1])
        else:
            izraz[1] = copy.deepcopy(['~', izraz[1]])
            
        if izraz[2][0] == '~':
            izraz[2] = copy.deepcopy(izraz[2][1])
        else:
            izraz[2] = copy.deepcopy(['~', izraz[2]])
    
    return izraz

        
            
        


def remove_implication(a, b):
    return '|', ['~',a], b

def remove_equivalency(a, b):
    return '&',['|',['~',a], b],['|',['~',b], a]




def promijeni2(izraz):
    #print izraz
    novi = list()
    novi.append('&')
    novi.append(['|', izraz[1], izraz[2][1]])
    novi.append(['|', izraz[1], izraz[2][2]])

    return novi

def promijeni1(izraz):
    #print izraz
    novi = list()
    novi.append('&')
    novi.append(['|', izraz[2], izraz[1][1]])
    novi.append(['|', izraz[2], izraz[1][2]])

    return novi




def distributivnost(formula):

    if len(formula) > 1 and len(formula[1]) == 3:
        formula[1] = distributivnost(formula[1])
    if len(formula) > 2 and len(formula[2]) == 3:
        formula[2] = distributivnost(formula[2])

        
    if len(formula) > 1 and isinstance(formula[1], list):
        if len(formula[1]) == 3 and formula[1][0] == '&' and formula[0] == '|':
            formula = copy.deepcopy(promijeni1(formula))
            
    if len(formula) > 2 and isinstance(formula[2], list):
        if len(formula[2]) == 3 and formula[2][0] == '&' and formula[0] == '|':
            formula = copy.deepcopy(promijeni2(formula))



    if len(formula) > 1 and len(formula[1]) == 3:
        formula[1] = distributivnost(formula[1])
    if len(formula) > 2 and len(formula[2]) == 3:
        formula[2] = distributivnost(formula[2])
    return formula



def involucija(formula):

    if len(formula) == 3:
        formula[1] = involucija(formula[1])
        formula[2] = involucija(formula[2])

    if formula[0] == '~' and formula[1][0] == '~':
        formula = copy.deepcopy(formula[1][1])

    return formula


def faktorizacija(formula):
    #print "FAKTORIZACIJA",formula
    if formula[0] == '|':
        if formula[1] == formula[2]:
            formula = copy.deepcopy(formula[1])
            formula = copy.deepcopy(faktorizacija(formula))
        else:
            formula[1] = copy.deepcopy(faktorizacija(formula[1]))
            formula[2] = copy.deepcopy(faktorizacija(formula[2]))

    else:
        if len(formula) == 3:
            formula[1] = copy.deepcopy(faktorizacija(formula[1]))
            formula[2] = copy.deepcopy(faktorizacija(formula[2]))

    return formula

def normal(formula):
    global normalanIspis
    if len(formula) == 3:

        if formula[0] == '&':
            formula[1] = copy.deepcopy(normal(formula[1]))
            
            normalanIspis.append("&")
            formula[2] = copy.deepcopy(normal(formula[2]))

        elif formula[0] == '|':
            #normalanIspis.append('&')
            formula[1]=copy.deepcopy(normal(formula[1]))
            formula[2]=copy.deepcopy(normal(formula[2]))
            #normalanIspis.append('&')

    else:

        normalanIspis.append(formula)
            
    

def cnfConvert(formula):

    form = ekviImp(formula)
    removanNot = move_not(form)

    i = 0
    while i < 1:
        removanNot = distributivnost(removanNot)
        i = i+1

    removanNot = involucija(removanNot)
    removanNot = faktorizacija(removanNot)
    normal(removanNot)


    ljista = list()
    for i in normalanIspis:
        if isinstance(i, list):
            i = "".join(i)
            ljista.append(i)
        else:
            ljista.append(i)

    temp = list()
    fer = list()
    ljista.append('&')

    for i in ljista:
        if i != '&':
            temp.append(i)
        else:
            
            fer.append(temp)
            temp = []

    return fer

#____________________________________________________________________#
POSJECENO = list()
def selectClauses(iznadCrte, ispodCrte):

    for k in iznadCrte:
     
        for c in ispodCrte:
          
            for literal in k:
                if literal[0] == '~':
                    negacija = literal[1]
                else:
                    negacija = '~'+literal
                if negacija in c:
                    if [k, c] not in POSJECENO:
                        POSJECENO.append([list(set(k)), list(set(c))])
                        
                        return list(set(k)), list(set(c))
                    
                    
def tautologija(formula):

    for i in range(len(formula)-1):
        for j in range(i+1,len(formula)):
            if formula[i][0] == '~':
                neg = formula[i][1]
            else:
                neg = '~'+formula[i]
            if neg in formula:
                return True

    return False

def unija(lista1, lista2):

    konj = lista1[:]

    for i in lista1:
        i.sort()
        if i not in konj:
            konj.append(list(set(i)))
        

    for i in lista2:
        i.sort()

        if i not in konj:
            konj.append(list(set(i)))

    return konj



iznadCrte = list()
ispodCrte = list()

def pretvori(klauzule):

    skupchina = []

    for kla in klauzule:
        for el in kla:
            skupchina.append(el)

    return skupchina

publicIspodCrte = list()
najveciBrojKlauzula = []
tempSkup = list()


def plResolve1(c1, c2):
    skup_rez = list()
    resolve = False
    removeList = []

    for el1 in c1:

        if el1[0] == '~':
            negacija_el1 = el1[1]
        else:
            negacija_el1 = '~'+el1

        if negacija_el1 in c2:

            index1 = c1.index(el1)
            index2 = c2.index(negacija_el1)
            resolve = True
            rez = sorted(list(set(c1[0:index1]+c1[index1+1:]+c2[0:index2]+c2[index2+1:])))

            if rez not in publicIspodCrte and not tautologija(rez):
                publicIspodCrte.append(rez)
                if rez not in tempSkup:
                    tempSkup.append(rez)


    # IZBACI REDUNDANTNE #

    for i in range(len(publicIspodCrte)-1):
        a = set(publicIspodCrte[i])
        for j in range(i+1, len(publicIspodCrte)):
            b = set(publicIspodCrte[j])

            if b.issubset(a):
                if publicIspodCrte[i] not in removeList:
                    removeList.append(publicIspodCrte[i])
                
            elif a.issubset(b):
                if publicIspodCrte[j] not in removeList:
                    removeList.append(publicIspodCrte[j])
                    
    for i in removeList:
        publicIspodCrte.remove(i)
    najveciBrojKlauzula.append(len(publicIspodCrte))

                




def plResolve0(c1, c2):
    skup_rez = list()
    resolve = False
    removeList = []
    for el1 in c1:

        if el1[0] == '~':
            negacija_el1 = el1[1]
        else:
            negacija_el1 = '~'+el1

        if negacija_el1 in c2:

            index1 = c1.index(el1)
            index2 = c2.index(negacija_el1)
            resolve = True
            rez = sorted(list(set(c1[0:index1]+c1[index1+1:]+c2[0:index2]+c2[index2+1:])))

            if rez not in publicIspodCrte:
                publicIspodCrte.append(rez)
                if rez not in tempSkup:
                    tempSkup.append(rez)
                
                
    # IZBACI REDUNDANTNE #

    for i in range(len(publicIspodCrte)-1):
        a = set(publicIspodCrte[i])
        for j in range(i+1, len(publicIspodCrte)):
            b = set(publicIspodCrte[j])

            if b.issubset(a):
                if publicIspodCrte[i] not in removeList:
                    removeList.append(publicIspodCrte[i])
                
            elif a.issubset(b):
                if publicIspodCrte[j] not in removeList:
                    removeList.append(publicIspodCrte[j])
                    
    for i in removeList:
        publicIspodCrte.remove(i)

    najveciBrojKlauzula.append(len(publicIspodCrte))
    
        
                

            

def plResolution0(skup_premisa):
    global normalanIspis
    global publicIspodCrte
    premise = skup_premisa[0:-1]
    ciljna = skup_premisa[-1]
    klauzule = list()
    ciljne_klauzula = list()
    nove_klauzule = list()

    for premisa in premise:

        klauzule.append(cnfConvert(premisa))
        del normalanIspis[:]

    normalanIspis = []
    klauzule = pretvori(klauzule)
    parent = copy.deepcopy(klauzule)
    parentClauses = []
    pparent = []
    for i in parent:
        pparent.append(sorted(i))

    for i in pparent:
        parentClauses.append(list(set(sorted(i))))
            
    new = copy.deepcopy(cnfConvert(ciljna))
    publicIspodCrte = []
    for i in new:
        if isinstance(i, str):
            publicIspodCrte.append([i])
        else:
            publicIspodCrte.append(i)
    
    
    VecRazrjeseni = []
    brojac = 0
    start = time.time()
    while True:

        parovi = kombiniraj(parentClauses, publicIspodCrte)
        prije = publicIspodCrte[:]
        for par in parovi:
            if par not in VecRazrjeseni:
                VecRazrjeseni.append(par)
                plResolve0(par[0], par[1])
                brojac += 1
                if [] in publicIspodCrte:

                    print "\tNIL"
                    print "========================="
                    print "Broj koraka: ", brojac
                    print "Najveci broj klauzula u memoriji: ", max(najveciBrojKlauzula)
                    printLista(parentClauses)
                    print "- - - - - - - - - - - - -"
                    printLista(tempSkup)
                    print time.time()-start
                    return True
                
        if prije == publicIspodCrte: return False
        if publicIspodCrte == publicIspodCrte+parentClauses: return False
        publicIspodCrte = sorted(publicIspodCrte, key = len)




def plResolution1(skup_premisa):
    global normalanIspis
    global publicIspodCrte
    premise = skup_premisa[0:-1]
    ciljna = skup_premisa[-1]
    klauzule = list()
    ciljne_klauzula = list()
    nove_klauzule = list()

    for premisa in premise:

        klauzule.append(cnfConvert(premisa))
        del normalanIspis[:]

    normalanIspis = []
    klauzule = pretvori(klauzule)
    parent = copy.deepcopy(klauzule)
    parentClauses = []
    pparent = []
    for i in parent:
        pparent.append(sorted(i))

    for i in pparent:
        if not tautologija(i):
            parentClauses.append(list(set(sorted(i))))
            
    new = copy.deepcopy(cnfConvert(ciljna))
    publicIspodCrte = []
    for i in new:
        if isinstance(i, str):
            publicIspodCrte.append([i])
        else:
            publicIspodCrte.append(i)
    
    
    VecRazrjeseni = []
    brojac = 0
    start = time.time()
    while True:

        parovi = kombiniraj(parentClauses, publicIspodCrte)

        
        prije = publicIspodCrte[:]
        for par in parovi:
            if par not in VecRazrjeseni:
                VecRazrjeseni.append(par)
                plResolve1(par[0], par[1])
                brojac += 1
                if [] in publicIspodCrte:
                    print "Dokazano"
                    print "Broj koraka: ", brojac
                    print "Najveci broj klauzula u memoriji: ", max(najveciBrojKlauzula)
                    printLista(parentClauses)
                    print "- - - - - - - - - - - - -"
                    printLista(tempSkup)
                    print time.time()-start
                    return True
                
        if prije == publicIspodCrte: return False
        if publicIspodCrte == publicIspodCrte+parentClauses: return False
        publicIspodCrte = sorted(publicIspodCrte, key = len)


def printLista(lista):
    for i in lista:
        print i
        
def kombiniraj(parentClauses, newClauses):
    parovi = []


    for k in parentClauses:
     
        for c in newClauses:
          
            for literal in k:
                if literal[0] == '~':
                    negacija = literal[1]
                else:
                    negacija = '~'+literal
                if negacija in c:
                    t = sorted([k, c])
                    if t not in parovi:
                        parovi.append(t)

    for i in range(len(newClauses)-1):
        for j in range(i+1, len(newClauses)):
            for literal in newClauses[i]:

                if literal[0] == '~':
                    negacija = literal[1]
                else:
                    negacija = '~'+literal

                if negacija in newClauses[j]:
                    t = sorted([newClauses[i], newClauses[j]])
                    if t not in parovi:
                        parovi.append(t)
          
    return parovi




def izgradi_stablo(formula):
    if not len(formula):
        raise ValueError(formula)
    formula = formula.strip()
    if len(formula) == 1 and formula.isupper():
        return formula

    dubina = 0
    stablo = None
    for i in reversed(xrange(len(formula))):
        if formula[i] == ')':
            dubina += 1
        elif formula[i] == '(':
            dubina -= 1
        elif dubina == 0:
            for o in ['<->', '->', '|', '&']:
                pocetak = i - len(o) + 1
                if formula[pocetak:].startswith(o):
                    if stablo is not None:
                        raise ValueError(formula)
                    stablo = [o,izgradi_stablo(formula[0:pocetak]),izgradi_stablo(formula[i + 1:])]
                    break
    if stablo is not None:
        return stablo
    if formula[0] == '~':
        return ['~', izgradi_stablo(formula[1:])]
    if formula[0] == '(' and formula[-1] == ')':
        return izgradi_stablo(formula[1:-1])
    raise ValueError(formula)




print "Unesite svaku formulu u zasebni redak"
print "Za kraj unosa formula unesite '#'"
try:
    skup_premisa = list()
    lista_premisa = list()
    while True:

        premisa = raw_input()
        
        
        if premisa != "#":
            lista_premisa.append(premisa)

        else:
            break
    lista_premisa[-2] = '~('+lista_premisa[-2]+')'
    strategija = lista_premisa[-1]
    lista_premisa = lista_premisa[0:-1]
    for p in lista_premisa:
        p = izgradi_stablo(p)
        skup_premisa.append(p)

except ValueError as e:
    print "Formula nije dobro oblikovana: %s" % e
print "Unesite strategiju..."
print "(0 - strategija skupa potpore, 1 - strategija skupa potpore sa strategijom pojednostavljenja)"
if strategija == '0':
    if plResolution0(skup_premisa):
        print "Dokazano"
    else:
        print "Nije Dokazano"
elif strategija == '1':
    if plResolution1(skup_premisa):
        print "Dokazano"
    else:
        print "Nije Dokazano"
else:
    print "Greska prilikom unosa strategije"
    

