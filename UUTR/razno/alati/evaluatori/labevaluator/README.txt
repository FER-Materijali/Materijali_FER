Program se pokrece iz komandne linije.

1) Pozicioniraj se u datoteku gdje je i Evaluator.java.
2) Iskompajliraj: javac Evaluator.java
3) Pokreni: java Evaluator -v [opcionalno] /put/do/programa/koji/testiras/Program.java /put/do/korijenskog/direktorija/testova

* Korijenski direktorij s testovima mora sadrzavati SAMO testove s ekstenzijama .in i .out. Primjer direktorija s testovima:

— testovi
    — test01
        — test.in
        — test.out
    — test02
        — test.in
        — test.out

* Ako se kao prvi argument Evaluatoru preda “-v” ili “—verbose”, ispisivat ce se ocekivani i stvarni izlaz za svaki test posebno.


Primjeri pokretanja:

bez verbose) java Evaluator -v /Users/slepi/UTR/SimPa.java /Users/apple/UTR/testovi/
s verbose) java Evaluator /Users/slepi/UTR/SimPa.java /Users/apple/UTR/testovi/

Primjeri rada: 

bez verbose) 
Evaluation of SimPa.java: 25/25 hits.

s verbose) 
test02: correct
Actual: [q1#K|q1#NK|q2#NK|q2#K|q3#$|1]
Expected: [q1#K|q1#NK|q2#NK|q2#K|q3#$|1]

test03: correct
Actual: [q1#K|q1#JK|q2#JK|fail|0]
Expected: [q1#K|q1#JK|q2#JK|fail|0]
