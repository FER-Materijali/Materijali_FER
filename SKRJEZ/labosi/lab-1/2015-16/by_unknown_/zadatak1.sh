#!/bin/bash

#a)
proba="Ovo je proba"

#b)
echo "$proba"

#c)
lista_datoteka=*
echo $lista_datoteka

#d)
proba3="$proba. $proba. $proba. "

#e)
a=4
b=3
c=7
d=$((($a+4)*($b%$c)))

#f)
broj_rijeci=$(cat *.txt | wc -w)
echo $broj_rijeci

#g)
ls ~

#h)
cut -d ":"  -f 1,6,7 /etc/passwd

#i)
ps u n | tr -s " " | cut -d " " -f 2,3,11- 
