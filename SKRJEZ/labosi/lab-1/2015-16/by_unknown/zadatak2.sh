grep -i -E "banana|jabuka|jagoda|dinja|lubenica" namirnice.txt
grep -v -i -E "banana|jabuka|jagoda|dinja|lubenica" namirnice.txt > ne-voce.txt
grep -r -E "[A-Z]{3}[0-9]{6}" ~/projekti/
find -mtime +7 -and -mtime -14 -ls
for i in $(seq 15); do echo $i; done