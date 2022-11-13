Razvojno okruženje korišteno za izradu rada je Microsoft Visual Studio Enterprise 2015. Za izradu programske podrške odabran je programski jezik C#. 
Programski jezik C# je objektno orijentirani programski jezik namijenjen za opću upotrebu, razvijen od strane Microsofta za .NET platformu. 
Za razvoj programske podrške korištena je trenutno aktualna verzija 4.5 platforme .NET i verzija 6 programskog jezika C#.
Za razvoj baze podataka korišten je sustav za upravljanje bazama podataka posgreSQL.

Prije prvog pokretanja potrebno je pokrenuti posgreSQL na adresi 192.168.56.12, portu 5432.
Stvoriti korisnika postgres s lozinkom reverse, te izvrsiti SQL skriptu danu u nastavku.
Kod svih ostalih pokretanja dovoljno je pokrenuti postgreSQL i iz razvojnog okruzenja MS Visual Studio pokrenuti aplikaciju sa F5 ili Ctrl + F5.

-- Database: P1

-- DROP DATABASE "P1";

CREATE DATABASE "P1"
    WITH 
    OWNER = postgres
    ENCODING = 'UTF8'
    LC_COLLATE = 'en_US.UTF-8'
    LC_CTYPE = 'en_US.UTF-8'
    TABLESPACE = pg_default
    CONNECTION LIMIT = -1;
	
CREATE SEQUENCE public.document_id_seq
    INCREMENT 1
    START 14
    MINVALUE 1
    MAXVALUE 9223372036854775807
    CACHE 1;

ALTER SEQUENCE public.document_id_seq
    OWNER TO postgres;
	
-- Table: public.document

-- DROP TABLE public.document;

CREATE TABLE public.document
(
    id integer NOT NULL DEFAULT nextval('document_id_seq'::regclass),
    title character varying(200) COLLATE "default".pg_catalog NOT NULL,
    summary character varying(1000) COLLATE "default".pg_catalog NOT NULL,
    body character varying(10000) COLLATE "default".pg_catalog NOT NULL,
    keywords character varying(200) COLLATE "default".pg_catalog NOT NULL,
    vector tsvector,
    title_vector tsvector NOT NULL,
    CONSTRAINT document_pkey PRIMARY KEY (id)
)
WITH (
    OIDS = FALSE
)
TABLESPACE pg_default;

ALTER TABLE public.document
    OWNER to postgres;

-- Index: idx_document_gist

-- DROP INDEX public.idx_document_gist;

CREATE INDEX idx_document_gist
    ON public.document USING gist
    (vector)
    TABLESPACE pg_default;

-- Index: idx_document_title_gist

-- DROP INDEX public.idx_document_title_gist;

CREATE INDEX idx_document_title_gist
    ON public.document USING gist
    (title_vector)
    TABLESPACE pg_default;
	
CREATE SEQUENCE public.search_log_id_seq
    INCREMENT 1
    START 26
    MINVALUE 1
    MAXVALUE 9223372036854775807
    CACHE 1;

ALTER SEQUENCE public.search_log_id_seq
    OWNER TO postgres;
	
-- Table: public.search_log

-- DROP TABLE public.search_log;

CREATE TABLE public.search_log
(
    id integer NOT NULL DEFAULT nextval('search_log_id_seq'::regclass),
    query character varying(200) COLLATE "default".pg_catalog NOT NULL,
    stamp timestamp without time zone NOT NULL DEFAULT now(),
    CONSTRAINT search_log_pkey PRIMARY KEY (id)
)
WITH (
    OIDS = FALSE
)
TABLESPACE pg_default;

ALTER TABLE public.search_log
    OWNER to postgres;

-- Index: idx_search_log_query

-- DROP INDEX public.idx_search_log_query;

CREATE INDEX idx_search_log_query
    ON public.search_log USING btree
    (query COLLATE pg_catalog."default")
    TABLESPACE pg_default;