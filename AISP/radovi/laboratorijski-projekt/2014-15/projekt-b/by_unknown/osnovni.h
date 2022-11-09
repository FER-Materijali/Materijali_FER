#define NSTAVKI 4453
#define DATOTEKA_PODACI "words.dat"
#define DATOTEKA_TEST "test.dat"
#define SIZE_LIMIT 50

struct element{
    char word[SIZE_LIMIT+1];
};
struct at{
    char word[SIZE_LIMIT+1];
    long pocetak_bloka;
    struct at *sljed, *preth;
};
struct indeks{
	struct at *glava, *rep;
};
struct pom{
    char word[SIZE_LIMIT+1];
    long pocetak_bloka;
};

typedef struct element element;
typedef struct at atom;
typedef struct indeks indeks;
typedef struct pom pom;

atom* create_atom(void);
pom* create_sort_polje(FILE *ulaz);
void create_list(pom *polje);

extern atom *pocetci[26];