#define DATOTEKA_IZLAZ "output1.rez"
#define DATOTEKA_IZLAZ2 "output2.rez"

void inicijaliziraj(FILE *ulaz);
long nadji_blok(char znak, FILE *ulaz);
long nadji_blok_r(char znak, FILE *ulaz, long lijevo, long desno);
void init_blok(FILE *ulaz);
void add_to_list(char *word, unsigned long pocetak_bloka);
void fill_array(void);

extern unsigned long velbloka;
extern unsigned long brstavki;
extern unsigned long brblokova;
extern unsigned long velblokb;
extern int poz;