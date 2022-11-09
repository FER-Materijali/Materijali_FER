#include"source.h"

int OdrediPrim(int m) {
	int i, prim, kraj;
	prim = m + 1;
	do {
		prim--;
		kraj = (int)pow((double)prim, (double) 0.5);
		for (i = kraj; i > 0; i--) {
			if (prim % i == 0) break;
		}
	} while (i != 1);
	return prim;
}
int JMBAG_adresa(char JMBAG[], int prim){
	int i, a, b, c, adr;
	char pom[4 + 1] = { '\0' };
	for (i = 0; i < 4; ++i){
		pom[i] = JMBAG[i + 3];
	}
	a = atoi(pom);
	pom[3] = '0';
	for (i = 0; i < 3; ++i){
		pom[i] = JMBAG[2 - i];
	}
	b = atoi(pom);
	pom[3] = '0';
	for (i = 0; i < 3; ++i){
		pom[i] = JMBAG[7 + i];
	}
	c = atoi(pom);
	adr = a + b + c;
	adr = (a + b + c) % prim;
	return adr;

}
int upis(student_zapis student, FILE *studento, int prim){
	student_zapis pretinac[C_student];
	int i, j, adr;
	adr = i = JMBAG_adresa(student.JMBAG, prim);
	do{
		fseek(studento, i*BLOK, SEEK_SET);
		fread(pretinac, sizeof(pretinac), 1, studento);
		for (j = 0; j < C_student; ++j){
			if (pretinac[j].JMBAG[0] == '\0'){
				pretinac[j] = student;
				fseek(studento, i*BLOK, SEEK_SET);
				fwrite(pretinac, sizeof(pretinac), 1, studento);
				return 1;
			}
		}
		i = (i + 1) % M_student;
	} while (i != adr);
	return 0;
}