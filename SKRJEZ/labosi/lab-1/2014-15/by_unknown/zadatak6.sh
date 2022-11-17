#!/bin/bash
#6. zadatak
 
lista=`eval "echo \$"$#""`
 
if [ ! -d "$lista" ]
        then
        mkdir "$lista"
        echo kreiran je folder $lista
        fi
declare -i brojac=0
 
for broj in $(seq $(($#-1)))
do
        odrediste=`eval "echo \$"$broj""`
        if [[ -r "$odrediste" && -f "$odrediste" ]]
        then
                cp "$odrediste" "$lista"
                ((brojac++))
        else
        echo Greska pri kopiranju datoteke $odrediste
        fi
done
 
echo $brojac datoteka je kopirano u $lista