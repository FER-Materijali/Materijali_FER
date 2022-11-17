grep -i -E "\<banan|\<jabuk|\<jagod|\<dinj|\<luben" namirnice.txt
echo

grep -i -v -E "\<banan|\<jabuk|\<jagod|\<dinj|\<luben" namirnice.txt > ne-voce.txt
echo

grep -E -n -R '.*[A-Z]{3}[0-9]{6}.*' ~/projekti/
echo

find ~/ -mtime -14 -mtime +7 -ls
echo

for i in $(seq -s " " 1 15); do echo "broj "$i; done
echo

brojac=0
for i in *; 
 do if test -f $i
 then 
	brojac=$(($brojac+1));
	echo $brojac": "$i" ... "`wc -l $i | cut -d " " -f 1`" redaka";
	echo "--------------------------";
	head -n 3 $i;
	echo; 
 fi
done
