#include"source.h"

int main(void){
	char *polje;
	FILE *student_in, *student_out, *predmet_in, *predmet_out;
	int	prim = OdrediPrim(M_student);
	student_in = fopen("studenti.txt", "r"); //student input
	student_out = fopen("studenti.dat", "w+b"); //student output
	predmet_in = fopen("predmeti.txt", "r"); //predmet input
	predmet_out = fopen("predmeti.dat", "w+b"); //predmet output
	Isprazni(student_out,predmet_out);
	polje = (char *)malloc(sizeof(student));
	while (fgets(polje, sizeof(student_zapis), student_in) != NULL)
	{
		sscanf(polje, "%11[^\t] %15[^\t] %15[^\n] ", student.JMBAG, student.prezime, student.ime);
		upis(student, student_out,prim);
	}
	free(polje);
	polje = (char *)malloc(sizeof(predmet));
	while (fgets(polje, sizeof(predmet_zapis), predmet_in) != NULL)
	{
		sscanf(polje, "%8[^\t] %64[^\t] %8[^\n] ", predmet.sifra, predmet.naziv, predmet.dir_preduvjet);
		upis_predmeti(predmet, predmet_out);
		predmet.dir_preduvjet[0] = '\0';
	}
	free(polje);
	fclose(student_in);
	fclose(student_out);
	fclose(predmet_in);
	fclose(predmet_out);
	return 0;
}
