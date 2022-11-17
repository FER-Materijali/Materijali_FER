#!/bin/bash

if [ "$#" -ne 2 ]; then
	echo "Krivi broj argumenata"
	exit 
fi

page=$1
log=$2

if [ ! -r $log ]; then
	echo "datoteka nije citljiva"
	exit 
fi

echo "----------------------------------------"
echo "Broj pristupa stranici: $page"
echo "      IP adresa    |     Br.pristupa "
echo "----------------------------------------"

cat $log | cut -f 1 -d' ' | sort | uniq -c -d | sort -n -r | sed -r 's/([0-9]+)(.*)/\2 \t \1/'
echo "----------------------------------------"

