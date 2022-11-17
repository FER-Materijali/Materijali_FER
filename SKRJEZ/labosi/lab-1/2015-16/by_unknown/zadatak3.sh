for datoteka in localhost_access_log.[[:digit:]][[:digit:]]-02*; do
	echo "datuom: $datoteka" | cut -d'.' -f2
	echo "-----------"
	cat $datoteka | cut -d'"' -f2 | sort | uniq -c | tr -s " " | sort -nr
done