## Authors: hrckov
## Desc: /
## Date: 21.12.2010
## Location: University of Zagreb, Faculty of Electrical Engineering and Computing
## Version: 1.0.2


python izvor.py
python ent_kod.py 12.txt
python z_kod.py 23.txt

##stvaranje error vektora, prvi argument je 0 za kanal bez smetnji, !=0 za kanal sa smetnjama, 
##zakomentirati ga ili promjeniti izlaznu datoteku za koristenje vlastitog err vektora
python error_vec_create.py 1 34.txt err_vec.txt

python kanal.py 34.txt err_vec.txt
python z_dekod.py 45.txt
python ent_dekod.py 56.txt 
python odrediste.py 67.txt

##racunanje entropije i transinformacije
##odkomentirati za koristenje
##python entro_trans.py 12.txt 67.txt