CREATE TABLE IZDAVAC
(
  sifraIzd INT NOT NULL,
  nazivIzd VARCHAR(100) NOT NULL,
  godOsnIzd INT NOT NULL,
  PRIMARY KEY (sifraIzd),
  UNIQUE (nazivIzd)
);

CREATE TABLE PERIODA
(
  sifraPer INT NOT NULL,
  opisPer VARCHAR(50) NOT NULL,
  PRIMARY KEY (sifraPer)
);

CREATE TABLE ZNANSTPOD
(
  sifraZp INT NOT NULL,
  nazivZp VARCHAR(200) NOT NULL,
  PRIMARY KEY (sifraZp),
  UNIQUE (nazivZp)
);

CREATE TABLE AUTOR
(
  sifOsoba INT NOT NULL,
  ime VARCHAR(25) NOT NULL,
  prezime VARCHAR(25) NOT NULL,
  email VARCHAR(50) NOT NULL,
  PRIMARY KEY (sifOsoba),
  UNIQUE (email)
);

CREATE TABLE CASOPIS
(
  sifraCas INT NOT NULL,
  nazivCas VARCHAR(100) NOT NULL,
  URICas VARCHAR(100) NOT NULL,
  godOsnCas INT NOT NULL,
  sifraIzd INT NOT NULL,
  sifraPer INT NOT NULL,
  PRIMARY KEY (sifraCas),
  FOREIGN KEY (sifraIzd) REFERENCES IZDAVAC(sifraIzd),
  FOREIGN KEY (sifraPer) REFERENCES PERIODA(sifraPer),
  UNIQUE (nazivCas),
  UNIQUE (URICas),
  CONSTRAINT chkGodinaOsnutka CHECK godOsnCas <= EXTRACT(YEAR FROM CURRENT_DATE)
);

CREATE TABLE IZDANJE
(
  datumIzd DATE NOT NULL,
  sifraCas INT NOT NULL,
  PRIMARY KEY (datumIzd, sifraCas),
  FOREIGN KEY (sifraCas) REFERENCES CASOPIS(sifraCas)
);

CREATE TABLE CLANAK
(
  rbr INT NOT NULL,
  naslovClanak VARCHAR(250) NOT NULL,
  sazetak VARCHAR(1000) NOT NULL,
  datumIzd DATE NOT NULL,
  sifraCas INT NOT NULL,
  PRIMARY KEY (rbr, datumIzd, sifraCas),
  FOREIGN KEY (datumIzd, sifraCas) REFERENCES IZDANJE(datumIzd, sifraCas),
  CONSTRAINT chkRbrClanak CHECK rbr BETWEEN 1 AND 100
);

CREATE TABLE pripada
(
  sifraCas INT NOT NULL,
  sifraZp INT NOT NULL,
  PRIMARY KEY (sifraCas, sifraZp),
  FOREIGN KEY (sifraCas) REFERENCES CASOPIS(sifraCas),
  FOREIGN KEY (sifraZp) REFERENCES ZNANSTPOD(sifraZp)
);

CREATE TABLE jeAutor
(
  rbr INT NOT NULL,
  datumIzd DATE NOT NULL,
  sifraCas INT NOT NULL,
  sifOsoba INT NOT NULL,
  PRIMARY KEY (rbr, datumIzd, sifraCas, sifOsoba),
  FOREIGN KEY (rbr, datumIzd, sifraCas) REFERENCES CLANAK(rbr, datumIzd, sifraCas),
  FOREIGN KEY (sifOsoba) REFERENCES AUTOR(sifOsoba)
);

CREATE TABLE referencira
(
  rbr_1 INT NOT NULL,
  datumIzd DATE NOT NULL,
  sifraCas INT NOT NULL,
  referencirarbr_2 INT NOT NULL,
  referenciradatumIzd DATE NOT NULL,
  referencirasifraCas INT NOT NULL,
  PRIMARY KEY (rbr_1, datumIzd, sifraCas, referencirarbr_2, referenciradatumIzd, referencirasifraCas),
  FOREIGN KEY (rbr_1, datumIzd, sifraCas) REFERENCES CLANAK(rbr, datumIzd, sifraCas),
  FOREIGN KEY (referencirarbr_2, referenciradatumIzd, referencirasifraCas) REFERENCES CLANAK(rbr, datumIzd, sifraCas),
  CONSTRAINT chkRef CHECK NOT (rbr_1 == referencirarbr_2 AND datumIzd == referenciradatumIzd AND sifraCas == referencirasifraCas)
);


