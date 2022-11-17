brojac=0
for i in *; 
 do test -f $i && brojac=$(($brojac+1)); echo $brojac": "$i" ... "`wc -l $i | cut -d " " -f 1`" redaka"; echo "--------------------------"; head -n 3 $i; echo; 
done
