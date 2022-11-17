echo $1
echo $2

broj=0
for datoteka in $(find "$1" -regex ".*$2"); do
	broj=$((broj+$(wc -l $datoteka | cut -d" " -f1)))
done
echo $broj
