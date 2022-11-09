#include<stdio.h>
#include<math.h>
#include <stdlib.h>
#include <string.h>
#define BLOK 512L
#define S 5000
#define P 100
#define C_student ((int)(BLOK)/(sizeof(student_zapis)))
#define C_predmet ((int)(BLOK)/(sizeof(predmet)))
#define M_student ((int) (S / C_student *1.2))
#define M_predmet ((int)((P)*(1.2))/(C_predmet))

typedef struct {
	char JMBAG[10+1];
	char prezime[14 + 1];
	char ime[14 + 1];
}student_zapis;
student_zapis pretinac[C_student],student;

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



int JMBAG_adresa(char JMBAG[],int prim){
	int i,a, b, c, adr;
	char pom[4 + 1];
	pom[4] = '\0';
	for (i = 0; i < 3; ++i){
		pom[i] = JMBAG[i+3];
		a = atoi(pom);
	}
	for (i = 0; i < 3; ++i){
		pom[i] = JMBAG[2 - i];
		b = atoi(pom);
	}
	for (i = 0; i < 3; ++i){
		pom[i] = JMBAG[8 - i];
		c = atoi(pom);
	}
	adr = a + b + c;
	adr = (a + b + c) % prim;
	printf("\nIzracunata adresa (%d) = %d\n", (a + b + c), adr);
	return adr;
}

int upis(student_zapis student, FILE *studento,int prim){
	int i, j, adr;
	adr=i=JMBAG_adresa(student.JMBAG,prim);
	do{
		fseek(studento, i*BLOK, SEEK_SET);
		fread(pretinac, sizeof(pretinac), 1, studento);
		for (j = 0; j < C_student; ++i){
			if (pretinac[j].JMBAG !='\0'){
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

int main(void){
	FILE *studenti, *studento;
	int prim;
	prim = OdrediPrim(M_student);
	printf("Prim. broj= <%d>", prim);
	studenti = fopen("studenti.txt", "r"); //student input
	studento = fopen("studenti.dat", "wb"); //student output
	while (fscanf(studenti, " %[^\t] %[^\t] %[^\n]", student.JMBAG, student.prezime, student.ime) != EOF)
	{
		if (!upis(student, studento, prim)){
			printf("Tablica puna");
		}
		else{
			printf("JMBAG= %s Prezime= %s Ime= %s \n", student.JMBAG, student.prezime, student.ime);
		}
		}
	return 0;
}