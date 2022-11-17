#!/bin/bash

broj_redaka=6
if [ "$#" -eq 1  ];then
 if [ -d "$1" ];then
  direktorij="$1"
 else
  echo "Prvi argument je datoteka ili ne postoji."
  exit 1
 fi
else
 if [ -d "$1" ];then
 direktorij="$1"
 $broj_redaka="$2"
 else
  echo "Prvi argument je datoteka ili ne postoji."
  exit 1
 fi
fi
echo "$direktorij"
echo "$broj_redaka"
for skripta in $(ls "$direktorij") ;do
 echo "Ime skripte: $skripta"
 echo "-----------------------------"
  head -n $broj_redaka "$direktorij/$skripta"
done
