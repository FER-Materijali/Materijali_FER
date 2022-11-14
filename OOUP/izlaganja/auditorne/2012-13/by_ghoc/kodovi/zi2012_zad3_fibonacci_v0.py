brojPoziva = 0
def fib(n):
    global brojPoziva
    brojPoziva += 1
    print("Poziv funkcije br. %d" %brojPoziva)
    if n < 2:
        return n
    return fib(n-1) + fib(n-2)

def test():
    print([ fib(n) for n in range(5) ])

test()
