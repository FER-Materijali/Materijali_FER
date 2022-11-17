#!/bin/bash
#Skriptni jezici
#Zadatak 6 za 1. ciklus laboratorijskih vjezbi 

#eval za izvrsavanje naredbe iz argumenta, escape na prvi dollar sign i grupiranje $#
#zbog potencijalnog dvoznamenkastog broja
dest=$( eval "echo \${$#}" )

#ako ne postoji destination backup folder, stvori ga
if [ ! -d "$dest" ]; then
    mkdir "$dest"
    echo "Kreiran direktorij $dest"
fi

#init brojaca
copied=0

#for petlja svih argumenata osim zadnjeg (dest dir)
for dat in "${@:1:$(($#-1))}"; do   #sublista od liste argumenata -> n-1
    if [ -f "$dat" -a -r "$dat" ]; then #provjeri jel je datoteka i citljiva
        cp "$dat" "$dest"   #kopiraj
        ((copied+=1))       #povecaj brojac
    else
        echo "Datoteka - "$dat" - ne postoji ili nije čitljiva!"
    fi
done

echo "Broj datoteka kopirano u "$dest": "$copied""

