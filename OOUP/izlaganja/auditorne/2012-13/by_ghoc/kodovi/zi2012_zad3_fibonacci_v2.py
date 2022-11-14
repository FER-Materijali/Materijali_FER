brojPoziva = 0


class Sequence:
    def get(self, n):
        raise NotImplementedError


class Fibonacci(Sequence):
    def get(self, n):
        print("  POZVAN GET IZ FIBONACCIJA!")
        global brojPoziva
        brojPoziva += 1
        print("Poziv funkcije br. %d" %brojPoziva)
        if n < 2:
            return n
        return self.get(n-1) + self.get(n-2)


class CachedFibonacci(Fibonacci):
    def __init__(self):
        self.cache = dict() # self.cache = {}

    def get(self, n):
        print("  POZVAN GET IZ CACHED FIBONACCIJA")
        if n in self.cache.keys():
            print("  imam %d u cacheu" %n)
            return self.cache[n]
        else:
            print("  nemam %d" %n)
            fib_n = super(CachedFibonacci, self).get(n)
            self.cache[n] = fib_n
            return fib_n

        
def test ():
    F = Fibonacci()
    cachedFib = CachedFibonacci()
    
    print([cachedFib.get(n) for n in range(5) ])

    
test()
