import sys

class Komponenta:
    def __init__(self, atom):
        pass
    def __str__(self):
        pass
    def value(self):
        pass

class Atom(Komponenta):
    def __init__(self, atom):
        self.atom = atom
        
    def __str__(self):
        return self.atom
    
    def value(self):
        try: 
            return float(self.atom)
        except: 
            pass
        
        if self.atom in Symbols: 
            return Symbols[self.atom]
        
        print "Error: " + self.atom
        sys.exit(-1)
    
class Kompozit(Komponenta):
    def __init__(self, oper, lijeviIzraz, desniIzraz):
        self.oper = oper
        self.lijeviIzraz = lijeviIzraz
        self.desniIzraz = desniIzraz
        
    def __str__(self):
        return "({0} {1} {2})".format(self.lijeviIzraz.__str__(), self.oper, self.desniIzraz.__str__())
    
    def value(self):
        pass
        
class KompozitPlus(Kompozit):
    def value(self):
        return self.lijeviIzraz.value() + self.desniIzraz.value()
class KompozitMinus(Kompozit):
    def value(self):
        return self.lijeviIzraz.value() - self.desniIzraz.value()
class KompozitPuta(Kompozit):
    def value(self):
        return self.lijeviIzraz.value() * self.desniIzraz.value()
class KompozitPodijeljeno(Kompozit):
    def value(self):
        return self.lijeviIzraz.value() / self.desniIzraz.value()

class Operator:
    def getKompozit(self):
        pass
        
class Plus(Operator):
    def getKompozit(self):
        return KompozitPlus
    def __str__(self):
        return '+'
class Minus(Operator):
    def getKompozit(self):
        return KompozitMinus
    def __str__(self):
        return '-'
class Puta(Operator):
    def getKompozit(self):
        return KompozitPuta
    def __str__(self):
        return '*'
class Podijeljeno(Operator):
    def getKompozit(self):
        return KompozitPodijeljeno
    def __str__(self):
        return '/'

Operators = [Plus(), Minus(), Puta(), Podijeljeno()]

def KompozitFactory(operator, lijeviIzraz, desniIzraz):
    for oper in Operators:
        if oper.__str__() == operator:
            return oper.getKompozit()(operator, lijeviIzraz, desniIzraz)
    

def parse(strInput):
    for operator in ["+-", "*/"]:
        depth = 0
        for p in range(len(strInput) - 1, -1, -1):
            if strInput[p] == ')': depth += 1
            elif strInput[p] == '(': depth -= 1
            elif depth==0 and strInput[p] in operator:
                # strInput is a compound expression
                return KompozitFactory(strInput[p], parse(strInput[:p]), parse(strInput[p+1:]))
    strInput = strInput.strip()
    if strInput[0] == '(':
        # strInput is a parenthesized expression?
        return parse(strInput[1:-1])
    # strInput is an atom!
    return Atom(strInput)

Symbols = {}