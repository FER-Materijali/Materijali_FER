echo $1 | cut -d ";" -f 3 studenti.txt | sort | uniq -c | sort -n | sed -r "s/([0-9]{1,})  ([0-9].[A-Z][0-9])/\2 : \1/" | sed "s/^[ \t]*//" |  sed 's/^/   /' 

