proba="Ovo je proba"
echo $proba
lista_datoteka=$(ls *)
echo $lista_datoteka
proba3=$(for i in $(seq 1 3); do printf "%s. " "$proba"; done)
a=4; b=3; c=7
d=$(((a+4)*b%c))
broj_rijeci=$(cat *.txt | wc -w)
ls ~
cut -d ':' -f 1,6,7 /etc/passwd
ps | tr -s " " | cut -d " " -f 2,7,9