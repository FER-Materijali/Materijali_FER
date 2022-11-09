#include"source.h"

int main(void){
	char polje[sizeof(student_zapis) + 1]; //gets
	FILE *studenti, *studento;
	int prim;
	prim = OdrediPrim(M_student);
	printf("Prim. broj= <%d>", prim);
	printf("\n%d", M_student);
	studenti = fopen("studenti.txt", "r"); //student input
	studento = fopen("studenti.dat", "wb"); //student output
	while (fgets(polje,sizeof(student_zapis),studenti)!=NULL)
	{
		sscanf(polje, "%11[^\t] %15[^\t] %15[^\0] ", student.JMBAG, student.prezime, student.ime);
			upis(student, studento,prim);
		}
	fclose(studenti);
	fclose(studento);
	return 0;
}