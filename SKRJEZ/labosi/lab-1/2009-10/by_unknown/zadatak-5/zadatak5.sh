test 2 -ne $# && echo "Očekivana su 2 parametra." && exit 3;

if [ ! -e "$1" ]; then
	echo "Prva datoteka ne postoji";
	exit 1;
fi

if [ ! -e "$2" ]; then
	echo "Druga datoteka ne postoji";
	exit 2;
fi

echo
echo "JMBAG Prezime Ime (grupa) Broj_bodova_1 Broj_bodova_2"
while read redakDruge; do
	mbr=$(echo $redakDruge | sed -r 's/([0-9]{10}).*/\1/')
	brbod2=$(echo $redakDruge | sed -r 's/[0-9]{10}.([0-9]*)/\1/')
	redakPrve=$(grep $mbr "$1" | sed 's/ //g')
	prezimeIme=$(echo $redakPrve | cut -d \; -f 2 | sed -r 's/[,]/ /')
	grupa=$(echo $redakPrve | cut -d \; -f 4)
	brbod1=$(echo $redakPrve | cut -d \; -f 3)
	test -z "$prezimeIme" && prezimeIme="-- --"
	test -z "$grupa" && grupa="--"
	test -z "$brbod1" && brbod1="--"
	echo "$mbr $prezimeIme ($grupa) $brbod1 $brbod2"
done < "$2"
echo
