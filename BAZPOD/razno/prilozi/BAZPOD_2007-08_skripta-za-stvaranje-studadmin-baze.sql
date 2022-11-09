-- Ova skipta stvara bazu "studAdmin". Tablice nemaju kljuèeve (ni primarne ni strane) veæ samo distinct indekse.

-- CLOSE DATABASE;
-- DROP DATABASE studAdmin;

CREATE DATABASE studAdmin WITH LOG;

CREATE TABLE zupanija ( 
  sifZupanija      SMALLINT     NOT NULL 
, nazZupanija      NCHAR(40)    NOT NULL 
); 

CREATE DISTINCT INDEX idx_zupanija  ON zupanija (sifZupanija);

CREATE TABLE mjesto ( 
  pbr              INTEGER      NOT NULL 
, nazMjesto        NCHAR(40)    NOT NULL 
, sifZupanija      SMALLINT 

);
CREATE DISTINCT INDEX idx_mjesto ON mjesto(pbr);
CREATE INDEX mjestoUnique ON mjesto (nazMjesto); 

CREATE TABLE dvorana (
  oznDvorana       CHAR(5)       NOT NULL 
, kapacitet        INTEGER       DEFAULT 40 
); 
CREATE DISTINCT INDEX idx_dvorana ON dvorana(oznDvorana);

CREATE TABLE orgjed (
  sifOrgjed        INTEGER      NOT NULL 
, nazOrgjed        NCHAR(120)    NOT NULL 
, sifNadOrgjed     INTEGER 
); 
CREATE DISTINCT INDEX idx_orgjed ON orgjed(sifOrgjed);


CREATE TABLE predmet (
  sifPredmet      INTEGER       NOT NULL 
, naziv           NCHAR(60)     NOT NULL 
, ECTSBod         DECIMAL(4,1)  
, ukBrSatiTjedno  SMALLINT
); 
CREATE DISTINCT INDEX idx_predmet ON predmet(sifPredmet);

CREATE TABLE grupa (
  akGodina         SMALLINT      NOT NULL
, oznGrupa         CHAR(10)      NOT NULL
, kapacitet        SMALLINT      
); 
CREATE DISTINCT INDEX idx_grupa ON grupa(akGodina, oznGrupa);

CREATE TABLE student (
  JMBAG     CHAR(10)      NOT NULL 
, ime       NCHAR(25)     NOT NULL 
, prezime   NCHAR(25)     NOT NULL 
, jmbg      CHAR(13)
, spol      NCHAR(1)
, datRod    DATE 
, pbrRod    INTEGER 
, pbrStan   INTEGER 

);
CREATE DISTINCT INDEX idx_student ON student(JMBAG) ;

CREATE TABLE nastavnik ( 
  sifNastavnik     INTEGER      NOT NULL 
, ime              NCHAR(25)    NOT NULL 
, prezime          NCHAR(25)    NOT NULL 
, pbrStan          INTEGER 
, sifOrgjed        INTEGER      NOT NULL 
, koef             DECIMAL(3,2) NOT NULL 
, datumZaposlenOd  DATE         NOT NULL 
, datumZaposlenDo  DATE 
); 
CREATE DISTINCT INDEX idx_nastavnik ON nastavnik(sifNastavnik);


CREATE TABLE predmetGrupa (
  sifPredmet       INTEGER       NOT NULL 
, akGodina         SMALLINT      NOT NULL
, oznGrupa         CHAR(10)      NOT NULL
, sifNastavnik     INTEGER       NOT NULL
, oznDvorana       CHAR(5)       
); 
CREATE DISTINCT INDEX idx_predmetGrupa ON predmetGrupa(sifPredmet, akGodina, oznGrupa);

CREATE TABLE  upisanPredmet(
  JMBAG            CHAR(10)      NOT NULL 
, sifPredmet       INTEGER       NOT NULL 
, akGodina         SMALLINT      NOT NULL
, oznGrupa         CHAR(10)      NOT NULL
, datumOcjena      DATE          
, ocjena           SMALLINT      
); 
CREATE DISTINCT INDEX idx_upisanPredmet ON upisanPredmet(JMBAG, sifPredmet, akGodina); 



INSERT INTO zupanija(sifzupanija, nazzupanija)
  VALUES(0, 'Nepoznata županija');
INSERT INTO zupanija(sifzupanija, nazzupanija)
  VALUES(1, 'Zagrebaèka');
INSERT INTO zupanija(sifzupanija, nazzupanija)
  VALUES(2, 'Krapinsko-zagorska');
INSERT INTO zupanija(sifzupanija, nazzupanija)
  VALUES(3, 'Sisaèko-moslavaèka');
INSERT INTO zupanija(sifzupanija, nazzupanija)
  VALUES(4, 'Karlovaèka');
INSERT INTO zupanija(sifzupanija, nazzupanija)
  VALUES(5, 'Varaždinska');
INSERT INTO zupanija(sifzupanija, nazzupanija)
  VALUES(6, 'Koprivnièko-križevaèka');
INSERT INTO zupanija(sifzupanija, nazzupanija)
  VALUES(7, 'Bjelovarsko-bilogorska');
INSERT INTO zupanija(sifzupanija, nazzupanija)
  VALUES(8, 'Primorsko-goranska');
INSERT INTO zupanija(sifzupanija, nazzupanija)
  VALUES(9, 'Lièko-senjska');
INSERT INTO zupanija(sifzupanija, nazzupanija)
  VALUES(10, 'Virovitièko-podravska');
INSERT INTO zupanija(sifzupanija, nazzupanija)
  VALUES(11, 'Požeško-slavonska');
INSERT INTO zupanija(sifzupanija, nazzupanija)
  VALUES(12, 'Brodsko-posavska');
INSERT INTO zupanija(sifzupanija, nazzupanija)
  VALUES(13, 'Zadarska');
INSERT INTO zupanija(sifzupanija, nazzupanija)
  VALUES(14, 'Osjeèko-baranjska');
INSERT INTO zupanija(sifzupanija, nazzupanija)
  VALUES(15, 'Šibensko-kninska');
INSERT INTO zupanija(sifzupanija, nazzupanija)
  VALUES(16, 'Vukovarsko-srijemska');
INSERT INTO zupanija(sifzupanija, nazzupanija)
  VALUES(17, 'Splitsko-dalmatinska');
INSERT INTO zupanija(sifzupanija, nazzupanija)
  VALUES(18, 'Istarska');
INSERT INTO zupanija(sifzupanija, nazzupanija)
  VALUES(19, 'Dubrovaèko-neretvanska');
INSERT INTO zupanija(sifzupanija, nazzupanija)
  VALUES(20, 'Meðimurska');
INSERT INTO zupanija(sifzupanija, nazzupanija)
  VALUES(21, 'Grad Zagreb');



INSERT INTO mjesto(pbr, nazmjesto, sifzupanija)
  VALUES(43500, 'Daruvar', 7);
INSERT INTO mjesto(pbr, nazmjesto, sifzupanija)
  VALUES(43531, 'Veliki Bastaji', 7);
INSERT INTO mjesto(pbr, nazmjesto, sifzupanija)
  VALUES(44000, 'Sisak', 3);
INSERT INTO mjesto(pbr, nazmjesto, sifzupanija)
  VALUES(44271, 'Letovaniæ', 3);
INSERT INTO mjesto(pbr, nazmjesto, sifzupanija)
  VALUES(44320, 'Kutina', 3);
INSERT INTO mjesto(pbr, nazmjesto, sifzupanija)
  VALUES(44330, 'Novska', 3);
INSERT INTO mjesto(pbr, nazmjesto, sifzupanija)
  VALUES(44400, 'Glina', 3);
INSERT INTO mjesto(pbr, nazmjesto, sifzupanija)
  VALUES(44410, 'Gvozd', 3);
INSERT INTO mjesto(pbr, nazmjesto, sifzupanija)
  VALUES(47000, 'Karlovac', 4);
INSERT INTO mjesto(pbr, nazmjesto, sifzupanija)
  VALUES(47201, 'Draganiæi', 4);
INSERT INTO mjesto(pbr, nazmjesto, sifzupanija)
  VALUES(47220, 'Vojniæ', 4);
INSERT INTO mjesto(pbr, nazmjesto, sifzupanija)
  VALUES(47240, 'Slunj', 4);
INSERT INTO mjesto(pbr, nazmjesto, sifzupanija)
  VALUES(47251, 'Bosiljevo', 4);
INSERT INTO mjesto(pbr, nazmjesto, sifzupanija)
  VALUES(47300, 'Ogulin', 4);
INSERT INTO mjesto(pbr, nazmjesto, sifzupanija)
  VALUES(47302, 'Oštarije', 4);
INSERT INTO mjesto(pbr, nazmjesto, sifzupanija)
  VALUES(48000, 'Koprivnica', 6);
INSERT INTO mjesto(pbr, nazmjesto, sifzupanija)
  VALUES(48260, 'Križevci', 6);
INSERT INTO mjesto(pbr, nazmjesto, sifzupanija)
  VALUES(49000, 'Krapina', 2);
INSERT INTO mjesto(pbr, nazmjesto, sifzupanija)
  VALUES(10000, 'Zagreb', 21);
INSERT INTO mjesto(pbr, nazmjesto, sifzupanija)
  VALUES(10010, 'Zagreb-Sloboština', 21);
INSERT INTO mjesto(pbr, nazmjesto, sifzupanija)
  VALUES(10090, 'Zagreb-Susedgrad', 21);
INSERT INTO mjesto(pbr, nazmjesto, sifzupanija)
  VALUES(10360, 'Sesvete', 1);
INSERT INTO mjesto(pbr, nazmjesto, sifzupanija)
  VALUES(10370, 'Dugo Selo', 1);
INSERT INTO mjesto(pbr, nazmjesto, sifzupanija)
  VALUES(10380, 'Sveti Ivan Zelina', 21);
INSERT INTO mjesto(pbr, nazmjesto, sifzupanija)
  VALUES(10430, 'Samobor', 1);
INSERT INTO mjesto(pbr, nazmjesto, sifzupanija)
  VALUES(10450, 'Jastrebarsko', 1);
INSERT INTO mjesto(pbr, nazmjesto, sifzupanija)
  VALUES(20000, 'Dubrovnik', 19);
INSERT INTO mjesto(pbr, nazmjesto, sifzupanija)
  VALUES(20210, 'Cavtat', 19);
INSERT INTO mjesto(pbr, nazmjesto, sifzupanija)
  VALUES(20230, 'Ston', 19);
INSERT INTO mjesto(pbr, nazmjesto, sifzupanija)
  VALUES(20242, 'Oskorušno', 19);
INSERT INTO mjesto(pbr, nazmjesto, sifzupanija)
  VALUES(20250, 'Orebiæ', 19);
INSERT INTO mjesto(pbr, nazmjesto, sifzupanija)
  VALUES(20270, 'Vela Luka', 19);
INSERT INTO mjesto(pbr, nazmjesto, sifzupanija)
  VALUES(20340, 'Ploèe', 19);
INSERT INTO mjesto(pbr, nazmjesto, sifzupanija)
  VALUES(21000, 'Split', 17);
INSERT INTO mjesto(pbr, nazmjesto, sifzupanija)
  VALUES(21210, 'Solin', 17);
INSERT INTO mjesto(pbr, nazmjesto, sifzupanija)
  VALUES(21232, 'Dicmo', 17);
INSERT INTO mjesto(pbr, nazmjesto, sifzupanija)
  VALUES(21240, 'Trilj', 17);
INSERT INTO mjesto(pbr, nazmjesto, sifzupanija)
  VALUES(21270, 'Zagvozd', 17);
INSERT INTO mjesto(pbr, nazmjesto, sifzupanija)
  VALUES(21310, 'Omiš', 17);
INSERT INTO mjesto(pbr, nazmjesto, sifzupanija)
  VALUES(21400, 'Supetar', 17);
INSERT INTO mjesto(pbr, nazmjesto, sifzupanija)
  VALUES(21420, 'Bol', 17);
INSERT INTO mjesto(pbr, nazmjesto, sifzupanija)
  VALUES(21450, 'Hvar', 17);
INSERT INTO mjesto(pbr, nazmjesto, sifzupanija)
  VALUES(22000, 'Šibenik', 15);
INSERT INTO mjesto(pbr, nazmjesto, sifzupanija)
  VALUES(22010, 'Šibenik-Brodarica', 15);
INSERT INTO mjesto(pbr, nazmjesto, sifzupanija)
  VALUES(22020, 'Šibenik-Ražine', 15);
INSERT INTO mjesto(pbr, nazmjesto, sifzupanija)
  VALUES(23210, 'Biograd na moru', 13);
INSERT INTO mjesto(pbr, nazmjesto, sifzupanija)
  VALUES(23250, 'Pag', 13);
INSERT INTO mjesto(pbr, nazmjesto, sifzupanija)
  VALUES(23420, 'Benkovac', 13);
INSERT INTO mjesto(pbr, nazmjesto, sifzupanija)
  VALUES(31000, 'Osijek', 14);
INSERT INTO mjesto(pbr, nazmjesto, sifzupanija)
  VALUES(31300, 'Beli Manastir', 14);
INSERT INTO mjesto(pbr, nazmjesto, sifzupanija)
  VALUES(31301, 'Branjin Vrh', 14);
INSERT INTO mjesto(pbr, nazmjesto, sifzupanija)
  VALUES(31410, 'Strizivojna', 14);
INSERT INTO mjesto(pbr, nazmjesto, sifzupanija)
  VALUES(31500, 'Našice', 14);
INSERT INTO mjesto(pbr, nazmjesto, sifzupanija)
  VALUES(31530, 'Podravska Moslavina', 14);
INSERT INTO mjesto(pbr, nazmjesto, sifzupanija)
  VALUES(31531, 'Viljevo', 14);
INSERT INTO mjesto(pbr, nazmjesto, sifzupanija)
  VALUES(31550, 'Valpovo', 14);
INSERT INTO mjesto(pbr, nazmjesto, sifzupanija)
  VALUES(32000, 'Vukovar', 16);
INSERT INTO mjesto(pbr, nazmjesto, sifzupanija)
  VALUES(32100, 'Vinkovci', 16);
INSERT INTO mjesto(pbr, nazmjesto, sifzupanija)
  VALUES(32240, 'Mirkovci', 16);
INSERT INTO mjesto(pbr, nazmjesto, sifzupanija)
  VALUES(32280, 'Jarmina', 16);
INSERT INTO mjesto(pbr, nazmjesto, sifzupanija)
  VALUES(33000, 'Virovitica', 10);
INSERT INTO mjesto(pbr, nazmjesto, sifzupanija)
  VALUES(33520, 'Slatina', 10);
INSERT INTO mjesto(pbr, nazmjesto, sifzupanija)
  VALUES(34000, 'Požega', 11);
INSERT INTO mjesto(pbr, nazmjesto, sifzupanija)
  VALUES(34310, 'Pleternica', 11);
INSERT INTO mjesto(pbr, nazmjesto, sifzupanija)
  VALUES(34330, 'Velika', 11);
INSERT INTO mjesto(pbr, nazmjesto, sifzupanija)
  VALUES(34340, 'Kutjevo', 11);
INSERT INTO mjesto(pbr, nazmjesto, sifzupanija)
  VALUES(34550, 'Pakrac', 11);
INSERT INTO mjesto(pbr, nazmjesto, sifzupanija)
  VALUES(35000, 'Slavonski Brod', 12);
INSERT INTO mjesto(pbr, nazmjesto, sifzupanija)
  VALUES(35210, 'Vrpolje', 12);
INSERT INTO mjesto(pbr, nazmjesto, sifzupanija)
  VALUES(35220, 'Slavonski Šamac', 12);
INSERT INTO mjesto(pbr, nazmjesto, sifzupanija)
  VALUES(35250, 'Oriovac', 12);
INSERT INTO mjesto(pbr, nazmjesto, sifzupanija)
  VALUES(35420, 'Staro Petrovo Selo', 12);
INSERT INTO mjesto(pbr, nazmjesto, sifzupanija)
  VALUES(40000, 'Èakovec', 20);
INSERT INTO mjesto(pbr, nazmjesto, sifzupanija)
  VALUES(40320, 'Donji Kraljevec', 20);
INSERT INTO mjesto(pbr, nazmjesto, sifzupanija)
  VALUES(42000, 'Varaždin', 5);
INSERT INTO mjesto(pbr, nazmjesto, sifzupanija)
  VALUES(42240, 'Ivanec', 5);
INSERT INTO mjesto(pbr, nazmjesto, sifzupanija)
  VALUES(42250, 'Lepoglava', 5);
INSERT INTO mjesto(pbr, nazmjesto, sifzupanija)
  VALUES(43000, 'Bjelovar', 7);
INSERT INTO mjesto(pbr, nazmjesto, sifzupanija)
  VALUES(43271, 'Velika Pisanica', 7);
INSERT INTO mjesto(pbr, nazmjesto, sifzupanija)
  VALUES(43280, 'Garešnica', 7);
INSERT INTO mjesto(pbr, nazmjesto, sifzupanija)
  VALUES(43290, 'Grubišno Polje', 7);
INSERT INTO mjesto(pbr, nazmjesto, sifzupanija)
  VALUES(49210, 'Zabok', 2);
INSERT INTO mjesto(pbr, nazmjesto, sifzupanija)
  VALUES(49250, 'Zlatar', 2);
INSERT INTO mjesto(pbr, nazmjesto, sifzupanija)
  VALUES(51000, 'Rijeka', 8);
INSERT INTO mjesto(pbr, nazmjesto, sifzupanija)
  VALUES(51211, 'Matulji', 8);
INSERT INTO mjesto(pbr, nazmjesto, sifzupanija)
  VALUES(51251, 'Ledenice', 8);
INSERT INTO mjesto(pbr, nazmjesto, sifzupanija)
  VALUES(51280, 'Rab', 8);
INSERT INTO mjesto(pbr, nazmjesto, sifzupanija)
  VALUES(51410, 'Opatija', 8);
INSERT INTO mjesto(pbr, nazmjesto, sifzupanija)
  VALUES(51550, 'Mali Lošinj', 8);
INSERT INTO mjesto(pbr, nazmjesto, sifzupanija)
  VALUES(52000, 'Pazin', 18);
INSERT INTO mjesto(pbr, nazmjesto, sifzupanija)
  VALUES(52100, 'Pula', 18);
INSERT INTO mjesto(pbr, nazmjesto, sifzupanija)
  VALUES(52420, 'Buzet', 18);
INSERT INTO mjesto(pbr, nazmjesto, sifzupanija)
  VALUES(53000, 'Gospiæ', 9);
INSERT INTO mjesto(pbr, nazmjesto, sifzupanija)
  VALUES(53230, 'Korenica', 9);
INSERT INTO mjesto(pbr, nazmjesto, sifzupanija)
  VALUES(53250, 'Donji Lapac', 9);
INSERT INTO mjesto(pbr, nazmjesto, sifzupanija)
  VALUES(10020, 'Zagreb-Novi Zagreb', 21);
INSERT INTO mjesto(pbr, nazmjesto, sifzupanija)
  VALUES(10040, 'Zagreb-Dubrava', 21);
INSERT INTO mjesto(pbr, nazmjesto, sifzupanija)
  VALUES(10250, 'Luèko', 1);
INSERT INTO mjesto(pbr, nazmjesto, sifzupanija)
  VALUES(10255, 'Gornji Stupnik', 1);
INSERT INTO mjesto(pbr, nazmjesto, sifzupanija)
  VALUES(10290, 'Zaprešiæ', 1);
INSERT INTO mjesto(pbr, nazmjesto, sifzupanija)
  VALUES(10295, 'Kupljenovo', 1);
INSERT INTO mjesto(pbr, nazmjesto, sifzupanija)
  VALUES(10310, 'Ivaniæ-Grad', 1);
INSERT INTO mjesto(pbr, nazmjesto, sifzupanija)
  VALUES(10315, 'Novoselec', 1);
INSERT INTO mjesto(pbr, nazmjesto, sifzupanija)
  VALUES(10340, 'Vrbovec', 1);
INSERT INTO mjesto(pbr, nazmjesto, sifzupanija)
  VALUES(10345, 'Gradec', 1);
INSERT INTO mjesto(pbr, nazmjesto, sifzupanija)
  VALUES(10410, 'Velika Gorica', 1);
INSERT INTO mjesto(pbr, nazmjesto, sifzupanija)
  VALUES(10415, 'Novo Èièe', 1);
INSERT INTO mjesto(pbr, nazmjesto, sifzupanija)
  VALUES(10435, 'Sveti Martin pod Okiæem', 1);
INSERT INTO mjesto(pbr, nazmjesto, sifzupanija)
  VALUES(10455, 'Kostanjevac', 1);
INSERT INTO mjesto(pbr, nazmjesto, sifzupanija)
  VALUES(20205, 'Topolo', 19);
INSERT INTO mjesto(pbr, nazmjesto, sifzupanija)
  VALUES(20215, 'Gruda', 19);
INSERT INTO mjesto(pbr, nazmjesto, sifzupanija)
  VALUES(20225, 'Babino Polje', 19);
INSERT INTO mjesto(pbr, nazmjesto, sifzupanija)
  VALUES(20235, 'Zaton Veliki', 19);
INSERT INTO mjesto(pbr, nazmjesto, sifzupanija)
  VALUES(20240, 'Trpanj', 19);
INSERT INTO mjesto(pbr, nazmjesto, sifzupanija)
  VALUES(20245, 'Trstenik', 19);
INSERT INTO mjesto(pbr, nazmjesto, sifzupanija)
  VALUES(20260, 'Korèula', 19);
INSERT INTO mjesto(pbr, nazmjesto, sifzupanija)
  VALUES(20275, 'Žrnovo', 19);
INSERT INTO mjesto(pbr, nazmjesto, sifzupanija)
  VALUES(20290, 'Lastovo', 19);
INSERT INTO mjesto(pbr, nazmjesto, sifzupanija)
  VALUES(20345, 'Staševica', 19);
INSERT INTO mjesto(pbr, nazmjesto, sifzupanija)
  VALUES(20350, 'Metkoviæ', 19);
INSERT INTO mjesto(pbr, nazmjesto, sifzupanija)
  VALUES(20355, 'Opuzen', 19);
INSERT INTO mjesto(pbr, nazmjesto, sifzupanija)
  VALUES(21205, 'Donji Dolac', 17);
INSERT INTO mjesto(pbr, nazmjesto, sifzupanija)
  VALUES(21215, 'Kaštel Lukšiæ', 17);
INSERT INTO mjesto(pbr, nazmjesto, sifzupanija)
  VALUES(21220, 'Trogir', 17);
INSERT INTO mjesto(pbr, nazmjesto, sifzupanija)
  VALUES(21225, 'Drvenik Veliki', 17);
INSERT INTO mjesto(pbr, nazmjesto, sifzupanija)
  VALUES(21230, 'Sinj', 17);
INSERT INTO mjesto(pbr, nazmjesto, sifzupanija)
  VALUES(21235, 'Otišiæ', 17);
INSERT INTO mjesto(pbr, nazmjesto, sifzupanija)
  VALUES(21245, 'Tijarica', 17);
INSERT INTO mjesto(pbr, nazmjesto, sifzupanija)
  VALUES(21250, 'Šestanovac', 17);
INSERT INTO mjesto(pbr, nazmjesto, sifzupanija)
  VALUES(21255, 'Zadvarje', 17);
INSERT INTO mjesto(pbr, nazmjesto, sifzupanija)
  VALUES(21260, 'Imotski', 17);
INSERT INTO mjesto(pbr, nazmjesto, sifzupanija)
  VALUES(21265, 'Studenci', 17);
INSERT INTO mjesto(pbr, nazmjesto, sifzupanija)
  VALUES(21275, 'Dragljane', 17);
INSERT INTO mjesto(pbr, nazmjesto, sifzupanija)
  VALUES(21300, 'Makarska', 17);
INSERT INTO mjesto(pbr, nazmjesto, sifzupanija)
  VALUES(21315, 'Dugi Rat', 17);
INSERT INTO mjesto(pbr, nazmjesto, sifzupanija)
  VALUES(21320, 'Baška Voda', 17);
INSERT INTO mjesto(pbr, nazmjesto, sifzupanija)
  VALUES(21325, 'Tuèepi', 17);
INSERT INTO mjesto(pbr, nazmjesto, sifzupanija)
  VALUES(21330, 'Gradac', 17);
INSERT INTO mjesto(pbr, nazmjesto, sifzupanija)
  VALUES(21335, 'Podaca', 17);
INSERT INTO mjesto(pbr, nazmjesto, sifzupanija)
  VALUES(21405, 'Milna', 17);
INSERT INTO mjesto(pbr, nazmjesto, sifzupanija)
  VALUES(21410, 'Postira', 17);
INSERT INTO mjesto(pbr, nazmjesto, sifzupanija)
  VALUES(21425, 'Selca', 17);
INSERT INTO mjesto(pbr, nazmjesto, sifzupanija)
  VALUES(21430, 'Grohote', 17);
INSERT INTO mjesto(pbr, nazmjesto, sifzupanija)
  VALUES(21460, 'Stari Grad', 17);
INSERT INTO mjesto(pbr, nazmjesto, sifzupanija)
  VALUES(21465, 'Jelsa', 17);
INSERT INTO mjesto(pbr, nazmjesto, sifzupanija)
  VALUES(21480, 'Vis', 17);
INSERT INTO mjesto(pbr, nazmjesto, sifzupanija)
  VALUES(21485, 'Komiža', 17);
INSERT INTO mjesto(pbr, nazmjesto, sifzupanija)
  VALUES(22030, 'Šibenik-Zablaæe', 15);
INSERT INTO mjesto(pbr, nazmjesto, sifzupanija)
  VALUES(22205, 'Perkoviæ', 15);
INSERT INTO mjesto(pbr, nazmjesto, sifzupanija)
  VALUES(22215, 'Zaton', 15);
INSERT INTO mjesto(pbr, nazmjesto, sifzupanija)
  VALUES(22235, 'Kaprije', 15);
INSERT INTO mjesto(pbr, nazmjesto, sifzupanija)
  VALUES(22240, 'Tisno', 15);
INSERT INTO mjesto(pbr, nazmjesto, sifzupanija)
  VALUES(22320, 'Drniš', 15);
INSERT INTO mjesto(pbr, nazmjesto, sifzupanija)
  VALUES(23000, 'Zadar', 13);
INSERT INTO mjesto(pbr, nazmjesto, sifzupanija)
  VALUES(23205, 'Bibinje', 13);
INSERT INTO mjesto(pbr, nazmjesto, sifzupanija)
  VALUES(23235, 'Vrsi', 13);
INSERT INTO mjesto(pbr, nazmjesto, sifzupanija)
  VALUES(23245, 'Tribanj', 13);
INSERT INTO mjesto(pbr, nazmjesto, sifzupanija)
  VALUES(23275, 'Ugljan', 13);
INSERT INTO mjesto(pbr, nazmjesto, sifzupanija)
  VALUES(23285, 'Brbinj', 13);
INSERT INTO mjesto(pbr, nazmjesto, sifzupanija)
  VALUES(23295, 'Silba', 13);
INSERT INTO mjesto(pbr, nazmjesto, sifzupanija)
  VALUES(23440, 'Graèac', 13);
INSERT INTO mjesto(pbr, nazmjesto, sifzupanija)
  VALUES(23445, 'Srb', 13);
INSERT INTO mjesto(pbr, nazmjesto, sifzupanija)
  VALUES(23450, 'Obrovac', 13);
INSERT INTO mjesto(pbr, nazmjesto, sifzupanija)
  VALUES(31205, 'Aljmaš', 14);
INSERT INTO mjesto(pbr, nazmjesto, sifzupanija)
  VALUES(31215, 'Ernestinovo', 14);
INSERT INTO mjesto(pbr, nazmjesto, sifzupanija)
  VALUES(31225, 'Breznica Našièka', 14);
INSERT INTO mjesto(pbr, nazmjesto, sifzupanija)
  VALUES(31305, 'Draž', 14);
INSERT INTO mjesto(pbr, nazmjesto, sifzupanija)
  VALUES(31315, 'Karanac', 14);
INSERT INTO mjesto(pbr, nazmjesto, sifzupanija)
  VALUES(31325, 'Èeminac', 14);
INSERT INTO mjesto(pbr, nazmjesto, sifzupanija)
  VALUES(31400, 'Ðakovo', 14);
INSERT INTO mjesto(pbr, nazmjesto, sifzupanija)
  VALUES(31415, 'Selci Ðakovaèki', 14);
INSERT INTO mjesto(pbr, nazmjesto, sifzupanija)
  VALUES(31540, 'Donji Miholjac', 14);
INSERT INTO mjesto(pbr, nazmjesto, sifzupanija)
  VALUES(31555, 'Marijanci', 14);
INSERT INTO mjesto(pbr, nazmjesto, sifzupanija)
  VALUES(32225, 'Bobota', 16);
INSERT INTO mjesto(pbr, nazmjesto, sifzupanija)
  VALUES(32235, 'Bapska', 16);
INSERT INTO mjesto(pbr, nazmjesto, sifzupanija)
  VALUES(32245, 'Nijemci', 16);
INSERT INTO mjesto(pbr, nazmjesto, sifzupanija)
  VALUES(32255, 'Soljani', 16);
INSERT INTO mjesto(pbr, nazmjesto, sifzupanija)
  VALUES(32260, 'Gunja', 16);
INSERT INTO mjesto(pbr, nazmjesto, sifzupanija)
  VALUES(32270, 'Županja', 16);
INSERT INTO mjesto(pbr, nazmjesto, sifzupanija)
  VALUES(32275, 'Bošnjaci', 16);
INSERT INTO mjesto(pbr, nazmjesto, sifzupanija)
  VALUES(33405, 'Pitomaèa', 10);
INSERT INTO mjesto(pbr, nazmjesto, sifzupanija)
  VALUES(33410, 'Suhopolje', 10);
INSERT INTO mjesto(pbr, nazmjesto, sifzupanija)
  VALUES(33515, 'Orahovica', 10);
INSERT INTO mjesto(pbr, nazmjesto, sifzupanija)
  VALUES(33525, 'Sopje', 10);
INSERT INTO mjesto(pbr, nazmjesto, sifzupanija)
  VALUES(34315, 'Ratkovica', 11);
INSERT INTO mjesto(pbr, nazmjesto, sifzupanija)
  VALUES(34320, 'Orljavac', 11);
INSERT INTO mjesto(pbr, nazmjesto, sifzupanija)
  VALUES(34335, 'Vetovo', 11);
INSERT INTO mjesto(pbr, nazmjesto, sifzupanija)
  VALUES(34350, 'Èaglin', 11);
INSERT INTO mjesto(pbr, nazmjesto, sifzupanija)
  VALUES(35215, 'Svilaj', 12);
INSERT INTO mjesto(pbr, nazmjesto, sifzupanija)
  VALUES(35255, 'Slavonski Kobaš', 12);
INSERT INTO mjesto(pbr, nazmjesto, sifzupanija)
  VALUES(35400, 'Nova Gradiška', 12);
INSERT INTO mjesto(pbr, nazmjesto, sifzupanija)
  VALUES(35425, 'Davor', 12);
INSERT INTO mjesto(pbr, nazmjesto, sifzupanija)
  VALUES(35430, 'Okuèani', 12);
INSERT INTO mjesto(pbr, nazmjesto, sifzupanija)
  VALUES(35435, 'Stara Gradiška', 12);
INSERT INTO mjesto(pbr, nazmjesto, sifzupanija)
  VALUES(40305, 'Nedelišèe', 20);
INSERT INTO mjesto(pbr, nazmjesto, sifzupanija)
  VALUES(40315, 'Mursko Središèe', 20);
INSERT INTO mjesto(pbr, nazmjesto, sifzupanija)
  VALUES(40325, 'Draškovec', 20);
INSERT INTO mjesto(pbr, nazmjesto, sifzupanija)
  VALUES(42205, 'Vidovec', 5);
INSERT INTO mjesto(pbr, nazmjesto, sifzupanija)
  VALUES(42220, 'Novi Marof', 5);
INSERT INTO mjesto(pbr, nazmjesto, sifzupanija)
  VALUES(42225, 'Breznièki Hum', 5);
INSERT INTO mjesto(pbr, nazmjesto, sifzupanija)
  VALUES(42230, 'Ludbreg', 5);
INSERT INTO mjesto(pbr, nazmjesto, sifzupanija)
  VALUES(42245, 'Donja Voæa', 5);
INSERT INTO mjesto(pbr, nazmjesto, sifzupanija)
  VALUES(42255, 'Donja Višnjica', 5);
INSERT INTO mjesto(pbr, nazmjesto, sifzupanija)
  VALUES(43240, 'Èazma', 7);
INSERT INTO mjesto(pbr, nazmjesto, sifzupanija)
  VALUES(43245, 'Gornji Draganec', 7);
INSERT INTO mjesto(pbr, nazmjesto, sifzupanija)
  VALUES(43270, 'Veliki Grðevac', 7);
INSERT INTO mjesto(pbr, nazmjesto, sifzupanija)
  VALUES(43285, 'Velika Trnovitica', 7);
INSERT INTO mjesto(pbr, nazmjesto, sifzupanija)
  VALUES(43505, 'Konèanica', 7);
INSERT INTO mjesto(pbr, nazmjesto, sifzupanija)
  VALUES(44205, 'Donja Baèuga', 3);
INSERT INTO mjesto(pbr, nazmjesto, sifzupanija)
  VALUES(44210, 'Sunja', 3);
INSERT INTO mjesto(pbr, nazmjesto, sifzupanija)
  VALUES(44250, 'Petrinja', 3);
INSERT INTO mjesto(pbr, nazmjesto, sifzupanija)
  VALUES(44325, 'Krapje', 3);
INSERT INTO mjesto(pbr, nazmjesto, sifzupanija)
  VALUES(44405, 'Mali Gradac', 3);
INSERT INTO mjesto(pbr, nazmjesto, sifzupanija)
  VALUES(44415, 'Topusko', 3);
INSERT INTO mjesto(pbr, nazmjesto, sifzupanija)
  VALUES(44425, 'Gornja Buèica', 3);
INSERT INTO mjesto(pbr, nazmjesto, sifzupanija)
  VALUES(44430, 'Hrvatska Kostajnica', 3);
INSERT INTO mjesto(pbr, nazmjesto, sifzupanija)
  VALUES(44435, 'Divuša', 3);
INSERT INTO mjesto(pbr, nazmjesto, sifzupanija)
  VALUES(44440, 'Dvor', 3);
INSERT INTO mjesto(pbr, nazmjesto, sifzupanija)
  VALUES(44450, 'Hrvatska Dubica', 3);
INSERT INTO mjesto(pbr, nazmjesto, sifzupanija)
  VALUES(47205, 'Vukmaniæ', 4);
INSERT INTO mjesto(pbr, nazmjesto, sifzupanija)
  VALUES(47245, 'Rakovica', 4);
INSERT INTO mjesto(pbr, nazmjesto, sifzupanija)
  VALUES(47250, 'Duga Resa', 4);
INSERT INTO mjesto(pbr, nazmjesto, sifzupanija)
  VALUES(47280, 'Ozalj', 4);
INSERT INTO mjesto(pbr, nazmjesto, sifzupanija)
  VALUES(47305, 'Lièka Jesenica', 4);
INSERT INTO mjesto(pbr, nazmjesto, sifzupanija)
  VALUES(48265, 'Raven', 6);
INSERT INTO mjesto(pbr, nazmjesto, sifzupanija)
  VALUES(48305, 'Reka', 6);
INSERT INTO mjesto(pbr, nazmjesto, sifzupanija)
  VALUES(48325, 'Novigrad Podravski', 6);
INSERT INTO mjesto(pbr, nazmjesto, sifzupanija)
  VALUES(48350, 'Ðurðevac', 6);
INSERT INTO mjesto(pbr, nazmjesto, sifzupanija)
  VALUES(48355, 'Novo Virje', 6);
INSERT INTO mjesto(pbr, nazmjesto, sifzupanija)
  VALUES(49215, 'Tuhelj', 2);
INSERT INTO mjesto(pbr, nazmjesto, sifzupanija)
  VALUES(49225, 'Ðurmanec', 2);
INSERT INTO mjesto(pbr, nazmjesto, sifzupanija)
  VALUES(49240, 'Donja Stubica', 2);
INSERT INTO mjesto(pbr, nazmjesto, sifzupanija)
  VALUES(49245, 'Gornja Stubica', 2);
INSERT INTO mjesto(pbr, nazmjesto, sifzupanija)
  VALUES(49255, 'Novi Golubovec', 2);
INSERT INTO mjesto(pbr, nazmjesto, sifzupanija)
  VALUES(49290, 'Klanjec', 2);
INSERT INTO mjesto(pbr, nazmjesto, sifzupanija)
  VALUES(49295, 'Kumrovec', 2);
INSERT INTO mjesto(pbr, nazmjesto, sifzupanija)
  VALUES(51215, 'Kastav', 8);
INSERT INTO mjesto(pbr, nazmjesto, sifzupanija)
  VALUES(51225, 'Praputnjak', 8);
INSERT INTO mjesto(pbr, nazmjesto, sifzupanija)
  VALUES(51250, 'Novi Vinodolski', 8);
INSERT INTO mjesto(pbr, nazmjesto, sifzupanija)
  VALUES(51260, 'Crikvenica', 8);
INSERT INTO mjesto(pbr, nazmjesto, sifzupanija)
  VALUES(51265, 'Dramalj', 8);
INSERT INTO mjesto(pbr, nazmjesto, sifzupanija)
  VALUES(51300, 'Delnice', 8);
INSERT INTO mjesto(pbr, nazmjesto, sifzupanija)
  VALUES(51305, 'Tršæe', 8);
INSERT INTO mjesto(pbr, nazmjesto, sifzupanija)
  VALUES(51315, 'Mrkopalj', 8);
INSERT INTO mjesto(pbr, nazmjesto, sifzupanija)
  VALUES(51325, 'Moravice', 8);
INSERT INTO mjesto(pbr, nazmjesto, sifzupanija)
  VALUES(51415, 'Lovran', 8);
INSERT INTO mjesto(pbr, nazmjesto, sifzupanija)
  VALUES(51500, 'Krk', 8);
INSERT INTO mjesto(pbr, nazmjesto, sifzupanija)
  VALUES(51515, 'Šilo', 8);
INSERT INTO mjesto(pbr, nazmjesto, sifzupanija)
  VALUES(51555, 'Belej', 8);
INSERT INTO mjesto(pbr, nazmjesto, sifzupanija)
  VALUES(52210, 'Rovinj (Rovigno)', 18);
INSERT INTO mjesto(pbr, nazmjesto, sifzupanija)
  VALUES(52215, 'Vodnjan (Dignano)', 18);
INSERT INTO mjesto(pbr, nazmjesto, sifzupanija)
  VALUES(52220, 'Labin', 18);
INSERT INTO mjesto(pbr, nazmjesto, sifzupanija)
  VALUES(52425, 'Roè', 18);
INSERT INTO mjesto(pbr, nazmjesto, sifzupanija)
  VALUES(52440, 'Poreè', 18);
INSERT INTO mjesto(pbr, nazmjesto, sifzupanija)
  VALUES(52445, 'Baderna', 18);
INSERT INTO mjesto(pbr, nazmjesto, sifzupanija)
  VALUES(52450, 'Vrsar', 18);
INSERT INTO mjesto(pbr, nazmjesto, sifzupanija)
  VALUES(52460, 'Buje (Buie)', 18);
INSERT INTO mjesto(pbr, nazmjesto, sifzupanija)
  VALUES(52465, 'Tar', 18);
INSERT INTO mjesto(pbr, nazmjesto, sifzupanija)
  VALUES(52470, 'Umag (Umago)', 18);
INSERT INTO mjesto(pbr, nazmjesto, sifzupanija)
  VALUES(52475, 'Savudrija (Salvore)', 18);
INSERT INTO mjesto(pbr, nazmjesto, sifzupanija)
  VALUES(53205, 'Medak', 9);
INSERT INTO mjesto(pbr, nazmjesto, sifzupanija)
  VALUES(53220, 'Otoèac', 9);
INSERT INTO mjesto(pbr, nazmjesto, sifzupanija)
  VALUES(53225, 'Švica', 9);
INSERT INTO mjesto(pbr, nazmjesto, sifzupanija)
  VALUES(53260, 'Brinje', 9);
INSERT INTO mjesto(pbr, nazmjesto, sifzupanija)
  VALUES(53270, 'Senj', 9);
INSERT INTO mjesto(pbr, nazmjesto, sifzupanija)
  VALUES(53285, 'Lukovo', 9);
INSERT INTO mjesto(pbr, nazmjesto, sifzupanija)
  VALUES(31220, 'Višnjevac', 14);
INSERT INTO mjesto(pbr, nazmjesto, sifzupanija)
  VALUES(47285, 'Radatoviæi', 4);
INSERT INTO mjesto(pbr, nazmjesto, sifzupanija)
  VALUES(44010, 'Sisak-Caprag', 3);
INSERT INTO mjesto(pbr, nazmjesto, sifzupanija)
  VALUES(53235, 'Buniæ', 9);
INSERT INTO mjesto(pbr, nazmjesto, sifzupanija)
  VALUES(22310, 'Kijevo', 15);
INSERT INTO mjesto(pbr, nazmjesto, sifzupanija)
  VALUES(22305, 'Kistanje', 15);
INSERT INTO mjesto(pbr, nazmjesto, sifzupanija)
  VALUES(22300, 'Knin', 15);
INSERT INTO mjesto(pbr, nazmjesto, sifzupanija)
  VALUES(49221, 'Bedekovèina', 2);
INSERT INTO mjesto(pbr, nazmjesto, sifzupanija)
  VALUES(49247, 'Zlatar Bistrica', 2);


INSERT INTO dvorana(ozndvorana, kapacitet)
  VALUES('A101', 60);
INSERT INTO dvorana(ozndvorana, kapacitet)
  VALUES('B1', 100);
INSERT INTO dvorana(ozndvorana, kapacitet)
  VALUES('D1', 100);
INSERT INTO dvorana(ozndvorana, kapacitet)
  VALUES('D160', 60);
INSERT INTO dvorana(ozndvorana, kapacitet)
  VALUES('A102', 60);
INSERT INTO dvorana(ozndvorana, kapacitet)
  VALUES('A104', 30);
INSERT INTO dvorana(ozndvorana, kapacitet)
  VALUES('A105', 24);
INSERT INTO dvorana(ozndvorana, kapacitet)
  VALUES('A111', 60);
INSERT INTO dvorana(ozndvorana, kapacitet)
  VALUES('A201', 60);
INSERT INTO dvorana(ozndvorana, kapacitet)
  VALUES('A202', 60);
INSERT INTO dvorana(ozndvorana, kapacitet)
  VALUES('A204', 30);
INSERT INTO dvorana(ozndvorana, kapacitet)
  VALUES('A205', 30);
INSERT INTO dvorana(ozndvorana, kapacitet)
  VALUES('A209', 50);
INSERT INTO dvorana(ozndvorana, kapacitet)
  VALUES('A210', 60);
INSERT INTO dvorana(ozndvorana, kapacitet)
  VALUES('A211', 60);
INSERT INTO dvorana(ozndvorana, kapacitet)
  VALUES('B4', 100);
INSERT INTO dvorana(ozndvorana, kapacitet)
  VALUES('B2', 50);
INSERT INTO dvorana(ozndvorana, kapacitet)
  VALUES('B3', 50);
INSERT INTO dvorana(ozndvorana, kapacitet)
  VALUES('D2', 100);
INSERT INTO dvorana(ozndvorana, kapacitet)
  VALUES('D033', 35);
INSERT INTO dvorana(ozndvorana, kapacitet)
  VALUES('D152', 50);
INSERT INTO dvorana(ozndvorana, kapacitet)
  VALUES('D153', 25);
INSERT INTO dvorana(ozndvorana, kapacitet)
  VALUES('D158', 25);
INSERT INTO dvorana(ozndvorana, kapacitet)
  VALUES('D159', 20);
INSERT INTO dvorana(ozndvorana, kapacitet)
  VALUES('D346', 55);
INSERT INTO dvorana(ozndvorana, kapacitet)
  VALUES('D347', 25);
INSERT INTO dvorana(ozndvorana, kapacitet)
  VALUES('D251', 20);
INSERT INTO dvorana(ozndvorana, kapacitet)
  VALUES('D258', 20);
INSERT INTO dvorana(ozndvorana, kapacitet)
  VALUES('D259', 18);
INSERT INTO dvorana(ozndvorana, kapacitet)
  VALUES('D260', 64);
INSERT INTO dvorana(ozndvorana, kapacitet)
  VALUES('D262', 24);
INSERT INTO dvorana(ozndvorana, kapacitet)
  VALUES('D263', 16);
INSERT INTO dvorana(ozndvorana, kapacitet)
  VALUES('D269', 24);
INSERT INTO dvorana(ozndvorana, kapacitet)
  VALUES('D270', 24);
INSERT INTO dvorana(ozndvorana, kapacitet)
  VALUES('D272', 64);
INSERT INTO dvorana(ozndvorana, kapacitet)
  VALUES('D273', 60);
INSERT INTO dvorana(ozndvorana, kapacitet)
  VALUES('B5', 40);
INSERT INTO dvorana(ozndvorana, kapacitet)
  VALUES('A301', 16);
INSERT INTO dvorana(ozndvorana, kapacitet)
  VALUES('A302', 16);
INSERT INTO dvorana(ozndvorana, kapacitet)
  VALUES('A309', 16);
INSERT INTO dvorana(ozndvorana, kapacitet)
  VALUES('A310', 16);
INSERT INTO dvorana(ozndvorana, kapacitet)
  VALUES('A311', 16);
INSERT INTO dvorana(ozndvorana, kapacitet)
  VALUES('A312', 16);
INSERT INTO dvorana(ozndvorana, kapacitet)
  VALUES('A109', 40);
INSERT INTO dvorana(ozndvorana, kapacitet)
  VALUES('A110', 40);
INSERT INTO dvorana(ozndvorana, kapacitet)
  VALUES('C603', 36);



INSERT INTO orgjed(siforgjed, nazorgjed, sifnadorgjed)
  VALUES(9996, 'Sveuèilište u Zagrebu', NULL);
INSERT INTO orgjed(siforgjed, nazorgjed, sifnadorgjed)
  VALUES(9997, 'Sveuèilište u Osijeku', NULL);
INSERT INTO orgjed(siforgjed, nazorgjed, sifnadorgjed)
  VALUES(9998, 'Sveuèilište u Rijeci', NULL);
INSERT INTO orgjed(siforgjed, nazorgjed, sifnadorgjed)
  VALUES(9999, 'Sveuèilište u Splitu', NULL);
INSERT INTO orgjed(siforgjed, nazorgjed, sifnadorgjed)
  VALUES(6, 'Farmaceutsko-biokemijski fakultet', 9996);
INSERT INTO orgjed(siforgjed, nazorgjed, sifnadorgjed)
  VALUES(7, 'Geodetski fakultet', 9996);
INSERT INTO orgjed(siforgjed, nazorgjed, sifnadorgjed)
  VALUES(9, 'Filozofski fakultet u Rijeci', 9998);
INSERT INTO orgjed(siforgjed, nazorgjed, sifnadorgjed)
  VALUES(10, 'Ekonomski fakultet', 9997);
INSERT INTO orgjed(siforgjed, nazorgjed, sifnadorgjed)
  VALUES(11, 'Kemijsko-tehnološki fakultet', 9999);
INSERT INTO orgjed(siforgjed, nazorgjed, sifnadorgjed)
  VALUES(13, 'Edukacijsko-rehabilitacijski fakultet', 9996);
INSERT INTO orgjed(siforgjed, nazorgjed, sifnadorgjed)
  VALUES(15, 'Fakultet politièkih znanosti', 9996);
INSERT INTO orgjed(siforgjed, nazorgjed, sifnadorgjed)
  VALUES(16, 'Fakultet organizacije i informatike u Varaždinu', 9996);
INSERT INTO orgjed(siforgjed, nazorgjed, sifnadorgjed)
  VALUES(18, 'Pravni fakultet', 9999);
INSERT INTO orgjed(siforgjed, nazorgjed, sifnadorgjed)
  VALUES(23, 'Fakultet elektrotehnike, strojarstva i brodogradnje', 9999);
INSERT INTO orgjed(siforgjed, nazorgjed, sifnadorgjed)
  VALUES(33, 'Fakultet za turizam i vanjsku trgovinu', 9999);
INSERT INTO orgjed(siforgjed, nazorgjed, sifnadorgjed)
  VALUES(34, 'Fakultet za fizièku kulturu', 9996);
INSERT INTO orgjed(siforgjed, nazorgjed, sifnadorgjed)
  VALUES(36, 'Fakultet elektrotehnike i raèunarstva', 9996);
INSERT INTO orgjed(siforgjed, nazorgjed, sifnadorgjed)
  VALUES(37, 'Prirodoslovno-matematièki fakultet Matematièki odjel', 9996);
INSERT INTO orgjed(siforgjed, nazorgjed, sifnadorgjed)
  VALUES(53, 'Veterinarski fakultet', 9996);
INSERT INTO orgjed(siforgjed, nazorgjed, sifnadorgjed)
  VALUES(54, 'Arhitektonski fakultet', 9996);
INSERT INTO orgjed(siforgjed, nazorgjed, sifnadorgjed)
  VALUES(55, 'Ekonomski fakultet', 9999);
INSERT INTO orgjed(siforgjed, nazorgjed, sifnadorgjed)
  VALUES(58, 'Prehrambeno-biotehnološki fakultet', 9996);
INSERT INTO orgjed(siforgjed, nazorgjed, sifnadorgjed)
  VALUES(62, 'Medicinski fakultet', 9998);
INSERT INTO orgjed(siforgjed, nazorgjed, sifnadorgjed)
  VALUES(63, 'Medicinski fakultet', 9999);
INSERT INTO orgjed(siforgjed, nazorgjed, sifnadorgjed)
  VALUES(65, 'Stomatološki fakultet', 9996);
INSERT INTO orgjed(siforgjed, nazorgjed, sifnadorgjed)
  VALUES(66, 'Pravni fakultet', 9996);
INSERT INTO orgjed(siforgjed, nazorgjed, sifnadorgjed)
  VALUES(67, 'Ekonomski fakultet', 9996);
INSERT INTO orgjed(siforgjed, nazorgjed, sifnadorgjed)
  VALUES(68, 'Šumarski fakultet', 9996);
INSERT INTO orgjed(siforgjed, nazorgjed, sifnadorgjed)
  VALUES(69, 'Tehnièki fakultet', 9998);
INSERT INTO orgjed(siforgjed, nazorgjed, sifnadorgjed)
  VALUES(70, 'Filozofski fakultet', 9999);
INSERT INTO orgjed(siforgjed, nazorgjed, sifnadorgjed)
  VALUES(79, 'Poljoprivredni fakultet', 9997);
INSERT INTO orgjed(siforgjed, nazorgjed, sifnadorgjed)
  VALUES(81, 'Ekonomski fakultet', 9998);
INSERT INTO orgjed(siforgjed, nazorgjed, sifnadorgjed)
  VALUES(82, 'Graðevinski fakultet', 9996);
INSERT INTO orgjed(siforgjed, nazorgjed, sifnadorgjed)
  VALUES(83, 'Graðevinski fakultet', 9999);
INSERT INTO orgjed(siforgjed, nazorgjed, sifnadorgjed)
  VALUES(108, 'Medicinski fakultet', 9996);
INSERT INTO orgjed(siforgjed, nazorgjed, sifnadorgjed)
  VALUES(111, 'Pravni fakultet', 9997);
INSERT INTO orgjed(siforgjed, nazorgjed, sifnadorgjed)
  VALUES(113, 'Prehrambeno tehnološki fakultet', 9997);
INSERT INTO orgjed(siforgjed, nazorgjed, sifnadorgjed)
  VALUES(114, 'Graðevinski fakultet', 9998);
INSERT INTO orgjed(siforgjed, nazorgjed, sifnadorgjed)
  VALUES(115, 'Pravni fakultet', 9998);
INSERT INTO orgjed(siforgjed, nazorgjed, sifnadorgjed)
  VALUES(116, 'Hotelijerski fakultet', 9998);
INSERT INTO orgjed(siforgjed, nazorgjed, sifnadorgjed)
  VALUES(117, 'Tekstilno-tehnološki fakultet', 9996);
INSERT INTO orgjed(siforgjed, nazorgjed, sifnadorgjed)
  VALUES(119, 'Prirodoslovno-matematièki fakultet Prirodoslovni odsjeci', 9996);
INSERT INTO orgjed(siforgjed, nazorgjed, sifnadorgjed)
  VALUES(120, 'Fakultet strojarstva i brodogradnje', 9996);
INSERT INTO orgjed(siforgjed, nazorgjed, sifnadorgjed)
  VALUES(122, 'Pedagoški fakultet', 9997);
INSERT INTO orgjed(siforgjed, nazorgjed, sifnadorgjed)
  VALUES(124, 'Metalurški fakultet', 9996);
INSERT INTO orgjed(siforgjed, nazorgjed, sifnadorgjed)
  VALUES(125, 'Fakultet kemijskog inženjerstva i tehnologije', 9996);
INSERT INTO orgjed(siforgjed, nazorgjed, sifnadorgjed)
  VALUES(128, 'Grafièki fakultet', 9996);
INSERT INTO orgjed(siforgjed, nazorgjed, sifnadorgjed)
  VALUES(130, 'Filozofski fakultet', 9996);
INSERT INTO orgjed(siforgjed, nazorgjed, sifnadorgjed)
  VALUES(131, 'Uèiteljska akademija', 9996);
INSERT INTO orgjed(siforgjed, nazorgjed, sifnadorgjed)
  VALUES(135, 'Fakultet prometnih znanosti', 9996);
INSERT INTO orgjed(siforgjed, nazorgjed, sifnadorgjed)
  VALUES(140, 'Filozofski fakultet u Puli', 9998);
INSERT INTO orgjed(siforgjed, nazorgjed, sifnadorgjed)
  VALUES(145, 'Fakultet ekonomije i turizma "Dr. Mijo Mirkoviæ"', 9998);
INSERT INTO orgjed(siforgjed, nazorgjed, sifnadorgjed)
  VALUES(149, 'Graðevinski fakultet', 9997);
INSERT INTO orgjed(siforgjed, nazorgjed, sifnadorgjed)
  VALUES(152, 'Strojarski fakultet', 9997);
INSERT INTO orgjed(siforgjed, nazorgjed, sifnadorgjed)
  VALUES(160, 'Geotehnièki fakultet', 9996);
INSERT INTO orgjed(siforgjed, nazorgjed, sifnadorgjed)
  VALUES(165, 'Elektrotehnièki fakultet', 9997);
INSERT INTO orgjed(siforgjed, nazorgjed, sifnadorgjed)
  VALUES(177, 'Fakultet prirodoslovno matematièkih znanosti i odgojnih podr', 9999);
INSERT INTO orgjed(siforgjed, nazorgjed, sifnadorgjed)
  VALUES(178, 'Agronomski fakultet', 9996);
INSERT INTO orgjed(siforgjed, nazorgjed, sifnadorgjed)
  VALUES(195, 'Rudarsko-geološko-naftni fakultet', 9996);
INSERT INTO orgjed(siforgjed, nazorgjed, sifnadorgjed)
  VALUES(203, 'Katolièki bogoslovni fakultet', 9996);
INSERT INTO orgjed(siforgjed, nazorgjed, sifnadorgjed)
  VALUES(215, 'Umjetnièka akademija', 9999);
INSERT INTO orgjed(siforgjed, nazorgjed, sifnadorgjed)
  VALUES(224, 'Veleuèilište u Dubrovniku', NULL);
INSERT INTO orgjed(siforgjed, nazorgjed, sifnadorgjed)
  VALUES(236, 'Medicinski fakultet', 9997);
INSERT INTO orgjed(siforgjed, nazorgjed, sifnadorgjed)
  VALUES(239, 'Odjel za pomorstvo u Rijeci', 9998);
INSERT INTO orgjed(siforgjed, nazorgjed, sifnadorgjed)
  VALUES(245, 'Odjel za pomorstvo u Splitu', 9999);
INSERT INTO orgjed(siforgjed, nazorgjed, sifnadorgjed)
  VALUES(262, 'Visoka uèiteljska škola', 9999);
INSERT INTO orgjed(siforgjed, nazorgjed, sifnadorgjed)
  VALUES(263, 'Visoka uèiteljska škola', 9999);
INSERT INTO orgjed(siforgjed, nazorgjed, sifnadorgjed)
  VALUES(264, 'Visoka uèiteljska škola', 9998);
INSERT INTO orgjed(siforgjed, nazorgjed, sifnadorgjed)
  VALUES(265, 'Visoka uèiteljska škola', 9998);
INSERT INTO orgjed(siforgjed, nazorgjed, sifnadorgjed)
  VALUES(266, 'Visoka uèiteljska škola', 9998);
INSERT INTO orgjed(siforgjed, nazorgjed, sifnadorgjed)
  VALUES(267, 'Visoka uèiteljska škola', 9997);
INSERT INTO orgjed(siforgjed, nazorgjed, sifnadorgjed)
  VALUES(302, 'Studij poslovne informatike', 9996);
INSERT INTO orgjed(siforgjed, nazorgjed, sifnadorgjed)
  VALUES(381, 'Akademija likovnih umjetnosti', 9996);
INSERT INTO orgjed(siforgjed, nazorgjed, sifnadorgjed)
  VALUES(1053, 'Akademija dramske umjetnosti', 9996);
INSERT INTO orgjed(siforgjed, nazorgjed, sifnadorgjed)
  VALUES(1298, 'Katolièki bogoslovni fakultet', 9999);
INSERT INTO orgjed(siforgjed, nazorgjed, sifnadorgjed)
  VALUES(1349, 'Muzièka akademija', 9996);
INSERT INTO orgjed(siforgjed, nazorgjed, sifnadorgjed)
  VALUES(2223, 'Hrvatski studiji', 9996);
INSERT INTO orgjed(siforgjed, nazorgjed, sifnadorgjed)
  VALUES(2241, 'Nautièki odjel', 224);
INSERT INTO orgjed(siforgjed, nazorgjed, sifnadorgjed)
  VALUES(2242, 'Strojarski odjel', 224);
INSERT INTO orgjed(siforgjed, nazorgjed, sifnadorgjed)
  VALUES(2243, 'Odjel elektrotehnike i raèunarstva', 224);
INSERT INTO orgjed(siforgjed, nazorgjed, sifnadorgjed)
  VALUES(2244, 'Turistièki odjel', 224);
INSERT INTO orgjed(siforgjed, nazorgjed, sifnadorgjed)
  VALUES(8888, 'SPECIMEN', 9996);
INSERT INTO orgjed(siforgjed, nazorgjed, sifnadorgjed)
  VALUES(100001, 'Zavod za primijenjenu fiziku', 36);
INSERT INTO orgjed(siforgjed, nazorgjed, sifnadorgjed)
  VALUES(100002, 'Zavod za primijenjenu matematiku', 36);
INSERT INTO orgjed(siforgjed, nazorgjed, sifnadorgjed)
  VALUES(100003, 'Zavod za osnove elektrotehnike i elektrièka mjerenja', 36);
INSERT INTO orgjed(siforgjed, nazorgjed, sifnadorgjed)
  VALUES(100004, 'Zavod za elektrostrojarstvo i automatizaciju', 36);
INSERT INTO orgjed(siforgjed, nazorgjed, sifnadorgjed)
  VALUES(100005, 'Zavod za visoki napon i energetiku', 36);
INSERT INTO orgjed(siforgjed, nazorgjed, sifnadorgjed)
  VALUES(100006, 'Zavod za telekomunikacije', 36);
INSERT INTO orgjed(siforgjed, nazorgjed, sifnadorgjed)
  VALUES(100007, 'Zavod za elektronièke sustave i obradbu informacija', 36);
INSERT INTO orgjed(siforgjed, nazorgjed, sifnadorgjed)
  VALUES(100008, 'Zavod za automatiku i raèunalno inženjerstvo', 36);
INSERT INTO orgjed(siforgjed, nazorgjed, sifnadorgjed)
  VALUES(100009, 'Zavod za elektroakustiku', 36);
INSERT INTO orgjed(siforgjed, nazorgjed, sifnadorgjed)
  VALUES(100012, 'Centar informacijske potpore', 36);
INSERT INTO orgjed(siforgjed, nazorgjed, sifnadorgjed)
  VALUES(100017, 'Tajništvo', 36);
INSERT INTO orgjed(siforgjed, nazorgjed, sifnadorgjed)
  VALUES(100020, 'Raèunovodstvo', 100017);
INSERT INTO orgjed(siforgjed, nazorgjed, sifnadorgjed)
  VALUES(100013, 'Služba održavanja', 100017);
INSERT INTO orgjed(siforgjed, nazorgjed, sifnadorgjed)
  VALUES(100015, 'Studentska služba', 100017);
INSERT INTO orgjed(siforgjed, nazorgjed, sifnadorgjed)
  VALUES(100016, 'Opæa i kadrovska služba', 100017);
INSERT INTO orgjed(siforgjed, nazorgjed, sifnadorgjed)
  VALUES(100021, 'Bibliotekarska služba', 100017);
INSERT INTO orgjed(siforgjed, nazorgjed, sifnadorgjed)
  VALUES(100023, 'Grupa za fiziku', 100001);
INSERT INTO orgjed(siforgjed, nazorgjed, sifnadorgjed)
  VALUES(100024, 'Grupa fizikalnih osnova novih energetskih tehnologija', 100001);
INSERT INTO orgjed(siforgjed, nazorgjed, sifnadorgjed)
  VALUES(100025, 'Grupa za primijenjenu matematiku', 100002);
INSERT INTO orgjed(siforgjed, nazorgjed, sifnadorgjed)
  VALUES(100026, 'Grupa raèunarskih znanosti', 100002);
INSERT INTO orgjed(siforgjed, nazorgjed, sifnadorgjed)
  VALUES(100027, 'Grupa za osnove elektrotehnike', 100003);
INSERT INTO orgjed(siforgjed, nazorgjed, sifnadorgjed)
  VALUES(100028, 'Grupa za mjerenja u elektrotehnici', 100003);
INSERT INTO orgjed(siforgjed, nazorgjed, sifnadorgjed)
  VALUES(100029, 'Grupa za elektriène strojeve', 100004);
INSERT INTO orgjed(siforgjed, nazorgjed, sifnadorgjed)
  VALUES(100030, 'Grupa za regulaciju elektriènih strojeva', 100004);
INSERT INTO orgjed(siforgjed, nazorgjed, sifnadorgjed)
  VALUES(100031, 'Grupa za tehnologiju', 100004);
INSERT INTO orgjed(siforgjed, nazorgjed, sifnadorgjed)
  VALUES(100032, 'Grupa za mehanièke konstrukcije', 100004);
INSERT INTO orgjed(siforgjed, nazorgjed, sifnadorgjed)
  VALUES(100033, 'Grupa za elektriène aparate', 100004);
INSERT INTO orgjed(siforgjed, nazorgjed, sifnadorgjed)
  VALUES(100034, 'Grupa za energetsku elektroniku', 100004);
INSERT INTO orgjed(siforgjed, nazorgjed, sifnadorgjed)
  VALUES(100035, 'Grupa za elektrometriju', 36);
INSERT INTO orgjed(siforgjed, nazorgjed, sifnadorgjed)
  VALUES(100036, 'Grupa za elektriènu vuèu', 100004);
INSERT INTO orgjed(siforgjed, nazorgjed, sifnadorgjed)
  VALUES(100037, 'Grupa za metode organizacije', 36);
INSERT INTO orgjed(siforgjed, nazorgjed, sifnadorgjed)
  VALUES(100038, 'Grupa za elektrièna postrojenja', 100005);
INSERT INTO orgjed(siforgjed, nazorgjed, sifnadorgjed)
  VALUES(100039, 'Grupa za nuklearne elektrane', 100005);
INSERT INTO orgjed(siforgjed, nazorgjed, sifnadorgjed)
  VALUES(100040, 'Grupa za prijenos elektriène energije', 100005);
INSERT INTO orgjed(siforgjed, nazorgjed, sifnadorgjed)
  VALUES(100041, 'Grupa za elektriènu rasvjetu', 100005);
INSERT INTO orgjed(siforgjed, nazorgjed, sifnadorgjed)
  VALUES(100042, 'Grupa za elektriène željeznice', 100005);
INSERT INTO orgjed(siforgjed, nazorgjed, sifnadorgjed)
  VALUES(100043, 'Grupa za telekomunikacije i informatiku', 100006);
INSERT INTO orgjed(siforgjed, nazorgjed, sifnadorgjed)
  VALUES(100044, 'Grupa za mreže, sisteme i signale', 100007);
INSERT INTO orgjed(siforgjed, nazorgjed, sifnadorgjed)
  VALUES(100045, 'Grupa za elektronièka mjerenja i biomedicinsku elektroniku', 100007);
INSERT INTO orgjed(siforgjed, nazorgjed, sifnadorgjed)
  VALUES(100046, 'Grupa za automatsko upravljanje sistemima', 100008);
INSERT INTO orgjed(siforgjed, nazorgjed, sifnadorgjed)
  VALUES(100047, 'Grupa za raèunarske sisteme i procese', 100008);
INSERT INTO orgjed(siforgjed, nazorgjed, sifnadorgjed)
  VALUES(100048, 'Grupa za tonfrekvencijsku i prijemnièku elektroniku', 100009);
INSERT INTO orgjed(siforgjed, nazorgjed, sifnadorgjed)
  VALUES(100049, 'Grupa za akustiku i elektroakustiku', 100009);
INSERT INTO orgjed(siforgjed, nazorgjed, sifnadorgjed)
  VALUES(100050, 'Grupa za elektronièke sklopove', 100010);
INSERT INTO orgjed(siforgjed, nazorgjed, sifnadorgjed)
  VALUES(100051, 'Grupa za raèunarsku tehniku', 100010);
INSERT INTO orgjed(siforgjed, nazorgjed, sifnadorgjed)
  VALUES(100052, 'Grupa za radiokomunikacijske sustave', 100011);
INSERT INTO orgjed(siforgjed, nazorgjed, sifnadorgjed)
  VALUES(100053, 'Grupa za visokofrekvencijsku elektroniku', 100011);
INSERT INTO orgjed(siforgjed, nazorgjed, sifnadorgjed)
  VALUES(100054, 'Grupa za strani jezik', 100002);
INSERT INTO orgjed(siforgjed, nazorgjed, sifnadorgjed)
  VALUES(100062, 'Grupa za teoretsku elektrotehniku', 100003);
INSERT INTO orgjed(siforgjed, nazorgjed, sifnadorgjed)
  VALUES(100063, 'Grupa za energetsku elektrotehniku', 100004);
INSERT INTO orgjed(siforgjed, nazorgjed, sifnadorgjed)
  VALUES(100014, 'Zavod za primijenjeno raèunarstvo', 36);
INSERT INTO orgjed(siforgjed, nazorgjed, sifnadorgjed)
  VALUES(100010, 'Zavod za elektroniku, mikroelektroniku, raèunalne i inteligentne sustave', 36);
INSERT INTO orgjed(siforgjed, nazorgjed, sifnadorgjed)
  VALUES(100011, 'Zavod za radiokomunikacije', 36);


INSERT INTO predmet(sifpredmet, naziv, ectsbod, ukbrsatitjedno)
  VALUES(16, 'Osnove elektrotehnike', 7.0, 6);
INSERT INTO predmet(sifpredmet, naziv, ectsbod, ukbrsatitjedno)
  VALUES(24, 'Matematika 2', 7.0, 6);
INSERT INTO predmet(sifpredmet, naziv, ectsbod, ukbrsatitjedno)
  VALUES(26, 'Logièka algebra', 6.0, 6);
INSERT INTO predmet(sifpredmet, naziv, ectsbod, ukbrsatitjedno)
  VALUES(34, 'Fizika 1', 6.0, 6);
INSERT INTO predmet(sifpredmet, naziv, ectsbod, ukbrsatitjedno)
  VALUES(14, 'Programiranje i programsko inženjerstvo', 6.0, 5);
INSERT INTO predmet(sifpredmet, naziv, ectsbod, ukbrsatitjedno)
  VALUES(18, 'Operacijski sustavi', 7.0, 6);
INSERT INTO predmet(sifpredmet, naziv, ectsbod, ukbrsatitjedno)
  VALUES(4, 'Upravljanje kakvoæom', 3.0, 2);
INSERT INTO predmet(sifpredmet, naziv, ectsbod, ukbrsatitjedno)
  VALUES(38, 'Digitalni automati', 6.0, 5);
INSERT INTO predmet(sifpredmet, naziv, ectsbod, ukbrsatitjedno)
  VALUES(2, 'Višemedijske komunikacije', 3.0, 3);
INSERT INTO predmet(sifpredmet, naziv, ectsbod, ukbrsatitjedno)
  VALUES(3, 'Uvod u baze podataka', 6.0, 5);
INSERT INTO predmet(sifpredmet, naziv, ectsbod, ukbrsatitjedno)
  VALUES(29, 'Inteligentni sustavi', 6.0, 6);
INSERT INTO predmet(sifpredmet, naziv, ectsbod, ukbrsatitjedno)
  VALUES(32, 'Formalni postupci u oblikovanju raèunalnih sustava', 6.0, 6);
INSERT INTO predmet(sifpredmet, naziv, ectsbod, ukbrsatitjedno)
  VALUES(1, 'Vještine komuniciranja', 3.0, 2);
INSERT INTO predmet(sifpredmet, naziv, ectsbod, ukbrsatitjedno)
  VALUES(22, 'Matematika 3R', 5.0, 4);
INSERT INTO predmet(sifpredmet, naziv, ectsbod, ukbrsatitjedno)
  VALUES(30, 'Informacijske mreže', 6.0, 5);
INSERT INTO predmet(sifpredmet, naziv, ectsbod, ukbrsatitjedno)
  VALUES(33, 'Fizika 2', 6.0, 6);
INSERT INTO predmet(sifpredmet, naziv, ectsbod, ukbrsatitjedno)
  VALUES(36, 'Elektrièni krugovi', 7.0, 6);
INSERT INTO predmet(sifpredmet, naziv, ectsbod, ukbrsatitjedno)
  VALUES(46, 'Algoritmi i strukture podataka', 6.0, 5);
INSERT INTO predmet(sifpredmet, naziv, ectsbod, ukbrsatitjedno)
  VALUES(5, 'Transmisijski sustavi', 5.0, 5);
INSERT INTO predmet(sifpredmet, naziv, ectsbod, ukbrsatitjedno)
  VALUES(11, 'Seminar', 10.0, 4);
INSERT INTO predmet(sifpredmet, naziv, ectsbod, ukbrsatitjedno)
  VALUES(12, 'Raèunala i procesi', 5.0, 5);
INSERT INTO predmet(sifpredmet, naziv, ectsbod, ukbrsatitjedno)
  VALUES(20, 'Modeliranje i simuliranje', 6.0, 5);
INSERT INTO predmet(sifpredmet, naziv, ectsbod, ukbrsatitjedno)
  VALUES(17, 'Operacijski sustavi I', 6.0, 6);
INSERT INTO predmet(sifpredmet, naziv, ectsbod, ukbrsatitjedno)
  VALUES(23, 'Matematika 3E', 5.0, 4);
INSERT INTO predmet(sifpredmet, naziv, ectsbod, ukbrsatitjedno)
  VALUES(28, 'Komunikacijski protokoli', 5.0, 5);
INSERT INTO predmet(sifpredmet, naziv, ectsbod, ukbrsatitjedno)
  VALUES(37, 'Ekonomika', 2.0, 2);
INSERT INTO predmet(sifpredmet, naziv, ectsbod, ukbrsatitjedno)
  VALUES(40, 'Baze podataka', 5.0, 4);
INSERT INTO predmet(sifpredmet, naziv, ectsbod, ukbrsatitjedno)
  VALUES(19, 'Mreže raèunala', 6.0, 6);
INSERT INTO predmet(sifpredmet, naziv, ectsbod, ukbrsatitjedno)
  VALUES(25, 'Matematika 1', 7.0, 6);
INSERT INTO predmet(sifpredmet, naziv, ectsbod, ukbrsatitjedno)
  VALUES(6, 'Teorija prometa', 5.0, 5);
INSERT INTO predmet(sifpredmet, naziv, ectsbod, ukbrsatitjedno)
  VALUES(7, 'Teorija informacije', 6.0, 6);
INSERT INTO predmet(sifpredmet, naziv, ectsbod, ukbrsatitjedno)
  VALUES(8, 'Telematièke usluge', 5.0, 4);
INSERT INTO predmet(sifpredmet, naziv, ectsbod, ukbrsatitjedno)
  VALUES(13, 'Projektiranje digitalnih sustava', 7.0, 7);
INSERT INTO predmet(sifpredmet, naziv, ectsbod, ukbrsatitjedno)
  VALUES(15, 'Pouzdanost telekomunikacijskih sustava', 5.0, 5);
INSERT INTO predmet(sifpredmet, naziv, ectsbod, ukbrsatitjedno)
  VALUES(21, 'Menadžment u inženjerstvu', 3.0, 2);
INSERT INTO predmet(sifpredmet, naziv, ectsbod, ukbrsatitjedno)
  VALUES(27, 'Komutacijski sustavi', 5.0, 5);
INSERT INTO predmet(sifpredmet, naziv, ectsbod, ukbrsatitjedno)
  VALUES(41, 'Automati, formalni jezici i jezièni procesori II', 7.0, 6);
INSERT INTO predmet(sifpredmet, naziv, ectsbod, ukbrsatitjedno)
  VALUES(42, 'Automati, formalni jezici i jezièni procesori I', 6.0, 5);
INSERT INTO predmet(sifpredmet, naziv, ectsbod, ukbrsatitjedno)
  VALUES(45, 'Analiza i projektiranje raèunalom', 6.0, 6);
INSERT INTO predmet(sifpredmet, naziv, ectsbod, ukbrsatitjedno)
  VALUES(9, 'Telekomunikacijske mreže', 5.0, 4);
INSERT INTO predmet(sifpredmet, naziv, ectsbod, ukbrsatitjedno)
  VALUES(31, 'Informacija, logika, jezici', 5.0, 4);
INSERT INTO predmet(sifpredmet, naziv, ectsbod, ukbrsatitjedno)
  VALUES(10, 'Seminar', 12.0, 7);
INSERT INTO predmet(sifpredmet, naziv, ectsbod, ukbrsatitjedno)
  VALUES(35, 'Elektronika 1', 7.0, 6);
INSERT INTO predmet(sifpredmet, naziv, ectsbod, ukbrsatitjedno)
  VALUES(39, 'Digitalna logika', 6.0, 5);
INSERT INTO predmet(sifpredmet, naziv, ectsbod, ukbrsatitjedno)
  VALUES(43, 'Arhitektura raèunala 1', 6.0, 5);
INSERT INTO predmet(sifpredmet, naziv, ectsbod, ukbrsatitjedno)
  VALUES(44, 'Arhitektura i organizacija raèunala', 7.0, 6);
INSERT INTO predmet(sifpredmet, naziv, ectsbod, ukbrsatitjedno)
  VALUES(47, 'Industrijska praksa', 5.0, 5);
INSERT INTO predmet(sifpredmet, naziv, ectsbod, ukbrsatitjedno)
  VALUES(48, 'Elektrane - konstrukcijske vježbe', 6.0, 6);
INSERT INTO predmet(sifpredmet, naziv, ectsbod, ukbrsatitjedno)
  VALUES(49, 'Elektrièki strojevi II - konstrukcijske vježbe', 7.0, 7);
INSERT INTO predmet(sifpredmet, naziv, ectsbod, ukbrsatitjedno)
  VALUES(50, 'Elektroenergetske mreže I - konstrukcijske vježbe', 6.0, 6);
INSERT INTO predmet(sifpredmet, naziv, ectsbod, ukbrsatitjedno)
  VALUES(51, 'Elektroenergetske mreže II - konstrukcijske vježbe', 5.0, 5);
INSERT INTO predmet(sifpredmet, naziv, ectsbod, ukbrsatitjedno)
  VALUES(52, 'Elektroenergetski sistem - konstrukcijske vježbe', 5.0, 5);
INSERT INTO predmet(sifpredmet, naziv, ectsbod, ukbrsatitjedno)
  VALUES(53, 'Energetski izvori - konstrukcijske vježbe', 6.0, 6);
INSERT INTO predmet(sifpredmet, naziv, ectsbod, ukbrsatitjedno)
  VALUES(54, 'Energetski sistemi i bilance - konstrukcijske vježbe', 7.0, 7);
INSERT INTO predmet(sifpredmet, naziv, ectsbod, ukbrsatitjedno)
  VALUES(55, 'Rasklopna postrojenja - konstrukcijske vježbe', 6.0, 6);
INSERT INTO predmet(sifpredmet, naziv, ectsbod, ukbrsatitjedno)
  VALUES(56, 'Razvod elektriène energije - konstrukcijske vježbe', 5.0, 5);
INSERT INTO predmet(sifpredmet, naziv, ectsbod, ukbrsatitjedno)
  VALUES(57, 'Sinkroni strojevi - konstrukcijske vježbe', 5.0, 5);
INSERT INTO predmet(sifpredmet, naziv, ectsbod, ukbrsatitjedno)
  VALUES(58, 'Upravljanje u EE sistemu - konstrukcijske vježbe', 6.0, 6);
INSERT INTO predmet(sifpredmet, naziv, ectsbod, ukbrsatitjedno)
  VALUES(59, 'Elektrièni strojevi III - konstrukcijske vježbe', 7.0, 7);
INSERT INTO predmet(sifpredmet, naziv, ectsbod, ukbrsatitjedno)
  VALUES(60, 'Mehanièke konstrukcije - konstrukcijske vježbe', 6.0, 6);
INSERT INTO predmet(sifpredmet, naziv, ectsbod, ukbrsatitjedno)
  VALUES(61, 'Osnove teorije nuklearnog reaktora - konstrukcijske vježbe', 5.0, 5);
INSERT INTO predmet(sifpredmet, naziv, ectsbod, ukbrsatitjedno)
  VALUES(62, 'Tehnièko dokumentiranje', 3.0, 3);
INSERT INTO predmet(sifpredmet, naziv, ectsbod, ukbrsatitjedno)
  VALUES(63, 'Laboratorij za detekciju i zaštitu od zraèenja', 6.0, 6);
INSERT INTO predmet(sifpredmet, naziv, ectsbod, ukbrsatitjedno)
  VALUES(64, 'Znanost o religijama', 2.0, 2);
INSERT INTO predmet(sifpredmet, naziv, ectsbod, ukbrsatitjedno)
  VALUES(65, 'Hrvatska kultura i civilizacija', 2.0, 2);
INSERT INTO predmet(sifpredmet, naziv, ectsbod, ukbrsatitjedno)
  VALUES(66, 'Okruženje managementa', 2.0, 2);


INSERT INTO grupa(akgodina, ozngrupa, kapacitet)
  VALUES(2003, 'C-A1', 30);
INSERT INTO grupa(akgodina, ozngrupa, kapacitet)
  VALUES(2003, 'C-A2', 30);
INSERT INTO grupa(akgodina, ozngrupa, kapacitet)
  VALUES(2003, 'C-A3', 30);
INSERT INTO grupa(akgodina, ozngrupa, kapacitet)
  VALUES(2003, 'C-A4', 30);
INSERT INTO grupa(akgodina, ozngrupa, kapacitet)
  VALUES(2003, 'C-A5', 30);
INSERT INTO grupa(akgodina, ozngrupa, kapacitet)
  VALUES(2003, 'C-B1', 30);
INSERT INTO grupa(akgodina, ozngrupa, kapacitet)
  VALUES(2003, 'C-B2', 30);
INSERT INTO grupa(akgodina, ozngrupa, kapacitet)
  VALUES(2003, 'C-B3', 30);
INSERT INTO grupa(akgodina, ozngrupa, kapacitet)
  VALUES(2003, 'C-B4', 30);
INSERT INTO grupa(akgodina, ozngrupa, kapacitet)
  VALUES(2003, 'C-B5', 30);
INSERT INTO grupa(akgodina, ozngrupa, kapacitet)
  VALUES(2003, 'D-A1', 20);
INSERT INTO grupa(akgodina, ozngrupa, kapacitet)
  VALUES(2003, 'D-A2', 20);
INSERT INTO grupa(akgodina, ozngrupa, kapacitet)
  VALUES(2003, 'D-A3', 20);
INSERT INTO grupa(akgodina, ozngrupa, kapacitet)
  VALUES(2003, 'D-A4', 20);
INSERT INTO grupa(akgodina, ozngrupa, kapacitet)
  VALUES(2003, 'D-A5', 20);
INSERT INTO grupa(akgodina, ozngrupa, kapacitet)
  VALUES(2003, 'D-B1', 20);
INSERT INTO grupa(akgodina, ozngrupa, kapacitet)
  VALUES(2003, 'D-B2', 20);
INSERT INTO grupa(akgodina, ozngrupa, kapacitet)
  VALUES(2003, 'D-B3', 20);
INSERT INTO grupa(akgodina, ozngrupa, kapacitet)
  VALUES(2003, 'D-B4', 20);
INSERT INTO grupa(akgodina, ozngrupa, kapacitet)
  VALUES(2003, 'D-B5', 20);
INSERT INTO grupa(akgodina, ozngrupa, kapacitet)
  VALUES(2004, 'C-A1', 30);
INSERT INTO grupa(akgodina, ozngrupa, kapacitet)
  VALUES(2004, 'C-A2', 30);
INSERT INTO grupa(akgodina, ozngrupa, kapacitet)
  VALUES(2004, 'C-A3', 30);
INSERT INTO grupa(akgodina, ozngrupa, kapacitet)
  VALUES(2004, 'C-A4', 30);
INSERT INTO grupa(akgodina, ozngrupa, kapacitet)
  VALUES(2004, 'C-A5', 30);
INSERT INTO grupa(akgodina, ozngrupa, kapacitet)
  VALUES(2004, 'C-B1', 30);
INSERT INTO grupa(akgodina, ozngrupa, kapacitet)
  VALUES(2004, 'C-B2', 30);
INSERT INTO grupa(akgodina, ozngrupa, kapacitet)
  VALUES(2004, 'C-B3', 30);
INSERT INTO grupa(akgodina, ozngrupa, kapacitet)
  VALUES(2004, 'C-B4', 30);
INSERT INTO grupa(akgodina, ozngrupa, kapacitet)
  VALUES(2004, 'C-B5', 30);
INSERT INTO grupa(akgodina, ozngrupa, kapacitet)
  VALUES(2004, 'D-A1', 20);
INSERT INTO grupa(akgodina, ozngrupa, kapacitet)
  VALUES(2004, 'D-A2', 20);
INSERT INTO grupa(akgodina, ozngrupa, kapacitet)
  VALUES(2004, 'D-A3', 20);
INSERT INTO grupa(akgodina, ozngrupa, kapacitet)
  VALUES(2004, 'D-A4', 20);
INSERT INTO grupa(akgodina, ozngrupa, kapacitet)
  VALUES(2004, 'D-A5', 20);
INSERT INTO grupa(akgodina, ozngrupa, kapacitet)
  VALUES(2004, 'D-A6', 20);
INSERT INTO grupa(akgodina, ozngrupa, kapacitet)
  VALUES(2004, 'D-B1', 20);
INSERT INTO grupa(akgodina, ozngrupa, kapacitet)
  VALUES(2004, 'D-B2', 20);
INSERT INTO grupa(akgodina, ozngrupa, kapacitet)
  VALUES(2004, 'D-B3', 20);
INSERT INTO grupa(akgodina, ozngrupa, kapacitet)
  VALUES(2004, 'D-B4', 20);
INSERT INTO grupa(akgodina, ozngrupa, kapacitet)
  VALUES(2004, 'D-B5', 20);
INSERT INTO grupa(akgodina, ozngrupa, kapacitet)
  VALUES(2004, 'D-C1', 20);
INSERT INTO grupa(akgodina, ozngrupa, kapacitet)
  VALUES(2004, 'D-E1', 20);
INSERT INTO grupa(akgodina, ozngrupa, kapacitet)
  VALUES(2004, 'D-F1', 20);
INSERT INTO grupa(akgodina, ozngrupa, kapacitet)
  VALUES(2004, 'D-G1', 20);
INSERT INTO grupa(akgodina, ozngrupa, kapacitet)
  VALUES(2004, 'D-H1', 20);
INSERT INTO grupa(akgodina, ozngrupa, kapacitet)
  VALUES(2004, 'D-I1', 20);
INSERT INTO grupa(akgodina, ozngrupa, kapacitet)
  VALUES(2004, 'D-I2', 20);
INSERT INTO grupa(akgodina, ozngrupa, kapacitet)
  VALUES(2005, 'A-A', 40);
INSERT INTO grupa(akgodina, ozngrupa, kapacitet)
  VALUES(2005, 'A-B', 40);
INSERT INTO grupa(akgodina, ozngrupa, kapacitet)
  VALUES(2005, 'A-C', 40);
INSERT INTO grupa(akgodina, ozngrupa, kapacitet)
  VALUES(2005, 'A-D', 40);
INSERT INTO grupa(akgodina, ozngrupa, kapacitet)
  VALUES(2005, 'A-E', 40);
INSERT INTO grupa(akgodina, ozngrupa, kapacitet)
  VALUES(2005, 'A-F', 40);
INSERT INTO grupa(akgodina, ozngrupa, kapacitet)
  VALUES(2005, 'A-G', 40);
INSERT INTO grupa(akgodina, ozngrupa, kapacitet)
  VALUES(2005, 'A-H', 40);
INSERT INTO grupa(akgodina, ozngrupa, kapacitet)
  VALUES(2005, 'A-I', 40);
INSERT INTO grupa(akgodina, ozngrupa, kapacitet)
  VALUES(2005, 'A-J', 40);
INSERT INTO grupa(akgodina, ozngrupa, kapacitet)
  VALUES(2005, 'A-K', 40);
INSERT INTO grupa(akgodina, ozngrupa, kapacitet)
  VALUES(2005, 'A-L', 40);
INSERT INTO grupa(akgodina, ozngrupa, kapacitet)
  VALUES(2005, 'A-M', 40);
INSERT INTO grupa(akgodina, ozngrupa, kapacitet)
  VALUES(2005, 'A-N', 40);
INSERT INTO grupa(akgodina, ozngrupa, kapacitet)
  VALUES(2005, 'C-A1', 30);
INSERT INTO grupa(akgodina, ozngrupa, kapacitet)
  VALUES(2005, 'C-A2', 30);
INSERT INTO grupa(akgodina, ozngrupa, kapacitet)
  VALUES(2005, 'C-A3', 30);
INSERT INTO grupa(akgodina, ozngrupa, kapacitet)
  VALUES(2005, 'C-A4', 30);
INSERT INTO grupa(akgodina, ozngrupa, kapacitet)
  VALUES(2005, 'C-A5', 30);
INSERT INTO grupa(akgodina, ozngrupa, kapacitet)
  VALUES(2005, 'C-B1', 30);
INSERT INTO grupa(akgodina, ozngrupa, kapacitet)
  VALUES(2005, 'C-B2', 30);
INSERT INTO grupa(akgodina, ozngrupa, kapacitet)
  VALUES(2005, 'C-B3', 30);
INSERT INTO grupa(akgodina, ozngrupa, kapacitet)
  VALUES(2005, 'C-B4', 30);
INSERT INTO grupa(akgodina, ozngrupa, kapacitet)
  VALUES(2005, 'C-B5', 30);
INSERT INTO grupa(akgodina, ozngrupa, kapacitet)
  VALUES(2005, 'D-A1', 20);
INSERT INTO grupa(akgodina, ozngrupa, kapacitet)
  VALUES(2005, 'D-A2', 20);
INSERT INTO grupa(akgodina, ozngrupa, kapacitet)
  VALUES(2005, 'D-A3', 20);
INSERT INTO grupa(akgodina, ozngrupa, kapacitet)
  VALUES(2005, 'D-A4', 20);
INSERT INTO grupa(akgodina, ozngrupa, kapacitet)
  VALUES(2005, 'D-A5', 20);
INSERT INTO grupa(akgodina, ozngrupa, kapacitet)
  VALUES(2005, 'D-B1', 20);
INSERT INTO grupa(akgodina, ozngrupa, kapacitet)
  VALUES(2005, 'D-B2', 20);
INSERT INTO grupa(akgodina, ozngrupa, kapacitet)
  VALUES(2005, 'D-B3', 20);
INSERT INTO grupa(akgodina, ozngrupa, kapacitet)
  VALUES(2005, 'D-B4', 20);
INSERT INTO grupa(akgodina, ozngrupa, kapacitet)
  VALUES(2005, 'D-B5', 20);
INSERT INTO grupa(akgodina, ozngrupa, kapacitet)
  VALUES(2005, 'D-C1', 20);
INSERT INTO grupa(akgodina, ozngrupa, kapacitet)
  VALUES(2005, 'D-E1', 20);
INSERT INTO grupa(akgodina, ozngrupa, kapacitet)
  VALUES(2005, 'D-F1', 20);
INSERT INTO grupa(akgodina, ozngrupa, kapacitet)
  VALUES(2005, 'D-G1', 20);
INSERT INTO grupa(akgodina, ozngrupa, kapacitet)
  VALUES(2005, 'D-H1', 20);
INSERT INTO grupa(akgodina, ozngrupa, kapacitet)
  VALUES(2005, 'D-I1', 20);
INSERT INTO grupa(akgodina, ozngrupa, kapacitet)
  VALUES(2005, 'D-I2', 20);
INSERT INTO grupa(akgodina, ozngrupa, kapacitet)
  VALUES(2006, 'A-A', 40);
INSERT INTO grupa(akgodina, ozngrupa, kapacitet)
  VALUES(2006, 'A-B', 40);
INSERT INTO grupa(akgodina, ozngrupa, kapacitet)
  VALUES(2006, 'A-C', 40);
INSERT INTO grupa(akgodina, ozngrupa, kapacitet)
  VALUES(2006, 'A-D', 40);
INSERT INTO grupa(akgodina, ozngrupa, kapacitet)
  VALUES(2006, 'A-E', 40);
INSERT INTO grupa(akgodina, ozngrupa, kapacitet)
  VALUES(2006, 'A-F', 40);
INSERT INTO grupa(akgodina, ozngrupa, kapacitet)
  VALUES(2006, 'A-G', 40);
INSERT INTO grupa(akgodina, ozngrupa, kapacitet)
  VALUES(2006, 'A-H', 40);
INSERT INTO grupa(akgodina, ozngrupa, kapacitet)
  VALUES(2006, 'A-I', 40);
INSERT INTO grupa(akgodina, ozngrupa, kapacitet)
  VALUES(2006, 'A-J', 40);
INSERT INTO grupa(akgodina, ozngrupa, kapacitet)
  VALUES(2006, 'A-K', 40);
INSERT INTO grupa(akgodina, ozngrupa, kapacitet)
  VALUES(2006, 'A-L', 40);
INSERT INTO grupa(akgodina, ozngrupa, kapacitet)
  VALUES(2006, 'A-M', 40);
INSERT INTO grupa(akgodina, ozngrupa, kapacitet)
  VALUES(2006, 'A-N', 40);
INSERT INTO grupa(akgodina, ozngrupa, kapacitet)
  VALUES(2006, 'A-O', 40);
INSERT INTO grupa(akgodina, ozngrupa, kapacitet)
  VALUES(2006, 'B-A', 40);
INSERT INTO grupa(akgodina, ozngrupa, kapacitet)
  VALUES(2006, 'B-B', 40);
INSERT INTO grupa(akgodina, ozngrupa, kapacitet)
  VALUES(2006, 'B-C', 40);
INSERT INTO grupa(akgodina, ozngrupa, kapacitet)
  VALUES(2006, 'B-D', 40);
INSERT INTO grupa(akgodina, ozngrupa, kapacitet)
  VALUES(2006, 'B-E', 40);
INSERT INTO grupa(akgodina, ozngrupa, kapacitet)
  VALUES(2006, 'B-F', 40);
INSERT INTO grupa(akgodina, ozngrupa, kapacitet)
  VALUES(2006, 'B-G', 40);
INSERT INTO grupa(akgodina, ozngrupa, kapacitet)
  VALUES(2006, 'B-H', 40);
INSERT INTO grupa(akgodina, ozngrupa, kapacitet)
  VALUES(2006, 'B-I', 40);
INSERT INTO grupa(akgodina, ozngrupa, kapacitet)
  VALUES(2006, 'B-J', 40);
INSERT INTO grupa(akgodina, ozngrupa, kapacitet)
  VALUES(2006, 'B-K', 40);
INSERT INTO grupa(akgodina, ozngrupa, kapacitet)
  VALUES(2006, 'C-A1', 30);
INSERT INTO grupa(akgodina, ozngrupa, kapacitet)
  VALUES(2006, 'C-A2', 30);
INSERT INTO grupa(akgodina, ozngrupa, kapacitet)
  VALUES(2006, 'C-A3', 30);
INSERT INTO grupa(akgodina, ozngrupa, kapacitet)
  VALUES(2006, 'C-A4', 30);
INSERT INTO grupa(akgodina, ozngrupa, kapacitet)
  VALUES(2006, 'C-A5', 30);
INSERT INTO grupa(akgodina, ozngrupa, kapacitet)
  VALUES(2006, 'C-B1', 30);
INSERT INTO grupa(akgodina, ozngrupa, kapacitet)
  VALUES(2006, 'C-B2', 30);
INSERT INTO grupa(akgodina, ozngrupa, kapacitet)
  VALUES(2006, 'C-B3', 30);
INSERT INTO grupa(akgodina, ozngrupa, kapacitet)
  VALUES(2006, 'C-B4', 30);
INSERT INTO grupa(akgodina, ozngrupa, kapacitet)
  VALUES(2006, 'C-B5', 30);
INSERT INTO grupa(akgodina, ozngrupa, kapacitet)
  VALUES(2006, 'D-A1', 20);
INSERT INTO grupa(akgodina, ozngrupa, kapacitet)
  VALUES(2006, 'D-A2', 20);
INSERT INTO grupa(akgodina, ozngrupa, kapacitet)
  VALUES(2006, 'D-A3', 20);
INSERT INTO grupa(akgodina, ozngrupa, kapacitet)
  VALUES(2006, 'D-A4', 20);
INSERT INTO grupa(akgodina, ozngrupa, kapacitet)
  VALUES(2006, 'D-A5', 20);
INSERT INTO grupa(akgodina, ozngrupa, kapacitet)
  VALUES(2006, 'D-B1', 20);
INSERT INTO grupa(akgodina, ozngrupa, kapacitet)
  VALUES(2006, 'D-B2', 20);
INSERT INTO grupa(akgodina, ozngrupa, kapacitet)
  VALUES(2006, 'D-B3', 20);
INSERT INTO grupa(akgodina, ozngrupa, kapacitet)
  VALUES(2006, 'D-B4', 20);
INSERT INTO grupa(akgodina, ozngrupa, kapacitet)
  VALUES(2006, 'D-B5', 20);


INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555000011', 'Krešimir', 'Salopek', '0101980554687', 'M', EXTEND(MDY(1,1,1980), YEAR to SECOND), NULL, NULL);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555000027', 'Andrej', 'Jurèiæ', '0101980554318', 'M', EXTEND(MDY(1,1,1980), YEAR to SECOND), NULL, 10000);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555000032', 'Adonis', 'Miæiæ', '0102980551099', 'M', EXTEND(MDY(2,1,1980), YEAR to SECOND), 44320, 44320);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555000048', 'Krešimir', 'Vagiæ', '0103979551197', 'M', EXTEND(MDY(3,1,1979), YEAR to SECOND), NULL, 10000);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555000053', 'Hrvoje', 'Korkut', '0106976553767', 'M', EXTEND(MDY(6,1,1976), YEAR to SECOND), NULL, NULL);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555000069', 'Siniša', 'Bet', '0106980550152', 'M', EXTEND(MDY(6,1,1980), YEAR to SECOND), NULL, NULL);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555000074', 'Hrvoje', 'Buneta', '0107972553238', 'M', EXTEND(MDY(7,1,1972), YEAR to SECOND), NULL, NULL);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555000095', 'Vladimir', 'Mušanoviæ', '0107979552229', 'M', EXTEND(MDY(7,1,1979), YEAR to SECOND), NULL, NULL);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555000102', 'Ivor', 'Purkoviæ', '0102978552959', 'M', EXTEND(MDY(2,1,1978), YEAR to SECOND), NULL, NULL);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555000118', 'Maroje', 'Klepiæ', '0103978552106', 'M', EXTEND(MDY(3,1,1978), YEAR to SECOND), NULL, NULL);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555000123', 'Tomislav', 'Lipovac', '0103978552963', 'M', EXTEND(MDY(3,1,1978), YEAR to SECOND), NULL, NULL);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555000139', 'Vedran', 'Kauzlariæ', '0104979552955', 'M', EXTEND(MDY(4,1,1979), YEAR to SECOND), NULL, NULL);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555000144', 'Tonei', 'Matkoviæ', '0105971552286', 'M', EXTEND(MDY(5,1,1971), YEAR to SECOND), NULL, NULL);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555000165', 'Ozren', 'Jurèeviæ', '0105978552281', 'M', EXTEND(MDY(5,1,1978), YEAR to SECOND), 10000, NULL);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555000170', 'Lobell', 'Æubeliæ', '0106977552217', 'M', EXTEND(MDY(6,1,1977), YEAR to SECOND), NULL, NULL);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555000186', 'Kristijan', 'Paškoto', '0107977552523', 'M', EXTEND(MDY(7,1,1977), YEAR to SECOND), NULL, NULL);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555000191', 'Vladimir', 'Mihelèiæ', '0107978552276', 'M', EXTEND(MDY(7,1,1978), YEAR to SECOND), NULL, NULL);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555000209', 'Bojan', 'Pepelar', '0107980552216', 'M', EXTEND(MDY(7,1,1980), YEAR to SECOND), NULL, NULL);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555000214', 'Vedran', 'Žuža', '0106977552969', 'M', EXTEND(MDY(6,1,1977), YEAR to SECOND), NULL, NULL);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555000235', 'Tomislav', 'Štimac', '0105974552295', 'M', EXTEND(MDY(5,1,1974), YEAR to SECOND), NULL, NULL);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555000240', 'Marko', 'Janežiæ', '0104973554069', 'M', EXTEND(MDY(4,1,1973), YEAR to SECOND), NULL, NULL);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555000256', 'Davor', 'Pahliæ', '0104974552361', 'M', EXTEND(MDY(4,1,1974), YEAR to SECOND), NULL, NULL);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555000261', 'Srðan', 'Tkalèec', '0103979551367', 'M', EXTEND(MDY(3,1,1979), YEAR to SECOND), NULL, NULL);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555000277', 'Mate', 'Maras', '0103976552966', 'M', EXTEND(MDY(3,1,1976), YEAR to SECOND), NULL, NULL);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555000282', 'Dejan', 'Makarun', '0106976552108', 'M', EXTEND(MDY(6,1,1976), YEAR to SECOND), NULL, NULL);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555000298', 'Marko', 'Prkaèin', '0107971552971', 'M', EXTEND(MDY(7,1,1971), YEAR to SECOND), NULL, NULL);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555000305', 'Kristijan', 'Koriæ', '0103975552369', 'M', EXTEND(MDY(3,1,1975), YEAR to SECOND), NULL, NULL);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555000310', 'Tomislav', 'Pauloviæ', '0104974552299', 'M', EXTEND(MDY(4,1,1974), YEAR to SECOND), NULL, NULL);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555000326', 'Mario', 'Ivanšiæ', '0107976552961', 'M', EXTEND(MDY(7,1,1976), YEAR to SECOND), NULL, NULL);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555000331', 'Ognjen', 'Muževiæ', '0105975552965', 'M', EXTEND(MDY(5,1,1975), YEAR to SECOND), NULL, NULL);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555000347', 'Dinko', 'Pleško', '0102973554848', 'M', EXTEND(MDY(2,1,1973), YEAR to SECOND), NULL, NULL);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555000352', 'Marko', 'Karloviæ', '0105973554316', 'M', EXTEND(MDY(5,1,1973), YEAR to SECOND), NULL, NULL);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555000368', 'Igor', 'Peraniæ', '0105975551098', 'M', EXTEND(MDY(5,1,1975), YEAR to SECOND), NULL, NULL);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555000373', 'Ivan', 'Ded', '0101974552214', 'M', EXTEND(MDY(1,1,1974), YEAR to SECOND), NULL, NULL);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555000389', 'Nikica', 'Vidoviæ', '0105981552225', 'M', EXTEND(MDY(5,1,1981), YEAR to SECOND), NULL, NULL);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555000394', 'Krunoslav', 'Kiršiæ', '0104981553233', 'M', EXTEND(MDY(4,1,1981), YEAR to SECOND), NULL, NULL);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555000401', 'Hrvoje', 'Vego', '0103981552109', 'M', EXTEND(MDY(3,1,1981), YEAR to SECOND), NULL, NULL);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555000417', 'Tomislav', 'Makar', '0106980552228', 'M', EXTEND(MDY(6,1,1980), YEAR to SECOND), NULL, NULL);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555000422', 'Igor', 'Cigiæ', '0103980552288', 'M', EXTEND(MDY(3,1,1980), YEAR to SECOND), 22320, NULL);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555000438', 'Marko', 'Èop', '0103981550157', 'M', EXTEND(MDY(12,1,1980), YEAR to SECOND), NULL, NULL);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555000443', 'Neven', 'Kolariæ', '0107982553899', 'M', EXTEND(MDY(7,1,1982), YEAR to SECOND), 10000, 10340);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555000459', 'Domagoj', 'Topiæ', '0102982554508', 'M', EXTEND(MDY(2,1,1982), YEAR to SECOND), 33000, 10000);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555000464', 'Marko', 'Ravnik', '0106982552985', 'M', EXTEND(MDY(6,1,1982), YEAR to SECOND), NULL, NULL);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555000485', 'Ante', 'Milièiæ', '0105982552253', 'M', EXTEND(MDY(5,1,1982), YEAR to SECOND), 10000, 10000);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555000490', 'Branimir', 'Dragièeviæ', '0408982552892', 'M', EXTEND(MDY(8,4,1982), YEAR to SECOND), 42000, 10000);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555000508', 'Zlatko', 'Matas', '1507983552421', 'M', EXTEND(MDY(7,15,1983), YEAR to SECOND), 48260, 10000);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555000513', 'Simon', 'Glavan', '0112965550138', 'M', EXTEND(MDY(12,1,1965), YEAR to SECOND), 23000, 10000);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555000529', 'Krunoslav', 'Ðukiæ', '0408973553339', 'M', EXTEND(MDY(8,4,1973), YEAR to SECOND), 32000, 10000);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555000534', 'Krešimir', 'Dujmoviæ', '0105975553473', 'M', EXTEND(MDY(5,1,1975), YEAR to SECOND), 23000, 10000);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555000555', 'Krešo', 'Glad', '0803975552247', 'M', EXTEND(MDY(3,8,1975), YEAR to SECOND), 48000, 10040);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555000560', 'Pavle', 'Stankoviæ', '2209976551358', 'M', EXTEND(MDY(9,22,1976), YEAR to SECOND), 49210, 10000);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555000576', 'Krešimir', 'Rodiæ', '0104977552249', 'M', EXTEND(MDY(4,1,1977), YEAR to SECOND), NULL, NULL);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555000581', 'Ninoslav', 'Brajkoviæ', '1504978553763', 'M', EXTEND(MDY(4,15,1978), YEAR to SECOND), 10000, 10000);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555000597', 'Tihomir', 'Æikoviæ', '1212978552928', 'M', EXTEND(MDY(12,12,1978), YEAR to SECOND), 10000, 10000);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555000604', 'Maja', 'Splait', '2401979552248', 'M', EXTEND(MDY(1,24,1979), YEAR to SECOND), 10000, 10000);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555000625', 'Ivan', 'Grahovac', '1907979552385', 'M', EXTEND(MDY(7,19,1979), YEAR to SECOND), 21000, 10000);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555000630', 'Dragutin', 'Miškulin', '1903978554079', 'M', EXTEND(MDY(3,19,1978), YEAR to SECOND), 10000, 10000);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555000646', 'Danijel', 'Medica', '3107979550146', 'M', EXTEND(MDY(7,31,1979), YEAR to SECOND), 31000, 10000);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555000651', 'Gordan', 'Miljeviæ', '1409979550137', 'M', EXTEND(MDY(9,14,1979), YEAR to SECOND), 23000, 10000);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555000667', 'Ante', 'Veliæ', '2112979552408', 'M', EXTEND(MDY(12,21,1979), YEAR to SECOND), 42250, 10000);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555000672', 'Hrvoje', 'Fabris', '1210979551078', 'M', EXTEND(MDY(10,12,1979), YEAR to SECOND), 10000, 34340);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555000688', 'Tomislav', 'Glavièiæ', '0201980552972', 'M', EXTEND(MDY(1,2,1980), YEAR to SECOND), 10000, 10090);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555000693', 'Egon', 'Jurkoviæ', '3107979554079', 'M', EXTEND(MDY(7,31,1979), YEAR to SECOND), 10000, 22320);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555000700', 'Zrinoslav', 'Huziak', '0307980552274', 'M', EXTEND(MDY(7,3,1980), YEAR to SECOND), 10000, 10000);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555000716', 'Amir', 'Torbarina', '1907976551337', 'M', EXTEND(MDY(7,19,1976), YEAR to SECOND), 51000, 10000);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555000721', 'Melko', 'Lipovac', '1509980550102', 'M', EXTEND(MDY(9,15,1980), YEAR to SECOND), 22320, 10000);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555000737', 'Domagoj', 'Zlojutro', '1807981552347', 'M', EXTEND(MDY(7,18,1981), YEAR to SECOND), 21000, NULL);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555000742', 'Mario', 'Vidaèiæ', '1604981553736', 'M', EXTEND(MDY(4,16,1981), YEAR to SECOND), 52100, 10000);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555000758', 'Radoslav', 'Velièan', '1310980550152', 'M', EXTEND(MDY(10,13,1980), YEAR to SECOND), 31000, NULL);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555000763', 'Krešimir', 'Kovrlija', '1003981552906', 'M', EXTEND(MDY(3,10,1981), YEAR to SECOND), 10000, 10000);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555000779', 'Daniel', 'Lekiæ', '2401981552336', 'M', EXTEND(MDY(1,24,1981), YEAR to SECOND), 47000, 10000);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555000784', 'Saša', 'Krajnoviæ', '0510980552975', 'M', EXTEND(MDY(10,5,1980), YEAR to SECOND), 10000, 10020);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555000807', 'Krešimir', 'Dusper', '2412980552946', 'M', EXTEND(MDY(12,24,1980), YEAR to SECOND), 31500, 10000);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555000812', 'Luka', 'Maturanec', '1605980551361', 'M', EXTEND(MDY(5,16,1980), YEAR to SECOND), 42250, 10360);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555000828', 'Antonio', 'Bitanga', '0405981552989', 'M', EXTEND(MDY(5,4,1981), YEAR to SECOND), 10000, 10000);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555000833', 'Marko', 'Èaèiæ', '2403980552076', 'M', EXTEND(MDY(3,24,1980), YEAR to SECOND), 47240, 10000);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555000849', 'Ivo', 'Zriliæ', '1012980552332', 'M', EXTEND(MDY(12,10,1980), YEAR to SECOND), 48260, 10000);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555000854', 'Tomislav-Ivan', 'Rukavina', '1603981552253', 'M', EXTEND(MDY(3,16,1981), YEAR to SECOND), 10000, 10000);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555000875', 'Krešimir', 'Demo', '1501981552914', 'M', EXTEND(MDY(1,15,1981), YEAR to SECOND), 10000, 10000);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555000880', 'Tonei', 'Lovriæ', '0307980552983', 'M', EXTEND(MDY(7,3,1980), YEAR to SECOND), 10000, NULL);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555000896', 'Marijo', 'Štefulinac', '1103982551169', 'M', EXTEND(MDY(3,11,1982), YEAR to SECOND), 31500, NULL);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555000903', 'Goran', 'Dragoviæ-Cetniski', '0902982554709', 'M', EXTEND(MDY(2,9,1982), YEAR to SECOND), 34000, NULL);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555000919', 'Tin', 'Zlopaša', '0209982551923', 'M', EXTEND(MDY(9,2,1982), YEAR to SECOND), 34000, NULL);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555000924', 'Martin', 'Klanjèiæ', '2110981552293', 'M', EXTEND(MDY(10,21,1981), YEAR to SECOND), 10000, 10000);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555000945', 'Vjekoslav', 'KOLONIÆ', '2901982550135', 'M', EXTEND(MDY(1,29,1982), YEAR to SECOND), 23000, NULL);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555000950', 'Mijo', 'Klasiæ', '2207982550131', 'M', EXTEND(MDY(7,22,1982), YEAR to SECOND), 23000, 23000);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555000966', 'Ivan', 'Pauliæ', '2310981552527', 'M', EXTEND(MDY(10,23,1981), YEAR to SECOND), 43280, 43280);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555000971', 'Mislav', 'Zuzzi', '1212981550138', 'M', EXTEND(MDY(12,12,1981), YEAR to SECOND), 31000, NULL);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555000987', 'Vladimir', 'Bura', '1212981552998', 'M', EXTEND(MDY(12,12,1981), YEAR to SECOND), 47000, 10000);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555000992', 'Vedran', 'Franèiškoviæ', '1103982552246', 'M', EXTEND(MDY(3,11,1982), YEAR to SECOND), 10000, 10000);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555001003', 'Domagoj', 'Glavaš', '0311981552976', 'M', EXTEND(MDY(11,3,1981), YEAR to SECOND), 10000, 10020);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555001019', 'Mario', 'Karabaiæ', '1103982552297', 'M', EXTEND(MDY(3,11,1982), YEAR to SECOND), 42250, 10000);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555001024', 'Zoran', 'Tuk', '2102982552529', 'M', EXTEND(MDY(2,21,1982), YEAR to SECOND), 10000, 10290);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555001045', 'Aleksandar', 'Hrešiæ', '1911981551075', 'M', EXTEND(MDY(11,19,1981), YEAR to SECOND), 10000, 10430);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555001050', 'Filip', 'Drakuliæ', '0710981553451', 'M', EXTEND(MDY(10,7,1981), YEAR to SECOND), 23000, NULL);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555001066', 'Ivan', 'Kabalin', '0405981552415', 'M', EXTEND(MDY(5,4,1981), YEAR to SECOND), 42250, 10000);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555001071', 'Boris', 'Orliæ', '3108982552253', 'M', EXTEND(MDY(8,31,1982), YEAR to SECOND), 10000, 10000);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555001087', 'Dražen', 'Chiole', '0101982552967', 'M', EXTEND(MDY(1,1,1982), YEAR to SECOND), 10000, 10000);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555001092', 'Josip', 'Janeš', '1507982552967', 'M', EXTEND(MDY(7,15,1982), YEAR to SECOND), 10000, 10000);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555001115', 'Marko', 'Harapin', '0305982552317', 'M', EXTEND(MDY(5,3,1982), YEAR to SECOND), 10000, 10000);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555001120', 'Dubravko', 'Zamliæ', '2903982551762', 'M', EXTEND(MDY(3,29,1982), YEAR to SECOND), 10000, NULL);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555001136', 'Radovan', 'Maruna', '1309982552383', 'M', EXTEND(MDY(9,13,1982), YEAR to SECOND), 21000, 10000);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555001141', 'Darko', 'Kopljar', '2609981552395', 'M', EXTEND(MDY(9,26,1981), YEAR to SECOND), 21000, NULL);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555001157', 'Zvonimir', 'Perica', '2208983550336', 'M', EXTEND(MDY(8,22,1983), YEAR to SECOND), 22000, 10000);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555001162', 'Ivan', 'Maljiæ', '0104983553249', 'M', EXTEND(MDY(4,1,1983), YEAR to SECOND), 44000, 10000);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555001178', 'Dalibor', 'Miheliæ', '1903983553722', 'M', EXTEND(MDY(3,19,1983), YEAR to SECOND), 52100, NULL);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555001183', 'Jerko', 'Begiæ', '0202983550195', 'M', EXTEND(MDY(2,2,1983), YEAR to SECOND), 31000, 10000);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555001199', 'Damir', 'Mužiæ', '2205983554049', 'M', EXTEND(MDY(5,22,1983), YEAR to SECOND), 33000, 10000);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555001206', 'Dario', 'Zagriæ', '2401983552430', 'M', EXTEND(MDY(1,24,1983), YEAR to SECOND), 47240, 10000);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555001211', 'Damir', 'Faèini', '3012982550156', 'M', EXTEND(MDY(12,30,1982), YEAR to SECOND), 31000, NULL);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555001227', 'Dejan', 'Bakiæ', '0103983550138', 'M', EXTEND(MDY(3,1,1983), YEAR to SECOND), 23000, NULL);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555001232', 'Danijel', 'Mariæ', '2505983553321', 'M', EXTEND(MDY(5,25,1983), YEAR to SECOND), 32000, NULL);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555001248', 'Genadij', 'Skomina', '0604983552245', 'M', EXTEND(MDY(4,6,1983), YEAR to SECOND), 35000, NULL);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555001253', 'Mladen', 'Markoviæ', '0407983552202', 'M', EXTEND(MDY(7,4,1983), YEAR to SECOND), 10000, 49247);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555001269', 'Slobodan', 'Czerny', '1112982550978', 'M', EXTEND(MDY(12,11,1982), YEAR to SECOND), 48000, 10000);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555001274', 'Marko', 'Milanoviæ', '2009981553149', 'M', EXTEND(MDY(9,20,1981), YEAR to SECOND), 48000, 10000);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555001295', 'Filip', 'Šoštariæ', '2711982552223', 'M', EXTEND(MDY(11,27,1982), YEAR to SECOND), 35000, 35000);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555001302', 'Marko', 'Poropat', '0403983552312', 'M', EXTEND(MDY(3,4,1983), YEAR to SECOND), 10000, 10000);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555001318', 'Branimir', 'Kukiæ', '2402983552291', 'M', EXTEND(MDY(2,24,1983), YEAR to SECOND), 10000, 10000);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555001323', 'Dalibor', 'Stepanèiæ', '1111982552958', 'M', EXTEND(MDY(11,11,1982), YEAR to SECOND), 10000, 10000);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555001339', 'Fran', 'Èebuhar', '1001983552935', 'M', EXTEND(MDY(1,10,1983), YEAR to SECOND), 10000, 10000);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555001344', 'Seden', 'Grguriæ', '0909982552913', 'M', EXTEND(MDY(9,9,1982), YEAR to SECOND), 10000, NULL);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555001365', 'Hrvoje', 'Pribaniæ', '2101983552178', 'M', EXTEND(MDY(1,21,1983), YEAR to SECOND), 49210, 49221);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555001370', 'Vedran', 'Uzelac', '2409982552918', 'M', EXTEND(MDY(9,24,1982), YEAR to SECOND), 10000, NULL);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555001386', 'Matija', 'Penaviæ', '1107982550141', 'M', EXTEND(MDY(7,11,1982), YEAR to SECOND), 31000, 10000);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555001391', 'Marko', 'Hulusija', '2407982550335', 'M', EXTEND(MDY(7,24,1982), YEAR to SECOND), 22000, 10000);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555001409', 'Miran', 'Cvikiæ', '1810983551128', 'M', EXTEND(MDY(10,18,1983), YEAR to SECOND), 31500, NULL);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555001414', 'Fililp', 'Blaževiæ', '2010982552136', 'M', EXTEND(MDY(10,20,1982), YEAR to SECOND), 48000, NULL);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555001435', 'Vedran', 'Biga', '0105983554047', 'M', EXTEND(MDY(5,1,1983), YEAR to SECOND), 33000, 10000);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555001440', 'Boris', 'Dujmoviæ', '3001983552975', 'M', EXTEND(MDY(1,30,1983), YEAR to SECOND), 10000, NULL);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555001456', 'Ivan', 'Malnar', '2903983552215', 'M', EXTEND(MDY(3,29,1983), YEAR to SECOND), 10000, NULL);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555001461', 'Nikša', 'Kraguljac', '0810982552968', 'M', EXTEND(MDY(10,8,1982), YEAR to SECOND), 10000, NULL);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555001477', 'Jurij', 'Zuboviæ', '2005983552179', 'M', EXTEND(MDY(5,20,1983), YEAR to SECOND), 49210, 10000);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555001482', 'Nikola', 'Lešiæ', '0306984553929', 'M', EXTEND(MDY(6,3,1984), YEAR to SECOND), 42000, 10000);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555001498', 'Miroslav', 'Matiješeviæ', '1707982552907', 'M', EXTEND(MDY(7,17,1982), YEAR to SECOND), 10000, 10000);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555001505', 'Igor', 'Garbajs Nikolac', '2610982552893', 'M', EXTEND(MDY(10,26,1982), YEAR to SECOND), 42000, 10000);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555001510', 'Marin', 'Palle', '1804983552116', 'M', EXTEND(MDY(4,18,1983), YEAR to SECOND), 40000, 10000);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555001526', 'Goran', 'Brala', '2209982554717', 'M', EXTEND(MDY(9,22,1982), YEAR to SECOND), 34000, 10000);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555001531', 'Mirza', 'Jurèiæ', '1702983551236', 'M', EXTEND(MDY(2,17,1983), YEAR to SECOND), 47000, 10000);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555001547', 'Domagoj', 'Šimuniæ', '2812982550329', 'M', EXTEND(MDY(12,28,1982), YEAR to SECOND), 22000, 10000);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555001552', 'Krešo', 'Fumiæ', '2206983552298', 'M', EXTEND(MDY(6,22,1983), YEAR to SECOND), 10000, 34340);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555001568', 'Ivan', 'Rašetina', '2001983550162', 'M', EXTEND(MDY(1,20,1983), YEAR to SECOND), 31000, 10000);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555001573', 'Valentin', 'Tevanoviæ', '1108983554066', 'M', EXTEND(MDY(8,11,1983), YEAR to SECOND), 33000, 10000);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555001589', 'Igor', 'Vanèina', '0409984552268', 'M', EXTEND(MDY(9,4,1984), YEAR to SECOND), 21000, 10000);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555001594', 'Luka', 'Grguriæ', '3007983551241', 'M', EXTEND(MDY(7,30,1983), YEAR to SECOND), 47000, 47000);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555001601', 'Bojan', 'Bataljaku', '2203984550168', 'M', EXTEND(MDY(3,22,1984), YEAR to SECOND), 23000, 23205);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555001617', 'Jan', 'Èemeljiæ', '1402984552925', 'M', EXTEND(MDY(2,14,1984), YEAR to SECOND), 10000, 10310);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555001622', 'Željko', 'Gobo', '3009983552224', 'M', EXTEND(MDY(9,30,1983), YEAR to SECOND), 35000, 10000);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555001638', 'Davor', 'Barkiæ', '0912983552233', 'M', EXTEND(MDY(12,9,1983), YEAR to SECOND), 35000, 10000);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555001643', 'Domagoj', 'Orliæ', '2110983552924', 'M', EXTEND(MDY(10,21,1983), YEAR to SECOND), 10000, 10000);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555001659', 'Dario', 'Paviæ', '1305983552284', 'M', EXTEND(MDY(5,13,1983), YEAR to SECOND), 21000, 10000);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555001664', 'Goran', 'Pravdica', '2304984553222', 'M', EXTEND(MDY(4,23,1984), YEAR to SECOND), 44000, 10000);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555001685', 'Matija', 'Krtiniæ', '0302984554059', 'M', EXTEND(MDY(2,3,1984), YEAR to SECOND), 33000, 10000);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555001690', 'Domagoj', 'Maraviæ', '0908983552961', 'M', EXTEND(MDY(8,9,1983), YEAR to SECOND), 10000, 10000);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555001708', 'Boris', 'Barièeviæ', '0711983550979', 'M', EXTEND(MDY(11,7,1983), YEAR to SECOND), 48000, 10000);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555001713', 'Joško', 'Blažiæ', '1310983550153', 'M', EXTEND(MDY(10,13,1983), YEAR to SECOND), 23000, 10000);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555001729', 'Gregor', 'Hrelja', '0311983552264', 'M', EXTEND(MDY(11,3,1983), YEAR to SECOND), 10000, 10000);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555001734', 'Mario', 'Kos', '2405984554718', 'M', EXTEND(MDY(5,24,1984), YEAR to SECOND), 34000, 10000);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555001755', 'Krunoslav', 'Smiloviæ', '2701984552926', 'M', EXTEND(MDY(1,27,1984), YEAR to SECOND), 10000, 10000);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555001760', 'Ivan', 'Žuvela', '2905983552927', 'M', EXTEND(MDY(5,29,1983), YEAR to SECOND), 32100, 10000);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555001776', 'Damir', 'Ban', '1510983552457', 'M', EXTEND(MDY(10,15,1983), YEAR to SECOND), 42250, 10000);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555001781', 'Matej', 'Kuštriæ', '2012983553945', 'M', EXTEND(MDY(12,20,1983), YEAR to SECOND), 42000, 10000);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555001797', 'Slavko', 'Vehar', '0910983552907', 'M', EXTEND(MDY(10,9,1983), YEAR to SECOND), 10000, 10000);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555001804', 'Nikola', 'Šikiæ', '1112983554713', 'M', EXTEND(MDY(12,11,1983), YEAR to SECOND), 34000, 10000);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555001825', 'Domagoj', 'Jukiæ', '2802984552323', 'M', EXTEND(MDY(2,28,1984), YEAR to SECOND), 10000, 10000);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555001830', 'Slaven', 'Florijan', '0410983552335', 'M', EXTEND(MDY(10,4,1983), YEAR to SECOND), 10000, 10000);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555001846', 'Ivan', 'Brezac Radovan', '3103984552232', 'M', EXTEND(MDY(3,31,1984), YEAR to SECOND), 10000, 10000);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555001851', 'Domagoj', 'Gušæiæ', '1604984552927', 'M', EXTEND(MDY(4,16,1984), YEAR to SECOND), 10000, 10000);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555001867', 'Frane', 'Kopunoviæ', '2301984553797', 'M', EXTEND(MDY(1,23,1984), YEAR to SECOND), 43000, 10000);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555001872', 'Ivan', 'Kuèan', '2304984554326', 'M', EXTEND(MDY(4,23,1984), YEAR to SECOND), 52100, 10000);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555001888', 'Slaviša', 'Vretenar', '0601984552231', 'M', EXTEND(MDY(1,6,1984), YEAR to SECOND), 10000, 10000);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555001893', 'Robert', 'Filipoviæ', '1003983552946', 'M', EXTEND(MDY(3,10,1983), YEAR to SECOND), 10000, 10000);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555001900', 'Danijel', 'Milin', '1102984552956', 'M', EXTEND(MDY(2,11,1984), YEAR to SECOND), 10000, 10410);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555001916', 'Goran', 'Slaviæ', '0505984552437', 'M', EXTEND(MDY(5,5,1984), YEAR to SECOND), 21220, 10000);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555001921', 'Kamilo', 'Banko', '2308983552929', 'M', EXTEND(MDY(8,23,1983), YEAR to SECOND), 10000, 10000);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555001937', 'Tomislav', 'Devèiæ', '0711983553919', 'M', EXTEND(MDY(11,7,1983), YEAR to SECOND), 42000, 10000);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555001942', 'Vedran', 'Blažiæ', '0511983552913', 'M', EXTEND(MDY(11,5,1983), YEAR to SECOND), 10000, 10000);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555001958', 'Goran', 'Jovanoviæ', '1307983553771', 'M', EXTEND(MDY(7,13,1983), YEAR to SECOND), 43000, 10000);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555001963', 'Vedran', 'Jurinèiæ', '0309983552316', 'M', EXTEND(MDY(9,3,1983), YEAR to SECOND), 10000, 10000);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555001979', 'Filip', 'Grgiæ', '0508983551231', 'M', EXTEND(MDY(8,5,1983), YEAR to SECOND), 47000, 10000);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555001984', 'Ivana', 'Kokanoviæ', '2205984552198', 'M', EXTEND(MDY(5,22,1984), YEAR to SECOND), 49210, 10000);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555002000', 'Dino', 'Zohil', '1405984553874', 'M', EXTEND(MDY(5,14,1984), YEAR to SECOND), 20000, 10000);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555002016', 'Martin', 'Koševiæ', '2012983550172', 'M', EXTEND(MDY(12,20,1983), YEAR to SECOND), 23000, 10000);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555002021', 'Slaven', 'Svetiæ', '2707983550979', 'M', EXTEND(MDY(7,27,1983), YEAR to SECOND), 48000, 10000);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555002037', 'Marko', 'Lukanoviæ', '0312983554859', 'M', EXTEND(MDY(12,3,1983), YEAR to SECOND), 21300, 10000);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555002042', 'Neven', 'Marinac', '1608983550705', 'M', EXTEND(MDY(8,16,1983), YEAR to SECOND), 51000, 10000);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555002058', 'Hilarije', 'Jakaša', '1610984552218', 'M', EXTEND(MDY(10,16,1984), YEAR to SECOND), 10000, 10000);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555002063', 'Vlado', 'Šikiæ', '0412984552242', 'M', EXTEND(MDY(12,4,1984), YEAR to SECOND), 10000, 10000);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555002079', 'Marko', 'Nosiæ', '0309985552356', 'M', EXTEND(MDY(9,3,1985), YEAR to SECOND), 21000, 10000);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555002084', 'Bruno', 'Šarlija', '2806984552345', 'M', EXTEND(MDY(6,28,1984), YEAR to SECOND), 21000, 10000);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555002107', 'Ivan', 'Jardas', '1911984554946', 'M', EXTEND(MDY(11,19,1984), YEAR to SECOND), 20350, 10000);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555002112', 'Karlo', 'Oklobdžija', '1712984550328', 'M', EXTEND(MDY(12,17,1984), YEAR to SECOND), 22000, 10000);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555002128', 'Sanjin', 'Matešiæ', '1709984553849', 'M', EXTEND(MDY(9,17,1984), YEAR to SECOND), 20000, 10000);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555002133', 'Krešimir', 'Èandrliæ', '1704985550167', 'M', EXTEND(MDY(4,17,1985), YEAR to SECOND), 31000, 10000);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555002149', 'Josip', 'Damljanoviæ', '1204985553767', 'M', EXTEND(MDY(4,12,1985), YEAR to SECOND), 43000, 10000);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555002154', 'Ivan', 'Mavar', '0309984552379', 'M', EXTEND(MDY(9,3,1984), YEAR to SECOND), 21000, 10000);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555002175', 'Samir', 'Sankoviæ', '1512984552291', 'M', EXTEND(MDY(12,15,1984), YEAR to SECOND), 10000, 10000);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555002180', 'Jan', 'Vojinoviæ', '1011984554074', 'M', EXTEND(MDY(11,10,1984), YEAR to SECOND), 33000, 10000);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555002196', 'Bruno', 'Travalja', '2206984552984', 'M', EXTEND(MDY(6,22,1984), YEAR to SECOND), 10000, 10410);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555002203', 'Marko', 'Štefanèiæ', '1205985552228', 'M', EXTEND(MDY(5,12,1985), YEAR to SECOND), 10000, 10000);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555002219', 'Ivan', 'Švast', '1008984552933', 'M', EXTEND(MDY(8,10,1984), YEAR to SECOND), 10000, 10000);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555002224', 'Mislav', 'Šakiæ', '0502985552377', 'M', EXTEND(MDY(2,5,1985), YEAR to SECOND), 10000, 10000);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555002245', 'Davor', 'Poropat', '2509984550151', 'M', EXTEND(MDY(9,25,1984), YEAR to SECOND), 23000, NULL);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555002250', 'Tomislav', 'Tomiæ', '2809984552972', 'M', EXTEND(MDY(9,28,1984), YEAR to SECOND), 10000, 10000);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555002266', 'Goran', 'Vilušiæ', '2505985550338', 'M', EXTEND(MDY(5,25,1985), YEAR to SECOND), 22000, 10000);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555002271', 'Neven', 'Paladin', '0405984552467', 'M', EXTEND(MDY(5,4,1984), YEAR to SECOND), 21000, 10000);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555002287', 'Marko', 'Èabrijan', '2308984552566', 'M', EXTEND(MDY(8,23,1984), YEAR to SECOND), 44320, 10000);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555002292', 'Ivan', 'Buzdakin', '0204985550144', 'M', EXTEND(MDY(4,2,1985), YEAR to SECOND), 23000, 10000);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555002315', 'Petar', 'Miškoviæ', '0203985551837', 'M', EXTEND(MDY(3,2,1985), YEAR to SECOND), 21220, 10000);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555002320', 'Ivan', 'Vrcelj', '2601985552216', 'M', EXTEND(MDY(1,26,1985), YEAR to SECOND), 10000, 10000);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555002336', 'Damir', 'Raduloviæ', '0612984552519', 'M', EXTEND(MDY(12,6,1984), YEAR to SECOND), 43280, 43280);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555002341', 'Vjekoslav', 'Gajiæ', '0712985550123', 'M', EXTEND(MDY(12,7,1985), YEAR to SECOND), 31000, 33405);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555002357', 'Bojan', 'Bariæ', '3112984554323', 'M', EXTEND(MDY(12,31,1984), YEAR to SECOND), 52100, 10000);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555002362', 'Franko', 'Ðakoviæ', '2709984552102', 'M', EXTEND(MDY(9,27,1984), YEAR to SECOND), 10000, 10000);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555002378', 'Domagoj', 'Legoviæ', '2210984553465', 'M', EXTEND(MDY(10,22,1984), YEAR to SECOND), 48000, 10000);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555002383', 'Tomislav', 'Klaus', '2001984551790', 'M', EXTEND(MDY(1,20,1984), YEAR to SECOND), 47240, 10000);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555002399', 'Josip', 'Èirjak', '2405985552948', 'M', EXTEND(MDY(5,24,1985), YEAR to SECOND), 10000, 10000);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555002406', 'Marko', 'Kušmiæ', '0602985552177', 'M', EXTEND(MDY(2,6,1985), YEAR to SECOND), 49210, 10000);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555002411', 'Goran', 'Erjavec', '0804985553841', 'M', EXTEND(MDY(4,8,1985), YEAR to SECOND), 20000, 20000);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555002427', 'Samy', 'Ljubièiæ', '1205985552244', 'M', EXTEND(MDY(5,12,1985), YEAR to SECOND), 10000, 49000);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555002432', 'Ivan', 'Jurjeviæ', '2708984553846', 'M', EXTEND(MDY(8,27,1984), YEAR to SECOND), 20000, 10000);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555002448', 'Filip', 'Sabiæ', '2405985552247', 'M', EXTEND(MDY(5,24,1985), YEAR to SECOND), 10000, 10000);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555002453', 'Boris', 'Æuruvija', '2109984552938', 'M', EXTEND(MDY(9,21,1984), YEAR to SECOND), 10000, 10000);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555002469', 'Zoran', 'Studen', '0302984552234', 'M', EXTEND(MDY(2,3,1984), YEAR to SECOND), 51000, 10000);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555002474', 'Ivor', 'Pavletiæ', '2211984552988', 'M', EXTEND(MDY(11,22,1984), YEAR to SECOND), 10000, 10000);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555002495', 'Jakov', 'Božiæ', '0809984554048', 'M', EXTEND(MDY(9,8,1984), YEAR to SECOND), 33000, 10000);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555002502', 'Ivan', 'Božiæ', '2605985552173', 'M', EXTEND(MDY(5,26,1985), YEAR to SECOND), 49210, 49210);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555002518', 'Marko', 'Keseroviæ', '1109984552241', 'M', EXTEND(MDY(9,11,1984), YEAR to SECOND), 10000, 10000);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555002523', 'Matej', 'Šuæuroviæ', '2105985552235', 'M', EXTEND(MDY(5,21,1985), YEAR to SECOND), 10000, 10000);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555002539', 'Nikica', 'Grbèiæ', '2203985552903', 'M', EXTEND(MDY(3,22,1985), YEAR to SECOND), 10000, 10000);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555002544', 'Damir', 'Prpiæ', '0211984552255', 'M', EXTEND(MDY(11,2,1984), YEAR to SECOND), 10000, 10000);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555002565', 'Eugen', 'Pobor', '2306984552261', 'M', EXTEND(MDY(6,23,1984), YEAR to SECOND), 10000, 10000);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555002570', 'Viktor', 'Levar', '1808984552255', 'M', EXTEND(MDY(8,18,1984), YEAR to SECOND), 10000, 10000);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555002586', 'Hrvoje', 'Draževiæ', '2802984552277', 'M', EXTEND(MDY(2,28,1984), YEAR to SECOND), 10000, 49210);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555002591', 'Ivan', 'Bundalo', '1909984552213', 'M', EXTEND(MDY(9,19,1984), YEAR to SECOND), 10000, 10000);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555002609', 'Marko', 'Barešiæ', '1103985552271', 'M', EXTEND(MDY(3,11,1985), YEAR to SECOND), 10000, 10000);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555002614', 'Mijo', 'Vidiè', '1406984552246', 'M', EXTEND(MDY(6,14,1984), YEAR to SECOND), 10000, 10000);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555002635', 'Dario', 'Stevanèeviæ', '0410984552355', 'M', EXTEND(MDY(10,4,1984), YEAR to SECOND), 10000, 10000);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555002640', 'Nikola', 'Miljenoviæ', '0909984552430', 'M', EXTEND(MDY(9,9,1984), YEAR to SECOND), 48260, 10000);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555002656', 'Mate', 'Mariæ', '2404985552232', 'M', EXTEND(MDY(4,24,1985), YEAR to SECOND), 10000, 10000);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555002661', 'Nikica', 'Veljkoviæ', '0411984552297', 'M', EXTEND(MDY(11,4,1984), YEAR to SECOND), 35000, 10000);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555002677', 'Antun', 'Valinger', '1810985554515', 'M', EXTEND(MDY(10,18,1985), YEAR to SECOND), 42250, NULL);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555002682', 'Domagoj', 'Radiæ', '2612985550339', 'M', EXTEND(MDY(12,26,1985), YEAR to SECOND), 22000, NULL);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555002698', 'Marijan', 'Kostelenski', '0512985551236', 'M', EXTEND(MDY(12,5,1985), YEAR to SECOND), 47000, NULL);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555002705', 'Željko', 'Ivkoviæ', '0901986552348', 'M', EXTEND(MDY(1,9,1986), YEAR to SECOND), 21000, NULL);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555002710', 'Ivo', 'Surian', '1703985550136', 'M', EXTEND(MDY(3,17,1985), YEAR to SECOND), 31000, NULL);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555002726', 'Alen', 'Rogiæ', '1204986553841', 'M', EXTEND(MDY(4,12,1986), YEAR to SECOND), 20000, 10000);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555002731', 'Siniša', 'Karaula', '2706985550163', 'M', EXTEND(MDY(6,27,1985), YEAR to SECOND), 23000, NULL);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555002747', 'Josip', 'Bajac', '2612985551319', 'M', EXTEND(MDY(12,26,1985), YEAR to SECOND), 51000, NULL);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555002752', 'Toma', 'Jusufagiæ', '0603985553323', 'M', EXTEND(MDY(3,6,1985), YEAR to SECOND), 32000, NULL);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555002768', 'Tomislav', 'Privileggio', '1008985552988', 'M', EXTEND(MDY(8,10,1985), YEAR to SECOND), 32100, NULL);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555002773', 'Janko', 'Margetiæ', '1002985553218', 'M', EXTEND(MDY(2,10,1985), YEAR to SECOND), 44000, NULL);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555002789', 'Marija', 'Jeliæ', '1111985551782', 'M', EXTEND(MDY(11,11,1985), YEAR to SECOND), 48260, NULL);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555002794', 'Antonio', 'Butkoviæ', '2901985550187', 'M', EXTEND(MDY(1,29,1985), YEAR to SECOND), 43280, 43280);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555002801', 'Toni', 'Jerman', '3007985552385', 'M', EXTEND(MDY(7,30,1985), YEAR to SECOND), 21000, NULL);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555002817', 'Marko', 'Žepina', '0607985552314', 'M', EXTEND(MDY(7,6,1985), YEAR to SECOND), 10000, NULL);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555002822', 'Mario', 'Grenko', '0505985552945', 'M', EXTEND(MDY(5,5,1985), YEAR to SECOND), 10000, NULL);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555002838', 'Boris', 'Jermaniš', '1610985552408', 'M', EXTEND(MDY(10,16,1985), YEAR to SECOND), 48260, NULL);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555002843', 'Hrvoje', 'Bevandiæ', '0409985554868', 'M', EXTEND(MDY(9,4,1985), YEAR to SECOND), 21300, 10000);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555002859', 'Josip', 'Buriæ', '1004986553257', 'M', EXTEND(MDY(4,10,1986), YEAR to SECOND), 44000, NULL);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555002864', 'Davor', 'Budimir', '2306986552242', 'M', EXTEND(MDY(6,23,1986), YEAR to SECOND), 10000, NULL);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555002885', 'Matija', 'Tonkoviæ', '1411985552332', 'M', EXTEND(MDY(11,14,1985), YEAR to SECOND), 48260, NULL);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555002890', 'Predrag', 'Kraljiæ', '0509985550123', 'M', EXTEND(MDY(9,5,1985), YEAR to SECOND), 31000, NULL);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555002908', 'Benedikt', 'Radan', '2409985552269', 'M', EXTEND(MDY(9,24,1985), YEAR to SECOND), 10000, NULL);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555002913', 'David', 'Sankoviæ', '1304986552173', 'M', EXTEND(MDY(4,13,1986), YEAR to SECOND), 49210, NULL);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555002929', 'Hrvoje', 'Butorac', '1311985552923', 'M', EXTEND(MDY(11,13,1985), YEAR to SECOND), 10000, 10000);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555002934', 'Nikola', 'Barun', '0807985552135', 'M', EXTEND(MDY(7,8,1985), YEAR to SECOND), 21220, NULL);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555002955', 'Štefan', 'Kostelac', '0508985552286', 'M', EXTEND(MDY(8,5,1985), YEAR to SECOND), 48260, NULL);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555002960', 'Uroš', 'Srzentiæ', '2002985553815', 'M', EXTEND(MDY(2,20,1985), YEAR to SECOND), 33405, NULL);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555002976', 'Marko', 'Grliæ', '1403986552953', 'M', EXTEND(MDY(3,14,1986), YEAR to SECOND), 10000, NULL);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555002981', 'Jurica', 'Vidušin', '2807986552357', 'M', EXTEND(MDY(7,28,1986), YEAR to SECOND), 21000, NULL);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555002997', 'Ivan', 'Gvero', '2412985552278', 'M', EXTEND(MDY(12,24,1985), YEAR to SECOND), 47240, NULL);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555003008', 'Gorki', 'Gavriæ', '0705986550155', 'M', EXTEND(MDY(5,7,1986), YEAR to SECOND), 23000, NULL);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555003013', 'Antonijo', 'Æikoviæ', '2410985552216', 'M', EXTEND(MDY(10,24,1985), YEAR to SECOND), 10000, NULL);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555003029', 'Ivica', 'Bernardi', '2207986552287', 'M', EXTEND(MDY(7,22,1986), YEAR to SECOND), 10000, NULL);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555003034', 'Žarko', 'Pribaniæ', '0801986552947', 'M', EXTEND(MDY(1,8,1986), YEAR to SECOND), 10000, NULL);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555003055', 'Zoltan', 'Lampe', '2509985550139', 'M', EXTEND(MDY(9,25,1985), YEAR to SECOND), 23000, NULL);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555003060', 'Miroslav', 'Smiljaniæ', '2502986553773', 'M', EXTEND(MDY(2,25,1986), YEAR to SECOND), 43000, NULL);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555003076', 'Radovan', 'Rupèiæ', '1806987552369', 'M', EXTEND(MDY(6,18,1987), YEAR to SECOND), 21000, 10000);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555003081', 'Ivor', 'Lonèar', '1512986554615', 'M', EXTEND(MDY(12,15,1986), YEAR to SECOND), 51000, 51550);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555003097', 'Ivan', 'Kolenc', '1411986554312', 'M', EXTEND(MDY(11,14,1986), YEAR to SECOND), 52100, NULL);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555003104', 'Ivan', 'Gregoran', '0204987554953', 'M', EXTEND(MDY(4,2,1987), YEAR to SECOND), 20350, NULL);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555003125', 'Smajil', 'Franèiæ', '1303987553738', 'M', EXTEND(MDY(3,13,1987), YEAR to SECOND), 52100, NULL);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555003130', 'Tomislav', 'Crnokrak', '0812986553228', 'M', EXTEND(MDY(12,8,1986), YEAR to SECOND), 42250, NULL);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555003146', 'Ozren', 'Ratoša', '2005986552102', 'M', EXTEND(MDY(5,20,1986), YEAR to SECOND), 10000, NULL);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555003151', 'Ranko', 'Radiæ', '0705986552271', 'M', EXTEND(MDY(5,7,1986), YEAR to SECOND), 40305, NULL);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555003167', 'Jure', 'Linardiæ', '1110986552247', 'M', EXTEND(MDY(10,11,1986), YEAR to SECOND), 35000, NULL);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555003172', 'Hrvoje', 'Karas', '2811986552400', 'M', EXTEND(MDY(11,28,1986), YEAR to SECOND), 47240, NULL);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555003188', 'Goran', 'Dujmoviæ', '0210986552396', 'M', EXTEND(MDY(10,2,1986), YEAR to SECOND), 47240, NULL);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555003193', 'Petar', 'Perica', '1611986552971', 'M', EXTEND(MDY(11,16,1986), YEAR to SECOND), 10000, NULL);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555003200', 'Matija', 'Ðuriæ', '0706987552247', 'M', EXTEND(MDY(6,7,1987), YEAR to SECOND), 10000, 10000);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555003216', 'Ivan', 'Cerovac', '0204987552349', 'M', EXTEND(MDY(4,2,1987), YEAR to SECOND), 10000, NULL);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555003221', 'Luka', 'Maruna', '0205987552299', 'M', EXTEND(MDY(5,2,1987), YEAR to SECOND), 47240, NULL);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555003237', 'Igor', 'Kariæ', '0410986552271', 'M', EXTEND(MDY(10,4,1986), YEAR to SECOND), 10000, NULL);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555003242', 'Tomislav', 'Jeliniæ', '2808986551861', 'M', EXTEND(MDY(8,28,1986), YEAR to SECOND), 21230, NULL);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555003258', 'Dražen', 'Gomojiæ', '2804987552106', 'M', EXTEND(MDY(4,28,1987), YEAR to SECOND), 48260, NULL);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555003263', 'Ivan', 'Oštariæ', '1709986550324', 'M', EXTEND(MDY(9,17,1986), YEAR to SECOND), 22000, NULL);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555003279', 'Ljudevit', 'Kapoviæ', '2806987551188', 'M', EXTEND(MDY(6,28,1987), YEAR to SECOND), 40000, NULL);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555003284', 'Mislav', 'Èabrijan', '0511986552957', 'M', EXTEND(MDY(11,5,1986), YEAR to SECOND), 10000, NULL);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555003307', 'Nikola', 'Smokoviæ', '1208986552204', 'M', EXTEND(MDY(8,12,1986), YEAR to SECOND), 10000, NULL);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555003312', 'Martin', 'Jurièiæ', '1609986552454', 'M', EXTEND(MDY(9,16,1986), YEAR to SECOND), 21000, NULL);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555003328', 'Zvonimir', 'Mustaæ', '2408986552932', 'M', EXTEND(MDY(8,24,1986), YEAR to SECOND), 10000, NULL);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555003333', 'Vojko', 'Maljèec', '2102987550133', 'M', EXTEND(MDY(2,21,1987), YEAR to SECOND), 48260, NULL);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555003349', 'Goran', 'Bujan', '2808986552914', 'M', EXTEND(MDY(8,28,1986), YEAR to SECOND), 10000, NULL);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555003354', 'Luka', 'Pikuliæ', '1704987554844', 'M', EXTEND(MDY(4,17,1987), YEAR to SECOND), 21300, NULL);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555003375', 'Damir', 'Mohorac', '0406986551375', 'M', EXTEND(MDY(6,4,1986), YEAR to SECOND), 47240, NULL);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555003380', 'Tomislav', 'Mandiæ', '3006986552307', 'M', EXTEND(MDY(6,30,1986), YEAR to SECOND), 47240, NULL);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555003396', 'Vedran', 'Maletiæ', '0505986554313', 'M', EXTEND(MDY(5,5,1986), YEAR to SECOND), 52100, NULL);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555003403', 'Mate', 'Dukiæ', '0606986552974', 'M', EXTEND(MDY(6,6,1986), YEAR to SECOND), 10000, NULL);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555003419', 'Toma', 'Verbiè', '2103987552965', 'M', EXTEND(MDY(3,21,1987), YEAR to SECOND), 10000, NULL);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555003424', 'Andrija', 'Miletiæ', '2910986552921', 'M', EXTEND(MDY(10,29,1986), YEAR to SECOND), 10000, NULL);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555003445', 'Tomislav', 'Kardum', '0402987552981', 'M', EXTEND(MDY(2,4,1987), YEAR to SECOND), 10000, NULL);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555003450', 'Marko', 'Juriæ', '0812986552906', 'M', EXTEND(MDY(12,8,1986), YEAR to SECOND), 10000, NULL);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555003466', 'Izvor', 'Gruloviæ', '2802987553762', 'M', EXTEND(MDY(2,28,1987), YEAR to SECOND), 43000, NULL);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555003471', 'Ivan', 'Kardum', '0411986552278', 'M', EXTEND(MDY(11,4,1986), YEAR to SECOND), 10000, NULL);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555003487', 'Dušan', 'Zebiæ', '0108986553865', 'M', EXTEND(MDY(8,1,1986), YEAR to SECOND), 20000, NULL);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555003492', 'Marko', 'Runko', '2702987552249', 'M', EXTEND(MDY(2,27,1987), YEAR to SECOND), 10000, NULL);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555003515', 'Ivan', 'Peraniæ', '2103987551233', 'M', EXTEND(MDY(3,21,1987), YEAR to SECOND), 47000, NULL);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555003520', 'Luka', 'Mareniæ', '0209986552258', 'M', EXTEND(MDY(9,2,1986), YEAR to SECOND), 10000, NULL);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555003536', 'Hrvoje', 'Livadiæ', '1808986552287', 'M', EXTEND(MDY(8,18,1986), YEAR to SECOND), 10000, NULL);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555003541', 'Jurica', 'Vigan', '2306986552285', 'M', EXTEND(MDY(6,23,1986), YEAR to SECOND), 10000, NULL);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555003557', 'Krešimir', 'Sikiriæ', '2608986550130', 'M', EXTEND(MDY(8,26,1986), YEAR to SECOND), 47240, NULL);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555003562', 'Ivan', 'Kovaèiæ', '1510986552288', 'M', EXTEND(MDY(10,15,1986), YEAR to SECOND), 10000, NULL);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555003578', 'Darjan', 'Zebiæ', '0611986552315', 'M', EXTEND(MDY(11,6,1986), YEAR to SECOND), 10000, NULL);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555003583', 'Bojan', 'Ražnjeviæ', '1108986553257', 'M', EXTEND(MDY(8,11,1986), YEAR to SECOND), 44000, NULL);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555003599', 'Mario', 'Jeleniæ', '3112986552360', 'M', EXTEND(MDY(12,31,1986), YEAR to SECOND), 21000, NULL);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555003606', 'Goran', 'Viola', '1302987553251', 'M', EXTEND(MDY(2,13,1987), YEAR to SECOND), 53220, NULL);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555003611', 'Karlo', 'Grubešiæ', '1612986552986', 'M', EXTEND(MDY(12,16,1986), YEAR to SECOND), 10000, NULL);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555003627', 'Vladimir', 'Slokoviæ', '1812986551245', 'M', EXTEND(MDY(12,18,1986), YEAR to SECOND), 47000, NULL);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555003632', 'Stipe', 'Pleša', '0109986554116', 'M', EXTEND(MDY(9,1,1986), YEAR to SECOND), 35400, NULL);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555003648', 'Ivan', 'Damljanoviæ', '0908986550137', 'M', EXTEND(MDY(8,9,1986), YEAR to SECOND), 23000, NULL);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555003653', 'Tomislav', 'Svetlièiæ', '0501987552238', 'M', EXTEND(MDY(1,5,1987), YEAR to SECOND), 10000, NULL);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555003669', 'Bartol', 'Košta', '2308986552172', 'M', EXTEND(MDY(8,23,1986), YEAR to SECOND), 49210, NULL);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555003674', 'Zoran', 'Belasiæ', '2403986550156', 'M', EXTEND(MDY(3,24,1986), YEAR to SECOND), 31000, NULL);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555003695', 'Enver', 'Pahor', '0304987552289', 'M', EXTEND(MDY(4,3,1987), YEAR to SECOND), 10000, NULL);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555003702', 'Alen', 'Ivšiæ', '3004986552428', 'M', EXTEND(MDY(4,30,1986), YEAR to SECOND), 43280, 43280);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555003718', 'Krešimir', 'Šuran', '1605987554633', 'M', EXTEND(MDY(5,16,1987), YEAR to SECOND), 51000, NULL);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555003723', 'Zoran', 'Markoviæ', '2712987550152', 'M', EXTEND(MDY(12,27,1987), YEAR to SECOND), 23000, NULL);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555003739', 'Aladin', 'Milkoviæ', '0312987552923', 'M', EXTEND(MDY(12,3,1987), YEAR to SECOND), 32100, NULL);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555003744', 'Dejan', 'Gegaè', '1512987552209', 'M', EXTEND(MDY(12,15,1987), YEAR to SECOND), 10000, NULL);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555003765', 'Dejan', 'Rodiæ', '0811987552903', 'M', EXTEND(MDY(11,8,1987), YEAR to SECOND), 10000, NULL);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555003770', 'Stanislav', 'Debeliæ', '1511987552202', 'M', EXTEND(MDY(11,15,1987), YEAR to SECOND), 10000, NULL);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555003786', 'Zvonimir', 'Moroviæ', '0201988552262', 'M', EXTEND(MDY(1,2,1989), YEAR to SECOND), 10000, 22320);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555003791', 'Nenad', 'Francetiæ', '2811987554059', 'M', EXTEND(MDY(11,28,1987), YEAR to SECOND), 33000, NULL);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555003809', 'Alen', 'Švoriniæ', '1407987551794', 'M', EXTEND(MDY(7,14,1987), YEAR to SECOND), 43280, 43280);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555003814', 'Adrijano', 'Štifter', '2607987550138', 'M', EXTEND(MDY(7,26,1987), YEAR to SECOND), 31400, NULL);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555003835', 'Goran', 'Polumirac', '2308987554608', 'M', EXTEND(MDY(8,23,1987), YEAR to SECOND), 51000, NULL);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555003840', 'Matija', 'Ratkoviæ', '1506988552105', 'M', EXTEND(MDY(6,15,1988), YEAR to SECOND), 10000, NULL);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555003856', 'Mišo', 'Brandiæ', '2108987552959', 'M', EXTEND(MDY(8,21,1987), YEAR to SECOND), 10090, NULL);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555003861', 'Milan', 'Pujas', '0207987550329', 'M', EXTEND(MDY(7,2,1987), YEAR to SECOND), 22000, NULL);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555003877', 'Ivor', 'Markoviæ', '3103988554329', 'M', EXTEND(MDY(3,31,1988), YEAR to SECOND), 52100, NULL);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555003882', 'Krešimir', 'Kalebiæ', '0106987551928', 'M', EXTEND(MDY(6,1,1987), YEAR to SECOND), 34000, NULL);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555003898', 'Loris', 'Stojanoviæ', '3007987552943', 'M', EXTEND(MDY(7,30,1987), YEAR to SECOND), 10000, NULL);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555003905', 'Zvonko', 'Miliæ', '0804988552919', 'M', EXTEND(MDY(4,8,1988), YEAR to SECOND), 10000, NULL);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555003910', 'Vesko', 'Kos', '2809987552108', 'M', EXTEND(MDY(9,28,1987), YEAR to SECOND), 10000, NULL);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555003926', 'Ivica', 'Bobinac', '0706987550929', 'M', EXTEND(MDY(6,7,1987), YEAR to SECOND), 31400, NULL);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555003931', 'Damir', 'Šestan', '0606987552315', 'M', EXTEND(MDY(6,6,1987), YEAR to SECOND), 42250, NULL);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555003947', 'Livio', 'Krmpotiæ', '1402988552237', 'M', EXTEND(MDY(2,14,1988), YEAR to SECOND), 35000, NULL);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555003952', 'Tomislav', 'Fanuko', '2307987552978', 'M', EXTEND(MDY(7,23,1987), YEAR to SECOND), 10000, NULL);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555003968', 'Luka', 'Srdoè', '2301988552922', 'M', EXTEND(MDY(1,23,1988), YEAR to SECOND), 10000, NULL);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555003973', 'Mladen', 'Grubišiæ', '1204988552222', 'M', EXTEND(MDY(4,12,1988), YEAR to SECOND), 10000, NULL);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555003989', 'Mladen', 'Paðen', '3101988553001', 'M', EXTEND(MDY(1,31,1988), YEAR to SECOND), 31000, NULL);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555003994', 'Robert', 'Marinkoviæ', '0901988552248', 'M', EXTEND(MDY(1,9,1988), YEAR to SECOND), 10000, NULL);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555004005', 'Sandy', 'Juriæ', '0409987550142', 'M', EXTEND(MDY(9,4,1987), YEAR to SECOND), 23000, NULL);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555004010', 'Krešimir', 'Hibšer', '2907987551235', 'M', EXTEND(MDY(7,29,1987), YEAR to SECOND), 47000, NULL);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555004026', 'Marin', 'Feketija', '2012987553761', 'M', EXTEND(MDY(12,20,1987), YEAR to SECOND), 43000, NULL);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555004031', 'Borislav', 'Blaškoviæ', '1104988553216', 'M', EXTEND(MDY(4,11,1988), YEAR to SECOND), 44000, NULL);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555004047', 'Igor', 'Bandiæ', '0101988553841', 'M', EXTEND(MDY(1,1,1988), YEAR to SECOND), 20000, NULL);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555004052', 'Goran', 'Rafajac', '0401988552369', 'M', EXTEND(MDY(1,4,1988), YEAR to SECOND), 21000, NULL);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555004068', 'Lovro', 'Gregoroviæ', '1404987550152', 'M', EXTEND(MDY(4,14,1987), YEAR to SECOND), 31000, NULL);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555004073', 'Ivo', 'Kovaèiæ', '2401988550142', 'M', EXTEND(MDY(1,24,1988), YEAR to SECOND), 31000, NULL);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555004089', 'Damjan', 'Uršiæ', '1303988552964', 'M', EXTEND(MDY(3,13,1988), YEAR to SECOND), 10000, NULL);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555004094', 'Dražen', 'Bunjevac', '1511987550986', 'M', EXTEND(MDY(11,15,1987), YEAR to SECOND), 48000, NULL);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555004101', 'Željko', 'Markoviæ', '1906988552375', 'M', EXTEND(MDY(6,19,1988), YEAR to SECOND), 21000, NULL);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555004117', 'Aleksandar', 'Maliæ', '1704988552373', 'M', EXTEND(MDY(4,17,1988), YEAR to SECOND), 21000, NULL);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555004122', 'Saša', 'Perkoviæ', '2812987553768', 'M', EXTEND(MDY(12,28,1987), YEAR to SECOND), 43000, NULL);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555004138', 'Marin', 'Štajduhar', '1809987554336', 'M', EXTEND(MDY(9,18,1987), YEAR to SECOND), 52100, NULL);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555004143', 'Saša', 'Flego', '2902988552322', 'M', EXTEND(MDY(2,29,1988), YEAR to SECOND), 10310, NULL);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555004159', 'Dejan', 'Jurièiæ', '3007987552269', 'M', EXTEND(MDY(7,30,1987), YEAR to SECOND), 10000, NULL);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555004164', 'Dalibor', 'Miljak', '0904987552316', 'M', EXTEND(MDY(4,9,1987), YEAR to SECOND), 10000, NULL);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555004185', 'Igor', 'Asiæ', '0506987551373', 'M', EXTEND(MDY(6,5,1987), YEAR to SECOND), 21000, NULL);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555004190', 'Ante', 'Benkoviæ', '2601988552918', 'M', EXTEND(MDY(1,26,1988), YEAR to SECOND), 10000, NULL);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555004208', 'Marko', 'Mikiæ', '2107987554076', 'M', EXTEND(MDY(7,21,1987), YEAR to SECOND), 43280, 43280);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555004213', 'Vladimir', 'Špehar', '2507987551237', 'M', EXTEND(MDY(7,25,1987), YEAR to SECOND), 47000, NULL);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555004229', 'Bruno', 'Šaban', '3007987552927', 'M', EXTEND(MDY(7,30,1987), YEAR to SECOND), 10000, NULL);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555004234', 'Tihomir', 'Cupan', '1404988550962', 'M', EXTEND(MDY(4,14,1988), YEAR to SECOND), 48000, NULL);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555004255', 'Edvard', 'Zoriæ', '2704987552292', 'M', EXTEND(MDY(4,27,1987), YEAR to SECOND), 10000, NULL);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555004260', 'Tomislav', 'Gradišar', '0610986552327', 'M', EXTEND(MDY(10,6,1986), YEAR to SECOND), 10000, NULL);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555004276', 'Mario', 'Cupan', '1510987552249', 'M', EXTEND(MDY(10,15,1987), YEAR to SECOND), 10000, NULL);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555004281', 'Marin', 'Laznicki', '1011987552978', 'M', EXTEND(MDY(11,10,1987), YEAR to SECOND), 10000, NULL);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555004297', 'Saša', 'Matoiæ', '3103988552288', 'M', EXTEND(MDY(3,31,1988), YEAR to SECOND), 10000, NULL);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555004304', 'Milan', 'Lonjak', '1610987552898', 'M', EXTEND(MDY(10,16,1987), YEAR to SECOND), 42000, NULL);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555004325', 'Boris', 'Blažekoviæ', '3107987551127', 'M', EXTEND(MDY(7,31,1987), YEAR to SECOND), 31500, NULL);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555004330', 'Filip', 'Biondiæ', '1512987551318', 'M', EXTEND(MDY(12,15,1987), YEAR to SECOND), 33405, NULL);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555004346', 'Niko', 'Pap', '1208988552953', 'M', EXTEND(MDY(8,12,1988), YEAR to SECOND), 10000, NULL);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555004351', 'Domagoj', 'Stamenkoviæ', '0307986553248', 'M', EXTEND(MDY(7,3,1986), YEAR to SECOND), 44000, NULL);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555004367', 'Hrvoje', 'Globan', '2105983552289', 'M', EXTEND(MDY(5,21,1983), YEAR to SECOND), 21000, 10000);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555004372', 'Tomislav', 'Nježiæ', '1510979551454', 'M', EXTEND(MDY(10,15,1979), YEAR to SECOND), 42250, NULL);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555004388', 'Tomislav', 'Ðurièiæ', '3103984550329', 'M', EXTEND(MDY(3,31,1984), YEAR to SECOND), 22000, NULL);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555004393', 'Petra', 'Lojen', '0103979556547', 'Ž', EXTEND(MDY(3,1,1979), YEAR to SECOND), NULL, NULL);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555004400', 'Matea', 'Èoliæ', '0106979558786', 'Ž', EXTEND(MDY(6,1,1979), YEAR to SECOND), NULL, NULL);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555004416', 'Daniela', 'Heged', '0103982557902', 'Ž', EXTEND(MDY(3,1,1982), YEAR to SECOND), NULL, NULL);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555004421', 'Kristina', 'Egredžija', '0107982557231', 'Ž', EXTEND(MDY(7,1,1982), YEAR to SECOND), 10000, NULL);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555004437', 'Sanja', 'Kanešiæ', '0104982556767', 'Ž', EXTEND(MDY(4,1,1982), YEAR to SECOND), 21000, 10000);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555004442', 'Nina', 'Vuk', '0807979557958', 'Ž', EXTEND(MDY(7,8,1979), YEAR to SECOND), 40305, 10040);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555004458', 'Martina', 'Kokuruš', '2903981555322', 'Ž', EXTEND(MDY(3,29,1981), YEAR to SECOND), 10000, 10000);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555004463', 'Tatjana', 'Lovkoviæ', '2908981557971', 'Ž', EXTEND(MDY(8,29,1981), YEAR to SECOND), 47240, 10000);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555004479', 'Jasenka', 'Kovaèiæ', '1601981556531', 'Ž', EXTEND(MDY(1,16,1981), YEAR to SECOND), 47000, NULL);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555004484', 'Tea', 'Tuðman', '1807981555125', 'Ž', EXTEND(MDY(7,18,1981), YEAR to SECOND), 31000, NULL);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555004507', 'Ana', 'Zoljan', '1009982557349', 'Ž', EXTEND(MDY(9,10,1982), YEAR to SECOND), 21000, NULL);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555004512', 'Tihana', 'Prodan', '0607982557226', 'Ž', EXTEND(MDY(7,6,1982), YEAR to SECOND), 10000, 34340);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555004528', 'Magdalena', 'Mamiloviæ', '2801982556724', 'Ž', EXTEND(MDY(1,28,1982), YEAR to SECOND), 33000, 10000);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555004533', 'Zrinka', 'Mihelèiæ', '2501982557913', 'Ž', EXTEND(MDY(1,25,1982), YEAR to SECOND), 10000, NULL);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555004549', 'Matea', 'Corva', '1008981557233', 'Ž', EXTEND(MDY(8,10,1981), YEAR to SECOND), 10000, NULL);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555004554', 'Marija', 'Mièetiæ', '0403983555133', 'Ž', EXTEND(MDY(3,4,1983), YEAR to SECOND), 23000, NULL);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555004575', 'Ivana', 'Londero', '2003983557232', 'Ž', EXTEND(MDY(3,20,1983), YEAR to SECOND), 35000, 10000);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555004580', 'Maja', 'Škibola', '0612982557211', 'Ž', EXTEND(MDY(12,6,1982), YEAR to SECOND), 10000, NULL);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555004596', 'Monika', 'Marinoviæ', '1804983557398', 'Ž', EXTEND(MDY(4,18,1983), YEAR to SECOND), 21000, 10000);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555004603', 'Ana', 'Pošèiæ', '1311982557231', 'Ž', EXTEND(MDY(11,13,1982), YEAR to SECOND), 10000, 10000);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555004619', 'Sanja', 'Kutleša', '1904983557279', 'Ž', EXTEND(MDY(4,19,1983), YEAR to SECOND), 21000, 10000);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555004624', 'Ivana', 'Haramija', '1412982557216', 'Ž', EXTEND(MDY(12,14,1982), YEAR to SECOND), 35400, 10000);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555004645', 'Tatjana', 'Goleš', '2608983556375', 'Ž', EXTEND(MDY(8,26,1983), YEAR to SECOND), 47240, 10000);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555004650', 'Sabina', 'Matahlija', '0411982557518', 'Ž', EXTEND(MDY(11,4,1982), YEAR to SECOND), 10000, 10000);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555004666', 'Željka', 'Vranèiæ', '0807982556326', 'Ž', EXTEND(MDY(7,8,1982), YEAR to SECOND), 10000, NULL);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555004671', 'Kristina', 'Sikiriæ', '2303983557325', 'Ž', EXTEND(MDY(3,23,1983), YEAR to SECOND), 47240, NULL);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555004687', 'Vjera', 'Penoviæ', '1608982557226', 'Ž', EXTEND(MDY(8,16,1982), YEAR to SECOND), 35000, 10000);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555004692', 'Matea', 'Batkoski', '1405983558848', 'Ž', EXTEND(MDY(5,14,1983), YEAR to SECOND), 20000, 10000);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555004715', 'Jelena', 'Tubin', '2410983557377', 'Ž', EXTEND(MDY(10,24,1983), YEAR to SECOND), 21000, 10000);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555004720', 'Naða', 'Iljkiæ', '2611982559053', 'Ž', EXTEND(MDY(11,26,1982), YEAR to SECOND), 33000, NULL);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555004736', 'Nives', 'Æurkoviæ', '1712982557961', 'Ž', EXTEND(MDY(12,17,1982), YEAR to SECOND), 10000, 10000);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555004741', 'Vesna', 'Èaèiæ', '0111982555155', 'Ž', EXTEND(MDY(11,1,1982), YEAR to SECOND), 23000, 10000);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555004757', 'Biljana', 'Paškvaliæ', '1001983556019', 'Ž', EXTEND(MDY(1,10,1983), YEAR to SECOND), 42250, 10000);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555004762', 'Ana', 'Poropat', '0206983557292', 'Ž', EXTEND(MDY(6,2,1983), YEAR to SECOND), 10000, 34340);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555004778', 'Dunja', 'Erliæ', '1403984557893', 'Ž', EXTEND(MDY(3,14,1984), YEAR to SECOND), 42000, 10000);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555004783', 'Antonija', 'Crnkoviæ', '1004984557263', 'Ž', EXTEND(MDY(4,10,1984), YEAR to SECOND), 21000, 10000);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555004799', 'Barbara', 'Mažuraniæ', '1705984555153', 'Ž', EXTEND(MDY(5,17,1984), YEAR to SECOND), 23000, 10000);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555004806', 'Ana', 'Baljak', '2804984557271', 'Ž', EXTEND(MDY(4,28,1984), YEAR to SECOND), 21000, 10000);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555004811', 'Jelena', 'Simiæ', '0201984556042', 'Ž', EXTEND(MDY(1,2,1984), YEAR to SECOND), 42250, 43280);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555004827', 'Pamela', 'Grevinger', '0908983557947', 'Ž', EXTEND(MDY(8,9,1983), YEAR to SECOND), 10000, 10000);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555004832', 'Ana', 'Kedžo', '0602984557973', 'Ž', EXTEND(MDY(2,6,1984), YEAR to SECOND), 10000, 10000);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555004848', 'Valentina', 'Mesaroš', '1204983556785', 'Ž', EXTEND(MDY(4,12,1983), YEAR to SECOND), 47240, 10000);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555004853', 'Nikolina', 'Pušiæ', '0412983555922', 'Ž', EXTEND(MDY(12,4,1983), YEAR to SECOND), 31400, 10000);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555004869', 'Blanka', 'Zoviæ', '2207983557296', 'Ž', EXTEND(MDY(7,22,1983), YEAR to SECOND), 10000, 10000);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555004874', 'Kristina', 'Vujnoviæ', '1604983557232', 'Ž', EXTEND(MDY(4,16,1983), YEAR to SECOND), 10000, 10000);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555004895', 'Antonia', 'Bakarèiæ', '2412983557981', 'Ž', EXTEND(MDY(12,24,1983), YEAR to SECOND), 10000, 10000);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555004902', 'Ivana', 'Ninèeviæ', '2709983556333', 'Ž', EXTEND(MDY(9,27,1983), YEAR to SECOND), 51000, 10000);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555004918', 'Ana', 'Krizmaniæ', '1212983557946', 'Ž', EXTEND(MDY(12,12,1983), YEAR to SECOND), 32100, 10000);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555004923', 'Ivana', 'Mašina', '1505984557203', 'Ž', EXTEND(MDY(5,15,1984), YEAR to SECOND), 10000, 10000);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555004939', 'Tajana', 'Bistroviæ', '1606984556046', 'Ž', EXTEND(MDY(6,16,1984), YEAR to SECOND), 43280, 43280);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555004944', 'Karmen', 'Mikulièiæ', '1603984556365', 'Ž', EXTEND(MDY(3,16,1984), YEAR to SECOND), 40305, 10000);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555004965', 'Ana', 'Arbanas', '1201985556325', 'Ž', EXTEND(MDY(1,12,1985), YEAR to SECOND), 51000, 10000);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555004970', 'Vedrana', 'Rukavina', '1511984557238', 'Ž', EXTEND(MDY(11,15,1984), YEAR to SECOND), 10000, 10000);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555004986', 'Marijana', 'Adamoviæ', '0509985558868', 'Ž', EXTEND(MDY(9,5,1985), YEAR to SECOND), 20000, 10000);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555004991', 'Gordana', 'Šulentiæ', '1010984555341', 'Ž', EXTEND(MDY(10,10,1984), YEAR to SECOND), 22000, 10000);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555005002', 'Gordana', 'Abramoviæ', '2104984557350', 'Ž', EXTEND(MDY(4,21,1984), YEAR to SECOND), 43280, 43280);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555005018', 'Zrinka', 'Zduniæ', '1309985557386', 'Ž', EXTEND(MDY(9,13,1985), YEAR to SECOND), 21000, 10000);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555005023', 'Vladimira', 'Matiæ', '0507984557318', 'Ž', EXTEND(MDY(7,5,1984), YEAR to SECOND), 10000, 10000);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555005039', 'Danijela', 'Radumilo', '0204984556289', 'Ž', EXTEND(MDY(4,2,1984), YEAR to SECOND), 47000, 10000);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555005044', 'Andreja', 'Jeriæ', '1711984558713', 'Ž', EXTEND(MDY(11,17,1984), YEAR to SECOND), 52100, 10000);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555005065', 'Jasenka', 'Æošiæ', '0604985559948', 'Ž', EXTEND(MDY(4,6,1985), YEAR to SECOND), 20350, 20350);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555005070', 'Bojana', 'Dujiæ', '1210984556924', 'Ž', EXTEND(MDY(10,12,1984), YEAR to SECOND), 34000, 10000);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555005086', 'Katarina', 'Novak - Gašpiæ', '0603985557264', 'Ž', EXTEND(MDY(3,6,1985), YEAR to SECOND), 10000, 10000);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555005091', 'Tatjana', 'Fabijaniæ', '1402985555154', 'Ž', EXTEND(MDY(2,14,1985), YEAR to SECOND), 23000, 10000);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555005109', 'Iva', 'Nièiæ', '1812984557319', 'Ž', EXTEND(MDY(12,18,1984), YEAR to SECOND), 10000, 10000);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555005114', 'Ana', 'Marèetiæ', '1511984557033', 'Ž', EXTEND(MDY(11,15,1984), YEAR to SECOND), 21260, 10000);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555005135', 'Tatjana', 'Vukiæ', '1508984559841', 'Ž', EXTEND(MDY(8,15,1984), YEAR to SECOND), 21300, 10000);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555005140', 'Ivana', 'Braim', '0906985557208', 'Ž', EXTEND(MDY(6,9,1985), YEAR to SECOND), 10000, 10000);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555005156', 'Vedrana', 'Radinoviæ', '2207984558962', 'Ž', EXTEND(MDY(7,22,1984), YEAR to SECOND), 42000, 10000);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555005161', 'Željka', 'Ban', '1008984556122', 'Ž', EXTEND(MDY(8,10,1984), YEAR to SECOND), 47240, 10000);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555005177', 'Lidija', 'Miloloža', '2709984557945', 'Ž', EXTEND(MDY(9,27,1984), YEAR to SECOND), 10000, 10000);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555005182', 'Dunja', 'Stanojeviæ', '1803984556259', 'Ž', EXTEND(MDY(3,18,1984), YEAR to SECOND), 47000, 10000);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555005198', 'Ana', 'Aniæ', '0603984557988', 'Ž', EXTEND(MDY(3,6,1984), YEAR to SECOND), 44320, 10000);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555005205', 'Tamara', 'Blažekoviæ', '1803985557372', 'Ž', EXTEND(MDY(3,18,1985), YEAR to SECOND), 48260, 10000);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555005210', 'Dubravka', 'Šubara', '0108985557239', 'Ž', EXTEND(MDY(8,1,1985), YEAR to SECOND), 10000, 10000);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555005226', 'Tanja', 'Germanoviæ', '2509985557346', 'Ž', EXTEND(MDY(9,25,1985), YEAR to SECOND), 21000, NULL);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555005231', 'Maja', 'Juriæ', '0905986557272', 'Ž', EXTEND(MDY(5,9,1986), YEAR to SECOND), 21000, NULL);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555005247', 'Davorka', 'Engelman', '1504986557247', 'Ž', EXTEND(MDY(4,15,1986), YEAR to SECOND), 10000, NULL);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555005252', 'Zorica', 'Dragojeviæ', '1008985556363', 'Ž', EXTEND(MDY(8,10,1985), YEAR to SECOND), 47240, NULL);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555005268', 'Danica', 'Šercer', '0205985557927', 'Ž', EXTEND(MDY(5,2,1985), YEAR to SECOND), 10000, NULL);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555005273', 'Dubravka', 'Juriæ', '1401986557278', 'Ž', EXTEND(MDY(1,14,1986), YEAR to SECOND), 21000, NULL);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555005289', 'Vanja', 'Šariæ', '2904986557907', 'Ž', EXTEND(MDY(4,29,1986), YEAR to SECOND), 10000, NULL);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555005294', 'Marija', 'Vujaniæ', '1703986555131', 'Ž', EXTEND(MDY(3,17,1986), YEAR to SECOND), 23000, NULL);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555005301', 'Tatjana', 'Vujaniæ', '1610985557361', 'Ž', EXTEND(MDY(10,16,1985), YEAR to SECOND), 21000, NULL);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555005317', 'Marta', 'Petroviæ', '2608985556127', 'Ž', EXTEND(MDY(8,26,1985), YEAR to SECOND), 31500, NULL);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555005322', 'Lana', 'Dukiæ', '1709986558872', 'Ž', EXTEND(MDY(9,17,1986), YEAR to SECOND), 20000, NULL);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555005338', 'Jelena', 'Grguriæ', '0804987559561', 'Ž', EXTEND(MDY(4,8,1987), YEAR to SECOND), 53000, NULL);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555005343', 'Ana', 'Èorvilo', '1301987555355', 'Ž', EXTEND(MDY(1,13,1987), YEAR to SECOND), 22000, 10000);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555005359', 'Eva', 'Krmpotiæ', '0702987557952', 'Ž', EXTEND(MDY(2,7,1987), YEAR to SECOND), 10000, NULL);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555005364', 'Ines', 'Èugelj', '0410986557176', 'Ž', EXTEND(MDY(10,4,1986), YEAR to SECOND), 49210, NULL);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555005385', 'Iva', 'Radoviæ', '1906987556016', 'Ž', EXTEND(MDY(6,19,1987), YEAR to SECOND), 47300, NULL);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555005390', 'Mirna', 'Jurèeviæ', '2303987557974', 'Ž', EXTEND(MDY(3,23,1987), YEAR to SECOND), 10000, NULL);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555005408', 'Valentina', 'Barkoviæ', '2307986557941', 'Ž', EXTEND(MDY(7,23,1986), YEAR to SECOND), 10000, NULL);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555005413', 'Dragana', 'Cink', '1610986557268', 'Ž', EXTEND(MDY(10,16,1986), YEAR to SECOND), 10000, NULL);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555005429', 'Zrinka', 'Grguriæ', '0406986557381', 'Ž', EXTEND(MDY(6,4,1986), YEAR to SECOND), 47240, NULL);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555005434', 'Anita', 'Dejanoviæ', '2411986559067', 'Ž', EXTEND(MDY(11,24,1986), YEAR to SECOND), 33000, NULL);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555005455', 'Biljana', 'Jakovljeviæ', '0806986557983', 'Ž', EXTEND(MDY(6,8,1986), YEAR to SECOND), 10000, NULL);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555005460', 'Ines', 'Vukoja', '1510986557956', 'Ž', EXTEND(MDY(10,15,1986), YEAR to SECOND), 10000, NULL);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555005476', 'Daniela', 'Baban', '2803986555997', 'Ž', EXTEND(MDY(3,28,1986), YEAR to SECOND), 48000, NULL);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555005481', 'Maja', 'Lenac', '1911986557217', 'Ž', EXTEND(MDY(11,19,1986), YEAR to SECOND), 10000, NULL);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555005497', 'Ani', 'Otuliæ', '1211987557219', 'Ž', EXTEND(MDY(11,12,1987), YEAR to SECOND), 22320, NULL);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555005504', 'Ana', 'Stipiæ', '0803988557256', 'Ž', EXTEND(MDY(3,8,1988), YEAR to SECOND), 10000, NULL);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555005525', 'Kristina', 'Klepac', '0302988557265', 'Ž', EXTEND(MDY(2,3,1988), YEAR to SECOND), 10000, NULL);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555005530', 'Ksenija', 'Ružiæ', '0911987557284', 'Ž', EXTEND(MDY(11,9,1987), YEAR to SECOND), 21000, NULL);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555005546', 'Maja', 'Peroš', '2906987557377', 'Ž', EXTEND(MDY(6,29,1987), YEAR to SECOND), 42250, NULL);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555005551', 'Marija', 'Pešun', '2212987555135', 'Ž', EXTEND(MDY(12,22,1987), YEAR to SECOND), 23000, NULL);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555005567', 'Tina', 'Keršiæ', '1211987557294', 'Ž', EXTEND(MDY(11,12,1987), YEAR to SECOND), 42250, NULL);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555005572', 'Sanja', 'Runko', '2601988556875', 'Ž', EXTEND(MDY(1,26,1988), YEAR to SECOND), 21230, NULL);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555005588', 'Martina', 'Poleto', '1908987557252', 'Ž', EXTEND(MDY(8,19,1987), YEAR to SECOND), 42250, NULL);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555005593', 'Anamaria', 'Terleviæ', '2610987557923', 'Ž', EXTEND(MDY(10,26,1987), YEAR to SECOND), 10000, NULL);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555005600', 'Tihana', 'Zec', '2211987557948', 'Ž', EXTEND(MDY(11,22,1987), YEAR to SECOND), 10000, NULL);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555005616', 'Maja', 'Stipinoviæ', '3011987557039', 'Ž', EXTEND(MDY(11,30,1987), YEAR to SECOND), 21260, NULL);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555005621', 'Marija', 'Deželjin', '1409987556233', 'Ž', EXTEND(MDY(9,14,1987), YEAR to SECOND), 47000, NULL);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555005637', 'Dubravka', 'Žaja', '3006987557981', 'Ž', EXTEND(MDY(6,30,1987), YEAR to SECOND), 10000, NULL);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555005642', 'Nikolina', 'Mamula', '0102988557959', 'Ž', EXTEND(MDY(2,1,1988), YEAR to SECOND), 10000, NULL);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555005658', 'Jelena', 'Miculiniæ', '1002988557249', 'Ž', EXTEND(MDY(2,10,1988), YEAR to SECOND), 35000, NULL);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555005663', 'Anita', 'Meiæ', '1803988557993', 'Ž', EXTEND(MDY(3,18,1988), YEAR to SECOND), 44320, NULL);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555005679', 'Danijela', 'Šegulja', '1802988557202', 'Ž', EXTEND(MDY(2,18,1988), YEAR to SECOND), 10000, NULL);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555005684', 'Jelena', 'Host', '0907987557988', 'Ž', EXTEND(MDY(7,9,1987), YEAR to SECOND), 10000, NULL);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555005707', 'Sanja', 'Laliæ', '1907988557233', 'Ž', EXTEND(MDY(7,19,1988), YEAR to SECOND), 10000, NULL);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555005712', 'Ana', 'Žakula', '1206987556243', 'Ž', EXTEND(MDY(6,12,1987), YEAR to SECOND), 47000, NULL);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555005728', 'Marija', 'Zanketiæ', '2501982557212', 'Ž', EXTEND(MDY(1,25,1982), YEAR to SECOND), 10000, 10000);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555005733', 'Nikolina', 'Smiloviæ', '0503984557207', 'Ž', EXTEND(MDY(3,5,1984), YEAR to SECOND), 10000, 10000);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555005749', 'Gordana', 'Martinkoviæ', '2403987557316', 'Ž', EXTEND(MDY(3,24,1987), YEAR to SECOND), 10000, NULL);
INSERT INTO student(jmbag, ime, prezime, jmbg, spol, datrod, pbrrod, pbrstan)
  VALUES('0555005754', 'Mia', 'Zekanoviæ', '2209984558272', 'Ž', EXTEND(MDY(9,22,1984), YEAR to SECOND), 44000, 10000);


INSERT INTO nastavnik(sifnastavnik, ime, prezime, pbrstan, siforgjed, koef, datumzaposlenod, datumzaposlendo)
  VALUES(238, 'Ivana', 'Martinec', 21265, 100008, 4.7, EXTEND(MDY(7,1,1995), YEAR to DAY), NULL);
INSERT INTO nastavnik(sifnastavnik, ime, prezime, pbrstan, siforgjed, koef, datumzaposlenod, datumzaposlendo)
  VALUES(249, 'Andrija', 'Salopek-Rabatiæ', 21265, 100008, 9.9, EXTEND(MDY(12,19,1994), YEAR to DAY), NULL);
INSERT INTO nastavnik(sifnastavnik, ime, prezime, pbrstan, siforgjed, koef, datumzaposlenod, datumzaposlendo)
  VALUES(252, 'Jure', 'Damiani-Einwalter', 21265, 100008, 4.1, EXTEND(MDY(5,1,2001), YEAR to DAY), NULL);
INSERT INTO nastavnik(sifnastavnik, ime, prezime, pbrstan, siforgjed, koef, datumzaposlenod, datumzaposlendo)
  VALUES(256, 'Milica', 'Balen', 21265, 100008, 5.7, EXTEND(MDY(5,1,2001), YEAR to DAY), EXTEND(MDY(7,24,2005), YEAR to DAY));
INSERT INTO nastavnik(sifnastavnik, ime, prezime, pbrstan, siforgjed, koef, datumzaposlenod, datumzaposlendo)
  VALUES(257, 'Tatjana', 'Kancir', 21265, 100008, 3.9, EXTEND(MDY(5,1,2001), YEAR to DAY), NULL);
INSERT INTO nastavnik(sifnastavnik, ime, prezime, pbrstan, siforgjed, koef, datumzaposlenod, datumzaposlendo)
  VALUES(261, 'Salih', 'Jalšovec', 21265, 100008, 5.5, EXTEND(MDY(5,1,2001), YEAR to DAY), NULL);
INSERT INTO nastavnik(sifnastavnik, ime, prezime, pbrstan, siforgjed, koef, datumzaposlenod, datumzaposlendo)
  VALUES(262, 'Antun', 'Pajniæ', 21265, 100008, 5.9, EXTEND(MDY(5,1,2001), YEAR to DAY), NULL);
INSERT INTO nastavnik(sifnastavnik, ime, prezime, pbrstan, siforgjed, koef, datumzaposlenod, datumzaposlendo)
  VALUES(263, 'Vlasta', 'Zanchi', 21265, 100008, 6.3, EXTEND(MDY(10,14,1985), YEAR to DAY), NULL);
INSERT INTO nastavnik(sifnastavnik, ime, prezime, pbrstan, siforgjed, koef, datumzaposlenod, datumzaposlendo)
  VALUES(267, 'Božena', 'Pavloviæ', 21265, 100008, 7.9, EXTEND(MDY(5,1,2001), YEAR to DAY), EXTEND(MDY(8,31,2000), YEAR to DAY));
INSERT INTO nastavnik(sifnastavnik, ime, prezime, pbrstan, siforgjed, koef, datumzaposlenod, datumzaposlendo)
  VALUES(268, 'Velimir', 'Jankoviæ', 21265, 100008, 8.3, EXTEND(MDY(5,1,2001), YEAR to DAY), EXTEND(MDY(5,1,2005), YEAR to DAY));
INSERT INTO nastavnik(sifnastavnik, ime, prezime, pbrstan, siforgjed, koef, datumzaposlenod, datumzaposlendo)
  VALUES(271, 'Živko', 'Laloviæ', 10000, 100008, 3.3, EXTEND(MDY(5,1,2001), YEAR to DAY), NULL);
INSERT INTO nastavnik(sifnastavnik, ime, prezime, pbrstan, siforgjed, koef, datumzaposlenod, datumzaposlendo)
  VALUES(295, 'Lukša', 'Manojloviæ', 21275, 100008, 5.9, EXTEND(MDY(5,1,2001), YEAR to DAY), EXTEND(MDY(9,30,2003), YEAR to DAY));
INSERT INTO nastavnik(sifnastavnik, ime, prezime, pbrstan, siforgjed, koef, datumzaposlenod, datumzaposlendo)
  VALUES(296, 'Hamid', 'Babiæ', 21275, 100008, 6.3, EXTEND(MDY(5,1,2001), YEAR to DAY), NULL);
INSERT INTO nastavnik(sifnastavnik, ime, prezime, pbrstan, siforgjed, koef, datumzaposlenod, datumzaposlendo)
  VALUES(297, 'Mato', 'Žarkoviæ', 21275, 100008, 6.7, EXTEND(MDY(5,1,2001), YEAR to DAY), EXTEND(MDY(8,31,2003), YEAR to DAY));
INSERT INTO nastavnik(sifnastavnik, ime, prezime, pbrstan, siforgjed, koef, datumzaposlenod, datumzaposlendo)
  VALUES(298, 'Ivan', 'Jakovljeviæ', 21275, 100008, 7.1, EXTEND(MDY(5,1,2001), YEAR to DAY), NULL);
INSERT INTO nastavnik(sifnastavnik, ime, prezime, pbrstan, siforgjed, koef, datumzaposlenod, datumzaposlendo)
  VALUES(301, 'Janko', 'Matošin', 21275, 100008, 8.3, EXTEND(MDY(5,1,2001), YEAR to DAY), NULL);
INSERT INTO nastavnik(sifnastavnik, ime, prezime, pbrstan, siforgjed, koef, datumzaposlenod, datumzaposlendo)
  VALUES(304, 'Goran', 'Kamenaroviæ', 21275, 100008, 9.5, EXTEND(MDY(5,1,2001), YEAR to DAY), NULL);
INSERT INTO nastavnik(sifnastavnik, ime, prezime, pbrstan, siforgjed, koef, datumzaposlenod, datumzaposlendo)
  VALUES(305, 'Nina', 'Mance', 21275, 100008, 9.9, EXTEND(MDY(2,1,1972), YEAR to DAY), EXTEND(MDY(1,1,1900), YEAR to DAY));
INSERT INTO nastavnik(sifnastavnik, ime, prezime, pbrstan, siforgjed, koef, datumzaposlenod, datumzaposlendo)
  VALUES(313, 'Marijan', 'Èaèiæ', 21275, 100008, 3.9, EXTEND(MDY(5,1,2001), YEAR to DAY), NULL);
INSERT INTO nastavnik(sifnastavnik, ime, prezime, pbrstan, siforgjed, koef, datumzaposlenod, datumzaposlendo)
  VALUES(330, 'Ðorðe', 'Hadži-Veljkoviæ', 21275, 100008, 4.5, EXTEND(MDY(5,1,2001), YEAR to DAY), NULL);
INSERT INTO nastavnik(sifnastavnik, ime, prezime, pbrstan, siforgjed, koef, datumzaposlenod, datumzaposlendo)
  VALUES(332, 'Siniša', 'Cariæ', 21275, 100008, 3.1, EXTEND(MDY(5,1,2001), YEAR to DAY), EXTEND(MDY(7,15,2003), YEAR to DAY));
INSERT INTO nastavnik(sifnastavnik, ime, prezime, pbrstan, siforgjed, koef, datumzaposlenod, datumzaposlendo)
  VALUES(334, 'Željko', 'Bakran', 21275, 100009, 3.9, EXTEND(MDY(8,1,1995), YEAR to DAY), NULL);
INSERT INTO nastavnik(sifnastavnik, ime, prezime, pbrstan, siforgjed, koef, datumzaposlenod, datumzaposlendo)
  VALUES(335, 'Leo', 'Gašparoviæ', 21275, 100009, 4.3, EXTEND(MDY(2,8,1988), YEAR to DAY), NULL);
INSERT INTO nastavnik(sifnastavnik, ime, prezime, pbrstan, siforgjed, koef, datumzaposlenod, datumzaposlendo)
  VALUES(337, 'Petar', 'Radoniæ', 21275, 100009, 5.1, EXTEND(MDY(5,1,2001), YEAR to DAY), NULL);
INSERT INTO nastavnik(sifnastavnik, ime, prezime, pbrstan, siforgjed, koef, datumzaposlenod, datumzaposlendo)
  VALUES(338, 'Ivo', 'Èala', 21275, 100009, 5.5, EXTEND(MDY(5,1,2001), YEAR to DAY), NULL);
INSERT INTO nastavnik(sifnastavnik, ime, prezime, pbrstan, siforgjed, koef, datumzaposlenod, datumzaposlendo)
  VALUES(339, 'Zlata', 'Pavièiæ', 21275, 100009, 5.9, EXTEND(MDY(5,1,2001), YEAR to DAY), NULL);
INSERT INTO nastavnik(sifnastavnik, ime, prezime, pbrstan, siforgjed, koef, datumzaposlenod, datumzaposlendo)
  VALUES(340, 'Davor', 'Samaržija', 21275, 100009, 6.3, EXTEND(MDY(5,1,2001), YEAR to DAY), NULL);
INSERT INTO nastavnik(sifnastavnik, ime, prezime, pbrstan, siforgjed, koef, datumzaposlenod, datumzaposlendo)
  VALUES(341, 'Zlatan', 'Jakšiæ', 22000, 100009, 6.7, EXTEND(MDY(5,1,2001), YEAR to DAY), EXTEND(MDY(8,31,2005), YEAR to DAY));
INSERT INTO nastavnik(sifnastavnik, ime, prezime, pbrstan, siforgjed, koef, datumzaposlenod, datumzaposlendo)
  VALUES(349, 'Helena', 'Papa', 22000, 100009, 3.7, EXTEND(MDY(5,1,2001), YEAR to DAY), EXTEND(MDY(9,30,1996), YEAR to DAY));
INSERT INTO nastavnik(sifnastavnik, ime, prezime, pbrstan, siforgjed, koef, datumzaposlenod, datumzaposlendo)
  VALUES(350, 'Nenad', 'Šantek', 22000, 100009, 4.1, EXTEND(MDY(9,15,1995), YEAR to DAY), NULL);
INSERT INTO nastavnik(sifnastavnik, ime, prezime, pbrstan, siforgjed, koef, datumzaposlenod, datumzaposlendo)
  VALUES(351, 'Uroš', 'Mažuraniæ', 22000, 100009, 4.5, EXTEND(MDY(5,1,2001), YEAR to DAY), EXTEND(MDY(9,30,2002), YEAR to DAY));
INSERT INTO nastavnik(sifnastavnik, ime, prezime, pbrstan, siforgjed, koef, datumzaposlenod, datumzaposlendo)
  VALUES(353, 'Alan', 'Balzani', 22000, 100007, 5.3, EXTEND(MDY(5,1,2001), YEAR to DAY), EXTEND(MDY(9,30,2004), YEAR to DAY));
INSERT INTO nastavnik(sifnastavnik, ime, prezime, pbrstan, siforgjed, koef, datumzaposlenod, datumzaposlendo)
  VALUES(354, 'Josip', 'Marinoviæ', 22000, 100007, 5.7, EXTEND(MDY(5,1,2001), YEAR to DAY), NULL);
INSERT INTO nastavnik(sifnastavnik, ime, prezime, pbrstan, siforgjed, koef, datumzaposlenod, datumzaposlendo)
  VALUES(355, 'Božidar', 'Baršiæ', 22000, 100007, 3.9, EXTEND(MDY(5,1,2001), YEAR to DAY), NULL);
INSERT INTO nastavnik(sifnastavnik, ime, prezime, pbrstan, siforgjed, koef, datumzaposlenod, datumzaposlendo)
  VALUES(356, 'Maja', 'Palmoviæ', 22000, 100007, 4.3, EXTEND(MDY(5,1,2001), YEAR to DAY), EXTEND(MDY(1,31,2006), YEAR to DAY));
INSERT INTO nastavnik(sifnastavnik, ime, prezime, pbrstan, siforgjed, koef, datumzaposlenod, datumzaposlendo)
  VALUES(360, 'Jure', 'Džepina', 22000, 100007, 5.9, EXTEND(MDY(2,2,1994), YEAR to DAY), NULL);
INSERT INTO nastavnik(sifnastavnik, ime, prezime, pbrstan, siforgjed, koef, datumzaposlenod, datumzaposlendo)
  VALUES(361, 'Hrvoje', 'Martinac', 22000, 100007, 6.3, EXTEND(MDY(5,1,2001), YEAR to DAY), EXTEND(MDY(1,1,1900), YEAR to DAY));
INSERT INTO nastavnik(sifnastavnik, ime, prezime, pbrstan, siforgjed, koef, datumzaposlenod, datumzaposlendo)
  VALUES(362, 'Nikola', 'Pasini', 22000, 100007, 6.7, EXTEND(MDY(5,1,2001), YEAR to DAY), EXTEND(MDY(12,18,2003), YEAR to DAY));
INSERT INTO nastavnik(sifnastavnik, ime, prezime, pbrstan, siforgjed, koef, datumzaposlenod, datumzaposlendo)
  VALUES(367, 'Ivan', 'Baudoin', 22000, 100007, 9.5, EXTEND(MDY(10,1,1994), YEAR to DAY), EXTEND(MDY(3,31,1992), YEAR to DAY));
INSERT INTO nastavnik(sifnastavnik, ime, prezime, pbrstan, siforgjed, koef, datumzaposlenod, datumzaposlendo)
  VALUES(368, 'Marko', 'Katušiæ', 22000, 100007, 9.9, EXTEND(MDY(5,1,2001), YEAR to DAY), NULL);
INSERT INTO nastavnik(sifnastavnik, ime, prezime, pbrstan, siforgjed, koef, datumzaposlenod, datumzaposlendo)
  VALUES(369, 'Krešimir', 'Batiniæ', 22000, 100007, 3.3, EXTEND(MDY(5,1,2001), YEAR to DAY), NULL);
INSERT INTO nastavnik(sifnastavnik, ime, prezime, pbrstan, siforgjed, koef, datumzaposlenod, datumzaposlendo)
  VALUES(370, 'Hrvoje', 'Rajiæ', 22000, 100007, 3.7, EXTEND(MDY(9,1,2005), YEAR to DAY), EXTEND(MDY(10,31,1999), YEAR to DAY));
INSERT INTO nastavnik(sifnastavnik, ime, prezime, pbrstan, siforgjed, koef, datumzaposlenod, datumzaposlendo)
  VALUES(378, 'Maja', 'Èaniæ', 22000, 100007, 3.9, EXTEND(MDY(5,1,2001), YEAR to DAY), EXTEND(MDY(9,30,2003), YEAR to DAY));
INSERT INTO nastavnik(sifnastavnik, ime, prezime, pbrstan, siforgjed, koef, datumzaposlenod, datumzaposlendo)
  VALUES(379, 'Draško', 'Babiæ-Nagliæ', 22000, 100007, 5.1, EXTEND(MDY(5,1,1996), YEAR to DAY), EXTEND(MDY(9,30,1999), YEAR to DAY));
INSERT INTO nastavnik(sifnastavnik, ime, prezime, pbrstan, siforgjed, koef, datumzaposlenod, datumzaposlendo)
  VALUES(380, 'Vesna', 'Jajiæ', 22000, 100007, 5.5, EXTEND(MDY(11,1,2001), YEAR to DAY), NULL);
INSERT INTO nastavnik(sifnastavnik, ime, prezime, pbrstan, siforgjed, koef, datumzaposlenod, datumzaposlendo)
  VALUES(383, 'Maja', 'Èadež', 22000, 100007, 6.7, EXTEND(MDY(1,1,1995), YEAR to DAY), NULL);
INSERT INTO nastavnik(sifnastavnik, ime, prezime, pbrstan, siforgjed, koef, datumzaposlenod, datumzaposlendo)
  VALUES(385, 'Jasenka', 'Laziæ', 22000, 100007, 7.5, EXTEND(MDY(5,1,2001), YEAR to DAY), NULL);
INSERT INTO nastavnik(sifnastavnik, ime, prezime, pbrstan, siforgjed, koef, datumzaposlenod, datumzaposlendo)
  VALUES(386, 'Nicollete', 'Marjanoviæ-Rajèiæ', 22000, 100007, 7.9, EXTEND(MDY(5,1,2001), YEAR to DAY), NULL);
INSERT INTO nastavnik(sifnastavnik, ime, prezime, pbrstan, siforgjed, koef, datumzaposlenod, datumzaposlendo)
  VALUES(387, 'Marko', 'Babiæ', 22000, 100007, 8.3, EXTEND(MDY(5,1,2001), YEAR to DAY), EXTEND(MDY(4,15,2001), YEAR to DAY));
INSERT INTO nastavnik(sifnastavnik, ime, prezime, pbrstan, siforgjed, koef, datumzaposlenod, datumzaposlendo)
  VALUES(388, 'Ivanèica', 'Kalauz', 22000, 100007, 8.7, EXTEND(MDY(5,1,2001), YEAR to DAY), NULL);
INSERT INTO nastavnik(sifnastavnik, ime, prezime, pbrstan, siforgjed, koef, datumzaposlenod, datumzaposlendo)
  VALUES(392, 'Daria', 'Balen', 22000, 100007, 4.1, EXTEND(MDY(8,1,1998), YEAR to DAY), NULL);
INSERT INTO nastavnik(sifnastavnik, ime, prezime, pbrstan, siforgjed, koef, datumzaposlenod, datumzaposlendo)
  VALUES(393, 'Slavica', 'Žagar', 22000, 100007, 5.9, EXTEND(MDY(5,1,2001), YEAR to DAY), EXTEND(MDY(8,31,1995), YEAR to DAY));
INSERT INTO nastavnik(sifnastavnik, ime, prezime, pbrstan, siforgjed, koef, datumzaposlenod, datumzaposlendo)
  VALUES(394, 'Ana', 'Kacian', 22000, 100007, 6.3, EXTEND(MDY(8,22,1996), YEAR to DAY), NULL);
INSERT INTO nastavnik(sifnastavnik, ime, prezime, pbrstan, siforgjed, koef, datumzaposlenod, datumzaposlendo)
  VALUES(404, 'Ninoslava', 'Šapina', 31000, 100007, 3.3, EXTEND(MDY(5,1,2001), YEAR to DAY), NULL);
INSERT INTO nastavnik(sifnastavnik, ime, prezime, pbrstan, siforgjed, koef, datumzaposlenod, datumzaposlendo)
  VALUES(420, 'Zvonko', 'Kardum', 31000, 100007, 8.3, EXTEND(MDY(1,1,1997), YEAR to DAY), EXTEND(MDY(5,1,2005), YEAR to DAY));
INSERT INTO nastavnik(sifnastavnik, ime, prezime, pbrstan, siforgjed, koef, datumzaposlenod, datumzaposlendo)
  VALUES(421, 'Hrvoje', 'Èabrijan', 31000, 100007, 8.7, EXTEND(MDY(1,1,1997), YEAR to DAY), NULL);
INSERT INTO nastavnik(sifnastavnik, ime, prezime, pbrstan, siforgjed, koef, datumzaposlenod, datumzaposlendo)
  VALUES(422, 'Velimir', 'Tambiæ-Andraševiæ', 31000, 100007, 9.1, EXTEND(MDY(1,1,1997), YEAR to DAY), NULL);
INSERT INTO nastavnik(sifnastavnik, ime, prezime, pbrstan, siforgjed, koef, datumzaposlenod, datumzaposlendo)
  VALUES(423, 'Gordana', 'Ðakoviæ Rode', 31000, 100007, 9.5, EXTEND(MDY(1,1,1997), YEAR to DAY), EXTEND(MDY(1,13,1998), YEAR to DAY));
INSERT INTO nastavnik(sifnastavnik, ime, prezime, pbrstan, siforgjed, koef, datumzaposlenod, datumzaposlendo)
  VALUES(432, 'Luka', 'Halužan', NULL, 100007, 3.9, EXTEND(MDY(3,1,1997), YEAR to DAY), NULL);
INSERT INTO nastavnik(sifnastavnik, ime, prezime, pbrstan, siforgjed, koef, datumzaposlenod, datumzaposlendo)
  VALUES(462, 'Aleksandra', 'Kavalari', 31410, 100007, 7.5, EXTEND(MDY(3,1,1997), YEAR to DAY), EXTEND(MDY(1,19,2007), YEAR to DAY));
INSERT INTO nastavnik(sifnastavnik, ime, prezime, pbrstan, siforgjed, koef, datumzaposlenod, datumzaposlendo)
  VALUES(467, 'Dražen', 'Jakovèeviæ', 31410, 100007, 3.3, EXTEND(MDY(3,1,1997), YEAR to DAY), NULL);
INSERT INTO nastavnik(sifnastavnik, ime, prezime, pbrstan, siforgjed, koef, datumzaposlenod, datumzaposlendo)
  VALUES(472, 'Emil', 'Baraæ', 31410, 100010, 5.3, EXTEND(MDY(4,1,1997), YEAR to DAY), NULL);
INSERT INTO nastavnik(sifnastavnik, ime, prezime, pbrstan, siforgjed, koef, datumzaposlenod, datumzaposlendo)
  VALUES(473, 'Eduard', 'Markovinoviæ', 31410, 100010, 5.7, EXTEND(MDY(4,1,1997), YEAR to DAY), NULL);
INSERT INTO nastavnik(sifnastavnik, ime, prezime, pbrstan, siforgjed, koef, datumzaposlenod, datumzaposlendo)
  VALUES(474, 'Franka Miriam', 'Babiæ', 31410, 100010, 3.1, EXTEND(MDY(4,1,1997), YEAR to DAY), NULL);
INSERT INTO nastavnik(sifnastavnik, ime, prezime, pbrstan, siforgjed, koef, datumzaposlenod, datumzaposlendo)
  VALUES(478, 'Hrvoje', 'Mandiæ', 31410, 100010, 5.5, EXTEND(MDY(3,1,1997), YEAR to DAY), NULL);
INSERT INTO nastavnik(sifnastavnik, ime, prezime, pbrstan, siforgjed, koef, datumzaposlenod, datumzaposlendo)
  VALUES(479, 'Ibrahim', 'Paliæ', 31410, 100010, 5.9, EXTEND(MDY(5,1,2001), YEAR to DAY), EXTEND(MDY(1,31,1988), YEAR to DAY));
INSERT INTO nastavnik(sifnastavnik, ime, prezime, pbrstan, siforgjed, koef, datumzaposlenod, datumzaposlendo)
  VALUES(480, 'Ivo', 'Baèiæ', 31410, 100010, 6.3, EXTEND(MDY(5,1,2001), YEAR to DAY), NULL);
INSERT INTO nastavnik(sifnastavnik, ime, prezime, pbrstan, siforgjed, koef, datumzaposlenod, datumzaposlendo)
  VALUES(484, 'Julije', 'Galoviæ', 31410, 100010, 7.9, EXTEND(MDY(7,1,2006), YEAR to DAY), NULL);
INSERT INTO nastavnik(sifnastavnik, ime, prezime, pbrstan, siforgjed, koef, datumzaposlenod, datumzaposlendo)
  VALUES(485, 'Josip', 'Manger-Slijepèeviæ', 31410, 100010, 8.3, EXTEND(MDY(4,1,1997), YEAR to DAY), NULL);
INSERT INTO nastavnik(sifnastavnik, ime, prezime, pbrstan, siforgjed, koef, datumzaposlenod, datumzaposlendo)
  VALUES(487, 'Josip', 'Tariba', 31410, 100010, 9.1, EXTEND(MDY(5,1,2001), YEAR to DAY), EXTEND(MDY(6,30,1995), YEAR to DAY));
INSERT INTO nastavnik(sifnastavnik, ime, prezime, pbrstan, siforgjed, koef, datumzaposlenod, datumzaposlendo)
  VALUES(488, 'Krešimir', 'Tadej', 31410, 100010, 9.5, EXTEND(MDY(5,1,1997), YEAR to DAY), NULL);
INSERT INTO nastavnik(sifnastavnik, ime, prezime, pbrstan, siforgjed, koef, datumzaposlenod, datumzaposlendo)
  VALUES(489, 'Krunoslav', 'Paradžik', 31410, 100010, 3.7, EXTEND(MDY(4,1,1997), YEAR to DAY), NULL);
INSERT INTO nastavnik(sifnastavnik, ime, prezime, pbrstan, siforgjed, koef, datumzaposlenod, datumzaposlendo)
  VALUES(490, 'Luka', 'Katiæ Žlepalo', 31410, 100010, 4.1, EXTEND(MDY(4,1,1997), YEAR to DAY), NULL);
INSERT INTO nastavnik(sifnastavnik, ime, prezime, pbrstan, siforgjed, koef, datumzaposlenod, datumzaposlendo)
  VALUES(496, 'Mladen', 'Baniæ-Pajniæ', 31410, 100010, 7.9, EXTEND(MDY(4,1,1997), YEAR to DAY), EXTEND(MDY(5,31,2003), YEAR to DAY));
INSERT INTO nastavnik(sifnastavnik, ime, prezime, pbrstan, siforgjed, koef, datumzaposlenod, datumzaposlendo)
  VALUES(497, 'Martin', 'Barbariæ', 31410, 100010, 8.3, EXTEND(MDY(4,1,1997), YEAR to DAY), EXTEND(MDY(11,17,2002), YEAR to DAY));
INSERT INTO nastavnik(sifnastavnik, ime, prezime, pbrstan, siforgjed, koef, datumzaposlenod, datumzaposlendo)
  VALUES(498, 'Miljenko', 'Bariæ', 31410, 100010, 8.7, EXTEND(MDY(4,1,1997), YEAR to DAY), NULL);
INSERT INTO nastavnik(sifnastavnik, ime, prezime, pbrstan, siforgjed, koef, datumzaposlenod, datumzaposlendo)
  VALUES(503, 'Marko', 'Karbiæ', 31500, 100010, 4.5, EXTEND(MDY(5,1,1997), YEAR to DAY), NULL);
INSERT INTO nastavnik(sifnastavnik, ime, prezime, pbrstan, siforgjed, koef, datumzaposlenod, datumzaposlendo)
  VALUES(507, 'Neven', 'Lamza Posavec', 31500, 100010, 3.1, EXTEND(MDY(5,1,2001), YEAR to DAY), NULL);
INSERT INTO nastavnik(sifnastavnik, ime, prezime, pbrstan, siforgjed, koef, datumzaposlenod, datumzaposlendo)
  VALUES(508, 'Nela', 'Lay', 31500, 100010, 3.5, EXTEND(MDY(5,1,2001), YEAR to DAY), NULL);
INSERT INTO nastavnik(sifnastavnik, ime, prezime, pbrstan, siforgjed, koef, datumzaposlenod, datumzaposlendo)
  VALUES(509, 'Nedžad', 'Maðareviæ', 31500, 100010, 3.9, EXTEND(MDY(5,1,1997), YEAR to DAY), NULL);
INSERT INTO nastavnik(sifnastavnik, ime, prezime, pbrstan, siforgjed, koef, datumzaposlenod, datumzaposlendo)
  VALUES(513, 'Ružica', 'Marks', 31500, 100010, 5.5, EXTEND(MDY(5,1,1997), YEAR to DAY), EXTEND(MDY(1,14,1996), YEAR to DAY));
INSERT INTO nastavnik(sifnastavnik, ime, prezime, pbrstan, siforgjed, koef, datumzaposlenod, datumzaposlendo)
  VALUES(514, 'Saša', 'Maštroviæ', 31500, 100010, 5.9, EXTEND(MDY(5,1,1997), YEAR to DAY), NULL);
INSERT INTO nastavnik(sifnastavnik, ime, prezime, pbrstan, siforgjed, koef, datumzaposlenod, datumzaposlendo)
  VALUES(516, 'Sanja', 'Nagy', 31500, 100010, 7.5, EXTEND(MDY(5,1,1997), YEAR to DAY), EXTEND(MDY(6,30,2006), YEAR to DAY));
INSERT INTO nastavnik(sifnastavnik, ime, prezime, pbrstan, siforgjed, koef, datumzaposlenod, datumzaposlendo)
  VALUES(520, 'Vilmoš', 'Lanc', 31500, 100010, 9.1, EXTEND(MDY(5,1,1997), YEAR to DAY), NULL);
INSERT INTO nastavnik(sifnastavnik, ime, prezime, pbrstan, siforgjed, koef, datumzaposlenod, datumzaposlendo)
  VALUES(524, 'Vera', 'Marin', 31500, 100010, 3.7, EXTEND(MDY(5,1,1997), YEAR to DAY), NULL);
INSERT INTO nastavnik(sifnastavnik, ime, prezime, pbrstan, siforgjed, koef, datumzaposlenod, datumzaposlendo)
  VALUES(525, 'Vlado', 'Jašareviæ', 31500, 100010, 4.1, EXTEND(MDY(5,1,1997), YEAR to DAY), NULL);
INSERT INTO nastavnik(sifnastavnik, ime, prezime, pbrstan, siforgjed, koef, datumzaposlenod, datumzaposlendo)
  VALUES(526, 'Zvonko', 'Žagar', 31500, 100010, 4.5, EXTEND(MDY(5,1,1997), YEAR to DAY), NULL);
INSERT INTO nastavnik(sifnastavnik, ime, prezime, pbrstan, siforgjed, koef, datumzaposlenod, datumzaposlendo)
  VALUES(530, 'Željka', 'Laliæ', NULL, 100010, 3.9, EXTEND(MDY(5,1,1997), YEAR to DAY), NULL);
INSERT INTO nastavnik(sifnastavnik, ime, prezime, pbrstan, siforgjed, koef, datumzaposlenod, datumzaposlendo)
  VALUES(531, 'Zvonimir', 'Paveliæ', NULL, 100010, 4.3, EXTEND(MDY(5,1,1997), YEAR to DAY), NULL);
INSERT INTO nastavnik(sifnastavnik, ime, prezime, pbrstan, siforgjed, koef, datumzaposlenod, datumzaposlendo)
  VALUES(532, 'Marina', 'Pavlakoviæ', NULL, 100010, 4.7, EXTEND(MDY(5,1,1997), YEAR to DAY), EXTEND(MDY(5,31,1999), YEAR to DAY));
INSERT INTO nastavnik(sifnastavnik, ime, prezime, pbrstan, siforgjed, koef, datumzaposlenod, datumzaposlendo)
  VALUES(533, 'Vesna', 'Valentiæ', NULL, 100010, 5.1, EXTEND(MDY(5,1,1997), YEAR to DAY), EXTEND(MDY(4,30,1996), YEAR to DAY));
INSERT INTO nastavnik(sifnastavnik, ime, prezime, pbrstan, siforgjed, koef, datumzaposlenod, datumzaposlendo)
  VALUES(534, 'Igor', 'Vaniæ', NULL, 100010, 5.5, EXTEND(MDY(6,1,1997), YEAR to DAY), NULL);
INSERT INTO nastavnik(sifnastavnik, ime, prezime, pbrstan, siforgjed, koef, datumzaposlenod, datumzaposlendo)
  VALUES(535, 'Sandra', 'Rakošec', NULL, 100010, 5.9, EXTEND(MDY(6,1,1997), YEAR to DAY), NULL);
INSERT INTO nastavnik(sifnastavnik, ime, prezime, pbrstan, siforgjed, koef, datumzaposlenod, datumzaposlendo)
  VALUES(536, 'Ladislav', 'Babiæ', NULL, 100010, 6.3, EXTEND(MDY(6,1,1997), YEAR to DAY), NULL);
INSERT INTO nastavnik(sifnastavnik, ime, prezime, pbrstan, siforgjed, koef, datumzaposlenod, datumzaposlendo)
  VALUES(538, 'Ana', 'Balent', NULL, 100010, 7.1, EXTEND(MDY(6,1,1997), YEAR to DAY), NULL);
INSERT INTO nastavnik(sifnastavnik, ime, prezime, pbrstan, siforgjed, koef, datumzaposlenod, datumzaposlendo)
  VALUES(545, 'Renato', 'Barbariæ', 31500, 100010, 3.7, EXTEND(MDY(6,1,1997), YEAR to DAY), NULL);
INSERT INTO nastavnik(sifnastavnik, ime, prezime, pbrstan, siforgjed, koef, datumzaposlenod, datumzaposlendo)
  VALUES(546, 'Eni', 'Barbariæ Mikoèeviæ', 31500, 100010, 4.1, EXTEND(MDY(6,1,1997), YEAR to DAY), EXTEND(MDY(10,31,2001), YEAR to DAY));
INSERT INTO nastavnik(sifnastavnik, ime, prezime, pbrstan, siforgjed, koef, datumzaposlenod, datumzaposlendo)
  VALUES(547, 'Miroslav', 'Džimbeg Malèiæ', 31500, 100010, 4.5, EXTEND(MDY(6,1,1997), YEAR to DAY), EXTEND(MDY(11,2,1997), YEAR to DAY));
INSERT INTO nastavnik(sifnastavnik, ime, prezime, pbrstan, siforgjed, koef, datumzaposlenod, datumzaposlendo)
  VALUES(550, 'Ani', 'Kaštelan Kunst', 31500, 100010, 5.7, EXTEND(MDY(6,1,1997), YEAR to DAY), NULL);
INSERT INTO nastavnik(sifnastavnik, ime, prezime, pbrstan, siforgjed, koef, datumzaposlenod, datumzaposlendo)
  VALUES(553, 'Mladen', 'Majnariæ', 31500, 100004, 4.7, EXTEND(MDY(6,1,1997), YEAR to DAY), NULL);
INSERT INTO nastavnik(sifnastavnik, ime, prezime, pbrstan, siforgjed, koef, datumzaposlenod, datumzaposlendo)
  VALUES(558, 'Ana', 'Paveliæ', 31500, 100004, 6.7, EXTEND(MDY(6,1,1997), YEAR to DAY), EXTEND(MDY(6,30,1996), YEAR to DAY));
INSERT INTO nastavnik(sifnastavnik, ime, prezime, pbrstan, siforgjed, koef, datumzaposlenod, datumzaposlendo)
  VALUES(559, 'Miloš', 'Gadže', 31500, 100004, 7.1, EXTEND(MDY(6,1,1997), YEAR to DAY), NULL);
INSERT INTO nastavnik(sifnastavnik, ime, prezime, pbrstan, siforgjed, koef, datumzaposlenod, datumzaposlendo)
  VALUES(560, 'Zdravko', 'Bašiæ', 31500, 100004, 7.5, EXTEND(MDY(6,1,1997), YEAR to DAY), EXTEND(MDY(1,1,2000), YEAR to DAY));
INSERT INTO nastavnik(sifnastavnik, ime, prezime, pbrstan, siforgjed, koef, datumzaposlenod, datumzaposlendo)
  VALUES(561, 'Goran', 'Caput', 31500, 100004, 7.9, EXTEND(MDY(6,1,1997), YEAR to DAY), EXTEND(MDY(9,30,2006), YEAR to DAY));
INSERT INTO nastavnik(sifnastavnik, ime, prezime, pbrstan, siforgjed, koef, datumzaposlenod, datumzaposlendo)
  VALUES(566, 'Ante', 'Bariæ', 31500, 100004, 3.7, EXTEND(MDY(6,1,1997), YEAR to DAY), EXTEND(MDY(1,16,1994), YEAR to DAY));
INSERT INTO nastavnik(sifnastavnik, ime, prezime, pbrstan, siforgjed, koef, datumzaposlenod, datumzaposlendo)
  VALUES(567, 'Aleksandar', 'Kapš', 31500, 100004, 4.1, EXTEND(MDY(6,1,1997), YEAR to DAY), EXTEND(MDY(3,14,1998), YEAR to DAY));
INSERT INTO nastavnik(sifnastavnik, ime, prezime, pbrstan, siforgjed, koef, datumzaposlenod, datumzaposlendo)
  VALUES(568, 'Lovorka', 'Maletiæ', 31500, 100004, 4.5, EXTEND(MDY(6,1,1997), YEAR to DAY), NULL);
INSERT INTO nastavnik(sifnastavnik, ime, prezime, pbrstan, siforgjed, koef, datumzaposlenod, datumzaposlendo)
  VALUES(569, 'Ivan Krešimir', 'Matiæ', 31500, 100004, 4.9, EXTEND(MDY(6,1,1997), YEAR to DAY), NULL);
INSERT INTO nastavnik(sifnastavnik, ime, prezime, pbrstan, siforgjed, koef, datumzaposlenod, datumzaposlendo)
  VALUES(580, 'Irena', 'Bariæ', 31500, 100004, 7.1, EXTEND(MDY(6,1,1997), YEAR to DAY), EXTEND(MDY(5,16,2000), YEAR to DAY));
INSERT INTO nastavnik(sifnastavnik, ime, prezime, pbrstan, siforgjed, koef, datumzaposlenod, datumzaposlendo)
  VALUES(581, 'Antonije', 'Matkoviæ', 31500, 100004, 7.5, EXTEND(MDY(6,1,1997), YEAR to DAY), NULL);
INSERT INTO nastavnik(sifnastavnik, ime, prezime, pbrstan, siforgjed, koef, datumzaposlenod, datumzaposlendo)
  VALUES(582, 'Antun', 'Parenta', 31500, 100004, 7.9, EXTEND(MDY(6,1,1997), YEAR to DAY), NULL);
INSERT INTO nastavnik(sifnastavnik, ime, prezime, pbrstan, siforgjed, koef, datumzaposlenod, datumzaposlendo)
  VALUES(583, 'Darko', 'Radman', 31500, 100004, 8.3, EXTEND(MDY(6,1,1997), YEAR to DAY), NULL);
INSERT INTO nastavnik(sifnastavnik, ime, prezime, pbrstan, siforgjed, koef, datumzaposlenod, datumzaposlendo)
  VALUES(588, 'Vladimir', 'Babiæ', 31500, 100004, 4.1, EXTEND(MDY(6,1,1997), YEAR to DAY), NULL);
INSERT INTO nastavnik(sifnastavnik, ime, prezime, pbrstan, siforgjed, koef, datumzaposlenod, datumzaposlendo)
  VALUES(589, 'Stanko', 'Babiæ', 31500, 100004, 5.9, EXTEND(MDY(6,1,1997), YEAR to DAY), NULL);
INSERT INTO nastavnik(sifnastavnik, ime, prezime, pbrstan, siforgjed, koef, datumzaposlenod, datumzaposlendo)
  VALUES(590, 'Gorjana', 'Baèun-Družina', 31500, 100004, 6.3, EXTEND(MDY(6,1,1997), YEAR to DAY), NULL);
INSERT INTO nastavnik(sifnastavnik, ime, prezime, pbrstan, siforgjed, koef, datumzaposlenod, datumzaposlendo)
  VALUES(591, 'Slobodan', 'Banoviæ', 31500, 100004, 6.7, EXTEND(MDY(6,1,1997), YEAR to DAY), EXTEND(MDY(5,5,1996), YEAR to DAY));
INSERT INTO nastavnik(sifnastavnik, ime, prezime, pbrstan, siforgjed, koef, datumzaposlenod, datumzaposlendo)
  VALUES(592, 'Dubravko', 'Bauman', 31500, 100004, 7.1, EXTEND(MDY(6,1,1997), YEAR to DAY), NULL);
INSERT INTO nastavnik(sifnastavnik, ime, prezime, pbrstan, siforgjed, koef, datumzaposlenod, datumzaposlendo)
  VALUES(593, 'Rudolf', 'Barbariæ', 31500, 100004, 7.5, EXTEND(MDY(6,1,1997), YEAR to DAY), NULL);
INSERT INTO nastavnik(sifnastavnik, ime, prezime, pbrstan, siforgjed, koef, datumzaposlenod, datumzaposlendo)
  VALUES(596, 'Silvio', 'Karloviæ', 31500, 100004, 8.7, EXTEND(MDY(6,1,1997), YEAR to DAY), EXTEND(MDY(1,1,1999), YEAR to DAY));
INSERT INTO nastavnik(sifnastavnik, ime, prezime, pbrstan, siforgjed, koef, datumzaposlenod, datumzaposlendo)
  VALUES(597, 'Jasna', 'Kataniæ', 31500, 100004, 9.1, EXTEND(MDY(6,1,1997), YEAR to DAY), NULL);
INSERT INTO nastavnik(sifnastavnik, ime, prezime, pbrstan, siforgjed, koef, datumzaposlenod, datumzaposlendo)
  VALUES(598, 'Antun', 'Kasaniæ', 31500, 100004, 9.5, EXTEND(MDY(6,1,1997), YEAR to DAY), NULL);
INSERT INTO nastavnik(sifnastavnik, ime, prezime, pbrstan, siforgjed, koef, datumzaposlenod, datumzaposlendo)
  VALUES(635, 'Leonardo', 'Maæešiæ', NULL, 100004, 6.7, EXTEND(MDY(9,1,1997), YEAR to DAY), NULL);
INSERT INTO nastavnik(sifnastavnik, ime, prezime, pbrstan, siforgjed, koef, datumzaposlenod, datumzaposlendo)
  VALUES(641, 'Tomislav', 'Maliæ', 32000, 100004, 9.9, EXTEND(MDY(9,1,1997), YEAR to DAY), NULL);
INSERT INTO nastavnik(sifnastavnik, ime, prezime, pbrstan, siforgjed, koef, datumzaposlenod, datumzaposlendo)
  VALUES(642, 'Marijan', 'Mariæ', 32000, 100004, 3.3, EXTEND(MDY(9,1,1997), YEAR to DAY), EXTEND(MDY(12,31,1992), YEAR to DAY));
INSERT INTO nastavnik(sifnastavnik, ime, prezime, pbrstan, siforgjed, koef, datumzaposlenod, datumzaposlendo)
  VALUES(643, 'Tedi', 'Marièiæ', 32000, 100004, 3.7, EXTEND(MDY(9,1,1997), YEAR to DAY), EXTEND(MDY(3,15,1992), YEAR to DAY));
INSERT INTO nastavnik(sifnastavnik, ime, prezime, pbrstan, siforgjed, koef, datumzaposlenod, datumzaposlendo)
  VALUES(656, 'Renata', 'Lackoviæ', 32000, 100003, 6.7, EXTEND(MDY(10,1,1997), YEAR to DAY), NULL);
INSERT INTO nastavnik(sifnastavnik, ime, prezime, pbrstan, siforgjed, koef, datumzaposlenod, datumzaposlendo)
  VALUES(659, 'Zdravko', 'Dardaliæ', 32000, 100003, 7.9, EXTEND(MDY(10,1,1997), YEAR to DAY), NULL);
INSERT INTO nastavnik(sifnastavnik, ime, prezime, pbrstan, siforgjed, koef, datumzaposlenod, datumzaposlendo)
  VALUES(660, 'Renata', 'Hadžiæ', 32000, 100003, 8.3, EXTEND(MDY(10,1,1997), YEAR to DAY), NULL);
INSERT INTO nastavnik(sifnastavnik, ime, prezime, pbrstan, siforgjed, koef, datumzaposlenod, datumzaposlendo)
  VALUES(661, 'Robert', 'Valentin', 32000, 100003, 9.5, EXTEND(MDY(10,1,1997), YEAR to DAY), NULL);
INSERT INTO nastavnik(sifnastavnik, ime, prezime, pbrstan, siforgjed, koef, datumzaposlenod, datumzaposlendo)
  VALUES(662, 'Arsen', 'Kalman', 32000, 100003, 9.9, EXTEND(MDY(10,1,1997), YEAR to DAY), EXTEND(MDY(2,15,2004), YEAR to DAY));
INSERT INTO nastavnik(sifnastavnik, ime, prezime, pbrstan, siforgjed, koef, datumzaposlenod, datumzaposlendo)
  VALUES(663, 'Sandro', 'Karloviæ', 32000, 100003, 3.3, EXTEND(MDY(10,1,1997), YEAR to DAY), NULL);
INSERT INTO nastavnik(sifnastavnik, ime, prezime, pbrstan, siforgjed, koef, datumzaposlenod, datumzaposlendo)
  VALUES(665, 'Ines', 'Majiæ', 32000, 100003, 4.1, EXTEND(MDY(10,1,1997), YEAR to DAY), NULL);
INSERT INTO nastavnik(sifnastavnik, ime, prezime, pbrstan, siforgjed, koef, datumzaposlenod, datumzaposlendo)
  VALUES(668, 'Pero', 'Bariæ', 32000, 100003, 5.3, EXTEND(MDY(10,1,1997), YEAR to DAY), NULL);
INSERT INTO nastavnik(sifnastavnik, ime, prezime, pbrstan, siforgjed, koef, datumzaposlenod, datumzaposlendo)
  VALUES(670, 'Ivan', 'Fabijaniæ', 32000, 100003, 3.1, EXTEND(MDY(11,1,1997), YEAR to DAY), NULL);
INSERT INTO nastavnik(sifnastavnik, ime, prezime, pbrstan, siforgjed, koef, datumzaposlenod, datumzaposlendo)
  VALUES(671, 'Milivoj', 'Faziniæ', 32000, 100003, 3.5, EXTEND(MDY(10,1,1997), YEAR to DAY), NULL);
INSERT INTO nastavnik(sifnastavnik, ime, prezime, pbrstan, siforgjed, koef, datumzaposlenod, datumzaposlendo)
  VALUES(672, 'Antica', 'Galzina', 32000, 100003, 3.9, EXTEND(MDY(5,1,2001), YEAR to DAY), NULL);
INSERT INTO nastavnik(sifnastavnik, ime, prezime, pbrstan, siforgjed, koef, datumzaposlenod, datumzaposlendo)
  VALUES(673, 'Hrvoje', 'Majer', 32000, 100003, 5.1, EXTEND(MDY(5,1,2001), YEAR to DAY), NULL);
INSERT INTO nastavnik(sifnastavnik, ime, prezime, pbrstan, siforgjed, koef, datumzaposlenod, datumzaposlendo)
  VALUES(679, 'Duško', 'Gagiæ', 32000, 100003, 7.5, EXTEND(MDY(11,1,1997), YEAR to DAY), EXTEND(MDY(3,31,1996), YEAR to DAY));
INSERT INTO nastavnik(sifnastavnik, ime, prezime, pbrstan, siforgjed, koef, datumzaposlenod, datumzaposlendo)
  VALUES(680, 'Vesna', 'Galiæ', 32000, 100003, 7.9, EXTEND(MDY(12,1,1997), YEAR to DAY), NULL);
INSERT INTO nastavnik(sifnastavnik, ime, prezime, pbrstan, siforgjed, koef, datumzaposlenod, datumzaposlendo)
  VALUES(681, 'Nada', 'Gašparoviæ', 32000, 100003, 8.3, EXTEND(MDY(12,1,1997), YEAR to DAY), EXTEND(MDY(12,31,2003), YEAR to DAY));
INSERT INTO nastavnik(sifnastavnik, ime, prezime, pbrstan, siforgjed, koef, datumzaposlenod, datumzaposlendo)
  VALUES(682, 'Franjo', 'Mariæ', 32000, 100003, 8.7, EXTEND(MDY(12,1,1997), YEAR to DAY), EXTEND(MDY(11,30,1999), YEAR to DAY));
INSERT INTO nastavnik(sifnastavnik, ime, prezime, pbrstan, siforgjed, koef, datumzaposlenod, datumzaposlendo)
  VALUES(683, 'Hanija', 'Baccarini', 32000, 100003, 9.1, EXTEND(MDY(12,1,1997), YEAR to DAY), NULL);
INSERT INTO nastavnik(sifnastavnik, ime, prezime, pbrstan, siforgjed, koef, datumzaposlenod, datumzaposlendo)
  VALUES(690, 'Anto', 'Fanuko', 32000, 100003, 7.1, EXTEND(MDY(12,1,1997), YEAR to DAY), NULL);
INSERT INTO nastavnik(sifnastavnik, ime, prezime, pbrstan, siforgjed, koef, datumzaposlenod, datumzaposlendo)
  VALUES(693, 'Davor', 'Caroviæ', 32000, 100003, 8.3, EXTEND(MDY(12,1,1997), YEAR to DAY), NULL);
INSERT INTO nastavnik(sifnastavnik, ime, prezime, pbrstan, siforgjed, koef, datumzaposlenod, datumzaposlendo)
  VALUES(694, 'Mirna', 'Džidiæ', 32000, 100003, 8.7, EXTEND(MDY(12,1,1997), YEAR to DAY), NULL);
INSERT INTO nastavnik(sifnastavnik, ime, prezime, pbrstan, siforgjed, koef, datumzaposlenod, datumzaposlendo)
  VALUES(695, 'Dubravka', 'Habuš Jerèiæ', 32000, 100003, 9.1, EXTEND(MDY(12,1,1997), YEAR to DAY), EXTEND(MDY(9,30,2002), YEAR to DAY));
INSERT INTO nastavnik(sifnastavnik, ime, prezime, pbrstan, siforgjed, koef, datumzaposlenod, datumzaposlendo)
  VALUES(696, 'Sanja', 'Hadelan', 32000, 100003, 9.5, EXTEND(MDY(12,1,1997), YEAR to DAY), EXTEND(MDY(1,31,2001), YEAR to DAY));
INSERT INTO nastavnik(sifnastavnik, ime, prezime, pbrstan, siforgjed, koef, datumzaposlenod, datumzaposlendo)
  VALUES(697, 'Nikola', 'Janušiæ', 32000, 100003, 9.9, EXTEND(MDY(12,1,1997), YEAR to DAY), NULL);
INSERT INTO nastavnik(sifnastavnik, ime, prezime, pbrstan, siforgjed, koef, datumzaposlenod, datumzaposlendo)
  VALUES(698, 'Ante', 'Kapoviæ', 32000, 100003, 3.3, EXTEND(MDY(12,1,1997), YEAR to DAY), EXTEND(MDY(4,17,1995), YEAR to DAY));
INSERT INTO nastavnik(sifnastavnik, ime, prezime, pbrstan, siforgjed, koef, datumzaposlenod, datumzaposlendo)
  VALUES(704, 'Daniela', 'Jardas', 32100, 100003, 3.5, EXTEND(MDY(12,1,1997), YEAR to DAY), NULL);
INSERT INTO nastavnik(sifnastavnik, ime, prezime, pbrstan, siforgjed, koef, datumzaposlenod, datumzaposlendo)
  VALUES(705, 'Maja', 'Kaliman', 32100, 100003, 3.9, EXTEND(MDY(12,1,1997), YEAR to DAY), NULL);
INSERT INTO nastavnik(sifnastavnik, ime, prezime, pbrstan, siforgjed, koef, datumzaposlenod, datumzaposlendo)
  VALUES(707, 'Ivan', 'Labinac', 32100, 100003, 4.7, EXTEND(MDY(12,1,1997), YEAR to DAY), NULL);
INSERT INTO nastavnik(sifnastavnik, ime, prezime, pbrstan, siforgjed, koef, datumzaposlenod, datumzaposlendo)
  VALUES(708, 'Ines', 'Majetiæ', 32100, 100003, 5.1, EXTEND(MDY(12,1,1997), YEAR to DAY), NULL);
INSERT INTO nastavnik(sifnastavnik, ime, prezime, pbrstan, siforgjed, koef, datumzaposlenod, datumzaposlendo)
  VALUES(709, 'Arijana', 'Majkus', 32100, 100003, 5.5, EXTEND(MDY(12,1,1997), YEAR to DAY), NULL);
INSERT INTO nastavnik(sifnastavnik, ime, prezime, pbrstan, siforgjed, koef, datumzaposlenod, datumzaposlendo)
  VALUES(712, 'Juraj', 'Pahljina-Reiniæ', 32100, 100003, 7.5, EXTEND(MDY(12,1,1997), YEAR to DAY), NULL);
INSERT INTO nastavnik(sifnastavnik, ime, prezime, pbrstan, siforgjed, koef, datumzaposlenod, datumzaposlendo)
  VALUES(714, 'Melita', 'Radovan', 32100, 100003, 8.3, EXTEND(MDY(12,1,1997), YEAR to DAY), NULL);
INSERT INTO nastavnik(sifnastavnik, ime, prezime, pbrstan, siforgjed, koef, datumzaposlenod, datumzaposlendo)
  VALUES(717, 'Danijela', 'Sajko', 32100, 100003, 9.5, EXTEND(MDY(1,1,1998), YEAR to DAY), NULL);
INSERT INTO nastavnik(sifnastavnik, ime, prezime, pbrstan, siforgjed, koef, datumzaposlenod, datumzaposlendo)
  VALUES(719, 'Gordana', 'Salopek', 32100, 100014, 3.3, EXTEND(MDY(1,1,1998), YEAR to DAY), NULL);
INSERT INTO nastavnik(sifnastavnik, ime, prezime, pbrstan, siforgjed, koef, datumzaposlenod, datumzaposlendo)
  VALUES(720, 'Darko', 'Takšiæ', 32100, 100014, 3.7, EXTEND(MDY(1,1,1998), YEAR to DAY), NULL);
INSERT INTO nastavnik(sifnastavnik, ime, prezime, pbrstan, siforgjed, koef, datumzaposlenod, datumzaposlendo)
  VALUES(721, 'Andrica', 'Bajšanski', 32100, 100014, 4.1, EXTEND(MDY(7,1,2002), YEAR to DAY), NULL);
INSERT INTO nastavnik(sifnastavnik, ime, prezime, pbrstan, siforgjed, koef, datumzaposlenod, datumzaposlendo)
  VALUES(723, 'Ksenija', 'Gavran', 32100, 100014, 5.7, EXTEND(MDY(1,1,1998), YEAR to DAY), NULL);
INSERT INTO nastavnik(sifnastavnik, ime, prezime, pbrstan, siforgjed, koef, datumzaposlenod, datumzaposlendo)
  VALUES(726, 'Dražen', 'Kalogjera', 32100, 100014, 3.9, EXTEND(MDY(5,1,2001), YEAR to DAY), NULL);
INSERT INTO nastavnik(sifnastavnik, ime, prezime, pbrstan, siforgjed, koef, datumzaposlenod, datumzaposlendo)
  VALUES(728, 'Ðulijano', 'Matešiæ', 32100, 100014, 4.7, EXTEND(MDY(6,1,2001), YEAR to DAY), NULL);
INSERT INTO nastavnik(sifnastavnik, ime, prezime, pbrstan, siforgjed, koef, datumzaposlenod, datumzaposlendo)
  VALUES(729, 'Barbara', 'Pavletiæ', 32100, 100014, 5.1, EXTEND(MDY(2,1,1998), YEAR to DAY), NULL);
INSERT INTO nastavnik(sifnastavnik, ime, prezime, pbrstan, siforgjed, koef, datumzaposlenod, datumzaposlendo)
  VALUES(734, 'Darko', 'Ban', NULL, 100014, 7.1, EXTEND(MDY(2,1,1998), YEAR to DAY), NULL);
INSERT INTO nastavnik(sifnastavnik, ime, prezime, pbrstan, siforgjed, koef, datumzaposlenod, datumzaposlendo)
  VALUES(735, 'Anton', 'Baniæ-Zrinšæak', NULL, 100014, 8.3, EXTEND(MDY(2,1,1998), YEAR to DAY), NULL);
INSERT INTO nastavnik(sifnastavnik, ime, prezime, pbrstan, siforgjed, koef, datumzaposlenod, datumzaposlendo)
  VALUES(737, 'Domagoj', 'Matijašiæ', NULL, 100014, 9.1, EXTEND(MDY(3,1,1998), YEAR to DAY), NULL);
INSERT INTO nastavnik(sifnastavnik, ime, prezime, pbrstan, siforgjed, koef, datumzaposlenod, datumzaposlendo)
  VALUES(753, 'Irena', 'Matejaš', 32100, 100001, 6.3, EXTEND(MDY(4,1,1998), YEAR to DAY), NULL);
INSERT INTO nastavnik(sifnastavnik, ime, prezime, pbrstan, siforgjed, koef, datumzaposlenod, datumzaposlendo)
  VALUES(756, 'Jasenka', 'Mastanjeviæ', 32100, 100001, 7.5, EXTEND(MDY(4,1,1998), YEAR to DAY), NULL);
INSERT INTO nastavnik(sifnastavnik, ime, prezime, pbrstan, siforgjed, koef, datumzaposlenod, datumzaposlendo)
  VALUES(757, 'Damir', 'Barudžija', 32100, 100001, 7.9, EXTEND(MDY(4,1,1998), YEAR to DAY), NULL);
INSERT INTO nastavnik(sifnastavnik, ime, prezime, pbrstan, siforgjed, koef, datumzaposlenod, datumzaposlendo)
  VALUES(758, 'Miranda', 'Radoš', 32100, 100001, 8.3, EXTEND(MDY(4,1,1998), YEAR to DAY), EXTEND(MDY(3,31,1995), YEAR to DAY));
INSERT INTO nastavnik(sifnastavnik, ime, prezime, pbrstan, siforgjed, koef, datumzaposlenod, datumzaposlendo)
  VALUES(759, 'Elvira', 'Galiæ', 32100, 100001, 9.5, EXTEND(MDY(4,1,1998), YEAR to DAY), NULL);
INSERT INTO nastavnik(sifnastavnik, ime, prezime, pbrstan, siforgjed, koef, datumzaposlenod, datumzaposlendo)
  VALUES(760, 'Boris', 'Garapiæ', 32100, 100001, 9.9, EXTEND(MDY(4,1,1998), YEAR to DAY), NULL);
INSERT INTO nastavnik(sifnastavnik, ime, prezime, pbrstan, siforgjed, koef, datumzaposlenod, datumzaposlendo)
  VALUES(761, 'Marina', 'Garapiæ Šiftar', 32100, 100001, 3.3, EXTEND(MDY(5,1,2001), YEAR to DAY), NULL);
INSERT INTO nastavnik(sifnastavnik, ime, prezime, pbrstan, siforgjed, koef, datumzaposlenod, datumzaposlendo)
  VALUES(767, 'Željko', 'Karasalihoviæ', 32100, 100001, 5.7, EXTEND(MDY(5,1,1998), YEAR to DAY), NULL);
INSERT INTO nastavnik(sifnastavnik, ime, prezime, pbrstan, siforgjed, koef, datumzaposlenod, datumzaposlendo)
  VALUES(768, 'Ariana', 'Kavedžija', 32100, 100001, 3.1, EXTEND(MDY(5,1,1998), YEAR to DAY), NULL);
INSERT INTO nastavnik(sifnastavnik, ime, prezime, pbrstan, siforgjed, koef, datumzaposlenod, datumzaposlendo)
  VALUES(772, 'Željka', 'Matanoviæ', 32100, 100001, 5.5, EXTEND(MDY(6,1,1998), YEAR to DAY), NULL);
INSERT INTO nastavnik(sifnastavnik, ime, prezime, pbrstan, siforgjed, koef, datumzaposlenod, datumzaposlendo)
  VALUES(773, 'Saša', 'Matošin', 32100, 100001, 5.9, EXTEND(MDY(6,1,1998), YEAR to DAY), EXTEND(MDY(2,28,1997), YEAR to DAY));
INSERT INTO nastavnik(sifnastavnik, ime, prezime, pbrstan, siforgjed, koef, datumzaposlenod, datumzaposlendo)
  VALUES(774, 'Radojka', 'Mauroviæ', 32100, 100001, 6.3, EXTEND(MDY(6,1,1998), YEAR to DAY), EXTEND(MDY(5,31,2004), YEAR to DAY));
INSERT INTO nastavnik(sifnastavnik, ime, prezime, pbrstan, siforgjed, koef, datumzaposlenod, datumzaposlendo)
  VALUES(775, 'Ela', 'Mayer', 32100, 100001, 6.7, EXTEND(MDY(6,1,1998), YEAR to DAY), NULL);
INSERT INTO nastavnik(sifnastavnik, ime, prezime, pbrstan, siforgjed, koef, datumzaposlenod, datumzaposlendo)
  VALUES(776, 'Ivica', 'Nakiæ', 32100, 100001, 7.1, EXTEND(MDY(6,1,1998), YEAR to DAY), NULL);
INSERT INTO nastavnik(sifnastavnik, ime, prezime, pbrstan, siforgjed, koef, datumzaposlenod, datumzaposlendo)
  VALUES(777, 'Eduard', 'Parlov', 32100, 100001, 7.5, EXTEND(MDY(6,1,1998), YEAR to DAY), NULL);
INSERT INTO nastavnik(sifnastavnik, ime, prezime, pbrstan, siforgjed, koef, datumzaposlenod, datumzaposlendo)
  VALUES(778, 'Ester', 'Paveliæ', 32100, 100001, 7.9, EXTEND(MDY(6,1,1998), YEAR to DAY), NULL);
INSERT INTO nastavnik(sifnastavnik, ime, prezime, pbrstan, siforgjed, koef, datumzaposlenod, datumzaposlendo)
  VALUES(779, 'Mladen', 'Rajkoviæ', 32100, 100001, 8.3, EXTEND(MDY(10,1,2005), YEAR to DAY), NULL);
INSERT INTO nastavnik(sifnastavnik, ime, prezime, pbrstan, siforgjed, koef, datumzaposlenod, datumzaposlendo)
  VALUES(782, 'Duška', 'Rašiæ Krnjakoviæ', 32100, 100001, 9.5, EXTEND(MDY(11,2,1999), YEAR to DAY), NULL);
INSERT INTO nastavnik(sifnastavnik, ime, prezime, pbrstan, siforgjed, koef, datumzaposlenod, datumzaposlendo)
  VALUES(791, 'Gordana', 'Bakoviæ', 32100, 100002, 8.3, EXTEND(MDY(6,1,1998), YEAR to DAY), NULL);
INSERT INTO nastavnik(sifnastavnik, ime, prezime, pbrstan, siforgjed, koef, datumzaposlenod, datumzaposlendo)
  VALUES(795, 'Ivan', 'Fabian', 32100, 100002, 9.9, EXTEND(MDY(7,1,1998), YEAR to DAY), NULL);
INSERT INTO nastavnik(sifnastavnik, ime, prezime, pbrstan, siforgjed, koef, datumzaposlenod, datumzaposlendo)
  VALUES(796, 'Gordana', 'Salopek', 32100, 100002, 3.3, EXTEND(MDY(7,1,1998), YEAR to DAY), NULL);
INSERT INTO nastavnik(sifnastavnik, ime, prezime, pbrstan, siforgjed, koef, datumzaposlenod, datumzaposlendo)
  VALUES(797, 'Alenka', 'Šafran', 32100, 100002, 4.5, EXTEND(MDY(7,1,1998), YEAR to DAY), EXTEND(MDY(2,28,1994), YEAR to DAY));
INSERT INTO nastavnik(sifnastavnik, ime, prezime, pbrstan, siforgjed, koef, datumzaposlenod, datumzaposlendo)
  VALUES(798, 'Gordana', 'Valent', 32100, 100002, 4.9, EXTEND(MDY(7,1,1998), YEAR to DAY), EXTEND(MDY(9,30,1999), YEAR to DAY));
INSERT INTO nastavnik(sifnastavnik, ime, prezime, pbrstan, siforgjed, koef, datumzaposlenod, datumzaposlendo)
  VALUES(799, 'Marta', 'Karamarko', 32100, 100002, 5.3, EXTEND(MDY(7,1,1998), YEAR to DAY), NULL);
INSERT INTO nastavnik(sifnastavnik, ime, prezime, pbrstan, siforgjed, koef, datumzaposlenod, datumzaposlendo)
  VALUES(800, 'Darko', 'Kasum', 32100, 100002, 5.7, EXTEND(MDY(7,1,1998), YEAR to DAY), NULL);
INSERT INTO nastavnik(sifnastavnik, ime, prezime, pbrstan, siforgjed, koef, datumzaposlenod, datumzaposlendo)
  VALUES(801, 'Sanjin', 'Raèiæ', 10000, 100002, 3.1, EXTEND(MDY(7,1,1998), YEAR to DAY), EXTEND(MDY(2,28,1993), YEAR to DAY));
INSERT INTO nastavnik(sifnastavnik, ime, prezime, pbrstan, siforgjed, koef, datumzaposlenod, datumzaposlendo)
  VALUES(802, 'Anðelka', 'Pavloviæ', 10000, 100002, 3.5, EXTEND(MDY(7,1,1998), YEAR to DAY), NULL);
INSERT INTO nastavnik(sifnastavnik, ime, prezime, pbrstan, siforgjed, koef, datumzaposlenod, datumzaposlendo)
  VALUES(803, 'Biserka', 'Landeka C755', 33000, 100002, 3.9, EXTEND(MDY(7,1,1998), YEAR to DAY), NULL);
INSERT INTO nastavnik(sifnastavnik, ime, prezime, pbrstan, siforgjed, koef, datumzaposlenod, datumzaposlendo)
  VALUES(804, 'Ljiljana', 'Varga', 33000, 100002, 4.3, EXTEND(MDY(7,1,1998), YEAR to DAY), EXTEND(MDY(9,30,2001), YEAR to DAY));
INSERT INTO nastavnik(sifnastavnik, ime, prezime, pbrstan, siforgjed, koef, datumzaposlenod, datumzaposlendo)
  VALUES(805, 'Jagoda', 'Èaèiæ', 33000, 100002, 4.7, EXTEND(MDY(7,1,1998), YEAR to DAY), NULL);
INSERT INTO nastavnik(sifnastavnik, ime, prezime, pbrstan, siforgjed, koef, datumzaposlenod, datumzaposlendo)
  VALUES(806, 'Smiljana', 'Kalajdžiæ', 33000, 100002, 5.1, EXTEND(MDY(7,1,1998), YEAR to DAY), EXTEND(MDY(3,31,2003), YEAR to DAY));
INSERT INTO nastavnik(sifnastavnik, ime, prezime, pbrstan, siforgjed, koef, datumzaposlenod, datumzaposlendo)
  VALUES(807, 'Jelena', 'Æaleta', 33000, 100002, 5.5, EXTEND(MDY(5,1,2001), YEAR to DAY), EXTEND(MDY(12,31,1996), YEAR to DAY));
INSERT INTO nastavnik(sifnastavnik, ime, prezime, pbrstan, siforgjed, koef, datumzaposlenod, datumzaposlendo)
  VALUES(808, 'Vojko', 'Šariæ', 33000, 100002, 5.9, EXTEND(MDY(5,1,2001), YEAR to DAY), NULL);
INSERT INTO nastavnik(sifnastavnik, ime, prezime, pbrstan, siforgjed, koef, datumzaposlenod, datumzaposlendo)
  VALUES(809, 'Gordana', 'Bajraktareviæ', 33000, 100002, 7.1, EXTEND(MDY(5,1,2001), YEAR to DAY), NULL);
INSERT INTO nastavnik(sifnastavnik, ime, prezime, pbrstan, siforgjed, koef, datumzaposlenod, datumzaposlendo)
  VALUES(810, 'Josip', 'Èakiæ', 33000, 100002, 7.5, EXTEND(MDY(9,1,1998), YEAR to DAY), NULL);
INSERT INTO nastavnik(sifnastavnik, ime, prezime, pbrstan, siforgjed, koef, datumzaposlenod, datumzaposlendo)
  VALUES(811, 'Daniel', 'Barišiæ', 33000, 100002, 7.9, EXTEND(MDY(10,1,1998), YEAR to DAY), NULL);
INSERT INTO nastavnik(sifnastavnik, ime, prezime, pbrstan, siforgjed, koef, datumzaposlenod, datumzaposlendo)
  VALUES(813, 'Tomislav', 'Gaurina Èakiæ', 33000, 100002, 8.7, EXTEND(MDY(9,15,1998), YEAR to DAY), NULL);
INSERT INTO nastavnik(sifnastavnik, ime, prezime, pbrstan, siforgjed, koef, datumzaposlenod, datumzaposlendo)
  VALUES(814, 'Jasminka', 'Matkoviæ', 33000, 100002, 9.1, EXTEND(MDY(9,1,1998), YEAR to DAY), NULL);
INSERT INTO nastavnik(sifnastavnik, ime, prezime, pbrstan, siforgjed, koef, datumzaposlenod, datumzaposlendo)
  VALUES(816, 'Klementina', 'Lapaine', 33000, 100002, 9.9, EXTEND(MDY(10,1,1998), YEAR to DAY), NULL);
INSERT INTO nastavnik(sifnastavnik, ime, prezime, pbrstan, siforgjed, koef, datumzaposlenod, datumzaposlendo)
  VALUES(817, 'Ivone', 'Radoševiæ', 33000, 100002, 3.3, EXTEND(MDY(10,1,1998), YEAR to DAY), NULL);
INSERT INTO nastavnik(sifnastavnik, ime, prezime, pbrstan, siforgjed, koef, datumzaposlenod, datumzaposlendo)
  VALUES(822, 'Aleks', 'Bakoviæ', 33000, 100002, 3.1, EXTEND(MDY(2,11,2003), YEAR to DAY), NULL);
INSERT INTO nastavnik(sifnastavnik, ime, prezime, pbrstan, siforgjed, koef, datumzaposlenod, datumzaposlendo)
  VALUES(827, 'Irena', 'Šarèeviæ', 33000, 100002, 5.1, EXTEND(MDY(11,1,1998), YEAR to DAY), NULL);
INSERT INTO nastavnik(sifnastavnik, ime, prezime, pbrstan, siforgjed, koef, datumzaposlenod, datumzaposlendo)
  VALUES(831, 'Adalbert', 'Baliæ', NULL, 100002, 6.7, EXTEND(MDY(11,1,1998), YEAR to DAY), EXTEND(MDY(8,31,2004), YEAR to DAY));
INSERT INTO nastavnik(sifnastavnik, ime, prezime, pbrstan, siforgjed, koef, datumzaposlenod, datumzaposlendo)
  VALUES(832, 'Valter', 'Galiæ', NULL, 100002, 7.1, EXTEND(MDY(11,1,1998), YEAR to DAY), EXTEND(MDY(2,29,1996), YEAR to DAY));
INSERT INTO nastavnik(sifnastavnik, ime, prezime, pbrstan, siforgjed, koef, datumzaposlenod, datumzaposlendo)
  VALUES(833, 'Dražen', 'Gavranoviæ', NULL, 100002, 8.3, EXTEND(MDY(11,1,1998), YEAR to DAY), EXTEND(MDY(2,25,2001), YEAR to DAY));
INSERT INTO nastavnik(sifnastavnik, ime, prezime, pbrstan, siforgjed, koef, datumzaposlenod, datumzaposlendo)
  VALUES(834, 'Marina', 'Markovina', NULL, 100002, 8.7, EXTEND(MDY(12,1,1998), YEAR to DAY), NULL);
INSERT INTO nastavnik(sifnastavnik, ime, prezime, pbrstan, siforgjed, koef, datumzaposlenod, datumzaposlendo)
  VALUES(835, 'Ivica', 'Papkoviæ', NULL, 100002, 9.1, EXTEND(MDY(12,1,1998), YEAR to DAY), NULL);
INSERT INTO nastavnik(sifnastavnik, ime, prezime, pbrstan, siforgjed, koef, datumzaposlenod, datumzaposlendo)
  VALUES(836, 'Branko', 'Pavièeviæ', NULL, 100002, 9.5, EXTEND(MDY(11,13,1998), YEAR to DAY), NULL);
INSERT INTO nastavnik(sifnastavnik, ime, prezime, pbrstan, siforgjed, koef, datumzaposlenod, datumzaposlendo)
  VALUES(837, 'Ognjen', 'Šamanoviæ', NULL, 100002, 9.9, EXTEND(MDY(10,5,1998), YEAR to DAY), NULL);
INSERT INTO nastavnik(sifnastavnik, ime, prezime, pbrstan, siforgjed, koef, datumzaposlenod, datumzaposlendo)
  VALUES(838, 'Marica', 'Šakiæ', NULL, 100002, 3.3, EXTEND(MDY(12,1,1998), YEAR to DAY), NULL);
INSERT INTO nastavnik(sifnastavnik, ime, prezime, pbrstan, siforgjed, koef, datumzaposlenod, datumzaposlendo)
  VALUES(839, 'Arianna', 'Bariæ', NULL, 100002, 3.7, EXTEND(MDY(12,1,1998), YEAR to DAY), EXTEND(MDY(9,30,2002), YEAR to DAY));
INSERT INTO nastavnik(sifnastavnik, ime, prezime, pbrstan, siforgjed, koef, datumzaposlenod, datumzaposlendo)
  VALUES(840, 'Anton', 'Baèiæ', NULL, 100002, 4.1, EXTEND(MDY(12,1,1998), YEAR to DAY), NULL);
INSERT INTO nastavnik(sifnastavnik, ime, prezime, pbrstan, siforgjed, koef, datumzaposlenod, datumzaposlendo)
  VALUES(841, 'Tamara', 'Careva', 33000, 100002, 4.5, EXTEND(MDY(12,1,1998), YEAR to DAY), NULL);
INSERT INTO nastavnik(sifnastavnik, ime, prezime, pbrstan, siforgjed, koef, datumzaposlenod, datumzaposlendo)
  VALUES(842, 'Hrvoje', 'Bakiæ', 33000, 100002, 4.9, EXTEND(MDY(12,1,1998), YEAR to DAY), NULL);
INSERT INTO nastavnik(sifnastavnik, ime, prezime, pbrstan, siforgjed, koef, datumzaposlenod, datumzaposlendo)
  VALUES(843, 'Mirko', 'Kasun', 33000, 100002, 5.3, EXTEND(MDY(12,1,1998), YEAR to DAY), NULL);
INSERT INTO nastavnik(sifnastavnik, ime, prezime, pbrstan, siforgjed, koef, datumzaposlenod, datumzaposlendo)
  VALUES(844, 'Davor', 'Rajèiæ', 33000, 100002, 5.7, EXTEND(MDY(12,1,1998), YEAR to DAY), NULL);
INSERT INTO nastavnik(sifnastavnik, ime, prezime, pbrstan, siforgjed, koef, datumzaposlenod, datumzaposlendo)
  VALUES(845, 'Nataša', 'Æatoviæ', 33000, 100002, 3.9, EXTEND(MDY(12,1,1998), YEAR to DAY), EXTEND(MDY(9,14,2000), YEAR to DAY));
INSERT INTO nastavnik(sifnastavnik, ime, prezime, pbrstan, siforgjed, koef, datumzaposlenod, datumzaposlendo)
  VALUES(851, 'Zlatko', 'Bagariæ', 33000, 100002, 6.3, EXTEND(MDY(12,1,1998), YEAR to DAY), NULL);
INSERT INTO nastavnik(sifnastavnik, ime, prezime, pbrstan, siforgjed, koef, datumzaposlenod, datumzaposlendo)
  VALUES(863, 'Jadranka', 'Mandiæ', 33000, 100011, 4.9, EXTEND(MDY(3,1,1999), YEAR to DAY), NULL);
INSERT INTO nastavnik(sifnastavnik, ime, prezime, pbrstan, siforgjed, koef, datumzaposlenod, datumzaposlendo)
  VALUES(867, 'Duje', 'Radionov', 33000, 100011, 3.5, EXTEND(MDY(3,1,1999), YEAR to DAY), NULL);
INSERT INTO nastavnik(sifnastavnik, ime, prezime, pbrstan, siforgjed, koef, datumzaposlenod, datumzaposlendo)
  VALUES(868, 'Mima', 'Bajuk', 33000, 100011, 3.9, EXTEND(MDY(4,1,1999), YEAR to DAY), NULL);
INSERT INTO nastavnik(sifnastavnik, ime, prezime, pbrstan, siforgjed, koef, datumzaposlenod, datumzaposlendo)
  VALUES(877, 'Nedžad', 'Radoš', 33000, 100011, 8.3, EXTEND(MDY(4,1,1999), YEAR to DAY), EXTEND(MDY(12,31,2005), YEAR to DAY));
INSERT INTO nastavnik(sifnastavnik, ime, prezime, pbrstan, siforgjed, koef, datumzaposlenod, datumzaposlendo)
  VALUES(878, 'Marina', 'Jarmiæ', 33000, 100011, 8.7, EXTEND(MDY(4,1,1999), YEAR to DAY), NULL);
INSERT INTO nastavnik(sifnastavnik, ime, prezime, pbrstan, siforgjed, koef, datumzaposlenod, datumzaposlendo)
  VALUES(879, 'Zvonimir', 'Raðenoviæ', 33000, 100011, 9.1, EXTEND(MDY(4,1,1999), YEAR to DAY), NULL);
INSERT INTO nastavnik(sifnastavnik, ime, prezime, pbrstan, siforgjed, koef, datumzaposlenod, datumzaposlendo)
  VALUES(880, 'Zvonkec', 'Bakiæ', 33000, 100011, 9.5, EXTEND(MDY(4,1,1999), YEAR to DAY), NULL);
INSERT INTO nastavnik(sifnastavnik, ime, prezime, pbrstan, siforgjed, koef, datumzaposlenod, datumzaposlendo)
  VALUES(881, 'Sven', 'Laziæ', 33000, 100011, 3.7, EXTEND(MDY(4,1,1999), YEAR to DAY), NULL);
INSERT INTO nastavnik(sifnastavnik, ime, prezime, pbrstan, siforgjed, koef, datumzaposlenod, datumzaposlendo)
  VALUES(882, 'Martin', 'Malina', 33000, 100011, 4.1, EXTEND(MDY(4,1,1999), YEAR to DAY), NULL);
INSERT INTO nastavnik(sifnastavnik, ime, prezime, pbrstan, siforgjed, koef, datumzaposlenod, datumzaposlendo)
  VALUES(883, 'Viktor', 'Mamuziæ', 33000, 100011, 5.9, EXTEND(MDY(4,1,1999), YEAR to DAY), EXTEND(MDY(12,31,1998), YEAR to DAY));
INSERT INTO nastavnik(sifnastavnik, ime, prezime, pbrstan, siforgjed, koef, datumzaposlenod, datumzaposlendo)
  VALUES(891, 'Ivor', 'Kalvarešin', 33000, 100011, 9.1, EXTEND(MDY(8,28,2002), YEAR to DAY), NULL);
INSERT INTO nastavnik(sifnastavnik, ime, prezime, pbrstan, siforgjed, koef, datumzaposlenod, datumzaposlendo)
  VALUES(892, 'Zoran', 'Tadiæ', 33000, 100011, 9.5, EXTEND(MDY(5,1,1999), YEAR to DAY), NULL);
INSERT INTO nastavnik(sifnastavnik, ime, prezime, pbrstan, siforgjed, koef, datumzaposlenod, datumzaposlendo)
  VALUES(893, 'Neven', 'Barišiæ', 33000, 100011, 9.9, EXTEND(MDY(5,1,1999), YEAR to DAY), NULL);
INSERT INTO nastavnik(sifnastavnik, ime, prezime, pbrstan, siforgjed, koef, datumzaposlenod, datumzaposlendo)
  VALUES(894, 'Roni', 'Radoš', 33000, 100011, 3.3, EXTEND(MDY(5,1,1999), YEAR to DAY), EXTEND(MDY(9,30,2003), YEAR to DAY));
INSERT INTO nastavnik(sifnastavnik, ime, prezime, pbrstan, siforgjed, koef, datumzaposlenod, datumzaposlendo)
  VALUES(895, 'Tomislav', 'Carek', 33000, 100011, 4.5, EXTEND(MDY(5,1,1999), YEAR to DAY), EXTEND(MDY(9,30,2001), YEAR to DAY));
INSERT INTO nastavnik(sifnastavnik, ime, prezime, pbrstan, siforgjed, koef, datumzaposlenod, datumzaposlendo)
  VALUES(896, 'Mate', 'Æatiæ', 33000, 100011, 4.9, EXTEND(MDY(5,1,2001), YEAR to DAY), NULL);
INSERT INTO nastavnik(sifnastavnik, ime, prezime, pbrstan, siforgjed, koef, datumzaposlenod, datumzaposlendo)
  VALUES(897, 'Janko', 'Jankoviæ', 33000, 100011, 5.3, EXTEND(MDY(6,1,1999), YEAR to DAY), NULL);
INSERT INTO nastavnik(sifnastavnik, ime, prezime, pbrstan, siforgjed, koef, datumzaposlenod, datumzaposlendo)
  VALUES(902, 'Kamen', 'Sandev', 34000, 100006, 4.3, EXTEND(MDY(7,1,1999), YEAR to DAY), NULL);
INSERT INTO nastavnik(sifnastavnik, ime, prezime, pbrstan, siforgjed, koef, datumzaposlenod, datumzaposlendo)
  VALUES(911, 'Vlatko', 'Ramljak', 34000, 100006, 8.7, EXTEND(MDY(5,1,2001), YEAR to DAY), NULL);
INSERT INTO nastavnik(sifnastavnik, ime, prezime, pbrstan, siforgjed, koef, datumzaposlenod, datumzaposlendo)
  VALUES(912, 'Slavko', 'Babiæ', 34000, 100006, 9.1, EXTEND(MDY(9,1,1999), YEAR to DAY), NULL);
INSERT INTO nastavnik(sifnastavnik, ime, prezime, pbrstan, siforgjed, koef, datumzaposlenod, datumzaposlendo)
  VALUES(913, 'Zdravko', 'Bartoluci', 34000, 100006, 9.5, EXTEND(MDY(9,1,1999), YEAR to DAY), NULL);
INSERT INTO nastavnik(sifnastavnik, ime, prezime, pbrstan, siforgjed, koef, datumzaposlenod, datumzaposlendo)
  VALUES(914, 'Jarno', 'Talan-Jagiæ', 34000, 100006, 9.9, EXTEND(MDY(9,1,1999), YEAR to DAY), NULL);
INSERT INTO nastavnik(sifnastavnik, ime, prezime, pbrstan, siforgjed, koef, datumzaposlenod, datumzaposlendo)
  VALUES(915, 'Zlatko', 'Banièek', 34000, 100006, 3.3, EXTEND(MDY(9,1,2002), YEAR to DAY), NULL);
INSERT INTO nastavnik(sifnastavnik, ime, prezime, pbrstan, siforgjed, koef, datumzaposlenod, datumzaposlendo)
  VALUES(916, 'Ivan', 'Fabeta', 34000, 100006, 3.7, EXTEND(MDY(9,6,1999), YEAR to DAY), EXTEND(MDY(2,13,1996), YEAR to DAY));
INSERT INTO nastavnik(sifnastavnik, ime, prezime, pbrstan, siforgjed, koef, datumzaposlenod, datumzaposlendo)
  VALUES(919, 'Dinko', 'Palej', 34000, 100006, 5.7, EXTEND(MDY(11,5,2002), YEAR to DAY), NULL);
INSERT INTO nastavnik(sifnastavnik, ime, prezime, pbrstan, siforgjed, koef, datumzaposlenod, datumzaposlendo)
  VALUES(920, 'Ante', 'Matas', 34000, 100006, 3.1, EXTEND(MDY(5,1,2001), YEAR to DAY), NULL);
INSERT INTO nastavnik(sifnastavnik, ime, prezime, pbrstan, siforgjed, koef, datumzaposlenod, datumzaposlendo)
  VALUES(923, 'Janko', 'Banoci', 34000, 100006, 4.3, EXTEND(MDY(5,1,2001), YEAR to DAY), NULL);
INSERT INTO nastavnik(sifnastavnik, ime, prezime, pbrstan, siforgjed, koef, datumzaposlenod, datumzaposlendo)
  VALUES(930, 'Miro', 'Laleta', 34000, 100006, 7.1, EXTEND(MDY(11,2,1999), YEAR to DAY), NULL);
INSERT INTO nastavnik(sifnastavnik, ime, prezime, pbrstan, siforgjed, koef, datumzaposlenod, datumzaposlendo)
  VALUES(932, 'Matej', 'Barišin', 34000, 100006, 8.7, EXTEND(MDY(12,1,1999), YEAR to DAY), NULL);
INSERT INTO nastavnik(sifnastavnik, ime, prezime, pbrstan, siforgjed, koef, datumzaposlenod, datumzaposlendo)
  VALUES(933, 'Neva', 'Salamon', 34000, 100006, 9.1, EXTEND(MDY(11,10,1999), YEAR to DAY), NULL);
INSERT INTO nastavnik(sifnastavnik, ime, prezime, pbrstan, siforgjed, koef, datumzaposlenod, datumzaposlendo)
  VALUES(934, 'Patrik', 'Markoviæ', 34000, 100006, 9.5, EXTEND(MDY(6,9,2003), YEAR to DAY), NULL);
INSERT INTO nastavnik(sifnastavnik, ime, prezime, pbrstan, siforgjed, koef, datumzaposlenod, datumzaposlendo)
  VALUES(935, 'Ljubo', 'Marušiæ', 34000, 100006, 9.9, EXTEND(MDY(12,1,1999), YEAR to DAY), EXTEND(MDY(2,1,1993), YEAR to DAY));
INSERT INTO nastavnik(sifnastavnik, ime, prezime, pbrstan, siforgjed, koef, datumzaposlenod, datumzaposlendo)
  VALUES(936, 'Andro', 'Ravliæ', 34000, 100006, 3.3, EXTEND(MDY(12,1,1999), YEAR to DAY), EXTEND(MDY(1,31,2006), YEAR to DAY));
INSERT INTO nastavnik(sifnastavnik, ime, prezime, pbrstan, siforgjed, koef, datumzaposlenod, datumzaposlendo)
  VALUES(937, 'Vlado', 'Èapko', 34000, 100006, 3.7, EXTEND(MDY(12,1,1999), YEAR to DAY), NULL);
INSERT INTO nastavnik(sifnastavnik, ime, prezime, pbrstan, siforgjed, koef, datumzaposlenod, datumzaposlendo)
  VALUES(941, 'Toni', 'Kandžija', 34000, 100006, 5.3, EXTEND(MDY(12,1,1999), YEAR to DAY), NULL);
INSERT INTO nastavnik(sifnastavnik, ime, prezime, pbrstan, siforgjed, koef, datumzaposlenod, datumzaposlendo)
  VALUES(942, 'Frane', 'Karaman', 34000, 100006, 5.7, EXTEND(MDY(12,1,1999), YEAR to DAY), EXTEND(MDY(9,30,2004), YEAR to DAY));
INSERT INTO nastavnik(sifnastavnik, ime, prezime, pbrstan, siforgjed, koef, datumzaposlenod, datumzaposlendo)
  VALUES(943, 'Ivo', 'Pavloviæ', 34000, 100006, 3.9, EXTEND(MDY(12,1,1999), YEAR to DAY), NULL);
INSERT INTO nastavnik(sifnastavnik, ime, prezime, pbrstan, siforgjed, koef, datumzaposlenod, datumzaposlendo)
  VALUES(944, 'Ante', 'Gagliardi', 34000, 100006, 4.3, EXTEND(MDY(12,1,1999), YEAR to DAY), EXTEND(MDY(10,12,2003), YEAR to DAY));
INSERT INTO nastavnik(sifnastavnik, ime, prezime, pbrstan, siforgjed, koef, datumzaposlenod, datumzaposlendo)
  VALUES(945, 'Zoran', 'Madiraca', 34000, 100006, 4.7, EXTEND(MDY(12,1,1999), YEAR to DAY), NULL);
INSERT INTO nastavnik(sifnastavnik, ime, prezime, pbrstan, siforgjed, koef, datumzaposlenod, datumzaposlendo)
  VALUES(946, 'Slaven', 'Babiæ', 34000, 100006, 5.1, EXTEND(MDY(5,23,2001), YEAR to DAY), NULL);
INSERT INTO nastavnik(sifnastavnik, ime, prezime, pbrstan, siforgjed, koef, datumzaposlenod, datumzaposlendo)
  VALUES(960, 'Ivo', 'Džidiæ', 34000, 100006, 4.5, EXTEND(MDY(2,22,2000), YEAR to DAY), EXTEND(MDY(2,28,2006), YEAR to DAY));
INSERT INTO nastavnik(sifnastavnik, ime, prezime, pbrstan, siforgjed, koef, datumzaposlenod, datumzaposlendo)
  VALUES(975, 'Ivan', 'Badanjak', 34000, 100006, 8.3, EXTEND(MDY(5,24,2000), YEAR to DAY), NULL);
INSERT INTO nastavnik(sifnastavnik, ime, prezime, pbrstan, siforgjed, koef, datumzaposlenod, datumzaposlendo)
  VALUES(982, 'Emil', 'Æavar', 34000, 100006, 6.3, EXTEND(MDY(7,13,2000), YEAR to DAY), NULL);
INSERT INTO nastavnik(sifnastavnik, ime, prezime, pbrstan, siforgjed, koef, datumzaposlenod, datumzaposlendo)
  VALUES(987, 'Antoaneta', 'Kalogjera', 34000, 100006, 8.3, EXTEND(MDY(7,18,2000), YEAR to DAY), NULL);
INSERT INTO nastavnik(sifnastavnik, ime, prezime, pbrstan, siforgjed, koef, datumzaposlenod, datumzaposlendo)
  VALUES(988, 'Maja', 'Mariæ', 34000, 100006, 8.7, EXTEND(MDY(7,21,2000), YEAR to DAY), EXTEND(MDY(12,31,2005), YEAR to DAY));
INSERT INTO nastavnik(sifnastavnik, ime, prezime, pbrstan, siforgjed, koef, datumzaposlenod, datumzaposlendo)
  VALUES(990, 'Mirna', 'Magdiæ', 34000, 100006, 9.5, EXTEND(MDY(7,1,2000), YEAR to DAY), EXTEND(MDY(10,1,2005), YEAR to DAY));
INSERT INTO nastavnik(sifnastavnik, ime, prezime, pbrstan, siforgjed, koef, datumzaposlenod, datumzaposlendo)
  VALUES(998, 'Branko', 'Tanodi', 10000, 100005, 3.5, EXTEND(MDY(5,1,2001), YEAR to DAY), EXTEND(MDY(1,31,2004), YEAR to DAY));
INSERT INTO nastavnik(sifnastavnik, ime, prezime, pbrstan, siforgjed, koef, datumzaposlenod, datumzaposlendo)
  VALUES(999, 'Sunèica', 'Careviæ', 10000, 100005, 3.9, EXTEND(MDY(11,1,2002), YEAR to DAY), NULL);
INSERT INTO nastavnik(sifnastavnik, ime, prezime, pbrstan, siforgjed, koef, datumzaposlenod, datumzaposlendo)
  VALUES(1000, 'Božidar', 'Ban', 10000, 100005, 4.3, EXTEND(MDY(6,3,2002), YEAR to DAY), EXTEND(MDY(6,14,2000), YEAR to DAY));
INSERT INTO nastavnik(sifnastavnik, ime, prezime, pbrstan, siforgjed, koef, datumzaposlenod, datumzaposlendo)
  VALUES(1001, 'Sanja', 'Barkoviæ', 34550, 100005, 4.7, EXTEND(MDY(9,1,2003), YEAR to DAY), NULL);
INSERT INTO nastavnik(sifnastavnik, ime, prezime, pbrstan, siforgjed, koef, datumzaposlenod, datumzaposlendo)
  VALUES(1002, 'Željko', 'Bašiæ', 34550, 100005, 5.1, EXTEND(MDY(5,1,2001), YEAR to DAY), NULL);
INSERT INTO nastavnik(sifnastavnik, ime, prezime, pbrstan, siforgjed, koef, datumzaposlenod, datumzaposlendo)
  VALUES(1003, 'Petar', 'Galiæ', 34550, 100005, 5.5, EXTEND(MDY(6,1,2004), YEAR to DAY), NULL);
INSERT INTO nastavnik(sifnastavnik, ime, prezime, pbrstan, siforgjed, koef, datumzaposlenod, datumzaposlendo)
  VALUES(1004, 'Ljerka', 'Radiæ', 34550, 100005, 5.9, EXTEND(MDY(9,1,2003), YEAR to DAY), EXTEND(MDY(7,31,2000), YEAR to DAY));
INSERT INTO nastavnik(sifnastavnik, ime, prezime, pbrstan, siforgjed, koef, datumzaposlenod, datumzaposlendo)
  VALUES(1005, 'Drago', 'Mamužiæ', 34550, 100005, 7.1, EXTEND(MDY(9,1,2003), YEAR to DAY), NULL);
INSERT INTO nastavnik(sifnastavnik, ime, prezime, pbrstan, siforgjed, koef, datumzaposlenod, datumzaposlendo)
  VALUES(1006, 'Ljerka', 'Èaèe', 34550, 100005, 7.5, EXTEND(MDY(1,8,2002), YEAR to DAY), EXTEND(MDY(8,16,1998), YEAR to DAY));
INSERT INTO nastavnik(sifnastavnik, ime, prezime, pbrstan, siforgjed, koef, datumzaposlenod, datumzaposlendo)
  VALUES(1007, 'Zdenko', 'Bajiæ', 34550, 100005, 7.9, EXTEND(MDY(11,22,2003), YEAR to DAY), NULL);
INSERT INTO nastavnik(sifnastavnik, ime, prezime, pbrstan, siforgjed, koef, datumzaposlenod, datumzaposlendo)
  VALUES(1008, 'Vjekoslava', 'Magerle', 34550, 100005, 8.3, EXTEND(MDY(5,1,2001), YEAR to DAY), EXTEND(MDY(5,14,2006), YEAR to DAY));
INSERT INTO nastavnik(sifnastavnik, ime, prezime, pbrstan, siforgjed, koef, datumzaposlenod, datumzaposlendo)
  VALUES(1009, 'Vladimir', 'Habajec', 34550, 100005, 8.7, EXTEND(MDY(11,1,2000), YEAR to DAY), EXTEND(MDY(1,14,2003), YEAR to DAY));
INSERT INTO nastavnik(sifnastavnik, ime, prezime, pbrstan, siforgjed, koef, datumzaposlenod, datumzaposlendo)
  VALUES(1010, 'Nataša', 'Kasap', 34550, 100005, 9.1, EXTEND(MDY(11,1,2000), YEAR to DAY), NULL);
INSERT INTO nastavnik(sifnastavnik, ime, prezime, pbrstan, siforgjed, koef, datumzaposlenod, datumzaposlendo)
  VALUES(1035, 'Anton', 'Fajdetiæ', 34550, 100005, 3.7, EXTEND(MDY(3,1,2003), YEAR to DAY), NULL);
INSERT INTO nastavnik(sifnastavnik, ime, prezime, pbrstan, siforgjed, koef, datumzaposlenod, datumzaposlendo)
  VALUES(1036, 'Irena', 'Mamula', 34550, 100005, 4.1, EXTEND(MDY(2,8,2001), YEAR to DAY), NULL);
INSERT INTO nastavnik(sifnastavnik, ime, prezime, pbrstan, siforgjed, koef, datumzaposlenod, datumzaposlendo)
  VALUES(1037, 'Andrina', 'Hadžaliæ', 34550, 100005, 4.5, EXTEND(MDY(1,1,2001), YEAR to DAY), NULL);
INSERT INTO nastavnik(sifnastavnik, ime, prezime, pbrstan, siforgjed, koef, datumzaposlenod, datumzaposlendo)
  VALUES(1038, 'Ivana', 'Lapiæ', 34550, 100005, 4.9, EXTEND(MDY(5,1,2001), YEAR to DAY), NULL);
INSERT INTO nastavnik(sifnastavnik, ime, prezime, pbrstan, siforgjed, koef, datumzaposlenod, datumzaposlendo)
  VALUES(1045, 'Ljiljana', 'Kaiæ-Rak', 34550, 100005, 5.5, EXTEND(MDY(3,12,2001), YEAR to DAY), NULL);
INSERT INTO nastavnik(sifnastavnik, ime, prezime, pbrstan, siforgjed, koef, datumzaposlenod, datumzaposlendo)
  VALUES(1047, 'Milko', 'Pavlek', 34550, 100005, 6.3, EXTEND(MDY(3,26,2001), YEAR to DAY), NULL);
INSERT INTO nastavnik(sifnastavnik, ime, prezime, pbrstan, siforgjed, koef, datumzaposlenod, datumzaposlendo)
  VALUES(1055, 'Rea', 'Matutinoviæ', 35000, 100005, 3.3, EXTEND(MDY(5,1,2001), YEAR to DAY), NULL);
INSERT INTO nastavnik(sifnastavnik, ime, prezime, pbrstan, siforgjed, koef, datumzaposlenod, datumzaposlendo)
  VALUES(1086, 'Vlasta', 'Sabati', 35000, 100005, 8.7, EXTEND(MDY(9,3,2001), YEAR to DAY), NULL);
INSERT INTO nastavnik(sifnastavnik, ime, prezime, pbrstan, siforgjed, koef, datumzaposlenod, datumzaposlendo)
  VALUES(1087, 'Smiljana', 'Sajko', 35000, 100005, 9.1, EXTEND(MDY(9,3,2001), YEAR to DAY), NULL);
INSERT INTO nastavnik(sifnastavnik, ime, prezime, pbrstan, siforgjed, koef, datumzaposlenod, datumzaposlendo)
  VALUES(1088, 'Katja', 'Malekoviæ', 35000, 100005, 9.5, EXTEND(MDY(9,3,2001), YEAR to DAY), EXTEND(MDY(9,30,1996), YEAR to DAY));
INSERT INTO nastavnik(sifnastavnik, ime, prezime, pbrstan, siforgjed, koef, datumzaposlenod, datumzaposlendo)
  VALUES(1089, 'Jasminka', 'Rabuzin', 35000, 100005, 9.9, EXTEND(MDY(9,3,2001), YEAR to DAY), NULL);
INSERT INTO nastavnik(sifnastavnik, ime, prezime, pbrstan, siforgjed, koef, datumzaposlenod, datumzaposlendo)
  VALUES(1090, 'Višnja', 'Èatipoviæ-Stankoviæ', 35000, 100005, 3.3, EXTEND(MDY(9,3,2001), YEAR to DAY), NULL);
INSERT INTO nastavnik(sifnastavnik, ime, prezime, pbrstan, siforgjed, koef, datumzaposlenod, datumzaposlendo)
  VALUES(1091, 'Santa', 'Lajšiæ', 35000, 100005, 4.5, EXTEND(MDY(9,3,2001), YEAR to DAY), NULL);
INSERT INTO nastavnik(sifnastavnik, ime, prezime, pbrstan, siforgjed, koef, datumzaposlenod, datumzaposlendo)
  VALUES(1092, 'Damir', 'Èapo-Stankoviæ', 35000, 100005, 4.9, EXTEND(MDY(9,3,2001), YEAR to DAY), NULL);
INSERT INTO nastavnik(sifnastavnik, ime, prezime, pbrstan, siforgjed, koef, datumzaposlenod, datumzaposlendo)
  VALUES(6, 'Branka', 'Taušan', 10000, 100012, 7.9, EXTEND(MDY(5,1,2001), YEAR to DAY), NULL);
INSERT INTO nastavnik(sifnastavnik, ime, prezime, pbrstan, siforgjed, koef, datumzaposlenod, datumzaposlendo)
  VALUES(7, 'Antun', 'Macan', 10000, 100012, 8.3, EXTEND(MDY(5,1,2001), YEAR to DAY), NULL);
INSERT INTO nastavnik(sifnastavnik, ime, prezime, pbrstan, siforgjed, koef, datumzaposlenod, datumzaposlendo)
  VALUES(8, 'Željko', 'Maziæ', 10000, 100012, 8.7, EXTEND(MDY(5,1,2001), YEAR to DAY), NULL);
INSERT INTO nastavnik(sifnastavnik, ime, prezime, pbrstan, siforgjed, koef, datumzaposlenod, datumzaposlendo)
  VALUES(9, 'Drago', 'Fabris', 10000, 100012, 9.1, EXTEND(MDY(11,1,1959), YEAR to DAY), NULL);
INSERT INTO nastavnik(sifnastavnik, ime, prezime, pbrstan, siforgjed, koef, datumzaposlenod, datumzaposlendo)
  VALUES(10, 'Ivan', 'Radoševiæ', 10000, 100012, 9.5, EXTEND(MDY(5,1,2001), YEAR to DAY), NULL);
INSERT INTO nastavnik(sifnastavnik, ime, prezime, pbrstan, siforgjed, koef, datumzaposlenod, datumzaposlendo)
  VALUES(11, 'Lia', 'Žanetiæ', 10000, 100012, 9.9, EXTEND(MDY(5,1,2001), YEAR to DAY), NULL);
INSERT INTO nastavnik(sifnastavnik, ime, prezime, pbrstan, siforgjed, koef, datumzaposlenod, datumzaposlendo)
  VALUES(12, 'Marijo', 'Radiæ', 10000, 100012, 3.3, EXTEND(MDY(5,1,2001), YEAR to DAY), NULL);
INSERT INTO nastavnik(sifnastavnik, ime, prezime, pbrstan, siforgjed, koef, datumzaposlenod, datumzaposlendo)
  VALUES(13, 'Vjekoslav', 'Martinac', 10000, 100012, 4.5, EXTEND(MDY(10,1,1963), YEAR to DAY), EXTEND(MDY(12,30,2006), YEAR to DAY));
INSERT INTO nastavnik(sifnastavnik, ime, prezime, pbrstan, siforgjed, koef, datumzaposlenod, datumzaposlendo)
  VALUES(14, 'Ivo', 'Zakarija', 10000, 100012, 4.9, EXTEND(MDY(5,1,2001), YEAR to DAY), EXTEND(MDY(5,31,2003), YEAR to DAY));
INSERT INTO nastavnik(sifnastavnik, ime, prezime, pbrstan, siforgjed, koef, datumzaposlenod, datumzaposlendo)
  VALUES(15, 'Antun', 'Èatiæ', 10000, 100012, 5.3, EXTEND(MDY(5,1,2001), YEAR to DAY), NULL);
INSERT INTO nastavnik(sifnastavnik, ime, prezime, pbrstan, siforgjed, koef, datumzaposlenod, datumzaposlendo)
  VALUES(16, 'Jadran', 'Galaso', 10000, 100012, 5.7, EXTEND(MDY(5,1,1967), YEAR to DAY), NULL);
INSERT INTO nastavnik(sifnastavnik, ime, prezime, pbrstan, siforgjed, koef, datumzaposlenod, datumzaposlendo)
  VALUES(17, 'Marija', 'Galoviæ', 10000, 100012, 3.1, EXTEND(MDY(9,16,1960), YEAR to DAY), EXTEND(MDY(3,31,2004), YEAR to DAY));
INSERT INTO nastavnik(sifnastavnik, ime, prezime, pbrstan, siforgjed, koef, datumzaposlenod, datumzaposlendo)
  VALUES(19, 'Matko', 'Šakiæ', 10000, 36, 3.9, EXTEND(MDY(5,1,2001), YEAR to DAY), NULL);
INSERT INTO nastavnik(sifnastavnik, ime, prezime, pbrstan, siforgjed, koef, datumzaposlenod, datumzaposlendo)
  VALUES(20, 'Željko', 'Žaniæ', 10000, 36, 4.3, EXTEND(MDY(5,1,2001), YEAR to DAY), NULL);
INSERT INTO nastavnik(sifnastavnik, ime, prezime, pbrstan, siforgjed, koef, datumzaposlenod, datumzaposlendo)
  VALUES(21, 'Nikša', 'Cajner', 10000, 36, 4.7, EXTEND(MDY(5,1,2001), YEAR to DAY), NULL);
INSERT INTO nastavnik(sifnastavnik, ime, prezime, pbrstan, siforgjed, koef, datumzaposlenod, datumzaposlendo)
  VALUES(22, 'Ivan', 'Mahoviæ', 10000, 36, 5.1, EXTEND(MDY(10,1,1968), YEAR to DAY), NULL);
INSERT INTO nastavnik(sifnastavnik, ime, prezime, pbrstan, siforgjed, koef, datumzaposlenod, datumzaposlendo)
  VALUES(23, 'Vedran', 'Math', 10000, 36, 5.5, EXTEND(MDY(5,1,2001), YEAR to DAY), NULL);
INSERT INTO nastavnik(sifnastavnik, ime, prezime, pbrstan, siforgjed, koef, datumzaposlenod, datumzaposlendo)
  VALUES(24, 'Mate', 'Mavriæ', 10000, 36, 5.9, EXTEND(MDY(5,1,2001), YEAR to DAY), NULL);
INSERT INTO nastavnik(sifnastavnik, ime, prezime, pbrstan, siforgjed, koef, datumzaposlenod, datumzaposlendo)
  VALUES(36, 'Zrinka', 'Balen', NULL, 36, 4.5, EXTEND(MDY(5,1,2001), YEAR to DAY), NULL);
INSERT INTO nastavnik(sifnastavnik, ime, prezime, pbrstan, siforgjed, koef, datumzaposlenod, datumzaposlendo)
  VALUES(37, 'Davor', 'Car', NULL, 36, 5.7, EXTEND(MDY(5,1,2001), YEAR to DAY), NULL);
INSERT INTO nastavnik(sifnastavnik, ime, prezime, pbrstan, siforgjed, koef, datumzaposlenod, datumzaposlendo)
  VALUES(38, 'Dubravko', 'Marušiæ', NULL, 36, 3.1, EXTEND(MDY(5,1,2001), YEAR to DAY), NULL);
INSERT INTO nastavnik(sifnastavnik, ime, prezime, pbrstan, siforgjed, koef, datumzaposlenod, datumzaposlendo)
  VALUES(39, 'Katarina', 'Matijeviæ', NULL, 36, 3.5, EXTEND(MDY(5,1,2001), YEAR to DAY), NULL);
INSERT INTO nastavnik(sifnastavnik, ime, prezime, pbrstan, siforgjed, koef, datumzaposlenod, datumzaposlendo)
  VALUES(40, 'Igor', 'Pavkoviæ', NULL, 36, 3.9, EXTEND(MDY(5,1,2001), YEAR to DAY), NULL);
INSERT INTO nastavnik(sifnastavnik, ime, prezime, pbrstan, siforgjed, koef, datumzaposlenod, datumzaposlendo)
  VALUES(41, 'Mario', 'Ðarmati-Car', 10000, 36, 4.3, EXTEND(MDY(1,1,1975), YEAR to DAY), NULL);
INSERT INTO nastavnik(sifnastavnik, ime, prezime, pbrstan, siforgjed, koef, datumzaposlenod, datumzaposlendo)
  VALUES(43, 'Vladimir', 'Parunov', 10000, 36, 5.1, EXTEND(MDY(4,22,2002), YEAR to DAY), NULL);
INSERT INTO nastavnik(sifnastavnik, ime, prezime, pbrstan, siforgjed, koef, datumzaposlenod, datumzaposlendo)
  VALUES(55, 'Ivka', 'Radujkoviæ', 10000, 36, 3.7, EXTEND(MDY(5,1,2001), YEAR to DAY), NULL);
INSERT INTO nastavnik(sifnastavnik, ime, prezime, pbrstan, siforgjed, koef, datumzaposlenod, datumzaposlendo)
  VALUES(56, 'Petar', 'Raduka', 20000, 36, 4.1, EXTEND(MDY(5,1,2001), YEAR to DAY), NULL);
INSERT INTO nastavnik(sifnastavnik, ime, prezime, pbrstan, siforgjed, koef, datumzaposlenod, datumzaposlendo)
  VALUES(57, 'Mladen', 'Rajèiæ', 20000, 36, 4.5, EXTEND(MDY(5,1,2001), YEAR to DAY), NULL);
INSERT INTO nastavnik(sifnastavnik, ime, prezime, pbrstan, siforgjed, koef, datumzaposlenod, datumzaposlendo)
  VALUES(59, 'Davor', 'Šavor', 20000, 36, 5.3, EXTEND(MDY(5,1,2001), YEAR to DAY), NULL);
INSERT INTO nastavnik(sifnastavnik, ime, prezime, pbrstan, siforgjed, koef, datumzaposlenod, datumzaposlendo)
  VALUES(60, 'Vanja', 'Završki', 20000, 36, 5.7, EXTEND(MDY(5,1,2001), YEAR to DAY), NULL);
INSERT INTO nastavnik(sifnastavnik, ime, prezime, pbrstan, siforgjed, koef, datumzaposlenod, datumzaposlendo)
  VALUES(61, 'Periša', 'Banjad Galiæ', 20000, 36, 3.9, EXTEND(MDY(5,1,2001), YEAR to DAY), NULL);
INSERT INTO nastavnik(sifnastavnik, ime, prezime, pbrstan, siforgjed, koef, datumzaposlenod, datumzaposlendo)
  VALUES(84, 'Èedomir', 'Paunoviæ', 20000, 36, 3.9, EXTEND(MDY(5,1,2001), YEAR to DAY), NULL);
INSERT INTO nastavnik(sifnastavnik, ime, prezime, pbrstan, siforgjed, koef, datumzaposlenod, datumzaposlendo)
  VALUES(87, 'Dragan', 'Magdaleniæ', 20000, 36, 5.9, EXTEND(MDY(5,21,2002), YEAR to DAY), NULL);
INSERT INTO nastavnik(sifnastavnik, ime, prezime, pbrstan, siforgjed, koef, datumzaposlenod, datumzaposlendo)
  VALUES(92, 'Mladen', 'Babiæ-Ravniæ', 20000, 36, 7.9, EXTEND(MDY(5,1,2001), YEAR to DAY), NULL);
INSERT INTO nastavnik(sifnastavnik, ime, prezime, pbrstan, siforgjed, koef, datumzaposlenod, datumzaposlendo)
  VALUES(94, 'Dragutin', 'Pavlekoviæ', 20000, 36, 8.7, EXTEND(MDY(5,1,2001), YEAR to DAY), NULL);
INSERT INTO nastavnik(sifnastavnik, ime, prezime, pbrstan, siforgjed, koef, datumzaposlenod, datumzaposlendo)
  VALUES(95, 'Mladen', 'Ravniæ', 20000, 36, 9.1, EXTEND(MDY(5,1,2001), YEAR to DAY), NULL);
INSERT INTO nastavnik(sifnastavnik, ime, prezime, pbrstan, siforgjed, koef, datumzaposlenod, datumzaposlendo)
  VALUES(104, 'Janez', 'Hanzer', 20000, 36, 7.9, EXTEND(MDY(12,15,1988), YEAR to DAY), NULL);



INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(1, 2003, 'D-A1', 690, 'D159');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(1, 2003, 'D-A2', 690, 'D159');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(1, 2003, 'D-A3', 690, 'D159');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(1, 2003, 'D-A4', 690, 'D159');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(1, 2003, 'D-A5', 690, 'D159');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(1, 2003, 'D-B1', 690, 'D159');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(1, 2003, 'D-B2', 690, 'D159');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(1, 2003, 'D-B3', 690, 'D159');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(1, 2003, 'D-B4', 690, 'D159');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(1, 2003, 'D-B5', 690, 'D159');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(1, 2004, 'D-A1', 690, 'D033');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(1, 2004, 'D-A2', 690, 'D159');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(1, 2004, 'D-A3', 690, 'D159');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(1, 2004, 'D-A4', 690, 'D033');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(1, 2004, 'D-A5', 690, 'D033');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(1, 2004, 'D-B1', 690, 'D159');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(1, 2004, 'D-B2', 690, 'D159');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(1, 2004, 'D-B3', 690, 'D159');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(1, 2004, 'D-B4', 690, 'D033');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(1, 2004, 'D-B5', 690, 'D159');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(1, 2004, 'D-C1', 690, 'D159');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(1, 2004, 'D-E1', 690, 'D159');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(1, 2004, 'D-F1', 690, 'D159');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(1, 2004, 'D-G1', 690, 'D159');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(1, 2004, 'D-H1', 690, 'D159');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(1, 2004, 'D-I1', 690, 'D159');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(1, 2004, 'D-I2', 690, 'D159');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(1, 2005, 'A-A', 690, 'D1');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(1, 2005, 'D-A1', 690, 'D159');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(1, 2005, 'D-A2', 690, 'D159');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(1, 2005, 'D-A3', 690, 'D159');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(1, 2005, 'D-A4', 690, 'D033');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(1, 2005, 'D-A5', 690, 'D159');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(1, 2005, 'D-B1', 690, 'D159');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(1, 2005, 'D-B2', 690, 'D159');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(1, 2005, 'D-B3', 690, 'D159');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(1, 2005, 'D-B4', 690, 'D159');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(1, 2005, 'D-B5', 690, 'D159');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(1, 2005, 'D-C1', 690, 'D159');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(1, 2005, 'D-E1', 690, 'D159');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(1, 2005, 'D-F1', 690, 'D159');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(1, 2005, 'D-G1', 690, 'D159');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(1, 2005, 'D-H1', 690, 'D159');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(1, 2005, 'D-I1', 690, 'D159');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(1, 2005, 'D-I2', 690, 'D159');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(2, 2003, 'C-A1', 919, 'D263');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(2, 2003, 'C-A2', 919, 'D263');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(2, 2003, 'C-A3', 919, 'D263');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(2, 2003, 'C-A4', 919, 'D263');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(2, 2003, 'C-A5', 919, 'D263');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(2, 2003, 'C-B1', 919, 'D263');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(2, 2003, 'C-B2', 919, 'A204');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(2, 2003, 'C-B3', 919, 'D263');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(2, 2003, 'C-B4', 919, 'D263');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(2, 2003, 'C-B5', 919, 'D263');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(2, 2004, 'C-A1', 919, 'D263');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(2, 2004, 'C-A2', 919, 'D263');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(2, 2004, 'C-A3', 919, 'D263');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(2, 2004, 'C-A4', 919, 'D263');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(2, 2004, 'C-A5', 919, 'D263');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(2, 2004, 'C-B1', 919, 'D263');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(2, 2004, 'C-B2', 919, 'D263');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(2, 2004, 'C-B3', 919, 'D263');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(2, 2004, 'C-B4', 919, 'D263');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(2, 2004, 'C-B5', 919, 'D263');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(2, 2005, 'C-B1', 919, 'D263');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(2, 2005, 'C-B2', 919, 'D263');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(2, 2005, 'C-B3', 919, 'D263');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(2, 2005, 'C-B4', 919, 'D263');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(2, 2005, 'C-B5', 919, 'D263');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(2, 2006, 'C-B1', 919, 'D263');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(2, 2006, 'C-B2', 919, 'D263');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(2, 2006, 'C-B3', 919, 'D263');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(2, 2006, 'C-B4', 919, 'D263');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(2, 2006, 'C-B5', 919, 'D263');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(3, 2003, 'C-A1', 550, 'A311');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(3, 2003, 'C-A2', 550, 'B2');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(3, 2003, 'C-A3', 550, 'B2');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(3, 2003, 'C-A4', 550, 'A204');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(3, 2003, 'C-A5', 550, 'A311');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(3, 2004, 'C-A1', 550, 'A204');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(3, 2004, 'C-A2', 550, 'A311');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(3, 2004, 'C-A3', 550, 'A311');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(3, 2004, 'C-A4', 550, 'A311');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(3, 2004, 'C-A5', 550, 'A311');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(3, 2005, 'A-A', 550, 'A311');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(3, 2005, 'C-A1', 550, 'A311');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(3, 2005, 'C-A2', 550, 'A204');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(3, 2005, 'C-A3', 550, 'A311');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(3, 2005, 'C-A4', 550, 'A311');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(3, 2005, 'C-A5', 550, 'A311');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(4, 2003, 'C-B1', 946, 'D262');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(4, 2003, 'C-B2', 946, 'D347');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(4, 2003, 'C-B3', 946, 'D262');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(4, 2003, 'C-B4', 946, 'D262');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(4, 2003, 'C-B5', 946, 'D262');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(4, 2004, 'C-B1', 946, 'D262');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(4, 2004, 'C-B2', 946, 'D262');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(4, 2004, 'C-B3', 946, 'D262');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(4, 2004, 'C-B4', 946, 'D262');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(4, 2004, 'C-B5', 946, 'D262');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(4, 2005, 'C-B1', 946, 'D262');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(4, 2005, 'C-B2', 946, 'D262');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(4, 2005, 'C-B3', 946, 'D262');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(4, 2005, 'C-B4', 946, 'D262');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(4, 2005, 'C-B5', 946, 'D262');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(4, 2006, 'C-B1', 946, 'D262');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(4, 2006, 'C-B2', 946, 'D262');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(4, 2006, 'C-B3', 946, 'D262');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(4, 2006, 'C-B4', 946, 'D262');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(4, 2006, 'C-B5', 946, 'D262');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(5, 2003, 'C-B1', 930, 'D262');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(5, 2003, 'C-B2', 930, 'C603');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(5, 2003, 'C-B3', 930, 'D262');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(5, 2003, 'C-B4', 930, 'D262');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(5, 2003, 'C-B5', 930, 'D262');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(5, 2003, 'D-A1', 930, 'D262');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(5, 2003, 'D-A2', 930, 'D262');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(5, 2003, 'D-A3', 930, 'D262');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(5, 2003, 'D-A4', 930, 'D262');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(5, 2004, 'C-B1', 930, 'D262');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(5, 2004, 'C-B2', 930, 'D262');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(5, 2004, 'C-B3', 930, 'D262');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(5, 2004, 'C-B4', 930, 'D262');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(5, 2004, 'C-B5', 930, 'D262');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(5, 2004, 'D-A1', 930, 'D262');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(5, 2004, 'D-A2', 930, 'D262');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(5, 2004, 'D-A3', 930, 'D262');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(5, 2004, 'D-A4', 930, 'C603');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(5, 2004, 'D-A5', 930, 'D262');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(5, 2005, 'C-B1', 930, 'D262');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(5, 2005, 'C-B2', 930, 'D262');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(5, 2005, 'C-B3', 930, 'D262');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(5, 2005, 'C-B4', 930, 'D262');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(5, 2005, 'C-B5', 930, 'D262');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(5, 2006, 'C-B1', 930, 'D262');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(5, 2006, 'C-B2', 930, 'D262');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(5, 2006, 'C-B3', 930, 'D262');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(5, 2006, 'C-B4', 930, 'D262');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(5, 2006, 'C-B5', 930, 'D262');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(6, 2003, 'C-B1', 919, 'A302');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(6, 2003, 'C-B2', 919, 'D158');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(6, 2003, 'C-B3', 919, 'D158');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(6, 2003, 'C-B4', 919, 'A302');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(6, 2003, 'C-B5', 919, 'A302');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(6, 2004, 'C-B1', 919, 'A302');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(6, 2004, 'C-B2', 919, 'A302');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(6, 2004, 'C-B3', 919, 'A302');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(6, 2004, 'C-B4', 919, 'A302');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(6, 2004, 'C-B5', 919, 'A302');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(6, 2005, 'A-A', 919, 'A302');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(6, 2005, 'C-B1', 919, 'A302');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(6, 2005, 'C-B2', 919, 'A302');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(6, 2005, 'C-B3', 919, 'A302');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(6, 2005, 'C-B4', 919, 'A302');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(6, 2005, 'C-B5', 919, 'A302');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(7, 2003, 'C-B1', 946, 'D270');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(7, 2003, 'C-B2', 946, 'A204');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(7, 2003, 'C-B3', 946, 'A204');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(7, 2003, 'C-B4', 946, 'D270');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(7, 2003, 'C-B5', 946, 'D270');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(7, 2004, 'C-B1', 946, 'D270');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(7, 2004, 'C-B2', 946, 'D270');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(7, 2004, 'C-B3', 946, 'D270');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(7, 2004, 'C-B4', 946, 'D270');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(7, 2004, 'C-B5', 946, 'D270');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(7, 2005, 'A-A', 946, 'D270');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(7, 2005, 'C-B1', 946, 'D270');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(7, 2005, 'C-B2', 946, 'D270');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(7, 2005, 'C-B3', 946, 'D270');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(7, 2005, 'C-B4', 946, 'D270');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(7, 2005, 'C-B5', 946, 'D270');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(8, 2003, 'C-B1', 902, 'A302');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(8, 2003, 'C-B2', 902, 'D347');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(8, 2003, 'C-B3', 902, 'D347');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(8, 2003, 'C-B4', 902, 'A302');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(8, 2003, 'C-B5', 902, 'A302');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(8, 2004, 'C-B1', 902, 'A302');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(8, 2004, 'C-B2', 902, 'A302');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(8, 2004, 'C-B3', 902, 'A302');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(8, 2004, 'C-B4', 902, 'A302');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(8, 2004, 'C-B5', 902, 'A302');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(8, 2005, 'A-A', 902, 'A302');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(8, 2005, 'C-B1', 902, 'A302');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(8, 2005, 'C-B2', 902, 'A302');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(8, 2005, 'C-B3', 902, 'A302');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(8, 2005, 'C-B4', 902, 'A302');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(8, 2005, 'C-B5', 902, 'A302');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(9, 2003, 'C-A1', 550, 'D259');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(9, 2003, 'C-A2', 550, 'C603');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(9, 2003, 'C-A3', 550, 'A109');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(9, 2003, 'C-A4', 550, 'C603');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(9, 2003, 'C-A5', 550, 'D259');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(9, 2003, 'C-B1', 550, 'D259');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(9, 2003, 'C-B2', 550, 'C603');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(9, 2003, 'C-B3', 550, 'D259');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(9, 2003, 'C-B4', 550, 'D259');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(9, 2003, 'C-B5', 550, 'D259');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(9, 2004, 'C-A1', 550, 'C603');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(9, 2004, 'C-A2', 550, 'D259');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(9, 2004, 'C-A3', 550, 'D259');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(9, 2004, 'C-A4', 550, 'D259');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(9, 2004, 'C-A5', 550, 'D259');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(9, 2004, 'C-B1', 550, 'D259');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(9, 2004, 'C-B2', 550, 'D259');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(9, 2004, 'C-B3', 550, 'D259');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(9, 2004, 'C-B4', 550, 'D259');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(9, 2004, 'C-B5', 550, 'D259');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(9, 2005, 'C-A1', 550, 'D259');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(9, 2005, 'C-A2', 550, 'C603');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(9, 2005, 'C-A3', 550, 'D259');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(9, 2005, 'C-A4', 550, 'D259');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(9, 2005, 'C-A5', 550, 'D259');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(9, 2005, 'C-B1', 550, 'D259');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(9, 2005, 'C-B2', 550, 'D259');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(9, 2005, 'C-B3', 550, 'D259');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(9, 2005, 'C-B4', 550, 'D259');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(9, 2005, 'C-B5', 550, 'D259');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(9, 2006, 'C-A1', 550, 'D259');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(9, 2006, 'C-A2', 550, 'D259');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(9, 2006, 'C-A3', 550, 'D259');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(9, 2006, 'C-A4', 550, 'D259');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(9, 2006, 'C-A5', 550, 'D259');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(9, 2006, 'C-B1', 550, 'D259');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(9, 2006, 'C-B2', 550, 'D259');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(9, 2006, 'C-B3', 550, 'D259');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(9, 2006, 'C-B4', 550, 'D259');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(9, 2006, 'C-B5', 550, 'D259');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(10, 2003, 'C-A1', 535, 'D262');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(10, 2003, 'C-A2', 535, 'A204');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(10, 2003, 'C-A3', 535, 'D160');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(10, 2003, 'C-A4', 535, 'A204');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(10, 2003, 'C-A5', 535, 'D262');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(10, 2004, 'C-A1', 535, 'A204');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(10, 2004, 'C-A2', 535, 'D262');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(10, 2004, 'C-A3', 535, 'D262');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(10, 2004, 'C-A4', 535, 'D262');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(10, 2004, 'C-A5', 535, 'D262');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(10, 2005, 'C-A1', 535, 'D262');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(10, 2005, 'C-A2', 535, 'D262');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(10, 2005, 'C-A3', 535, 'D262');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(10, 2005, 'C-A4', 535, 'D262');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(10, 2005, 'C-A5', 535, 'D262');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(10, 2006, 'C-A1', 535, 'D262');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(10, 2006, 'C-A2', 535, 'A204');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(10, 2006, 'C-A3', 535, 'D262');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(10, 2006, 'C-A4', 535, 'D262');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(10, 2006, 'C-A5', 535, 'D262');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(11, 2003, 'C-A1', 535, 'D263');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(11, 2003, 'C-A2', 535, 'A205');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(11, 2003, 'C-A3', 535, 'A102');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(11, 2003, 'C-A4', 535, 'A205');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(11, 2003, 'C-A5', 535, 'D263');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(11, 2004, 'C-A1', 535, 'A205');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(11, 2004, 'C-A2', 535, 'D263');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(11, 2004, 'C-A3', 535, 'D263');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(11, 2004, 'C-A4', 535, 'D263');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(11, 2004, 'C-A5', 535, 'D263');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(11, 2005, 'A-A', 535, 'A205');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(11, 2005, 'C-A1', 535, 'D263');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(11, 2005, 'C-A2', 535, 'A205');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(11, 2005, 'C-A3', 535, 'D263');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(11, 2005, 'C-A4', 535, 'D263');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(11, 2005, 'C-A5', 535, 'D263');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(12, 2003, 'C-A1', 535, 'D269');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(12, 2003, 'C-A2', 535, 'D033');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(12, 2003, 'C-A3', 535, 'A111');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(12, 2003, 'C-A4', 535, 'D033');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(12, 2003, 'C-A5', 535, 'D269');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(12, 2003, 'C-B1', 490, 'D269');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(12, 2003, 'C-B2', 490, 'D347');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(12, 2003, 'C-B3', 490, 'D347');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(12, 2003, 'C-B4', 490, 'D269');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(12, 2003, 'C-B5', 490, 'D269');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(12, 2004, 'C-A1', 535, 'D033');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(12, 2004, 'C-A2', 535, 'D269');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(12, 2004, 'C-A3', 535, 'D269');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(12, 2004, 'C-A4', 535, 'D269');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(12, 2004, 'C-A5', 535, 'D269');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(12, 2004, 'C-B1', 490, 'D269');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(12, 2004, 'C-B2', 490, 'D269');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(12, 2004, 'C-B3', 490, 'D269');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(12, 2004, 'C-B4', 490, 'D269');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(12, 2004, 'C-B5', 490, 'D269');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(12, 2005, 'A-A', 535, 'D269');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(12, 2005, 'C-A1', 535, 'D269');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(12, 2005, 'C-A2', 535, 'D033');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(12, 2005, 'C-A3', 535, 'D269');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(12, 2005, 'C-A4', 535, 'D269');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(12, 2005, 'C-A5', 535, 'D269');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(12, 2005, 'C-B1', 490, 'D269');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(12, 2005, 'C-B2', 490, 'D269');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(12, 2005, 'C-B3', 490, 'D269');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(12, 2005, 'C-B4', 490, 'D269');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(12, 2005, 'C-B5', 490, 'D269');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(13, 2003, 'D-A1', 484, 'D251');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(13, 2003, 'D-A2', 484, 'D251');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(13, 2003, 'D-A3', 484, 'D251');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(13, 2003, 'D-A4', 484, 'D251');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(13, 2004, 'D-A1', 484, 'A204');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(13, 2004, 'D-A2', 484, 'D251');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(13, 2004, 'D-A3', 484, 'D251');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(13, 2004, 'D-A4', 484, 'A204');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(13, 2004, 'D-A5', 484, 'A204');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(13, 2005, 'D-A1', 484, 'D251');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(13, 2005, 'D-A2', 484, 'D251');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(13, 2005, 'D-A3', 484, 'D251');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(13, 2005, 'D-A4', 484, 'A204');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(13, 2005, 'D-A5', 484, 'D251');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(13, 2006, 'D-A1', 484, 'D251');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(13, 2006, 'D-A2', 484, 'D251');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(13, 2006, 'D-A3', 484, 'D251');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(13, 2006, 'D-A4', 484, 'D251');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(13, 2006, 'D-A5', 484, 'A204');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(14, 2003, 'D-A1', 472, 'D263');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(14, 2003, 'D-A2', 472, 'D263');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(14, 2003, 'D-A3', 472, 'D263');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(14, 2003, 'D-A4', 472, 'D263');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(14, 2003, 'D-A5', 472, 'D263');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(14, 2004, 'D-A1', 472, 'D347');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(14, 2004, 'D-A2', 472, 'D263');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(14, 2004, 'D-A3', 472, 'D263');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(14, 2004, 'D-A4', 472, 'D347');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(14, 2004, 'D-A5', 472, 'D347');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(14, 2005, 'A-A', 535, 'D158');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(14, 2005, 'D-A1', 472, 'D263');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(14, 2005, 'D-A2', 472, 'D263');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(14, 2005, 'D-A3', 472, 'D263');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(14, 2005, 'D-A4', 472, 'D347');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(14, 2005, 'D-A5', 472, 'D263');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(15, 2003, 'D-A1', 545, 'D262');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(15, 2003, 'D-A2', 545, 'D262');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(15, 2003, 'D-A3', 545, 'D262');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(15, 2003, 'D-A4', 545, 'D262');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(15, 2004, 'D-A1', 545, 'A104');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(15, 2004, 'D-A2', 545, 'D262');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(15, 2004, 'D-A3', 545, 'D262');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(15, 2004, 'D-A4', 545, 'A104');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(15, 2004, 'D-A5', 545, 'A104');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(15, 2005, 'D-A1', 545, 'D262');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(15, 2005, 'D-A2', 545, 'D262');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(15, 2005, 'D-A3', 545, 'D262');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(15, 2005, 'D-A4', 545, 'A104');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(15, 2005, 'D-A5', 545, 'D262');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(15, 2006, 'D-A1', 545, 'D262');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(15, 2006, 'D-A2', 545, 'D262');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(15, 2006, 'D-A3', 545, 'D262');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(15, 2006, 'D-A4', 545, 'D262');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(15, 2006, 'D-A5', 545, 'A104');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(17, 2003, 'D-A1', 313, 'A105');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(17, 2003, 'D-A2', 313, 'A105');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(17, 2003, 'D-A3', 313, 'A105');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(17, 2003, 'D-A4', 313, 'A105');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(17, 2004, 'D-A1', 313, 'A205');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(17, 2004, 'D-A2', 313, 'A105');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(17, 2004, 'D-A3', 313, 'A105');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(17, 2004, 'D-A4', 313, 'A205');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(17, 2004, 'D-A5', 313, 'A205');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(17, 2005, 'D-A1', 313, 'A105');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(17, 2005, 'D-A2', 313, 'A105');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(17, 2005, 'D-A3', 313, 'A105');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(17, 2005, 'D-A4', 313, 'A205');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(17, 2005, 'D-A5', 313, 'A105');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(17, 2006, 'D-A1', 313, 'A105');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(17, 2006, 'D-A2', 313, 'A105');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(17, 2006, 'D-A3', 313, 'A105');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(17, 2006, 'D-A4', 313, 'A105');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(17, 2006, 'D-A5', 313, 'A205');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(18, 2003, 'D-B1', 920, 'D270');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(18, 2003, 'D-B2', 920, 'D270');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(18, 2003, 'D-B3', 920, 'D270');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(18, 2003, 'D-B4', 920, 'D270');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(18, 2004, 'D-B1', 920, 'D270');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(18, 2004, 'D-B2', 920, 'D270');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(18, 2004, 'D-B3', 920, 'D270');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(18, 2004, 'D-B4', 920, 'A205');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(18, 2004, 'D-B5', 920, 'D270');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(18, 2005, 'D-B1', 920, 'D270');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(18, 2005, 'D-B2', 920, 'D270');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(18, 2005, 'D-B3', 920, 'D270');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(18, 2005, 'D-B4', 920, 'D270');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(18, 2005, 'D-B5', 920, 'D270');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(18, 2006, 'D-B1', 920, 'D270');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(18, 2006, 'D-B2', 920, 'D270');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(18, 2006, 'D-B3', 920, 'D270');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(18, 2006, 'D-B4', 920, 'D270');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(18, 2006, 'D-B5', 920, 'D270');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(19, 2003, 'D-B1', 932, 'D263');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(19, 2003, 'D-B2', 932, 'D263');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(19, 2003, 'D-B3', 932, 'D263');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(19, 2003, 'D-B4', 932, 'D263');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(19, 2004, 'D-B1', 932, 'D263');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(19, 2004, 'D-B2', 932, 'D263');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(19, 2004, 'D-B3', 932, 'D263');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(19, 2004, 'D-B4', 932, 'C603');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(19, 2004, 'D-B5', 932, 'D263');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(19, 2005, 'D-B1', 932, 'D263');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(19, 2005, 'D-B2', 932, 'D263');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(19, 2005, 'D-B3', 932, 'D263');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(19, 2005, 'D-B4', 932, 'D263');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(19, 2005, 'D-B5', 932, 'D263');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(19, 2006, 'D-B1', 932, 'D263');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(19, 2006, 'D-B2', 932, 'D263');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(19, 2006, 'D-B3', 932, 'D263');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(19, 2006, 'D-B4', 932, 'D263');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(19, 2006, 'D-B5', 932, 'D263');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(20, 2003, 'D-B1', 932, 'D269');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(20, 2003, 'D-B2', 932, 'D269');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(20, 2003, 'D-B3', 932, 'D269');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(20, 2003, 'D-B4', 932, 'D269');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(20, 2004, 'D-B1', 932, 'D269');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(20, 2004, 'D-B2', 932, 'D269');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(20, 2004, 'D-B3', 932, 'D269');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(20, 2004, 'D-B4', 932, 'A104');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(20, 2004, 'D-B5', 932, 'D269');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(20, 2005, 'D-B1', 932, 'D269');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(20, 2005, 'D-B2', 932, 'D269');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(20, 2005, 'D-B3', 932, 'D269');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(20, 2005, 'D-B4', 932, 'D269');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(20, 2005, 'D-B5', 932, 'D269');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(20, 2006, 'D-B1', 932, 'D269');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(20, 2006, 'D-B2', 932, 'D269');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(20, 2006, 'D-B3', 932, 'D269');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(20, 2006, 'D-B4', 932, 'D269');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(20, 2006, 'D-B5', 932, 'D269');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(21, 2003, 'D-B1', 987, 'D258');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(21, 2003, 'D-B2', 987, 'D258');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(21, 2003, 'D-B3', 987, 'D258');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(21, 2003, 'D-B4', 987, 'D258');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(21, 2003, 'D-B5', 987, 'D258');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(21, 2004, 'D-B1', 987, 'D258');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(21, 2004, 'D-B2', 987, 'D258');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(21, 2004, 'D-B3', 987, 'D258');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(21, 2004, 'D-B4', 987, 'A104');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(21, 2004, 'D-B5', 987, 'D258');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(21, 2005, 'A-A', 987, 'D258');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(21, 2005, 'D-B1', 987, 'D258');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(21, 2005, 'D-B2', 987, 'D258');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(21, 2005, 'D-B3', 987, 'D258');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(21, 2005, 'D-B4', 987, 'D258');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(21, 2005, 'D-B5', 987, 'D258');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(22, 2003, 'D-B1', 923, 'A105');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(22, 2003, 'D-B2', 923, 'A105');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(22, 2003, 'D-B3', 923, 'A105');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(22, 2003, 'D-B4', 923, 'A105');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(22, 2003, 'D-B5', 923, 'A105');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(22, 2004, 'D-B1', 923, 'A105');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(22, 2004, 'D-B2', 923, 'A105');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(22, 2004, 'D-B3', 923, 'A105');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(22, 2004, 'D-B4', 923, 'A204');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(22, 2004, 'D-B5', 923, 'A105');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(22, 2005, 'A-A', 923, 'A105');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(22, 2005, 'D-B1', 923, 'A105');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(22, 2005, 'D-B2', 923, 'A105');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(22, 2005, 'D-B3', 923, 'A105');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(22, 2005, 'D-B4', 923, 'A105');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(22, 2005, 'D-B5', 923, 'A105');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(23, 2003, 'D-B1', 721, 'A301');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(23, 2003, 'D-B2', 721, 'A301');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(23, 2003, 'D-B3', 721, 'A301');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(23, 2003, 'D-B4', 721, 'A301');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(23, 2003, 'D-B5', 721, 'A301');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(23, 2004, 'D-B1', 721, 'A301');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(23, 2004, 'D-B2', 721, 'A301');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(23, 2004, 'D-B3', 721, 'A301');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(23, 2004, 'D-B4', 721, 'A104');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(23, 2004, 'D-B5', 721, 'A301');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(23, 2005, 'A-A', 721, 'A301');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(23, 2005, 'D-B1', 721, 'A301');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(23, 2005, 'D-B2', 721, 'A301');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(23, 2005, 'D-B3', 721, 'A301');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(23, 2005, 'D-B4', 721, 'A301');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(23, 2005, 'D-B5', 721, 'A301');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(25, 2003, 'D-B1', 923, 'D258');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(25, 2003, 'D-B2', 923, 'D258');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(25, 2003, 'D-B3', 923, 'D258');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(25, 2003, 'D-B4', 923, 'D258');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(25, 2003, 'D-B5', 923, 'D258');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(25, 2004, 'D-B1', 923, 'D258');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(25, 2004, 'D-B2', 923, 'D258');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(25, 2004, 'D-B3', 923, 'D258');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(25, 2004, 'D-B4', 923, 'D153');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(25, 2004, 'D-B5', 923, 'D258');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(25, 2005, 'D-B1', 923, 'D258');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(25, 2005, 'D-B2', 923, 'D258');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(25, 2005, 'D-B3', 923, 'D258');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(25, 2005, 'D-B4', 923, 'D258');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(25, 2005, 'D-B5', 923, 'D258');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(25, 2006, 'D-B1', 923, 'D258');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(25, 2006, 'D-B2', 923, 'D258');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(25, 2006, 'D-B3', 923, 'D258');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(25, 2006, 'D-B4', 923, 'D258');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(25, 2006, 'D-B5', 923, 'D258');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(26, 2003, 'D-A1', 530, 'D159');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(26, 2003, 'D-A2', 530, 'D159');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(26, 2003, 'D-A3', 530, 'D159');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(26, 2003, 'D-A4', 530, 'D159');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(26, 2003, 'D-A5', 530, 'D159');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(26, 2004, 'D-A1', 530, 'D153');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(26, 2004, 'D-A2', 530, 'D159');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(26, 2004, 'D-A3', 530, 'D159');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(26, 2004, 'D-A4', 530, 'D153');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(26, 2004, 'D-A5', 530, 'D159');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(26, 2005, 'D-A1', 530, 'D159');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(26, 2005, 'D-A2', 530, 'D159');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(26, 2005, 'D-A3', 530, 'D159');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(26, 2005, 'D-A4', 530, 'D153');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(26, 2005, 'D-A5', 530, 'D159');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(26, 2006, 'D-A1', 530, 'D159');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(26, 2006, 'D-A2', 530, 'D159');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(26, 2006, 'D-A3', 530, 'D159');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(26, 2006, 'D-A4', 530, 'D159');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(26, 2006, 'D-A5', 530, 'D153');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(27, 2003, 'D-A1', 520, 'D269');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(27, 2003, 'D-A2', 520, 'D269');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(27, 2003, 'D-A3', 520, 'D269');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(27, 2003, 'D-A4', 520, 'D269');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(27, 2003, 'D-A5', 520, 'D269');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(27, 2004, 'D-A1', 520, 'D033');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(27, 2004, 'D-A2', 520, 'D269');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(27, 2004, 'D-A3', 520, 'D269');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(27, 2004, 'D-A4', 520, 'D033');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(27, 2004, 'D-A5', 520, 'D033');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(27, 2005, 'A-A', 520, 'D269');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(27, 2005, 'D-A1', 520, 'D269');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(27, 2005, 'D-A2', 520, 'D269');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(27, 2005, 'D-A3', 520, 'D269');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(27, 2005, 'D-A4', 520, 'D033');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(27, 2005, 'D-A5', 520, 'D269');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(28, 2003, 'C-A1', 723, 'D159');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(28, 2003, 'C-A2', 723, 'C603');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(28, 2003, 'C-A3', 723, 'A111');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(28, 2003, 'C-A4', 723, 'C603');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(28, 2003, 'C-A5', 723, 'D159');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(28, 2003, 'D-B3', 728, 'D263');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(28, 2003, 'D-B4', 728, 'D263');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(28, 2004, 'C-A1', 723, 'C603');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(28, 2004, 'C-A2', 723, 'D159');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(28, 2004, 'C-A3', 723, 'D159');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(28, 2004, 'C-A4', 723, 'D159');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(28, 2004, 'C-A5', 723, 'D159');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(28, 2004, 'C-B1', 728, 'D263');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(28, 2004, 'C-B4', 728, 'D263');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(28, 2004, 'D-B5', 728, 'D263');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(28, 2005, 'C-A1', 723, 'D159');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(28, 2005, 'C-A2', 723, 'C603');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(28, 2005, 'C-A3', 723, 'D159');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(28, 2005, 'C-A4', 723, 'D159');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(28, 2005, 'C-A5', 723, 'D159');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(28, 2006, 'C-A1', 723, 'D159');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(28, 2006, 'C-A2', 723, 'C603');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(28, 2006, 'C-A3', 723, 'C603');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(28, 2006, 'C-A4', 723, 'D159');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(28, 2006, 'C-A5', 723, 'C603');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(29, 2003, 'D-A1', 723, 'D251');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(29, 2003, 'D-A2', 723, 'D251');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(29, 2003, 'D-A3', 723, 'D251');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(29, 2003, 'D-A4', 723, 'D251');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(29, 2003, 'D-A5', 723, 'D251');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(29, 2004, 'D-A1', 723, 'A104');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(29, 2004, 'D-A2', 723, 'D251');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(29, 2004, 'D-A3', 723, 'D251');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(29, 2004, 'D-A4', 723, 'A104');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(29, 2004, 'D-A5', 723, 'A104');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(29, 2004, 'D-A6', 719, 'A311');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(29, 2005, 'D-A1', 723, 'A104');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(29, 2005, 'D-A2', 723, 'D251');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(29, 2005, 'D-A3', 723, 'D251');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(29, 2005, 'D-A4', 723, 'A104');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(29, 2005, 'D-A5', 723, 'D251');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(30, 2005, 'A-A', 803, 'A204');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(30, 2005, 'A-B', 810, 'A105');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(30, 2005, 'A-C', 817, 'C603');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(30, 2005, 'A-D', 791, 'A202');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(30, 2005, 'A-E', 816, 'D347');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(30, 2005, 'A-F', 814, 'D152');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(30, 2005, 'A-G', 803, 'D270');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(30, 2005, 'A-H', 842, 'D251');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(30, 2005, 'A-I', 813, 'D033');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(30, 2005, 'A-J', 851, 'A309');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(30, 2005, 'A-K', 827, 'A204');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(30, 2005, 'A-L', 851, 'A309');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(30, 2005, 'A-M', 827, 'D251');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(30, 2005, 'A-N', 814, 'D259');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(30, 2006, 'A-A', 822, 'A310');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(30, 2006, 'A-B', 808, 'A311');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(30, 2006, 'A-C', 838, 'D153');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(30, 2006, 'A-D', 814, 'D152');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(30, 2006, 'A-E', 817, 'C603');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(30, 2006, 'A-F', 814, 'D153');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(30, 2006, 'A-G', 791, 'D158');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(30, 2006, 'A-H', 842, 'A104');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(30, 2006, 'A-I', 841, 'C603');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(30, 2006, 'A-J', 851, 'A204');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(30, 2006, 'A-K', 810, 'A105');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(30, 2006, 'A-L', 851, 'A309');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(31, 2005, 'A-A', 717, 'D153');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(31, 2005, 'A-B', 704, 'A105');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(31, 2005, 'A-C', 694, 'D158');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(31, 2005, 'A-D', 705, 'A202');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(31, 2005, 'A-E', 707, 'A205');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(31, 2005, 'A-F', 707, 'A210');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(31, 2005, 'A-G', 712, 'D270');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(31, 2005, 'A-H', 705, 'D159');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(31, 2005, 'A-I', 708, 'D033');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(31, 2005, 'A-J', 708, 'D259');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(31, 2005, 'A-K', 705, 'A104');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(31, 2005, 'A-L', 694, 'D262');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(31, 2005, 'A-M', 708, 'D259');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(31, 2005, 'A-N', 717, 'A311');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(31, 2006, 'A-A', 717, 'A311');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(31, 2006, 'A-B', 717, 'D153');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(31, 2006, 'A-C', 694, 'D158');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(31, 2006, 'A-D', 705, 'A202');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(31, 2006, 'A-E', 707, 'A205');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(31, 2006, 'A-F', 707, 'A205');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(31, 2006, 'A-G', 704, 'C603');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(31, 2006, 'A-H', 661, 'D153');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(31, 2006, 'A-I', 709, 'D153');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(31, 2006, 'A-J', 708, 'D033');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(31, 2006, 'A-K', 694, 'D158');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(31, 2006, 'A-L', 694, 'D262');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(32, 2005, 'A-A', 507, 'D033');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(32, 2005, 'A-B', 526, 'D258');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(32, 2005, 'A-C', 538, 'A205');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(32, 2005, 'A-D', 490, 'D346');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(32, 2005, 'A-E', 946, 'A205');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(32, 2005, 'A-F', 988, 'A101');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(32, 2005, 'A-G', 545, 'D269');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(32, 2005, 'A-H', 661, 'D158');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(32, 2005, 'A-I', 960, 'A104');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(32, 2005, 'A-J', 338, 'A302');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(32, 2005, 'A-K', 335, 'C603');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(32, 2005, 'A-L', 982, 'A301');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(32, 2005, 'A-M', 338, 'A302');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(32, 2005, 'A-N', 335, 'D269');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(32, 2006, 'A-A', 335, 'D269');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(32, 2006, 'A-B', 867, 'D033');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(32, 2006, 'A-C', 538, 'A205');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(32, 2006, 'A-D', 507, 'D346');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(32, 2006, 'A-E', 946, 'A205');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(32, 2006, 'A-F', 526, 'D347');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(32, 2006, 'A-G', 545, 'A204');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(32, 2006, 'A-H', 338, 'A205');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(32, 2006, 'A-I', 990, 'D347');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(32, 2006, 'A-J', 982, 'D347');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(32, 2006, 'A-K', 404, 'D159');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(32, 2006, 'A-L', 545, 'A110');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(33, 2005, 'A-A', 1047, 'A104');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(33, 2005, 'A-B', 663, 'D263');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(33, 2005, 'A-C', 726, 'C603');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(33, 2005, 'A-D', 43, 'A211');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(33, 2005, 'A-E', 728, 'A204');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(33, 2005, 'A-F', 728, 'D273');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(33, 2005, 'A-G', 721, 'D259');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(33, 2005, 'A-H', 721, 'A205');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(33, 2005, 'A-I', 720, 'A204');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(33, 2005, 'A-J', 720, 'D258');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(33, 2005, 'A-K', 553, 'A205');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(33, 2005, 'A-L', 735, 'D258');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(33, 2005, 'A-M', 720, 'D258');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(33, 2005, 'A-N', 735, 'D258');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(33, 2006, 'A-A', 663, 'D263');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(33, 2006, 'A-B', 735, 'A104');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(33, 2006, 'A-C', 726, 'C603');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(33, 2006, 'A-D', 43, 'A211');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(33, 2006, 'A-E', 728, 'A204');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(33, 2006, 'A-F', 737, 'A205');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(33, 2006, 'A-G', 92, 'D158');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(33, 2006, 'A-H', 721, 'A205');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(33, 2006, 'A-I', 720, 'A204');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(33, 2006, 'A-J', 1047, 'A104');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(33, 2006, 'A-K', 720, 'A204');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(33, 2006, 'A-L', 735, 'D258');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(34, 2005, 'A-A', 635, 'D158');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(34, 2005, 'A-B', 61, 'D262');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(34, 2005, 'A-C', 56, 'A205');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(34, 2005, 'A-D', 60, 'B2');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(34, 2005, 'A-E', 55, 'A204');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(34, 2005, 'A-F', 59, 'A211');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(34, 2005, 'A-G', 635, 'A301');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(34, 2005, 'A-H', 61, 'C603');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(34, 2005, 'A-I', 56, 'A205');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(34, 2005, 'A-J', 60, 'D259');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(34, 2005, 'A-K', 55, 'A204');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(34, 2005, 'A-L', 59, 'D258');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(34, 2005, 'A-M', 94, 'D270');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(34, 2005, 'A-N', 57, 'D159');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(34, 2006, 'A-A', 635, 'A301');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(34, 2006, 'A-B', 87, 'A204');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(34, 2006, 'A-C', 56, 'A205');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(34, 2006, 'A-D', 84, 'A110');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(34, 2006, 'A-E', 104, 'A205');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(34, 2006, 'A-F', 57, 'D033');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(34, 2006, 'A-G', 56, 'A205');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(34, 2006, 'A-H', 84, 'D347');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(34, 2006, 'A-I', 104, 'A205');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(34, 2006, 'A-J', 57, 'D033');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(34, 2006, 'A-K', 87, 'A204');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(34, 2006, 'A-L', 635, 'D158');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(34, 2006, 'A-M', 94, 'B2');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(35, 2005, 'A-A', 803, 'A202');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(35, 2005, 'A-B', 810, 'D262');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(35, 2005, 'A-C', 795, 'D262');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(35, 2005, 'A-D', 791, 'A205');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(35, 2005, 'A-E', 816, 'D033');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(35, 2005, 'A-F', 809, 'D152');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(35, 2005, 'A-G', 817, 'A310');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(35, 2005, 'A-H', 808, 'D258');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(35, 2005, 'A-I', 813, 'A109');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(35, 2005, 'A-J', 822, 'D251');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(36, 2005, 'A-A', 782, 'A102');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(36, 2005, 'A-B', 767, 'D270');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(36, 2005, 'A-C', 753, 'A301');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(36, 2005, 'A-D', 760, 'D153');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(36, 2005, 'A-E', 779, 'C603');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(36, 2005, 'A-F', 776, 'D273');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(36, 2005, 'A-G', 753, 'D158');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(36, 2005, 'A-H', 767, 'D270');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(36, 2005, 'A-I', 779, 'A110');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(36, 2005, 'A-J', 760, 'D159');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(37, 2005, 'A-A', 663, 'D153');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(37, 2005, 'A-B', 553, 'D262');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(37, 2005, 'A-C', 729, 'D159');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(37, 2005, 'A-D', 43, 'A104');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(37, 2005, 'A-E', 721, 'D347');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(37, 2005, 'A-F', 92, 'B3');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(37, 2005, 'A-G', 734, 'D263');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(37, 2005, 'A-H', 726, 'D033');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(37, 2005, 'A-I', 516, 'B2');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(37, 2005, 'A-J', 729, 'D159');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(38, 2005, 'A-A', 661, 'D033');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(38, 2005, 'A-B', 313, 'D263');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(38, 2005, 'A-C', 472, 'A105');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(38, 2005, 'A-D', 462, 'D153');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(38, 2005, 'A-E', 332, 'A205');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(38, 2005, 'A-F', 368, 'A109');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(38, 2005, 'A-G', 238, 'D263');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(38, 2005, 'A-H', 509, 'D033');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(38, 2005, 'A-I', 330, 'D152');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(39, 2005, 'A-A', 975, 'D152');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(39, 2005, 'A-B', 432, 'D263');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(39, 2005, 'A-C', 1035, 'A205');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(39, 2005, 'A-D', 1036, 'A201');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(39, 2005, 'A-E', 1045, 'D153');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(39, 2005, 'A-F', 1037, 'A202');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(39, 2005, 'A-G', 712, 'D159');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(39, 2005, 'A-H', 95, 'D347');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(39, 2005, 'A-I', 1055, 'A209');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(39, 2005, 'A-J', 370, 'D259');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(39, 2005, 'A-K', 1045, 'D259');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(39, 2005, 'A-L', 1038, 'A310');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(39, 2005, 'A-M', 40, 'D259');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(39, 2005, 'A-N', 665, 'A312');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(40, 2006, 'B-A', 811, 'D033');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(40, 2006, 'B-B', 811, 'D033');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(40, 2006, 'B-C', 809, 'A204');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(40, 2006, 'B-D', 809, 'A110');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(40, 2006, 'B-E', 813, 'D158');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(41, 2006, 'B-A', 753, 'A312');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(41, 2006, 'B-B', 776, 'A204');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(41, 2006, 'B-C', 753, 'A205');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(41, 2006, 'B-D', 776, 'D160');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(41, 2006, 'B-E', 760, 'D263');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(41, 2006, 'B-F', 767, 'A104');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(41, 2006, 'B-G', 779, 'D153');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(41, 2006, 'B-H', 768, 'D272');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(41, 2006, 'B-I', 779, 'D153');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(41, 2006, 'B-J', 782, 'C603');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(42, 2006, 'A-N', 485, 'D251');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(42, 2006, 'A-O', 485, 'D251');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(42, 2006, 'B-A', 547, 'D259');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(42, 2006, 'B-B', 508, 'D347');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(42, 2006, 'B-C', 534, 'A104');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(42, 2006, 'B-D', 503, 'D160');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(42, 2006, 'B-E', 868, 'B2');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(42, 2006, 'B-F', 589, 'C603');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(42, 2006, 'B-G', 532, 'D347');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(42, 2006, 'B-H', 503, 'D160');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(42, 2006, 'B-I', 534, 'D263');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(42, 2006, 'B-J', 863, 'A204');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(42, 2006, 'B-K', 530, 'D153');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(43, 2006, 'B-A', 368, 'D263');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(43, 2006, 'B-B', 385, 'D153');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(43, 2006, 'B-C', 462, 'A204');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(43, 2006, 'B-D', 467, 'A101');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(43, 2006, 'B-E', 383, 'D160');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(44, 2006, 'B-A', 668, 'D269');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(44, 2006, 'B-B', 714, 'D347');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(44, 2006, 'B-C', 665, 'D158');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(44, 2006, 'B-D', 656, 'A111');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(44, 2006, 'B-E', 656, 'D260');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(44, 2006, 'B-F', 693, 'A204');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(44, 2006, 'B-G', 693, 'A204');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(44, 2006, 'B-H', 656, 'D260');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(44, 2006, 'B-I', 668, 'A104');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(44, 2006, 'B-J', 665, 'D158');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(44, 2006, 'B-K', 714, 'B3');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(45, 2006, 'B-F', 816, 'D158');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(45, 2006, 'B-G', 816, 'D158');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(45, 2006, 'B-H', 843, 'A201');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(45, 2006, 'B-I', 843, 'D258');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(45, 2006, 'B-J', 837, 'A109');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(45, 2006, 'B-K', 827, 'A104');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(46, 2006, 'B-F', 490, 'A104');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(46, 2006, 'B-G', 479, 'D158');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(46, 2006, 'B-H', 538, 'A209');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(46, 2006, 'B-I', 472, 'D347');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(46, 2006, 'B-J', 546, 'A104');
INSERT INTO predmetgrupa(sifpredmet, akgodina, ozngrupa, sifnastavnik, ozndvorana)
  VALUES(46, 2006, 'B-K', 509, 'A105');



INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555000490', 1, 2005, 'D-B2', EXTEND(MDY(6,13,2006), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555000490', 2, 2004, 'C-B4', EXTEND(MDY(2,14,2005), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555000490', 4, 2004, 'C-B4', EXTEND(MDY(2,17,2005), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555000490', 5, 2004, 'C-B4', EXTEND(MDY(2,7,2005), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555000490', 6, 2004, 'C-B4', EXTEND(MDY(6,28,2005), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555000490', 7, 2004, 'C-B4', EXTEND(MDY(9,26,2005), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555000490', 8, 2004, 'C-B4', EXTEND(MDY(6,13,2005), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555000490', 9, 2004, 'C-B4', EXTEND(MDY(4,13,2005), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555000490', 12, 2004, 'C-B4', EXTEND(MDY(6,21,2005), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555000490', 18, 2005, 'D-B2', EXTEND(MDY(7,4,2006), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555000490', 19, 2005, 'D-B2', EXTEND(MDY(2,6,2006), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555000490', 20, 2005, 'D-B2', EXTEND(MDY(2,20,2006), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555000490', 21, 2005, 'D-B2', EXTEND(MDY(12,11,2006), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555000490', 22, 2005, 'D-B2', EXTEND(MDY(6,19,2006), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555000490', 23, 2005, 'D-B2', EXTEND(MDY(7,4,2006), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555000490', 25, 2005, 'D-B2', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555000508', 31, 2005, 'A-H', EXTEND(MDY(1,30,2006), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555000508', 32, 2005, 'A-H', EXTEND(MDY(2,2,2006), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555000508', 33, 2005, 'A-H', EXTEND(MDY(1,31,2006), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555000508', 34, 2005, 'A-H', EXTEND(MDY(2,3,2006), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555000508', 37, 2005, 'A-H', EXTEND(MDY(6,27,2006), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555000508', 38, 2005, 'A-H', EXTEND(MDY(6,29,2006), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555000508', 39, 2005, 'A-H', EXTEND(MDY(6,30,2006), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555000508', 40, 2006, 'B-C', EXTEND(MDY(2,1,2007), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555000508', 42, 2006, 'B-C', EXTEND(MDY(2,1,2007), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555000508', 43, 2006, 'B-C', EXTEND(MDY(2,1,2007), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555000508', 44, 2006, 'B-C', EXTEND(MDY(2,1,2007), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555000529', 32, 2006, 'A-K', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555000529', 34, 2006, 'A-L', EXTEND(MDY(2,1,2007), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555000529', 42, 2006, 'B-E', EXTEND(MDY(2,1,2007), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555000529', 44, 2006, 'B-E', EXTEND(MDY(2,1,2007), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555000555', 27, 2005, 'A-A', EXTEND(MDY(6,26,2006), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555000555', 29, 2004, 'D-A6', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555000555', 29, 2005, 'D-A1', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555000560', 32, 2006, 'A-K', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555000560', 33, 2006, 'A-K', EXTEND(MDY(2,1,2007), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555000560', 34, 2006, 'A-K', EXTEND(MDY(2,1,2007), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555000560', 44, 2006, 'B-E', EXTEND(MDY(2,1,2007), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555000581', 1, 2003, 'D-A1', EXTEND(MDY(9,22,2005), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555000581', 14, 2003, 'D-A1', EXTEND(MDY(9,4,2004), YEAR to SECOND), 1);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555000581', 14, 2005, 'A-A', EXTEND(MDY(9,4,2006), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555000581', 26, 2003, 'D-A1', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555000581', 27, 2003, 'D-A1', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555000581', 29, 2003, 'D-A1', EXTEND(MDY(9,5,2005), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555000597', 2, 2003, 'C-A1', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555000597', 3, 2003, 'C-A1', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555000597', 6, 2005, 'A-A', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555000597', 7, 2005, 'A-A', EXTEND(MDY(6,20,2006), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555000597', 8, 2005, 'A-A', EXTEND(MDY(6,12,2006), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555000597', 11, 2003, 'C-A1', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555000597', 12, 2003, 'C-A1', EXTEND(MDY(7,5,2005), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555000597', 28, 2003, 'C-A1', EXTEND(MDY(2,9,2004), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555000604', 34, 2006, 'A-M', EXTEND(MDY(2,1,2007), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555000604', 42, 2006, 'B-K', EXTEND(MDY(2,1,2007), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555000604', 44, 2006, 'B-K', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555000604', 45, 2006, 'B-K', EXTEND(MDY(2,1,2007), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555000625', 3, 2004, 'C-A4', EXTEND(MDY(9,28,2006), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555000625', 9, 2004, 'C-A4', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555000625', 10, 2004, 'C-A4', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555000625', 11, 2004, 'C-A4', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555000625', 11, 2005, 'A-A', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555000625', 12, 2004, 'C-A4', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555000625', 12, 2005, 'A-A', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555000625', 28, 2004, 'C-A4', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555000646', 1, 2005, 'D-A1', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555000646', 14, 2005, 'D-A1', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555000646', 15, 2005, 'D-A1', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555000646', 26, 2005, 'D-A1', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555000646', 27, 2005, 'D-A1', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555000646', 29, 2004, 'D-A6', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555000667', 3, 2005, 'A-A', EXTEND(MDY(7,13,2006), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555000667', 11, 2005, 'A-A', EXTEND(MDY(7,11,2006), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555000667', 13, 2006, 'D-A4', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555000667', 15, 2006, 'D-A4', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555000667', 17, 2006, 'D-A4', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555000667', 26, 2006, 'D-A4', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555000688', 1, 2005, 'D-B4', EXTEND(MDY(6,13,2006), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555000688', 2, 2003, 'C-B1', EXTEND(MDY(7,16,2004), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555000688', 6, 2003, 'C-B1', EXTEND(MDY(9,11,2006), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555000688', 7, 2003, 'C-B1', EXTEND(MDY(6,15,2004), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555000688', 8, 2003, 'C-B1', EXTEND(MDY(4,14,2005), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555000688', 9, 2003, 'C-B1', EXTEND(MDY(7,5,2006), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555000688', 12, 2003, 'C-B1', EXTEND(MDY(6,21,2004), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555000688', 20, 2005, 'D-B4', EXTEND(MDY(2,20,2006), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555000688', 21, 2005, 'D-B4', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555000688', 22, 2005, 'D-B4', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555000688', 23, 2005, 'D-B4', EXTEND(MDY(6,13,2006), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555000688', 25, 2005, 'D-B4', EXTEND(MDY(9,25,2006), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555000693', 1, 2004, 'D-A2', EXTEND(MDY(9,1,2005), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555000693', 2, 2003, 'C-A4', EXTEND(MDY(9,10,2004), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555000693', 3, 2003, 'C-A4', EXTEND(MDY(6,15,2004), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555000693', 5, 2004, 'D-A2', EXTEND(MDY(2,7,2005), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555000693', 9, 2003, 'C-A4', EXTEND(MDY(2,6,2004), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555000693', 10, 2003, 'C-A4', EXTEND(MDY(2,12,2004), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555000693', 11, 2003, 'C-A4', EXTEND(MDY(6,23,2004), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555000693', 12, 2003, 'C-A4', EXTEND(MDY(6,21,2004), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555000693', 13, 2004, 'D-A2', EXTEND(MDY(2,14,2005), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555000693', 14, 2004, 'D-A2', EXTEND(MDY(6,16,2005), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555000693', 15, 2004, 'D-A2', EXTEND(MDY(2,10,2005), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555000693', 17, 2004, 'D-A2', EXTEND(MDY(4,12,2005), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555000693', 26, 2004, 'D-A2', EXTEND(MDY(5,8,2006), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555000693', 27, 2004, 'D-A2', EXTEND(MDY(6,21,2005), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555000693', 28, 2003, 'C-A4', EXTEND(MDY(2,9,2004), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555000693', 29, 2004, 'D-A2', EXTEND(MDY(6,13,2005), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555000700', 1, 2005, 'A-A', EXTEND(MDY(9,26,2006), YEAR to SECOND), 0);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555000716', 1, 2003, 'D-A5', EXTEND(MDY(7,13,2004), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555000716', 11, 2005, 'A-A', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555000716', 13, 2003, 'D-A2', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555000716', 14, 2003, 'D-A5', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555000716', 14, 2005, 'A-A', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555000716', 17, 2003, 'D-A2', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555000716', 26, 2003, 'D-A2', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555000716', 27, 2003, 'D-A5', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555000716', 29, 2003, 'D-A5', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555000716', 29, 2004, 'D-A6', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555000716', 29, 2005, 'D-A1', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555000721', 2, 2003, 'C-B5', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555000721', 4, 2003, 'C-B5', EXTEND(MDY(2,17,2005), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555000721', 5, 2003, 'C-B5', EXTEND(MDY(2,7,2005), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555000721', 6, 2003, 'C-B5', EXTEND(MDY(9,4,2004), YEAR to SECOND), 1);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555000721', 6, 2005, 'A-A', EXTEND(MDY(6,14,2006), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555000721', 7, 2003, 'C-B5', EXTEND(MDY(6,14,2005), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555000721', 8, 2003, 'C-B5', EXTEND(MDY(6,13,2005), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555000721', 9, 2003, 'C-B5', EXTEND(MDY(2,4,2005), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555000721', 12, 2003, 'C-B5', EXTEND(MDY(6,21,2005), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555000737', 34, 2006, 'A-L', EXTEND(MDY(2,1,2007), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555000737', 40, 2006, 'B-E', EXTEND(MDY(2,1,2007), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555000737', 42, 2006, 'B-E', EXTEND(MDY(2,1,2007), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555000737', 43, 2006, 'B-E', EXTEND(MDY(2,1,2007), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555000737', 44, 2006, 'B-E', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555000742', 1, 2005, 'D-A3', EXTEND(MDY(6,13,2006), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555000742', 2, 2004, 'C-A5', EXTEND(MDY(9,11,2006), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555000742', 3, 2004, 'C-A5', EXTEND(MDY(7,13,2006), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555000742', 10, 2004, 'C-A5', EXTEND(MDY(2,10,2005), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555000742', 11, 2004, 'C-A5', EXTEND(MDY(6,21,2005), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555000742', 13, 2005, 'D-A3', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555000742', 14, 2005, 'D-A3', EXTEND(MDY(6,16,2006), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555000742', 15, 2005, 'D-A3', EXTEND(MDY(2,20,2006), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555000742', 17, 2005, 'D-A3', EXTEND(MDY(2,17,2006), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555000742', 26, 2005, 'D-A3', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555000742', 27, 2005, 'D-A3', EXTEND(MDY(6,20,2006), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555000742', 28, 2004, 'C-A5', EXTEND(MDY(2,7,2005), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555000742', 29, 2005, 'D-A3', EXTEND(MDY(6,12,2006), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555000758', 1, 2005, 'D-A1', EXTEND(MDY(7,4,2006), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555000758', 3, 2003, 'C-A4', EXTEND(MDY(9,11,2006), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555000758', 9, 2003, 'C-A4', EXTEND(MDY(2,14,2006), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555000758', 11, 2003, 'C-A4', EXTEND(MDY(6,23,2004), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555000758', 12, 2003, 'C-A4', EXTEND(MDY(6,21,2004), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555000758', 13, 2005, 'D-A1', EXTEND(MDY(2,13,2006), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555000758', 14, 2005, 'D-A1', EXTEND(MDY(6,16,2006), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555000758', 26, 2005, 'D-A1', EXTEND(MDY(7,11,2006), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555000758', 27, 2005, 'D-A1', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555000758', 28, 2003, 'C-A4', EXTEND(MDY(2,9,2004), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555000758', 29, 2005, 'D-A1', EXTEND(MDY(6,12,2006), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555000763', 1, 2003, 'D-A4', EXTEND(MDY(7,6,2004), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555000763', 13, 2003, 'D-A4', EXTEND(MDY(2,16,2004), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555000763', 14, 2003, 'D-A4', EXTEND(MDY(6,17,2004), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555000763', 15, 2003, 'D-A4', EXTEND(MDY(2,20,2006), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555000763', 17, 2003, 'D-A4', EXTEND(MDY(2,2,2004), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555000763', 26, 2003, 'D-A4', EXTEND(MDY(9,30,2004), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555000763', 27, 2003, 'D-A4', EXTEND(MDY(9,12,2005), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555000763', 29, 2003, 'D-A4', EXTEND(MDY(6,15,2004), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555000779', 34, 2006, 'A-M', EXTEND(MDY(2,1,2007), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555000779', 42, 2006, 'B-K', EXTEND(MDY(2,1,2007), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555000779', 44, 2006, 'B-K', EXTEND(MDY(2,1,2007), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555000779', 45, 2006, 'B-K', EXTEND(MDY(2,1,2007), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555000779', 46, 2006, 'B-K', EXTEND(MDY(2,1,2007), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555000784', 1, 2005, 'A-A', EXTEND(MDY(6,13,2006), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555000807', 1, 2004, 'D-B3', EXTEND(MDY(6,16,2005), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555000807', 2, 2003, 'C-B3', EXTEND(MDY(2,16,2004), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555000807', 4, 2003, 'C-B3', EXTEND(MDY(2,3,2004), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555000807', 5, 2003, 'C-B3', EXTEND(MDY(2,15,2005), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555000807', 6, 2003, 'C-B3', EXTEND(MDY(6,16,2004), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555000807', 7, 2003, 'C-B3', EXTEND(MDY(6,15,2004), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555000807', 8, 2003, 'C-B3', EXTEND(MDY(6,14,2004), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555000807', 9, 2003, 'C-B3', EXTEND(MDY(4,21,2004), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555000807', 12, 2003, 'C-B3', EXTEND(MDY(6,21,2005), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555000807', 18, 2004, 'D-B3', EXTEND(MDY(7,5,2005), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555000807', 19, 2004, 'D-B3', EXTEND(MDY(7,8,2005), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555000807', 20, 2004, 'D-B3', EXTEND(MDY(2,8,2006), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555000807', 21, 2004, 'D-B3', EXTEND(MDY(7,14,2006), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555000807', 22, 2004, 'D-B3', EXTEND(MDY(2,3,2006), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555000807', 23, 2004, 'D-B3', EXTEND(MDY(7,12,2005), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555000807', 25, 2004, 'D-B3', EXTEND(MDY(12,4,2006), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555000812', 1, 2004, 'D-A4', EXTEND(MDY(6,16,2005), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555000812', 3, 2003, 'C-A2', EXTEND(MDY(7,14,2005), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555000812', 5, 2004, 'D-A4', EXTEND(MDY(2,7,2005), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555000812', 10, 2003, 'C-A2', EXTEND(MDY(2,10,2005), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555000812', 11, 2003, 'C-A2', EXTEND(MDY(6,23,2004), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555000812', 12, 2003, 'C-A2', EXTEND(MDY(6,21,2004), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555000812', 13, 2004, 'D-A4', EXTEND(MDY(6,14,2006), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555000812', 14, 2004, 'D-A4', EXTEND(MDY(6,16,2005), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555000812', 15, 2004, 'D-A4', EXTEND(MDY(4,12,2005), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555000812', 17, 2004, 'D-A4', EXTEND(MDY(3,16,2006), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555000812', 26, 2004, 'D-A4', EXTEND(MDY(9,26,2005), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555000812', 27, 2004, 'D-A4', EXTEND(MDY(9,11,2006), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555000812', 28, 2003, 'C-A2', EXTEND(MDY(2,9,2004), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555000812', 29, 2004, 'D-A4', EXTEND(MDY(6,13,2005), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555000828', 1, 2004, 'D-B2', EXTEND(MDY(7,7,2005), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555000828', 6, 2003, 'C-B3', EXTEND(MDY(6,28,2005), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555000828', 7, 2003, 'C-B3', EXTEND(MDY(9,7,2004), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555000828', 8, 2003, 'C-B3', EXTEND(MDY(9,21,2004), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555000828', 12, 2003, 'C-B3', EXTEND(MDY(6,21,2004), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555000828', 18, 2004, 'D-B2', EXTEND(MDY(6,15,2005), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555000828', 19, 2004, 'D-B2', EXTEND(MDY(2,7,2005), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555000828', 20, 2004, 'D-B2', EXTEND(MDY(2,9,2005), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555000828', 21, 2004, 'D-B2', EXTEND(MDY(11,7,2005), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555000828', 22, 2004, 'D-B2', EXTEND(MDY(6,20,2005), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555000828', 23, 2004, 'D-B2', EXTEND(MDY(12,8,2005), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555000828', 25, 2004, 'D-B2', EXTEND(MDY(9,25,2006), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555000833', 1, 2005, 'D-B5', EXTEND(MDY(7,4,2006), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555000833', 4, 2004, 'C-B5', EXTEND(MDY(2,1,2005), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555000833', 6, 2004, 'C-B5', EXTEND(MDY(6,28,2005), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555000833', 7, 2004, 'C-B5', EXTEND(MDY(9,28,2005), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555000833', 9, 2004, 'C-B5', EXTEND(MDY(9,19,2005), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555000833', 12, 2004, 'C-B5', EXTEND(MDY(6,21,2005), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555000833', 18, 2005, 'D-B5', EXTEND(MDY(7,4,2006), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555000833', 19, 2005, 'D-B5', EXTEND(MDY(2,6,2006), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555000833', 20, 2005, 'D-B5', EXTEND(MDY(2,20,2006), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555000833', 21, 2005, 'D-B5', EXTEND(MDY(9,1,2006), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555000833', 22, 2005, 'D-B5', EXTEND(MDY(6,19,2006), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555000833', 23, 2005, 'D-B5', EXTEND(MDY(6,13,2006), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555000833', 25, 2005, 'D-B5', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555000849', 1, 2005, 'A-A', EXTEND(MDY(7,4,2006), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555000854', 4, 2005, 'C-B5', EXTEND(MDY(2,16,2006), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555000854', 6, 2005, 'C-B5', EXTEND(MDY(6,27,2006), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555000854', 7, 2005, 'C-B5', EXTEND(MDY(9,25,2006), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555000854', 8, 2005, 'C-B5', EXTEND(MDY(6,12,2006), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555000854', 12, 2005, 'C-B5', EXTEND(MDY(6,20,2006), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555000854', 18, 2006, 'D-B1', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555000854', 19, 2006, 'D-B1', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555000854', 20, 2006, 'D-B1', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555000854', 25, 2006, 'D-B1', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555000875', 1, 2005, 'A-A', EXTEND(MDY(7,4,2006), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555000880', 1, 2004, 'D-B1', EXTEND(MDY(6,16,2005), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555000880', 2, 2003, 'C-B1', EXTEND(MDY(2,2,2004), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555000880', 4, 2003, 'C-B1', EXTEND(MDY(9,2,2004), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555000880', 5, 2003, 'C-B1', EXTEND(MDY(2,9,2004), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555000880', 6, 2003, 'C-B1', EXTEND(MDY(6,16,2004), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555000880', 7, 2003, 'C-B1', EXTEND(MDY(6,15,2004), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555000880', 8, 2003, 'C-B1', EXTEND(MDY(6,14,2004), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555000880', 9, 2003, 'C-B1', EXTEND(MDY(2,6,2004), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555000880', 12, 2003, 'C-B1', EXTEND(MDY(6,21,2004), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555000880', 18, 2004, 'D-B1', EXTEND(MDY(11,9,2005), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555000880', 19, 2004, 'D-B1', EXTEND(MDY(2,7,2005), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555000880', 20, 2004, 'D-B1', EXTEND(MDY(2,9,2005), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555000880', 21, 2004, 'D-B1', EXTEND(MDY(6,15,2005), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555000880', 22, 2004, 'D-B1', EXTEND(MDY(6,20,2005), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555000880', 23, 2004, 'D-B1', EXTEND(MDY(7,5,2005), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555000880', 25, 2004, 'D-B1', EXTEND(MDY(9,9,2005), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555000896', 1, 2005, 'D-B1', EXTEND(MDY(6,13,2006), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555000896', 2, 2003, 'C-B3', EXTEND(MDY(2,13,2006), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555000896', 4, 2003, 'C-B3', EXTEND(MDY(2,3,2004), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555000896', 5, 2003, 'C-B3', EXTEND(MDY(6,28,2004), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555000896', 6, 2003, 'C-B3', EXTEND(MDY(7,6,2006), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555000896', 7, 2003, 'C-B3', EXTEND(MDY(6,15,2004), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555000896', 8, 2003, 'C-B3', EXTEND(MDY(7,5,2004), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555000896', 9, 2003, 'C-B3', EXTEND(MDY(9,19,2005), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555000896', 12, 2003, 'C-B3', EXTEND(MDY(6,20,2006), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555000896', 19, 2005, 'D-B1', EXTEND(MDY(12,14,2006), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555000896', 20, 2005, 'D-B1', EXTEND(MDY(6,14,2006), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555000896', 21, 2005, 'D-B1', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555000896', 22, 2005, 'D-B1', EXTEND(MDY(6,19,2006), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555000896', 23, 2005, 'D-B1', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555000896', 25, 2005, 'D-B1', EXTEND(MDY(9,25,2006), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555000903', 1, 2004, 'D-B4', EXTEND(MDY(6,30,2005), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555000903', 2, 2003, 'C-B3', EXTEND(MDY(2,14,2005), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555000903', 4, 2003, 'C-B3', EXTEND(MDY(2,19,2004), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555000903', 5, 2003, 'C-B3', EXTEND(MDY(2,9,2004), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555000903', 6, 2003, 'C-B3', EXTEND(MDY(6,29,2004), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555000903', 7, 2003, 'C-B3', EXTEND(MDY(2,17,2005), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555000903', 8, 2003, 'C-B3', EXTEND(MDY(6,13,2005), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555000903', 9, 2003, 'C-B3', EXTEND(MDY(2,6,2004), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555000903', 12, 2003, 'C-B3', EXTEND(MDY(6,21,2004), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555000903', 18, 2004, 'D-B4', EXTEND(MDY(9,8,2005), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555000903', 19, 2004, 'D-B4', EXTEND(MDY(2,7,2005), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555000903', 20, 2004, 'D-B4', EXTEND(MDY(2,21,2005), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555000903', 21, 2004, 'D-B4', EXTEND(MDY(6,15,2005), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555000903', 22, 2004, 'D-B4', EXTEND(MDY(6,20,2005), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555000903', 23, 2004, 'D-B4', EXTEND(MDY(3,16,2006), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555000903', 25, 2004, 'D-B4', EXTEND(MDY(12,5,2005), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555000919', 1, 2004, 'D-B4', EXTEND(MDY(2,21,2006), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555000919', 2, 2003, 'C-B2', EXTEND(MDY(9,20,2004), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555000919', 5, 2003, 'C-B2', EXTEND(MDY(6,16,2004), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555000919', 6, 2003, 'C-B2', EXTEND(MDY(6,29,2004), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555000919', 7, 2003, 'C-B2', EXTEND(MDY(6,23,2004), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555000919', 8, 2003, 'C-B2', EXTEND(MDY(7,5,2004), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555000919', 9, 2003, 'C-B2', EXTEND(MDY(2,6,2004), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555000919', 18, 2004, 'D-B4', EXTEND(MDY(4,14,2005), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555000919', 19, 2004, 'D-B4', EXTEND(MDY(2,7,2005), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555000919', 20, 2004, 'D-B4', EXTEND(MDY(2,9,2005), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555000919', 21, 2004, 'D-B4', EXTEND(MDY(6,15,2005), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555000919', 22, 2004, 'D-B4', EXTEND(MDY(6,20,2005), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555000919', 23, 2004, 'D-B4', EXTEND(MDY(6,14,2005), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555000919', 25, 2004, 'D-B4', EXTEND(MDY(6,23,2005), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555000950', 1, 2004, 'D-A4', EXTEND(MDY(7,7,2005), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555000950', 2, 2003, 'C-A3', EXTEND(MDY(7,15,2005), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555000950', 3, 2003, 'C-A3', EXTEND(MDY(4,13,2005), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555000950', 5, 2004, 'D-A4', EXTEND(MDY(2,7,2005), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555000950', 9, 2003, 'C-A3', EXTEND(MDY(2,17,2004), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555000950', 11, 2003, 'C-A3', EXTEND(MDY(6,23,2004), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555000950', 12, 2003, 'C-A3', EXTEND(MDY(7,6,2004), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555000950', 13, 2004, 'D-A4', EXTEND(MDY(2,1,2006), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555000950', 14, 2004, 'D-A4', EXTEND(MDY(6,16,2005), YEAR to SECOND), 1);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555000950', 14, 2005, 'A-A', EXTEND(MDY(6,16,2006), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555000950', 15, 2004, 'D-A4', EXTEND(MDY(7,4,2006), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555000950', 17, 2004, 'D-A4', EXTEND(MDY(1,31,2005), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555000950', 26, 2004, 'D-A4', EXTEND(MDY(9,26,2005), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555000950', 27, 2004, 'D-A4', EXTEND(MDY(6,16,2005), YEAR to SECOND), 1);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555000950', 27, 2005, 'A-A', EXTEND(MDY(6,20,2006), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555000950', 29, 2004, 'D-A4', EXTEND(MDY(6,13,2005), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555000966', 1, 2004, 'D-A1', EXTEND(MDY(6,16,2005), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555000966', 5, 2004, 'D-A1', EXTEND(MDY(2,7,2005), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555000966', 14, 2004, 'D-A1', EXTEND(MDY(6,16,2005), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555000966', 17, 2004, 'D-A1', EXTEND(MDY(4,12,2005), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555000966', 26, 2004, 'D-A1', EXTEND(MDY(9,22,2005), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555000966', 29, 2004, 'D-A1', EXTEND(MDY(6,13,2005), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555000971', 1, 2004, 'D-B4', EXTEND(MDY(6,30,2005), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555000971', 4, 2003, 'C-B2', EXTEND(MDY(2,3,2004), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555000971', 5, 2003, 'C-B2', EXTEND(MDY(2,9,2004), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555000971', 6, 2003, 'C-B2', EXTEND(MDY(6,16,2004), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555000971', 7, 2003, 'C-B2', EXTEND(MDY(6,15,2004), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555000971', 8, 2003, 'C-B2', EXTEND(MDY(6,14,2004), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555000971', 9, 2003, 'C-B2', EXTEND(MDY(7,7,2004), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555000971', 12, 2003, 'C-B2', EXTEND(MDY(9,10,2004), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555000971', 18, 2004, 'D-B4', EXTEND(MDY(6,15,2005), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555000971', 19, 2004, 'D-B4', EXTEND(MDY(2,7,2005), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555000971', 20, 2004, 'D-B4', EXTEND(MDY(7,11,2005), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555000971', 21, 2004, 'D-B4', EXTEND(MDY(7,4,2006), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555000971', 22, 2004, 'D-B4', EXTEND(MDY(6,20,2005), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555000971', 23, 2004, 'D-B4', EXTEND(MDY(9,5,2005), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555000971', 25, 2004, 'D-B4', EXTEND(MDY(9,22,2005), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555000987', 1, 2005, 'D-B3', EXTEND(MDY(6,13,2006), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555000987', 2, 2003, 'C-B3', EXTEND(MDY(7,15,2005), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555000987', 4, 2003, 'C-B3', EXTEND(MDY(2,3,2004), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555000987', 5, 2003, 'C-B3', EXTEND(MDY(2,9,2004), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555000987', 6, 2003, 'C-B3', EXTEND(MDY(6,28,2005), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555000987', 7, 2003, 'C-B3', EXTEND(MDY(6,23,2004), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555000987', 8, 2003, 'C-B3', EXTEND(MDY(7,5,2004), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555000987', 9, 2003, 'C-B3', EXTEND(MDY(7,5,2006), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555000987', 12, 2003, 'C-B3', EXTEND(MDY(9,22,2005), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555000987', 18, 2005, 'D-B3', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555000987', 19, 2005, 'D-B3', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555000987', 20, 2005, 'D-B3', EXTEND(MDY(2,8,2006), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555000987', 21, 2005, 'D-B3', EXTEND(MDY(9,28,2006), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555000987', 22, 2005, 'D-B3', EXTEND(MDY(6,19,2006), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555000987', 23, 2005, 'D-B3', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555000987', 25, 2005, 'D-B3', EXTEND(MDY(9,25,2006), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555000992', 1, 2005, 'D-A3', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555000992', 3, 2004, 'C-A3', EXTEND(MDY(6,14,2005), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555000992', 9, 2004, 'C-A3', EXTEND(MDY(2,4,2005), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555000992', 10, 2004, 'C-A3', EXTEND(MDY(2,10,2005), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555000992', 11, 2004, 'C-A3', EXTEND(MDY(6,21,2005), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555000992', 12, 2004, 'C-A3', EXTEND(MDY(6,21,2005), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555000992', 13, 2005, 'D-A3', EXTEND(MDY(2,1,2006), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555000992', 14, 2005, 'D-A3', EXTEND(MDY(6,16,2006), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555000992', 15, 2005, 'D-A3', EXTEND(MDY(2,20,2006), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555000992', 17, 2005, 'D-A3', EXTEND(MDY(9,18,2006), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555000992', 26, 2005, 'D-A3', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555000992', 27, 2005, 'D-A3', EXTEND(MDY(6,20,2006), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555000992', 29, 2005, 'D-A3', EXTEND(MDY(6,12,2006), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001003', 1, 2004, 'D-A3', EXTEND(MDY(6,30,2005), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001003', 13, 2004, 'D-A3', EXTEND(MDY(9,13,2005), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001003', 14, 2004, 'D-A3', EXTEND(MDY(6,16,2005), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001003', 17, 2004, 'D-A3', EXTEND(MDY(2,18,2005), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001003', 26, 2004, 'D-A3', EXTEND(MDY(9,26,2005), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001003', 27, 2004, 'D-A3', EXTEND(MDY(6,21,2005), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001019', 1, 2005, 'D-A4', EXTEND(MDY(7,12,2006), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001019', 3, 2003, 'C-A4', EXTEND(MDY(9,29,2005), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001019', 10, 2003, 'C-A4', EXTEND(MDY(2,12,2004), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001019', 11, 2003, 'C-A4', EXTEND(MDY(6,21,2005), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001019', 12, 2003, 'C-A4', EXTEND(MDY(7,5,2005), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001019', 13, 2005, 'D-A4', EXTEND(MDY(9,20,2006), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001019', 14, 2005, 'D-A4', EXTEND(MDY(6,16,2006), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001019', 15, 2005, 'D-A4', EXTEND(MDY(2,20,2006), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001019', 17, 2005, 'D-A4', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001019', 26, 2005, 'D-A4', EXTEND(MDY(9,11,2006), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001019', 27, 2005, 'D-A4', EXTEND(MDY(7,7,2006), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001019', 28, 2003, 'C-A4', EXTEND(MDY(2,9,2004), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001019', 29, 2005, 'D-A4', EXTEND(MDY(6,12,2006), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001024', 3, 2004, 'C-A1', EXTEND(MDY(6,14,2005), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001024', 9, 2004, 'C-A1', EXTEND(MDY(2,4,2005), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001024', 10, 2004, 'C-A1', EXTEND(MDY(2,10,2005), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001024', 11, 2004, 'C-A1', EXTEND(MDY(6,21,2005), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001024', 12, 2004, 'C-A1', EXTEND(MDY(6,21,2005), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001024', 13, 2006, 'D-A2', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001024', 15, 2006, 'D-A2', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001024', 17, 2006, 'D-A2', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001024', 26, 2006, 'D-A2', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001024', 28, 2004, 'C-A1', EXTEND(MDY(2,7,2005), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001045', 1, 2005, 'A-A', EXTEND(MDY(7,4,2006), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001050', 1, 2005, 'D-A2', EXTEND(MDY(7,4,2006), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001050', 2, 2004, 'C-A4', EXTEND(MDY(9,11,2006), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001050', 3, 2004, 'C-A4', EXTEND(MDY(7,13,2006), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001050', 9, 2004, 'C-A4', EXTEND(MDY(2,15,2005), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001050', 10, 2004, 'C-A4', EXTEND(MDY(2,10,2005), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001050', 11, 2004, 'C-A4', EXTEND(MDY(6,21,2005), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001050', 12, 2004, 'C-A4', EXTEND(MDY(6,21,2005), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001050', 13, 2005, 'D-A2', EXTEND(MDY(2,1,2006), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001050', 14, 2005, 'D-A2', EXTEND(MDY(6,16,2006), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001050', 15, 2005, 'D-A2', EXTEND(MDY(2,20,2006), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001050', 17, 2005, 'D-A2', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001050', 26, 2005, 'D-A2', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001050', 27, 2005, 'D-A2', EXTEND(MDY(6,20,2006), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001050', 29, 2005, 'D-A1', EXTEND(MDY(6,12,2006), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001066', 1, 2005, 'D-A4', EXTEND(MDY(9,5,2006), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001066', 3, 2003, 'C-A5', EXTEND(MDY(6,30,2006), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001066', 9, 2003, 'C-A5', EXTEND(MDY(9,12,2006), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001066', 10, 2003, 'C-A5', EXTEND(MDY(2,10,2005), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001066', 11, 2003, 'C-A5', EXTEND(MDY(6,21,2005), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001066', 12, 2003, 'C-A5', EXTEND(MDY(11,11,2005), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001066', 13, 2005, 'D-A4', EXTEND(MDY(4,5,2006), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001066', 14, 2005, 'D-A4', EXTEND(MDY(6,16,2006), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001066', 15, 2005, 'D-A4', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001066', 17, 2005, 'D-A4', EXTEND(MDY(1,30,2006), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001066', 26, 2005, 'D-A4', EXTEND(MDY(9,28,2006), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001066', 27, 2005, 'D-A4', EXTEND(MDY(6,20,2006), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001066', 28, 2003, 'C-A5', EXTEND(MDY(2,7,2005), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001066', 29, 2005, 'D-A4', EXTEND(MDY(6,12,2006), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001071', 1, 2003, 'D-A1', EXTEND(MDY(9,27,2004), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001071', 13, 2003, 'D-A1', EXTEND(MDY(5,17,2006), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001071', 14, 2003, 'D-A1', EXTEND(MDY(3,13,2006), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001071', 15, 2003, 'D-A1', EXTEND(MDY(2,10,2005), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001071', 17, 2003, 'D-A1', EXTEND(MDY(2,20,2004), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001071', 27, 2003, 'D-A1', EXTEND(MDY(6,28,2004), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001071', 29, 2003, 'D-A1', EXTEND(MDY(9,28,2005), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001087', 1, 2005, 'A-A', EXTEND(MDY(9,5,2006), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001092', 1, 2004, 'D-A4', EXTEND(MDY(6,30,2005), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001092', 2, 2003, 'C-A2', EXTEND(MDY(9,11,2006), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001092', 3, 2003, 'C-A2', EXTEND(MDY(9,29,2005), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001092', 9, 2003, 'C-A2', EXTEND(MDY(2,6,2004), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001092', 10, 2003, 'C-A2', EXTEND(MDY(2,12,2004), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001092', 11, 2003, 'C-A2', EXTEND(MDY(6,23,2004), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001092', 13, 2004, 'D-A4', EXTEND(MDY(2,14,2005), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001092', 14, 2004, 'D-A4', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001092', 15, 2004, 'D-A4', EXTEND(MDY(2,20,2006), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001092', 17, 2004, 'D-A4', EXTEND(MDY(2,18,2005), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001092', 26, 2004, 'D-A4', EXTEND(MDY(9,26,2005), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001092', 27, 2004, 'D-A4', EXTEND(MDY(6,21,2005), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001092', 29, 2004, 'D-A4', EXTEND(MDY(6,13,2005), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001115', 1, 2004, 'D-A5', EXTEND(MDY(7,7,2005), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001115', 2, 2003, 'C-A2', EXTEND(MDY(2,2,2004), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001115', 3, 2003, 'C-A2', EXTEND(MDY(9,12,2005), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001115', 5, 2004, 'D-A5', EXTEND(MDY(2,7,2005), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001115', 10, 2003, 'C-A2', EXTEND(MDY(2,12,2004), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001115', 11, 2003, 'C-A2', EXTEND(MDY(6,23,2004), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001115', 12, 2003, 'C-A2', EXTEND(MDY(9,10,2004), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001115', 13, 2004, 'D-A5', EXTEND(MDY(9,21,2005), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001115', 14, 2004, 'D-A5', EXTEND(MDY(6,16,2005), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001115', 15, 2004, 'D-A5', EXTEND(MDY(2,20,2006), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001115', 17, 2004, 'D-A5', EXTEND(MDY(2,18,2005), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001115', 26, 2004, 'D-A5', EXTEND(MDY(9,26,2005), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001115', 27, 2004, 'D-A5', EXTEND(MDY(6,26,2006), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001115', 28, 2003, 'C-A2', EXTEND(MDY(2,9,2004), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001115', 29, 2004, 'D-A5', EXTEND(MDY(6,13,2005), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001120', 1, 2004, 'D-A3', EXTEND(MDY(7,7,2005), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001120', 3, 2003, 'C-A2', EXTEND(MDY(9,9,2004), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001120', 12, 2003, 'C-A2', EXTEND(MDY(6,21,2004), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001120', 13, 2004, 'D-A3', EXTEND(MDY(2,14,2005), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001120', 14, 2004, 'D-A3', EXTEND(MDY(6,16,2005), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001120', 15, 2004, 'D-A3', EXTEND(MDY(2,10,2005), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001120', 17, 2004, 'D-A3', EXTEND(MDY(4,12,2005), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001120', 26, 2004, 'D-A3', EXTEND(MDY(5,4,2006), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001120', 27, 2004, 'D-A3', EXTEND(MDY(6,21,2005), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001120', 28, 2003, 'C-A2', EXTEND(MDY(2,9,2004), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001120', 29, 2004, 'D-A3', EXTEND(MDY(6,13,2005), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001136', 3, 2004, 'C-A1', EXTEND(MDY(4,5,2006), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001136', 9, 2004, 'C-A1', EXTEND(MDY(9,1,2005), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001136', 11, 2004, 'C-A1', EXTEND(MDY(6,21,2005), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001136', 12, 2004, 'C-A1', EXTEND(MDY(6,21,2005), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001136', 13, 2006, 'D-A5', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001136', 15, 2006, 'D-A5', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001136', 17, 2006, 'D-A5', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001136', 26, 2006, 'D-A5', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001141', 2, 2005, 'C-B2', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001141', 4, 2005, 'C-B2', EXTEND(MDY(6,30,2006), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001141', 6, 2005, 'C-B2', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001141', 7, 2005, 'C-B2', EXTEND(MDY(6,20,2006), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001141', 8, 2005, 'C-B2', EXTEND(MDY(7,3,2006), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001141', 9, 2005, 'C-B2', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001141', 12, 2005, 'C-B2', EXTEND(MDY(6,20,2006), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001157', 1, 2005, 'D-A5', EXTEND(MDY(6,13,2006), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001157', 2, 2003, 'C-A5', EXTEND(MDY(2,14,2005), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001157', 3, 2003, 'C-A5', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001157', 9, 2003, 'C-A5', EXTEND(MDY(9,13,2005), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001157', 10, 2003, 'C-A5', EXTEND(MDY(2,10,2005), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001157', 11, 2003, 'C-A5', EXTEND(MDY(6,16,2004), YEAR to SECOND), 1);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001157', 11, 2005, 'A-A', EXTEND(MDY(6,21,2006), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001157', 12, 2003, 'C-A5', EXTEND(MDY(7,5,2005), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001157', 13, 2005, 'D-A5', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001157', 14, 2005, 'D-A5', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001157', 15, 2005, 'D-A5', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001157', 17, 2005, 'D-A5', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001157', 26, 2005, 'D-A5', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001157', 27, 2005, 'D-A5', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001157', 28, 2003, 'C-A5', EXTEND(MDY(2,7,2005), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001157', 29, 2005, 'D-A5', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001178', 1, 2004, 'D-A1', EXTEND(MDY(6,16,2005), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001178', 3, 2003, 'C-A3', EXTEND(MDY(6,15,2004), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001178', 5, 2004, 'D-A1', EXTEND(MDY(2,7,2005), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001178', 9, 2003, 'C-A3', EXTEND(MDY(2,6,2004), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001178', 10, 2003, 'C-A3', EXTEND(MDY(2,12,2004), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001178', 11, 2003, 'C-A3', EXTEND(MDY(6,23,2004), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001178', 12, 2003, 'C-A3', EXTEND(MDY(6,21,2004), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001178', 13, 2004, 'D-A1', EXTEND(MDY(2,14,2005), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001178', 14, 2004, 'D-A1', EXTEND(MDY(6,16,2005), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001178', 15, 2004, 'D-A1', EXTEND(MDY(2,10,2005), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001178', 17, 2004, 'D-A1', EXTEND(MDY(4,12,2005), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001178', 26, 2004, 'D-A1', EXTEND(MDY(7,11,2006), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001178', 27, 2004, 'D-A1', EXTEND(MDY(6,21,2005), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001178', 28, 2003, 'C-A3', EXTEND(MDY(2,9,2004), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001178', 29, 2004, 'D-A1', EXTEND(MDY(6,13,2005), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001183', 1, 2005, 'A-A', EXTEND(MDY(6,13,2006), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001199', 3, 2003, 'C-A3', EXTEND(MDY(7,14,2005), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001199', 9, 2003, 'C-A3', EXTEND(MDY(4,21,2004), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001199', 10, 2003, 'C-A3', EXTEND(MDY(2,12,2004), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001199', 11, 2003, 'C-A3', EXTEND(MDY(6,23,2004), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001199', 12, 2003, 'C-A3', EXTEND(MDY(6,21,2004), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001199', 13, 2006, 'D-A5', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001199', 15, 2006, 'D-A5', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001199', 17, 2006, 'D-A5', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001199', 28, 2003, 'C-A3', EXTEND(MDY(2,7,2005), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001206', 1, 2004, 'D-A1', EXTEND(MDY(6,30,2005), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001206', 3, 2003, 'C-A2', EXTEND(MDY(6,15,2004), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001206', 5, 2004, 'D-A1', EXTEND(MDY(2,15,2005), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001206', 9, 2003, 'C-A2', EXTEND(MDY(4,21,2004), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001206', 10, 2003, 'C-A2', EXTEND(MDY(2,10,2005), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001206', 11, 2003, 'C-A2', EXTEND(MDY(6,21,2005), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001206', 12, 2003, 'C-A2', EXTEND(MDY(6,21,2004), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001206', 13, 2004, 'D-A1', EXTEND(MDY(2,14,2005), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001206', 14, 2004, 'D-A1', EXTEND(MDY(6,16,2005), YEAR to SECOND), 1);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001206', 14, 2005, 'A-A', EXTEND(MDY(6,16,2006), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001206', 15, 2004, 'D-A1', EXTEND(MDY(2,20,2006), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001206', 17, 2004, 'D-A1', EXTEND(MDY(4,4,2006), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001206', 26, 2004, 'D-A1', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001206', 27, 2004, 'D-A1', EXTEND(MDY(6,21,2005), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001206', 28, 2003, 'C-A2', EXTEND(MDY(6,29,2004), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001206', 29, 2004, 'D-A1', EXTEND(MDY(6,13,2005), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001211', 1, 2004, 'D-B1', EXTEND(MDY(6,16,2005), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001211', 2, 2003, 'C-B2', EXTEND(MDY(2,2,2004), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001211', 4, 2003, 'C-B2', EXTEND(MDY(2,3,2004), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001211', 5, 2003, 'C-B2', EXTEND(MDY(2,9,2004), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001211', 6, 2003, 'C-B2', EXTEND(MDY(6,16,2004), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001211', 7, 2003, 'C-B2', EXTEND(MDY(2,7,2005), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001211', 8, 2003, 'C-B2', EXTEND(MDY(11,12,2004), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001211', 9, 2003, 'C-B2', EXTEND(MDY(2,6,2004), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001211', 12, 2003, 'C-B2', EXTEND(MDY(6,21,2004), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001211', 18, 2004, 'D-B1', EXTEND(MDY(12,7,2005), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001211', 19, 2004, 'D-B1', EXTEND(MDY(2,7,2005), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001211', 20, 2004, 'D-B1', EXTEND(MDY(2,21,2005), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001211', 21, 2004, 'D-B1', EXTEND(MDY(6,15,2005), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001211', 22, 2004, 'D-B1', EXTEND(MDY(6,20,2005), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001211', 23, 2004, 'D-B1', EXTEND(MDY(6,14,2005), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001211', 25, 2004, 'D-B1', EXTEND(MDY(9,9,2005), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001227', 1, 2004, 'D-A4', EXTEND(MDY(6,16,2005), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001227', 3, 2003, 'C-A1', EXTEND(MDY(7,2,2004), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001227', 5, 2004, 'D-A4', EXTEND(MDY(2,7,2005), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001227', 9, 2003, 'C-A1', EXTEND(MDY(4,21,2004), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001227', 10, 2003, 'C-A1', EXTEND(MDY(2,12,2004), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001227', 11, 2003, 'C-A1', EXTEND(MDY(6,23,2004), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001227', 12, 2003, 'C-A1', EXTEND(MDY(7,14,2004), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001227', 13, 2004, 'D-A4', EXTEND(MDY(2,14,2005), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001227', 14, 2004, 'D-A4', EXTEND(MDY(3,13,2006), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001227', 15, 2004, 'D-A4', EXTEND(MDY(2,21,2005), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001227', 17, 2004, 'D-A4', EXTEND(MDY(9,7,2005), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001227', 27, 2004, 'D-A4', EXTEND(MDY(6,27,2005), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001227', 28, 2003, 'C-A1', EXTEND(MDY(2,9,2004), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001227', 29, 2004, 'D-A4', EXTEND(MDY(9,5,2005), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001232', 1, 2004, 'D-A5', EXTEND(MDY(6,16,2005), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001232', 3, 2003, 'C-A2', EXTEND(MDY(6,15,2004), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001232', 5, 2004, 'D-A5', EXTEND(MDY(2,7,2005), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001232', 9, 2003, 'C-A2', EXTEND(MDY(2,6,2004), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001232', 10, 2003, 'C-A2', EXTEND(MDY(2,12,2004), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001232', 11, 2003, 'C-A2', EXTEND(MDY(6,23,2004), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001232', 12, 2003, 'C-A2', EXTEND(MDY(6,21,2004), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001232', 13, 2004, 'D-A5', EXTEND(MDY(2,14,2005), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001232', 14, 2004, 'D-A5', EXTEND(MDY(6,16,2005), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001232', 15, 2004, 'D-A5', EXTEND(MDY(2,10,2005), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001232', 17, 2004, 'D-A5', EXTEND(MDY(1,31,2005), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001232', 26, 2004, 'D-A5', EXTEND(MDY(9,26,2005), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001232', 27, 2004, 'D-A5', EXTEND(MDY(6,21,2005), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001232', 28, 2003, 'C-A2', EXTEND(MDY(2,9,2004), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001232', 29, 2004, 'D-A5', EXTEND(MDY(6,13,2005), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001248', 1, 2005, 'A-A', EXTEND(MDY(6,13,2006), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001253', 1, 2005, 'D-A4', EXTEND(MDY(7,4,2006), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001253', 2, 2004, 'C-A1', EXTEND(MDY(9,11,2006), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001253', 3, 2004, 'C-A1', EXTEND(MDY(6,14,2005), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001253', 9, 2004, 'C-A1', EXTEND(MDY(2,15,2005), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001253', 12, 2004, 'C-A1', EXTEND(MDY(7,5,2005), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001253', 13, 2005, 'D-A4', EXTEND(MDY(2,13,2006), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001253', 14, 2005, 'D-A4', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001253', 15, 2005, 'D-A4', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001253', 17, 2005, 'D-A4', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001253', 26, 2005, 'D-A4', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001253', 27, 2005, 'D-A4', EXTEND(MDY(6,20,2006), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001253', 28, 2004, 'C-A1', EXTEND(MDY(2,7,2005), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001253', 29, 2005, 'D-A4', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001269', 1, 2004, 'D-A2', EXTEND(MDY(6,16,2005), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001269', 3, 2003, 'C-A4', EXTEND(MDY(7,14,2005), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001269', 9, 2003, 'C-A4', EXTEND(MDY(7,13,2004), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001269', 10, 2003, 'C-A4', EXTEND(MDY(2,12,2004), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001269', 11, 2003, 'C-A4', EXTEND(MDY(6,23,2004), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001269', 12, 2003, 'C-A4', EXTEND(MDY(6,21,2004), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001269', 13, 2004, 'D-A2', EXTEND(MDY(11,8,2006), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001269', 14, 2004, 'D-A2', EXTEND(MDY(6,16,2006), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001269', 15, 2004, 'D-A2', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001269', 17, 2004, 'D-A2', EXTEND(MDY(9,19,2005), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001269', 26, 2004, 'D-A2', EXTEND(MDY(9,22,2005), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001269', 27, 2004, 'D-A2', EXTEND(MDY(6,16,2005), YEAR to SECOND), 1);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001269', 27, 2005, 'A-A', EXTEND(MDY(7,7,2006), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001269', 28, 2003, 'C-A4', EXTEND(MDY(2,9,2004), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001269', 29, 2004, 'D-A2', EXTEND(MDY(6,13,2005), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001274', 31, 2006, 'A-K', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001274', 32, 2006, 'A-K', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001274', 34, 2006, 'A-L', EXTEND(MDY(2,1,2007), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001274', 40, 2006, 'B-E', EXTEND(MDY(2,1,2007), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001274', 44, 2006, 'B-E', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001295', 1, 2004, 'D-A4', EXTEND(MDY(9,1,2005), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001295', 2, 2003, 'C-A2', EXTEND(MDY(2,2,2004), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001295', 3, 2003, 'C-A2', EXTEND(MDY(7,1,2005), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001295', 5, 2004, 'D-A4', EXTEND(MDY(2,7,2005), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001295', 9, 2003, 'C-A2', EXTEND(MDY(2,15,2005), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001295', 10, 2003, 'C-A2', EXTEND(MDY(2,12,2004), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001295', 11, 2003, 'C-A2', EXTEND(MDY(6,23,2004), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001295', 12, 2003, 'C-A2', EXTEND(MDY(6,21,2005), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001295', 13, 2004, 'D-A4', EXTEND(MDY(2,14,2005), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001295', 14, 2004, 'D-A4', EXTEND(MDY(6,16,2005), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001295', 15, 2004, 'D-A4', EXTEND(MDY(2,20,2006), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001295', 17, 2004, 'D-A4', EXTEND(MDY(1,31,2005), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001295', 26, 2004, 'D-A4', EXTEND(MDY(9,22,2005), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001295', 27, 2004, 'D-A4', EXTEND(MDY(7,8,2005), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001295', 28, 2003, 'C-A2', EXTEND(MDY(2,9,2004), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001295', 29, 2004, 'D-A4', EXTEND(MDY(6,13,2005), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001302', 2, 2005, 'C-B4', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001302', 4, 2005, 'C-B4', EXTEND(MDY(6,21,2006), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001302', 5, 2005, 'C-B4', EXTEND(MDY(2,6,2006), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001302', 6, 2005, 'C-B4', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001302', 7, 2005, 'C-B4', EXTEND(MDY(9,28,2006), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001302', 8, 2005, 'C-B4', EXTEND(MDY(7,11,2006), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001302', 9, 2005, 'C-B4', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001302', 12, 2005, 'C-B4', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001318', 1, 2004, 'D-A4', EXTEND(MDY(4,4,2006), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001318', 3, 2003, 'C-A3', EXTEND(MDY(11,12,2004), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001318', 5, 2004, 'D-A4', EXTEND(MDY(2,7,2005), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001318', 9, 2003, 'C-A3', EXTEND(MDY(2,6,2004), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001318', 10, 2003, 'C-A3', EXTEND(MDY(2,12,2004), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001318', 11, 2003, 'C-A3', EXTEND(MDY(6,23,2004), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001318', 12, 2003, 'C-A3', EXTEND(MDY(6,21,2004), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001318', 13, 2004, 'D-A4', EXTEND(MDY(2,14,2005), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001318', 14, 2004, 'D-A4', EXTEND(MDY(6,16,2005), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001318', 15, 2004, 'D-A4', EXTEND(MDY(2,10,2005), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001318', 17, 2004, 'D-A4', EXTEND(MDY(9,27,2005), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001318', 26, 2004, 'D-A4', EXTEND(MDY(9,22,2005), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001318', 27, 2004, 'D-A4', EXTEND(MDY(6,21,2005), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001318', 28, 2003, 'C-A3', EXTEND(MDY(2,9,2004), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001318', 29, 2004, 'D-A4', EXTEND(MDY(6,13,2005), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001323', 1, 2005, 'D-A4', EXTEND(MDY(7,12,2006), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001323', 3, 2004, 'C-A1', EXTEND(MDY(6,13,2006), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001323', 9, 2004, 'C-A1', EXTEND(MDY(2,15,2005), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001323', 10, 2004, 'C-A1', EXTEND(MDY(2,10,2005), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001323', 11, 2004, 'C-A1', EXTEND(MDY(6,16,2005), YEAR to SECOND), 1);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001323', 11, 2005, 'A-A', EXTEND(MDY(6,21,2006), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001323', 12, 2004, 'C-A1', EXTEND(MDY(7,13,2005), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001323', 13, 2005, 'D-A4', EXTEND(MDY(2,13,2006), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001323', 14, 2005, 'D-A4', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001323', 15, 2005, 'D-A4', EXTEND(MDY(4,4,2006), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001323', 17, 2005, 'D-A4', EXTEND(MDY(9,26,2006), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001323', 26, 2005, 'D-A4', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001323', 27, 2005, 'D-A4', EXTEND(MDY(7,7,2006), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001323', 28, 2004, 'C-A1', EXTEND(MDY(2,7,2005), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001323', 29, 2005, 'D-A1', EXTEND(MDY(6,12,2006), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001339', 1, 2005, 'A-A', EXTEND(MDY(7,4,2006), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001344', 1, 2004, 'D-A5', EXTEND(MDY(9,1,2005), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001344', 3, 2003, 'C-A5', EXTEND(MDY(9,30,2004), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001344', 9, 2003, 'C-A5', EXTEND(MDY(2,6,2004), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001344', 10, 2003, 'C-A5', EXTEND(MDY(2,12,2004), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001344', 11, 2003, 'C-A5', EXTEND(MDY(6,23,2004), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001344', 12, 2003, 'C-A5', EXTEND(MDY(6,21,2004), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001344', 13, 2004, 'D-A5', EXTEND(MDY(2,14,2005), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001344', 14, 2004, 'D-A5', EXTEND(MDY(6,16,2005), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001344', 15, 2004, 'D-A5', EXTEND(MDY(2,10,2005), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001344', 17, 2004, 'D-A5', EXTEND(MDY(1,31,2005), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001344', 27, 2004, 'D-A5', EXTEND(MDY(6,21,2005), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001344', 28, 2003, 'C-A5', EXTEND(MDY(2,9,2004), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001344', 29, 2004, 'D-A5', EXTEND(MDY(6,13,2005), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001365', 10, 2006, 'C-A2', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001365', 28, 2006, 'C-A2', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001370', 1, 2004, 'D-A5', EXTEND(MDY(6,16,2005), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001370', 2, 2003, 'C-A3', EXTEND(MDY(2,2,2004), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001370', 3, 2003, 'C-A3', EXTEND(MDY(6,15,2004), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001370', 5, 2004, 'D-A5', EXTEND(MDY(2,7,2005), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001370', 9, 2003, 'C-A3', EXTEND(MDY(2,6,2004), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001370', 10, 2003, 'C-A3', EXTEND(MDY(2,12,2004), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001370', 11, 2003, 'C-A3', EXTEND(MDY(6,23,2004), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001370', 12, 2003, 'C-A3', EXTEND(MDY(6,21,2004), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001370', 13, 2004, 'D-A5', EXTEND(MDY(2,14,2005), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001370', 14, 2004, 'D-A5', EXTEND(MDY(6,16,2005), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001370', 15, 2004, 'D-A5', EXTEND(MDY(2,10,2005), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001370', 17, 2004, 'D-A5', EXTEND(MDY(2,18,2005), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001370', 26, 2004, 'D-A5', EXTEND(MDY(7,12,2005), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001370', 27, 2004, 'D-A5', EXTEND(MDY(6,21,2005), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001370', 28, 2003, 'C-A3', EXTEND(MDY(2,9,2004), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001370', 29, 2004, 'D-A5', EXTEND(MDY(6,13,2005), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001386', 1, 2005, 'D-A4', EXTEND(MDY(9,26,2006), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001386', 3, 2004, 'C-A1', EXTEND(MDY(6,14,2005), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001386', 9, 2004, 'C-A1', EXTEND(MDY(2,4,2005), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001386', 10, 2004, 'C-A1', EXTEND(MDY(2,10,2005), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001386', 11, 2004, 'C-A1', EXTEND(MDY(6,21,2005), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001386', 12, 2004, 'C-A1', EXTEND(MDY(6,21,2005), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001386', 13, 2005, 'D-A4', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001386', 14, 2005, 'D-A4', EXTEND(MDY(6,16,2006), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001386', 15, 2005, 'D-A4', EXTEND(MDY(2,20,2006), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001386', 17, 2005, 'D-A4', EXTEND(MDY(1,30,2006), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001386', 26, 2005, 'D-A4', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001386', 27, 2005, 'D-A4', EXTEND(MDY(6,20,2006), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001386', 28, 2004, 'C-A1', EXTEND(MDY(2,7,2005), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001386', 29, 2005, 'D-A4', EXTEND(MDY(6,12,2006), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001391', 1, 2004, 'D-A1', EXTEND(MDY(6,30,2005), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001391', 2, 2003, 'C-A4', EXTEND(MDY(7,16,2004), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001391', 3, 2003, 'C-A4', EXTEND(MDY(9,9,2004), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001391', 9, 2003, 'C-A4', EXTEND(MDY(6,23,2004), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001391', 10, 2003, 'C-A4', EXTEND(MDY(2,12,2004), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001391', 11, 2003, 'C-A4', EXTEND(MDY(6,21,2005), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001391', 12, 2003, 'C-A4', EXTEND(MDY(6,21,2004), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001391', 13, 2004, 'D-A1', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001391', 14, 2004, 'D-A1', EXTEND(MDY(6,16,2005), YEAR to SECOND), 1);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001391', 14, 2005, 'A-A', EXTEND(MDY(6,16,2006), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001391', 15, 2004, 'D-A1', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001391', 17, 2004, 'D-A1', EXTEND(MDY(2,17,2006), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001391', 26, 2004, 'D-A1', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001391', 27, 2004, 'D-A1', EXTEND(MDY(6,21,2005), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001391', 28, 2003, 'C-A4', EXTEND(MDY(2,7,2005), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001391', 29, 2004, 'D-A1', EXTEND(MDY(6,13,2005), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001409', 1, 2004, 'D-A3', EXTEND(MDY(4,4,2006), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001409', 3, 2003, 'C-A3', EXTEND(MDY(9,9,2004), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001409', 5, 2004, 'D-A3', EXTEND(MDY(2,7,2005), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001409', 9, 2003, 'C-A3', EXTEND(MDY(2,6,2004), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001409', 10, 2003, 'C-A3', EXTEND(MDY(2,12,2004), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001409', 11, 2003, 'C-A3', EXTEND(MDY(6,23,2004), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001409', 12, 2003, 'C-A3', EXTEND(MDY(6,21,2004), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001409', 13, 2004, 'D-A3', EXTEND(MDY(2,14,2005), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001409', 14, 2004, 'D-A3', EXTEND(MDY(3,13,2006), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001409', 15, 2004, 'D-A3', EXTEND(MDY(2,21,2005), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001409', 17, 2004, 'D-A3', EXTEND(MDY(9,27,2005), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001409', 27, 2004, 'D-A3', EXTEND(MDY(6,27,2005), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001409', 28, 2003, 'C-A3', EXTEND(MDY(2,9,2004), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001409', 29, 2004, 'D-A3', EXTEND(MDY(6,13,2005), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001414', 1, 2004, 'D-B1', EXTEND(MDY(6,30,2005), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001414', 2, 2003, 'C-B4', EXTEND(MDY(7,1,2005), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001414', 4, 2003, 'C-B4', EXTEND(MDY(2,19,2004), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001414', 5, 2003, 'C-B4', EXTEND(MDY(2,9,2004), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001414', 6, 2003, 'C-B4', EXTEND(MDY(2,22,2005), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001414', 7, 2003, 'C-B4', EXTEND(MDY(6,15,2004), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001414', 8, 2003, 'C-B4', EXTEND(MDY(6,14,2004), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001414', 9, 2003, 'C-B4', EXTEND(MDY(4,21,2004), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001414', 12, 2003, 'C-B4', EXTEND(MDY(9,5,2005), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001414', 18, 2004, 'D-B1', EXTEND(MDY(2,14,2005), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001414', 19, 2004, 'D-B1', EXTEND(MDY(2,7,2005), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001414', 20, 2004, 'D-B1', EXTEND(MDY(2,9,2005), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001414', 21, 2004, 'D-B1', EXTEND(MDY(7,5,2005), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001414', 22, 2004, 'D-B1', EXTEND(MDY(6,20,2005), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001414', 23, 2004, 'D-B1', EXTEND(MDY(7,5,2005), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001414', 25, 2004, 'D-B1', EXTEND(MDY(7,7,2005), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001435', 1, 2004, 'D-A1', EXTEND(MDY(7,4,2006), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001435', 3, 2003, 'C-A3', EXTEND(MDY(7,15,2004), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001435', 5, 2004, 'D-A1', EXTEND(MDY(2,7,2005), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001435', 9, 2003, 'C-A3', EXTEND(MDY(2,6,2004), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001435', 10, 2003, 'C-A3', EXTEND(MDY(2,12,2004), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001435', 11, 2003, 'C-A3', EXTEND(MDY(6,23,2004), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001435', 12, 2003, 'C-A3', EXTEND(MDY(6,21,2004), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001435', 13, 2004, 'D-A1', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001435', 14, 2004, 'D-A1', EXTEND(MDY(6,16,2005), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001435', 15, 2004, 'D-A1', EXTEND(MDY(2,10,2005), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001435', 17, 2004, 'D-A1', EXTEND(MDY(2,17,2006), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001435', 26, 2004, 'D-A1', EXTEND(MDY(9,22,2005), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001435', 27, 2004, 'D-A1', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001435', 28, 2003, 'C-A3', EXTEND(MDY(2,9,2004), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001435', 29, 2004, 'D-A1', EXTEND(MDY(6,13,2005), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001440', 1, 2004, 'D-A1', EXTEND(MDY(6,16,2005), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001440', 3, 2003, 'C-A4', EXTEND(MDY(6,15,2004), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001440', 9, 2003, 'C-A4', EXTEND(MDY(2,6,2004), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001440', 10, 2003, 'C-A4', EXTEND(MDY(2,12,2004), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001440', 11, 2003, 'C-A4', EXTEND(MDY(6,23,2004), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001440', 12, 2003, 'C-A4', EXTEND(MDY(2,11,2005), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001440', 13, 2004, 'D-A1', EXTEND(MDY(2,13,2006), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001440', 14, 2004, 'D-A1', EXTEND(MDY(5,15,2006), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001440', 15, 2004, 'D-A1', EXTEND(MDY(2,21,2005), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001440', 17, 2004, 'D-A1', EXTEND(MDY(9,7,2005), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001440', 26, 2004, 'D-A1', EXTEND(MDY(7,12,2005), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001440', 27, 2004, 'D-A1', EXTEND(MDY(6,21,2005), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001440', 28, 2003, 'C-A4', EXTEND(MDY(2,9,2004), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001440', 29, 2004, 'D-A1', EXTEND(MDY(6,13,2005), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001456', 1, 2004, 'D-B5', EXTEND(MDY(9,22,2005), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001456', 2, 2003, 'C-B2', EXTEND(MDY(2,2,2004), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001456', 4, 2003, 'C-B2', EXTEND(MDY(2,3,2004), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001456', 5, 2003, 'C-B2', EXTEND(MDY(2,9,2004), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001456', 6, 2003, 'C-B2', EXTEND(MDY(6,16,2004), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001456', 7, 2003, 'C-B2', EXTEND(MDY(6,15,2004), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001456', 8, 2003, 'C-B2', EXTEND(MDY(7,5,2004), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001456', 9, 2003, 'C-B2', EXTEND(MDY(2,6,2004), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001456', 12, 2003, 'C-B2', EXTEND(MDY(6,21,2004), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001456', 18, 2004, 'D-B5', EXTEND(MDY(2,14,2005), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001456', 19, 2004, 'D-B5', EXTEND(MDY(2,7,2005), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001456', 20, 2004, 'D-B5', EXTEND(MDY(2,9,2005), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001456', 21, 2004, 'D-B5', EXTEND(MDY(6,15,2005), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001456', 22, 2004, 'D-B5', EXTEND(MDY(6,20,2005), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001456', 23, 2004, 'D-B5', EXTEND(MDY(7,5,2005), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001456', 25, 2004, 'D-B5', EXTEND(MDY(7,7,2005), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001461', 1, 2004, 'D-A3', EXTEND(MDY(6,13,2006), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001461', 3, 2003, 'C-A1', EXTEND(MDY(9,2,2005), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001461', 5, 2004, 'D-A3', EXTEND(MDY(2,7,2005), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001461', 9, 2003, 'C-A1', EXTEND(MDY(9,13,2004), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001461', 10, 2003, 'C-A1', EXTEND(MDY(2,12,2004), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001461', 11, 2003, 'C-A1', EXTEND(MDY(6,23,2004), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001461', 12, 2003, 'C-A1', EXTEND(MDY(9,5,2005), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001461', 13, 2004, 'D-A3', EXTEND(MDY(6,14,2006), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001461', 14, 2004, 'D-A3', EXTEND(MDY(6,16,2005), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001461', 15, 2004, 'D-A3', EXTEND(MDY(2,21,2005), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001461', 17, 2004, 'D-A3', EXTEND(MDY(6,27,2005), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001461', 27, 2004, 'D-A3', EXTEND(MDY(6,21,2005), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001461', 28, 2003, 'C-A1', EXTEND(MDY(2,9,2004), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001461', 29, 2004, 'D-A3', EXTEND(MDY(6,13,2005), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001482', 1, 2004, 'D-A1', EXTEND(MDY(9,22,2005), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001482', 3, 2003, 'C-A2', EXTEND(MDY(6,15,2004), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001482', 9, 2003, 'C-A2', EXTEND(MDY(2,6,2004), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001482', 10, 2003, 'C-A2', EXTEND(MDY(2,12,2004), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001482', 11, 2003, 'C-A2', EXTEND(MDY(6,23,2004), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001482', 12, 2003, 'C-A2', EXTEND(MDY(6,21,2004), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001482', 13, 2004, 'D-A1', EXTEND(MDY(7,14,2005), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001482', 14, 2004, 'D-A1', EXTEND(MDY(6,16,2005), YEAR to SECOND), 1);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001482', 14, 2005, 'A-A', EXTEND(MDY(6,16,2006), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001482', 15, 2004, 'D-A1', EXTEND(MDY(2,20,2006), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001482', 17, 2004, 'D-A1', EXTEND(MDY(6,27,2005), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001482', 26, 2004, 'D-A1', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001482', 27, 2004, 'D-A1', EXTEND(MDY(6,20,2005), YEAR to SECOND), 1);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001482', 27, 2005, 'A-A', EXTEND(MDY(6,20,2006), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001482', 28, 2003, 'C-A2', EXTEND(MDY(2,9,2004), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001482', 29, 2004, 'D-A1', EXTEND(MDY(6,13,2005), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001498', 1, 2005, 'D-A2', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001498', 3, 2004, 'C-A1', EXTEND(MDY(7,13,2006), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001498', 12, 2004, 'C-A1', EXTEND(MDY(6,21,2005), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001498', 13, 2005, 'D-A2', EXTEND(MDY(2,13,2006), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001498', 14, 2005, 'D-A2', EXTEND(MDY(6,26,2006), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001498', 15, 2005, 'D-A2', EXTEND(MDY(2,20,2006), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001498', 17, 2005, 'D-A2', EXTEND(MDY(4,4,2006), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001498', 26, 2005, 'D-A2', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001498', 27, 2005, 'D-A2', EXTEND(MDY(6,26,2006), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001498', 28, 2004, 'C-A1', EXTEND(MDY(2,7,2005), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001498', 29, 2005, 'D-A2', EXTEND(MDY(6,12,2006), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001510', 2, 2005, 'C-B1', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001510', 6, 2005, 'C-B1', EXTEND(MDY(6,27,2006), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001510', 7, 2005, 'C-B1', EXTEND(MDY(7,11,2006), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001510', 9, 2005, 'C-B1', EXTEND(MDY(4,5,2006), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001510', 12, 2005, 'C-B1', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001526', 1, 2005, 'D-B2', EXTEND(MDY(6,13,2006), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001526', 2, 2004, 'C-B2', EXTEND(MDY(9,28,2005), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001526', 4, 2004, 'C-B2', EXTEND(MDY(2,1,2005), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001526', 5, 2004, 'C-B2', EXTEND(MDY(2,7,2005), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001526', 6, 2004, 'C-B2', EXTEND(MDY(6,14,2006), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001526', 7, 2004, 'C-B2', EXTEND(MDY(6,14,2005), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001526', 8, 2004, 'C-B2', EXTEND(MDY(11,11,2005), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001526', 9, 2004, 'C-B2', EXTEND(MDY(9,13,2005), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001526', 12, 2004, 'C-B2', EXTEND(MDY(6,21,2005), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001526', 18, 2005, 'D-B2', EXTEND(MDY(12,13,2006), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001526', 19, 2005, 'D-B2', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001526', 20, 2005, 'D-B2', EXTEND(MDY(2,8,2006), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001526', 21, 2005, 'D-B2', EXTEND(MDY(6,14,2006), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001526', 22, 2005, 'D-B2', EXTEND(MDY(6,19,2006), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001526', 23, 2005, 'D-B2', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001526', 25, 2005, 'D-B2', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001547', 1, 2005, 'A-A', EXTEND(MDY(9,26,2006), YEAR to SECOND), 0);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001547', 2, 2003, 'C-B3', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001547', 4, 2003, 'C-B3', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001547', 5, 2003, 'C-B3', EXTEND(MDY(2,7,2005), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001547', 6, 2003, 'C-B3', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001547', 7, 2003, 'C-B3', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001547', 8, 2003, 'C-B3', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001547', 9, 2003, 'C-B3', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001547', 12, 2003, 'C-B3', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001552', 2, 2004, 'C-A5', EXTEND(MDY(4,14,2005), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001552', 3, 2004, 'C-A5', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001552', 9, 2004, 'C-A5', EXTEND(MDY(2,3,2006), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001552', 10, 2004, 'C-A5', EXTEND(MDY(2,10,2005), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001552', 11, 2004, 'C-A5', EXTEND(MDY(6,21,2005), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001552', 12, 2004, 'C-A5', EXTEND(MDY(7,13,2005), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001552', 13, 2006, 'D-A2', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001552', 15, 2006, 'D-A2', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001552', 17, 2006, 'D-A2', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001552', 26, 2006, 'D-A2', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001552', 28, 2004, 'C-A5', EXTEND(MDY(2,7,2005), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001568', 1, 2004, 'D-A3', EXTEND(MDY(7,12,2006), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001568', 3, 2003, 'C-A2', EXTEND(MDY(7,15,2004), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001568', 5, 2004, 'D-A3', EXTEND(MDY(2,7,2005), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001568', 9, 2003, 'C-A2', EXTEND(MDY(2,17,2004), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001568', 10, 2003, 'C-A2', EXTEND(MDY(2,12,2004), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001568', 11, 2003, 'C-A2', EXTEND(MDY(6,23,2004), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001568', 12, 2003, 'C-A2', EXTEND(MDY(6,21,2004), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001568', 13, 2004, 'D-A3', EXTEND(MDY(2,14,2005), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001568', 14, 2004, 'D-A3', EXTEND(MDY(6,16,2005), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001568', 15, 2004, 'D-A3', EXTEND(MDY(2,10,2005), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001568', 17, 2004, 'D-A3', EXTEND(MDY(2,17,2006), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001568', 26, 2004, 'D-A3', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001568', 27, 2004, 'D-A3', EXTEND(MDY(6,21,2005), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001568', 28, 2003, 'C-A2', EXTEND(MDY(2,9,2004), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001568', 29, 2004, 'D-A3', EXTEND(MDY(6,13,2005), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001573', 2, 2006, 'C-B4', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001573', 4, 2006, 'C-B4', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001573', 5, 2006, 'C-B4', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001573', 9, 2006, 'C-B4', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001589', 3, 2005, 'C-A1', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001589', 9, 2005, 'C-A1', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001589', 10, 2005, 'C-A1', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001589', 11, 2005, 'C-A1', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001589', 12, 2005, 'C-A1', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001589', 28, 2005, 'C-A1', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001601', 1, 2005, 'D-A1', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001601', 3, 2004, 'C-A2', EXTEND(MDY(4,5,2006), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001601', 9, 2004, 'C-A2', EXTEND(MDY(2,15,2005), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001601', 10, 2004, 'C-A2', EXTEND(MDY(2,10,2005), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001601', 11, 2004, 'C-A2', EXTEND(MDY(6,21,2005), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001601', 12, 2004, 'C-A2', EXTEND(MDY(9,5,2005), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001601', 13, 2005, 'D-A1', EXTEND(MDY(6,29,2006), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001601', 14, 2005, 'D-A1', EXTEND(MDY(6,16,2006), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001601', 15, 2005, 'D-A1', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001601', 17, 2005, 'D-A1', EXTEND(MDY(4,4,2006), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001601', 26, 2005, 'D-A1', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001601', 27, 2005, 'D-A1', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001601', 28, 2004, 'C-A2', EXTEND(MDY(6,27,2005), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001601', 29, 2005, 'D-A1', EXTEND(MDY(6,12,2006), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001622', 1, 2005, 'A-A', EXTEND(MDY(7,4,2006), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001638', 4, 2005, 'C-B1', EXTEND(MDY(2,16,2006), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001638', 5, 2005, 'C-B1', EXTEND(MDY(2,6,2006), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001638', 6, 2005, 'C-B1', EXTEND(MDY(6,27,2006), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001638', 7, 2005, 'C-B1', EXTEND(MDY(7,11,2006), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001638', 9, 2005, 'C-B1', EXTEND(MDY(2,3,2006), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001638', 12, 2005, 'C-B1', EXTEND(MDY(6,20,2006), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001638', 18, 2006, 'D-B3', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001638', 19, 2006, 'D-B3', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001638', 20, 2006, 'D-B3', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001638', 25, 2006, 'D-B3', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001659', 32, 2006, 'A-L', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001659', 34, 2006, 'A-K', EXTEND(MDY(2,1,2007), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001659', 42, 2006, 'B-E', EXTEND(MDY(2,1,2007), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001659', 43, 2006, 'B-E', EXTEND(MDY(2,1,2007), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001659', 44, 2006, 'B-E', EXTEND(MDY(2,1,2007), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001664', 2, 2005, 'C-B4', EXTEND(MDY(4,6,2006), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001664', 4, 2005, 'C-B4', EXTEND(MDY(1,31,2006), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001664', 5, 2005, 'C-B4', EXTEND(MDY(2,6,2006), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001664', 6, 2005, 'C-B4', EXTEND(MDY(6,27,2006), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001664', 7, 2005, 'C-B4', EXTEND(MDY(6,13,2006), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001664', 8, 2005, 'C-B4', EXTEND(MDY(6,12,2006), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001664', 12, 2005, 'C-B4', EXTEND(MDY(6,20,2006), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001664', 18, 2006, 'D-B3', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001664', 19, 2006, 'D-B3', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001664', 20, 2006, 'D-B3', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001664', 25, 2006, 'D-B3', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001685', 1, 2005, 'D-A1', EXTEND(MDY(7,4,2006), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001685', 3, 2004, 'C-A1', EXTEND(MDY(9,11,2006), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001685', 9, 2004, 'C-A1', EXTEND(MDY(2,3,2006), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001685', 10, 2004, 'C-A1', EXTEND(MDY(2,10,2005), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001685', 11, 2004, 'C-A1', EXTEND(MDY(6,21,2005), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001685', 12, 2004, 'C-A1', EXTEND(MDY(6,21,2005), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001685', 13, 2005, 'D-A1', EXTEND(MDY(2,1,2006), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001685', 14, 2005, 'D-A1', EXTEND(MDY(6,16,2006), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001685', 15, 2005, 'D-A1', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001685', 17, 2005, 'D-A1', EXTEND(MDY(2,17,2006), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001685', 26, 2005, 'D-A1', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001685', 27, 2005, 'D-A1', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001685', 28, 2004, 'C-A1', EXTEND(MDY(2,7,2005), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001685', 29, 2005, 'D-A1', EXTEND(MDY(9,4,2006), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001708', 1, 2005, 'D-B2', EXTEND(MDY(7,4,2006), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001708', 2, 2004, 'C-B5', EXTEND(MDY(1,31,2005), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001708', 4, 2004, 'C-B5', EXTEND(MDY(2,17,2005), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001708', 5, 2004, 'C-B5', EXTEND(MDY(2,7,2005), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001708', 6, 2004, 'C-B5', EXTEND(MDY(6,28,2005), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001708', 7, 2004, 'C-B5', EXTEND(MDY(6,14,2005), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001708', 8, 2004, 'C-B5', EXTEND(MDY(6,13,2005), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001708', 9, 2004, 'C-B5', EXTEND(MDY(2,4,2005), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001708', 12, 2004, 'C-B5', EXTEND(MDY(6,21,2005), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001708', 18, 2005, 'D-B2', EXTEND(MDY(2,13,2006), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001708', 19, 2005, 'D-B2', EXTEND(MDY(2,6,2006), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001708', 20, 2005, 'D-B2', EXTEND(MDY(2,8,2006), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001708', 21, 2005, 'D-B2', EXTEND(MDY(6,14,2006), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001708', 22, 2005, 'D-B2', EXTEND(MDY(6,19,2006), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001708', 23, 2005, 'D-B2', EXTEND(MDY(6,13,2006), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001708', 25, 2005, 'D-B2', EXTEND(MDY(7,10,2006), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001713', 32, 2006, 'A-L', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001713', 34, 2006, 'A-K', EXTEND(MDY(2,1,2007), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001713', 42, 2006, 'B-K', EXTEND(MDY(2,1,2007), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001713', 44, 2006, 'B-K', EXTEND(MDY(2,1,2007), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001713', 45, 2006, 'B-K', EXTEND(MDY(2,1,2007), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001729', 1, 2005, 'D-A3', EXTEND(MDY(7,4,2006), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001729', 3, 2004, 'C-A1', EXTEND(MDY(9,29,2005), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001729', 9, 2004, 'C-A1', EXTEND(MDY(2,4,2005), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001729', 10, 2004, 'C-A1', EXTEND(MDY(2,10,2005), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001729', 11, 2004, 'C-A1', EXTEND(MDY(6,21,2005), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001729', 12, 2004, 'C-A1', EXTEND(MDY(6,21,2005), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001729', 13, 2005, 'D-A3', EXTEND(MDY(2,1,2006), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001729', 14, 2005, 'D-A3', EXTEND(MDY(6,16,2006), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001729', 15, 2005, 'D-A3', EXTEND(MDY(6,13,2006), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001729', 17, 2005, 'D-A3', EXTEND(MDY(9,18,2006), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001729', 26, 2005, 'D-A3', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001729', 27, 2005, 'D-A3', EXTEND(MDY(6,20,2006), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001729', 28, 2004, 'C-A1', EXTEND(MDY(2,7,2005), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001729', 29, 2005, 'D-A3', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001760', 1, 2005, 'D-A4', EXTEND(MDY(9,26,2006), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001760', 3, 2004, 'C-A1', EXTEND(MDY(6,14,2005), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001760', 9, 2004, 'C-A1', EXTEND(MDY(6,23,2005), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001760', 10, 2004, 'C-A1', EXTEND(MDY(2,9,2006), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001760', 11, 2004, 'C-A1', EXTEND(MDY(6,21,2005), YEAR to SECOND), 1);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001760', 11, 2005, 'A-A', EXTEND(MDY(6,21,2006), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001760', 12, 2004, 'C-A1', EXTEND(MDY(7,5,2005), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001760', 13, 2005, 'D-A4', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001760', 14, 2005, 'D-A4', EXTEND(MDY(9,25,2006), YEAR to SECOND), 1);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001760', 15, 2005, 'D-A4', EXTEND(MDY(2,20,2006), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001760', 17, 2005, 'D-A4', EXTEND(MDY(1,30,2006), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001760', 26, 2005, 'D-A4', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001760', 27, 2005, 'D-A4', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001760', 28, 2004, 'C-A1', EXTEND(MDY(6,27,2005), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001760', 29, 2005, 'D-A4', EXTEND(MDY(9,4,2006), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001776', 2, 2005, 'C-B3', EXTEND(MDY(2,13,2006), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001776', 6, 2005, 'C-B3', EXTEND(MDY(6,27,2006), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001776', 8, 2005, 'C-B3', EXTEND(MDY(9,20,2006), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001776', 9, 2005, 'C-B3', EXTEND(MDY(2,3,2006), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001776', 12, 2005, 'C-B3', EXTEND(MDY(6,20,2006), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001776', 18, 2006, 'D-B1', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001776', 19, 2006, 'D-B1', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001776', 20, 2006, 'D-B1', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001776', 25, 2006, 'D-B1', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001804', 1, 2005, 'D-A1', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001804', 2, 2004, 'C-A4', EXTEND(MDY(1,31,2005), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001804', 3, 2004, 'C-A4', EXTEND(MDY(6,14,2005), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001804', 9, 2004, 'C-A4', EXTEND(MDY(7,12,2005), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001804', 10, 2004, 'C-A4', EXTEND(MDY(2,10,2005), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001804', 11, 2004, 'C-A4', EXTEND(MDY(6,21,2005), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001804', 12, 2004, 'C-A4', EXTEND(MDY(6,21,2005), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001804', 13, 2005, 'D-A1', EXTEND(MDY(2,1,2006), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001804', 14, 2005, 'D-A1', EXTEND(MDY(6,16,2006), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001804', 15, 2005, 'D-A1', EXTEND(MDY(2,20,2006), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001804', 17, 2005, 'D-A1', EXTEND(MDY(7,11,2006), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001804', 26, 2005, 'D-A1', EXTEND(MDY(7,11,2006), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001804', 27, 2005, 'D-A1', EXTEND(MDY(6,20,2006), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001804', 28, 2004, 'C-A4', EXTEND(MDY(2,7,2005), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001804', 29, 2005, 'D-A1', EXTEND(MDY(6,12,2006), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001825', 3, 2005, 'C-A4', EXTEND(MDY(6,13,2006), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001825', 9, 2005, 'C-A4', EXTEND(MDY(2,3,2006), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001825', 11, 2005, 'C-A4', EXTEND(MDY(7,4,2006), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001825', 12, 2005, 'C-A4', EXTEND(MDY(6,20,2006), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001825', 13, 2006, 'D-A4', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001825', 15, 2006, 'D-A4', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001825', 17, 2006, 'D-A4', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001825', 26, 2006, 'D-A4', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001825', 28, 2005, 'C-A4', EXTEND(MDY(2,6,2006), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001830', 3, 2005, 'C-A3', EXTEND(MDY(6,30,2006), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001830', 9, 2005, 'C-A3', EXTEND(MDY(7,11,2006), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001830', 10, 2005, 'C-A3', EXTEND(MDY(2,9,2006), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001830', 11, 2005, 'C-A3', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001830', 12, 2005, 'C-A3', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001872', 32, 2006, 'A-L', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001872', 34, 2006, 'A-M', EXTEND(MDY(2,1,2007), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001872', 42, 2006, 'B-K', EXTEND(MDY(2,1,2007), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001872', 44, 2006, 'B-K', EXTEND(MDY(2,1,2007), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001888', 3, 2005, 'C-A2', EXTEND(MDY(6,13,2006), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001888', 9, 2005, 'C-A2', EXTEND(MDY(2,3,2006), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001888', 10, 2005, 'C-A2', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001888', 11, 2005, 'C-A2', EXTEND(MDY(6,21,2006), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001888', 12, 2005, 'C-A2', EXTEND(MDY(6,20,2006), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001888', 13, 2006, 'D-A4', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001888', 15, 2006, 'D-A4', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001888', 17, 2006, 'D-A4', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001888', 26, 2006, 'D-A4', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001888', 28, 2005, 'C-A2', EXTEND(MDY(2,6,2006), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001893', 3, 2005, 'C-A2', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001893', 9, 2005, 'C-A2', EXTEND(MDY(2,14,2006), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001893', 11, 2005, 'C-A2', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001893', 12, 2005, 'C-A2', EXTEND(MDY(7,4,2006), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001893', 28, 2005, 'C-A2', EXTEND(MDY(2,6,2006), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001900', 3, 2004, 'C-A3', EXTEND(MDY(6,14,2005), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001900', 9, 2004, 'C-A3', EXTEND(MDY(2,15,2005), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001900', 10, 2004, 'C-A3', EXTEND(MDY(2,10,2005), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001900', 11, 2004, 'C-A3', EXTEND(MDY(6,21,2005), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001900', 12, 2004, 'C-A3', EXTEND(MDY(6,21,2005), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001900', 15, 2006, 'D-A5', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001900', 17, 2006, 'D-A5', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001900', 26, 2006, 'D-A5', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001900', 28, 2004, 'C-A3', EXTEND(MDY(2,7,2005), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001921', 2, 2005, 'C-B1', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001921', 4, 2005, 'C-B1', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001921', 5, 2005, 'C-B1', EXTEND(MDY(2,6,2006), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001921', 6, 2005, 'C-B1', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001921', 7, 2005, 'C-B1', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001921', 8, 2005, 'C-B1', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001921', 12, 2005, 'C-B1', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001937', 1, 2005, 'A-A', EXTEND(MDY(11,7,2006), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001958', 1, 2005, 'A-A', EXTEND(MDY(6,13,2006), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001979', 31, 2005, 'A-H', EXTEND(MDY(1,30,2006), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001979', 32, 2005, 'A-H', EXTEND(MDY(2,2,2006), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001979', 33, 2005, 'A-H', EXTEND(MDY(1,31,2006), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001979', 34, 2005, 'A-H', EXTEND(MDY(2,3,2006), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001979', 35, 2005, 'A-H', EXTEND(MDY(6,28,2006), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001979', 37, 2005, 'A-H', EXTEND(MDY(6,27,2006), YEAR to SECOND), 1);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001979', 38, 2005, 'A-H', EXTEND(MDY(6,29,2006), YEAR to SECOND), 1);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001979', 39, 2005, 'A-H', EXTEND(MDY(6,30,2006), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001979', 40, 2006, 'B-C', EXTEND(MDY(2,1,2007), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001979', 41, 2006, 'B-C', EXTEND(MDY(2,1,2007), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001979', 42, 2006, 'B-C', EXTEND(MDY(2,1,2007), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001979', 43, 2006, 'B-C', EXTEND(MDY(2,1,2007), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001979', 44, 2006, 'B-C', EXTEND(MDY(2,1,2007), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555001984', 1, 2005, 'A-A', EXTEND(MDY(7,4,2006), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555002000', 1, 2005, 'A-A', EXTEND(MDY(6,13,2006), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555002016', 3, 2004, 'C-A2', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555002016', 9, 2004, 'C-A2', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555002016', 10, 2004, 'C-A2', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555002016', 11, 2004, 'C-A2', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555002016', 11, 2005, 'A-A', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555002016', 12, 2004, 'C-A2', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555002016', 12, 2005, 'A-A', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555002016', 28, 2004, 'C-A2', EXTEND(MDY(2,6,2006), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555002021', 1, 2005, 'A-A', EXTEND(MDY(7,4,2006), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555002037', 2, 2005, 'C-B5', EXTEND(MDY(2,13,2006), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555002037', 4, 2005, 'C-B5', EXTEND(MDY(2,16,2006), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555002037', 5, 2005, 'C-B5', EXTEND(MDY(2,6,2006), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555002037', 6, 2005, 'C-B5', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555002037', 7, 2005, 'C-B5', EXTEND(MDY(7,11,2006), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555002037', 8, 2005, 'C-B5', EXTEND(MDY(7,3,2006), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555002037', 9, 2005, 'C-B5', EXTEND(MDY(9,18,2006), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555002037', 12, 2005, 'C-B5', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555002037', 18, 2006, 'D-B4', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555002037', 19, 2006, 'D-B4', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555002037', 20, 2006, 'D-B4', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555002037', 25, 2006, 'D-B4', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555002042', 28, 2006, 'C-A3', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555002063', 32, 2006, 'A-L', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555002063', 33, 2006, 'A-K', EXTEND(MDY(2,1,2007), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555002063', 34, 2006, 'A-L', EXTEND(MDY(2,1,2007), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555002063', 40, 2006, 'B-E', EXTEND(MDY(2,1,2007), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555002063', 42, 2006, 'B-E', EXTEND(MDY(2,1,2007), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555002063', 43, 2006, 'B-E', EXTEND(MDY(2,1,2007), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555002063', 44, 2006, 'B-E', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555002084', 3, 2005, 'C-A2', EXTEND(MDY(6,13,2006), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555002084', 9, 2005, 'C-A2', EXTEND(MDY(2,14,2006), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555002084', 10, 2005, 'C-A2', EXTEND(MDY(2,9,2006), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555002084', 11, 2005, 'C-A2', EXTEND(MDY(6,21,2006), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555002084', 12, 2005, 'C-A2', EXTEND(MDY(6,20,2006), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555002084', 13, 2006, 'D-A5', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555002084', 15, 2006, 'D-A5', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555002084', 17, 2006, 'D-A5', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555002084', 26, 2006, 'D-A5', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555002084', 28, 2005, 'C-A2', EXTEND(MDY(2,6,2006), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555002107', 32, 2006, 'A-L', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555002107', 33, 2006, 'A-K', EXTEND(MDY(2,1,2007), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555002107', 34, 2006, 'A-M', EXTEND(MDY(2,1,2007), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555002107', 42, 2006, 'B-E', EXTEND(MDY(2,1,2007), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555002107', 43, 2006, 'B-E', EXTEND(MDY(2,1,2007), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555002107', 44, 2006, 'B-E', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555002128', 3, 2005, 'C-A1', EXTEND(MDY(7,13,2006), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555002128', 9, 2005, 'C-A1', EXTEND(MDY(2,3,2006), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555002128', 10, 2005, 'C-A1', EXTEND(MDY(2,9,2006), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555002128', 11, 2005, 'C-A1', EXTEND(MDY(6,21,2006), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555002128', 12, 2005, 'C-A1', EXTEND(MDY(6,20,2006), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555002128', 13, 2006, 'D-A5', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555002128', 15, 2006, 'D-A5', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555002128', 17, 2006, 'D-A5', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555002128', 26, 2006, 'D-A5', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555002128', 28, 2005, 'C-A1', EXTEND(MDY(2,6,2006), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555002149', 3, 2005, 'C-A2', EXTEND(MDY(6,13,2006), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555002149', 9, 2005, 'C-A2', EXTEND(MDY(2,3,2006), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555002149', 10, 2005, 'C-A2', EXTEND(MDY(2,9,2006), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555002149', 11, 2005, 'C-A2', EXTEND(MDY(6,21,2006), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555002149', 12, 2005, 'C-A2', EXTEND(MDY(6,20,2006), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555002149', 28, 2005, 'C-A2', EXTEND(MDY(2,6,2006), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555002154', 2, 2005, 'C-B4', EXTEND(MDY(1,30,2006), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555002154', 4, 2005, 'C-B4', EXTEND(MDY(1,31,2006), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555002154', 5, 2005, 'C-B4', EXTEND(MDY(2,6,2006), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555002154', 6, 2005, 'C-B4', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555002154', 7, 2005, 'C-B4', EXTEND(MDY(6,20,2006), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555002154', 8, 2005, 'C-B4', EXTEND(MDY(6,12,2006), YEAR to SECOND), 0);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555002154', 9, 2005, 'C-B4', EXTEND(MDY(2,3,2006), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555002154', 12, 2005, 'C-B4', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555002154', 18, 2006, 'D-B4', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555002154', 19, 2006, 'D-B4', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555002154', 20, 2006, 'D-B4', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555002154', 25, 2006, 'D-B4', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555002175', 9, 2006, 'C-A4', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555002175', 10, 2006, 'C-A4', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555002175', 28, 2006, 'C-A4', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555002180', 34, 2006, 'A-L', EXTEND(MDY(2,1,2007), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555002180', 40, 2006, 'B-E', EXTEND(MDY(2,1,2007), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555002180', 42, 2006, 'B-E', EXTEND(MDY(2,1,2007), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555002180', 43, 2006, 'B-E', EXTEND(MDY(2,1,2007), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555002180', 44, 2006, 'B-E', EXTEND(MDY(2,1,2007), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555002196', 2, 2005, 'C-B3', EXTEND(MDY(2,13,2006), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555002196', 4, 2005, 'C-B3', EXTEND(MDY(4,4,2006), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555002196', 5, 2005, 'C-B3', EXTEND(MDY(2,6,2006), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555002196', 6, 2005, 'C-B3', EXTEND(MDY(6,27,2006), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555002196', 7, 2005, 'C-B3', EXTEND(MDY(6,13,2006), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555002196', 8, 2005, 'C-B3', EXTEND(MDY(6,12,2006), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555002196', 9, 2005, 'C-B3', EXTEND(MDY(2,14,2006), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555002196', 12, 2005, 'C-B3', EXTEND(MDY(6,20,2006), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555002196', 18, 2006, 'D-B1', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555002196', 19, 2006, 'D-B1', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555002196', 20, 2006, 'D-B1', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555002196', 25, 2006, 'D-B1', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555002203', 30, 2005, 'A-L', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555002203', 31, 2005, 'A-L', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555002203', 32, 2005, 'A-L', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555002203', 33, 2005, 'A-L', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555002203', 34, 2005, 'A-L', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555002224', 3, 2005, 'C-A3', EXTEND(MDY(6,13,2006), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555002224', 9, 2005, 'C-A3', EXTEND(MDY(2,3,2006), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555002224', 10, 2005, 'C-A3', EXTEND(MDY(2,9,2006), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555002224', 11, 2005, 'C-A3', EXTEND(MDY(6,21,2006), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555002224', 12, 2005, 'C-A3', EXTEND(MDY(6,20,2006), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555002224', 13, 2006, 'D-A5', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555002224', 15, 2006, 'D-A5', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555002224', 17, 2006, 'D-A5', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555002224', 26, 2006, 'D-A5', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555002224', 28, 2005, 'C-A3', EXTEND(MDY(2,6,2006), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555002245', 2, 2006, 'C-B2', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555002245', 4, 2006, 'C-B2', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555002245', 5, 2006, 'C-B2', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555002245', 9, 2006, 'C-B2', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555002250', 2, 2006, 'C-B3', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555002250', 4, 2006, 'C-B3', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555002250', 5, 2006, 'C-B3', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555002250', 9, 2006, 'C-B3', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555002266', 32, 2005, 'A-J', EXTEND(MDY(2,2,2006), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555002266', 33, 2005, 'A-J', EXTEND(MDY(1,31,2006), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555002266', 34, 2005, 'A-J', EXTEND(MDY(2,3,2006), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555002266', 35, 2005, 'A-G', EXTEND(MDY(6,28,2006), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555002266', 36, 2005, 'A-G', EXTEND(MDY(6,26,2006), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555002266', 37, 2005, 'A-G', EXTEND(MDY(6,27,2006), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555002266', 38, 2005, 'A-G', EXTEND(MDY(6,29,2006), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555002266', 39, 2005, 'A-G', EXTEND(MDY(6,30,2006), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555002266', 41, 2006, 'B-I', EXTEND(MDY(2,1,2007), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555002266', 42, 2006, 'B-I', EXTEND(MDY(2,1,2007), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555002266', 44, 2006, 'B-I', EXTEND(MDY(2,1,2007), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555002266', 45, 2006, 'B-I', EXTEND(MDY(2,1,2007), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555002266', 46, 2006, 'B-I', EXTEND(MDY(2,1,2007), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555002271', 2, 2005, 'C-B3', EXTEND(MDY(2,13,2006), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555002271', 4, 2005, 'C-B3', EXTEND(MDY(1,31,2006), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555002271', 5, 2005, 'C-B3', EXTEND(MDY(2,6,2006), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555002271', 6, 2005, 'C-B3', EXTEND(MDY(6,14,2006), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555002271', 7, 2005, 'C-B3', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555002271', 8, 2005, 'C-B3', EXTEND(MDY(6,12,2006), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555002271', 9, 2005, 'C-B3', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555002271', 12, 2005, 'C-B3', EXTEND(MDY(6,20,2006), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555002271', 18, 2006, 'D-B4', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555002271', 19, 2006, 'D-B4', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555002271', 20, 2006, 'D-B4', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555002271', 25, 2006, 'D-B4', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555002287', 32, 2006, 'A-L', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555002287', 34, 2006, 'A-M', EXTEND(MDY(2,1,2007), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555002287', 42, 2006, 'B-K', EXTEND(MDY(2,1,2007), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555002287', 44, 2006, 'B-K', EXTEND(MDY(2,1,2007), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555002287', 45, 2006, 'B-K', EXTEND(MDY(2,1,2007), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555002320', 32, 2006, 'A-K', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555002320', 34, 2006, 'A-L', EXTEND(MDY(2,1,2007), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555002320', 42, 2006, 'B-E', EXTEND(MDY(2,1,2007), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555002320', 44, 2006, 'B-E', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555002378', 32, 2005, 'A-H', EXTEND(MDY(2,2,2006), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555002378', 33, 2005, 'A-H', EXTEND(MDY(1,31,2006), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555002378', 34, 2005, 'A-H', EXTEND(MDY(2,3,2006), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555002378', 35, 2005, 'A-F', EXTEND(MDY(6,28,2006), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555002378', 37, 2005, 'A-F', EXTEND(MDY(6,27,2006), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555002378', 38, 2005, 'A-F', EXTEND(MDY(6,29,2006), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555002378', 39, 2005, 'A-F', EXTEND(MDY(6,30,2006), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555002378', 42, 2006, 'B-H', EXTEND(MDY(2,1,2007), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555002378', 44, 2006, 'B-H', EXTEND(MDY(2,1,2007), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555002378', 45, 2006, 'B-H', EXTEND(MDY(2,1,2007), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555002378', 46, 2006, 'B-H', EXTEND(MDY(2,1,2007), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555002383', 31, 2005, 'A-J', EXTEND(MDY(2,1,2007), YEAR to SECOND), 1);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555002383', 31, 2006, 'A-K', EXTEND(MDY(2,1,2007), YEAR to SECOND), 1);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555002383', 32, 2005, 'A-H', EXTEND(MDY(2,2,2006), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555002383', 34, 2005, 'A-J', EXTEND(MDY(2,3,2006), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555002383', 35, 2005, 'A-J', EXTEND(MDY(6,28,2006), YEAR to SECOND), 1);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555002383', 37, 2005, 'A-J', EXTEND(MDY(6,27,2006), YEAR to SECOND), 1);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555002383', 38, 2005, 'A-H', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555002383', 39, 2005, 'A-J', EXTEND(MDY(6,30,2006), YEAR to SECOND), 1);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555002383', 44, 2006, 'B-A', EXTEND(MDY(2,1,2007), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555002399', 2, 2005, 'C-B5', EXTEND(MDY(2,13,2006), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555002399', 4, 2005, 'C-B5', EXTEND(MDY(1,31,2006), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555002399', 5, 2005, 'C-B5', EXTEND(MDY(2,6,2006), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555002399', 6, 2005, 'C-B5', EXTEND(MDY(6,14,2006), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555002399', 7, 2005, 'C-B5', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555002399', 8, 2005, 'C-B5', EXTEND(MDY(6,12,2006), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555002399', 9, 2005, 'C-B5', EXTEND(MDY(2,3,2006), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555002399', 12, 2005, 'C-B5', EXTEND(MDY(6,20,2006), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555002399', 18, 2006, 'D-B1', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555002399', 19, 2006, 'D-B1', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555002399', 20, 2006, 'D-B1', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555002399', 25, 2006, 'D-B1', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555002406', 3, 2005, 'C-A3', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555002406', 9, 2005, 'C-A3', EXTEND(MDY(2,3,2006), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555002406', 10, 2005, 'C-A3', EXTEND(MDY(2,9,2006), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555002406', 11, 2005, 'C-A3', EXTEND(MDY(6,21,2006), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555002406', 12, 2005, 'C-A3', EXTEND(MDY(6,20,2006), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555002406', 13, 2006, 'D-A3', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555002406', 15, 2006, 'D-A3', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555002406', 17, 2006, 'D-A3', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555002406', 26, 2006, 'D-A3', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555002406', 28, 2005, 'C-A3', EXTEND(MDY(2,6,2006), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555002427', 32, 2005, 'A-J', EXTEND(MDY(2,2,2006), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555002427', 33, 2005, 'A-J', EXTEND(MDY(1,31,2006), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555002427', 34, 2005, 'A-J', EXTEND(MDY(2,3,2006), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555002427', 35, 2005, 'A-F', EXTEND(MDY(6,28,2006), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555002427', 37, 2005, 'A-F', EXTEND(MDY(6,27,2006), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555002427', 38, 2005, 'A-F', EXTEND(MDY(6,29,2006), YEAR to SECOND), 1);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555002427', 39, 2005, 'A-F', EXTEND(MDY(6,30,2006), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555002427', 40, 2006, 'B-B', EXTEND(MDY(2,1,2007), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555002427', 42, 2006, 'B-B', EXTEND(MDY(2,1,2007), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555002427', 43, 2006, 'B-B', EXTEND(MDY(2,1,2007), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555002427', 44, 2006, 'B-B', EXTEND(MDY(2,1,2007), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555002432', 3, 2005, 'C-A3', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555002432', 9, 2005, 'C-A3', EXTEND(MDY(2,3,2006), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555002432', 10, 2005, 'C-A3', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555002432', 11, 2005, 'C-A3', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555002432', 12, 2005, 'C-A3', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555002432', 28, 2005, 'C-A3', EXTEND(MDY(2,20,2006), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555002469', 3, 2005, 'C-A2', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555002469', 9, 2005, 'C-A2', EXTEND(MDY(6,21,2006), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555002469', 10, 2005, 'C-A2', EXTEND(MDY(2,9,2006), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555002469', 11, 2005, 'C-A2', EXTEND(MDY(6,21,2006), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555002469', 12, 2005, 'C-A2', EXTEND(MDY(6,20,2006), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555002469', 13, 2006, 'D-A5', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555002469', 15, 2006, 'D-A5', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555002469', 17, 2006, 'D-A5', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555002469', 26, 2006, 'D-A5', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555002469', 28, 2005, 'C-A2', EXTEND(MDY(2,6,2006), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555002474', 31, 2005, 'A-H', EXTEND(MDY(1,30,2006), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555002474', 32, 2005, 'A-H', EXTEND(MDY(2,2,2006), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555002474', 34, 2005, 'A-H', EXTEND(MDY(2,3,2006), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555002474', 35, 2005, 'A-G', EXTEND(MDY(6,28,2006), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555002474', 36, 2005, 'A-G', EXTEND(MDY(6,26,2006), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555002474', 37, 2005, 'A-G', EXTEND(MDY(6,27,2006), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555002474', 38, 2005, 'A-G', EXTEND(MDY(6,29,2006), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555002474', 39, 2005, 'A-G', EXTEND(MDY(6,30,2006), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555002474', 40, 2006, 'B-C', EXTEND(MDY(2,1,2007), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555002474', 41, 2006, 'B-C', EXTEND(MDY(2,1,2007), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555002474', 42, 2006, 'B-C', EXTEND(MDY(2,1,2007), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555002474', 43, 2006, 'B-C', EXTEND(MDY(2,1,2007), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555002474', 44, 2006, 'B-C', EXTEND(MDY(2,1,2007), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555002495', 3, 2005, 'C-A5', EXTEND(MDY(6,13,2006), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555002495', 9, 2005, 'C-A5', EXTEND(MDY(4,5,2006), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555002495', 10, 2005, 'C-A5', EXTEND(MDY(2,9,2006), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555002495', 11, 2005, 'C-A5', EXTEND(MDY(6,21,2006), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555002495', 12, 2005, 'C-A5', EXTEND(MDY(6,20,2006), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555002495', 13, 2006, 'D-A2', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555002495', 15, 2006, 'D-A2', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555002495', 17, 2006, 'D-A2', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555002495', 26, 2006, 'D-A2', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555002495', 28, 2005, 'C-A5', EXTEND(MDY(6,26,2006), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555002502', 3, 2005, 'C-A4', EXTEND(MDY(9,4,2006), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555002502', 9, 2005, 'C-A4', EXTEND(MDY(7,5,2006), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555002502', 10, 2005, 'C-A4', EXTEND(MDY(2,9,2006), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555002502', 11, 2005, 'C-A4', EXTEND(MDY(6,21,2006), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555002502', 12, 2005, 'C-A4', EXTEND(MDY(7,4,2006), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555002502', 13, 2006, 'D-A2', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555002502', 15, 2006, 'D-A2', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555002502', 17, 2006, 'D-A2', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555002502', 26, 2006, 'D-A2', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555002502', 28, 2005, 'C-A4', EXTEND(MDY(2,6,2006), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555002518', 3, 2005, 'C-A2', EXTEND(MDY(9,28,2006), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555002518', 9, 2005, 'C-A2', EXTEND(MDY(2,14,2006), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555002518', 10, 2005, 'C-A2', EXTEND(MDY(2,9,2006), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555002518', 11, 2005, 'C-A2', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555002518', 12, 2005, 'C-A2', EXTEND(MDY(6,20,2006), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555002518', 28, 2005, 'C-A2', EXTEND(MDY(2,6,2006), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555002539', 2, 2005, 'C-B1', EXTEND(MDY(1,30,2006), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555002539', 4, 2005, 'C-B1', EXTEND(MDY(2,16,2006), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555002539', 5, 2005, 'C-B1', EXTEND(MDY(2,6,2006), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555002539', 6, 2005, 'C-B1', EXTEND(MDY(6,27,2006), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555002539', 7, 2005, 'C-B1', EXTEND(MDY(6,13,2006), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555002539', 8, 2005, 'C-B1', EXTEND(MDY(7,3,2006), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555002539', 9, 2005, 'C-B1', EXTEND(MDY(2,3,2006), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555002539', 12, 2005, 'C-B1', EXTEND(MDY(6,20,2006), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555002539', 18, 2006, 'D-B4', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555002539', 19, 2006, 'D-B4', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555002539', 20, 2006, 'D-B4', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555002539', 25, 2006, 'D-B4', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555002544', 4, 2006, 'C-B4', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555002544', 5, 2006, 'C-B4', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555002544', 9, 2006, 'C-B4', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555002570', 9, 2006, 'C-A5', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555002570', 10, 2006, 'C-A5', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555002570', 28, 2006, 'C-A5', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555002586', 3, 2005, 'C-A3', EXTEND(MDY(6,30,2006), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555002586', 9, 2005, 'C-A3', EXTEND(MDY(2,14,2006), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555002586', 10, 2005, 'C-A3', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555002586', 11, 2005, 'C-A3', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555002586', 12, 2005, 'C-A3', EXTEND(MDY(6,20,2006), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555002586', 28, 2005, 'C-A3', EXTEND(MDY(2,6,2006), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555002640', 9, 2006, 'C-A3', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555002640', 10, 2006, 'C-A3', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555002640', 28, 2006, 'C-A3', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555002656', 32, 2006, 'A-L', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555002656', 34, 2006, 'A-M', EXTEND(MDY(2,1,2007), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555002656', 42, 2006, 'B-K', EXTEND(MDY(2,1,2007), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555002656', 44, 2006, 'B-K', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555002656', 45, 2006, 'B-K', EXTEND(MDY(2,1,2007), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555002677', 2, 2006, 'C-B3', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555002677', 4, 2006, 'C-B3', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555002677', 5, 2006, 'C-B3', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555002677', 9, 2006, 'C-B3', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555002682', 34, 2006, 'A-M', EXTEND(MDY(2,1,2007), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555002682', 40, 2006, 'B-E', EXTEND(MDY(2,1,2007), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555002682', 42, 2006, 'B-E', EXTEND(MDY(2,1,2007), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555002682', 43, 2006, 'B-E', EXTEND(MDY(2,1,2007), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555002682', 44, 2006, 'B-G', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555002698', 9, 2006, 'C-A3', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555002698', 10, 2006, 'C-A3', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555002698', 28, 2006, 'C-A3', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555002705', 2, 2006, 'C-B5', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555002705', 4, 2006, 'C-B5', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555002705', 5, 2006, 'C-B5', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555002705', 9, 2006, 'C-B5', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555002710', 9, 2006, 'C-A1', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555002710', 10, 2006, 'C-A1', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555002710', 28, 2006, 'C-A3', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555002726', 9, 2006, 'C-A3', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555002726', 10, 2006, 'C-A3', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555002726', 28, 2006, 'C-A3', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555002731', 34, 2006, 'A-M', EXTEND(MDY(2,1,2007), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555002731', 42, 2006, 'B-K', EXTEND(MDY(2,1,2007), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555002731', 44, 2006, 'B-K', EXTEND(MDY(2,1,2007), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555002731', 45, 2006, 'B-K', EXTEND(MDY(2,1,2007), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555002731', 46, 2006, 'B-K', EXTEND(MDY(2,1,2007), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555002747', 34, 2006, 'A-K', EXTEND(MDY(2,1,2007), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555002747', 42, 2006, 'B-K', EXTEND(MDY(2,1,2007), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555002747', 44, 2006, 'B-K', EXTEND(MDY(2,1,2007), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555002747', 45, 2006, 'B-K', EXTEND(MDY(2,1,2007), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555002747', 46, 2006, 'B-K', EXTEND(MDY(2,1,2007), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555002752', 9, 2006, 'C-A5', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555002752', 10, 2006, 'C-A5', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555002752', 28, 2006, 'C-A5', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555002768', 34, 2006, 'A-L', EXTEND(MDY(2,1,2007), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555002768', 40, 2006, 'B-E', EXTEND(MDY(2,1,2007), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555002768', 42, 2006, 'B-E', EXTEND(MDY(2,1,2007), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555002768', 43, 2006, 'B-E', EXTEND(MDY(2,1,2007), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555002768', 44, 2006, 'B-E', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555002773', 2, 2006, 'C-B5', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555002773', 4, 2006, 'C-B5', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555002773', 5, 2006, 'C-B5', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555002773', 9, 2006, 'C-B5', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555002789', 33, 2006, 'A-K', EXTEND(MDY(2,1,2007), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555002789', 34, 2006, 'A-M', EXTEND(MDY(2,1,2007), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555002789', 42, 2006, 'B-E', EXTEND(MDY(2,1,2007), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555002789', 43, 2006, 'B-E', EXTEND(MDY(2,1,2007), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555002789', 44, 2006, 'B-E', EXTEND(MDY(2,1,2007), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555002794', 32, 2006, 'A-L', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555002794', 33, 2006, 'A-K', EXTEND(MDY(2,1,2007), YEAR to SECOND), 1);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555002794', 34, 2006, 'A-K', EXTEND(MDY(2,1,2007), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555002794', 40, 2006, 'B-E', EXTEND(MDY(2,1,2007), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555002794', 42, 2006, 'B-E', EXTEND(MDY(2,1,2007), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555002794', 43, 2006, 'B-E', EXTEND(MDY(2,1,2007), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555002794', 44, 2006, 'B-E', EXTEND(MDY(2,1,2007), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555002801', 2, 2006, 'C-B1', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555002801', 4, 2006, 'C-B1', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555002801', 5, 2006, 'C-B1', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555002801', 9, 2006, 'C-B1', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555002822', 2, 2006, 'C-B3', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555002822', 4, 2006, 'C-B3', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555002822', 5, 2006, 'C-B3', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555002822', 9, 2006, 'C-B3', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555002838', 2, 2006, 'C-B1', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555002838', 4, 2006, 'C-B1', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555002838', 5, 2006, 'C-B1', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555002838', 9, 2006, 'C-B1', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555002859', 30, 2005, 'A-L', EXTEND(MDY(2,1,2006), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555002859', 31, 2005, 'A-L', EXTEND(MDY(1,30,2006), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555002859', 32, 2005, 'A-L', EXTEND(MDY(2,2,2006), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555002859', 33, 2005, 'A-L', EXTEND(MDY(1,31,2006), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555002859', 34, 2005, 'A-L', EXTEND(MDY(2,3,2006), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555002859', 35, 2005, 'A-F', EXTEND(MDY(6,28,2006), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555002859', 36, 2005, 'A-F', EXTEND(MDY(6,26,2006), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555002859', 37, 2005, 'A-F', EXTEND(MDY(6,27,2006), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555002859', 38, 2005, 'A-F', EXTEND(MDY(6,29,2006), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555002859', 39, 2005, 'A-F', EXTEND(MDY(6,30,2006), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555002859', 41, 2006, 'B-H', EXTEND(MDY(2,1,2007), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555002859', 42, 2006, 'B-H', EXTEND(MDY(2,1,2007), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555002859', 44, 2006, 'B-H', EXTEND(MDY(2,1,2007), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555002859', 45, 2006, 'B-H', EXTEND(MDY(2,1,2007), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555002859', 46, 2006, 'B-H', EXTEND(MDY(2,1,2007), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555002864', 30, 2005, 'A-L', EXTEND(MDY(2,1,2006), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555002864', 31, 2005, 'A-L', EXTEND(MDY(1,30,2006), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555002864', 32, 2005, 'A-L', EXTEND(MDY(2,2,2006), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555002864', 33, 2005, 'A-L', EXTEND(MDY(1,31,2006), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555002864', 34, 2005, 'A-L', EXTEND(MDY(2,3,2006), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555002864', 35, 2005, 'A-F', EXTEND(MDY(6,28,2006), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555002864', 36, 2005, 'A-F', EXTEND(MDY(6,26,2006), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555002864', 37, 2005, 'A-F', EXTEND(MDY(6,27,2006), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555002864', 38, 2005, 'A-F', EXTEND(MDY(6,29,2006), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555002864', 39, 2005, 'A-F', EXTEND(MDY(6,30,2006), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555002864', 41, 2006, 'B-H', EXTEND(MDY(2,1,2007), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555002864', 42, 2006, 'B-H', EXTEND(MDY(2,1,2007), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555002864', 44, 2006, 'B-H', EXTEND(MDY(2,1,2007), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555002864', 45, 2006, 'B-H', EXTEND(MDY(2,1,2007), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555002864', 46, 2006, 'B-H', EXTEND(MDY(2,1,2007), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555002885', 9, 2006, 'C-A2', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555002885', 10, 2006, 'C-A2', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555002885', 28, 2006, 'C-A2', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555002890', 32, 2005, 'A-H', EXTEND(MDY(2,2,2006), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555002890', 33, 2005, 'A-H', EXTEND(MDY(1,31,2006), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555002890', 34, 2005, 'A-H', EXTEND(MDY(2,3,2006), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555002890', 37, 2005, 'A-H', EXTEND(MDY(6,27,2006), YEAR to SECOND), 1);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555002890', 38, 2005, 'A-H', EXTEND(MDY(6,29,2006), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555002890', 39, 2005, 'A-H', EXTEND(MDY(6,30,2006), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555002890', 40, 2006, 'B-C', EXTEND(MDY(2,1,2007), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555002890', 42, 2006, 'B-C', EXTEND(MDY(2,1,2007), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555002890', 43, 2006, 'B-C', EXTEND(MDY(2,1,2007), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555002890', 44, 2006, 'B-C', EXTEND(MDY(2,1,2007), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555002908', 9, 2006, 'C-A5', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555002908', 10, 2006, 'C-A5', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555002908', 28, 2006, 'C-A5', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555002913', 32, 2005, 'A-H', EXTEND(MDY(2,2,2006), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555002913', 33, 2005, 'A-J', EXTEND(MDY(1,31,2006), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555002913', 34, 2005, 'A-J', EXTEND(MDY(2,3,2006), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555002913', 35, 2005, 'A-F', EXTEND(MDY(6,28,2006), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555002913', 37, 2005, 'A-F', EXTEND(MDY(6,27,2006), YEAR to SECOND), 1);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555002913', 38, 2005, 'A-F', EXTEND(MDY(6,29,2006), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555002913', 39, 2005, 'A-F', EXTEND(MDY(6,30,2006), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555002913', 40, 2006, 'B-B', EXTEND(MDY(2,1,2007), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555002913', 42, 2006, 'B-B', EXTEND(MDY(2,1,2007), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555002913', 43, 2006, 'B-B', EXTEND(MDY(2,1,2007), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555002913', 44, 2006, 'B-B', EXTEND(MDY(2,1,2007), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555002934', 9, 2006, 'C-A5', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555002934', 10, 2006, 'C-A5', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555002934', 28, 2006, 'C-A5', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555002955', 2, 2006, 'C-B2', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555002955', 4, 2006, 'C-B2', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555002955', 5, 2006, 'C-B2', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555002955', 9, 2006, 'C-B2', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555002960', 2, 2006, 'C-B5', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555002960', 4, 2006, 'C-B5', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555002960', 5, 2006, 'C-B5', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555002960', 9, 2006, 'C-B5', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555002960', 28, 2006, 'C-A1', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555002976', 31, 2005, 'A-H', EXTEND(MDY(1,30,2006), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555002976', 32, 2005, 'A-H', EXTEND(MDY(2,2,2006), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555002976', 33, 2005, 'A-H', EXTEND(MDY(1,31,2006), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555002976', 34, 2005, 'A-H', EXTEND(MDY(2,3,2006), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555002976', 35, 2005, 'A-H', EXTEND(MDY(6,28,2006), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555002976', 37, 2005, 'A-H', EXTEND(MDY(6,27,2006), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555002976', 38, 2005, 'A-H', EXTEND(MDY(6,29,2006), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555002976', 39, 2005, 'A-H', EXTEND(MDY(6,30,2006), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555002976', 41, 2006, 'B-I', EXTEND(MDY(2,1,2007), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555002976', 42, 2006, 'B-I', EXTEND(MDY(2,1,2007), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555002976', 44, 2006, 'B-I', EXTEND(MDY(2,1,2007), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555002976', 45, 2006, 'B-I', EXTEND(MDY(2,1,2007), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555002976', 46, 2006, 'B-I', EXTEND(MDY(2,1,2007), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555002981', 32, 2005, 'A-H', EXTEND(MDY(2,2,2006), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555002981', 34, 2005, 'A-H', EXTEND(MDY(2,3,2006), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555002981', 35, 2005, 'A-H', EXTEND(MDY(6,28,2006), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555002981', 37, 2005, 'A-H', EXTEND(MDY(6,27,2006), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555002981', 38, 2005, 'A-H', EXTEND(MDY(6,29,2006), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555002981', 39, 2005, 'A-H', EXTEND(MDY(6,30,2006), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555002981', 41, 2006, 'B-I', EXTEND(MDY(2,1,2007), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555002981', 42, 2006, 'B-I', EXTEND(MDY(2,1,2007), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555002981', 44, 2006, 'B-I', EXTEND(MDY(2,1,2007), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555002981', 45, 2006, 'B-I', EXTEND(MDY(2,1,2007), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555002981', 46, 2006, 'B-I', EXTEND(MDY(2,1,2007), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555002997', 9, 2006, 'C-A4', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555002997', 10, 2006, 'C-A4', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555002997', 28, 2006, 'C-A4', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003008', 9, 2006, 'C-A4', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003008', 10, 2006, 'C-A4', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003008', 28, 2006, 'C-A4', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003013', 34, 2006, 'A-M', EXTEND(MDY(2,1,2007), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003013', 44, 2006, 'B-J', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003013', 45, 2006, 'B-K', EXTEND(MDY(2,1,2007), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003013', 46, 2006, 'B-K', EXTEND(MDY(2,1,2007), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003034', 9, 2006, 'C-A2', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003034', 10, 2006, 'C-A2', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003034', 28, 2006, 'C-A2', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003060', 30, 2005, 'A-N', EXTEND(MDY(2,1,2006), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003060', 31, 2005, 'A-N', EXTEND(MDY(1,30,2006), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003060', 32, 2005, 'A-N', EXTEND(MDY(2,2,2006), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003060', 34, 2005, 'A-N', EXTEND(MDY(2,3,2006), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003060', 35, 2005, 'A-E', EXTEND(MDY(6,28,2006), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003060', 37, 2005, 'A-E', EXTEND(MDY(6,27,2006), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003060', 38, 2005, 'A-E', EXTEND(MDY(6,29,2006), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003060', 39, 2005, 'A-E', EXTEND(MDY(6,30,2006), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003060', 41, 2006, 'B-H', EXTEND(MDY(2,1,2007), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003060', 42, 2006, 'B-H', EXTEND(MDY(2,1,2007), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003060', 44, 2006, 'B-H', EXTEND(MDY(2,1,2007), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003060', 45, 2006, 'B-H', EXTEND(MDY(2,1,2007), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003060', 46, 2006, 'B-H', EXTEND(MDY(2,1,2007), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003076', 30, 2005, 'A-D', EXTEND(MDY(2,1,2006), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003076', 31, 2005, 'A-D', EXTEND(MDY(1,30,2006), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003076', 32, 2005, 'A-D', EXTEND(MDY(2,2,2006), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003076', 33, 2005, 'A-D', EXTEND(MDY(1,31,2006), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003076', 34, 2005, 'A-D', EXTEND(MDY(2,3,2006), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003076', 35, 2005, 'A-D', EXTEND(MDY(6,28,2006), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003076', 36, 2005, 'A-D', EXTEND(MDY(6,26,2006), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003076', 37, 2005, 'A-D', EXTEND(MDY(6,27,2006), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003076', 38, 2005, 'A-D', EXTEND(MDY(6,29,2006), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003076', 39, 2005, 'A-D', EXTEND(MDY(6,30,2006), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003076', 41, 2006, 'B-G', EXTEND(MDY(2,1,2007), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003076', 42, 2006, 'B-G', EXTEND(MDY(2,1,2007), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003076', 44, 2006, 'B-G', EXTEND(MDY(2,1,2007), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003076', 45, 2006, 'B-G', EXTEND(MDY(2,1,2007), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003076', 46, 2006, 'B-G', EXTEND(MDY(2,1,2007), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003081', 30, 2005, 'A-B', EXTEND(MDY(2,1,2006), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003081', 31, 2005, 'A-B', EXTEND(MDY(1,30,2006), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003081', 32, 2005, 'A-B', EXTEND(MDY(2,2,2006), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003081', 33, 2005, 'A-B', EXTEND(MDY(6,27,2006), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003081', 34, 2005, 'A-B', EXTEND(MDY(2,3,2006), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003081', 35, 2005, 'A-A', EXTEND(MDY(6,28,2006), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003081', 36, 2005, 'A-A', EXTEND(MDY(6,26,2006), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003081', 39, 2005, 'A-A', EXTEND(MDY(6,30,2006), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003081', 40, 2006, 'B-A', EXTEND(MDY(2,1,2007), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003081', 41, 2006, 'B-A', EXTEND(MDY(2,1,2007), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003081', 42, 2006, 'B-A', EXTEND(MDY(2,1,2007), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003081', 43, 2006, 'B-A', EXTEND(MDY(2,1,2007), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003081', 44, 2006, 'B-A', EXTEND(MDY(2,1,2007), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003097', 30, 2005, 'A-E', EXTEND(MDY(2,1,2006), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003097', 31, 2005, 'A-E', EXTEND(MDY(1,30,2006), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003097', 32, 2005, 'A-E', EXTEND(MDY(2,2,2006), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003097', 33, 2005, 'A-E', EXTEND(MDY(1,31,2006), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003097', 34, 2005, 'A-E', EXTEND(MDY(2,3,2006), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003097', 35, 2005, 'A-E', EXTEND(MDY(6,28,2006), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003097', 36, 2005, 'A-E', EXTEND(MDY(6,26,2006), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003097', 37, 2005, 'A-E', EXTEND(MDY(6,27,2006), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003097', 38, 2005, 'A-E', EXTEND(MDY(6,29,2006), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003097', 39, 2005, 'A-E', EXTEND(MDY(6,30,2006), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003097', 40, 2006, 'B-B', EXTEND(MDY(2,1,2007), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003097', 41, 2006, 'B-B', EXTEND(MDY(2,1,2007), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003097', 42, 2006, 'B-B', EXTEND(MDY(2,1,2007), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003097', 43, 2006, 'B-B', EXTEND(MDY(2,1,2007), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003097', 44, 2006, 'B-B', EXTEND(MDY(2,1,2007), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003104', 30, 2005, 'A-A', EXTEND(MDY(2,1,2006), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003104', 31, 2005, 'A-A', EXTEND(MDY(1,30,2006), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003104', 32, 2005, 'A-A', EXTEND(MDY(2,2,2006), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003104', 33, 2005, 'A-A', EXTEND(MDY(1,31,2006), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003104', 34, 2005, 'A-A', EXTEND(MDY(2,3,2006), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003104', 35, 2005, 'A-A', EXTEND(MDY(6,28,2006), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003104', 36, 2005, 'A-A', EXTEND(MDY(6,26,2006), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003104', 37, 2005, 'A-A', EXTEND(MDY(6,27,2006), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003104', 38, 2005, 'A-A', EXTEND(MDY(6,29,2006), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003104', 39, 2005, 'A-A', EXTEND(MDY(6,30,2006), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003104', 40, 2006, 'B-A', EXTEND(MDY(2,1,2007), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003104', 41, 2006, 'B-A', EXTEND(MDY(2,1,2007), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003104', 42, 2006, 'B-A', EXTEND(MDY(2,1,2007), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003104', 43, 2006, 'B-A', EXTEND(MDY(2,1,2007), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003104', 44, 2006, 'B-A', EXTEND(MDY(2,1,2007), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003125', 30, 2005, 'A-I', EXTEND(MDY(2,1,2006), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003125', 31, 2005, 'A-I', EXTEND(MDY(1,30,2006), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003125', 32, 2005, 'A-I', EXTEND(MDY(2,2,2006), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003125', 33, 2005, 'A-I', EXTEND(MDY(1,31,2006), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003125', 34, 2005, 'A-I', EXTEND(MDY(2,3,2006), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003125', 35, 2005, 'A-I', EXTEND(MDY(6,28,2006), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003125', 36, 2005, 'A-I', EXTEND(MDY(6,26,2006), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003125', 37, 2005, 'A-I', EXTEND(MDY(6,27,2006), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003125', 38, 2005, 'A-I', EXTEND(MDY(6,29,2006), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003125', 39, 2005, 'A-I', EXTEND(MDY(6,30,2006), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003125', 40, 2006, 'B-D', EXTEND(MDY(2,1,2007), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003125', 41, 2006, 'B-D', EXTEND(MDY(2,1,2007), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003125', 42, 2006, 'B-D', EXTEND(MDY(2,1,2007), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003125', 43, 2006, 'B-D', EXTEND(MDY(2,1,2007), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003125', 44, 2006, 'B-D', EXTEND(MDY(2,1,2007), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003130', 30, 2005, 'A-D', EXTEND(MDY(2,1,2006), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003130', 31, 2005, 'A-D', EXTEND(MDY(1,30,2006), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003130', 32, 2005, 'A-D', EXTEND(MDY(2,2,2006), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003130', 33, 2005, 'A-D', EXTEND(MDY(1,31,2006), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003130', 34, 2005, 'A-D', EXTEND(MDY(2,3,2006), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003130', 35, 2005, 'A-D', EXTEND(MDY(6,28,2006), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003130', 36, 2005, 'A-D', EXTEND(MDY(6,26,2006), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003130', 37, 2005, 'A-D', EXTEND(MDY(6,27,2006), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003130', 38, 2005, 'A-D', EXTEND(MDY(6,29,2006), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003130', 39, 2005, 'A-D', EXTEND(MDY(6,30,2006), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003130', 41, 2006, 'B-G', EXTEND(MDY(2,1,2007), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003130', 42, 2006, 'B-G', EXTEND(MDY(2,1,2007), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003130', 44, 2006, 'B-G', EXTEND(MDY(2,1,2007), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003130', 45, 2006, 'B-G', EXTEND(MDY(2,1,2007), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003130', 46, 2006, 'B-G', EXTEND(MDY(2,1,2007), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003146', 30, 2005, 'A-A', EXTEND(MDY(2,1,2006), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003146', 31, 2005, 'A-A', EXTEND(MDY(1,30,2006), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003146', 32, 2005, 'A-A', EXTEND(MDY(6,29,2006), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003146', 33, 2005, 'A-A', EXTEND(MDY(1,31,2006), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003146', 34, 2005, 'A-A', EXTEND(MDY(2,3,2006), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003146', 35, 2005, 'A-A', EXTEND(MDY(6,28,2006), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003146', 36, 2005, 'A-A', EXTEND(MDY(6,26,2006), YEAR to SECOND), 1);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003146', 37, 2005, 'A-A', EXTEND(MDY(6,27,2006), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003146', 39, 2005, 'A-A', EXTEND(MDY(6,30,2006), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003146', 40, 2006, 'B-D', EXTEND(MDY(2,1,2007), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003146', 41, 2006, 'B-D', EXTEND(MDY(2,1,2007), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003146', 42, 2006, 'B-D', EXTEND(MDY(2,1,2007), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003146', 43, 2006, 'B-D', EXTEND(MDY(2,1,2007), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003146', 44, 2006, 'B-D', EXTEND(MDY(2,1,2007), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003151', 30, 2005, 'A-F', EXTEND(MDY(2,1,2006), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003151', 31, 2005, 'A-F', EXTEND(MDY(1,30,2006), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003151', 32, 2005, 'A-F', EXTEND(MDY(2,2,2006), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003151', 33, 2005, 'A-F', EXTEND(MDY(1,31,2006), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003151', 34, 2005, 'A-F', EXTEND(MDY(2,3,2006), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003151', 35, 2005, 'A-F', EXTEND(MDY(6,28,2006), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003151', 36, 2005, 'A-F', EXTEND(MDY(6,26,2006), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003151', 37, 2005, 'A-F', EXTEND(MDY(6,27,2006), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003151', 38, 2005, 'A-F', EXTEND(MDY(6,29,2006), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003151', 39, 2005, 'A-F', EXTEND(MDY(6,30,2006), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003151', 41, 2006, 'B-H', EXTEND(MDY(2,1,2007), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003151', 42, 2006, 'B-H', EXTEND(MDY(2,1,2007), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003151', 44, 2006, 'B-H', EXTEND(MDY(2,1,2007), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003151', 45, 2006, 'B-H', EXTEND(MDY(2,1,2007), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003151', 46, 2006, 'B-H', EXTEND(MDY(2,1,2007), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003167', 30, 2005, 'A-K', EXTEND(MDY(2,1,2006), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003167', 31, 2005, 'A-K', EXTEND(MDY(1,30,2006), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003167', 32, 2005, 'A-K', EXTEND(MDY(2,2,2006), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003167', 33, 2005, 'A-K', EXTEND(MDY(1,31,2006), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003167', 34, 2005, 'A-K', EXTEND(MDY(2,3,2006), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003167', 35, 2005, 'A-I', EXTEND(MDY(6,28,2006), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003167', 36, 2005, 'A-I', EXTEND(MDY(6,26,2006), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003167', 37, 2005, 'A-I', EXTEND(MDY(6,27,2006), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003167', 38, 2005, 'A-I', EXTEND(MDY(6,29,2006), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003167', 39, 2005, 'A-I', EXTEND(MDY(6,30,2006), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003167', 41, 2006, 'B-J', EXTEND(MDY(2,1,2007), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003167', 42, 2006, 'B-J', EXTEND(MDY(2,1,2007), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003167', 44, 2006, 'B-J', EXTEND(MDY(2,1,2007), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003167', 45, 2006, 'B-J', EXTEND(MDY(2,1,2007), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003167', 46, 2006, 'B-J', EXTEND(MDY(2,1,2007), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003172', 30, 2005, 'A-I', EXTEND(MDY(6,28,2006), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003172', 31, 2005, 'A-I', EXTEND(MDY(1,30,2006), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003172', 32, 2005, 'A-I', EXTEND(MDY(2,2,2006), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003172', 33, 2005, 'A-I', EXTEND(MDY(6,27,2006), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003172', 34, 2005, 'A-I', EXTEND(MDY(2,3,2006), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003172', 36, 2005, 'A-J', EXTEND(MDY(6,26,2006), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003172', 39, 2005, 'A-J', EXTEND(MDY(6,30,2006), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003172', 41, 2006, 'B-F', EXTEND(MDY(2,1,2007), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003172', 42, 2006, 'B-F', EXTEND(MDY(2,1,2007), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003172', 44, 2006, 'B-F', EXTEND(MDY(2,1,2007), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003188', 30, 2005, 'A-D', EXTEND(MDY(2,1,2006), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003188', 31, 2005, 'A-D', EXTEND(MDY(1,30,2006), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003188', 32, 2005, 'A-D', EXTEND(MDY(2,2,2006), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003188', 33, 2005, 'A-D', EXTEND(MDY(1,31,2006), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003188', 34, 2005, 'A-D', EXTEND(MDY(2,3,2006), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003188', 35, 2005, 'A-D', EXTEND(MDY(6,28,2006), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003188', 36, 2005, 'A-D', EXTEND(MDY(6,26,2006), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003188', 37, 2005, 'A-D', EXTEND(MDY(6,27,2006), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003188', 38, 2005, 'A-D', EXTEND(MDY(6,29,2006), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003188', 39, 2005, 'A-D', EXTEND(MDY(6,30,2006), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003188', 41, 2006, 'B-G', EXTEND(MDY(2,1,2007), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003188', 42, 2006, 'B-G', EXTEND(MDY(2,1,2007), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003188', 44, 2006, 'B-G', EXTEND(MDY(2,1,2007), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003188', 45, 2006, 'B-G', EXTEND(MDY(2,1,2007), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003188', 46, 2006, 'B-G', EXTEND(MDY(2,1,2007), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003193', 30, 2005, 'A-G', EXTEND(MDY(2,1,2006), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003193', 31, 2005, 'A-G', EXTEND(MDY(1,30,2006), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003193', 32, 2005, 'A-G', EXTEND(MDY(2,2,2006), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003193', 33, 2005, 'A-G', EXTEND(MDY(1,31,2006), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003193', 34, 2005, 'A-G', EXTEND(MDY(2,3,2006), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003193', 35, 2005, 'A-G', EXTEND(MDY(6,28,2006), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003193', 36, 2005, 'A-G', EXTEND(MDY(6,26,2006), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003193', 37, 2005, 'A-G', EXTEND(MDY(6,27,2006), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003193', 38, 2005, 'A-G', EXTEND(MDY(6,29,2006), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003193', 39, 2005, 'A-G', EXTEND(MDY(6,30,2006), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003193', 41, 2006, 'B-I', EXTEND(MDY(2,1,2007), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003193', 42, 2006, 'B-I', EXTEND(MDY(2,1,2007), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003193', 44, 2006, 'B-I', EXTEND(MDY(2,1,2007), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003193', 45, 2006, 'B-I', EXTEND(MDY(2,1,2007), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003193', 46, 2006, 'B-I', EXTEND(MDY(2,1,2007), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003200', 30, 2005, 'A-F', EXTEND(MDY(2,1,2006), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003200', 31, 2005, 'A-F', EXTEND(MDY(6,30,2006), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003200', 32, 2005, 'A-F', EXTEND(MDY(2,2,2006), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003200', 33, 2005, 'A-F', EXTEND(MDY(1,31,2006), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003200', 34, 2005, 'A-F', EXTEND(MDY(2,3,2006), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003200', 35, 2005, 'A-C', EXTEND(MDY(6,28,2006), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003200', 36, 2005, 'A-E', EXTEND(MDY(6,26,2006), YEAR to SECOND), 1);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003200', 37, 2005, 'A-C', EXTEND(MDY(6,27,2006), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003200', 38, 2005, 'A-C', EXTEND(MDY(6,29,2006), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003200', 39, 2005, 'A-C', EXTEND(MDY(6,30,2006), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003200', 41, 2006, 'B-F', EXTEND(MDY(2,1,2007), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003200', 42, 2006, 'B-F', EXTEND(MDY(2,1,2007), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003200', 44, 2006, 'B-F', EXTEND(MDY(2,1,2007), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003200', 45, 2006, 'B-F', EXTEND(MDY(2,1,2007), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003200', 46, 2006, 'B-F', EXTEND(MDY(2,1,2007), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003216', 30, 2005, 'A-D', EXTEND(MDY(2,1,2006), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003216', 31, 2005, 'A-D', EXTEND(MDY(1,30,2006), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003216', 32, 2005, 'A-D', EXTEND(MDY(2,2,2006), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003216', 33, 2005, 'A-D', EXTEND(MDY(1,31,2006), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003216', 34, 2005, 'A-D', EXTEND(MDY(2,3,2006), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003216', 35, 2005, 'A-D', EXTEND(MDY(6,28,2006), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003216', 36, 2005, 'A-D', EXTEND(MDY(6,26,2006), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003216', 37, 2005, 'A-D', EXTEND(MDY(6,27,2006), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003216', 38, 2005, 'A-D', EXTEND(MDY(6,29,2006), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003216', 39, 2005, 'A-D', EXTEND(MDY(6,30,2006), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003216', 41, 2006, 'B-G', EXTEND(MDY(2,1,2007), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003216', 42, 2006, 'B-G', EXTEND(MDY(2,1,2007), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003216', 44, 2006, 'B-G', EXTEND(MDY(2,1,2007), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003216', 45, 2006, 'B-G', EXTEND(MDY(2,1,2007), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003216', 46, 2006, 'B-G', EXTEND(MDY(2,1,2007), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003221', 30, 2005, 'A-I', EXTEND(MDY(2,1,2006), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003221', 31, 2005, 'A-I', EXTEND(MDY(1,30,2006), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003221', 32, 2005, 'A-I', EXTEND(MDY(2,2,2006), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003221', 33, 2005, 'A-I', EXTEND(MDY(1,31,2006), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003221', 34, 2005, 'A-I', EXTEND(MDY(2,3,2006), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003221', 35, 2005, 'A-I', EXTEND(MDY(6,28,2006), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003221', 36, 2005, 'A-I', EXTEND(MDY(6,26,2006), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003221', 37, 2005, 'A-I', EXTEND(MDY(6,27,2006), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003221', 38, 2005, 'A-I', EXTEND(MDY(6,29,2006), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003221', 39, 2005, 'A-I', EXTEND(MDY(6,30,2006), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003221', 41, 2006, 'B-J', EXTEND(MDY(2,1,2007), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003221', 42, 2006, 'B-J', EXTEND(MDY(2,1,2007), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003221', 44, 2006, 'B-J', EXTEND(MDY(2,1,2007), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003221', 45, 2006, 'B-J', EXTEND(MDY(2,1,2007), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003221', 46, 2006, 'B-J', EXTEND(MDY(2,1,2007), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003237', 30, 2005, 'A-K', EXTEND(MDY(2,1,2006), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003237', 31, 2005, 'A-K', EXTEND(MDY(1,30,2006), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003237', 32, 2005, 'A-K', EXTEND(MDY(2,2,2006), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003237', 33, 2005, 'A-K', EXTEND(MDY(1,31,2006), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003237', 34, 2005, 'A-K', EXTEND(MDY(2,3,2006), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003237', 35, 2005, 'A-I', EXTEND(MDY(6,28,2006), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003237', 36, 2005, 'A-I', EXTEND(MDY(6,26,2006), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003237', 37, 2005, 'A-I', EXTEND(MDY(6,27,2006), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003237', 38, 2005, 'A-I', EXTEND(MDY(6,29,2006), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003237', 39, 2005, 'A-I', EXTEND(MDY(6,30,2006), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003237', 40, 2006, 'B-D', EXTEND(MDY(2,1,2007), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003237', 41, 2006, 'B-D', EXTEND(MDY(2,1,2007), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003237', 42, 2006, 'B-D', EXTEND(MDY(2,1,2007), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003237', 43, 2006, 'B-D', EXTEND(MDY(2,1,2007), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003237', 44, 2006, 'B-D', EXTEND(MDY(2,1,2007), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003242', 30, 2005, 'A-K', EXTEND(MDY(2,1,2006), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003242', 31, 2005, 'A-K', EXTEND(MDY(1,30,2006), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003242', 32, 2005, 'A-K', EXTEND(MDY(2,2,2006), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003242', 33, 2005, 'A-K', EXTEND(MDY(1,31,2006), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003242', 34, 2005, 'A-K', EXTEND(MDY(2,3,2006), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003242', 35, 2005, 'A-I', EXTEND(MDY(6,28,2006), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003242', 36, 2005, 'A-I', EXTEND(MDY(6,26,2006), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003242', 37, 2005, 'A-I', EXTEND(MDY(6,27,2006), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003242', 38, 2005, 'A-I', EXTEND(MDY(6,29,2006), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003242', 39, 2005, 'A-I', EXTEND(MDY(6,30,2006), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003242', 40, 2006, 'B-D', EXTEND(MDY(2,1,2007), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003242', 41, 2006, 'B-D', EXTEND(MDY(2,1,2007), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003242', 42, 2006, 'B-D', EXTEND(MDY(2,1,2007), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003242', 43, 2006, 'B-D', EXTEND(MDY(2,1,2007), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003242', 44, 2006, 'B-D', EXTEND(MDY(2,1,2007), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003258', 30, 2005, 'A-D', EXTEND(MDY(2,1,2006), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003258', 31, 2005, 'A-D', EXTEND(MDY(1,30,2006), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003258', 32, 2005, 'A-D', EXTEND(MDY(2,2,2006), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003258', 33, 2005, 'A-D', EXTEND(MDY(1,31,2006), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003258', 34, 2005, 'A-D', EXTEND(MDY(2,3,2006), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003258', 35, 2005, 'A-D', EXTEND(MDY(6,28,2006), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003258', 36, 2005, 'A-D', EXTEND(MDY(6,26,2006), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003258', 37, 2005, 'A-D', EXTEND(MDY(6,27,2006), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003258', 38, 2005, 'A-D', EXTEND(MDY(6,29,2006), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003258', 39, 2005, 'A-D', EXTEND(MDY(6,30,2006), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003258', 40, 2006, 'B-B', EXTEND(MDY(2,1,2007), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003258', 41, 2006, 'B-B', EXTEND(MDY(2,1,2007), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003258', 42, 2006, 'B-B', EXTEND(MDY(2,1,2007), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003258', 43, 2006, 'B-B', EXTEND(MDY(2,1,2007), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003258', 44, 2006, 'B-B', EXTEND(MDY(2,1,2007), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003263', 30, 2005, 'A-F', EXTEND(MDY(2,1,2006), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003263', 31, 2005, 'A-F', EXTEND(MDY(1,30,2006), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003263', 32, 2005, 'A-F', EXTEND(MDY(2,2,2006), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003263', 33, 2005, 'A-F', EXTEND(MDY(1,31,2006), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003263', 34, 2005, 'A-F', EXTEND(MDY(2,3,2006), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003263', 35, 2005, 'A-F', EXTEND(MDY(6,28,2006), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003263', 36, 2005, 'A-F', EXTEND(MDY(6,26,2006), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003263', 37, 2005, 'A-F', EXTEND(MDY(6,27,2006), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003263', 38, 2005, 'A-F', EXTEND(MDY(6,29,2006), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003263', 39, 2005, 'A-F', EXTEND(MDY(6,30,2006), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003263', 41, 2006, 'B-H', EXTEND(MDY(2,1,2007), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003263', 42, 2006, 'B-H', EXTEND(MDY(2,1,2007), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003263', 44, 2006, 'B-H', EXTEND(MDY(2,1,2007), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003263', 45, 2006, 'B-H', EXTEND(MDY(2,1,2007), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003263', 46, 2006, 'B-H', EXTEND(MDY(2,1,2007), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003279', 30, 2005, 'A-E', EXTEND(MDY(2,1,2006), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003279', 31, 2005, 'A-E', EXTEND(MDY(1,30,2006), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003279', 32, 2005, 'A-E', EXTEND(MDY(2,2,2006), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003279', 33, 2005, 'A-E', EXTEND(MDY(1,31,2006), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003279', 34, 2005, 'A-E', EXTEND(MDY(2,3,2006), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003279', 35, 2005, 'A-E', EXTEND(MDY(6,28,2006), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003279', 36, 2005, 'A-E', EXTEND(MDY(6,26,2006), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003279', 37, 2005, 'A-E', EXTEND(MDY(6,27,2006), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003279', 38, 2005, 'A-E', EXTEND(MDY(6,29,2006), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003279', 39, 2005, 'A-E', EXTEND(MDY(6,30,2006), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003279', 41, 2006, 'B-H', EXTEND(MDY(2,1,2007), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003279', 42, 2006, 'B-H', EXTEND(MDY(2,1,2007), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003279', 44, 2006, 'B-H', EXTEND(MDY(2,1,2007), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003279', 45, 2006, 'B-H', EXTEND(MDY(2,1,2007), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003279', 46, 2006, 'B-H', EXTEND(MDY(2,1,2007), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003284', 30, 2005, 'A-A', EXTEND(MDY(2,1,2006), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003284', 31, 2005, 'A-A', EXTEND(MDY(1,30,2006), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003284', 32, 2005, 'A-A', EXTEND(MDY(2,2,2006), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003284', 33, 2005, 'A-A', EXTEND(MDY(1,31,2006), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003284', 34, 2005, 'A-A', EXTEND(MDY(2,3,2006), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003284', 35, 2005, 'A-A', EXTEND(MDY(6,28,2006), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003284', 36, 2005, 'A-A', EXTEND(MDY(6,26,2006), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003284', 37, 2005, 'A-A', EXTEND(MDY(6,27,2006), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003284', 38, 2005, 'A-A', EXTEND(MDY(6,29,2006), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003284', 39, 2005, 'A-A', EXTEND(MDY(6,30,2006), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003284', 41, 2006, 'B-F', EXTEND(MDY(2,1,2007), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003284', 42, 2006, 'B-F', EXTEND(MDY(2,1,2007), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003284', 44, 2006, 'B-F', EXTEND(MDY(2,1,2007), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003284', 45, 2006, 'B-F', EXTEND(MDY(2,1,2007), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003284', 46, 2006, 'B-F', EXTEND(MDY(2,1,2007), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003307', 30, 2005, 'A-A', EXTEND(MDY(2,1,2006), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003307', 31, 2005, 'A-A', EXTEND(MDY(1,30,2006), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003307', 32, 2005, 'A-A', EXTEND(MDY(6,29,2006), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003307', 33, 2005, 'A-A', EXTEND(MDY(6,27,2006), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003307', 34, 2005, 'A-A', EXTEND(MDY(2,3,2006), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003307', 35, 2005, 'A-B', EXTEND(MDY(6,28,2006), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003307', 36, 2005, 'A-B', EXTEND(MDY(6,26,2006), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003307', 39, 2005, 'A-D', EXTEND(MDY(6,30,2006), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003307', 40, 2006, 'B-C', EXTEND(MDY(2,1,2007), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003307', 41, 2006, 'B-C', EXTEND(MDY(2,1,2007), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003307', 42, 2006, 'B-C', EXTEND(MDY(2,1,2007), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003307', 43, 2006, 'B-C', EXTEND(MDY(2,1,2007), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003307', 44, 2006, 'B-C', EXTEND(MDY(2,1,2007), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003312', 30, 2005, 'A-F', EXTEND(MDY(2,1,2006), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003312', 31, 2005, 'A-F', EXTEND(MDY(1,30,2006), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003312', 32, 2005, 'A-F', EXTEND(MDY(2,2,2006), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003312', 33, 2005, 'A-F', EXTEND(MDY(1,31,2006), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003312', 34, 2005, 'A-F', EXTEND(MDY(2,3,2006), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003312', 35, 2005, 'A-F', EXTEND(MDY(6,28,2006), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003312', 36, 2005, 'A-F', EXTEND(MDY(6,26,2006), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003312', 37, 2005, 'A-F', EXTEND(MDY(6,27,2006), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003312', 38, 2005, 'A-F', EXTEND(MDY(6,29,2006), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003312', 39, 2005, 'A-F', EXTEND(MDY(6,30,2006), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003312', 41, 2006, 'B-H', EXTEND(MDY(2,1,2007), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003312', 42, 2006, 'B-H', EXTEND(MDY(2,1,2007), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003312', 44, 2006, 'B-H', EXTEND(MDY(2,1,2007), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003312', 45, 2006, 'B-H', EXTEND(MDY(2,1,2007), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003312', 46, 2006, 'B-H', EXTEND(MDY(2,1,2007), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003328', 30, 2005, 'A-D', EXTEND(MDY(6,28,2006), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003328', 31, 2005, 'A-D', EXTEND(MDY(2,1,2007), YEAR to SECOND), 1);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003328', 31, 2006, 'A-K', EXTEND(MDY(2,1,2007), YEAR to SECOND), 1);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003328', 32, 2005, 'A-D', EXTEND(MDY(6,29,2006), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003328', 33, 2005, 'A-D', EXTEND(MDY(6,16,2006), YEAR to SECOND), 1);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003328', 33, 2006, 'A-K', EXTEND(MDY(2,1,2007), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003328', 34, 2005, 'A-D', EXTEND(MDY(2,3,2006), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003328', 39, 2005, 'A-N', EXTEND(MDY(6,30,2006), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003328', 41, 2006, 'B-A', EXTEND(MDY(2,1,2007), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003328', 44, 2006, 'B-C', EXTEND(MDY(2,1,2007), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003333', 30, 2005, 'A-E', EXTEND(MDY(2,1,2006), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003333', 31, 2005, 'A-E', EXTEND(MDY(1,30,2006), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003333', 32, 2005, 'A-E', EXTEND(MDY(2,2,2006), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003333', 33, 2005, 'A-E', EXTEND(MDY(1,31,2006), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003333', 34, 2005, 'A-E', EXTEND(MDY(2,3,2006), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003333', 35, 2005, 'A-E', EXTEND(MDY(6,28,2006), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003333', 36, 2005, 'A-E', EXTEND(MDY(6,26,2006), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003333', 37, 2005, 'A-E', EXTEND(MDY(6,27,2006), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003333', 38, 2005, 'A-E', EXTEND(MDY(6,29,2006), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003333', 39, 2005, 'A-E', EXTEND(MDY(6,30,2006), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003333', 41, 2006, 'B-H', EXTEND(MDY(2,1,2007), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003333', 42, 2006, 'B-H', EXTEND(MDY(2,1,2007), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003333', 44, 2006, 'B-H', EXTEND(MDY(2,1,2007), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003333', 45, 2006, 'B-H', EXTEND(MDY(2,1,2007), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003333', 46, 2006, 'B-H', EXTEND(MDY(2,1,2007), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003349', 30, 2005, 'A-A', EXTEND(MDY(2,1,2006), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003349', 31, 2005, 'A-A', EXTEND(MDY(1,30,2006), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003349', 32, 2005, 'A-A', EXTEND(MDY(2,2,2006), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003349', 33, 2005, 'A-A', EXTEND(MDY(6,27,2006), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003349', 34, 2005, 'A-A', EXTEND(MDY(2,3,2006), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003349', 35, 2005, 'A-A', EXTEND(MDY(6,28,2006), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003349', 36, 2005, 'A-A', EXTEND(MDY(6,26,2006), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003349', 39, 2005, 'A-A', EXTEND(MDY(6,30,2006), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003349', 40, 2006, 'B-D', EXTEND(MDY(2,1,2007), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003349', 41, 2006, 'B-D', EXTEND(MDY(2,1,2007), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003349', 42, 2006, 'B-D', EXTEND(MDY(2,1,2007), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003349', 43, 2006, 'B-D', EXTEND(MDY(2,1,2007), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003349', 44, 2006, 'B-D', EXTEND(MDY(2,1,2007), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003354', 30, 2005, 'A-K', EXTEND(MDY(2,1,2006), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003354', 31, 2005, 'A-K', EXTEND(MDY(1,30,2006), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003354', 32, 2005, 'A-K', EXTEND(MDY(6,29,2006), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003354', 33, 2005, 'A-K', EXTEND(MDY(6,27,2006), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003354', 34, 2005, 'A-K', EXTEND(MDY(2,3,2006), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003354', 35, 2005, 'A-J', EXTEND(MDY(6,28,2006), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003354', 36, 2005, 'A-H', EXTEND(MDY(6,26,2006), YEAR to SECOND), 1);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003354', 39, 2005, 'A-J', EXTEND(MDY(6,30,2006), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003354', 40, 2006, 'B-D', EXTEND(MDY(2,1,2007), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003354', 41, 2006, 'B-D', EXTEND(MDY(2,1,2007), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003354', 42, 2006, 'B-D', EXTEND(MDY(2,1,2007), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003354', 43, 2006, 'B-D', EXTEND(MDY(2,1,2007), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003354', 44, 2006, 'B-D', EXTEND(MDY(2,1,2007), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003375', 30, 2005, 'A-F', EXTEND(MDY(2,1,2006), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003375', 31, 2005, 'A-F', EXTEND(MDY(1,30,2006), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003375', 32, 2005, 'A-F', EXTEND(MDY(2,2,2006), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003375', 33, 2005, 'A-F', EXTEND(MDY(1,31,2006), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003375', 34, 2005, 'A-F', EXTEND(MDY(2,3,2006), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003375', 35, 2005, 'A-F', EXTEND(MDY(6,28,2006), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003375', 36, 2005, 'A-F', EXTEND(MDY(6,26,2006), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003375', 37, 2005, 'A-F', EXTEND(MDY(6,27,2006), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003375', 38, 2005, 'A-F', EXTEND(MDY(6,29,2006), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003375', 39, 2005, 'A-F', EXTEND(MDY(6,30,2006), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003375', 41, 2006, 'B-H', EXTEND(MDY(2,1,2007), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003375', 42, 2006, 'B-H', EXTEND(MDY(2,1,2007), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003375', 44, 2006, 'B-H', EXTEND(MDY(2,1,2007), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003375', 45, 2006, 'B-H', EXTEND(MDY(2,1,2007), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003375', 46, 2006, 'B-H', EXTEND(MDY(2,1,2007), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003380', 30, 2005, 'A-K', EXTEND(MDY(2,1,2006), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003380', 31, 2005, 'A-K', EXTEND(MDY(1,30,2006), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003380', 32, 2005, 'A-K', EXTEND(MDY(2,2,2006), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003380', 33, 2005, 'A-K', EXTEND(MDY(1,31,2006), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003380', 34, 2005, 'A-K', EXTEND(MDY(2,3,2006), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003380', 35, 2005, 'A-I', EXTEND(MDY(6,28,2006), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003380', 36, 2005, 'A-I', EXTEND(MDY(6,26,2006), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003380', 37, 2005, 'A-I', EXTEND(MDY(6,27,2006), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003380', 38, 2005, 'A-I', EXTEND(MDY(6,29,2006), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003380', 39, 2005, 'A-I', EXTEND(MDY(6,30,2006), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003380', 41, 2006, 'B-J', EXTEND(MDY(2,1,2007), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003380', 42, 2006, 'B-J', EXTEND(MDY(2,1,2007), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003380', 44, 2006, 'B-J', EXTEND(MDY(2,1,2007), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003380', 45, 2006, 'B-J', EXTEND(MDY(2,1,2007), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003380', 46, 2006, 'B-J', EXTEND(MDY(2,1,2007), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003396', 30, 2005, 'A-F', EXTEND(MDY(2,1,2006), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003396', 31, 2005, 'A-F', EXTEND(MDY(1,30,2006), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003396', 32, 2005, 'A-F', EXTEND(MDY(2,2,2006), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003396', 33, 2005, 'A-F', EXTEND(MDY(1,31,2006), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003396', 34, 2005, 'A-F', EXTEND(MDY(2,3,2006), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003396', 35, 2005, 'A-F', EXTEND(MDY(6,28,2006), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003396', 36, 2005, 'A-F', EXTEND(MDY(6,26,2006), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003396', 37, 2005, 'A-F', EXTEND(MDY(6,27,2006), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003396', 38, 2005, 'A-F', EXTEND(MDY(6,29,2006), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003396', 39, 2005, 'A-F', EXTEND(MDY(6,30,2006), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003396', 41, 2006, 'B-H', EXTEND(MDY(2,1,2007), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003396', 42, 2006, 'B-H', EXTEND(MDY(2,1,2007), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003396', 44, 2006, 'B-H', EXTEND(MDY(2,1,2007), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003396', 45, 2006, 'B-H', EXTEND(MDY(2,1,2007), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003396', 46, 2006, 'B-H', EXTEND(MDY(2,1,2007), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003403', 30, 2005, 'A-D', EXTEND(MDY(2,1,2006), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003403', 31, 2005, 'A-D', EXTEND(MDY(1,30,2006), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003403', 32, 2005, 'A-D', EXTEND(MDY(2,2,2006), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003403', 33, 2005, 'A-D', EXTEND(MDY(1,31,2006), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003403', 34, 2005, 'A-D', EXTEND(MDY(2,3,2006), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003403', 35, 2005, 'A-D', EXTEND(MDY(6,28,2006), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003403', 36, 2005, 'A-D', EXTEND(MDY(6,26,2006), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003403', 37, 2005, 'A-D', EXTEND(MDY(6,27,2006), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003403', 38, 2005, 'A-D', EXTEND(MDY(6,29,2006), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003403', 39, 2005, 'A-D', EXTEND(MDY(6,30,2006), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003403', 41, 2006, 'B-G', EXTEND(MDY(2,1,2007), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003403', 42, 2006, 'B-G', EXTEND(MDY(2,1,2007), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003403', 44, 2006, 'B-G', EXTEND(MDY(2,1,2007), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003403', 45, 2006, 'B-G', EXTEND(MDY(2,1,2007), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003403', 46, 2006, 'B-G', EXTEND(MDY(2,1,2007), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003419', 30, 2005, 'A-D', EXTEND(MDY(2,1,2006), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003419', 31, 2005, 'A-D', EXTEND(MDY(1,30,2006), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003419', 32, 2005, 'A-D', EXTEND(MDY(2,2,2006), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003419', 33, 2005, 'A-D', EXTEND(MDY(1,31,2006), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003419', 34, 2005, 'A-D', EXTEND(MDY(2,3,2006), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003419', 35, 2005, 'A-D', EXTEND(MDY(6,28,2006), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003419', 36, 2005, 'A-D', EXTEND(MDY(6,26,2006), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003419', 37, 2005, 'A-D', EXTEND(MDY(6,27,2006), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003419', 38, 2005, 'A-D', EXTEND(MDY(6,29,2006), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003419', 39, 2005, 'A-D', EXTEND(MDY(6,30,2006), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003419', 41, 2006, 'B-G', EXTEND(MDY(2,1,2007), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003419', 42, 2006, 'B-G', EXTEND(MDY(2,1,2007), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003419', 44, 2006, 'B-G', EXTEND(MDY(2,1,2007), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003419', 45, 2006, 'B-G', EXTEND(MDY(2,1,2007), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003419', 46, 2006, 'B-G', EXTEND(MDY(2,1,2007), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003424', 30, 2005, 'A-I', EXTEND(MDY(2,1,2006), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003424', 31, 2005, 'A-I', EXTEND(MDY(1,30,2006), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003424', 32, 2005, 'A-I', EXTEND(MDY(2,2,2006), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003424', 33, 2005, 'A-I', EXTEND(MDY(1,31,2006), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003424', 34, 2005, 'A-I', EXTEND(MDY(2,3,2006), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003424', 35, 2005, 'A-I', EXTEND(MDY(6,28,2006), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003424', 36, 2005, 'A-I', EXTEND(MDY(6,26,2006), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003424', 37, 2005, 'A-I', EXTEND(MDY(6,27,2006), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003424', 38, 2005, 'A-I', EXTEND(MDY(6,29,2006), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003424', 39, 2005, 'A-I', EXTEND(MDY(6,30,2006), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003424', 40, 2006, 'B-D', EXTEND(MDY(2,1,2007), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003424', 41, 2006, 'B-D', EXTEND(MDY(2,1,2007), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003424', 42, 2006, 'B-D', EXTEND(MDY(2,1,2007), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003424', 43, 2006, 'B-D', EXTEND(MDY(2,1,2007), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003424', 44, 2006, 'B-D', EXTEND(MDY(2,1,2007), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003445', 30, 2005, 'A-K', EXTEND(MDY(2,1,2006), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003445', 31, 2005, 'A-K', EXTEND(MDY(1,30,2006), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003445', 32, 2005, 'A-K', EXTEND(MDY(2,2,2006), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003445', 33, 2005, 'A-K', EXTEND(MDY(1,31,2006), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003445', 34, 2005, 'A-K', EXTEND(MDY(2,3,2006), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003445', 35, 2005, 'A-I', EXTEND(MDY(6,28,2006), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003445', 36, 2005, 'A-I', EXTEND(MDY(6,26,2006), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003445', 37, 2005, 'A-I', EXTEND(MDY(6,27,2006), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003445', 38, 2005, 'A-I', EXTEND(MDY(6,29,2006), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003445', 39, 2005, 'A-I', EXTEND(MDY(6,30,2006), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003445', 41, 2006, 'B-J', EXTEND(MDY(2,1,2007), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003445', 42, 2006, 'B-J', EXTEND(MDY(2,1,2007), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003445', 44, 2006, 'B-J', EXTEND(MDY(2,1,2007), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003445', 45, 2006, 'B-J', EXTEND(MDY(2,1,2007), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003445', 46, 2006, 'B-J', EXTEND(MDY(2,1,2007), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003450', 30, 2005, 'A-E', EXTEND(MDY(2,1,2006), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003450', 31, 2005, 'A-E', EXTEND(MDY(1,30,2006), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003450', 32, 2005, 'A-E', EXTEND(MDY(2,2,2006), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003450', 33, 2005, 'A-E', EXTEND(MDY(1,31,2006), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003450', 34, 2005, 'A-E', EXTEND(MDY(2,3,2006), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003450', 35, 2005, 'A-E', EXTEND(MDY(6,28,2006), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003450', 36, 2005, 'A-E', EXTEND(MDY(6,26,2006), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003450', 37, 2005, 'A-E', EXTEND(MDY(6,27,2006), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003450', 38, 2005, 'A-E', EXTEND(MDY(6,29,2006), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003450', 39, 2005, 'A-E', EXTEND(MDY(6,30,2006), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003450', 41, 2006, 'B-H', EXTEND(MDY(2,1,2007), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003450', 42, 2006, 'B-H', EXTEND(MDY(2,1,2007), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003450', 44, 2006, 'B-H', EXTEND(MDY(2,1,2007), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003450', 45, 2006, 'B-H', EXTEND(MDY(2,1,2007), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003450', 46, 2006, 'B-H', EXTEND(MDY(2,1,2007), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003466', 30, 2005, 'A-D', EXTEND(MDY(2,1,2006), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003466', 31, 2005, 'A-D', EXTEND(MDY(1,30,2006), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003466', 32, 2005, 'A-D', EXTEND(MDY(2,2,2006), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003466', 33, 2005, 'A-D', EXTEND(MDY(1,31,2006), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003466', 34, 2005, 'A-D', EXTEND(MDY(2,3,2006), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003466', 35, 2005, 'A-D', EXTEND(MDY(6,28,2006), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003466', 36, 2005, 'A-D', EXTEND(MDY(6,26,2006), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003466', 37, 2005, 'A-D', EXTEND(MDY(6,27,2006), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003466', 38, 2005, 'A-D', EXTEND(MDY(6,29,2006), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003466', 39, 2005, 'A-D', EXTEND(MDY(6,30,2006), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003466', 40, 2006, 'B-B', EXTEND(MDY(2,1,2007), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003466', 41, 2006, 'B-B', EXTEND(MDY(2,1,2007), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003466', 42, 2006, 'B-B', EXTEND(MDY(2,1,2007), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003466', 43, 2006, 'B-B', EXTEND(MDY(2,1,2007), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003466', 44, 2006, 'B-B', EXTEND(MDY(2,1,2007), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003471', 30, 2005, 'A-A', EXTEND(MDY(2,1,2006), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003471', 31, 2005, 'A-A', EXTEND(MDY(1,30,2006), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003471', 32, 2005, 'A-A', EXTEND(MDY(2,2,2006), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003471', 33, 2005, 'A-A', EXTEND(MDY(1,31,2006), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003471', 34, 2005, 'A-A', EXTEND(MDY(2,3,2006), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003471', 35, 2005, 'A-A', EXTEND(MDY(6,28,2006), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003471', 36, 2005, 'A-A', EXTEND(MDY(6,26,2006), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003471', 37, 2005, 'A-A', EXTEND(MDY(6,27,2006), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003471', 38, 2005, 'A-A', EXTEND(MDY(6,29,2006), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003471', 39, 2005, 'A-A', EXTEND(MDY(6,30,2006), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003471', 41, 2006, 'B-F', EXTEND(MDY(2,1,2007), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003471', 42, 2006, 'B-F', EXTEND(MDY(2,1,2007), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003471', 44, 2006, 'B-F', EXTEND(MDY(2,1,2007), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003471', 45, 2006, 'B-F', EXTEND(MDY(2,1,2007), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003471', 46, 2006, 'B-F', EXTEND(MDY(2,1,2007), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003487', 30, 2005, 'A-E', EXTEND(MDY(2,1,2006), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003487', 31, 2005, 'A-E', EXTEND(MDY(1,30,2006), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003487', 32, 2005, 'A-E', EXTEND(MDY(2,2,2006), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003487', 33, 2005, 'A-E', EXTEND(MDY(1,31,2006), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003487', 34, 2005, 'A-E', EXTEND(MDY(2,3,2006), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003487', 35, 2005, 'A-E', EXTEND(MDY(6,28,2006), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003487', 36, 2005, 'A-E', EXTEND(MDY(6,26,2006), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003487', 37, 2005, 'A-E', EXTEND(MDY(6,27,2006), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003487', 38, 2005, 'A-E', EXTEND(MDY(6,29,2006), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003487', 39, 2005, 'A-E', EXTEND(MDY(6,30,2006), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003487', 40, 2006, 'B-B', EXTEND(MDY(2,1,2007), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003487', 41, 2006, 'B-B', EXTEND(MDY(2,1,2007), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003487', 42, 2006, 'B-B', EXTEND(MDY(2,1,2007), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003487', 43, 2006, 'B-B', EXTEND(MDY(2,1,2007), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003487', 44, 2006, 'B-B', EXTEND(MDY(2,1,2007), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003492', 30, 2005, 'A-C', EXTEND(MDY(2,1,2006), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003492', 31, 2005, 'A-C', EXTEND(MDY(1,30,2006), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003492', 32, 2005, 'A-C', EXTEND(MDY(2,2,2006), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003492', 33, 2005, 'A-C', EXTEND(MDY(1,31,2006), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003492', 34, 2005, 'A-C', EXTEND(MDY(2,3,2006), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003492', 35, 2005, 'A-C', EXTEND(MDY(6,28,2006), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003492', 36, 2005, 'A-C', EXTEND(MDY(6,26,2006), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003492', 37, 2005, 'A-C', EXTEND(MDY(6,27,2006), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003492', 38, 2005, 'A-C', EXTEND(MDY(6,29,2006), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003492', 39, 2005, 'A-C', EXTEND(MDY(6,30,2006), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003492', 41, 2006, 'B-G', EXTEND(MDY(2,1,2007), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003492', 42, 2006, 'B-G', EXTEND(MDY(2,1,2007), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003492', 44, 2006, 'B-G', EXTEND(MDY(2,1,2007), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003492', 45, 2006, 'B-G', EXTEND(MDY(2,1,2007), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003492', 46, 2006, 'B-G', EXTEND(MDY(2,1,2007), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003515', 30, 2005, 'A-E', EXTEND(MDY(2,1,2006), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003515', 31, 2005, 'A-E', EXTEND(MDY(6,30,2006), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003515', 32, 2005, 'A-E', EXTEND(MDY(2,2,2006), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003515', 33, 2005, 'A-E', EXTEND(MDY(1,31,2006), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003515', 34, 2005, 'A-E', EXTEND(MDY(2,3,2006), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003515', 35, 2005, 'A-C', EXTEND(MDY(6,28,2006), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003515', 37, 2005, 'A-C', EXTEND(MDY(6,27,2006), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003515', 38, 2005, 'A-A', EXTEND(MDY(6,29,2006), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003515', 39, 2005, 'A-C', EXTEND(MDY(6,30,2006), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003515', 41, 2006, 'B-I', EXTEND(MDY(2,1,2007), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003515', 42, 2006, 'A-O', EXTEND(MDY(2,1,2007), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003515', 44, 2006, 'B-I', EXTEND(MDY(2,1,2007), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003515', 45, 2006, 'B-J', EXTEND(MDY(2,1,2007), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003515', 46, 2006, 'B-I', EXTEND(MDY(2,1,2007), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003520', 30, 2005, 'A-C', EXTEND(MDY(6,28,2006), YEAR to SECOND), 1);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003520', 31, 2005, 'A-C', EXTEND(MDY(1,30,2006), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003520', 32, 2005, 'A-C', EXTEND(MDY(6,29,2006), YEAR to SECOND), 1);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003520', 33, 2005, 'A-C', EXTEND(MDY(6,27,2006), YEAR to SECOND), 1);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003520', 34, 2005, 'A-C', EXTEND(MDY(2,3,2006), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003520', 36, 2005, 'A-D', EXTEND(MDY(6,26,2006), YEAR to SECOND), 1);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003520', 39, 2005, 'A-N', EXTEND(MDY(6,30,2006), YEAR to SECOND), 1);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003536', 30, 2005, 'A-G', EXTEND(MDY(2,1,2006), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003536', 31, 2005, 'A-G', EXTEND(MDY(1,30,2006), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003536', 32, 2005, 'A-G', EXTEND(MDY(2,2,2006), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003536', 33, 2005, 'A-G', EXTEND(MDY(1,31,2006), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003536', 34, 2005, 'A-G', EXTEND(MDY(2,3,2006), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003536', 35, 2005, 'A-G', EXTEND(MDY(6,28,2006), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003536', 36, 2005, 'A-G', EXTEND(MDY(6,26,2006), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003536', 37, 2005, 'A-G', EXTEND(MDY(6,27,2006), YEAR to SECOND), 1);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003536', 38, 2005, 'A-G', EXTEND(MDY(6,29,2006), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003536', 39, 2005, 'A-G', EXTEND(MDY(6,30,2006), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003536', 40, 2006, 'B-A', EXTEND(MDY(2,1,2007), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003536', 41, 2006, 'B-C', EXTEND(MDY(2,1,2007), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003536', 42, 2006, 'B-C', EXTEND(MDY(2,1,2007), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003536', 43, 2006, 'B-C', EXTEND(MDY(2,1,2007), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003536', 44, 2006, 'B-E', EXTEND(MDY(2,1,2007), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003541', 30, 2005, 'A-A', EXTEND(MDY(2,1,2006), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003541', 31, 2005, 'A-A', EXTEND(MDY(6,30,2006), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003541', 32, 2005, 'A-A', EXTEND(MDY(2,2,2006), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003541', 33, 2005, 'A-A', EXTEND(MDY(1,31,2006), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003541', 34, 2005, 'A-A', EXTEND(MDY(2,3,2006), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003541', 35, 2005, 'A-A', EXTEND(MDY(6,28,2006), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003541', 37, 2005, 'A-A', EXTEND(MDY(6,27,2006), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003541', 38, 2005, 'A-A', EXTEND(MDY(6,29,2006), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003541', 39, 2005, 'A-A', EXTEND(MDY(6,30,2006), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003541', 40, 2006, 'B-A', EXTEND(MDY(2,1,2007), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003541', 41, 2006, 'B-A', EXTEND(MDY(2,1,2007), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003541', 42, 2006, 'B-A', EXTEND(MDY(2,1,2007), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003541', 43, 2006, 'B-A', EXTEND(MDY(2,1,2007), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003541', 44, 2006, 'B-A', EXTEND(MDY(2,1,2007), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003557', 30, 2005, 'A-C', EXTEND(MDY(2,1,2006), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003557', 31, 2005, 'A-C', EXTEND(MDY(6,30,2006), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003557', 32, 2005, 'A-C', EXTEND(MDY(6,29,2006), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003557', 33, 2005, 'A-C', EXTEND(MDY(6,27,2006), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003557', 34, 2005, 'A-C', EXTEND(MDY(2,3,2006), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003557', 35, 2005, 'A-D', EXTEND(MDY(6,28,2006), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003557', 39, 2005, 'A-N', EXTEND(MDY(6,30,2006), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003557', 40, 2006, 'B-A', EXTEND(MDY(2,1,2007), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003557', 41, 2006, 'B-C', EXTEND(MDY(2,1,2007), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003557', 42, 2006, 'A-N', EXTEND(MDY(2,1,2007), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003557', 43, 2006, 'B-C', EXTEND(MDY(2,1,2007), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003557', 44, 2006, 'B-E', EXTEND(MDY(2,1,2007), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003562', 30, 2005, 'A-D', EXTEND(MDY(6,28,2006), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003562', 31, 2005, 'A-D', EXTEND(MDY(1,30,2006), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003562', 32, 2005, 'A-D', EXTEND(MDY(6,29,2006), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003562', 33, 2005, 'A-D', EXTEND(MDY(1,31,2006), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003562', 34, 2005, 'A-D', EXTEND(MDY(2,3,2006), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003562', 36, 2005, 'A-J', EXTEND(MDY(6,26,2006), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003562', 37, 2005, 'A-J', EXTEND(MDY(6,27,2006), YEAR to SECOND), 1);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003562', 39, 2005, 'A-J', EXTEND(MDY(6,30,2006), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003562', 41, 2006, 'B-E', EXTEND(MDY(2,1,2007), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003562', 42, 2006, 'A-N', EXTEND(MDY(2,1,2007), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003562', 44, 2006, 'B-E', EXTEND(MDY(2,1,2007), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003578', 30, 2005, 'A-E', EXTEND(MDY(6,28,2006), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003578', 31, 2005, 'A-E', EXTEND(MDY(6,30,2006), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003578', 32, 2005, 'A-E', EXTEND(MDY(2,2,2006), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003578', 33, 2005, 'A-E', EXTEND(MDY(1,31,2006), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003578', 34, 2005, 'A-E', EXTEND(MDY(2,3,2006), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003578', 36, 2005, 'A-G', EXTEND(MDY(6,26,2006), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003578', 38, 2005, 'A-I', EXTEND(MDY(6,29,2006), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003578', 39, 2005, 'A-K', EXTEND(MDY(6,30,2006), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003578', 41, 2006, 'B-E', EXTEND(MDY(2,1,2007), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003578', 42, 2006, 'A-N', EXTEND(MDY(2,1,2007), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003578', 44, 2006, 'B-E', EXTEND(MDY(2,1,2007), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003583', 30, 2005, 'A-B', EXTEND(MDY(6,28,2006), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003583', 31, 2005, 'A-B', EXTEND(MDY(2,1,2007), YEAR to SECOND), 1);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003583', 31, 2006, 'A-K', EXTEND(MDY(2,1,2007), YEAR to SECOND), 1);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003583', 32, 2005, 'A-B', EXTEND(MDY(2,2,2006), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003583', 33, 2005, 'A-B', EXTEND(MDY(1,31,2006), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003583', 34, 2005, 'A-B', EXTEND(MDY(2,3,2006), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003583', 37, 2005, 'A-A', EXTEND(MDY(6,27,2006), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003583', 38, 2005, 'A-C', EXTEND(MDY(6,29,2006), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003583', 39, 2005, 'A-M', EXTEND(MDY(6,30,2006), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003583', 41, 2006, 'B-F', EXTEND(MDY(2,1,2007), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003583', 44, 2006, 'B-F', EXTEND(MDY(2,1,2007), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003583', 46, 2006, 'B-F', EXTEND(MDY(2,1,2007), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003599', 30, 2005, 'A-F', EXTEND(MDY(2,1,2006), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003599', 31, 2005, 'A-F', EXTEND(MDY(1,30,2006), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003599', 32, 2005, 'A-F', EXTEND(MDY(2,2,2006), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003599', 33, 2005, 'A-F', EXTEND(MDY(1,31,2006), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003599', 34, 2005, 'A-F', EXTEND(MDY(2,3,2006), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003599', 35, 2005, 'A-F', EXTEND(MDY(6,28,2006), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003599', 36, 2005, 'A-F', EXTEND(MDY(6,26,2006), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003599', 37, 2005, 'A-F', EXTEND(MDY(6,27,2006), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003599', 38, 2005, 'A-F', EXTEND(MDY(6,29,2006), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003599', 39, 2005, 'A-F', EXTEND(MDY(6,30,2006), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003599', 40, 2006, 'B-B', EXTEND(MDY(2,1,2007), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003599', 41, 2006, 'B-B', EXTEND(MDY(2,1,2007), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003599', 42, 2006, 'B-B', EXTEND(MDY(2,1,2007), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003599', 43, 2006, 'B-B', EXTEND(MDY(2,1,2007), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003599', 44, 2006, 'B-B', EXTEND(MDY(2,1,2007), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003606', 30, 2005, 'A-G', EXTEND(MDY(6,28,2006), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003606', 31, 2005, 'A-G', EXTEND(MDY(1,30,2006), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003606', 32, 2005, 'A-G', EXTEND(MDY(2,2,2006), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003606', 33, 2005, 'A-G', EXTEND(MDY(6,27,2006), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003606', 34, 2005, 'A-G', EXTEND(MDY(2,3,2006), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003606', 36, 2005, 'A-J', EXTEND(MDY(6,26,2006), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003606', 39, 2005, 'A-L', EXTEND(MDY(6,30,2006), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003606', 41, 2006, 'B-E', EXTEND(MDY(2,1,2007), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003606', 42, 2006, 'A-N', EXTEND(MDY(2,1,2007), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003606', 44, 2006, 'B-E', EXTEND(MDY(2,1,2007), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003611', 30, 2005, 'A-C', EXTEND(MDY(2,1,2006), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003611', 31, 2005, 'A-C', EXTEND(MDY(2,1,2007), YEAR to SECOND), 1);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003611', 31, 2006, 'A-K', EXTEND(MDY(2,1,2007), YEAR to SECOND), 1);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003611', 32, 2005, 'A-C', EXTEND(MDY(2,2,2006), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003611', 33, 2005, 'A-C', EXTEND(MDY(1,31,2006), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003611', 34, 2005, 'A-C', EXTEND(MDY(2,3,2006), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003611', 35, 2005, 'A-A', EXTEND(MDY(6,28,2006), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003611', 36, 2005, 'A-A', EXTEND(MDY(6,26,2006), YEAR to SECOND), 1);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003611', 37, 2005, 'A-A', EXTEND(MDY(6,27,2006), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003611', 38, 2005, 'A-A', EXTEND(MDY(6,29,2006), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003611', 39, 2005, 'A-A', EXTEND(MDY(6,30,2006), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003611', 41, 2006, 'B-F', EXTEND(MDY(2,1,2007), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003611', 44, 2006, 'B-H', EXTEND(MDY(2,1,2007), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003611', 45, 2006, 'B-F', EXTEND(MDY(2,1,2007), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003611', 46, 2006, 'B-F', EXTEND(MDY(2,1,2007), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003627', 30, 2005, 'A-I', EXTEND(MDY(2,1,2006), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003627', 31, 2005, 'A-I', EXTEND(MDY(1,30,2006), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003627', 32, 2005, 'A-I', EXTEND(MDY(2,2,2006), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003627', 33, 2005, 'A-I', EXTEND(MDY(1,31,2006), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003627', 34, 2005, 'A-I', EXTEND(MDY(2,3,2006), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003627', 35, 2005, 'A-I', EXTEND(MDY(6,28,2006), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003627', 36, 2005, 'A-I', EXTEND(MDY(6,26,2006), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003627', 37, 2005, 'A-I', EXTEND(MDY(6,27,2006), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003627', 38, 2005, 'A-I', EXTEND(MDY(6,29,2006), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003627', 39, 2005, 'A-I', EXTEND(MDY(6,30,2006), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003627', 41, 2006, 'B-J', EXTEND(MDY(2,1,2007), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003627', 42, 2006, 'B-J', EXTEND(MDY(2,1,2007), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003627', 44, 2006, 'B-J', EXTEND(MDY(2,1,2007), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003627', 45, 2006, 'B-J', EXTEND(MDY(2,1,2007), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003627', 46, 2006, 'B-J', EXTEND(MDY(2,1,2007), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003632', 30, 2005, 'A-K', EXTEND(MDY(2,1,2006), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003632', 31, 2005, 'A-K', EXTEND(MDY(1,30,2006), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003632', 32, 2005, 'A-K', EXTEND(MDY(2,2,2006), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003632', 33, 2005, 'A-K', EXTEND(MDY(1,31,2006), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003632', 34, 2005, 'A-K', EXTEND(MDY(2,3,2006), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003632', 35, 2005, 'A-H', EXTEND(MDY(6,28,2006), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003632', 36, 2005, 'A-H', EXTEND(MDY(6,26,2006), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003632', 37, 2005, 'A-H', EXTEND(MDY(6,27,2006), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003632', 38, 2005, 'A-H', EXTEND(MDY(6,29,2006), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003632', 39, 2005, 'A-H', EXTEND(MDY(6,30,2006), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003632', 41, 2006, 'B-J', EXTEND(MDY(2,1,2007), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003632', 42, 2006, 'B-J', EXTEND(MDY(2,1,2007), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003632', 44, 2006, 'B-J', EXTEND(MDY(2,1,2007), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003632', 45, 2006, 'B-J', EXTEND(MDY(2,1,2007), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003632', 46, 2006, 'B-J', EXTEND(MDY(2,1,2007), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003648', 30, 2005, 'A-C', EXTEND(MDY(2,1,2006), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003648', 31, 2005, 'A-C', EXTEND(MDY(1,30,2006), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003648', 32, 2005, 'A-C', EXTEND(MDY(2,2,2006), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003648', 33, 2005, 'A-C', EXTEND(MDY(1,31,2006), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003648', 34, 2005, 'A-C', EXTEND(MDY(2,3,2006), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003648', 35, 2005, 'A-C', EXTEND(MDY(6,28,2006), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003648', 36, 2005, 'A-C', EXTEND(MDY(6,26,2006), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003648', 37, 2005, 'A-C', EXTEND(MDY(6,27,2006), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003648', 38, 2005, 'A-C', EXTEND(MDY(6,29,2006), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003648', 39, 2005, 'A-C', EXTEND(MDY(6,30,2006), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003648', 40, 2006, 'B-D', EXTEND(MDY(2,1,2007), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003648', 41, 2006, 'B-D', EXTEND(MDY(2,1,2007), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003648', 42, 2006, 'B-D', EXTEND(MDY(2,1,2007), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003648', 43, 2006, 'B-D', EXTEND(MDY(2,1,2007), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003648', 44, 2006, 'B-D', EXTEND(MDY(2,1,2007), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003653', 30, 2005, 'A-I', EXTEND(MDY(2,1,2006), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003653', 31, 2005, 'A-I', EXTEND(MDY(1,30,2006), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003653', 32, 2005, 'A-I', EXTEND(MDY(2,2,2006), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003653', 33, 2005, 'A-I', EXTEND(MDY(1,31,2006), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003653', 34, 2005, 'A-I', EXTEND(MDY(2,3,2006), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003653', 35, 2005, 'A-I', EXTEND(MDY(6,28,2006), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003653', 36, 2005, 'A-I', EXTEND(MDY(6,26,2006), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003653', 37, 2005, 'A-I', EXTEND(MDY(6,27,2006), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003653', 38, 2005, 'A-I', EXTEND(MDY(6,29,2006), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003653', 39, 2005, 'A-I', EXTEND(MDY(6,30,2006), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003653', 40, 2006, 'B-D', EXTEND(MDY(2,1,2007), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003653', 41, 2006, 'B-D', EXTEND(MDY(2,1,2007), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003653', 42, 2006, 'B-D', EXTEND(MDY(2,1,2007), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003653', 43, 2006, 'B-D', EXTEND(MDY(2,1,2007), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003653', 44, 2006, 'B-D', EXTEND(MDY(2,1,2007), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003669', 30, 2005, 'A-F', EXTEND(MDY(2,1,2006), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003669', 31, 2005, 'A-F', EXTEND(MDY(1,30,2006), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003669', 32, 2005, 'A-F', EXTEND(MDY(2,2,2006), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003669', 33, 2005, 'A-F', EXTEND(MDY(1,31,2006), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003669', 34, 2005, 'A-F', EXTEND(MDY(2,3,2006), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003669', 35, 2005, 'A-F', EXTEND(MDY(6,28,2006), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003669', 36, 2005, 'A-F', EXTEND(MDY(6,26,2006), YEAR to SECOND), 1);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003669', 37, 2005, 'A-F', EXTEND(MDY(6,27,2006), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003669', 38, 2005, 'A-F', EXTEND(MDY(6,29,2006), YEAR to SECOND), 1);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003669', 39, 2005, 'A-F', EXTEND(MDY(6,30,2006), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003669', 41, 2006, 'B-J', EXTEND(MDY(2,1,2007), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003669', 42, 2006, 'A-O', EXTEND(MDY(2,1,2007), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003669', 44, 2006, 'B-K', EXTEND(MDY(2,1,2007), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003669', 45, 2006, 'B-J', EXTEND(MDY(2,1,2007), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003674', 30, 2005, 'A-F', EXTEND(MDY(2,1,2007), YEAR to SECOND), 1);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003674', 30, 2006, 'A-K', EXTEND(MDY(2,1,2007), YEAR to SECOND), 1);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003674', 31, 2005, 'A-F', EXTEND(MDY(2,1,2007), YEAR to SECOND), 1);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003674', 31, 2006, 'A-K', EXTEND(MDY(2,1,2007), YEAR to SECOND), 1);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003674', 32, 2005, 'A-F', EXTEND(MDY(6,29,2006), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003674', 33, 2005, 'A-F', EXTEND(MDY(1,31,2006), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003674', 34, 2005, 'A-F', EXTEND(MDY(2,3,2006), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003674', 36, 2005, 'A-E', EXTEND(MDY(6,26,2006), YEAR to SECOND), 1);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003674', 39, 2005, 'A-M', EXTEND(MDY(6,30,2006), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003674', 41, 2006, 'B-H', EXTEND(MDY(2,1,2007), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003674', 44, 2006, 'B-H', EXTEND(MDY(2,1,2007), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003695', 30, 2005, 'A-E', EXTEND(MDY(6,16,2005), YEAR to SECOND), 1);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003695', 30, 2006, 'A-K', EXTEND(MDY(2,1,2007), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003695', 31, 2005, 'A-E', EXTEND(MDY(6,16,2006), YEAR to SECOND), 1);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003695', 31, 2006, 'A-K', EXTEND(MDY(2,1,2007), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003695', 32, 2005, 'A-E', EXTEND(MDY(2,2,2006), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003695', 33, 2005, 'A-E', EXTEND(MDY(1,31,2006), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003695', 34, 2005, 'A-E', EXTEND(MDY(2,3,2006), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003695', 36, 2005, 'A-E', EXTEND(MDY(6,26,2006), YEAR to SECOND), 1);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003695', 38, 2005, 'A-C', EXTEND(MDY(6,29,2006), YEAR to SECOND), 1);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003695', 39, 2005, 'A-M', EXTEND(MDY(6,30,2006), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003695', 41, 2006, 'B-E', EXTEND(MDY(2,1,2007), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003695', 44, 2006, 'B-E', EXTEND(MDY(2,1,2007), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003702', 30, 2005, 'A-D', EXTEND(MDY(2,1,2006), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003702', 31, 2005, 'A-D', EXTEND(MDY(1,30,2006), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003702', 32, 2005, 'A-D', EXTEND(MDY(2,2,2006), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003702', 33, 2005, 'A-D', EXTEND(MDY(6,27,2006), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003702', 34, 2005, 'A-D', EXTEND(MDY(2,3,2006), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003702', 35, 2005, 'A-C', EXTEND(MDY(6,28,2006), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003702', 36, 2005, 'A-C', EXTEND(MDY(6,26,2006), YEAR to SECOND), 1);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003702', 39, 2005, 'A-C', EXTEND(MDY(6,30,2006), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003702', 40, 2006, 'B-A', EXTEND(MDY(2,1,2007), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003702', 41, 2006, 'B-E', EXTEND(MDY(2,1,2007), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003702', 42, 2006, 'A-N', EXTEND(MDY(2,1,2007), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003702', 43, 2006, 'B-A', EXTEND(MDY(2,1,2007), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003702', 44, 2006, 'B-E', EXTEND(MDY(2,1,2007), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003718', 30, 2006, 'A-D', EXTEND(MDY(2,1,2007), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003718', 31, 2006, 'A-D', EXTEND(MDY(2,1,2007), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003718', 32, 2006, 'A-D', EXTEND(MDY(2,1,2007), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003718', 33, 2006, 'A-D', EXTEND(MDY(2,1,2007), YEAR to SECOND), 1);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003718', 34, 2006, 'A-D', EXTEND(MDY(2,1,2007), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003723', 30, 2006, 'A-J', EXTEND(MDY(2,1,2007), YEAR to SECOND), 1);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003723', 31, 2006, 'A-J', EXTEND(MDY(2,1,2007), YEAR to SECOND), 1);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003723', 32, 2006, 'A-J', EXTEND(MDY(2,1,2007), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003723', 33, 2006, 'A-J', EXTEND(MDY(2,1,2007), YEAR to SECOND), 1);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003723', 34, 2006, 'A-J', EXTEND(MDY(2,1,2007), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003739', 30, 2006, 'A-F', EXTEND(MDY(2,1,2007), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003739', 31, 2006, 'A-F', EXTEND(MDY(2,1,2007), YEAR to SECOND), 1);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003739', 32, 2006, 'A-F', EXTEND(MDY(2,1,2007), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003739', 33, 2006, 'A-F', EXTEND(MDY(2,1,2007), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003739', 34, 2006, 'A-F', EXTEND(MDY(2,1,2007), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003744', 30, 2006, 'A-C', EXTEND(MDY(2,1,2007), YEAR to SECOND), 1);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003744', 31, 2006, 'A-C', EXTEND(MDY(2,1,2007), YEAR to SECOND), 1);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003744', 32, 2006, 'A-C', EXTEND(MDY(2,1,2007), YEAR to SECOND), 1);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003744', 33, 2006, 'A-C', EXTEND(MDY(2,1,2007), YEAR to SECOND), 1);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003744', 34, 2006, 'A-C', EXTEND(MDY(2,1,2007), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003765', 30, 2006, 'A-G', EXTEND(MDY(2,1,2007), YEAR to SECOND), 1);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003765', 31, 2006, 'A-G', EXTEND(MDY(2,1,2007), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003765', 32, 2006, 'A-G', EXTEND(MDY(2,1,2007), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003765', 33, 2006, 'A-G', EXTEND(MDY(2,1,2007), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003765', 34, 2006, 'A-G', EXTEND(MDY(2,1,2007), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003770', 30, 2006, 'A-H', EXTEND(MDY(2,1,2007), YEAR to SECOND), 1);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003770', 31, 2006, 'A-H', EXTEND(MDY(2,1,2007), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003770', 32, 2006, 'A-H', EXTEND(MDY(2,1,2007), YEAR to SECOND), 1);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003770', 33, 2006, 'A-H', EXTEND(MDY(2,1,2007), YEAR to SECOND), 1);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003770', 34, 2006, 'A-H', EXTEND(MDY(2,1,2007), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003786', 30, 2006, 'A-C', EXTEND(MDY(2,1,2007), YEAR to SECOND), 1);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003786', 31, 2006, 'A-C', EXTEND(MDY(2,1,2007), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003786', 32, 2006, 'A-C', EXTEND(MDY(2,1,2007), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003786', 33, 2006, 'A-C', EXTEND(MDY(2,1,2007), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003786', 34, 2006, 'A-C', EXTEND(MDY(2,1,2007), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003791', 30, 2006, 'A-D', EXTEND(MDY(2,1,2007), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003791', 31, 2006, 'A-D', EXTEND(MDY(2,1,2007), YEAR to SECOND), 1);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003791', 32, 2006, 'A-D', EXTEND(MDY(2,1,2007), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003791', 33, 2006, 'A-D', EXTEND(MDY(2,1,2007), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003791', 34, 2006, 'A-D', EXTEND(MDY(2,1,2007), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003809', 30, 2006, 'A-F', EXTEND(MDY(2,1,2007), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003809', 31, 2006, 'A-F', EXTEND(MDY(2,1,2007), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003809', 32, 2006, 'A-F', EXTEND(MDY(2,1,2007), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003809', 33, 2006, 'A-F', EXTEND(MDY(2,1,2007), YEAR to SECOND), 1);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003809', 34, 2006, 'A-F', EXTEND(MDY(2,1,2007), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003814', 30, 2006, 'A-E', EXTEND(MDY(2,1,2007), YEAR to SECOND), 1);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003814', 31, 2006, 'A-E', EXTEND(MDY(2,1,2007), YEAR to SECOND), 1);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003814', 32, 2006, 'A-E', EXTEND(MDY(2,1,2007), YEAR to SECOND), 1);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003814', 33, 2006, 'A-E', EXTEND(MDY(2,1,2007), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003814', 34, 2006, 'A-E', EXTEND(MDY(2,1,2007), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003835', 30, 2006, 'A-G', EXTEND(MDY(2,1,2007), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003835', 31, 2006, 'A-G', EXTEND(MDY(2,1,2007), YEAR to SECOND), 1);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003835', 32, 2006, 'A-G', EXTEND(MDY(2,1,2007), YEAR to SECOND), 1);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003835', 33, 2006, 'A-G', EXTEND(MDY(2,1,2007), YEAR to SECOND), 1);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003835', 34, 2006, 'A-G', EXTEND(MDY(2,1,2007), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003840', 30, 2006, 'A-D', EXTEND(MDY(2,1,2007), YEAR to SECOND), 1);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003840', 31, 2006, 'A-D', EXTEND(MDY(2,1,2007), YEAR to SECOND), 1);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003840', 32, 2006, 'A-D', EXTEND(MDY(2,1,2007), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003840', 33, 2006, 'A-D', EXTEND(MDY(2,1,2007), YEAR to SECOND), 1);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003840', 34, 2006, 'A-D', EXTEND(MDY(2,1,2007), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003856', 30, 2006, 'A-J', EXTEND(MDY(2,1,2007), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003856', 31, 2006, 'A-J', EXTEND(MDY(2,1,2007), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003856', 32, 2006, 'A-J', EXTEND(MDY(2,1,2007), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003856', 33, 2006, 'A-J', EXTEND(MDY(2,1,2007), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003856', 34, 2006, 'A-J', EXTEND(MDY(2,1,2007), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003861', 30, 2006, 'A-B', EXTEND(MDY(2,1,2007), YEAR to SECOND), 1);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003861', 31, 2006, 'A-B', EXTEND(MDY(2,1,2007), YEAR to SECOND), 1);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003861', 32, 2006, 'A-B', EXTEND(MDY(2,1,2007), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003861', 33, 2006, 'A-B', EXTEND(MDY(2,1,2007), YEAR to SECOND), 1);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003861', 34, 2006, 'A-B', EXTEND(MDY(2,1,2007), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003877', 30, 2006, 'A-D', EXTEND(MDY(2,1,2007), YEAR to SECOND), 1);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003877', 31, 2006, 'A-D', EXTEND(MDY(2,1,2007), YEAR to SECOND), 1);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003877', 32, 2006, 'A-D', EXTEND(MDY(2,1,2007), YEAR to SECOND), 1);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003877', 33, 2006, 'A-D', EXTEND(MDY(2,1,2007), YEAR to SECOND), 1);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003877', 34, 2006, 'A-D', EXTEND(MDY(2,1,2007), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003882', 30, 2006, 'A-C', EXTEND(MDY(2,1,2007), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003882', 31, 2006, 'A-C', EXTEND(MDY(2,1,2007), YEAR to SECOND), 1);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003882', 32, 2006, 'A-C', EXTEND(MDY(2,1,2007), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003882', 33, 2006, 'A-C', EXTEND(MDY(2,1,2007), YEAR to SECOND), 1);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003882', 34, 2006, 'A-C', EXTEND(MDY(2,1,2007), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003898', 30, 2006, 'A-J', EXTEND(MDY(2,1,2007), YEAR to SECOND), 1);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003898', 31, 2006, 'A-J', EXTEND(MDY(2,1,2007), YEAR to SECOND), 1);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003898', 32, 2006, 'A-J', EXTEND(MDY(2,1,2007), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003898', 33, 2006, 'A-J', EXTEND(MDY(2,1,2007), YEAR to SECOND), 1);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003898', 34, 2006, 'A-J', EXTEND(MDY(2,1,2007), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003905', 30, 2006, 'A-D', EXTEND(MDY(2,1,2007), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003905', 31, 2006, 'A-D', EXTEND(MDY(2,1,2007), YEAR to SECOND), 1);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003905', 32, 2006, 'A-D', EXTEND(MDY(2,1,2007), YEAR to SECOND), 1);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003905', 33, 2006, 'A-D', EXTEND(MDY(2,1,2007), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003905', 34, 2006, 'A-D', EXTEND(MDY(2,1,2007), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003910', 30, 2006, 'A-I', EXTEND(MDY(2,1,2007), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003910', 31, 2006, 'A-I', EXTEND(MDY(2,1,2007), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003910', 32, 2006, 'A-I', EXTEND(MDY(2,1,2007), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003910', 33, 2006, 'A-I', EXTEND(MDY(2,1,2007), YEAR to SECOND), 1);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003910', 34, 2006, 'A-I', EXTEND(MDY(2,1,2007), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003926', 30, 2006, 'A-G', EXTEND(MDY(2,1,2007), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003926', 31, 2006, 'A-G', EXTEND(MDY(2,1,2007), YEAR to SECOND), 1);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003926', 32, 2006, 'A-G', EXTEND(MDY(2,1,2007), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003926', 33, 2006, 'A-G', EXTEND(MDY(2,1,2007), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003926', 34, 2006, 'A-G', EXTEND(MDY(2,1,2007), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003931', 30, 2006, 'A-J', EXTEND(MDY(2,1,2007), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003931', 31, 2006, 'A-J', EXTEND(MDY(2,1,2007), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003931', 32, 2006, 'A-J', EXTEND(MDY(2,1,2007), YEAR to SECOND), 1);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003931', 33, 2006, 'A-J', EXTEND(MDY(2,1,2007), YEAR to SECOND), 1);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003931', 34, 2006, 'A-J', EXTEND(MDY(2,1,2007), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003947', 30, 2006, 'A-J', EXTEND(MDY(2,1,2007), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003947', 31, 2006, 'A-J', EXTEND(MDY(2,1,2007), YEAR to SECOND), 1);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003947', 32, 2006, 'A-J', EXTEND(MDY(2,1,2007), YEAR to SECOND), 1);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003947', 33, 2006, 'A-J', EXTEND(MDY(2,1,2007), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003947', 34, 2006, 'A-J', EXTEND(MDY(2,1,2007), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003952', 30, 2006, 'A-J', EXTEND(MDY(2,1,2007), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003952', 31, 2006, 'A-J', EXTEND(MDY(2,1,2007), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003952', 32, 2006, 'A-J', EXTEND(MDY(2,1,2007), YEAR to SECOND), 1);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003952', 33, 2006, 'A-J', EXTEND(MDY(2,1,2007), YEAR to SECOND), 1);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003952', 34, 2006, 'A-J', EXTEND(MDY(2,1,2007), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003968', 30, 2006, 'A-E', EXTEND(MDY(2,1,2007), YEAR to SECOND), 1);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003968', 31, 2006, 'A-E', EXTEND(MDY(2,1,2007), YEAR to SECOND), 1);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003968', 32, 2006, 'A-E', EXTEND(MDY(2,1,2007), YEAR to SECOND), 1);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003968', 33, 2006, 'A-E', EXTEND(MDY(2,1,2007), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003968', 34, 2006, 'A-E', EXTEND(MDY(2,1,2007), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003973', 30, 2006, 'A-J', EXTEND(MDY(2,1,2007), YEAR to SECOND), 1);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003973', 31, 2006, 'A-J', EXTEND(MDY(2,1,2007), YEAR to SECOND), 1);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003973', 32, 2006, 'A-J', EXTEND(MDY(2,1,2007), YEAR to SECOND), 1);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003973', 33, 2006, 'A-J', EXTEND(MDY(2,1,2007), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003973', 34, 2006, 'A-J', EXTEND(MDY(2,1,2007), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003989', 30, 2006, 'A-I', EXTEND(MDY(2,1,2007), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003989', 31, 2006, 'A-I', EXTEND(MDY(2,1,2007), YEAR to SECOND), 1);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003989', 32, 2006, 'A-I', EXTEND(MDY(2,1,2007), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003989', 33, 2006, 'A-I', EXTEND(MDY(2,1,2007), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003989', 34, 2006, 'A-I', EXTEND(MDY(2,1,2007), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003994', 30, 2006, 'A-H', EXTEND(MDY(2,1,2007), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003994', 31, 2006, 'A-H', EXTEND(MDY(2,1,2007), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003994', 32, 2006, 'A-H', EXTEND(MDY(2,1,2007), YEAR to SECOND), 1);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003994', 33, 2006, 'A-H', EXTEND(MDY(2,1,2007), YEAR to SECOND), 1);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555003994', 34, 2006, 'A-H', EXTEND(MDY(2,1,2007), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004005', 30, 2006, 'A-B', EXTEND(MDY(2,1,2007), YEAR to SECOND), 1);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004005', 31, 2006, 'A-B', EXTEND(MDY(2,1,2007), YEAR to SECOND), 1);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004005', 32, 2006, 'A-B', EXTEND(MDY(2,1,2007), YEAR to SECOND), 1);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004005', 33, 2006, 'A-B', EXTEND(MDY(2,1,2007), YEAR to SECOND), 1);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004005', 34, 2006, 'A-B', EXTEND(MDY(2,1,2007), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004010', 30, 2006, 'A-D', EXTEND(MDY(2,1,2007), YEAR to SECOND), 1);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004010', 31, 2006, 'A-D', EXTEND(MDY(2,1,2007), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004010', 32, 2006, 'A-D', EXTEND(MDY(2,1,2007), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004010', 33, 2006, 'A-D', EXTEND(MDY(2,1,2007), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004010', 34, 2006, 'A-D', EXTEND(MDY(2,1,2007), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004026', 30, 2006, 'A-A', EXTEND(MDY(2,1,2007), YEAR to SECOND), 1);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004026', 31, 2006, 'A-A', EXTEND(MDY(2,1,2007), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004026', 32, 2006, 'A-A', EXTEND(MDY(2,1,2007), YEAR to SECOND), 1);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004026', 33, 2006, 'A-A', EXTEND(MDY(2,1,2007), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004026', 34, 2006, 'A-A', EXTEND(MDY(2,1,2007), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004031', 30, 2006, 'A-E', EXTEND(MDY(2,1,2007), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004031', 31, 2006, 'A-E', EXTEND(MDY(2,1,2007), YEAR to SECOND), 1);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004031', 32, 2006, 'A-E', EXTEND(MDY(2,1,2007), YEAR to SECOND), 1);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004031', 33, 2006, 'A-E', EXTEND(MDY(2,1,2007), YEAR to SECOND), 1);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004031', 34, 2006, 'A-E', EXTEND(MDY(2,1,2007), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004047', 30, 2006, 'A-H', EXTEND(MDY(2,1,2007), YEAR to SECOND), 1);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004047', 31, 2006, 'A-H', EXTEND(MDY(2,1,2007), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004047', 32, 2006, 'A-H', EXTEND(MDY(2,1,2007), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004047', 33, 2006, 'A-H', EXTEND(MDY(2,1,2007), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004047', 34, 2006, 'A-H', EXTEND(MDY(2,1,2007), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004052', 30, 2006, 'A-F', EXTEND(MDY(2,1,2007), YEAR to SECOND), 1);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004052', 31, 2006, 'A-F', EXTEND(MDY(2,1,2007), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004052', 32, 2006, 'A-F', EXTEND(MDY(2,1,2007), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004052', 33, 2006, 'A-F', EXTEND(MDY(2,1,2007), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004052', 34, 2006, 'A-F', EXTEND(MDY(2,1,2007), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004068', 30, 2006, 'A-C', EXTEND(MDY(2,1,2007), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004068', 31, 2006, 'A-C', EXTEND(MDY(2,1,2007), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004068', 32, 2006, 'A-C', EXTEND(MDY(2,1,2007), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004068', 33, 2006, 'A-C', EXTEND(MDY(2,1,2007), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004068', 34, 2006, 'A-C', EXTEND(MDY(2,1,2007), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004073', 30, 2006, 'A-J', EXTEND(MDY(2,1,2007), YEAR to SECOND), 1);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004073', 31, 2006, 'A-J', EXTEND(MDY(2,1,2007), YEAR to SECOND), 1);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004073', 32, 2006, 'A-J', EXTEND(MDY(2,1,2007), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004073', 33, 2006, 'A-J', EXTEND(MDY(2,1,2007), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004073', 34, 2006, 'A-J', EXTEND(MDY(2,1,2007), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004089', 30, 2006, 'A-F', EXTEND(MDY(2,1,2007), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004089', 31, 2006, 'A-F', EXTEND(MDY(2,1,2007), YEAR to SECOND), 1);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004089', 32, 2006, 'A-F', EXTEND(MDY(2,1,2007), YEAR to SECOND), 1);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004089', 33, 2006, 'A-F', EXTEND(MDY(2,1,2007), YEAR to SECOND), 1);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004089', 34, 2006, 'A-F', EXTEND(MDY(2,1,2007), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004094', 30, 2006, 'A-A', EXTEND(MDY(2,1,2007), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004094', 31, 2006, 'A-A', EXTEND(MDY(2,1,2007), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004094', 32, 2006, 'A-A', EXTEND(MDY(2,1,2007), YEAR to SECOND), 1);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004094', 33, 2006, 'A-A', EXTEND(MDY(2,1,2007), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004094', 34, 2006, 'A-A', EXTEND(MDY(2,1,2007), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004101', 30, 2006, 'A-G', EXTEND(MDY(2,1,2007), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004101', 31, 2006, 'A-G', EXTEND(MDY(2,1,2007), YEAR to SECOND), 1);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004101', 32, 2006, 'A-G', EXTEND(MDY(2,1,2007), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004101', 33, 2006, 'A-G', EXTEND(MDY(2,1,2007), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004101', 34, 2006, 'A-G', EXTEND(MDY(2,1,2007), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004117', 30, 2006, 'A-D', EXTEND(MDY(2,1,2007), YEAR to SECOND), 1);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004117', 31, 2006, 'A-D', EXTEND(MDY(2,1,2007), YEAR to SECOND), 1);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004117', 32, 2006, 'A-D', EXTEND(MDY(2,1,2007), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004117', 33, 2006, 'A-D', EXTEND(MDY(2,1,2007), YEAR to SECOND), 1);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004117', 34, 2006, 'A-D', EXTEND(MDY(2,1,2007), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004122', 30, 2006, 'A-E', EXTEND(MDY(2,1,2007), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004122', 31, 2006, 'A-E', EXTEND(MDY(2,1,2007), YEAR to SECOND), 1);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004122', 32, 2006, 'A-E', EXTEND(MDY(2,1,2007), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004122', 33, 2006, 'A-E', EXTEND(MDY(2,1,2007), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004122', 34, 2006, 'A-E', EXTEND(MDY(2,1,2007), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004138', 30, 2006, 'A-B', EXTEND(MDY(2,1,2007), YEAR to SECOND), 1);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004138', 31, 2006, 'A-B', EXTEND(MDY(2,1,2007), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004138', 32, 2006, 'A-B', EXTEND(MDY(2,1,2007), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004138', 33, 2006, 'A-B', EXTEND(MDY(2,1,2007), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004138', 34, 2006, 'A-B', EXTEND(MDY(2,1,2007), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004143', 30, 2006, 'A-C', EXTEND(MDY(2,1,2007), YEAR to SECOND), 1);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004143', 31, 2006, 'A-C', EXTEND(MDY(2,1,2007), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004143', 32, 2006, 'A-C', EXTEND(MDY(2,1,2007), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004143', 33, 2006, 'A-C', EXTEND(MDY(2,1,2007), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004143', 34, 2006, 'A-C', EXTEND(MDY(2,1,2007), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004159', 30, 2006, 'A-I', EXTEND(MDY(2,1,2007), YEAR to SECOND), 1);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004159', 31, 2006, 'A-I', EXTEND(MDY(2,1,2007), YEAR to SECOND), 1);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004159', 32, 2006, 'A-I', EXTEND(MDY(2,1,2007), YEAR to SECOND), 1);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004159', 33, 2006, 'A-I', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004159', 34, 2006, 'A-I', EXTEND(MDY(2,1,2007), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004164', 30, 2006, 'A-H', EXTEND(MDY(2,1,2007), YEAR to SECOND), 1);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004164', 31, 2006, 'A-H', EXTEND(MDY(2,1,2007), YEAR to SECOND), 1);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004164', 32, 2006, 'A-H', EXTEND(MDY(2,1,2007), YEAR to SECOND), 1);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004164', 33, 2006, 'A-H', EXTEND(MDY(2,1,2007), YEAR to SECOND), 1);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004164', 34, 2006, 'A-H', EXTEND(MDY(2,1,2007), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004185', 30, 2006, 'A-E', EXTEND(MDY(2,1,2007), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004185', 31, 2006, 'A-E', EXTEND(MDY(2,1,2007), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004185', 32, 2006, 'A-E', EXTEND(MDY(2,1,2007), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004185', 33, 2006, 'A-E', EXTEND(MDY(2,1,2007), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004185', 34, 2006, 'A-E', EXTEND(MDY(2,1,2007), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004190', 30, 2006, 'A-C', EXTEND(MDY(2,1,2007), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004190', 31, 2006, 'A-C', EXTEND(MDY(2,1,2007), YEAR to SECOND), 1);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004190', 32, 2006, 'A-C', EXTEND(MDY(2,1,2007), YEAR to SECOND), 1);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004190', 33, 2006, 'A-C', EXTEND(MDY(2,1,2007), YEAR to SECOND), 1);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004190', 34, 2006, 'A-C', EXTEND(MDY(2,1,2007), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004208', 30, 2006, 'A-B', EXTEND(MDY(2,1,2007), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004208', 31, 2006, 'A-B', EXTEND(MDY(2,1,2007), YEAR to SECOND), 1);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004208', 32, 2006, 'A-B', EXTEND(MDY(2,1,2007), YEAR to SECOND), 1);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004208', 33, 2006, 'A-B', EXTEND(MDY(2,1,2007), YEAR to SECOND), 1);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004208', 34, 2006, 'A-B', EXTEND(MDY(2,1,2007), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004213', 30, 2006, 'A-D', EXTEND(MDY(2,1,2007), YEAR to SECOND), 1);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004213', 31, 2006, 'A-D', EXTEND(MDY(2,1,2007), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004213', 32, 2006, 'A-D', EXTEND(MDY(2,1,2007), YEAR to SECOND), 1);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004213', 33, 2006, 'A-D', EXTEND(MDY(2,1,2007), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004213', 34, 2006, 'A-D', EXTEND(MDY(2,1,2007), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004229', 30, 2006, 'A-G', EXTEND(MDY(2,1,2007), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004229', 31, 2006, 'A-G', EXTEND(MDY(2,1,2007), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004229', 32, 2006, 'A-G', EXTEND(MDY(2,1,2007), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004229', 33, 2006, 'A-G', EXTEND(MDY(2,1,2007), YEAR to SECOND), 1);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004229', 34, 2006, 'A-G', EXTEND(MDY(2,1,2007), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004234', 30, 2006, 'A-D', EXTEND(MDY(2,1,2007), YEAR to SECOND), 1);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004234', 31, 2006, 'A-D', EXTEND(MDY(2,1,2007), YEAR to SECOND), 1);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004234', 32, 2006, 'A-D', EXTEND(MDY(2,1,2007), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004234', 33, 2006, 'A-D', EXTEND(MDY(2,1,2007), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004234', 34, 2006, 'A-D', EXTEND(MDY(2,1,2007), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004255', 30, 2006, 'A-D', EXTEND(MDY(2,1,2007), YEAR to SECOND), 1);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004255', 31, 2006, 'A-D', EXTEND(MDY(2,1,2007), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004255', 32, 2006, 'A-D', EXTEND(MDY(2,1,2007), YEAR to SECOND), 1);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004255', 33, 2006, 'A-D', EXTEND(MDY(2,1,2007), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004255', 34, 2006, 'A-D', EXTEND(MDY(2,1,2007), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004260', 30, 2006, 'A-H', EXTEND(MDY(2,1,2007), YEAR to SECOND), 1);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004260', 31, 2006, 'A-H', EXTEND(MDY(2,1,2007), YEAR to SECOND), 1);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004260', 32, 2006, 'A-H', EXTEND(MDY(2,1,2007), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004260', 33, 2006, 'A-H', EXTEND(MDY(2,1,2007), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004260', 34, 2006, 'A-H', EXTEND(MDY(2,1,2007), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004276', 30, 2006, 'A-G', EXTEND(MDY(2,1,2007), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004276', 31, 2006, 'A-G', EXTEND(MDY(2,1,2007), YEAR to SECOND), 1);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004276', 32, 2006, 'A-G', EXTEND(MDY(2,1,2007), YEAR to SECOND), 1);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004276', 33, 2006, 'A-G', EXTEND(MDY(2,1,2007), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004276', 34, 2006, 'A-G', EXTEND(MDY(2,1,2007), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004281', 30, 2006, 'A-A', EXTEND(MDY(2,1,2007), YEAR to SECOND), 1);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004281', 31, 2006, 'A-A', EXTEND(MDY(2,1,2007), YEAR to SECOND), 1);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004281', 32, 2006, 'A-A', EXTEND(MDY(2,1,2007), YEAR to SECOND), 1);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004281', 33, 2006, 'A-A', EXTEND(MDY(2,1,2007), YEAR to SECOND), 1);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004281', 34, 2006, 'A-A', EXTEND(MDY(2,1,2007), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004297', 30, 2006, 'A-D', EXTEND(MDY(2,1,2007), YEAR to SECOND), 1);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004297', 31, 2006, 'A-D', EXTEND(MDY(2,1,2007), YEAR to SECOND), 1);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004297', 32, 2006, 'A-D', EXTEND(MDY(2,1,2007), YEAR to SECOND), 1);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004297', 33, 2006, 'A-D', EXTEND(MDY(2,1,2007), YEAR to SECOND), 1);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004297', 34, 2006, 'A-D', EXTEND(MDY(2,1,2007), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004304', 30, 2006, 'A-C', EXTEND(MDY(2,1,2007), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004304', 31, 2006, 'A-C', EXTEND(MDY(2,1,2007), YEAR to SECOND), 1);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004304', 32, 2006, 'A-C', EXTEND(MDY(2,1,2007), YEAR to SECOND), 1);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004304', 33, 2006, 'A-C', EXTEND(MDY(2,1,2007), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004304', 34, 2006, 'A-C', EXTEND(MDY(2,1,2007), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004325', 30, 2006, 'A-E', EXTEND(MDY(2,1,2007), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004325', 31, 2006, 'A-E', EXTEND(MDY(2,1,2007), YEAR to SECOND), 1);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004325', 32, 2006, 'A-E', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004325', 33, 2006, 'A-E', EXTEND(MDY(2,1,2007), YEAR to SECOND), 1);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004325', 34, 2006, 'A-E', EXTEND(MDY(2,1,2007), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004330', 30, 2006, 'A-G', EXTEND(MDY(2,1,2007), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004330', 31, 2006, 'A-G', EXTEND(MDY(2,1,2007), YEAR to SECOND), 1);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004330', 32, 2006, 'A-G', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004330', 33, 2006, 'A-G', EXTEND(MDY(2,1,2007), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004330', 34, 2006, 'A-G', EXTEND(MDY(2,1,2007), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004346', 30, 2006, 'A-I', EXTEND(MDY(2,1,2007), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004346', 31, 2006, 'A-I', EXTEND(MDY(2,1,2007), YEAR to SECOND), 1);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004346', 32, 2006, 'A-I', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004346', 33, 2006, 'A-I', EXTEND(MDY(2,1,2007), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004346', 34, 2006, 'A-I', EXTEND(MDY(2,1,2007), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004351', 31, 2006, 'A-F', EXTEND(MDY(2,1,2007), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004351', 32, 2006, 'A-F', EXTEND(MDY(2,1,2007), YEAR to SECOND), 1);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004351', 33, 2006, 'A-F', EXTEND(MDY(2,1,2007), YEAR to SECOND), 1);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004351', 34, 2006, 'A-F', EXTEND(MDY(2,1,2007), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004367', 3, 2005, 'A-A', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004367', 11, 2005, 'A-A', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004367', 12, 2005, 'A-A', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004372', 1, 2004, 'D-A1', EXTEND(MDY(6,16,2005), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004372', 3, 2003, 'C-A2', EXTEND(MDY(7,15,2004), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004372', 5, 2004, 'D-A1', EXTEND(MDY(2,7,2005), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004372', 9, 2003, 'C-A2', EXTEND(MDY(2,6,2004), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004372', 10, 2003, 'C-A2', EXTEND(MDY(2,12,2004), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004372', 11, 2003, 'C-A2', EXTEND(MDY(6,23,2004), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004372', 12, 2003, 'C-A2', EXTEND(MDY(6,21,2004), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004372', 13, 2004, 'D-A1', EXTEND(MDY(2,14,2005), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004372', 14, 2004, 'D-A1', EXTEND(MDY(6,16,2005), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004372', 15, 2004, 'D-A1', EXTEND(MDY(2,10,2005), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004372', 17, 2004, 'D-A1', EXTEND(MDY(7,12,2005), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004372', 26, 2004, 'D-A1', EXTEND(MDY(7,12,2005), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004372', 27, 2004, 'D-A1', EXTEND(MDY(6,21,2005), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004372', 28, 2003, 'C-A2', EXTEND(MDY(2,9,2004), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004372', 29, 2004, 'D-A1', EXTEND(MDY(6,13,2005), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004388', 9, 2006, 'C-A2', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004388', 10, 2006, 'C-A2', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004388', 28, 2006, 'C-A2', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004442', 1, 2005, 'A-A', EXTEND(MDY(7,12,2006), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004458', 1, 2004, 'D-A5', EXTEND(MDY(9,1,2005), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004458', 2, 2003, 'C-A2', EXTEND(MDY(7,14,2006), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004458', 3, 2003, 'C-A2', EXTEND(MDY(7,14,2005), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004458', 5, 2004, 'D-A5', EXTEND(MDY(2,7,2005), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004458', 10, 2003, 'C-A2', EXTEND(MDY(2,12,2004), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004458', 11, 2003, 'C-A2', EXTEND(MDY(6,23,2004), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004458', 12, 2003, 'C-A2', EXTEND(MDY(6,21,2004), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004458', 13, 2004, 'D-A5', EXTEND(MDY(9,28,2005), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004458', 14, 2004, 'D-A5', EXTEND(MDY(6,16,2005), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004458', 15, 2004, 'D-A5', EXTEND(MDY(2,10,2005), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004458', 17, 2004, 'D-A5', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004458', 26, 2004, 'D-A5', EXTEND(MDY(9,26,2005), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004458', 27, 2004, 'D-A5', EXTEND(MDY(6,16,2005), YEAR to SECOND), 1);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004458', 27, 2005, 'A-A', EXTEND(MDY(9,28,2006), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004458', 29, 2004, 'D-A5', EXTEND(MDY(6,16,2005), YEAR to SECOND), 1);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004458', 29, 2005, 'D-A1', EXTEND(MDY(6,12,2006), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004463', 1, 2005, 'A-A', EXTEND(MDY(7,12,2006), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004479', 1, 2003, 'D-A4', EXTEND(MDY(7,6,2004), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004479', 13, 2003, 'D-A4', EXTEND(MDY(4,21,2004), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004479', 14, 2003, 'D-A4', EXTEND(MDY(6,17,2004), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004479', 15, 2003, 'D-A4', EXTEND(MDY(2,20,2006), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004479', 17, 2003, 'D-A4', EXTEND(MDY(9,19,2005), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004479', 26, 2003, 'D-A4', EXTEND(MDY(9,27,2004), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004479', 27, 2003, 'D-A4', EXTEND(MDY(4,6,2006), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004479', 29, 2003, 'D-A4', EXTEND(MDY(6,15,2004), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004484', 1, 2004, 'D-B5', EXTEND(MDY(6,16,2005), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004484', 2, 2003, 'C-B5', EXTEND(MDY(2,16,2004), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004484', 4, 2003, 'C-B5', EXTEND(MDY(2,3,2004), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004484', 5, 2003, 'C-B5', EXTEND(MDY(2,9,2004), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004484', 6, 2003, 'C-B5', EXTEND(MDY(6,16,2004), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004484', 7, 2003, 'C-B5', EXTEND(MDY(6,15,2004), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004484', 8, 2003, 'C-B5', EXTEND(MDY(7,5,2004), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004484', 9, 2003, 'C-B5', EXTEND(MDY(7,6,2005), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004484', 12, 2003, 'C-B5', EXTEND(MDY(6,21,2004), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004484', 18, 2004, 'D-B5', EXTEND(MDY(7,15,2005), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004484', 19, 2004, 'D-B5', EXTEND(MDY(2,7,2005), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004484', 20, 2004, 'D-B5', EXTEND(MDY(2,9,2005), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004484', 21, 2004, 'D-B5', EXTEND(MDY(6,15,2005), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004484', 22, 2004, 'D-B5', EXTEND(MDY(6,20,2005), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004484', 23, 2004, 'D-B5', EXTEND(MDY(6,14,2005), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004484', 25, 2004, 'D-B5', EXTEND(MDY(3,6,2006), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004507', 1, 2004, 'D-B4', EXTEND(MDY(6,16,2005), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004507', 4, 2003, 'C-B5', EXTEND(MDY(2,3,2004), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004507', 5, 2003, 'C-B5', EXTEND(MDY(2,9,2004), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004507', 6, 2003, 'C-B5', EXTEND(MDY(6,16,2004), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004507', 7, 2003, 'C-B5', EXTEND(MDY(6,15,2004), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004507', 8, 2003, 'C-B5', EXTEND(MDY(2,23,2005), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004507', 9, 2003, 'C-B5', EXTEND(MDY(9,22,2004), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004507', 12, 2003, 'C-B5', EXTEND(MDY(6,21,2004), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004507', 18, 2004, 'D-B4', EXTEND(MDY(7,5,2005), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004507', 19, 2004, 'D-B4', EXTEND(MDY(2,7,2005), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004507', 20, 2004, 'D-B4', EXTEND(MDY(2,9,2005), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004507', 21, 2004, 'D-B4', EXTEND(MDY(6,15,2005), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004507', 22, 2004, 'D-B4', EXTEND(MDY(6,20,2005), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004507', 23, 2004, 'D-B4', EXTEND(MDY(6,14,2005), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004507', 25, 2004, 'D-B4', EXTEND(MDY(4,3,2006), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004512', 1, 2004, 'D-B2', EXTEND(MDY(6,30,2005), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004512', 19, 2004, 'D-B2', EXTEND(MDY(6,24,2005), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004512', 20, 2004, 'D-B2', EXTEND(MDY(9,1,2005), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004512', 21, 2004, 'D-B2', EXTEND(MDY(5,15,2006), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004512', 22, 2004, 'D-B2', EXTEND(MDY(6,20,2005), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004512', 23, 2004, 'D-B2', EXTEND(MDY(9,28,2006), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004512', 25, 2004, 'D-B2', EXTEND(MDY(9,22,2005), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004528', 1, 2005, 'D-B3', EXTEND(MDY(9,5,2006), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004528', 4, 2004, 'C-B2', EXTEND(MDY(2,1,2005), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004528', 5, 2004, 'C-B2', EXTEND(MDY(2,7,2005), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004528', 6, 2004, 'C-B2', EXTEND(MDY(6,27,2006), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004528', 7, 2004, 'C-B2', EXTEND(MDY(6,14,2005), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004528', 8, 2004, 'C-B2', EXTEND(MDY(6,13,2005), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004528', 9, 2004, 'C-B2', EXTEND(MDY(4,13,2005), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004528', 12, 2004, 'C-B2', EXTEND(MDY(6,21,2005), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004528', 18, 2005, 'D-B3', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004528', 19, 2005, 'D-B3', EXTEND(MDY(2,17,2006), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004528', 20, 2005, 'D-B3', EXTEND(MDY(2,8,2006), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004528', 21, 2005, 'D-B3', EXTEND(MDY(7,4,2006), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004528', 22, 2005, 'D-B3', EXTEND(MDY(6,19,2006), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004528', 23, 2005, 'D-B3', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004528', 25, 2005, 'D-B3', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004533', 1, 2004, 'D-B4', EXTEND(MDY(6,16,2005), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004533', 2, 2003, 'C-B2', EXTEND(MDY(2,16,2004), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004533', 4, 2003, 'C-B2', EXTEND(MDY(2,19,2004), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004533', 5, 2003, 'C-B2', EXTEND(MDY(4,11,2005), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004533', 6, 2003, 'C-B2', EXTEND(MDY(6,29,2004), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004533', 7, 2003, 'C-B2', EXTEND(MDY(6,15,2004), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004533', 8, 2003, 'C-B2', EXTEND(MDY(9,30,2004), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004533', 9, 2003, 'C-B2', EXTEND(MDY(9,22,2004), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004533', 12, 2003, 'C-B2', EXTEND(MDY(6,21,2004), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004533', 18, 2004, 'D-B4', EXTEND(MDY(9,16,2005), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004533', 19, 2004, 'D-B4', EXTEND(MDY(2,18,2005), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004533', 20, 2004, 'D-B4', EXTEND(MDY(2,9,2005), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004533', 21, 2004, 'D-B4', EXTEND(MDY(1,16,2006), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004533', 22, 2004, 'D-B4', EXTEND(MDY(6,20,2005), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004533', 23, 2004, 'D-B4', EXTEND(MDY(4,6,2006), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004533', 25, 2004, 'D-B4', EXTEND(MDY(6,23,2005), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004549', 1, 2004, 'D-B3', EXTEND(MDY(6,30,2005), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004549', 2, 2003, 'C-B2', EXTEND(MDY(2,16,2004), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004549', 4, 2003, 'C-B2', EXTEND(MDY(2,3,2004), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004549', 5, 2003, 'C-B2', EXTEND(MDY(2,9,2004), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004549', 6, 2003, 'C-B2', EXTEND(MDY(6,29,2004), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004549', 7, 2003, 'C-B2', EXTEND(MDY(6,21,2005), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004549', 8, 2003, 'C-B2', EXTEND(MDY(9,21,2004), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004549', 9, 2003, 'C-B2', EXTEND(MDY(2,15,2005), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004549', 12, 2003, 'C-B2', EXTEND(MDY(6,21,2004), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004549', 18, 2004, 'D-B3', EXTEND(MDY(7,5,2005), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004549', 19, 2004, 'D-B3', EXTEND(MDY(2,7,2005), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004549', 20, 2004, 'D-B3', EXTEND(MDY(2,9,2005), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004549', 21, 2004, 'D-B3', EXTEND(MDY(7,5,2005), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004549', 22, 2004, 'D-B3', EXTEND(MDY(6,20,2005), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004549', 23, 2004, 'D-B3', EXTEND(MDY(7,5,2005), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004549', 25, 2004, 'D-B3', EXTEND(MDY(9,22,2005), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004554', 1, 2004, 'D-A4', EXTEND(MDY(6,16,2005), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004554', 3, 2003, 'C-A3', EXTEND(MDY(7,2,2004), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004554', 5, 2004, 'D-A4', EXTEND(MDY(2,7,2005), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004554', 9, 2003, 'C-A3', EXTEND(MDY(2,6,2004), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004554', 10, 2003, 'C-A3', EXTEND(MDY(2,12,2004), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004554', 11, 2003, 'C-A3', EXTEND(MDY(6,23,2004), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004554', 12, 2003, 'C-A3', EXTEND(MDY(6,21,2004), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004554', 13, 2004, 'D-A4', EXTEND(MDY(2,14,2005), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004554', 14, 2004, 'D-A4', EXTEND(MDY(6,16,2005), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004554', 15, 2004, 'D-A4', EXTEND(MDY(2,10,2005), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004554', 17, 2004, 'D-A4', EXTEND(MDY(2,18,2005), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004554', 27, 2004, 'D-A4', EXTEND(MDY(6,21,2005), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004554', 28, 2003, 'C-A3', EXTEND(MDY(2,9,2004), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004554', 29, 2004, 'D-A4', EXTEND(MDY(6,13,2005), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004575', 1, 2005, 'D-A4', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004575', 2, 2003, 'C-A1', EXTEND(MDY(4,22,2004), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004575', 3, 2003, 'C-A1', EXTEND(MDY(6,15,2004), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004575', 9, 2003, 'C-A1', EXTEND(MDY(4,21,2004), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004575', 10, 2003, 'C-A1', EXTEND(MDY(2,10,2005), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004575', 11, 2003, 'C-A1', EXTEND(MDY(6,21,2005), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004575', 12, 2003, 'C-A1', EXTEND(MDY(7,6,2004), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004575', 13, 2005, 'D-A4', EXTEND(MDY(2,1,2006), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004575', 14, 2005, 'D-A4', EXTEND(MDY(6,16,2006), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004575', 15, 2005, 'D-A4', EXTEND(MDY(2,20,2006), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004575', 17, 2005, 'D-A4', EXTEND(MDY(2,17,2006), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004575', 26, 2005, 'D-A4', EXTEND(MDY(9,28,2006), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004575', 27, 2005, 'D-A4', EXTEND(MDY(6,20,2006), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004575', 28, 2003, 'C-A1', EXTEND(MDY(6,29,2004), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004575', 29, 2005, 'D-A4', EXTEND(MDY(6,12,2006), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004580', 1, 2004, 'D-B2', EXTEND(MDY(6,16,2005), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004580', 2, 2003, 'C-B1', EXTEND(MDY(2,2,2004), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004580', 4, 2003, 'C-B1', EXTEND(MDY(2,19,2004), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004580', 5, 2003, 'C-B1', EXTEND(MDY(2,9,2004), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004580', 6, 2003, 'C-B1', EXTEND(MDY(6,16,2004), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004580', 7, 2003, 'C-B1', EXTEND(MDY(9,17,2004), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004580', 8, 2003, 'C-B1', EXTEND(MDY(11,12,2004), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004580', 9, 2003, 'C-B1', EXTEND(MDY(9,13,2004), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004580', 12, 2003, 'C-B1', EXTEND(MDY(6,21,2004), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004580', 18, 2004, 'D-B2', EXTEND(MDY(4,14,2005), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004580', 19, 2004, 'D-B2', EXTEND(MDY(2,7,2005), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004580', 20, 2004, 'D-B2', EXTEND(MDY(7,11,2005), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004580', 21, 2004, 'D-B2', EXTEND(MDY(6,15,2005), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004580', 22, 2004, 'D-B2', EXTEND(MDY(6,20,2005), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004580', 23, 2004, 'D-B2', EXTEND(MDY(7,5,2005), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004580', 25, 2004, 'D-B2', EXTEND(MDY(7,7,2005), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004596', 1, 2005, 'D-A5', EXTEND(MDY(6,13,2006), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004596', 3, 2003, 'C-A4', EXTEND(MDY(4,5,2006), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004596', 9, 2003, 'C-A4', EXTEND(MDY(9,22,2004), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004596', 10, 2003, 'C-A4', EXTEND(MDY(2,10,2005), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004596', 11, 2003, 'C-A4', EXTEND(MDY(6,21,2005), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004596', 12, 2003, 'C-A4', EXTEND(MDY(9,30,2004), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004596', 14, 2005, 'D-A5', EXTEND(MDY(7,3,2006), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004596', 17, 2005, 'D-A5', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004596', 26, 2005, 'D-A5', EXTEND(MDY(7,11,2006), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004596', 27, 2005, 'D-A5', EXTEND(MDY(6,20,2006), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004596', 28, 2003, 'C-A4', EXTEND(MDY(2,18,2004), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004596', 29, 2004, 'D-A6', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004603', 32, 2006, 'A-L', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004603', 33, 2006, 'A-K', EXTEND(MDY(2,1,2007), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004603', 34, 2006, 'A-K', EXTEND(MDY(2,1,2007), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004603', 42, 2006, 'B-E', EXTEND(MDY(2,1,2007), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004603', 43, 2006, 'B-E', EXTEND(MDY(2,1,2007), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004603', 44, 2006, 'B-E', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004619', 3, 2004, 'C-A4', EXTEND(MDY(9,2,2005), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004619', 9, 2004, 'C-A4', EXTEND(MDY(7,12,2005), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004619', 10, 2004, 'C-A4', EXTEND(MDY(2,9,2006), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004619', 11, 2004, 'C-A4', EXTEND(MDY(6,21,2005), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004619', 12, 2004, 'C-A4', EXTEND(MDY(6,21,2005), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004619', 15, 2006, 'D-A1', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004619', 17, 2006, 'D-A1', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004619', 26, 2006, 'D-A1', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004619', 28, 2004, 'C-A4', EXTEND(MDY(2,6,2006), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004624', 1, 2004, 'D-A5', EXTEND(MDY(4,4,2006), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004624', 3, 2003, 'C-A3', EXTEND(MDY(11,12,2004), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004624', 5, 2004, 'D-A5', EXTEND(MDY(2,7,2005), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004624', 9, 2003, 'C-A3', EXTEND(MDY(2,17,2004), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004624', 10, 2003, 'C-A3', EXTEND(MDY(2,12,2004), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004624', 11, 2003, 'C-A3', EXTEND(MDY(6,23,2004), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004624', 12, 2003, 'C-A3', EXTEND(MDY(6,21,2004), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004624', 13, 2004, 'D-A5', EXTEND(MDY(2,14,2005), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004624', 14, 2004, 'D-A5', EXTEND(MDY(6,16,2005), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004624', 15, 2004, 'D-A5', EXTEND(MDY(2,10,2005), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004624', 17, 2004, 'D-A5', EXTEND(MDY(9,27,2005), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004624', 26, 2004, 'D-A5', EXTEND(MDY(9,26,2005), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004624', 27, 2004, 'D-A5', EXTEND(MDY(6,21,2005), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004624', 28, 2003, 'C-A3', EXTEND(MDY(2,9,2004), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004624', 29, 2004, 'D-A5', EXTEND(MDY(6,13,2005), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004645', 3, 2004, 'C-A1', EXTEND(MDY(6,14,2005), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004645', 12, 2004, 'C-A1', EXTEND(MDY(6,21,2005), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004645', 28, 2004, 'C-A1', EXTEND(MDY(2,7,2005), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004650', 10, 2006, 'C-A1', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004666', 1, 2004, 'D-B4', EXTEND(MDY(6,16,2005), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004666', 2, 2003, 'C-B4', EXTEND(MDY(2,16,2004), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004666', 4, 2003, 'C-B4', EXTEND(MDY(2,3,2004), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004666', 5, 2003, 'C-B4', EXTEND(MDY(2,9,2004), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004666', 6, 2003, 'C-B4', EXTEND(MDY(2,22,2005), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004666', 7, 2003, 'C-B4', EXTEND(MDY(6,15,2004), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004666', 8, 2003, 'C-B4', EXTEND(MDY(7,13,2004), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004666', 9, 2003, 'C-B4', EXTEND(MDY(2,6,2004), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004666', 12, 2003, 'C-B4', EXTEND(MDY(6,21,2004), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004666', 18, 2004, 'D-B4', EXTEND(MDY(7,15,2005), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004666', 19, 2004, 'D-B4', EXTEND(MDY(2,7,2005), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004666', 20, 2004, 'D-B4', EXTEND(MDY(2,9,2005), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004666', 21, 2004, 'D-B4', EXTEND(MDY(7,5,2005), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004666', 22, 2004, 'D-B4', EXTEND(MDY(6,20,2005), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004666', 23, 2004, 'D-B4', EXTEND(MDY(11,10,2005), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004666', 25, 2004, 'D-B4', EXTEND(MDY(9,22,2005), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004671', 1, 2004, 'D-B2', EXTEND(MDY(6,16,2005), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004671', 2, 2003, 'C-B1', EXTEND(MDY(2,16,2004), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004671', 4, 2003, 'C-B1', EXTEND(MDY(2,19,2004), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004671', 5, 2003, 'C-B1', EXTEND(MDY(2,9,2004), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004671', 6, 2003, 'C-B1', EXTEND(MDY(6,29,2004), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004671', 7, 2003, 'C-B1', EXTEND(MDY(6,15,2004), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004671', 8, 2003, 'C-B1', EXTEND(MDY(6,14,2004), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004671', 9, 2003, 'C-B1', EXTEND(MDY(2,6,2004), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004671', 12, 2003, 'C-B1', EXTEND(MDY(6,21,2004), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004671', 18, 2004, 'D-B2', EXTEND(MDY(2,14,2005), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004671', 19, 2004, 'D-B2', EXTEND(MDY(2,7,2005), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004671', 20, 2004, 'D-B2', EXTEND(MDY(2,9,2005), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004671', 21, 2004, 'D-B2', EXTEND(MDY(9,13,2005), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004671', 22, 2004, 'D-B2', EXTEND(MDY(6,20,2005), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004671', 23, 2004, 'D-B2', EXTEND(MDY(6,14,2005), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004687', 1, 2005, 'D-A5', EXTEND(MDY(7,4,2006), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004687', 3, 2004, 'C-A5', EXTEND(MDY(6,14,2005), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004687', 9, 2004, 'C-A5', EXTEND(MDY(2,15,2005), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004687', 12, 2004, 'C-A5', EXTEND(MDY(6,21,2005), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004687', 13, 2005, 'D-A5', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004687', 14, 2005, 'D-A5', EXTEND(MDY(9,25,2006), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004687', 15, 2005, 'D-A5', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004687', 17, 2005, 'D-A5', EXTEND(MDY(2,17,2006), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004687', 26, 2005, 'D-A5', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004687', 27, 2005, 'D-A5', EXTEND(MDY(7,7,2006), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004687', 29, 2005, 'D-A5', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004692', 1, 2004, 'D-A4', EXTEND(MDY(9,1,2005), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004692', 3, 2003, 'C-A3', EXTEND(MDY(6,15,2004), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004692', 5, 2004, 'D-A4', EXTEND(MDY(2,15,2005), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004692', 9, 2003, 'C-A3', EXTEND(MDY(6,23,2004), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004692', 10, 2003, 'C-A3', EXTEND(MDY(2,10,2005), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004692', 11, 2003, 'C-A3', EXTEND(MDY(6,23,2004), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004692', 12, 2003, 'C-A3', EXTEND(MDY(6,21,2004), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004692', 13, 2004, 'D-A4', EXTEND(MDY(2,14,2005), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004692', 14, 2004, 'D-A4', EXTEND(MDY(6,16,2005), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004692', 15, 2004, 'D-A4', EXTEND(MDY(2,20,2006), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004692', 17, 2004, 'D-A4', EXTEND(MDY(2,18,2005), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004692', 26, 2004, 'D-A4', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004692', 27, 2004, 'D-A4', EXTEND(MDY(6,21,2005), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004692', 28, 2003, 'C-A3', EXTEND(MDY(2,9,2004), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004692', 29, 2004, 'D-A4', EXTEND(MDY(9,28,2005), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004720', 1, 2004, 'D-A2', EXTEND(MDY(6,16,2005), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004720', 3, 2003, 'C-A3', EXTEND(MDY(9,1,2004), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004720', 5, 2004, 'D-A2', EXTEND(MDY(2,7,2005), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004720', 9, 2003, 'C-A3', EXTEND(MDY(2,6,2004), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004720', 10, 2003, 'C-A3', EXTEND(MDY(2,12,2004), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004720', 11, 2003, 'C-A3', EXTEND(MDY(6,23,2004), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004720', 12, 2003, 'C-A3', EXTEND(MDY(6,21,2004), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004720', 13, 2004, 'D-A2', EXTEND(MDY(2,14,2005), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004720', 14, 2004, 'D-A2', EXTEND(MDY(6,16,2005), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004720', 15, 2004, 'D-A2', EXTEND(MDY(2,10,2005), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004720', 17, 2004, 'D-A2', EXTEND(MDY(9,19,2005), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004720', 26, 2004, 'D-A2', EXTEND(MDY(9,26,2005), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004720', 27, 2004, 'D-A2', EXTEND(MDY(6,21,2005), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004720', 28, 2003, 'C-A3', EXTEND(MDY(2,9,2004), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004720', 29, 2004, 'D-A2', EXTEND(MDY(6,13,2005), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004736', 32, 2006, 'A-L', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004736', 34, 2006, 'A-M', EXTEND(MDY(2,1,2007), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004736', 42, 2006, 'B-K', EXTEND(MDY(2,1,2007), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004736', 44, 2006, 'B-K', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004736', 45, 2006, 'B-K', EXTEND(MDY(2,1,2007), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004741', 1, 2005, 'D-B3', EXTEND(MDY(7,4,2006), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004741', 2, 2003, 'C-B2', EXTEND(MDY(2,16,2004), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004741', 4, 2003, 'C-B2', EXTEND(MDY(2,19,2004), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004741', 5, 2003, 'C-B2', EXTEND(MDY(2,9,2004), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004741', 6, 2003, 'C-B2', EXTEND(MDY(6,29,2004), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004741', 7, 2003, 'C-B2', EXTEND(MDY(7,13,2004), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004741', 8, 2003, 'C-B2', EXTEND(MDY(2,2,2005), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004741', 9, 2003, 'C-B2', EXTEND(MDY(6,23,2005), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004741', 12, 2003, 'C-B2', EXTEND(MDY(6,21,2004), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004741', 18, 2005, 'D-B3', EXTEND(MDY(2,13,2006), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004741', 22, 2005, 'D-B3', EXTEND(MDY(6,27,2006), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004741', 25, 2005, 'D-B3', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004757', 1, 2004, 'D-A4', EXTEND(MDY(9,1,2005), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004757', 3, 2003, 'C-A3', EXTEND(MDY(7,1,2005), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004757', 9, 2003, 'C-A3', EXTEND(MDY(2,17,2004), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004757', 10, 2003, 'C-A3', EXTEND(MDY(2,12,2004), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004757', 11, 2003, 'C-A3', EXTEND(MDY(6,23,2004), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004757', 12, 2003, 'C-A3', EXTEND(MDY(6,21,2004), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004757', 13, 2004, 'D-A4', EXTEND(MDY(9,8,2005), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004757', 14, 2004, 'D-A4', EXTEND(MDY(6,16,2005), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004757', 15, 2004, 'D-A4', EXTEND(MDY(11,10,2006), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004757', 17, 2004, 'D-A4', EXTEND(MDY(7,12,2005), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004757', 26, 2004, 'D-A4', EXTEND(MDY(7,11,2006), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004757', 27, 2004, 'D-A4', EXTEND(MDY(6,21,2005), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004757', 28, 2003, 'C-A3', EXTEND(MDY(2,9,2004), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004757', 29, 2004, 'D-A4', EXTEND(MDY(6,13,2005), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004778', 1, 2005, 'D-B5', EXTEND(MDY(9,5,2006), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004778', 2, 2004, 'C-B3', EXTEND(MDY(1,31,2005), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004778', 4, 2004, 'C-B3', EXTEND(MDY(6,23,2005), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004778', 5, 2004, 'C-B3', EXTEND(MDY(2,7,2005), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004778', 6, 2004, 'C-B3', EXTEND(MDY(9,1,2005), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004778', 7, 2004, 'C-B3', EXTEND(MDY(6,14,2005), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004778', 8, 2004, 'C-B3', EXTEND(MDY(7,3,2006), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004778', 9, 2004, 'C-B3', EXTEND(MDY(2,4,2005), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004778', 12, 2004, 'C-B3', EXTEND(MDY(6,21,2005), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004778', 18, 2005, 'D-B5', EXTEND(MDY(11,8,2006), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004778', 19, 2005, 'D-B5', EXTEND(MDY(2,6,2006), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004778', 20, 2005, 'D-B5', EXTEND(MDY(2,8,2006), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004778', 21, 2005, 'D-B5', EXTEND(MDY(6,14,2006), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004778', 22, 2005, 'D-B5', EXTEND(MDY(6,19,2006), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004778', 23, 2005, 'D-B5', EXTEND(MDY(6,13,2006), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004778', 25, 2005, 'D-B5', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004783', 2, 2006, 'C-B1', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004783', 4, 2006, 'C-B1', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004783', 5, 2006, 'C-B1', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004783', 9, 2006, 'C-B1', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004799', 1, 2005, 'D-A5', EXTEND(MDY(7,4,2006), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004799', 3, 2004, 'C-A2', EXTEND(MDY(6,30,2006), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004799', 9, 2004, 'C-A2', EXTEND(MDY(7,12,2005), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004799', 10, 2004, 'C-A2', EXTEND(MDY(2,10,2005), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004799', 11, 2004, 'C-A2', EXTEND(MDY(6,21,2005), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004799', 12, 2004, 'C-A2', EXTEND(MDY(6,16,2005), YEAR to SECOND), 1);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004799', 12, 2005, 'A-A', EXTEND(MDY(7,4,2006), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004799', 13, 2005, 'D-A5', EXTEND(MDY(2,1,2006), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004799', 14, 2005, 'D-A5', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004799', 15, 2005, 'D-A5', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004799', 17, 2005, 'D-A5', EXTEND(MDY(9,26,2006), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004799', 26, 2005, 'D-A5', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004799', 27, 2005, 'D-A5', EXTEND(MDY(6,20,2006), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004799', 28, 2004, 'C-A2', EXTEND(MDY(2,7,2005), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004799', 29, 2005, 'D-A5', EXTEND(MDY(9,4,2006), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004806', 1, 2005, 'A-A', EXTEND(MDY(7,4,2006), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004811', 1, 2005, 'D-B3', EXTEND(MDY(7,4,2006), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004811', 2, 2004, 'C-B4', EXTEND(MDY(9,11,2006), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004811', 4, 2004, 'C-B4', EXTEND(MDY(7,1,2005), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004811', 5, 2004, 'C-B4', EXTEND(MDY(9,13,2005), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004811', 6, 2004, 'C-B4', EXTEND(MDY(6,14,2006), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004811', 7, 2004, 'C-B4', EXTEND(MDY(7,12,2005), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004811', 8, 2004, 'C-B4', EXTEND(MDY(7,12,2005), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004811', 9, 2004, 'C-B4', EXTEND(MDY(2,4,2005), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004811', 12, 2004, 'C-B4', EXTEND(MDY(7,5,2005), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004811', 18, 2005, 'D-B3', EXTEND(MDY(4,6,2006), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004811', 19, 2005, 'D-B3', EXTEND(MDY(2,17,2006), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004811', 20, 2005, 'D-B3', EXTEND(MDY(2,20,2006), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004811', 21, 2005, 'D-B3', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004811', 22, 2005, 'D-B3', EXTEND(MDY(6,27,2006), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004811', 23, 2005, 'D-B3', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004811', 25, 2005, 'D-B3', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004827', 1, 2005, 'D-B2', EXTEND(MDY(7,12,2006), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004827', 2, 2004, 'C-B1', EXTEND(MDY(1,31,2005), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004827', 4, 2004, 'C-B1', EXTEND(MDY(2,1,2005), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004827', 5, 2004, 'C-B1', EXTEND(MDY(2,7,2005), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004827', 6, 2004, 'C-B1', EXTEND(MDY(6,28,2005), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004827', 7, 2004, 'C-B1', EXTEND(MDY(6,21,2005), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004827', 8, 2004, 'C-B1', EXTEND(MDY(6,13,2005), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004827', 9, 2004, 'C-B1', EXTEND(MDY(2,4,2005), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004827', 12, 2004, 'C-B1', EXTEND(MDY(6,21,2005), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004827', 18, 2005, 'D-B2', EXTEND(MDY(2,13,2006), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004827', 19, 2005, 'D-B2', EXTEND(MDY(2,17,2006), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004827', 20, 2005, 'D-B2', EXTEND(MDY(2,8,2006), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004827', 21, 2005, 'D-B2', EXTEND(MDY(6,14,2006), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004827', 22, 2005, 'D-B2', EXTEND(MDY(6,19,2006), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004827', 23, 2005, 'D-B2', EXTEND(MDY(6,13,2006), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004827', 25, 2005, 'D-B2', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004832', 1, 2005, 'A-A', EXTEND(MDY(7,4,2006), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004848', 1, 2005, 'A-A', EXTEND(MDY(7,12,2006), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004853', 1, 2005, 'A-A', EXTEND(MDY(7,4,2006), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004869', 1, 2005, 'A-A', EXTEND(MDY(7,4,2006), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004874', 1, 2005, 'D-B2', EXTEND(MDY(9,5,2006), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004874', 2, 2004, 'C-B1', EXTEND(MDY(1,31,2005), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004874', 4, 2004, 'C-B1', EXTEND(MDY(2,1,2005), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004874', 5, 2004, 'C-B1', EXTEND(MDY(2,15,2005), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004874', 6, 2004, 'C-B1', EXTEND(MDY(6,28,2005), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004874', 7, 2004, 'C-B1', EXTEND(MDY(6,14,2005), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004874', 8, 2004, 'C-B1', EXTEND(MDY(6,13,2005), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004874', 9, 2004, 'C-B1', EXTEND(MDY(2,4,2005), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004874', 12, 2004, 'C-B1', EXTEND(MDY(7,13,2005), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004874', 18, 2005, 'D-B2', EXTEND(MDY(7,4,2006), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004874', 19, 2005, 'D-B2', EXTEND(MDY(2,6,2006), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004874', 20, 2005, 'D-B2', EXTEND(MDY(2,20,2006), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004874', 21, 2005, 'D-B2', EXTEND(MDY(6,14,2006), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004874', 22, 2005, 'D-B2', EXTEND(MDY(6,19,2006), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004874', 23, 2005, 'D-B2', EXTEND(MDY(6,13,2006), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004874', 25, 2005, 'D-B2', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004874', 28, 2004, 'C-B1', EXTEND(MDY(2,7,2005), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004902', 1, 2005, 'A-A', EXTEND(MDY(6,13,2006), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004918', 34, 2006, 'A-L', EXTEND(MDY(2,1,2007), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004918', 40, 2006, 'B-E', EXTEND(MDY(2,1,2007), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004918', 43, 2006, 'B-E', EXTEND(MDY(2,1,2007), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004918', 44, 2006, 'B-E', EXTEND(MDY(2,1,2007), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004923', 1, 2005, 'A-A', EXTEND(MDY(9,26,2006), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004944', 2, 2004, 'C-B5', EXTEND(MDY(2,14,2005), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004944', 4, 2004, 'C-B5', EXTEND(MDY(2,17,2005), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004944', 5, 2004, 'C-B5', EXTEND(MDY(2,7,2005), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004944', 6, 2004, 'C-B5', EXTEND(MDY(6,28,2005), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004944', 7, 2004, 'C-B5', EXTEND(MDY(6,13,2006), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004944', 8, 2004, 'C-B5', EXTEND(MDY(6,13,2005), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004944', 9, 2004, 'C-B5', EXTEND(MDY(9,18,2006), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004944', 12, 2004, 'C-B5', EXTEND(MDY(6,21,2005), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004944', 28, 2006, 'C-A2', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004970', 3, 2005, 'C-A5', EXTEND(MDY(6,13,2006), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004970', 9, 2005, 'C-A5', EXTEND(MDY(2,3,2006), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004970', 10, 2005, 'C-A5', EXTEND(MDY(2,9,2006), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004970', 11, 2005, 'C-A5', EXTEND(MDY(6,21,2006), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004970', 12, 2005, 'C-A5', EXTEND(MDY(6,20,2006), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004970', 13, 2006, 'D-A2', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004970', 15, 2006, 'D-A2', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004970', 17, 2006, 'D-A2', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004970', 26, 2006, 'D-A2', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555004970', 28, 2005, 'C-A5', EXTEND(MDY(2,6,2006), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555005002', 2, 2006, 'C-B2', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555005002', 4, 2006, 'C-B2', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555005002', 5, 2006, 'C-B2', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555005002', 9, 2006, 'C-B2', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555005039', 3, 2005, 'C-A5', EXTEND(MDY(7,13,2006), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555005039', 9, 2005, 'C-A5', EXTEND(MDY(2,3,2006), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555005039', 10, 2005, 'C-A5', EXTEND(MDY(2,9,2006), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555005039', 11, 2005, 'C-A5', EXTEND(MDY(6,21,2006), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555005039', 12, 2005, 'C-A5', EXTEND(MDY(7,4,2006), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555005039', 13, 2006, 'D-A3', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555005039', 15, 2006, 'D-A3', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555005039', 17, 2006, 'D-A3', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555005039', 26, 2006, 'D-A3', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555005039', 28, 2005, 'C-A5', EXTEND(MDY(2,20,2006), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555005065', 31, 2005, 'A-H', EXTEND(MDY(6,16,2006), YEAR to SECOND), 1);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555005065', 31, 2006, 'A-K', EXTEND(MDY(2,1,2007), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555005065', 32, 2005, 'A-H', EXTEND(MDY(6,29,2006), YEAR to SECOND), 1);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555005065', 32, 2006, 'A-K', EXTEND(MDY(6,29,2006), YEAR to SECOND), 1);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555005065', 33, 2005, 'A-H', EXTEND(MDY(1,31,2006), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555005065', 34, 2005, 'A-H', EXTEND(MDY(2,3,2006), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555005065', 37, 2005, 'A-J', EXTEND(MDY(6,27,2006), YEAR to SECOND), 1);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555005065', 39, 2005, 'A-J', EXTEND(MDY(6,30,2006), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555005065', 40, 2006, 'B-A', EXTEND(MDY(2,1,2007), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555005065', 44, 2006, 'B-A', EXTEND(MDY(2,1,2007), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555005070', 2, 2005, 'C-B4', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555005070', 4, 2005, 'C-B4', EXTEND(MDY(4,4,2006), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555005070', 5, 2005, 'C-B4', EXTEND(MDY(2,14,2006), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555005070', 6, 2005, 'C-B4', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555005070', 7, 2005, 'C-B4', EXTEND(MDY(7,11,2006), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555005070', 8, 2005, 'C-B4', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555005070', 9, 2005, 'C-B4', EXTEND(MDY(2,3,2006), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555005070', 12, 2005, 'C-B4', EXTEND(MDY(6,20,2006), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555005070', 18, 2006, 'D-B2', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555005070', 19, 2006, 'D-B2', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555005070', 20, 2006, 'D-B2', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555005070', 25, 2006, 'D-B2', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555005109', 2, 2006, 'C-B3', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555005109', 5, 2006, 'C-B3', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555005109', 7, 2005, 'A-A', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555005109', 9, 2006, 'C-B3', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555005114', 9, 2006, 'C-A5', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555005114', 10, 2006, 'C-A5', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555005114', 28, 2006, 'C-A5', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555005135', 3, 2005, 'C-A5', EXTEND(MDY(6,13,2006), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555005135', 9, 2005, 'C-A5', EXTEND(MDY(2,3,2006), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555005135', 10, 2005, 'C-A5', EXTEND(MDY(2,9,2006), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555005135', 11, 2005, 'C-A5', EXTEND(MDY(6,21,2006), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555005135', 12, 2005, 'C-A5', EXTEND(MDY(6,20,2006), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555005135', 13, 2006, 'D-A1', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555005135', 15, 2006, 'D-A1', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555005135', 17, 2006, 'D-A1', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555005135', 26, 2006, 'D-A1', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555005135', 28, 2005, 'C-A5', EXTEND(MDY(2,6,2006), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555005198', 4, 2006, 'C-B1', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555005198', 5, 2006, 'C-B1', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555005198', 9, 2006, 'C-B1', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555005198', 12, 2005, 'A-A', EXTEND(MDY(6,20,2006), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555005205', 32, 2006, 'A-L', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555005205', 33, 2006, 'A-K', EXTEND(MDY(2,1,2007), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555005205', 34, 2006, 'A-L', EXTEND(MDY(2,1,2007), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555005205', 42, 2006, 'B-E', EXTEND(MDY(2,1,2007), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555005205', 43, 2006, 'B-E', EXTEND(MDY(2,1,2007), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555005205', 44, 2006, 'B-E', EXTEND(MDY(2,1,2007), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555005210', 9, 2006, 'C-A4', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555005210', 10, 2006, 'C-A4', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555005210', 28, 2006, 'C-A5', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555005226', 9, 2006, 'C-A2', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555005226', 10, 2006, 'C-A2', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555005226', 28, 2006, 'C-A2', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555005231', 9, 2006, 'C-A2', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555005231', 10, 2006, 'C-A2', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555005231', 28, 2006, 'C-A2', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555005247', 32, 2006, 'A-L', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555005247', 34, 2006, 'A-L', EXTEND(MDY(2,1,2007), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555005247', 42, 2006, 'B-K', EXTEND(MDY(2,1,2007), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555005247', 44, 2006, 'B-K', EXTEND(MDY(2,1,2007), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555005247', 45, 2006, 'B-K', EXTEND(MDY(2,1,2007), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555005252', 2, 2006, 'C-B3', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555005252', 4, 2006, 'C-B3', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555005252', 5, 2006, 'C-B3', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555005252', 9, 2006, 'C-B3', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555005268', 9, 2006, 'C-A3', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555005268', 10, 2006, 'C-A3', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555005268', 28, 2006, 'C-A3', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555005289', 9, 2006, 'C-A1', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555005289', 10, 2006, 'C-A1', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555005289', 28, 2006, 'C-A1', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555005294', 2, 2006, 'C-B5', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555005294', 4, 2006, 'C-B5', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555005294', 5, 2006, 'C-B5', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555005294', 9, 2006, 'C-B5', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555005294', 28, 2006, 'C-A5', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555005301', 31, 2005, 'A-J', EXTEND(MDY(1,30,2006), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555005301', 32, 2005, 'A-J', EXTEND(MDY(2,2,2006), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555005301', 33, 2005, 'A-J', EXTEND(MDY(1,31,2006), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555005301', 34, 2005, 'A-J', EXTEND(MDY(2,3,2006), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555005301', 37, 2005, 'A-H', EXTEND(MDY(6,27,2006), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555005301', 38, 2005, 'A-H', EXTEND(MDY(6,29,2006), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555005301', 39, 2005, 'A-H', EXTEND(MDY(6,30,2006), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555005301', 42, 2006, 'B-I', EXTEND(MDY(2,1,2007), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555005301', 44, 2006, 'B-I', EXTEND(MDY(2,1,2007), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555005301', 45, 2006, 'B-I', EXTEND(MDY(2,1,2007), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555005301', 46, 2006, 'B-I', EXTEND(MDY(2,1,2007), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555005317', 2, 2006, 'C-B5', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555005317', 4, 2006, 'C-B5', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555005317', 5, 2006, 'C-B5', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555005317', 9, 2006, 'C-B5', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555005322', 30, 2005, 'A-B', EXTEND(MDY(2,1,2006), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555005322', 31, 2005, 'A-B', EXTEND(MDY(6,30,2006), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555005322', 32, 2005, 'A-B', EXTEND(MDY(2,2,2006), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555005322', 33, 2005, 'A-B', EXTEND(MDY(6,27,2006), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555005322', 34, 2005, 'A-B', EXTEND(MDY(2,3,2006), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555005322', 35, 2005, 'A-J', EXTEND(MDY(6,28,2006), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555005322', 36, 2005, 'A-J', EXTEND(MDY(6,26,2006), YEAR to SECOND), 1);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555005322', 39, 2005, 'A-L', EXTEND(MDY(6,30,2006), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555005322', 40, 2006, 'B-D', EXTEND(MDY(2,1,2007), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555005322', 41, 2006, 'B-D', EXTEND(MDY(2,1,2007), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555005322', 42, 2006, 'B-D', EXTEND(MDY(2,1,2007), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555005322', 43, 2006, 'B-D', EXTEND(MDY(2,1,2007), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555005322', 44, 2006, 'B-D', EXTEND(MDY(2,1,2007), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555005338', 30, 2005, 'A-C', EXTEND(MDY(6,28,2006), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555005338', 31, 2005, 'A-C', EXTEND(MDY(6,30,2006), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555005338', 32, 2005, 'A-C', EXTEND(MDY(6,29,2006), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555005338', 33, 2005, 'A-C', EXTEND(MDY(6,27,2006), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555005338', 34, 2005, 'A-C', EXTEND(MDY(2,3,2006), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555005338', 39, 2005, 'A-N', EXTEND(MDY(6,30,2006), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555005338', 41, 2006, 'B-G', EXTEND(MDY(2,1,2007), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555005338', 42, 2006, 'B-G', EXTEND(MDY(2,1,2007), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555005338', 44, 2006, 'B-G', EXTEND(MDY(2,1,2007), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555005343', 30, 2005, 'A-K', EXTEND(MDY(2,1,2006), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555005343', 31, 2005, 'A-K', EXTEND(MDY(1,30,2006), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555005343', 32, 2005, 'A-K', EXTEND(MDY(2,2,2006), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555005343', 33, 2005, 'A-K', EXTEND(MDY(1,31,2006), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555005343', 34, 2005, 'A-K', EXTEND(MDY(2,3,2006), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555005343', 35, 2005, 'A-I', EXTEND(MDY(6,28,2006), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555005343', 36, 2005, 'A-I', EXTEND(MDY(6,26,2006), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555005343', 37, 2005, 'A-I', EXTEND(MDY(6,27,2006), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555005343', 38, 2005, 'A-I', EXTEND(MDY(6,29,2006), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555005343', 39, 2005, 'A-I', EXTEND(MDY(6,30,2006), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555005343', 41, 2006, 'B-J', EXTEND(MDY(2,1,2007), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555005343', 42, 2006, 'B-J', EXTEND(MDY(2,1,2007), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555005343', 44, 2006, 'B-J', EXTEND(MDY(2,1,2007), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555005343', 45, 2006, 'B-J', EXTEND(MDY(2,1,2007), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555005343', 46, 2006, 'B-J', EXTEND(MDY(2,1,2007), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555005359', 30, 2005, 'A-K', EXTEND(MDY(2,1,2006), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555005359', 31, 2005, 'A-K', EXTEND(MDY(1,30,2006), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555005359', 32, 2005, 'A-K', EXTEND(MDY(2,2,2006), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555005359', 33, 2005, 'A-K', EXTEND(MDY(1,31,2006), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555005359', 34, 2005, 'A-K', EXTEND(MDY(2,3,2006), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555005359', 35, 2005, 'A-I', EXTEND(MDY(6,28,2006), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555005359', 36, 2005, 'A-I', EXTEND(MDY(6,26,2006), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555005359', 37, 2005, 'A-I', EXTEND(MDY(6,27,2006), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555005359', 38, 2005, 'A-I', EXTEND(MDY(6,29,2006), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555005359', 39, 2005, 'A-I', EXTEND(MDY(6,30,2006), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555005359', 40, 2006, 'B-D', EXTEND(MDY(2,1,2007), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555005359', 41, 2006, 'B-D', EXTEND(MDY(2,1,2007), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555005359', 42, 2006, 'B-D', EXTEND(MDY(2,1,2007), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555005359', 43, 2006, 'B-D', EXTEND(MDY(2,1,2007), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555005359', 44, 2006, 'B-D', EXTEND(MDY(2,1,2007), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555005364', 30, 2005, 'A-G', EXTEND(MDY(2,1,2006), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555005364', 31, 2005, 'A-G', EXTEND(MDY(1,30,2006), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555005364', 32, 2005, 'A-G', EXTEND(MDY(2,2,2006), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555005364', 33, 2005, 'A-G', EXTEND(MDY(1,31,2006), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555005364', 34, 2005, 'A-G', EXTEND(MDY(2,3,2006), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555005364', 35, 2005, 'A-G', EXTEND(MDY(6,28,2006), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555005364', 36, 2005, 'A-G', EXTEND(MDY(6,26,2006), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555005364', 37, 2005, 'A-G', EXTEND(MDY(6,27,2006), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555005364', 38, 2005, 'A-G', EXTEND(MDY(6,29,2006), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555005364', 39, 2005, 'A-G', EXTEND(MDY(6,30,2006), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555005364', 40, 2006, 'B-C', EXTEND(MDY(2,1,2007), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555005364', 41, 2006, 'B-C', EXTEND(MDY(2,1,2007), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555005364', 42, 2006, 'B-C', EXTEND(MDY(2,1,2007), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555005364', 43, 2006, 'B-C', EXTEND(MDY(2,1,2007), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555005364', 44, 2006, 'B-C', EXTEND(MDY(2,1,2007), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555005385', 30, 2005, 'A-D', EXTEND(MDY(2,1,2006), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555005385', 31, 2005, 'A-D', EXTEND(MDY(1,30,2006), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555005385', 32, 2005, 'A-D', EXTEND(MDY(2,2,2006), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555005385', 33, 2005, 'A-D', EXTEND(MDY(1,31,2006), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555005385', 34, 2005, 'A-D', EXTEND(MDY(2,3,2006), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555005385', 35, 2005, 'A-D', EXTEND(MDY(6,28,2006), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555005385', 36, 2005, 'A-D', EXTEND(MDY(6,26,2006), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555005385', 37, 2005, 'A-D', EXTEND(MDY(6,27,2006), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555005385', 38, 2005, 'A-D', EXTEND(MDY(6,29,2006), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555005385', 39, 2005, 'A-D', EXTEND(MDY(6,30,2006), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555005385', 40, 2006, 'B-B', EXTEND(MDY(2,1,2007), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555005385', 41, 2006, 'B-B', EXTEND(MDY(2,1,2007), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555005385', 42, 2006, 'B-B', EXTEND(MDY(2,1,2007), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555005385', 43, 2006, 'B-B', EXTEND(MDY(2,1,2007), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555005385', 44, 2006, 'B-B', EXTEND(MDY(2,1,2007), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555005390', 30, 2005, 'A-I', EXTEND(MDY(2,1,2006), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555005390', 31, 2005, 'A-I', EXTEND(MDY(1,30,2006), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555005390', 32, 2005, 'A-I', EXTEND(MDY(2,2,2006), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555005390', 33, 2005, 'A-I', EXTEND(MDY(1,31,2006), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555005390', 34, 2005, 'A-I', EXTEND(MDY(2,3,2006), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555005390', 35, 2005, 'A-I', EXTEND(MDY(6,28,2006), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555005390', 36, 2005, 'A-I', EXTEND(MDY(6,26,2006), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555005390', 37, 2005, 'A-I', EXTEND(MDY(6,27,2006), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555005390', 38, 2005, 'A-I', EXTEND(MDY(6,29,2006), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555005390', 39, 2005, 'A-I', EXTEND(MDY(6,30,2006), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555005390', 41, 2006, 'B-J', EXTEND(MDY(2,1,2007), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555005390', 42, 2006, 'B-J', EXTEND(MDY(2,1,2007), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555005390', 44, 2006, 'B-J', EXTEND(MDY(2,1,2007), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555005390', 45, 2006, 'B-J', EXTEND(MDY(2,1,2007), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555005390', 46, 2006, 'B-J', EXTEND(MDY(2,1,2007), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555005408', 30, 2005, 'A-B', EXTEND(MDY(6,28,2006), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555005408', 31, 2005, 'A-B', EXTEND(MDY(1,30,2006), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555005408', 32, 2005, 'A-B', EXTEND(MDY(2,2,2006), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555005408', 33, 2005, 'A-B', EXTEND(MDY(1,31,2006), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555005408', 34, 2005, 'A-B', EXTEND(MDY(2,3,2006), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555005408', 36, 2005, 'A-A', EXTEND(MDY(6,26,2006), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555005408', 37, 2005, 'A-A', EXTEND(MDY(6,27,2006), YEAR to SECOND), 1);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555005408', 38, 2005, 'A-A', EXTEND(MDY(6,29,2006), YEAR to SECOND), 1);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555005408', 39, 2005, 'A-A', EXTEND(MDY(6,30,2006), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555005408', 41, 2006, 'B-B', EXTEND(MDY(2,1,2007), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555005408', 42, 2006, 'B-B', EXTEND(MDY(2,1,2007), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555005408', 44, 2006, 'B-B', EXTEND(MDY(2,1,2007), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555005413', 30, 2005, 'A-A', EXTEND(MDY(2,1,2006), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555005413', 31, 2005, 'A-A', EXTEND(MDY(1,30,2006), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555005413', 32, 2005, 'A-A', EXTEND(MDY(2,2,2006), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555005413', 33, 2005, 'A-A', EXTEND(MDY(1,31,2006), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555005413', 34, 2005, 'A-A', EXTEND(MDY(2,3,2006), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555005413', 35, 2005, 'A-A', EXTEND(MDY(6,28,2006), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555005413', 36, 2005, 'A-A', EXTEND(MDY(6,26,2006), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555005413', 37, 2005, 'A-A', EXTEND(MDY(6,27,2006), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555005413', 38, 2005, 'A-A', EXTEND(MDY(6,29,2006), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555005413', 39, 2005, 'A-A', EXTEND(MDY(6,30,2006), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555005413', 41, 2006, 'B-F', EXTEND(MDY(2,1,2007), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555005413', 42, 2006, 'B-F', EXTEND(MDY(2,1,2007), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555005413', 44, 2006, 'B-F', EXTEND(MDY(2,1,2007), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555005413', 45, 2006, 'B-F', EXTEND(MDY(2,1,2007), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555005413', 46, 2006, 'B-F', EXTEND(MDY(2,1,2007), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555005429', 30, 2005, 'A-B', EXTEND(MDY(2,1,2006), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555005429', 31, 2005, 'A-B', EXTEND(MDY(1,30,2006), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555005429', 32, 2005, 'A-B', EXTEND(MDY(2,2,2006), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555005429', 33, 2005, 'A-B', EXTEND(MDY(1,31,2006), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555005429', 34, 2005, 'A-B', EXTEND(MDY(2,3,2006), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555005429', 35, 2005, 'A-B', EXTEND(MDY(6,28,2006), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555005429', 36, 2005, 'A-B', EXTEND(MDY(6,26,2006), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555005429', 37, 2005, 'A-B', EXTEND(MDY(6,27,2006), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555005429', 38, 2005, 'A-B', EXTEND(MDY(6,29,2006), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555005429', 39, 2005, 'A-B', EXTEND(MDY(6,30,2006), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555005429', 41, 2006, 'B-F', EXTEND(MDY(2,1,2007), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555005429', 42, 2006, 'B-F', EXTEND(MDY(2,1,2007), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555005429', 44, 2006, 'B-F', EXTEND(MDY(2,1,2007), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555005429', 45, 2006, 'B-F', EXTEND(MDY(2,1,2007), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555005429', 46, 2006, 'B-F', EXTEND(MDY(2,1,2007), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555005434', 30, 2005, 'A-F', EXTEND(MDY(2,1,2006), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555005434', 31, 2005, 'A-F', EXTEND(MDY(1,30,2006), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555005434', 32, 2005, 'A-F', EXTEND(MDY(2,2,2006), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555005434', 33, 2005, 'A-F', EXTEND(MDY(1,31,2006), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555005434', 34, 2005, 'A-F', EXTEND(MDY(2,3,2006), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555005434', 35, 2005, 'A-F', EXTEND(MDY(6,28,2006), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555005434', 36, 2005, 'A-F', EXTEND(MDY(6,26,2006), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555005434', 37, 2005, 'A-F', EXTEND(MDY(6,27,2006), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555005434', 38, 2005, 'A-F', EXTEND(MDY(6,29,2006), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555005434', 39, 2005, 'A-F', EXTEND(MDY(6,30,2006), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555005434', 41, 2006, 'B-H', EXTEND(MDY(2,1,2007), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555005434', 42, 2006, 'B-H', EXTEND(MDY(2,1,2007), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555005434', 44, 2006, 'B-H', EXTEND(MDY(2,1,2007), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555005434', 45, 2006, 'B-H', EXTEND(MDY(2,1,2007), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555005434', 46, 2006, 'B-H', EXTEND(MDY(2,1,2007), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555005455', 30, 2005, 'A-F', EXTEND(MDY(2,1,2006), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555005455', 31, 2005, 'A-F', EXTEND(MDY(1,30,2006), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555005455', 32, 2005, 'A-F', EXTEND(MDY(2,2,2006), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555005455', 33, 2005, 'A-F', EXTEND(MDY(1,31,2006), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555005455', 34, 2005, 'A-F', EXTEND(MDY(2,3,2006), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555005455', 35, 2005, 'A-F', EXTEND(MDY(6,28,2006), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555005455', 36, 2005, 'A-F', EXTEND(MDY(6,26,2006), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555005455', 37, 2005, 'A-F', EXTEND(MDY(6,27,2006), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555005455', 38, 2005, 'A-F', EXTEND(MDY(6,29,2006), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555005455', 39, 2005, 'A-F', EXTEND(MDY(6,30,2006), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555005455', 41, 2006, 'B-H', EXTEND(MDY(2,1,2007), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555005455', 42, 2006, 'B-H', EXTEND(MDY(2,1,2007), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555005455', 44, 2006, 'B-H', EXTEND(MDY(2,1,2007), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555005455', 45, 2006, 'B-H', EXTEND(MDY(2,1,2007), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555005455', 46, 2006, 'B-H', EXTEND(MDY(2,1,2007), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555005460', 30, 2005, 'A-A', EXTEND(MDY(2,1,2006), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555005460', 31, 2005, 'A-A', EXTEND(MDY(1,30,2006), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555005460', 32, 2005, 'A-A', EXTEND(MDY(2,2,2006), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555005460', 33, 2005, 'A-A', EXTEND(MDY(6,27,2006), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555005460', 34, 2005, 'A-A', EXTEND(MDY(2,3,2006), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555005460', 35, 2005, 'A-A', EXTEND(MDY(6,28,2006), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555005460', 36, 2005, 'A-A', EXTEND(MDY(6,26,2006), YEAR to SECOND), 1);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555005460', 39, 2005, 'A-A', EXTEND(MDY(6,30,2006), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555005460', 40, 2006, 'B-A', EXTEND(MDY(2,1,2007), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555005460', 41, 2006, 'B-C', EXTEND(MDY(2,1,2007), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555005460', 42, 2006, 'B-A', EXTEND(MDY(2,1,2007), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555005460', 43, 2006, 'B-C', EXTEND(MDY(2,1,2007), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555005460', 44, 2006, 'B-C', EXTEND(MDY(2,1,2007), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555005476', 30, 2005, 'A-K', EXTEND(MDY(2,1,2006), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555005476', 31, 2005, 'A-K', EXTEND(MDY(6,30,2006), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555005476', 32, 2005, 'A-K', EXTEND(MDY(6,29,2006), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555005476', 33, 2005, 'A-K', EXTEND(MDY(6,27,2006), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555005476', 34, 2005, 'A-K', EXTEND(MDY(2,3,2006), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555005476', 35, 2005, 'A-I', EXTEND(MDY(6,28,2006), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555005476', 39, 2005, 'A-K', EXTEND(MDY(6,30,2006), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555005476', 41, 2006, 'B-I', EXTEND(MDY(2,1,2007), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555005476', 42, 2006, 'A-O', EXTEND(MDY(2,1,2007), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555005476', 44, 2006, 'B-K', EXTEND(MDY(2,1,2007), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555005476', 45, 2006, 'B-J', EXTEND(MDY(2,1,2007), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555005481', 30, 2005, 'A-C', EXTEND(MDY(2,1,2006), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555005481', 31, 2005, 'A-C', EXTEND(MDY(6,30,2006), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555005481', 32, 2005, 'A-C', EXTEND(MDY(2,2,2006), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555005481', 33, 2005, 'A-C', EXTEND(MDY(1,31,2006), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555005481', 34, 2005, 'A-C', EXTEND(MDY(2,3,2006), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555005481', 35, 2005, 'A-A', EXTEND(MDY(6,28,2006), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555005481', 36, 2005, 'A-A', EXTEND(MDY(6,26,2006), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555005481', 37, 2005, 'A-A', EXTEND(MDY(6,27,2006), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555005481', 38, 2005, 'A-A', EXTEND(MDY(6,29,2006), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555005481', 39, 2005, 'A-C', EXTEND(MDY(6,30,2006), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555005481', 41, 2006, 'B-F', EXTEND(MDY(2,1,2007), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555005481', 42, 2006, 'B-F', EXTEND(MDY(2,1,2007), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555005481', 44, 2006, 'B-F', EXTEND(MDY(2,1,2007), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555005481', 45, 2006, 'B-F', EXTEND(MDY(2,1,2007), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555005481', 46, 2006, 'B-F', EXTEND(MDY(2,1,2007), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555005497', 30, 2006, 'A-A', EXTEND(MDY(2,1,2007), YEAR to SECOND), 1);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555005497', 31, 2006, 'A-A', EXTEND(MDY(2,1,2007), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555005497', 32, 2006, 'A-A', EXTEND(MDY(2,1,2007), YEAR to SECOND), 1);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555005497', 33, 2006, 'A-A', EXTEND(MDY(2,1,2007), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555005497', 34, 2006, 'A-A', EXTEND(MDY(2,1,2007), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555005504', 30, 2006, 'A-C', EXTEND(MDY(2,1,2007), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555005504', 31, 2006, 'A-C', EXTEND(MDY(2,1,2007), YEAR to SECOND), 1);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555005504', 32, 2006, 'A-C', EXTEND(MDY(2,1,2007), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555005504', 33, 2006, 'A-C', EXTEND(MDY(2,1,2007), YEAR to SECOND), 1);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555005504', 34, 2006, 'A-C', EXTEND(MDY(2,1,2007), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555005525', 30, 2006, 'A-E', EXTEND(MDY(2,1,2007), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555005525', 31, 2006, 'A-E', EXTEND(MDY(2,1,2007), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555005525', 32, 2006, 'A-E', EXTEND(MDY(2,1,2007), YEAR to SECOND), 1);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555005525', 33, 2006, 'A-E', EXTEND(MDY(2,1,2007), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555005525', 34, 2006, 'A-E', EXTEND(MDY(2,1,2007), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555005530', 30, 2006, 'A-F', EXTEND(MDY(2,1,2007), YEAR to SECOND), 1);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555005530', 31, 2006, 'A-F', EXTEND(MDY(2,1,2007), YEAR to SECOND), 1);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555005530', 32, 2006, 'A-F', EXTEND(MDY(2,1,2007), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555005530', 33, 2006, 'A-F', EXTEND(MDY(2,1,2007), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555005530', 34, 2006, 'A-F', EXTEND(MDY(2,1,2007), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555005546', 30, 2006, 'A-D', EXTEND(MDY(2,1,2007), YEAR to SECOND), 1);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555005546', 31, 2006, 'A-D', EXTEND(MDY(2,1,2007), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555005546', 32, 2006, 'A-D', EXTEND(MDY(2,1,2007), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555005546', 33, 2006, 'A-D', EXTEND(MDY(2,1,2007), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555005546', 34, 2006, 'A-D', EXTEND(MDY(2,1,2007), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555005551', 30, 2006, 'A-J', EXTEND(MDY(2,1,2007), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555005551', 31, 2006, 'A-J', EXTEND(MDY(2,1,2007), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555005551', 32, 2006, 'A-J', EXTEND(MDY(2,1,2007), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555005551', 33, 2006, 'A-J', EXTEND(MDY(2,1,2007), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555005551', 34, 2006, 'A-J', EXTEND(MDY(2,1,2007), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555005567', 30, 2006, 'A-I', EXTEND(MDY(2,1,2007), YEAR to SECOND), 1);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555005567', 31, 2006, 'A-I', EXTEND(MDY(2,1,2007), YEAR to SECOND), 1);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555005567', 32, 2006, 'A-I', EXTEND(MDY(2,1,2007), YEAR to SECOND), 1);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555005567', 33, 2006, 'A-I', EXTEND(MDY(2,1,2007), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555005567', 34, 2006, 'A-I', EXTEND(MDY(2,1,2007), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555005572', 30, 2006, 'A-F', EXTEND(MDY(2,1,2007), YEAR to SECOND), 1);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555005572', 31, 2006, 'A-F', EXTEND(MDY(2,1,2007), YEAR to SECOND), 1);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555005572', 32, 2006, 'A-F', EXTEND(MDY(2,1,2007), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555005572', 33, 2006, 'A-F', EXTEND(MDY(2,1,2007), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555005572', 34, 2006, 'A-F', EXTEND(MDY(2,1,2007), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555005588', 30, 2006, 'A-J', EXTEND(MDY(2,1,2007), YEAR to SECOND), 1);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555005588', 31, 2006, 'A-J', EXTEND(MDY(2,1,2007), YEAR to SECOND), 1);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555005588', 32, 2006, 'A-J', EXTEND(MDY(2,1,2007), YEAR to SECOND), 1);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555005588', 33, 2006, 'A-J', EXTEND(MDY(2,1,2007), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555005588', 34, 2006, 'A-J', EXTEND(MDY(2,1,2007), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555005593', 30, 2006, 'A-E', EXTEND(MDY(2,1,2007), YEAR to SECOND), 1);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555005593', 31, 2006, 'A-E', EXTEND(MDY(2,1,2007), YEAR to SECOND), 1);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555005593', 32, 2006, 'A-E', EXTEND(MDY(2,1,2007), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555005593', 33, 2006, 'A-E', EXTEND(MDY(2,1,2007), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555005593', 34, 2006, 'A-E', EXTEND(MDY(2,1,2007), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555005600', 30, 2006, 'A-C', EXTEND(MDY(2,1,2007), YEAR to SECOND), 1);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555005600', 31, 2006, 'A-C', EXTEND(MDY(2,1,2007), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555005600', 32, 2006, 'A-C', EXTEND(MDY(2,1,2007), YEAR to SECOND), 1);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555005600', 33, 2006, 'A-C', EXTEND(MDY(2,1,2007), YEAR to SECOND), 1);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555005600', 34, 2006, 'A-C', EXTEND(MDY(2,1,2007), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555005616', 30, 2006, 'A-I', EXTEND(MDY(2,1,2007), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555005616', 31, 2006, 'A-I', EXTEND(MDY(2,1,2007), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555005616', 32, 2006, 'A-I', EXTEND(MDY(2,1,2007), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555005616', 33, 2006, 'A-I', EXTEND(MDY(2,1,2007), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555005616', 34, 2006, 'A-I', EXTEND(MDY(2,1,2007), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555005621', 30, 2006, 'A-H', EXTEND(MDY(2,1,2007), YEAR to SECOND), 1);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555005621', 31, 2006, 'A-H', EXTEND(MDY(2,1,2007), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555005621', 32, 2006, 'A-H', EXTEND(MDY(2,1,2007), YEAR to SECOND), 1);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555005621', 33, 2006, 'A-H', EXTEND(MDY(2,1,2007), YEAR to SECOND), 1);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555005621', 34, 2006, 'A-H', EXTEND(MDY(2,1,2007), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555005637', 30, 2006, 'A-F', EXTEND(MDY(2,1,2007), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555005637', 31, 2006, 'A-F', EXTEND(MDY(2,1,2007), YEAR to SECOND), 1);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555005637', 32, 2006, 'A-F', EXTEND(MDY(2,1,2007), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555005637', 33, 2006, 'A-F', EXTEND(MDY(2,1,2007), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555005637', 34, 2006, 'A-F', EXTEND(MDY(2,1,2007), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555005642', 30, 2006, 'A-E', EXTEND(MDY(2,1,2007), YEAR to SECOND), 1);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555005642', 31, 2006, 'A-E', EXTEND(MDY(2,1,2007), YEAR to SECOND), 1);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555005642', 32, 2006, 'A-E', EXTEND(MDY(2,1,2007), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555005642', 33, 2006, 'A-E', EXTEND(MDY(2,1,2007), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555005642', 34, 2006, 'A-E', EXTEND(MDY(2,1,2007), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555005658', 30, 2006, 'A-H', EXTEND(MDY(2,1,2007), YEAR to SECOND), 1);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555005658', 31, 2006, 'A-H', EXTEND(MDY(2,1,2007), YEAR to SECOND), 1);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555005658', 32, 2006, 'A-H', EXTEND(MDY(2,1,2007), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555005658', 33, 2006, 'A-H', EXTEND(MDY(2,1,2007), YEAR to SECOND), 1);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555005658', 34, 2006, 'A-H', EXTEND(MDY(2,1,2007), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555005663', 30, 2006, 'A-H', EXTEND(MDY(2,1,2007), YEAR to SECOND), 1);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555005663', 31, 2006, 'A-H', EXTEND(MDY(2,1,2007), YEAR to SECOND), 1);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555005663', 32, 2006, 'A-H', EXTEND(MDY(2,1,2007), YEAR to SECOND), 1);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555005663', 33, 2006, 'A-H', EXTEND(MDY(2,1,2007), YEAR to SECOND), 1);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555005663', 34, 2006, 'A-H', EXTEND(MDY(2,1,2007), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555005679', 30, 2006, 'A-B', EXTEND(MDY(2,1,2007), YEAR to SECOND), 1);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555005679', 31, 2006, 'A-B', EXTEND(MDY(2,1,2007), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555005679', 32, 2006, 'A-B', EXTEND(MDY(2,1,2007), YEAR to SECOND), 1);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555005679', 33, 2006, 'A-B', EXTEND(MDY(2,1,2007), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555005679', 34, 2006, 'A-B', EXTEND(MDY(2,1,2007), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555005684', 30, 2006, 'A-G', EXTEND(MDY(2,1,2007), YEAR to SECOND), 1);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555005684', 31, 2006, 'A-G', EXTEND(MDY(2,1,2007), YEAR to SECOND), 1);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555005684', 32, 2006, 'A-G', EXTEND(MDY(2,1,2007), YEAR to SECOND), 1);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555005684', 33, 2006, 'A-G', EXTEND(MDY(2,1,2007), YEAR to SECOND), 1);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555005684', 34, 2006, 'A-G', EXTEND(MDY(2,1,2007), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555005707', 30, 2006, 'A-G', EXTEND(MDY(2,1,2007), YEAR to SECOND), 1);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555005707', 31, 2006, 'A-G', EXTEND(MDY(2,1,2007), YEAR to SECOND), 1);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555005707', 32, 2006, 'A-G', EXTEND(MDY(2,1,2007), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555005707', 33, 2006, 'A-G', EXTEND(MDY(2,1,2007), YEAR to SECOND), 1);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555005707', 34, 2006, 'A-G', EXTEND(MDY(2,1,2007), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555005712', 30, 2006, 'A-E', EXTEND(MDY(2,1,2007), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555005712', 31, 2006, 'A-E', EXTEND(MDY(2,1,2007), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555005712', 32, 2006, 'A-E', NULL, NULL);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555005712', 33, 2006, 'A-E', EXTEND(MDY(2,1,2007), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555005712', 34, 2006, 'A-E', EXTEND(MDY(2,1,2007), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555005733', 30, 2005, 'A-L', EXTEND(MDY(2,1,2006), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555005733', 31, 2005, 'A-L', EXTEND(MDY(2,1,2007), YEAR to SECOND), 1);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555005733', 31, 2006, 'A-K', EXTEND(MDY(2,1,2007), YEAR to SECOND), 1);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555005733', 32, 2005, 'A-L', EXTEND(MDY(2,2,2006), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555005733', 33, 2005, 'A-L', EXTEND(MDY(1,31,2006), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555005733', 34, 2005, 'A-L', EXTEND(MDY(2,3,2006), YEAR to SECOND), 3);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555005733', 35, 2005, 'A-B', EXTEND(MDY(6,28,2006), YEAR to SECOND), 1);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555005733', 37, 2005, 'A-D', EXTEND(MDY(6,27,2006), YEAR to SECOND), 1);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555005733', 38, 2005, 'A-B', EXTEND(MDY(6,29,2006), YEAR to SECOND), 1);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555005733', 39, 2005, 'A-D', EXTEND(MDY(6,30,2006), YEAR to SECOND), 2);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555005733', 41, 2006, 'B-H', EXTEND(MDY(2,1,2007), YEAR to SECOND), 5);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555005733', 44, 2006, 'B-H', EXTEND(MDY(2,1,2007), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555005749', 30, 2006, 'A-I', EXTEND(MDY(2,1,2007), YEAR to SECOND), 1);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555005749', 31, 2006, 'A-I', EXTEND(MDY(2,1,2007), YEAR to SECOND), 1);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555005749', 32, 2006, 'A-I', EXTEND(MDY(2,1,2007), YEAR to SECOND), 1);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555005749', 33, 2006, 'A-I', EXTEND(MDY(2,1,2007), YEAR to SECOND), 1);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555005749', 34, 2006, 'A-I', EXTEND(MDY(2,1,2007), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555005754', 31, 2006, 'A-B', EXTEND(MDY(2,1,2007), YEAR to SECOND), 4);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555005754', 32, 2006, 'A-B', EXTEND(MDY(2,1,2007), YEAR to SECOND), 1);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555005754', 33, 2006, 'A-B', EXTEND(MDY(2,1,2007), YEAR to SECOND), 1);
INSERT INTO upisanpredmet(jmbag, sifpredmet, akgodina, ozngrupa, datumocjena, ocjena)
  VALUES('0555005754', 34, 2006, 'A-B', EXTEND(MDY(2,1,2007), YEAR to SECOND), 3);

update statistics;