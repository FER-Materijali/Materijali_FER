#!/bin/bash

#a)
grep -i 'banana\|jabuka\|jagoda\|dinja\|lubenica' ./namirnice.txt

#b)
grep -iv 'banana\|jabuka\|jagoda\|dinja\|lubenica' ./namirnice.txt  > ne-voce.txt

#c)
grep -rE '[A-Z]{3}[0-9]{6}' ~/projekti/

#d)
find . -mtime +7 -mtime -14 -ls

#e)
#for i in {1..15};do echo $i;done
for i in $(seq 15);do echo $i;done
