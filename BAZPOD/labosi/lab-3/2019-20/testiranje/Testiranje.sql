CREATE TABLE Osoba
(
  OIB VARCHAR(11) NOT NULL CONSTRAINT chkOIB CHECK(length(OIB) = 11),
  ime VARCHAR(25) NOT NULL,
  prezime VARCHAR(25) NOT NULL,
  PRIMARY KEY (OIB)
);

CREATE TABLE Proizvodjac
(
  sifProizvodjac INT NOT NULL,
  nazivProizvodjac VARCHAR(50) NOT NULL,
  PRIMARY KEY (sifProizvodjac)
);

CREATE TABLE VrstaTerJedinice
(
  sifVrTerJedinice INT NOT NULL,
  nazVrTerJedinice VARCHAR(50) NOT NULL,
  PRIMARY KEY (sifVrTerJedinice)
);

CREATE TABLE BilaUKontaktu
(
  OIB_1 VARCHAR(11) NOT NULL,
  BilaUKontaktuOIB_2 VARCHAR(11) NOT NULL,
  PRIMARY KEY (OIB_1, BilaUKontaktuOIB_2),
  FOREIGN KEY (OIB_1) REFERENCES Osoba(OIB),
  FOREIGN KEY (BilaUKontaktuOIB_2) REFERENCES Osoba(OIB)
);

CREATE TABLE Test
(
  sifTest INT NOT NULL,
  nazivTest VARCHAR(50) NOT NULL,
  sifProizvodjac INT NOT NULL,
  PRIMARY KEY (sifTest),
  FOREIGN KEY (sifProizvodjac) REFERENCES Proizvodjac(sifProizvodjac),
  UNIQUE (nazivTest)
);

CREATE TABLE TerJedinica
(
  sifTerJedinica INT NOT NULL,
  nazivTerJedinica VARCHAR(50) NOT NULL,
  sifVrTerJedinice INT NOT NULL,
  JeNadredena_sifTerJedinica INT,
  PRIMARY KEY (sifTerJedinica),
  FOREIGN KEY (sifVrTerJedinice) REFERENCES VrstaTerJedinice(sifVrTerJedinice),
  FOREIGN KEY (JeNadredena_sifTerJedinica) REFERENCES TerJedinica(sifTerJedinica)
);

CREATE TABLE Ustanova
(
  sifUstanova INT NOT NULL,
  nazivUstanova VARCHAR(50) NOT NULL,
  sifTerJedinica INT NOT NULL,
  PRIMARY KEY (sifUstanova),
  FOREIGN KEY (sifTerJedinica) REFERENCES TerJedinica(sifTerJedinica)
);

CREATE TABLE Laboratorij
(
  oznakaLaboratorij INT NOT NULL,
  sifUstanova INT NOT NULL,
  PRIMARY KEY (oznakaLaboratorij, sifUstanova),
  FOREIGN KEY (sifUstanova) REFERENCES Ustanova(sifUstanova)
);

CREATE TABLE Testiranje
(
  sifTestiranje INT NOT NULL,
  datumTestiranje DATE NOT NULL,
  rezultat INT CONSTRAINT chkRezultat CHECK(rezultat IN (0,1)),
  OIB VARCHAR(11) NOT NULL,
  JeTestiranaOIB VARCHAR(11) NOT NULL,
  sifTest INT NOT NULL,
  oznakaLaboratorij INT NOT NULL,
  sifUstanova INT NOT NULL,
  PRIMARY KEY (sifTestiranje),
  FOREIGN KEY (OIB) REFERENCES Osoba(OIB),
  FOREIGN KEY (JeTestiranaOIB) REFERENCES Osoba(OIB),
  FOREIGN KEY (sifTest) REFERENCES Test(sifTest),
  FOREIGN KEY (oznakaLaboratorij, sifUstanova) REFERENCES Laboratorij(oznakaLaboratorij, sifUstanova)
);



