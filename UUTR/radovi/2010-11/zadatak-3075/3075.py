# -*- coding: cp1250 -*-
def fun(niz1,niz2):
    if niz1==niz2[1:]:
        print 'Gotovo generiranje za niz',niz1
    else:
        return
print '                          Linearno ograničeni automat'
print 'Zadana je konteksno neovisna gramatika G=(V,T,P,S) sa prijelazima:'
print '''
S->ABc
S->acD
A->bc
A->a
B->b
C->AB
D->a
D->ba'''
print '\nPrazan znak: P'
ulaz="bcbc"
print '\nUlazni niz je:',ulaz
ulaz=list(ulaz)
d=len(ulaz)
if d==0:
    print "LOA ne prihvaca prazan niz"
else:
    trag1=[]
    trag2=[]
    trag1="&"
    trag1=list(trag1)
    trag1=trag1+ulaz
    trag1.append ("$")
    print '\nPrvi trag trake je: ',trag1
    trag2.append('P')
    trag2.append('S')
    trag2.append('P')
    trag2.append('P')
    trag2.append('P')
    print '\nDrugi trag trake je:',trag2
    prod=[]
    st=[]
    st.append('q0')
    print '\nKonstrukcija automata'
    prod.append("(q0,[b,S])->(q0,[b,A],R)")
    trag2[1]='A'
    print prod[-1:],trag2
    fun(ulaz,trag2)
    prod.append('(q0,[b,A])->(q0,[b,b],R)')
    trag2[1]='b'
    print prod[-1:],trag2
    fun(ulaz,trag2)
    prod.append('(q0,[c,P])->(q1,[c,c],R)')
    trag2[2]='c'
    print prod[-1:],trag2
    st[0]=('q1')
    fun(ulaz,trag2)
    prod.append('(q1,[b,P])->(q2,[b,B],R)')
    trag2[3]='B'
    print prod[-1:],trag2
    st[0]=('q2')
    fun(ulaz,trag2)
    prod.append('(q1,[b,B])->(q2,[b,b],R)')
    trag2[3]='b'
    print prod[-1:],trag2
    fun(ulaz,trag2)
    prod.append('(q2,[c,P])->(q3,[c,c],R)')
    trag2[4]='c'
    print prod[-1:],trag2
    st[0]=('q3')
    fun(ulaz,trag2)
    ulaz='abc'
    ulaz=list(ulaz)
    trag2=[]
    trag2.append('P')
    trag2.append('S')
    trag2.append('P')
    trag2.append('P')
    st.append('q0')
    prod.append("(q0,[a,S])->(q0,[a,A],R)")
    trag2[1]='A'
    print prod[-1:],trag2
    fun(ulaz,trag2)
    prod.append("(q0,[a,A])->(q0,[a,a],R)")
    trag2[1]='a'
    print prod[-1:],trag2
    fun(ulaz,trag2)
    prod.append("(q0,[b,P])->(q1,[b,B],R)")
    trag2[2]='B'
    print prod[-1:],trag2
    st[1]=('q1')
    fun(ulaz,trag2)
    prod.append("(q0,[b,B])->(q1,[b,b],R)")
    trag2[2]='b'
    print prod[-1:],trag2
    fun(ulaz,trag2)
    prod.append("(q1,[c,P])->(q2,[c,c],R)")
    trag2[3]='c'
    print prod[-1:],trag2
    st[1]=('q2')
    fun(ulaz,trag2)
    ulaz='aca'
    ulaz=list(ulaz)
    trag2=[]
    trag2.append('P')
    trag2.append('S')
    trag2.append('P')
    trag2.append('P')
    st.append('q0')
    prod.append("(q0,[a,S])->(q0,[a,a],R)")
    trag2[1]='a'
    print prod[-1:],trag2
    fun(ulaz,trag2)
    prod.append("(q0,[c,P])->(q1,[c,c],R)")
    trag2[2]='c'
    print prod[-1:],trag2
    st[2]=('q1')
    fun(ulaz,trag2)
    prod.append("(q1,[a,P])->(q2,[a,D],R)")
    trag2[3]='D'
    print prod[-1:],trag2
    st[2]=('q2')
    fun(ulaz,trag2)
    prod.append("(q1,[a,D])->(q2,[a,a],R)")
    trag2[3]='a'
    print prod[-1:],trag2
    fun(ulaz,trag2)
    ulaz='acba'
    ulaz=list(ulaz)
    trag2.append('P')
    trag2[3]='P'
    trag2[2]='P'
    trag2[1]='S'
    st.append('q0')
    prod.append("(q0,[a,S])->(q0,[a,a],R)")
    trag2[1]='a'
    print prod[-1:],trag2
    fun(ulaz,trag2)
    prod.append("(q0,[c,P])->(q1,[c,c],R)")
    trag2[2]='c'
    print prod[-1:],trag2
    st[3]=('q1')
    fun(ulaz,trag2)
    prod.append("(q1,[b,P])->(q2,[b,D],R)")
    trag2[3]='D'
    print prod[-1:],trag2
    st[3]=('q2')
    fun(ulaz,trag2)
    prod.append("(q1,[b,D])->(q2,[b,b],R)")
    trag2[3]='b'
    print prod[-1:],trag2
    fun(ulaz,trag2)
    prod.append("(q2,[a,P])->(q3,[a,a],R)")
    trag2[4]='a'
    print prod[-1:],trag2
    st[3]=('q3')
    fun(ulaz,trag2)
    print '\nStanja automata su: q0, q1, q2, q3'
    print '\nPrihvatljiva stanja su:'
    if 'q1' in st:
        print 'q1'
    if 'q2' in st:
        print 'q2'
    if 'q3' in st:
        print 'q3'
    if 'q4' in st:
        print 'q4'
    print '\nPrijelazi'
    for i in range(len(prod)):
        print prod[i]
raw_input("\nPress ENTER")        
        
    
    
    
        
    
    
   
        
        
        
    
    
 



