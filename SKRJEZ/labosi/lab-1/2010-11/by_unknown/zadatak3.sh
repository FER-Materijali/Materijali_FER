for i in localhost_access_log.20??-02-??.txt
do

d=`echo $i | cut -d "." -f 2 | cut -d "-" -f 3`
m='02'
y=`echo $i | cut -d "." -f 2 | cut -d "-" -f 1`

echo "datum: $d-$m-$y"

echo "------------------------------------------------------"

cut $i -d '"' -f 2 | sed 's/^/: /g'| sort | uniq -c | tr -s '[\ ]' ' ' | sort -nr

done
