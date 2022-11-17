#5.zadatak
if [ "$#" -ne 2 ] 
	then
		echo "Krivi broj parametara!"
		exit
	fi
while read JMBAG2 Broj_bodova_2; 
	do
		redakPrve="$(grep $JMBAG2 "$1")"
		if [ $? = 0 ]
			then
				jmbag=$(echo $redakPrve|cut -f 1 -d ";")
				prezime=$(echo $redakPrve|cut -f 2 -d ";"|cut -f 1 -d ",")
				ime=$(echo $redakPrve|cut -f 2 -d ";"|cut -f 2 -d ",")
				Broj_bodova_1=$(echo $redakPrve|cut -f 3 -d ";")
				grupa=$(echo $redakPrve|cut -f 4 -d ";")
				echo "${jmbag} $prezime $ime ($grupa) ${Broj_bodova_1} ${Broj_bodova_2}";
			else
				echo "$JMBAG2 -- -- (--) -- $Broj_bodova_2";
			fi
	done < "$2"
	