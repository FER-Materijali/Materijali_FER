#! /bin/bash

touch pom.txt
n=$((0))
for i in {1..10}
do
	python3 SimTS.py < in/test$i.in > pom.txt
	diff --brief pom.txt out/test$i.out >/dev/null
	if [ $? -eq 1 ]
	then
		if [ ! -d krivi ];then mkdir krivi; fi;
		mv pom.txt krivi/krivi$i.txt
	else n=$(($n+1))
	fi
done

rm -f pom.txt
echo "Tocno: $n/10 primjera."

if [ -d krivi ];then echo "Krivi ispisi su u folderu 'krivi'"; fi;
