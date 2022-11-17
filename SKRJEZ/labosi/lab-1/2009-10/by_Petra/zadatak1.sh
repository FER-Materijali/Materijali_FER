#1.1
proba="Ovo je proba"
#1.2
echo $proba
#1.3
lista_datoteka="$ls *.*"
echo $lista_datoteka
#1.4
proba3="$proba. $proba. $proba. "
#1.5
a=4;b=3;c=7
d=$((($a+4)*$b%$c))
#1.6
broj_rijeci=$(cat *.txt | wc -w)
#1.7
ls ~
#1.8
cut -d ':' -f 1,6,7 /etc/passwd
#1.9 
ps|sed -r 's/[ ]+/ /g'|cut -d ' ' -f 7,2,9
 