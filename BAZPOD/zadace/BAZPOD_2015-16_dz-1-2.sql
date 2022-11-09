/*Za sve nastavnike s maksimalnim koeficijentom koji su predavali barem jednoj grupi ispisati šifru, ime, prezime i broj grupa kojima su predavali. Zapise poredati uzlazno po prezimenu nastavnika.
*/
SELECT nastavnik.sifNastavnik, imeNastavnik, prezimeNastavnik, COUNT(oznGrupa) AS brojGrupa
	FROM nastavnik JOIN predmetGrupa
	ON nastavnik.sifNastavnik = predmetGrupa.sifNastavnik
	WHERE koef >= (SELECT MAX(koef)
					FROM nastavnik)
	GROUP BY nastavnik.sifNastavnik, imeNastavnik, prezimeNastavnik
	ORDER BY prezimeNastavnik;
	
	
/*Za studente koji među preostalim ikada upisanim studentima nemaju imenjaka, a u nekoj su akademskoj godini pali(dobili ocjenu 1) iz više od dva predmeta ispisati jmbag, ime, prezime i akademsku godinu u kojoj se to dogodilo.
*/
SELECT student.jmbag, imeStudent, prezimeStudent, akGodina
	FROM upisanPredmet JOIN student
	ON upisanPredmet.jmbag = student.jmbag
	WHERE imeStudent IN (SELECT imeStudent
						FROM student
						GROUP BY imeStudent
						HAVING COUNT(imeStudent) = 1)
	AND ocjena = 1
	GROUP BY student.jmbag, imeStudent, prezimeStudent, akGodina
	HAVING SUM(ocjena) > 2;
	
	
/*Ispišite nazive, šifre, te ukupan broj sati predavanja tjedno za predmete koji se tjedno predaju ukupno 5,6 ili 7 sati. Prilikom ispisa atribut "sifpredmet" preimenujte u "sifra" a atribut "ukbrsatitjedno" preimenujte u "sati".
*/
SELECT nazPredmet, sifPredmet AS sifra, ukbrsatitjedno AS sati
	FROM predmet
	WHERE ukbrsatitjedno IN(5,6,7);
	
	
/*Za predmet Telekomunikacijske mreže ispšite naziv predmeta, akademsku godinu, i prosječnu ocenu svih studenata na tom predmetu u svakoj akademskoj godini. U obzir uzmite samo studente koji su položili predmet sa prolaznom ocjenom (dobili su 2,3,4 ili 5).
*/
SELECT nazPredmet, akGodina, AVG(ocjena)
	FROM predmet JOIN upisanPredmet
	ON predmet.sifPredmet = upisanPredmet.sifPredmet
	WHERE nazPredmet = 'Telekomunikacijske mreže'
	AND ocjena > 1
	GROUP BY nazPredmet, akGodina;
	
	
/*Pronaći dvorane u kojima se može održavati nastava nastavnim grupama čija je oznaka "A-A", s obzirom na kapacitete grupa i dvorana. Ispisati akademsku godinu nastavne grupe, kapacitet grupe, te oznaku dvorane u kojoj se može održati nastava.
*/
SELECT grupa.kapacitet, akGodina, oznDvorana
	FROM dvorana, grupa
	WHERE grupa.kapacitet <= dvorana.kapacitet
	AND oznGrupa = 'A-A';
	
	
/*Ispišite prezimena studenata ženskog spola ("Ž") koji ili stanuju u mjestu s poštanskim brojem 10000 ili nije poznato gdje stanuju.
*/
SELECT prezimeStudent
	FROM student
	WHERE spol = 'Ž'
	AND pbrStanStudent = 10000
	OR pbrStanStudent IS NULL;
	
	
/*Za relaciju nastavnik kreirati najmanji moući broj indeksa koji će omogućiti efikasno obavljanje svij navedenih upita:
SELECT * FROM nastavnik WHERE imeNastavnik = 'Ivana' AND prezimeNastavnik = 'Martinec';
SELECT * FROM nastavnik WHERE datumZaposlenOd >'1.1.2006';
SELECT * FROM nastavnik ORDER BY prezimeNastavnik DESC, imeNastavnik;
SELECT * FROM nastavnik ORDER BY preztimeNastavnik;
SELECT * FROM nastavnik ORDER BY datumZaposlenDo, datumZaposlenOd;
*/
CREATE INDEX in1 ON nastavnik (prezimeNastavnik DESC, imeNastavnik);
CREATE INDEX in2 ON nastavnik (datumZaposlenDo, datumZaposlenOn);
CREATE INDEX in3 ON nastavnik (datumZaposlenOd);


/*Ispišite oznaku dvorane i kapacitet zua dvorane koje imaju kapacitet veći od 50 ali manji od 100 (granične vrijednosti nisu uključene).
*/
SELECT *
	FROM dvorana
	WHERE kapacitet BETWEEN 51 AND 99;
	
	
/*Za sve organizacijske jedinice cija neposredna nadredjena organizacijska jedinica ima sifru 36 ispisati naziv, te dodatno ime i prezime svih nastavnika koji su zaposleni u tim organizacijskim jedinicama, a stanuju u mjestu ciji naziv pocinje slovom "Z". Ukoliko u organizacijskoj jedinici nema nastavnika koji zadovoljavaju dani uvjet, za ime i prezime nastavnika ispisatu NULL vrijednost.
*/
SELECT nazOrgJed, imeNastavnik, prezimeNastavnik
	FROM nastavnik JOIN mjesto
	ON mjesto.pbr = nastavnik.pbrstannastavnik AND nazmjesto like'Z%'
	RIGHT JOIN orgjed
	ON nastavnik.siforgjed = orgjed.siforgjed
	WHERE sifNadORgJed = 36;
	
	
/*Potrebno je dodati novu organizacijsku jedinicu "Republika Hrvatska" sa sifrom 1 (nema nadredjenu organizacijsku jedinicu). Zatim postaviti Republiku Hrvatsku kao nadredjenu svim sveucilistima(to su one organizacijske jedinice koje sadrze niz "sveuciliste" u nazivu bez obzira na velika i mala slova).
*/
INSERT INTO orgjed
	VALUES (1, "Republika Hrvatska", null);
UPDATE orgJed
	SET sifNadOrgJed = 1
	WHERE lower(nazorgJed) LIKE '%sveučilište%';
	
	
/*Svim grupama iz akademske godine 2011/2012 ciji kapacitet odgovata minimalnom kapacitetu svih grupa na oznaku dodati sufiks "-mala"(npr. grupa "D-H1" ce tako postati "D-H1-mala"). Voditi racuna o mogucm postojanju praznih mjesta u originalnim nazivima grupa.
*/
UPDATE grupa
	SET oznGrupa = trim(oznGrupa) || '-mala'
	WHERE akGodina = 2011
	AND kapacitet = (SELECT min(kapacitet)
					FROM grupa);
					
					
/*Ispisite imena i prezimena studenata koji su reodjeni u Zagrebu(postanski broj Zagreba je 10000).
*/
SELECT imeStudent, prezimeStudent
	FROM student
	WHERE pbrRodStudent = 10000;
	
	
/*Potrebno je organizacijskoj jedinici "Fakultet elektrotehnike i računarstva" dodati novu podredjenu organizacijsku jedinicu "Zavod za strane jezike" sa sifrom 100.
Zatim svim organizacijskim jedinicama kojima nazic pocinje s "Grupa" promijeniti nazic tako da umjesto s "rupa" pocinje s "Katedra" (npr. "Grupa racunarskih znanosti" je potrebno promijeniti u "Katedra racunarskih znanosti", itd).
*/
INSERT INTO orgJed (
	sifOrgJed,
	nazOrgJed,
	sifNadOrgJed
)
	VALUES(100,'Zavod za strane jezike', (SELECT sifOrgJed
											FROM orgJed
											WHERE nazOrgJed LIKE 'Fakultet elektrotehnike i računarstva'));
UPDATE orgJed
	SET nazOrgJed = REPLACE(nazOrgJed, 'Grupa', 'Katedra')
	WHERE nazOrgJed LIKE 'Grupa%';
	
	
/*Svim nastavnicima ciji je koeficijent jednak minimalnom koeficijentu postaviti koeficijent na maksimalni koeficijent.
*/
UPDATE nastavnik
	SET koef = (SELECT MAX(koefiicjent)
				FROM nastavnik)
	WHERE koef = (SELECT MIN(koeficijent)
				FROM nastavnik);
				
				
/*Ispisati jmbag, ime i prezime studenta, te dodatno prosjecnu vrijednost ECTS bodova(nazovite stupac prosjek_ects) predmeta koje je student polozio. Ipisati samo one studente koji su polozili vise od 15 predmeta.
*/
SELECT student.jmbag, imeStudent, prezimeStudent, AVG(ectsBod) AS prosjek_ects
	FROM student JOIN upisanPredmet
	ON student.jmbag = upisanPredmet.jmbag
	JOIN predmet
	ON upisanPredmet.sifPredmet = predmet.sifPredmet
	WHERE ocjena > 1
	GROUP BY student.jmbag, imeStudent, prezimeStudent
	HAVING COUNT(predmet.sifPredmet) > 15;
	
	
/*Za zadanu relacijsku hemu STUDSTIP={ime, prezime, jmbg, prosjekOcjena} napisati naredbu kojim ce se napraviti relacije studStip(STUDSTIP). Tipovi podataka neka budu sljedeci:
ime, prezime - NCHAR(25)
jmbg - CHAR(13)
prosjekOcjena - DECIMAL(5, 2)
U relaciju studStip upisati student koji imaju prosjeke ocjena veci ili jednak 3 a strogo manji dod 5 (U prosjke ocjena ulaze samo pozitivne ocjene).
*/
CREATE TABLE STUDSTIP(
	ime NCHAR(25),
	prezime NCHAR(25),
	jmbag CHAR(13),
	prosjekOcjena DECIMAL(5,2)
);
INSERT INTO STUDSTIP
	SELECT imeStudent, prezimeStudent, student.jmbg, AVG(ocjena)
		FROM student JOIN upisanPredmet
		ON student.jmbg = upisanPredmet.jmbg
		WHERE ocjena > 1
		GROUP BY imeStudent, prezimeStudent, student.jmbg
		HAVING (AVG(ocjena) > 3 AND AVG(ocjena) < 5);
		
		
/*Ispisati sifru i naziv, broj ECTS bodova i ukupan broj sati predavanja tjedno za sve predmete koji imaju neparan broj ECTS bodova i ukupan broj sati tjedno manji od 5.
Dodatno, za one predmete koji su se predavali akadremske godine 2011/2012 ispisati oznake i kapacitete grupa kojima su se ti predmeti predavali. Ukoliko se predmet nije predavao akademske kogidne 2011/2012 za oznaku i kapacitet grupe ispisati NULL vrijednost.
*/
SELECT DISTINCT predmet.sifPredmet, predmet.nazPredmet,ectsbod ,predmet.ukbrsatitjedno, grupa.ozngrupa,grupa.kapacitet
	FROM predmet LEFT JOIN predmetgrupa
		ON predmet.sifPredmet = predmetgrupa.sifPredmet AND predmetgrupa.akgodina = 2011
	LEFT JOIN grupa
		ON grupa.ozngrupa = predmetgrupa.ozngrupa AND grupa.akgodina = 2011
	WHERE (ukbrsatitjedno<5) AND MOD(ectsbod,2) = 1;
	
	
/*Za svaku A-dvoranu ciji je kapacitet manji ili jednak kapacitetu najmanje D-dvorane (tj D-dvorane s najmanjim kapacitetom) ispisati oznaku dvorane, kapacitet i broj razlicitih predmeta iz kojih se u toj dvorani odvija nastavna u akademskoj godini 2011/2012. (ukljuciti u ispis i dvorane u kojima se te godine nastava uopce ne drzi). Zapise poredati silazno po broju predmeta, a one s isim brojem predmeta prema oznaci dvorane uzlazno.
*/
SELECT dvorana.oznDvorana, kapacitet, COUNT( DISTINCT sifPredmet) AS brojPredmeta
	FROM predmetGrupa RIGHT JOIN dvorana
	ON predmetGrupa.oznDvorana = dvorana.oznDvorana AND akGodina = 2011
	WHERE dvorana.oznDvorana LIKE 'A%'
	AND dvorana.kapacitet <= (SELECT MIN(kapacitet)
							FROM dvorana
							WHERE oznDvorana LIKE 'D%')
	GROUP BY dvorana.oznDvorana, kapacitet
	ORDER BY brojPredmeta DESC, oznDvorana ASC;
	
	
/*Ispisati ime i prezime studenata, te mjesto rodjenja za sve studente rodjene izmedju 1980 i 1985 godine.
Mjesto rodjenja ipisati u sljedecem obliku:
Prva tri slova naziva mjesta velikim slovima + postanski broj(npr ZAG10000, SPL21000, DUB20000).
*/
SELECT imeStudent, prezimeStudent, UPPER(SUBSTRING(nazMjesto FROM 1 FOR 3) || pbr) AS string
	FROM student JOIN mjesto
	ON student.pbrRodStudent = mjesto.pbr
	WHERE YEAR(datumRod) BETWEEN 1980 AND 1985;
	
	
/*Napisati upit koji ce dohvatiti imena, prezimena i godine rodjenja svih studenada ciji rodjendan je u intervalu [15.travanja - 10.svibnja]. Atribute nazvati ime, prezime i godrod.
*/
SELECT imeStudent AS ime, prezimeStudent AS prezime, YEAR(datumRod) AS godrod
	FROM student
	WHERE (MONTH(datumRod) = 4 AND DAY(datumRod) >= 15)
	OR (MONTH(datumRod) <= 5 AND DAY(datumRod) <= 10);
	
	
/*Za parove nastavnika koji su jos uvijek u radnom odnosu, a imaju jednak koeficijent i zaposleni su u istoj organizacijskoj jedinici ispisati inicijal imena i prezime odojene tockom i iznos koeficijenta.
*/
SELECT SUBSTRING(nast1.imeNastavnik FROM 1 FOR 1) || '.' || TRIM(nast1.prezimeNastavnik) AS nastavnik1, nast1.koef AS koef1, 
	   SUBSTRING(nast2.imeNastavnik FROM 1 FOR 1) || '.' || TRIM(nast2.prezimeNastavnik) AS nastavnik2, nast2.koef AS koef2
	FROM nastavnik AS nast1 JOIN nastavnik AS nast2
	ON nast1.koef = nast2.koef AND nast1.sifOrgJed = nast2.sifOrgJed AND nast1.sifNastavnik <> nast2.sifNastavnik
	WHERE nast1.datumZaposlenDo IS NULL
	AND nast2.datumZaposlenDo IS NULL;
	
	
/*Ispisati oznaku i kapacitet svih dvorana kojima oznaka pocinje slovom "A". Za one dvorane u kojima se izvodila nastava za grupe kojima oznaka grupe pocinje slovom C, ispisati uz podatke o dvorani i akademsku godinu kada se ta nastava odvijala, u suprotnom ispisati NULL vrijednost. Dodatno, ispisati i naziv predmeta iz kojeg se odvijala takva nastava, ukoliko je predmet nosio 5 ECTS bodova, inace ispisati NULL vrijednost. Iz ispisa izbaciti duplikate.
*/
SELECT DISTINCT dvorana.oznDvorana, kapacitet, akGodina, nazpredmet
	FROM dvorana LEFT JOIN predmetGrupa
	ON dvorana.oznDvorana = predmetGrupa.oznDvorana AND oznGrupa LIKE 'C%'
	LEFT JOIN predmet
	ON predmetGrupa.sifpredmet = predmet.sifPredmet AND ectsBod = 5
	WHERE dvorana.oznDvorana LIKE 'A%';
	
	
/*Ispisati jmbag, ime, prezime, sifru predmeta, ocjenu i ak.godinu za svakog studenta i predmet za koje vrijedi da je student akademske godine 2011/2012 iz tog predmeta dobio pozitivnu ocjenu takvu da niti jedan drugi student nije uspio dobiti vecu ocjenu iz tog predmeta te akademske godine. Ispiati samo one studente ciji je ukuoni prosjek ocjena veci od 4.9. (U prosjek ulaze samo pozitivne ocjene).
*/
SELECT student.jmbag, imeStudent, prezimeStudent, sifpredmet, upisan.ocjena, akGodina -- ne radi
	FROM student JOIN upisanPredmet AS upisan
	ON student.jmbag = upisan.jmbag
	WHERE akGodina = 2012
	AND upisan.ocjena > 1
	AND ocjena > (SELECT MAX(ocjena)
				FROM upisanPredmet AS upisan2
				WHERE upisan.jmbag <> upisan2.jmbag
				AND upisan2.sifPredmet = upisan.sifPredmet
				AND upisan2.akGodina = upisan.akGodina)
	GROUP BY student.jmbag, imeStudent, prezimeStudent,sifpredmet, upisan.ocjena, akGodina
	HAVING AVG(upisan.ocjena) > 4.9;

SELECT student.jmbag, imeStudent, prezimeStudent, sifpredmet, ocjena, akGodina
	FROM student JOIN upisanPredmet
	ON student.jmbag = upisanPredmet.jmbag
	WHERE akGodina = 2012
	AND (SELECT AVG(ocjena)
			FROM upisanPredmet AS up
			WHERE up.jmbag = upisanPredmet.jmbag
			AND up.ocjena > 1) > 4.9
	AND upisanPredmet.ocjena = (SELECT MAX(ocjena)
							FROM upisanPredmet AS up2
							WHERE up2.sifPredmet = upisanPredmet.sifPredmet
							AND up2.akGodina = 2012);
							
							
/*Za svaki predmet ispisati naziv predmeta, ukupan broj pozitivno ocijenjenih upisa predmeta te ukupan broj neocijenjenih upisa tog predmeta.
*/
SELECT nazPredmet,
	(SELECT count(jmbag)
		FROM predmet AS pred LEFT JOIN upisanPredmet
		ON pred.sifPredmet = upisanPredmet.sifPredmet
		WHERE ocjena BETWEEN 2 AND 5
		AND pred.sifPredmet = predmet.sifPredmet) AS pozitivnoOcijenjenih,
	(SELECT count(jmbag)
		FROM predmet AS pred LEFT JOIN upisanPredmet
		ON pred.sifPredmet = upisanPredmet.sifPredmet
		WHERE ocjena IS NULL
		AND pred.sifPredmet = predmet.sifPredmet) AS neocijenjeni
	FROM predmet;
	
	
/*Primarni kljuc u relaciji predmetGrupa je skup atributa: {sifPredmet, akGodina, oznGrupa}. Jednom SQL naredbom osigurajte entitetski ntegritet kljuca u toj relaciji.
Osigurati entitetski integritet i integritet kljuca u relaciji dvorana.
Osigurati referencijski integritet medju relacijama predmetGrupa i dvorana.
Koristiti sintaksu za naknadnu izmjenu postojece tablice: ALTER TABLE ime_tablice ADD CONSTRAINT opis_ogranicenja CONSTRAINT ime_ogranicenja.
*/
ALTER TABLE predmetGrupa ADD CONSTRAINT PRIMARY KEY(sifPredmet, akGodina, oznGrupa)	CONSTRAINT Pk1;
	
ALTER TABLE dvorana	ADD CONSTRAINT PRIMARY KEY(oznDvorana) CONSTRAINT Pk2;
	
ALTER TABLE predmetGrupa ADD CONSTRAINT FOREIGN KEY(oznDvorana) REFERENCES dvorana(oznDvorana) CONSTRAINT Fk;
	
	
/*1.Napraviti virtualnu relaciju stanBr5 sa shemom relacije STANBR5 = pbrstan, broj5 koja ce omoguciti pregled broja studenata koji su polozili predmet s ocjenom 5 u 2013/2014 akademskoj godini po postanskom broj stanovanja
2.Napraviti virtualnu relaciju mjestoBr5 sa shemom relacije MJESTOBR5 = nazmjesto, broj5 koja ce po SVIM mjestima omoguciti pregled broja studenata koji su polozili predmet s ocjenom 5 u 2013/2014 akademskoj godini i koji stanuju u tom mjestu. Ukljuciti i studente cije mjesto stanovanja nije poznato.
Virtualnu relaciju mjestobr5 obavezno napraviti pomocu relacije stanBr5.
*/
CREATE VIEW stanBr5(pbrStan, broj5) AS
	SELECT pBrStanStudent, count(distinct student.jmbag)
		FROM student JOIN upisanPredmet
		ON upisanPredmet.jmbag = student.jmbag
		WHERE akGodina = 2013
		AND ocjena = 5
		GROUP BY pBrStanStudent;

CREATE VIEW mjestoBr5(nazMjesto, broj5) AS
	SELECT nazmjesto, broj5
		FROM mjesto JOIN stanBr5
		ON mjesto.pbr = stanBr5.pbrStan;
		
		
/*Za relaciju predmetgrupa kreirati najmanji moguci broj indeksa koji ce omoguciti efikasno obavljanje svih navedenih upita:
SELECT * FROM predmetgrupa WHERE sifpredmet = 1 AND akgodina = 2003;
SELECT * FROM predmetgrupa WHERE akgodina > 2000 AND akgodina < 2006 ORDER BY akgodina;
SELECT * FROM predmetgrupa WHERE sifnastavnik = 690 AND ozngrupa = 'D-A1';
SELECT * FROM predmetgrupa WHERE ozngrupa = 'D-A1' AND akgodina = 2003 AND sifpredmet > 20;
SELECT * FROM predmetgrupa ORDER BY akgodina DESC, sifpredmet;
SELECT * FROM predmetgrupa ORDER BY sifnastavnik;
SELECT * FROM predmetgrupa ORDER BY akgodina DESC, sifpredmet ASC, ozngrupa ASC;
*/
CREATE INDEX in1 ON predmetgrupa (sifnastavnik, ozngrupa);
CREATE INDEX in2 ON predmetgrupa (akgodina DESC, sifpredmet ASC, ozngrupa);


/*
SELECT * FROM nastavnik WHERE prezimeNastavnik = 'Martinec';
SELECT * FROM nastavnik WHERE datumZaposlenOd > '1.1.2006' and datumZaposlenDo < '1.1.2008';
SELECT * FROM nastavnik ORDER BY koef DESC;
SELECT * FROM nastavnik ORDER BY prezimeNastavnik, imeNastavnik;
SELECT * FROM nastavnik ORDER BY prezimeNastavnik DESC;
SELECT * FROM nastavnik ORDER BY datumZaposlenDo DESC, datumZaposlenOd ASC;
SELECT * FROM nastavnik ORDER BY koef DESC, prezimeNastavnik ASC, imeNastavnik ASC;
*/
CREATE INDEX in1 ON nastavnik (koef DESC, prezimeNastavnik, imeNastavnik);
CREATE INDEX in2 ON nastavnik (prezimeNastavnik, imeNastavnik);
CREATE INDEX in3 ON nastavnik (datumZaposlenDo DESC, datumZaposlenOd);


/*Osigurati entitetski integritet kljuca u relaciji mjesto.
Napomena: isti naziv mjesta se moze pojaviti vise puta.
Osigurati da se u relaciji nastavnik moze evidentirati samo mjesto stanovanja koje (ukoliko nije null) postoji u relaciji mjesto.
*/
ALTER TABLE mjesto ADD CONSTRAINT PRIMARY KEY (pbr);

ALTER TABLE nastavnik ADD CONSTRAINT FOREIGN KEY(pbrStanNastavnik) REFERENCES mjesto(pBr);
	
	
/*SELECT * FROM student WHERE datumRod > '01.01.1980' ORDER BY datumRod;
SELECT * FROM student WHERE prezimeStudent = 'Salopek' AND imeStudent = 'Andrej';
SELECT * FROM student WHERE prezimeStudent = 'Salopek';
SELECT * FROM student WHERE datumRod > '01.01.1980';
SELECT * FROM student ORDER BY prezimeStudent, imeStudent;
SELECT * FROM student ORDER BY datumRod, jmbag;
*/
CREATE INDEX in1 ON student (datumRod, jmbag);
CREATE INDEX in2 ON student (prezimeStudent, imeStudent);


/*Primarni ključ u relaciji predmetGrupa je skup atributa: {sifPredmet, akGodina, oznGrupa}.Jednom SQL naredbom
osigurajte entitetski integritet i integritet ključa u toj relaciji.
Primarni ključ u relaciji predmet je atribut: sifPredmet. Jednom SQL naredbom osigurajte entitetski integritet i
integritet ključa u toj relaciji.
Osigurati referencijski integritet među relacijama predmetGrupa i predmet.
*/
ALTER TABLE predmetGrupa ADD CONSTRAINT PRIMARY KEY (sifPredmet,akGodina,oznGrupa);

ALTER TABLE predmet ADD CONSTRAINT PRIMARY KEY(sifPredmet);

ALTER TABLE predmetGrupa ADD CONSTRAINT FOREIGN KEY(sifPredmet) REFERENCES predmet(sifPredmet);


/*Primarni ključ u relaciji upisanPredmet je skup atributa: {jmbag, sifPredmet, akGodina, oznGrupa}.Jednom SQL
naredbom osigurajte entitetski integritet i integritet ključa u toj relaciji.
Primarni ključ u relaciji predmetGrupa je skup atributa: {sifPredmet, akGodina, oznGrupa}. Jednom SQL naredbom
osigurajte entitetski integritet i integritet ključa u toj relaciji.
Osigurati referencijski integritet među relacijama upisanPredmet i predmetGrupa.
*/
ALTER TABLE upisanPredmet ADD CONSTRAINT PRIMARY KEY (jmbag, sifPredmet, akGodina, oznGrupa);

ALTER TABLE predmetGrupa ADD CONSTRAINT PRIMARY KEY (sifPredmet, akGodina, oznGrupa);

ALTER TABLE upisanPredmet ADD CONSTRAINT FOREIGN KEY (sifPredmet, akGodina, oznGrupa) REFERENCES predmetGrupa(sifPredmet, akGodina, oznGrupa);


/*Primarni ključ u relaciji predmetGrupa je skup atributa: {sifPredmet, akGodina, oznGrupa}.Jednom SQL naredbom
osigurajte entitetski integritet i integritet ključa u toj relaciji.
Osigurati entitetski integritet i integritet ključa u relaciji dvorana.
Osigurati referencijski integritet među relacijama predmetGrupa i dvorana
*/
ALTER TABLE predmetGrupa ADD CONSTRAINT PRIMARY KEY (sifPredmet, akGodina, oznGrupa);

ALTER TABLE dvorana ADD CONSTRAINT PRIMARY KEY (oznDvorana);

ALTER TABLE predmetGrupa ADD CONSTRAINT FOREIGN KEY (oznDvorana) REFERENCES dvorana(oznDvorana);


/*Za relaciju upisanpredmet kreirati najmanji mogući broj indeksa koji će omogućiti efikasno obavljanje svih
navedenih upita:
SELECT * FROM upisanpredmet WHERE akgodina = 2005 AND ozngrupa = 'C-B4';
SELECT * FROM upisanpredmet WHERE sifpredmet = 10 AND ozngrupa = 'C-B4' AND akgodina = 2005 ;
SELECT * FROM upisanpredmet WHERE datumocjena = '01.01.2006' AND sifpredmet = 10;
SELECT * FROM upisanpredmet ORDER BY akgodina, ozngrupa DESC, sifpredmet DESC;
SELECT * FROM upisanpredmet ORDER BY akgodina DESC;
SELECT * FROM upisanpredmet ORDER BY sifpredmet ASC, datumocjena DESC, ocjena DESC;
*/
CREATE INDEX in1 ON upisanpredmet (sifpredmet, datumocjena DESC, ocjena DESC);
CREATE INDEX in2 ON upisanpredmet (akgodina, ozngrupa DESC, sifpredmet DESC);


/*Primarni ključ u relaciji grupa je skup atributa: {akGodina, oznGrupa}.Jednom SQL naredbom osigurajte
entitetski integritet i integritet ključa u toj relaciji.
Osigurati referencijski integritet među relacijama predmetGrupa i grupa
*/
ALTER TABLE grupa ADD CONSTRAINT PRIMARY KEY (akGodina, oznGrupa);
ALTER TABLE predmetGrupa ADD CONSTRAINT FOREIGN KEY (akGodina, oznGrupa) REFERENCES grupa(akGodina, oznGrupa);


/*Napraviti 2 virtualne relacije.
1.Napraviti virtualnu relaciju stanBr sa shemom relacije STANBR = pbrstan, broj koja će omogućiti pregled broja studenata koji su položili barem jedan predmet u 2008/2009 akademskoj godini po poštanskom broju stanovanja.
2.Napraviti virtualnu relaciju mjestoBr sa shemom relacije MJESTOBR = nazmjesto, broj koja će po SVIM mjestima omogućiti pregled broja studenata koji su položili predmet u 2008/2009 akademskoj godini koji stanuju u tom mjestu. Uključiti i studente čije mjesto stanovanja nije poznato.
Virtualnu relaciju mjestoBr obavezno napraviti pomoću relacije stanBr.
*/
CREATE VIEW stanBr (pbrStan, broj) AS
	SELECT pBrStanStudent, COUNT(student.jmbag) -- ?? ili mozda *
		FROM student RIGHT OUTER JOIN upisanPredmet -- left ili right JOIN
		ON student.jmbag = upisanPredmet.jmbag 
		WHERE akGodina = 2008 -- prebacit kod JOIN-a odnosno uvjeta spajanja
		AND ocjena > 1
		GROUP BY pbrStanStudent;
		
CREATE VIEW mjestoBr (nazMjesto, broj) AS
	SELECT nazMjesto, broj
		FROM stanBr FULL OUTER JOIN mjesto
		ON stanBr.pbrStan = mjesto.pbr;
		
		
/*Za relaciju student kreirati najmanji mogući broj indeksa koji će omogućiti efikasno obavljanje svih navedenih upita:
SELECT * FROM student WHERE datumrod > '01.01.1980' ORDER BY datumrod;
SELECT * FROM student WHERE prezimeStudent = 'Salopek' AND imeStudent = 'Andrej';
SELECT * FROM student WHERE prezimeStudent = 'Salopek';
SELECT * FROM student ORDER BY datumrod DESC;
SELECT * FROM student WHERE jmbg = '0101980554687';
SELECT * FROM student WHERE datumrod > '01.01.1980';
SELECT * FROM student ORDER BY datumrod, jmbag;
*/
CREATE INDEX in1 ON student (datumrod,jmbag);
CREATE INDEX in2 ON STUDENT (prezimeStudent, imeStudent);
CREATE INDEX in3 ON STUDENT (jmbg);


/*1. Napraviti virtualnu relaciju stanPO sa shemom relacije STANPO = pbrstan, prosjekocjena koja će omogućiti pregled prosjeka ocjena položenih predmeta u 2007/2008akademskoj godini po poštanskom broju stanovanja.
Prosjek ocjena nije potrebno zaokruživati.
2. Napraviti virtualnu relaciju mjestoPO sa shemom relacije MJESTOPO = nazmjesto, prosjekocjena koja će po SVIM mjestima omogućiti pregled prosjeka ocjena položenihpredmeta u 2007/2008 akademskoj godini studenata koji stanuju u tom mjestu. Uključiti i prosjek ocjena za studente čije mjesto stanovanja nije poznato. Prosjek ocjena nije potrebno zaokruživati.
Virtualnu relaciju mjestoPO obavezno napraviti pomoću relacije stanPO.
*/
CREATE VIEW stanPO (pBrStan, prosjekOcjena) AS
	SELECT pBrStanStudent, AVG(ocjena)
		FROM student FULL RIGHT JOIN upisanPredmet
		ON student.jmbag = upisanPredmet.jmbag
		WHERE akGodina = 2007
		AND ocjena > 1
		GROUP BY pBrStanStudent;
		
CREATE VIEW mjesto PO (nazMjesto, prosjekOcjena) AS
	SELECT nazMjesto, prosjekOcjena
		FROM stanPo FULL JOIN mjesto
		ON stanPo.pBrStan = mjesto.pBr;
		
		
/*Za relaciju upisanpredmet kreirati najmanji mogući broj indeksa koji će omogućiti efikasno obavljanje svih
navedenih upita:
SELECT * FROM upisanpredmet WHERE akgodina = 2005 AND jmbag = '055000491';
SELECT * FROM upisanpredmet WHERE akgodina = 2005 AND ozngrupa = 'C-B4';
SELECT * FROM upisanpredmet WHERE sifpredmet = 10 AND ozngrupa = 'C-B4' AND akgodina = 2005 ;
SELECT * FROM upisanpredmet ORDER BY akgodina, ozngrupa DESC, sifpredmet DESC;
SELECT * FROM upisanpredmet ORDER BY akgodina DESC;
SELECT * FROM upisanpredmet ORDER BY akgodina ASC, jmbag ASC, sifpredmet ASC, ocjena DESC;
*/
CREATE INDEX in1 ON upisanpredmet (akgodina ASC, jmbag ASC, sifpredmet ASC, ocjena DESC);
CREATE INDEX in2 ON upisanpredmet (akgodina ASC, ozngrupa DESC, sifpredmet DESC);


/*Primarni ključ u relaciji grupa je skup atributa: {akGodina, oznGrupa}.Jednom SQL naredbom osigurajte entitetski integritet i integritet ključa u toj relaciji.
Osigurati referencijski integritet među relacijama predmetGrupa i grupa
*/
ALTER TABLE grupa ADD CONSTRAINT PRIMARY KEY (akGodina, oznGrupa);
ALTER TABLE predmetGrupa ADD CONSTRAINT FOREIGN KEY (akGodina, oznGrupa) REFERENCES grupa(akGodina, oznGrupa);


/*Svim nastavnicima čiji je koeficijent jednak maksimalnom koeficijentu postaviti koeficijent na minimalni koeficijent.
*/
CREATE TEMP TABLE koeficijenti (sifNast INTEGER, koef DECIMAL(3,2));

INSERT INTO koeficijenti
	SELECT sifNastavnik, koef -- ovo rjesenje stoju u jednom .pdfu, ali ne vidim smisao ovakvom kompliciranju sa TEMP relacijom osim ako u zadatku nije eksplicitno tako navedeno
		
UPDATE nastavnik
	SET koef = (SELECT MIN(koef)
					FROM koeficijenti)
	WHERE koef = (SELECT MAX(koef)
					FROM koeficijenti);