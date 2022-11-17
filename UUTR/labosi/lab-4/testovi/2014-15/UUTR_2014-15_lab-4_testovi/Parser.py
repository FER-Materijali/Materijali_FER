import sys

class Seq(object):
    def __init__(self, s):
        self.s = s

    def peek(self):
        return self.s[0]

    def next(self):
        self.s = self.s[1:]
        return self.s[0]

seq = Seq(sys.stdin.readline().strip() + '\n')

def chartest(c):
    return lambda: seq.peek() == c

def advance_seq():
    seq.next()
    return True

def lazy_call(*funs):
    for f in funs:
        yield f()

def S():
    print('S', end='')
    if seq.peek() == 'a': # S -> aAB
        return all(lazy_call(advance_seq, A, B))
    elif seq.peek() == 'b': # S -> bBA
        return all(lazy_call(advance_seq, B, A))
    else:
        return False

def A():
    print('A', end='')
    if seq.peek() == 'b': # A -> bC
        return all(lazy_call(advance_seq, C))
    elif seq.peek() == 'a': # A -> a
        return advance_seq()
    else:
        return False

def B():
    print('B', end='')
    if seq.peek() == 'c': # B -> ccSbc
        return all(lazy_call(advance_seq, chartest('c'), advance_seq, S, chartest('b'), advance_seq, chartest('c'), advance_seq))
    else:
        return True # B -> eps

def C():
    print('C', end='')
    return all(lazy_call(A, A)) # C -> AA

# run the parser
print('\n{}'.format('DA' if S() and seq.peek()=='\n' else 'NE'))
