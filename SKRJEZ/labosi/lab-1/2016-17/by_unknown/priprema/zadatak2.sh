#!/bin/bash
#Skriptni jezici
#Zadatak 2 za 1. ciklus laboratorijskih vjezbi 


# -i flag za ignorecase, | or operator, egrep == grep -E
egrep -i 'banana|jabuka|jagoda|dinja|lubenica' namirnice.txt

#-v invert match, >dat preusmjeren output u datoteku
egrep -vi 'banana|jabuka|jagoda|dinja|lubenica' namirnice.txt > ne-voce.txt

#-n number line prefix, r rekurzivno po direktorijima, jednostavan regex
egrep -nr '[A-Z]{3}[0-9]{6}' ~/projekti

# -a and operator, izmedu dva mtime-a, dodatna naredba -ls za prikaz detaljnih podataka
find ~/ -mtime +7 -a -mtime -14 -ls

#seq koristim za generiranje liste brojeva (seq ITEM1 ITEM2)
for i in $(seq 1 15) ; do echo -n "$i " ; done
echo

