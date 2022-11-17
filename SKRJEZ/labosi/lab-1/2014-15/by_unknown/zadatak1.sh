#1.Zadatak
#a), b)
proba="Ovo je proba" && echo $proba

#c)
lista_datoteka=*
echo $lista_datoteka

#d)
proba3="$proba. $proba. $proba. "

#e)
a=4 && b=3 && c=7
d=$((($a+4)*$b%$c))

#f)
broj_rijeci=$(cat *.txt | wc -w)

#g)
ls ~

#h)
cut -f 1,6,7 -d: /etc/passwd

#i)
ps -o uid,pid,comm -A