#!/usr/bin/env sh

echo ---------- `date` --------------
./izvor.exe
./entropija.exe 12.txt
./ent_kod.exe 12.txt
./gen_err_vec.exe # Generira err_vec.txt. Prebrisat će postojeći.

echo Analiza rezultata sa zaštitnim kodiranjem ISKLJUČENIM:
echo "  `./kanal.exe 23.txt err_vec.txt`"
./ent_dekod.exe 45.txt
echo "  `./diff.exe 12.txt 67.txt`"
echo "  `./entropija.exe 67.txt`"
echo "  `./transinformacija.exe 12.txt 67.txt`"

echo Analiza rezultata sa zaštitnim kodiranjem UKLJUČENIM:
./z_kod.exe 23.txt
echo "  `./kanal.exe 34.txt err_vec.txt`"
./z_dekod.exe 45.txt
./ent_dekod.exe 56.txt
echo "  `./diff.exe 23.txt 56.txt`"
echo "  `./diff.exe 12.txt 67.txt`"
echo "  `./entropija.exe 67.txt`"
echo "  `./transinformacija.exe 12.txt 67.txt`"
