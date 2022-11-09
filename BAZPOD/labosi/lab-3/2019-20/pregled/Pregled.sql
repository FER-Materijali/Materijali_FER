CREATE TABLE Struka
(
  sifStruka INT NOT NULL,
  nazivStruka VARCHAR(50) NOT NULL,
  PRIMARY KEY (sifStruka),
  UNIQUE (nazivStruka)
);

CREATE TABLE UlicaTrg
(
  sifUlicaTrg INT NOT NULL,
  nazivUlicaTrg VARCHAR(50) NOT NULL,
  PRIMARY KEY (sifUlicaTrg)
);

CREATE TABLE VrstaStete
(
  sifVrStete INT NOT NULL,
  nazVrStete VARCHAR(50) NOT NULL,
  PRIMARY KEY (sifVrStete)
);

CREATE TABLE Osoba
(
  OIB VARCHAR(11) NOT NULL CONSTRAINT chkDuljOIBOsoba CHECK(length(OIB) = 11),
  ime VARCHAR(25) NOT NULL,
  prezime VARCHAR(25) NOT NULL,
  sifStruka INT,
  PRIMARY KEY (OIB),
  FOREIGN KEY (sifStruka) REFERENCES Struka(sifStruka)
);

CREATE TABLE Objekt
(
  sifObjekt INT NOT NULL,
  kucniBroj VARCHAR(10) NOT NULL,
  sifUlicaTrg INT NOT NULL,
  PRIMARY KEY (sifObjekt),
  FOREIGN KEY (sifUlicaTrg) REFERENCES UlicaTrg(sifUlicaTrg)
);

CREATE TABLE DioObjekt
(
  oznakaDioObjekt INT NOT NULL,
  sifObjekt INT NOT NULL,
  PRIMARY KEY (oznakaDioObjekt, sifObjekt),
  FOREIGN KEY (sifObjekt) REFERENCES Objekt(sifObjekt)
);

CREATE TABLE Zapisnik
(
  brojZapisnik INT NOT NULL,
  datumZapisnik DATE NOT NULL,
  oznakaDioObjekt INT NOT NULL,
  sifObjekt INT NOT NULL,
  PRIMARY KEY (brojZapisnik),
  FOREIGN KEY (oznakaDioObjekt, sifObjekt) REFERENCES DioObjekt(oznakaDioObjekt, sifObjekt)
);

CREATE TABLE Steta
(
  rbrSteta INT NOT NULL,
  napomena VARCHAR(150) NOT NULL,
  stupanjStete INT NOT NULL CONSTRAINT chkStupanjStete CHECK (stupanjStete >= 1 AND stupanjStete <= 10),
  brojZapisnik INT NOT NULL,
  sifVrStete INT NOT NULL,
  PRIMARY KEY (rbrSteta, brojZapisnik),
  FOREIGN KEY (brojZapisnik) REFERENCES Zapisnik(brojZapisnik),
  FOREIGN KEY (sifVrStete) REFERENCES VrstaStete(sifVrStete)
);

CREATE TABLE JeVlasnik
(
  oznakaDioObjekt INT NOT NULL,
  sifObjekt INT NOT NULL,
  OIB VARCHAR(11) NOT NULL,
  PRIMARY KEY (oznakaDioObjekt, sifObjekt, OIB),
  FOREIGN KEY (oznakaDioObjekt, sifObjekt) REFERENCES DioObjekt(oznakaDioObjekt, sifObjekt),
  FOREIGN KEY (OIB) REFERENCES Osoba(OIB)
);

CREATE TABLE Napisao
(
  OIB VARCHAR(11) NOT NULL,
  brojZapisnik INT NOT NULL,
  PRIMARY KEY (OIB, brojZapisnik),
  FOREIGN KEY (OIB) REFERENCES Osoba(OIB),
  FOREIGN KEY (brojZapisnik) REFERENCES Zapisnik(brojZapisnik)
);