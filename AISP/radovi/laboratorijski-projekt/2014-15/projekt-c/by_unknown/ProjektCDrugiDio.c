#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

#define MAXIME 20

typedef struct {
	int ID;
	char prezime[MAXIME+1];
	char ime[MAXIME+1];
	float stanje;
}zapis;

struct at{
	int ID;
	int pozicija;
	struct at *sljed;
};

typedef struct at atom;

int Dodaj (atom **glavap, int ID, int pozicija) {
	atom *novi, *p;
	if ((novi=(atom *) malloc(sizeof(atom)))==NULL) return 0;
	novi->ID = ID; 
	novi->pozicija = pozicija;
	if (*glavap == NULL || (*glavap)->ID >= ID) {
														//dodavanje na pocetak liste
		novi->sljed = *glavap;
		*glavap=novi;
		
	} else {
		for (p=*glavap;p->sljed && (p->sljed)->ID < ID; p=p->sljed);
		novi->sljed = p->sljed;							//mijenjamo pointere tako da ubacimo novi element u listu
		p->sljed=novi;	
	}
	return 1;
}
void Upisuj (atom **glavap, FILE *citanje, FILE *pisanje, zapis pomocni) {
	atom *p;
	for (p=*glavap; p!=NULL;p=p->sljed) {
		fseek (citanje, (p->pozicija)*sizeof(zapis), SEEK_SET);
		fread(&pomocni, sizeof(zapis), 1, citanje);
		fprintf(pisanje, "%d;%20s;%20s;%f\n", pomocni.ID, pomocni.prezime, pomocni.ime, pomocni.stanje);
	}
}

int main(void) {
	FILE *podaci, *direkt, *sortirano;
	zapis pod, pomocni;
	atom cvor, *glava;
	glava=NULL;
	int i=0;
	podaci=fopen("podaci.dat", "r");
	direkt=fopen("podaci.bin", "ab+");
	sortirano=fopen("sortirano.dat", "a");
	
	while(fscanf(podaci, "%d;%[^;];%[^;];%f\n", &pod.ID, pod.prezime, pod.ime, &pod.stanje)!=EOF){
		
		fseek(direkt, i*sizeof(zapis), SEEK_SET);
		fwrite(&pod, sizeof(pod), 1, direkt);
		cvor.ID=pod.ID;
		cvor.pozicija=i;
		Dodaj(&glava, cvor.ID, cvor.pozicija);
		i++;
	}

	Upisuj(&glava, direkt, sortirano, pomocni);
	
	fclose(podaci);
	fclose(direkt);
	fclose(sortirano);
	return 0;
}

