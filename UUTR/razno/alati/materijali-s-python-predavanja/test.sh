#!/bin/bash

for i in {1..2}; do
	echo "Testiram primjer #${i}"
	python dka.py "ulaz${i}.txt" > "moj_izlaz_${i}.txt"
	diff "izlaz${i}.txt" "moj_izlaz_${i}.txt"
done
