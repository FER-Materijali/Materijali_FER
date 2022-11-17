#3. zadatak

for ime in `ls | grep -iE '[0-9]{4}-02-[0-9]{2}'`
do
       
        datum=`echo $ime | grep -oE '[0-9]{4}-02-[0-9]{2}'`
       
        dan=`echo $datum | cut -d "-" -f 3`
        mjesec=`echo $datum | cut -d "-" -f 2`
        godina=`echo $datum | cut -d "-" -f 1`
        echo "datum: $dan-$mjesec-$godina"
        echo "--------------------------------------------------"
        cut $ime -d '"' -f 2 | sort | uniq -c | sort -nr

done

