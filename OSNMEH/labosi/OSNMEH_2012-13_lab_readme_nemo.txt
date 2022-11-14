KRATKA UPUTSTVA ZA KORISTENJE DATOTEKA ZA LABOSE IZ OSNOVA MEHATRONIKE
(AKA kako lagano napisati izvjestaje bez da puno razmisljate)

Postovani kolega, 
U ovom folderu su spremljene sve datoteke za napisati dobar izvjestaj iz labosa na predmetu Osnove Mehatronike po FER2 programu (osim ako labose nisu promijenili, sto je malo vjerojatno).


Sadrzane datoteke su:
- README file
- LAB1..5 <- Folderi s izvjestajima u PDF formatu i arhivama za LaTeX
- OSNMECH_MATLAB <- Folder s MATLAB datotekama svih labosa
- Izvjestaji_drugih_kolega <- dovoljno rijecito


*** Folderi LAB1..5 
unutar sebe sadrze arhive u .zip formatu u kojima se nalaze sve datoteke potrebne za generiranje pdf-a uz pomoc LaTeX compilera.
Svaka .zip arhiva sadrzi izvorni tekst i *sve* SLIKE u prikladnim subfolderima. 

Postupak in short:
1. Odaberi labos koji zelis (1..5)
2. Extract .zip negdje
3. Koristi filove na jedan od ispod opisanih nacina
4. ...
5. Profit ;)

Vise informacija o LaTeXu ispod.


** NE Zelim znati sto je taj LaTeX
Ukoliko NE zelite otkriti sto je LaTeX (iz nekog meni nepoznatog razloga) i zelite se samo dokopati teksta izvjestaja sto prije (koji vam se ne zeli lijepo kopirati sa Copy i Paste iz PDF-a izvjestaja), istom mozete pristupiti na sljedeci nacin.
->Otvorite Folder s vjezbom koja vas interesira (LAB3 recimo), ekstrahirajte arhivu u .zip formatu i potrazite main.tex, u istom vam se nalazi sav kod iz kojeg se stvara pdf i medju kodom mozete naci i cisti tekst koji se lagano kopira, samo skrolajte... i skrolajte ;)
>>>> NEMOJTE KORISTITI NOTEPAD ZA OTVARANJE TEKSTUALNIH DATOTEKA JER JE SMECE, koristite neki normalan text editor, recimo Notepad++ [ili Vim :D] <<<<



*** MATLAB
Datoteke s MATLAB kodom sadrze sve sto vam treba za generiranje slika i grafova za izvjestaj. Iskreno, ne morate apsolutno nista na labosu napraviti i ako ih nisu promjenili imate sve podatke spremljene vec.
Svakako preporucam da skoknete na labose jer su ustvari poprilicno cool i bili bi izvrsni da se ne zuri vremenski s njima. Imate sto nauciti iz njih!

Grafovi - plotanje (za jako zabrinute)
Ukoliko ste zabrinuti da mozete bodove izgubiti ako cijela generacija ima identicne grafove (zamisli ti to), onda ce vam puno pomoci subfoler Slike u folderima s MATLAB kodom labosa ( u 2. i 3. vjezbi su mi se negdje izgubili ti subfolderi, my bad, nesto posla za iduce generacije, odnosno vas :D ).
Pored toga sto imate slike u .png formatu za dodavanje u izvjestaje, za SVAKI graf imate i odgovarajucu .fig datoteku.
Ista se iznimno jednostavno otvara u MATLAB-u te imate apsolutnu slobodu mjenjanja izgleda grafova. Mjenjati ih mozete u figure editoru MATLABa ili direktno pomocu .m skripti, za ideju kako koristiti skripte pogledajte dijelove iz skripte gpretty.m.

Sve GOTOVE slike koristene u izvjestajima vam se nalaze vec u .zip arhivama za LaTeX, mozete ih od tamo izvuci ako ih ne zelite mjenjati.



*** LaTeX

Za koristenje izvjestaja i pridruzenih datoteka se preporuca nakekav editor + LaTeX compiler jer su isti pisani u njemu.

Za one koji se do sada nisu susreli s LaTeX-om, par savjeta:
- cita se la-teh
- to je iznimno koristan alat za ikoga tko treba napisati vise od dvije formule u dokumentu
- potrosite malo vremena i naucite ga, biti cete si zahvalni na ustedi vremena i kvaliteti buducih radova (recimo zavrsnog), buduci inzenjeri ste, treba to biti na razini ;)


* Uputstva za one koji se prvi put susrecu s LaTeX-om, odnosno kako ublaziti learning curve
Preporucam da koristite nekakav online WYSIWYG editor za latex. Jedan relativno dobar mozete naci na ovoj adresi:
https://www.writelatex.com/

Baratate s datotekama tako da otvorite novi dokument na stranici te kliknete redom Project-> Upload files.
Kod odabira datoteka za upload pogledate u folder odgovarajuce vjezbe (recimo LAB4) i ekstrahirate datoteku iz .zip arhive i odaberete fileove UNUTAR datoteke kao ono sto zelite uploadati na stranicu.
Nakon toga, ako je sve u redu, osvjezit ce vam se prikaz na desnoj strani programa s prikazom kako ce izgledati vas izvjestaj u PDF-u.
Editirate izvjestaje na lijevoj strani.
Nesto vam nije jasno: http://en.wikibooks.org/wiki/LaTeX
Sretno i ugodno TeXanje!

* Za one koji vec koriste LaTeX
Ne moram nista posebno napominjati, gurnite datoteke negdje i compile, editirajte s omiljenim editorom. Enjoy!


Zahvale:
- Asistentu Sandoru Ilesu za zanimljive labose. Vjerojatno najpristupacniji i najugodniji asistent na cijelom fakultetu.
- Kolegi Tywinu (AKA The King) i Kolegi Brumbi za materijale prijasnjih godina
- Donaldu Knuthu na Tex-u 


Cheerio,
nemo