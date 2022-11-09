--6.predavanje, 21.slajd

CREATE TABLE ispit(
	mbr INTEGER,
	sifPred INTEGER,
	datIspit DATE,
	sifNast INTEGER,
	ocjena INTEGER);

INSERT INTO ispit VALUES(101,10,'30.1.2006',1003,1);
INSERT INTO ispit VALUES(101,10,'15.1.2007',1002,4);
INSERT INTO ispit VALUES(102,10,'30.1.2006',1001,3);
INSERT INTO ispit VALUES(102,11,'15.1.2006',1002,5);





select * from ispit as t1, ispit as t2
	WHERE t1.mbr=t2.mbr
		AND t1.sifNast=t2.sifNast
		AND (t1.ocjena <>t2.ocjena
			OR t1.datIspit <> t2.datIspit);

-funkcijska zavisnost možda vrijedi 