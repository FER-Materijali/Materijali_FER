if [ "$#" -ne 2 ] 
then

	echo "NEISPRAVAN BROJ PARAMETARA"
	echo "Ispravno koristenje skripte:"
	echo "sh zadatak4.sh /izvorni_direktorij/ /odredisni_direktorij/"
	echo "OBAVEZNO sa / na kraju svakog direktorija"
	exit

fi

src=$1
dest=$2

for i in $(ls "$src")
do

	control=$(echo $i | cut -d '.' -f 2)
	
	if [ $control != txt ]
	then
		continue
	fi


	name=$(stat -c %y "$src$i" | cut -d "-" -f1,2)
	
	target="$dest$name/"

	

	if [ ! -d $target ]
	then
		mkdir $target
	fi

	

	mv "$src$i" "$target$i"

	echo 'ODRADJENO'


done
