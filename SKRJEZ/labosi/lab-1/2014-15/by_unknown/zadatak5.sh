#!/bin/bash
#5. zadatak

kazalo=$1
ime=$2
 
echo kazalo je $kazalo
echo argument ime je $ime
declare -i ukupno=0
 
for folder in $(find $kazalo -type d)
        do
        echo trenutni folder je $folder
 
        for datoteka in `find "$folder" -maxdepth 1 -name "$ime" `
                do
                        broj=`wc -l $datoteka | cut -d " " -f 1`
                        ukupno=$((ukupno + broj))
                        echo trenutna $datoteka
                        echo trenutni broj je $broj trenutno ime$ime
 
 
                done
        done
 
 
echo $ukupno