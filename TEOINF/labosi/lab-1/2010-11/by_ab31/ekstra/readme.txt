Simulator kanala
Dijelovi:
1)Izvor pseudoslucajnih znakova
2)Huffmanov koder i dekoder
3)Hammingov koder i dekoder
4)Kanal sa i bez smetnji
5)Odrediste

Upotreba programa
Pri pokretanju programa sve vrijednosti su postavljene na vrijednosti definirane zadatkom, osim broja znakova za generirati(radi preglednosti rezultata).
Simulator pokrecete klikom na gump 'Pokreni', brisete trenutno ispisane vrijednosti gumbom 'Reset', gumb 'Pomoc' otvara prozor pomoci, a 'Izlaz' gasi program.
Ukoliko zelite kanal sa smetnjama oznacite kucicu na za to predvidjenom mjestu.
Simulatoru mozete dati i vlastite vrijednosti vjerojatnosti izvora/kanala, promijeniti tip hammingovog kodera i broj znakova za generiranje.
Vjerojatnosti izvora se zapisuju na sljedeci nacin: svaki par znak-vjerojatnost mora biti u zasebnom redu, a dijelovi para su odvojeni zarezom.
Program prima vjerojatnost niza do druge decimale(0.xy).
Vjerojatnost kanala se navodi kao razlomak u kojem su brojnik i nazivnik odvojeni razmakom(1 20 je 1/20)
Hammingov kod [n,k,3] se navodi kao n k 3. 
Program ispisuje vrijednosti nakon svakog dijela sustava(izvor, huffman koder, hamming koder, kanal, hamming dekoder, huffman dekoder), generirajucu matricu hammingovog koda G, matricu provjere pariteta hammingovog koda H, huffmanov generirani kod, broj pojedinih znakova na ulazu i izlazu iz sustava, broj promjenjenih bita u kanalu, te da li je ulazni niz jednak izlaznom.
