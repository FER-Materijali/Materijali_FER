#include"source.h"

void ispis(FILE *fs, char *JMBAG,student_zapis *student){
	student_zapis pretinac[C_student];
	int i, j;
	for (i = 0; i < M_student; ++i){
		fseek(fs, i*BLOK, SEEK_SET);
		fread(pretinac, sizeof(pretinac), 1, fs);
		for (j = 0; j < C_student; ++j){
			if (pretinac[j].JMBAG[0] == '\0')	break;
			if (strcmp(pretinac[j].JMBAG,JMBAG)==0){
				*(student) = pretinac[j];
			}
		}
	}
}
int nadi(FILE *fu, zapis polozeni, zapis *novo){
	fseek(fu, 0L, SEEK_SET);
	while (fscanf(fu, "%[^\t]\t%[^\t]\t%d\n", polozeni.JMBAG, polozeni.sifra, &polozeni.ocjena) != EOF){
		if (strcmp(polozeni.sifra, novo->sifra) == 0 && strcmp(polozeni.JMBAG, novo->JMBAG) == 0){
			novo->ocjena = polozeni.ocjena;
			return 1;
		}
	}
	return 0;
}
int provjera(FILE *fp, zapis polozeni, zapis novo){
	int i, j;
	predmet_zapis pretinac[C_predmet];
	student_zapis student;
	FILE *fs;
	fs = fopen("studenti.dat", "rb");
	for (i = 0; i < M_predmet; ++i){
		fseek(fp, i*BLOK, SEEK_SET);
		fread(pretinac, sizeof(pretinac), 1, fp);
		for (j = 0; j < C_predmet; j++){
			if (pretinac[j].sifra[0] == '\0') break;
			if (strcmp(pretinac[j].sifra, novo.sifra) == 0){
				if (nadi(fu, polozeni, &novo)){
					if (novo.ocjena>1){
						ispis(fs, novo.JMBAG, &student);
						printf("Student %s %s %s polozio je predmet %s s ocjenom %d.", student.JMBAG, student.prezime, student.ime, pretinac[j].naziv, novo.ocjena);
					}
				}
					else{
						if (pretinac[j].dir_preduvjet[0] == '\0'){
							ispis(fs, novo.JMBAG, &student);
							printf("Student %s %s %s moze upisati predmet %s.", student.JMBAG, student.prezime, student.ime, pretinac[j].naziv);
							return 1;
						}
						else{
							if (pretinac[j].dir_preduvjet[0] != '\0'){
								strcpy(novo.sifra, pretinac[j].dir_preduvjet);
								if (nadi(fu, polozeni, &novo)){
									if (novo.ocjena > 1){
										ispis(fs, novo.JMBAG, &student);
										printf("Student %s %s %s moze upisati predmet %s jer je polozio uvjet %s s ocjenom %d.", student.JMBAG, student.prezime, student.ime, pretinac[j].naziv, novo.sifra, novo.ocjena);
										return 1;
									}
								}
									else{
										ispis(fs, novo.JMBAG, &student);
										printf("Student %s %s %s ne moze upisati predmet %s jer nije polozio uvjet %s.", student.JMBAG, student.prezime, student.ime, pretinac[j].naziv, novo.sifra);
										return 1;
									}

								
							}
						}
					}
				}
			}

		}
	return  0;
	}
int main(void){
	fp = fopen("predmeti.dat", "rb");
	fu = fopen("polozeni.txt", "r");
	int z=0;
	printf("JMBAG > "); scanf("%s",&novo.JMBAG);
	printf("sifra > "); scanf("%s",&novo.sifra);
	printf("______________________________________________________________________________________________________\n");
	novo.ocjena = 0;
	provjera(fp, polozeni, novo);
	fclose(fu);
	fclose(fu);
	return 0;
}

