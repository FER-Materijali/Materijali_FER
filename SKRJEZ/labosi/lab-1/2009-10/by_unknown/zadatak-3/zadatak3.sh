for dat in localhost_access_log.2008-02-*.txt; do
 dan=`echo $dat | cut -d "-" -f 3`;
 godina=`echo $dat | cut -d "-" -f 1`;
 echo "datum: $dan-02-$godina";
 echo "---------------------------------------------"; 
 cut -d " " -f 6,7,8 $dat | sed -r 's/\"//g' | sort |  uniq -c | sort -n -r;
 echo "---------------------------------------------";
 echo;
done
