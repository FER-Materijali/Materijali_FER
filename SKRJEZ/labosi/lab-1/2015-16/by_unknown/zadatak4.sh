if [ $# == 2 ]; then
	if [ ! -d $2 ]; then
		mkdir $2
	fi

	for slika in $(ls $1); do
		folder_name="$2/$(stat -c %y "$1/$slika" | cut -c 1-7)"
		if [ ! -d $folder_name ]; then
			mkdir $folder_name	
		fi
		mv "$1/$slika" $folder_name
	done
fi

