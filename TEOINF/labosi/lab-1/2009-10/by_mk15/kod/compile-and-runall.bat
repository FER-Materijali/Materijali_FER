#!/usr/bin/env sh

echo ---------- `date` --------------

if gcc -lm izvor.c -o izvor.exe; then ./izvor.exe; fi
if gcc -lm entropija.c -o entropija.exe; then ./entropija.exe 12.txt; fi
if gcc -lm ent_kod.c -o ent_kod.exe; then ./ent_kod.exe 12.txt; fi
if gcc gen_err_vec.c -o gen_err_vec.exe; then ./gen_err_vec.exe; fi

echo Analiza rezultata sa zaštitnim kodiranjem ISKLJUČENIM:
if gcc kanal.c -o kanal.exe; then echo "  `./kanal.exe 23.txt err_vec.txt`"; fi
if gcc -lm ent_dekod.c -o ent_dekod.exe; then ./ent_dekod.exe 45.txt; fi
if gcc diff.c -o diff.exe; then echo "  `./diff.exe 12.txt 67.txt`"; fi
echo "  `./entropija.exe 67.txt`"
if gcc -lm transinformacija.c -o transinformacija.exe; then
    echo "  `./transinformacija.exe 12.txt 67.txt`"
fi

echo Analiza rezultata sa zaštitnim kodiranjem UKLJUČENIM:
if gcc -lm z_kod.c -o z_kod.exe; then ./z_kod.exe 23.txt; fi
echo "  `./kanal.exe 34.txt err_vec.txt`"
if gcc -lm z_dekod.c -o z_dekod.exe; then ./z_dekod.exe 45.txt; fi
./ent_dekod.exe 56.txt
echo "  `./diff.exe 23.txt 56.txt`"
echo "  `./diff.exe 12.txt 67.txt`"
echo "  `./entropija.exe 67.txt`"
echo "  `./transinformacija.exe 12.txt 67.txt`"
