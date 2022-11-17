folder=$(eval "echo \$$#")

if [ ! -d "$folder" ]; then
	mkdir "$folder"
	echo "Kreirano je kazalo $folder"
fi

succ=0
for i in $(seq $(($#-1))); do
	if [[ -r $(eval "echo \${$i}") && -f $(eval "echo \${$i}") ]]; then
		cp $(eval "echo \${$i}") "$folder"
		succ=$(($succ+1))
	else 
		echo "Greska"
	fi
done

echo "$succ datoteka kopirano je u kazalo $folder"