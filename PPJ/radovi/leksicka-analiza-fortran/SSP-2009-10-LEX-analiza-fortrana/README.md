1. Ja nisam nimalo, nikako, ni u kom slucaju odgovoran za posljedice korištenja ili nekorištenja bilo cega što sam u životu, smrti, ili negdje izmedu napravio, ucinio, izradio, uradio ili ne; u što spada i ovaj program.

2. Program je raden za Linux. Zato što je tak lakše. Ako hocete to u Windowsima koristit, trebate to ponovo kompajlirat, a i start.c treba bit drugaciji (makar to vam ne treba). Ne znam kak, ne pitajte. :)

3. Nemam pojma jel ovo valja, kolko valja, kolko ne valja i sl. Kad dobijem bodove, promijenit cu opis (ako se sjetim) i napisat kolko sam bodova dobio.

4. MOLIM VAS, nemojte beskrupulozno prepisivat. Prepisujte pametno, s razumijevanjem. Ili nemojte, al se pobrinite da vas (nas) ne uhvate. ;)

5. Možda cete morat namjestit permissions da biste ovo mogli pokrenut. U Ubuntuu to je desni klik na file > properties > permissions > oznacit kvacicu kraj "allow executing file as a program".

6. Ak ste ovo skinuli a ne znate koristit flex, postupak ide ovak:
flex pravila.lex
gcc -o analizator lex.yy.c -lfl
./analizator < ulaz.txt

(to je ako ne koristite onu moju izmišljotinu s programom start).



Nadam se da sam vam barem malo pomogao!

Živili!