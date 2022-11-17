#4.zadatak
if [ "$#" -ne 2 ] 
	then
		echo "Krivi broj parametara!"
		exit
	fi

for file in $(ls ./"$1");
do
	ime=$(stat -c %y "./$1/$file" |cut -f 1,2 -d "-");
	mkdir -p ./"$2"/"$ime";
	mv "./$1/$file" ./"$2"/"$ime"/"$file";
done
