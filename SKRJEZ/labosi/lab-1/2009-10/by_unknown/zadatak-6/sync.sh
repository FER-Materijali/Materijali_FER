if [ 2 -ne $# ]; then
	echo "Očekivana su 2 ulazna parametra." 1>&2;
	exit 1;
fi

if [ -f "$1" ]; then
	echo "Prvi parametar je datoteka. Očekivan je bio direktorij." 1>&2;
	exit 2;
fi

if [ -f "$2" ]; then
	echo "Drugi parametar je datoteka. Očekivan je bio direktorij." 1>&2;
	exit 3;
fi

if [ ! -e "$2" -a ! -e "$1" ]; then
	echo "Niti jedan od ulaznih direktorija ne postoji. Sinkronizacija nema smisla." 1>&2;
	exit 4;
fi

prvi=$(echo "$1" | sed 's/\///');
drugi=$(echo "$2" | sed 's/\///');

for datPrve in "$prvi"/*; do
	if [ ! -r "$datPrve" ]; then
		echo "$datPrve se ne može pročitati. Preskače se." 1>&2;
		continue;
	fi
	dat=$(echo $datPrve | cut -d \/ -f 2);
	if [ ! -e "$drugi/$dat" ]; then
		cp "$datPrve" "$drugi/$dat" --preserve=timestamps;
		echo "$datPrve -> $drugi";
	else
		vrijemePrve=$(stat -c %Y "$datPrve");
		vrijemeDruge=$(stat -c %Y "$drugi/$dat");
		if [ $vrijemePrve -gt $vrijemeDruge  ]; then
		     cp "$datPrve" "$drugi/$dat" --preserve=timestamps;		
		     echo "$datPrve -> $drugi";
		fi
	fi
done


for datDruge in "$drugi"/*; do
	if [ ! -r "$datDruge" ]; then
		echo "$datDruge se ne može pročitati. Preskače se." 1>&2;
		continue;
	fi
	dat=$(echo $datDruge | cut -d \/ -f 2);
	if [ ! -e "$prvi/$dat" ]; then
		cp "$datDruge" "$prvi/$dat" --preserve=timestamps;
		echo "$datDruge -> $prvi";
	else
		vrijemeDruge=$(($(stat -c %Y "$datDruge")-2));
		vrijemePrve=$(stat -c %Y "$prvi/$dat");
		if [ $vrijemeDruge -gt $vrijemePrve  ]; then
			cp "$datDruge" "$prvi/$dat" --preserve=timestamps;
			echo "$datDruge -> $prvi";
		fi
	fi
done


