
ovo su test primjeri izgenerirani sa http://161.53.19.109/~agrbin/ppj/ skripte.
svaki (ma kako glupi) unos bilo kojeg korisnika koji je prosao leksicku i
sintaksnu analizu je test primjer.

u direktoriju tp se nalazi dosta fajlova od kojih neki imaju isto ime.
njihove ekstenzije su

  c - izvorni kod programa koji je izgenerirao sintaksno stablo
  lex - fajl nastao leksickom analizom c programa
  in - generativno stablo (ulaz u semanticki analizator)
  out - izlaz iz semantickog analizatora (moze biti prazno)  -> nalazi se u ocekivani_output
  explain - objasnjenje za ulaz (koja linija, sto se dogodilo)

cudno ime fajla je md5 suma od X.c datoteke.

X.out i X.explain su prazni ako je X.c fajl semanticki tocan.

naravno, ne garantiram tocnost. ulazne datoteke su pisali korisnici navedene
skripte.

nas semanticki analizator mora primit .in fajl i dati .out fajl.

known bugs
----------

postoji greska u leksickoj definiciji ppjC jezika sa gutanjem niza znakova
"\\". greska je vidljiva u output-ovima od ovog test primjera:

http://161.53.19.109/~agrbin/ppj/details.php?33afe63b1ee4035db26b059b2d99aa35

ovdje se nasi analizatori mogu razlikovat. gresku sam prijavio ppj asistentima,
rekli su da je stvarno greska i da nece (naravno) doci u test primjerima 3.
labosa.


zivjeli,
Anton Grbin
