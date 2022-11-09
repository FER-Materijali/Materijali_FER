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

CREATE TABLE SKOLA
(
  sifSkola INT NOT NULL,
  nazSkola VARCHAR(150) NOT NULL,
  URI VARCHAR(150),
  sifTerJed INT NOT NULL,
  PRIMARY KEY (sifSkola),
  FOREIGN KEY (sifTerJed) REFERENCES TERJED(sifTerJed),
  UNIQUE (URI)
);

CREATE TABLE SKGODINA
(
  sifSkGod INT NOT NULL,
  opisSkGod VARCHAR(15) NOT NULL,
  datumPoc DATE NOT NULL,
  datumKraj DATE NOT NULL,
  PRIMARY KEY (sifSkGod),
  UNIQUE (opisSkGod),
  CONSTRAINT chkPocKrajSkGod CHECK(datumPoc<datumKraj)
);

CREATE TABLE UCENIK
(
  ime VARCHAR(25) NOT NULL,
  prezime VARCHAR(25) NOT NULL,
  datRod DATE NOT NULL,
  sifUcenik INT NOT NULL,
  OIB VARCHAR(11),
  sifSkola INT NOT NULL,
  PRIMARY KEY (sifUcenik),
  FOREIGN KEY (sifSkola) REFERENCES SKOLA(sifSkola),
  UNIQUE (OIB)
);

CREATE TABLE RAZRED
(
  oznRazred CHAR(2) NOT NULL,
  rbrRazred INT NOT NULL CONSTRAINT chkRbrRazred CHECK(rbrRazred BETWEEN 1 AND 4),
  sifRazred INT NOT NULL,
  sifSkola INT NOT NULL,
  sifSkGod INT NOT NULL,
  PRIMARY KEY (sifRazred, sifSkola, sifSkGod),
  FOREIGN KEY (sifSkola) REFERENCES SKOLA(sifSkola),
  FOREIGN KEY (sifSkGod) REFERENCES SKGODINA(sifSkGod)
);

CREATE TABLE ucenikRazred
(
  prosjekOcj NUMERIC(5,3) NOT NULL,
  sifUcenik INT NOT NULL,
  sifRazred INT NOT NULL,
  sifSkola INT NOT NULL,
  sifSkGod INT NOT NULL,
  PRIMARY KEY (sifUcenik, sifRazred, sifSkola, sifSkGod),
  FOREIGN KEY (sifUcenik) REFERENCES UCENIK(sifUcenik),
  FOREIGN KEY (sifRazred, sifSkola, sifSkGod) REFERENCES RAZRED(sifRazred, sifSkola, sifSkGod)
);
