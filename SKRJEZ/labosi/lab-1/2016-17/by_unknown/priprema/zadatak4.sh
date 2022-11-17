#!/bin/bash
#Skriptni jezici
#Zadatak 4 za 1. ciklus laboratorijskih vjezbi 

#provjeri kolko ima argumenata, moraju biti 2

if [ $# != 2 ]; then
    echo "Unesi 2 argumenta"
    exit 1
fi

src="$1"    #definiranje imena argumentima
dest="$2"

if [ ! -d $dest ]; then #ako ne postoji destination folder, napravi ga
    mkdir "$dest"
fi

for slika in $(ls $src); do     #za svaku sliku u popisu slika iz source-a
    #echo $slika                 uzmi godinu i mjesec, provjeri postoji li direktorij
    datum=$(stat -c %y $src/$slika | cut -d'-' -f1,2)   #ako ne, napravi ga i premjesti
    #echo $datum
    if [ ! -d $dest/$datum ]; then
        mkdir $dest/$datum
    fi
    mv $src/$slika $dest/$datum
done
