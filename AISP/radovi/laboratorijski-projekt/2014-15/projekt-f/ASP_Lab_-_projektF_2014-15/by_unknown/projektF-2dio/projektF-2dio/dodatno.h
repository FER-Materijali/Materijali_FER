struct student {
	char ime_prezime[ 51 ];
	char mjesto_rodjenja[ 41 ];
	char prebivaliste[ 41 ];
	char jmbag[ 11 ];
	char oib[ 12 ];
};

struct idx_jmbag {
	long pozicija;
	char jmbag[ 11 ];
};

struct idx_oib {
	long pozicija;
	char oib[ 12 ];
};

#define BROJ_ZAPISA 10000

