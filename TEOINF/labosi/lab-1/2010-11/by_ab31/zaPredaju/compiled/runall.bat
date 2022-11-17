python izvor.pyc
python ent_kod.pyc 12.txt
python z_kod.pyc 23.txt
##stvaranje error vektora, prvi argument je 0 za kanal bez smetnji, !=0 za kanal sa smetnjama, 
##zakomentirati ga ili promjeniti izlaznu datoteku za koristenje vlastitog err vektora
python error_vec_create.pyc 1 34.txt err_vec.txt

python kanal.pyc 34.txt err_vec.txt
python z_dekod.pyc 45.txt
python ent_dekod.pyc 56.txt 
python odrediste.pyc 67.txt

##racunanje entropije i transinformacije
##odkomentirati za koristenje
##python entro_trans.pyc 12.txt 67.txt