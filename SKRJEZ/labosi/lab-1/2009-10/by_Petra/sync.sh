#6.zadatak
if [ "$#" -ne 2 ] 
	then
		echo "Krivi broj parametara!" >2
		exit
	fi
for file in $(ls ./"$1");
do
	if [ -n "$(find ./"$2"  -name $file)" ]
		then
			if [ "$(stat -c %Y ./$1/$file)" -gt "$(stat -c %Y ./$2/$file)" ] 
			then 
				cp -p "./$1/$file" "./$2/$file";
				echo "$1/$file -> $2";
			fi
		else
			cp -p "./$1/$file" "./$2/$file";
			echo "$1/$file -> $2";
		fi
done
for file in $(ls ./"$2");
do
	if [ -n "$(find ./"$1"  -name $file)" ]
		then
			if [ "$(stat -c %Y ./$2/$file)" -gt "$(stat -c %Y ./$1/$file)" ] 
			then 
				cp -p "./$2/$file" "./$1/$file";
				echo "$2/$file -> $1";
			fi
		else
			cp -p "./$2/$file" "./$1/$file";
			echo "$2/$file -> $1";
		fi
done