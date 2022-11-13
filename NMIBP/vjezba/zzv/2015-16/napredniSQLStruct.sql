--uspostaviti vezu s bazom podataka i obaviti naredbe u nastavku

SET DateStyle = 'German, DMY';
--DROP TABLE projekt;
--DROP TABLE djelIsplata;
--DROP TABLE djelatnik;
--DROP TABLE orgjed;


CREATE TABLE orgJed (
sifOrgJed int CONSTRAINT pkOrgJed PRIMARY KEY,
nazOrgJed CHAR(25) NOT NULL);

CREATE TABLE djelatnik (
sifDjel 	int CONSTRAINT pkDjelatnik PRIMARY KEY,
imeDjel 	CHAR(25) NOT NULL,
prezDjel 	CHAR(25) NOT NULL,
sifOrgJed 		int 	 NOT NULL CONSTRAINT fkDjelatnikOJ REFERENCES orgJed(sifOrgJed),
sifNadrDjel 	int 	          CONSTRAINT fkDjelNadDjel REFERENCES djelatnik(sifDjel)
);

CREATE TABLE djelIsplata (
sifDjel int CONSTRAINT fkDjelIsplataD REFERENCES djelatnik(sifDjel) ,
datumisplata DATE,
iznos numeric (9,2) NOT NULL
, CONSTRAINT pkDjelIsplata PRIMARY KEY (sifDjel, datumisplata));

CREATE TABLE projekt (
sifProjekt int,
sifNadlDjel int CONSTRAINT fkProjektDjel REFERENCES djelatnik(sifDjel) ,
datumPoc DATE,
datumKraj DATE,
CONSTRAINT pkProjekt PRIMARY KEY (sifProjekt, sifNadlDjel));

INSERT INTO orgJed VALUES (1, 'Maloprodaja Radnička');
INSERT INTO orgJed VALUES (2, 'Maloprodaja Vukovarska');
INSERT INTO orgJed VALUES (3, 'Maloprodaja Ilica');

INSERT INTO djelatnik VALUES (1, 'Ana'    , 'Par'   , 1, null);
INSERT INTO djelatnik VALUES (2, 'Šime'   , 'Knez'  , 1, 1);
INSERT INTO djelatnik VALUES (3, 'Petra'  , 'Pilić' , 1, 1);
INSERT INTO djelatnik VALUES (4, 'Anita'  , 'Kralj' , 2, 2);
INSERT INTO djelatnik VALUES (5, 'Marko'  , 'Jelić' , 2, 2);
INSERT INTO djelatnik VALUES (6, 'Marija' , 'Burić' , 3, 4);
INSERT INTO djelatnik VALUES (7, 'Slavica', 'Rendić', 3, 6);
INSERT INTO djelatnik VALUES (8, 'Petar'  , 'Milić' , 3, 7);

INSERT INTO djelIsplata VALUES (1, '01.01.2013', 4700.00);
INSERT INTO djelIsplata VALUES (1, '01.02.2013', 4700.00);
INSERT INTO djelIsplata VALUES (1, '01.03.2013', 4700.00);
INSERT INTO djelIsplata VALUES (1, '01.04.2013', 4700.00);
INSERT INTO djelIsplata VALUES (1, '01.05.2013', 4750.00);
INSERT INTO djelIsplata VALUES (1, '01.06.2013', 4750.00);
INSERT INTO djelIsplata VALUES (1, '01.07.2013', 4900.00);
INSERT INTO djelIsplata VALUES (1, '01.08.2013', 4900.00);
INSERT INTO djelIsplata VALUES (1, '01.09.2013', 4900.00);

INSERT INTO djelIsplata VALUES (2, '01.01.2013', 3770.00);
INSERT INTO djelIsplata VALUES (2, '01.02.2013', 3770.00);
INSERT INTO djelIsplata VALUES (2, '01.03.2013', 4000.00);
INSERT INTO djelIsplata VALUES (2, '01.04.2013', 4770.00);
INSERT INTO djelIsplata VALUES (2, '01.05.2013', 4770.00);
INSERT INTO djelIsplata VALUES (2, '01.06.2013', 4770.00);
INSERT INTO djelIsplata VALUES (2, '01.07.2013', 5000.00);
INSERT INTO djelIsplata VALUES (2, '01.08.2013', 5000.00);
INSERT INTO djelIsplata VALUES (2, '01.09.2013', 5000.00);

INSERT INTO djelIsplata VALUES (3, '01.01.2013', 3500.00);
INSERT INTO djelIsplata VALUES (3, '01.02.2013', 3500.00);
INSERT INTO djelIsplata VALUES (3, '01.03.2013', 3500.00);
INSERT INTO djelIsplata VALUES (3, '01.04.2013', 3500.00);
INSERT INTO djelIsplata VALUES (3, '01.05.2013', 3500.00);
INSERT INTO djelIsplata VALUES (3, '01.06.2013', 3500.00);
INSERT INTO djelIsplata VALUES (3, '01.07.2013', 3800.00);
INSERT INTO djelIsplata VALUES (3, '01.08.2013', 3800.00);
INSERT INTO djelIsplata VALUES (3, '01.09.2013', 3800.00);

INSERT INTO djelIsplata VALUES (4, '01.01.2013', 8700.00);
INSERT INTO djelIsplata VALUES (4, '01.02.2013', 8700.00);
INSERT INTO djelIsplata VALUES (4, '01.03.2013', 8700.00);
INSERT INTO djelIsplata VALUES (4, '01.04.2013', 8700.00);
INSERT INTO djelIsplata VALUES (4, '01.05.2013', 8700.00);
INSERT INTO djelIsplata VALUES (4, '01.06.2013', 8700.00);
INSERT INTO djelIsplata VALUES (4, '01.07.2013', 8900.00);
INSERT INTO djelIsplata VALUES (4, '01.08.2013', 8900.00);
INSERT INTO djelIsplata VALUES (4, '01.09.2013', 8900.00);

INSERT INTO djelIsplata VALUES (5, '01.01.2013', 7500.00);
INSERT INTO djelIsplata VALUES (5, '01.02.2013', 7500.00);
INSERT INTO djelIsplata VALUES (5, '01.03.2013', 7500.00);
INSERT INTO djelIsplata VALUES (5, '01.04.2013', 7500.00);
INSERT INTO djelIsplata VALUES (5, '01.05.2013', 7500.00);
INSERT INTO djelIsplata VALUES (5, '01.06.2013', 7500.00);
INSERT INTO djelIsplata VALUES (5, '01.07.2013', 7500.00);
INSERT INTO djelIsplata VALUES (5, '01.08.2013', 7500.00);
INSERT INTO djelIsplata VALUES (5, '01.09.2013', 7500.00);

INSERT INTO djelIsplata VALUES (6, '01.01.2013', 10700.00);
INSERT INTO djelIsplata VALUES (6, '01.02.2013', 10700.00);
INSERT INTO djelIsplata VALUES (6, '01.03.2013', 10700.00);
INSERT INTO djelIsplata VALUES (6, '01.04.2013', 10700.00);
INSERT INTO djelIsplata VALUES (6, '01.05.2013', 10700.00);
INSERT INTO djelIsplata VALUES (6, '01.06.2013', 10700.00);
INSERT INTO djelIsplata VALUES (6, '01.07.2013', 10900.00);
INSERT INTO djelIsplata VALUES (6, '01.08.2013', 10900.00);
INSERT INTO djelIsplata VALUES (6, '01.09.2013', 10900.00);

INSERT INTO djelIsplata VALUES (7, '01.01.2013', 6070.00);
INSERT INTO djelIsplata VALUES (7, '01.02.2013', 6070.00);
INSERT INTO djelIsplata VALUES (7, '01.03.2013', 6070.00);
INSERT INTO djelIsplata VALUES (7, '01.04.2013', 6070.00);
INSERT INTO djelIsplata VALUES (7, '01.05.2013', 6070.00);
INSERT INTO djelIsplata VALUES (7, '01.06.2013', 6070.00);
INSERT INTO djelIsplata VALUES (7, '01.07.2013', 6000.00);
INSERT INTO djelIsplata VALUES (7, '01.08.2013', 6000.00);
INSERT INTO djelIsplata VALUES (7, '01.09.2013', 6000.00);

INSERT INTO djelIsplata VALUES (8, '01.01.2013', 2900.00);
INSERT INTO djelIsplata VALUES (8, '01.02.2013', 2900.00);
INSERT INTO djelIsplata VALUES (8, '01.03.2013', 2900.00);
INSERT INTO djelIsplata VALUES (8, '01.04.2013', 2900.00);
INSERT INTO djelIsplata VALUES (8, '01.05.2013', 2900.00);
INSERT INTO djelIsplata VALUES (8, '01.06.2013', 2900.00);
INSERT INTO djelIsplata VALUES (8, '01.07.2013', 2900.00);
INSERT INTO djelIsplata VALUES (8, '01.08.2013', 2900.00);
INSERT INTO djelIsplata VALUES (8, '01.09.2013', 2900.00);

INSERT INTO projekt VALUES (345, 1, '01.3.2013', '20.07.2013');
INSERT INTO projekt VALUES (746, 2, '05.4.2013', '15.08.2013');
