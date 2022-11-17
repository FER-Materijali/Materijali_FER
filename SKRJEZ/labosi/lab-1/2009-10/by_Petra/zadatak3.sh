#3.zadatak
for file in $(ls *-02-*.txt);
	do
		echo "datum: $(echo $file |cut -d "." -f 2| cut -d "-" -f 3)-$(echo $file |cut -d "." -f 2| cut -d "-" -f 2)-$(echo $file |cut -d "." -f 2| cut -d "-" -f 1)";
		echo "-------------------------------------------------------------------------------------------------------":
		cat $file | cut -f 2 -d \"| sort | uniq -c | sort -n -r | sed -r 's/([0-9]+)(.*)/\1 : \2/'
	done