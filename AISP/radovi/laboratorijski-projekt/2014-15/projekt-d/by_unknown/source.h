#include<stdio.h>
#include<math.h>
#include <stdlib.h>
#include <string.h>
#include<ctype.h>

#define BLOK 512L
#define S 5000
#define P 100
#define C_student ((int)(BLOK)/(sizeof(student_zapis)))
#define C_predmet ((int)(BLOK)/(sizeof(predmet_zapis)))
#define M_student ((int) (S / C_student *1.2))
#define M_predmet ((int)((P)*(1.2))/(C_predmet))


typedef struct {
	char JMBAG[10 + 1];
	char prezime[14 + 1];
	char ime[14 + 1];
}student_zapis;
student_zapis student;

typedef struct {
	char sifra[7 + 1];
	char naziv[63 + 1];
	char dir_preduvjet[7 + 1]; //kao i sifra
}predmet_zapis;

typedef struct{
	char JMBAG[10 + 1];
	char sifra[7 + 1];
	int ocjena;
}zapis;
zapis polozeni;
zapis novo;


predmet_zapis predmet;
FILE *fu;
FILE *fp;
