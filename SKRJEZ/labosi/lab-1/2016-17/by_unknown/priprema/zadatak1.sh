#!/bin/bash
#Skriptni jezici
#Zadatak 1 iz laboratorijskih vjezbi


proba="Ovo je proba" #postavljanje vrijednosti varijable ljuske

echo $proba     #ispisi vrijednost

echo        #<br>

lista_datoteka=*  #sirenje imena datoteka (svi znakovi)

echo $lista_datoteka    #ispis

echo

i=0
proba3=""
while [ "$i" -lt 3 ] 
do
    proba3+=""$proba". "
    i=$((i+1))
done
                            #proba3 inicijaliziran u prazan string, i=0
                            #svakim prolaskom kroz petlju se upise jedna recenica
                            #te se varijabla i poveca za 1
echo $proba3

echo

a=4; b=3; c=7;
                    #supervised, (a+4) * b % c treba ispasti 3
d=$(( (a+4)*b%c ))
echo $d

echo

    #wc ima output broja rijeci za svaku datoteku i na kraju total X, gdje je X broj
    #sa tailom pokupimo zadnji redak, cut na razmake i uzimamo 2. field jer je ispred broja
    #takoder razmak na outputu
broj_rijeci=$(wc -w *.txt | tail -n 1 | cut -d' ' -f2)
echo $broj_rijeci

echo   

ls ~/       #command substitution na ls, ~ oznacava home direktorij

echo

cut -d':' -f1,6,7 </etc/passwd 

echo

#rjesenje s regexom, ne znam jel dozvoljeno 
#ps -ef | sed -r 's/\s+/ /g' | cut -d' ' -f1,2,8 

#rjesenje sa naredbom tr, takoder ne znam jel se smije koristiti, ali nije regex :)
ps -ef | tr -s ' ' | cut -d' ' -f1,2,8








