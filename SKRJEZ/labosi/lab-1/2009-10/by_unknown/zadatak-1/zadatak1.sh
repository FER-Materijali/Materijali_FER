proba="Ovo je proba"
echo $proba
echo

lista_datoteka=`ls *.*`
echo $lista_datoteka
echo 

proba3=""
for i in 1 2 3;
 do proba3=$proba". "$proba3;
done
echo $proba3
echo

a=4
b=3
c=7
d=$((($a+4)*$b%$c))
echo $d
echo

broj_rijeci=$(wc -w *.txt)
echo $broj_rijeci
echo

ls ~
echo

cut -d: -f 1,6,7 /etc/passwd
echo

ps -e -F | sed -r 's/[ ]{2,}/ /g' | cut -d " " -f 1,2,11-

