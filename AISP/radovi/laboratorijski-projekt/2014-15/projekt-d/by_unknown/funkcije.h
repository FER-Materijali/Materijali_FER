#include"source.h"

int OdrediPrim(int m);
int JMBAG_adresa(char JMBAG[], int prim);
int upis(student_zapis student, FILE *studento, int prim);
int upis_predmeti(predmet_zapis predmet, FILE *predmet_out);
void Isprazni(FILE *student_out, FILE *predmet_out);
void Ispis(FILE *ft);
int provjera(FILE *fp, zapis polozeni, zapis novo);
int nadi(FILE *fu, zapis polozeni, zapis *novo);
void ispis(FILE *fs, char *JMBAG, student_zapis *student);