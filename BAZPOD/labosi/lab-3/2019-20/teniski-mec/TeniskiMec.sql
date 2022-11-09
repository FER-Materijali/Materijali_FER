/*
DROP TABLE SETMEC;
DROP TABLE MEC;
DROP TABLE INSTTURNIR;
DROP TABLE TEREN;
DROP TABLE TURNIR;
DROP TABLE KATTURNIR;
DROP TABLE TENISAC;
DROP TABLE DRZAVA;
*/


CREATE TABLE TEREN
(
  sifTeren INT NOT NULL,
  opisTeren VARCHAR(25) NOT NULL,
  PRIMARY KEY (sifTeren)
);

CREATE TABLE DRZAVA
(
  oznDrzava CHAR(2) NOT NULL,
  nazDrzava VARCHAR(50) NOT NULL,
  PRIMARY KEY (oznDrzava),
  UNIQUE (nazDrzava)
);

CREATE TABLE TENISAC
(
  ime VARCHAR(25) NOT NULL,
  prezime VARCHAR(25) NOT NULL,
  sifTenisac INT NOT NULL,
  brBodovaATP INT NOT NULL CONSTRAINT chkBrojATPBodova CHECK(brBodovaATP > 0), 
				/* ovo je onaj chkUkupnoGemova */
  oznDrzava CHAR(2) NOT NULL,
  PRIMARY KEY (sifTenisac),
  FOREIGN KEY (oznDrzava) REFERENCES DRZAVA(oznDrzava)
);

CREATE TABLE MEC
(
  datVrijemePoc DATE NOT NULL,
  sifMec INT NOT NULL,
  trajanje INT NOT NULL,
  tenisac1 INT NOT NULL,
  tenisac2 INT NOT NULL,
  sifTeren INT NOT NULL,
  datPocetak INT NOT NULL,
  sifTurnir INT NOT NULL,
  PRIMARY KEY (sifMec),
  FOREIGN KEY (tenisac1) REFERENCES TENISAC(sifTenisac),
  FOREIGN KEY (tenisac2) REFERENCES TENISAC(sifTenisac),
  FOREIGN KEY (sifTeren) REFERENCES TEREN(sifTeren),
  FOREIGN KEY (datPocetak, sifTurnir) REFERENCES INSTTURNIR(datPocetak, sifTurnir)
);

CREATE TABLE INSTTURNIR
(
  datPocetak INT NOT NULL,
  nagradniFond INT NOT NULL CONSTRAINT chkNagradniFond CHECK (nagradniFond > 0),
  sifTurnir INT NOT NULL,
  PRIMARY KEY (datPocetak, sifTurnir),
  FOREIGN KEY (sifTurnir) REFERENCES TURNIR(sifTurnir)
);

CREATE TABLE TURNIR
(
  sifTurnir INT NOT NULL,
  nazTurnir VARCHAR(100) NOT NULL,
  godOsnutak INT NOT NULL,
  webURL VARCHAR(200),
  sifKatTurnir INT NOT NULL,
  PRIMARY KEY (sifTurnir),
  FOREIGN KEY (sifKatTurnir) REFERENCES KATTURNIR(sifKatTurnir),
  UNIQUE (nazTurnir),
  UNIQUE (webURL)
);

CREATE TABLE KATTURNIR
(
  sifKatTurnir INT NOT NULL,
  nazKatTurnir VARCHAR(100) NOT NULL,
  nadKategorija_sifKatTurnir INT,
  PRIMARY KEY (sifKatTurnir),
  FOREIGN KEY (nadKategorija_sifKatTurnir) REFERENCES KATTURNIR(sifKatTurnir),
  UNIQUE (nazKatTurnir)
);

CREATE TABLE SETMEC
(
  rbrSet INT NOT NULL,
  osvojioGemovaI1 INT NOT NULL,
  osvojioGemovaI2 INT NOT NULL,
  sifMec INT NOT NULL,
  PRIMARY KEY (rbrSet, sifMec),
  FOREIGN KEY (sifMec) REFERENCES MEC(sifMec)
);
