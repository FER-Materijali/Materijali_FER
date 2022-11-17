#2.zadatak
#a)
grep -i 'banana\|jabuka\|jagoda\|dinja\|lubenica' namirnice.txt

#b)
grep -iv 'banana\|jabuka\|jagoda\|dinja\|lubenica' namirnice.txt > ne-voce.txt

#c)
grep -rE '[A-Z]{3}[0-9]{6}' ~/Projekti/

#d)
find . -mtime +7 -mtime -14 -ls

#e)
for i in {1..15};do echo $i; done