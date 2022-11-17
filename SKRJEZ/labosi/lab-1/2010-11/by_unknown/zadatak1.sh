proba="Ovo je proba"
echo $proba

lista_datoteka=`echo *`
echo $lista_datoteka 

for i in 1 2 3
do
	proba3=$proba3$proba'. '
done
echo $proba3

a=4 b=3 c=7
d=$((($a+4)*$b%$c))
echo $d

broj_rijeci=0
for i in *\.txt
do
	broj_rijeci=$(($(wc $i -w | cut -d ' ' -f 1)+$broj_rijeci))
done
echo $broj_rijeci

ls ~

grep ^$USER /etc/passwd | cut -d ':' -f1,6,7

ps aux | tr -s '[\ ]' '#' | cut -d '#' -f1,2,11 | tr -s '#' ' '

