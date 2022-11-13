CREATE EXTENSION fuzzystrmatch;
CREATE EXTENSION pg_trgm;

CREATE TABLE serije (
    serija_id serial primary key,
    serija_naziv varchar(100) NOT NULL,
    naziv_tsvector tsvector
);

INSERT INTO serije(serija_naziv, naziv_tsvector) VALUES('Pilot', to_tsvector('Pilot'));
INSERT INTO serije(serija_naziv, naziv_tsvector) VALUES('Friday Night Bites', to_tsvector('Friday Night Bites'));
INSERT INTO serije(serija_naziv, naziv_tsvector) VALUES('Family Ties', to_tsvector('Family Ties'));
INSERT INTO serije(serija_naziv, naziv_tsvector) VALUES('Youre Undead to Me', to_tsvector('Youre Undead to Me'));
INSERT INTO serije(serija_naziv, naziv_tsvector) VALUES('Lost Girls	', to_tsvector('Lost Girls'));
INSERT INTO serije(serija_naziv, naziv_tsvector) VALUES('Haunted', to_tsvector('Haunted'));
INSERT INTO serije(serija_naziv, naziv_tsvector) VALUES('162 Candles', to_tsvector('162 Candles'));
INSERT INTO serije(serija_naziv, naziv_tsvector) VALUES('History Repeating', to_tsvector('History Repeating'));
INSERT INTO serije(serija_naziv, naziv_tsvector) VALUES('History Repeating', to_tsvector('History Repeating'));
INSERT INTO serije(serija_naziv, naziv_tsvector) VALUES('Bloodlines', to_tsvector('Bloodlines'));

CREATE INDEX idx_naziv_tsvector ON serije USING gist(naziv_tsvector);
CREATE INDEX idx_naziv_trigram_idx ON serije USING gist(serija_naziv gist_trgm_ops);