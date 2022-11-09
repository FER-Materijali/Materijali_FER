/*
DROP TABLE ArtiklNarudzba;
DROP TABLE ARTIKL;
DROP TABLE NARUDZBA;
DROP TABLE OSOBA;
DROP TABLE baviSeDjelatnoscu;
DROP TABLE PODUZECE;
DROP TABLE Djelatnost;
DROP TABLE TERJED;
DROP TABLE VRTERJED;
*/

CREATE TABLE VRTERJED
(
  sifVrTerJed INT NOT NULL,
  nazVrTerJed VARCHAR(50) NOT NULL,
  PRIMARY KEY (sifVrTerJed)
);

CREATE TABLE TERJED
(
  sifTerJed INT NOT NULL,
  nazTerJed VARCHAR(50) NOT NULL,
  sifVrTerJed INT NOT NULL,
  nadTerJed_sifTerJed INT,
  PRIMARY KEY (sifTerJed),
  FOREIGN KEY (sifVrTerJed) REFERENCES VRTERJED(sifVrTerJed),
  FOREIGN KEY (nadTerJed_sifTerJed) REFERENCES TERJED(sifTerJed)
);

CREATE TABLE Djelatnost
(
  sifDjelatnost INT NOT NULL,
  nazDjelatnost VARCHAR(50) NOT NULL,
  PRIMARY KEY (sifDjelatnost),
  UNIQUE (nazDjelatnost)
);

CREATE TABLE PODUZECE
(
  sifPoduzece INT NOT NULL,
  nazPoduzece VARCHAR(50) NOT NULL,
  OIBpoduzece VARCHAR(11),
  sifTerJed INT NOT NULL,
  PRIMARY KEY (sifPoduzece),
  FOREIGN KEY (sifTerJed) REFERENCES TERJED(sifTerJed),
  UNIQUE (nazPoduzece),
  UNIQUE (OIBpoduzece)
);

CREATE TABLE baviSeDjelatnoscu
(
  sifPoduzece INT NOT NULL,
  sifDjelatnost INT NOT NULL,
  PRIMARY KEY (sifPoduzece, sifDjelatnost),
  FOREIGN KEY (sifPoduzece) REFERENCES PODUZECE(sifPoduzece),
  FOREIGN KEY (sifDjelatnost) REFERENCES Djelatnost(sifDjelatnost)
);

CREATE TABLE OSOBA
(
  OIBosoba VARCHAR(11) NOT NULL CONSTRAINT chkDuljOIBOsoba CHECK (LENGTH(OIBOsoba)=11),
  ime VARCHAR(25) NOT NULL,
  prezime VARCHAR(25) NOT NULL,
  datPocRO DATE NOT NULL,
  datKrajRO DATE,
  sifPoduzece INT NOT NULL,
  sifTerJed INT NOT NULL,
  PRIMARY KEY (OIBosoba),
  FOREIGN KEY (sifPoduzece) REFERENCES PODUZECE(sifPoduzece),
  FOREIGN KEY (sifTerJed) REFERENCES TERJED(sifTerJed),
  CONSTRAINT chkPocKrajRO CHECK (datKrajRO IS NULL OR datKrajRO > datPocRO)
);


CREATE TABLE NARUDZBA
(
  brNarudzba INT NOT NULL,
  datumNarudzba DATE NOT NULL,
  sifPoduzece INT NOT NULL,
  PRIMARY KEY (brNarudzba, sifPoduzece),
  FOREIGN KEY (sifPoduzece) REFERENCES PODUZECE(sifPoduzece)
);

CREATE TABLE ARTIKL
(
  sifArtikl INT NOT NULL,
  nazArtikl VARCHAR(50) NOT NULL,
  jedMjere VARCHAR(50) NOT NULL,
  PRIMARY KEY (sifArtikl)
);

CREATE TABLE ArtiklNarudzba
(
  kolicina INT NOT NULL,
  sifArtikl INT NOT NULL,
  brNarudzba INT NOT NULL,
  sifPoduzece INT NOT NULL,
  PRIMARY KEY (sifArtikl, brNarudzba, sifPoduzece),
  FOREIGN KEY (sifArtikl) REFERENCES ARTIKL(sifArtikl),
  FOREIGN KEY (brNarudzba, sifPoduzece) REFERENCES NARUDZBA(brNarudzba, sifPoduzece)
);

