#!/bin/bash

tocni=$((0))
i=$((1))

if [ -d krivi ];then rm -rf krivi; fi;

while read line
do
	echo $line > .temp.in

	./Parser < .temp.in > .moj.out
	diff --brief .moj.out out/$i.out >/dev/null

	if [ $? -eq 1 ]
	then
		if [ ! -d krivi ];then mkdir krivi; fi;
		mv .moj.out krivi/LOSE_$i.txt
		echo -e "\n\nTocno rjesenje:" >> krivi/LOSE_$i.txt
		cat out/$i.out >> krivi/LOSE_$i.txt
	else tocni=$(($tocni+1))
	fi

	i=$(($i+1))

done < ulazi.txt

rm -f .moj.out .temp.in
echo "Tocno: $tocni/1026 primjera."

if [ -d krivi ];then echo "Krivi ispisi su u folderu 'krivi'"; fi;
