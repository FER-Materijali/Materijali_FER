/*
DROP TABLE REDLETENJA;
DROP TABLE LET;
DROP TABLE AVION;
DROP TABLE VRAVION;
DROP TABLE PROIZVODJAC;
DROP TABLE PRIJEVOZNIK;
DROP TABLE ZRLUKA;
DROP TABLE GRAD;
DROP TABLE DRZAVA;

*/

CREATE TABLE DRZAVA
(
  kratDrzava CHAR(2) NOT NULL,
  nazDrzava VARCHAR(50) NOT NULL,
  PRIMARY KEY (kratDrzava),
  UNIQUE (nazDrzava)
);

CREATE TABLE GRAD
(
  sifGrad INT NOT NULL,
  nazGrad VARCHAR(50) NOT NULL,
  postOzn INT NOT NULL,
  kratDrzava CHAR(2) NOT NULL,
  PRIMARY KEY (sifGrad),
  FOREIGN KEY (kratDrzava) REFERENCES DRZAVA(kratDrzava)
);

CREATE TABLE ZRLUKA
(
  sifZrLuka INT NOT NULL,
  nazZrLuka VARCHAR(50) NOT NULL,
  sifGrad INT NOT NULL,
  PRIMARY KEY (sifZrLuka),
  FOREIGN KEY (sifGrad) REFERENCES GRAD(sifGrad)
);

CREATE TABLE PROIZVODJAC
(
  sifProizvodjac INT NOT NULL,
  nazProizvodjac VARCHAR(80) NOT NULL,
  PRIMARY KEY (sifProizvodjac),
  UNIQUE (nazProizvodjac)
);

CREATE TABLE PRIJEVOZNIK
(
  sifPrijevoznik INT NOT NULL,
  nazPrijevoznik VARCHAR(80) NOT NULL,
  PRIMARY KEY (sifPrijevoznik),
  UNIQUE (nazPrijevoznik)
);

CREATE TABLE VRAVION
(
  sifVrAvion INT NOT NULL,
  nazVrAvion VARCHAR(80) NOT NULL,
  brPutSjedala INT NOT NULL  CONSTRAINT chkBrPutSjedala CHECK(brPutSjedala BETWEEN 20 AND 1000),
  dupustenaTezina NUMERIC(10,2) NOT NULL,
  najvecaVisina INT NOT NULL,
  sifProizvodjac INT NOT NULL,
  PRIMARY KEY (sifVrAvion),
  FOREIGN KEY (sifProizvodjac) REFERENCES PROIZVODJAC(sifProizvodjac),
  UNIQUE (nazVrAvion)
);

CREATE TABLE AVION
(
  sifAvion INT NOT NULL,
  opisAvion VARCHAR(200) NOT NULL,
  datIzgradnja DATE NOT NULL CONSTRAINT chkDatIzgradAvion CHECK(datIzgradnja<CURRENT_DATE),
  sifVrAvion INT NOT NULL,
  sifPrijevoznik INT NOT NULL,
  PRIMARY KEY (sifAvion),
  FOREIGN KEY (sifVrAvion) REFERENCES VRAVION(sifVrAvion),
  FOREIGN KEY (sifPrijevoznik) REFERENCES PRIJEVOZNIK(sifPrijevoznik)
);

CREATE TABLE LET
(
  opis INT NOT NULL,
  udaljenost NUMERIC(10,2) NOT NULL,
  sifLet INT NOT NULL,
  sifZrLuka INT NOT NULL,
  lukaDolaskasifZrLuka INT NOT NULL,
  PRIMARY KEY (sifLet),
  FOREIGN KEY (sifZrLuka) REFERENCES ZRLUKA(sifZrLuka),
  FOREIGN KEY (lukaDolaskasifZrLuka) REFERENCES ZRLUKA(sifZrLuka)
);

CREATE TABLE REDLETENJA
(
  datVrPolazak INT NOT NULL,
  sifLet INT NOT NULL,
  sifAvion INT NOT NULL,
  sifPrijevoznik INT NOT NULL,
  PRIMARY KEY (datVrPolazak, sifLet),
  FOREIGN KEY (sifLet) REFERENCES LET(sifLet),
  FOREIGN KEY (sifAvion) REFERENCES AVION(sifAvion),
  FOREIGN KEY (sifPrijevoznik) REFERENCES PRIJEVOZNIK(sifPrijevoznik)
);

