CREATE TABLE VRTERJED
(
  sifVrTerJed INT NOT NULL,
  nazVrTerJed VARCHAR(50) NOT NULL,
  PRIMARY KEY (sifVrTerJed)
);

CREATE TABLE VRPLOVILO
(
  sifVrPlovilo INT NOT NULL,
  nazVrPlovilo VARCHAR(50) NOT NULL,
  PRIMARY KEY (sifVrPlovilo),
  UNIQUE (nazVrPlovilo)
);

CREATE TABLE OKRUŽJE
(
  sifOkruzje INT NOT NULL,
  nazOkruzje VARCHAR(150) NOT NULL,
  PRIMARY KEY (sifOkruzje),
  UNIQUE (nazOkruzje)
);

CREATE TABLE PLOVILO
(
  sifPlovilo INT NOT NULL,
  nazPlovilo VARCHAR(50) NOT NULL,
  datIzgradnja DATE NOT NULL CONSTRAINT chkDatIzgradnja CHECK (datIzgradnja < CURRENT_DATE),
  kapacPutnici INT NOT NULL,
  kapacOsVozila INT NOT NULL,
  sifVrPlovilo INT NOT NULL,
  PRIMARY KEY (sifPlovilo),
  FOREIGN KEY (sifVrPlovilo) REFERENCES VRPLOVILO(sifVrPlovilo),
  UNIQUE (nazPlovilo),
  CONSTRAINT chkKapacitetPlovilo CHECK (kapacOsVozila > 0 AND kapacOsVozila < kapacPutnici)
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

CREATE TABLE LUKA
(
  sifLuka INT NOT NULL,
  nazLuka VARCHAR(25) NOT NULL,
  sifTerJed INT NOT NULL,
  PRIMARY KEY (sifLuka),
  FOREIGN KEY (sifTerJed) REFERENCES TERJED(sifTerJed)
);

CREATE TABLE LINIJA
(
  opis VARCHAR(100) NOT NULL,
  udaljenost NUMERIC(6,3) NOT NULL,
  sifLinija INT NOT NULL,
  sifLuka INT NOT NULL,
  lukaDolaskasifLuka INT NOT NULL,
  sifOkruzje INT NOT NULL,
  PRIMARY KEY (sifLinija),
  FOREIGN KEY (sifLuka) REFERENCES LUKA(sifLuka),
  FOREIGN KEY (lukaDolaskasifLuka) REFERENCES LUKA(sifLuka),
  FOREIGN KEY (sifOkruzje) REFERENCES OKRUŽJE(sifOkruzje)
);

CREATE TABLE PLOVRED
(
  datVrPolazak INT NOT NULL,
  sifLinija INT NOT NULL,
  sifPlovilo INT NOT NULL,
  PRIMARY KEY (datVrPolazak, sifLinija),
  FOREIGN KEY (sifLinija) REFERENCES LINIJA(sifLinija),
  FOREIGN KEY (sifPlovilo) REFERENCES PLOVILO(sifPlovilo)
);