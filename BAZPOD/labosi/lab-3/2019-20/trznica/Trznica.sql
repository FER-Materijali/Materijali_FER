CREATE TABLE VrsTerJed
(
  sifVrsTerJed INT NOT NULL,
  nazVrsTerJed VARCHAR(50) NOT NULL,
  PRIMARY KEY (sifVrsTerJed)
);

CREATE TABLE VrsOdjel
(
  sifVrsOdjel INT NOT NULL,
  nazVrsOdjel VARCHAR(50) NOT NULL,
  PRIMARY KEY (sifVrsOdjel)
);

CREATE TABLE Prodavac
(
  OIBProdavac VARCHAR(11) NOT NULL,
  imeProdavac VARCHAR(25) NOT NULL,
  prezProdavac VARCHAR(25) NOT NULL,
  PRIMARY KEY (OIBProdavac)
);

CREATE TABLE TerJed
(
  sifTerJed INT NOT NULL,
  nazTerJed VARCHAR(50) NOT NULL,
  sifVrsTerJed INT NOT NULL,
  ImaNadTerJed_sifTerJed INT,
  PRIMARY KEY (sifTerJed),
  FOREIGN KEY (sifVrsTerJed) REFERENCES VrsTerJed(sifVrsTerJed),
  FOREIGN KEY (ImaNadTerJed_sifTerJed) REFERENCES TerJed(sifTerJed)
);

CREATE TABLE Trznica
(
  sifTrznica INT NOT NULL,
  nazTrznica VARCHAR(50) NOT NULL,
  sifTerJed INT NOT NULL,
  PRIMARY KEY (sifTrznica),
  FOREIGN KEY (sifTerJed) REFERENCES TerJed(sifTerJed)
);

CREATE TABLE Odjel
(
  rbrOdjel INT NOT NULL CONSTRAINT chkRbrOdjel CHECK (rbrOdjel >=1 AND rbrOdjel <=50),
  nazivOdjel VARCHAR(50) NOT NULL,
  sifTrznica INT NOT NULL,
  sifVrsOdjel INT NOT NULL,
  PRIMARY KEY (rbrOdjel, sifTrznica),
  FOREIGN KEY (sifTrznica) REFERENCES Trznica(sifTrznica),
  FOREIGN KEY (sifVrsOdjel) REFERENCES VrsOdjel(sifVrsOdjel)
);

CREATE TABLE ProdMjesto
(
  sifProdMjesto INT NOT NULL,
  napomena VARCHAR(150) NOT NULL,
  rbrOdjel INT NOT NULL,
  sifTrznica INT NOT NULL,
  PRIMARY KEY (sifProdMjesto),
  FOREIGN KEY (rbrOdjel, sifTrznica) REFERENCES Odjel(rbrOdjel, sifTrznica)
);

CREATE TABLE Rezervacija
(
  datumRezervacija DATE NOT NULL,
  sifProdMjesto INT NOT NULL,
  OIBProdavac VARCHAR(11),
  PRIMARY KEY (datumRezervacija, sifProdMjesto),
  FOREIGN KEY (sifProdMjesto) REFERENCES ProdMjesto(sifProdMjesto),
  FOREIGN KEY (OIBProdavac) REFERENCES Prodavac(OIBProdavac),
  CONSTRAINT unOIBDatum UNIQUE (datumRezervacija, OIBProdavac)
);

