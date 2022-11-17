if [ "$#" -ne 2 ] 
then

        echo "NEISPRAVAN BROJ PARAMETARA"
        echo "Ispravno koristenje skripte:"
        echo "sh zadatak6.sh /PATH_DO_PRVOG_DIREKTORIJA/ /PATH_DO_DRUGOG_DIREKTORIJA/"
	echo "DIREKTORIJE OBAVEZNO ZAVRŠITI SA /"

        exit

fi


for i in $(ls $1)
do
	if [ ! -f "$1$i" ]
	then
		continue
	fi

	mtime1=$(stat -c %Y "$1$i" 2>&2)

	if [ -f "$2$i" ]
	then
		mtime2=$(stat -c %Y "$2$i" 2>&2)
	else
		mtime2=1
	fi

	if [ "$mtime1" -gt "$mtime2" ] 
	then
		cp -p "$1$i" "$2$i" 2>&2

		if [ $? -eq 0 ] 
		then
			echo "$1$i -> $2"
		fi		


	fi
done


for i in $(ls $2)
do
        if [ ! -f "$2$i" ]
        then
                continue
        fi

        mtime1=$(stat -c %Y "$2$i" 2>&2)

        if [ -f "$1$i" ]
        then
                mtime2=$(stat -c %Y "$1$i" 2>&2)
        else
                mtime2=1
        fi

        if [ "$mtime1" -gt "$mtime2" ] 
        then
                cp -p "$2$i" "$1$i" 2>&2

                if [ $? -eq 0 ] 
                then
                        echo "$2$i -> $1"
                fi


        fi
done


