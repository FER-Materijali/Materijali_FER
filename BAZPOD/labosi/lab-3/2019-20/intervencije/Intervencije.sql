CREATE TABLE ulicaTrg
(
  sifUlicaTrg INT NOT NULL,
  nazivUlicaTrg VARCHAR(50) NOT NULL,
  PRIMARY KEY (sifUlicaTrg)
);

CREATE TABLE struka
(
  sifStruka INT NOT NULL,
  nazStruka VARCHAR(50) NOT NULL,
  PRIMARY KEY (sifStruka),
  UNIQUE (nazStruka)
);

CREATE TABLE proizvodac
(
  sifProziv INT NOT NULL,
  nazProizv VARCHAR(50) NOT NULL,
  PRIMARY KEY (sifProziv)
);

CREATE TABLE objekt
(
  sifObjekt INT NOT NULL,
  kbr VARCHAR(10) NOT NULL,
  sifUlicaTrg INT NOT NULL,
  PRIMARY KEY (sifObjekt),
  FOREIGN KEY (sifUlicaTrg) REFERENCES ulicaTrg(sifUlicaTrg)
);

CREATE TABLE dioObjekta
(
  oznaka VARCHAR(10) NOT NULL,
  sifObjekt INT NOT NULL,
  PRIMARY KEY (oznaka, sifObjekt),
  FOREIGN KEY (sifObjekt) REFERENCES objekt(sifObjekt)
);

CREATE TABLE intervencija
(
  sifIntervencija INT NOT NULL,
  datum DATE NOT NULL,
  vrPocetak VARCHAR(10) NOT NULL,
  vrZavrsetak VARCHAR(10),
  zahtjevnost INT NOT NULL,
  oznaka VARCHAR(10) NOT NULL,
  sifObjekt INT NOT NULL,
  PRIMARY KEY (sifIntervencija),
  FOREIGN KEY (oznaka, sifObjekt) REFERENCES dioObjekta(oznaka, sifObjekt),
  CONSTRAINT chkZahtjevnost CHECK (zahtjevnost >= 1 AND zahtjevnost <= 5)
);

CREATE TABLE osoba
(
  oib CHAR(11) NOT NULL,
  ime VARCHAR(25) NOT NULL,
  prezime VARCHAR(25) NOT NULL,
  sifStruka INT NOT NULL,
  PRIMARY KEY (oib),
  FOREIGN KEY (sifStruka) REFERENCES struka(sifStruka),
  CONSTRAINT chkDuljOIBOsoba CHECK (length(OIB)=11)
);

CREATE TABLE stroj
(
  sifStroj INT NOT NULL,
  nazStroj VARCHAR(50) NOT NULL,
  sifProziv INT NOT NULL,
  PRIMARY KEY (sifStroj),
  FOREIGN KEY (sifProziv) REFERENCES proizvodac(sifProziv)
);

CREATE TABLE sudjelujeOsoba
(
  brSati INT NOT NULL,
  sifIntervencija INT NOT NULL,
  oib CHAR(11) NOT NULL,
  PRIMARY KEY (sifIntervencija, oib),
  FOREIGN KEY (sifIntervencija) REFERENCES intervencija(sifIntervencija),
  FOREIGN KEY (oib) REFERENCES osoba(oib)
);

CREATE TABLE sudjeluje
(
  brSati INT NOT NULL,
  sifStroj INT NOT NULL,
  sifIntervencija INT NOT NULL,
  PRIMARY KEY (sifStroj, sifIntervencija),
  FOREIGN KEY (sifStroj) REFERENCES stroj(sifStroj),
  FOREIGN KEY (sifIntervencija) REFERENCES intervencija(sifIntervencija)
);
