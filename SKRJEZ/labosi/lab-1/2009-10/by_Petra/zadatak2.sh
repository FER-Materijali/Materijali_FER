#2.1
grep -E "banana|jabuka|jagoda|dinja|lubenica" namirnice.txt
#2.2
grep -v -E "banana|jabuka|jagoda|dinja|lubenica" namirnice.txt >ne_voce.txt
#2.3
grep -E "\<[A-Z]{3}[0-9]{6}\>" $(find ~/projekti/)
#2.4
find -type f -mtime +7 -mtime -14 -ls
#2.5
for i in `seq 1 15`; do echo $i; done
#2.6
i=1;
for file in $(ls *.*);
	do
		echo "
		";
		echo "$i: $file... $(wc -l <$file)";
		echo "-------------------------------";
		echo "$(head -n 3 <$file)";
		i=$(($i+1));
	done