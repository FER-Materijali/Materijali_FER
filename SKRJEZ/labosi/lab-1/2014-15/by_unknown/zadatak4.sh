#!/bin/bash
#4. zadatak

izvorni=$1
odrediste=$2

echo $izvorni
echo $odrediste

if [ ! -d $odrediste ]
        then
        mkdir $odrediste
        echo $odrediste
        fi

for foto in `ls $izvorno`
        do
        echo $izvorno
        echo $foto
        datum=`stat $foto | grep -i 'Modify:' | grep -iE -o '[0-9]{4}-[0-9]{2}'`
        godina=`echo $datum | cut -d "-" -f 1`
        mjesec=`echo $datum | cut -d "-" -f 2`
        folder="$odrediste/$godina-$mjesec/"
        echo $folder
        if [ ! -d $folder ]
                then
                mkdir $folder
                fi
        mv "$izvorno$foto" "$folder$foto"

done