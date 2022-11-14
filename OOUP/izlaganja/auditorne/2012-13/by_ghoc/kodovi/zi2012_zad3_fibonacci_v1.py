brojPoziva = 0


class Sequence:
    def get(self, n):
        raise NotImplementedError


class Fibonacci(Sequence):
    def get(self, n):
        global brojPoziva
        brojPoziva += 1
        print("%d. poziv funkcije" %brojPoziva)
        if n < 2:
            return n
        return self.get(n-1) + self.get(n-2)


class CachedSequence(Sequence):
    def __init__(self, seq):
        self.sequence = seq
        self.cache = dict() # self.cache = {}

    def get(self, n):
        if n in self.cache.keys():
            print("  imam %d u cacheu" %n)
            return self.cache[n]
        else:
            print("  nemam %d u cacheu" %n)
            fib_n = self.sequence.get(n)
            self.cache[n] = fib_n
            return fib_n

def test ():
    F = Fibonacci()
    cachedSeq = CachedSequence(F)
    
    print([cachedSeq.get(n) for n in range(5) ])

        
test()
