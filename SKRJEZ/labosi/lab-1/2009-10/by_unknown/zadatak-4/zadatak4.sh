if test 2 -ne $#
then
	echo "Neispravan broj ulaznih parametara."
	exit 1
fi

if test ! -d "$1"
then
	echo "Izvorno kazalo ne postoji ili nije direktorij."
	exit 1
fi


if test ! -e "$2"
then	
	mkdir "$2";
fi

for slika in `ls $1`; do 
	fold=`stat slike/"$slika" --format=%y | cut -d " " -f 1`
	if test ! -e $2/$fold
	then	
		mkdir $2/$fold;
	fi
	mv $1/"$slika" $2/$fold/"$slika";
done







