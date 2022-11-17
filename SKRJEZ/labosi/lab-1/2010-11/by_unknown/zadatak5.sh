if [ "$#" -ne 2 ] 
then

	echo "NEISPRAVAN BROJ PARAMETARA"
	echo "Ispravno koristenje skripte:"
	echo "sh zadatak5.sh /PATH_DO_PRVE_DATOTEKE /PATH_DO_DRUGE_DATOTEKE"
	
	exit

fi


while read JMBAG Broj_bodova_2
do

	prva=$(grep $JMBAG $1)

	if [ $? -eq 0 ] 
	then
		
		prezime=$(echo $prva | cut -d ' ' -f 2 | cut -d ',' -f 1 )
		ime=$(echo $prva | cut -d ' ' -f 3 | cut -d ';' -f 1 )
		grupa=$(echo $prva | cut -d ' ' -f 5 )
		br_1=$(echo $prva | cut -d ' ' -f 4 | cut -d ';' -f 1 )


	else

		prezime='--'
		ime='--'
		grupa='--'
		br_1='--'

	fi



	echo "$JMBAG\t$prezime $ime ($grupa)\t$br_1\t$Broj_bodova_2"


done < "$2"
