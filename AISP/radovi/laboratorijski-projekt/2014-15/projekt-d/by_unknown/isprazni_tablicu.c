#include"source.h"

student_zapis pretinac1[C_student];
predmet_zapis pretinac2[C_predmet];

void Isprazni(FILE *student_out, FILE *predmet_out) {
	int i;
	for (i = 0; i < C_student; i++) pretinac1[i].JMBAG[0] = '\0';
	for (i = 0; i < M_student; i++) {
		fseek(student_out, i*BLOK, SEEK_SET);
		fwrite(pretinac1, sizeof(pretinac1), 1, student_out);
	}
		for (i = 0; i < C_predmet; i++) pretinac2[i].sifra[0] = '\0';
		for (i = 0; i < M_predmet; i++) {
			fseek(predmet_out, i*BLOK, SEEK_SET);
			fwrite(pretinac1, sizeof(pretinac2), 1, predmet_out);
		}
	}