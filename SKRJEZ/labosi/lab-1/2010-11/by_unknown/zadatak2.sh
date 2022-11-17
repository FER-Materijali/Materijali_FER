grep -iE 'banana|jabuka|jagoda|dinja|lubenica' namirnice.txt

grep -ivE 'banana|jabuka|jagoda|dinja|lubenica' namirnice.txt > ne-voce.txt

grep -d recurse -E '([[:upper:]]{3}[[:digit:]]{6})' ~/projekti

find ./ -mtime +7 -mtime -14

for i in `seq 1 15`; do echo $i; done

j=0
for i in *
do

  if [ -f $i ] ; then

       	broj_redaka=$(wc $i -l | cut -d ' ' -f 1)
	


	j=$(($j+1))

	echo $j':' $i '...' $broj_redaka
	echo '-----------------------------'
	cat $i
	echo ' '
  
  fi

done
