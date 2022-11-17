#!/bin/bash
#Skriptni jezici
#Zadatak 5 za 1. ciklus laboratorijskih vjezbi 

# $# ispis svih argumenata
echo "$@"

#provjera za 2 argumenta, ako nema 2 argumenta, izlazi
if [ $# != 2 ]; then
    echo "Upisi 2 argumenta"
    exit 1
fi

#dodjela imena argumentima, init ukupnog broja redova na 0
dir=$1
pattern=$2
declare -i total=0


#za svaku datoteku koju naredba find pronađe unutar direktorija dir a zadovoljava pattern
#dodaj broj redova u ukupan broj redova
OIFS="$IFS"
IFS=$'\n'
for file in $(find "$dir" -name "$pattern"); do
    total+=$(($(wc -l "$file" | cut -d' ' -f1) ))
done
IFS="OIFS"
echo $total
