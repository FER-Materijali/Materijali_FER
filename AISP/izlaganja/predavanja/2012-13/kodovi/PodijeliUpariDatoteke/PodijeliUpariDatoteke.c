#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAXREDAKA 100
#define MAXZNAKOVA 512

void MergeNFile (FILE **fpolje, FILE *fout, int brdat){
	int i, ind;
	char **plinija;
	plinija =(char**)malloc(brdat * sizeof(char*));
	for(i = 0; i < brdat; i++){
		rewind(fpolje[i]);  //premotati na pocetak
		plinija[i]=(char *)malloc(MAXZNAKOVA + 1);
		if (!fgets(plinija[i], MAXZNAKOVA, fpolje[i])) 
			*plinija[i] = '\0';
	}
	while (1){
		ind = -1;
		for(i = 0; i < brdat; i++){
			if (*plinija[i]) {
				if (ind == -1 || strcmp(plinija[i], plinija[ind]) < 0) 
					ind = i;
			}
		}
		if (ind == -1) break;
		fputs (plinija[ind], fout);
		if (!fgets(plinija[ind], MAXZNAKOVA, fpolje[ind])) *plinija[ind] = '\0';
	}
	for(i = 0; i < brdat; i++) free(plinija[i]);
	free(plinija);
}
int compare( const void *redak1, const void *redak2 ) {
  return strcmp( * (char **) redak1, * (char **) redak2 );
}
int main() {
	FILE *f, *fout, **fpolje = NULL;
	int brdat, brojaczapisa, i;
	char *flag, imedat[30], *redak[MAXREDAKA];
	char linija[MAXZNAKOVA + 1];
	if ((f = fopen ("dat1.txt", "r")) == NULL) {
		printf("Pogreska kod otvaranja datoteke dat1.txt");
		exit (1);
	}
	for (brdat = 0; ;) {
		// dok imamo manje od velièine bloka i imamo što èitati
		for (brojaczapisa = 0; brojaczapisa < MAXREDAKA &&
			(flag = fgets (linija, MAXZNAKOVA, f)); brojaczapisa ++) { 
			redak [brojaczapisa]= (char *) malloc(strlen (linija) + 1);
			if (redak[brojaczapisa] == NULL){
				fprintf (stderr, "Nedovoljno memorije!");
				exit(1);
			}
			strcpy (redak[brojaczapisa], linija);
		}
		if (brojaczapisa > 0) {
			//treba sortirati podatke
			qsort((void *)redak, brojaczapisa, sizeof(char *), compare);
			//treba zapisati u novu datoteku
			fpolje = (FILE **)realloc(fpolje,(brdat + 1)* sizeof(FILE*));
			sprintf (imedat, "%03d.txt", brdat);	
			if (( fpolje[brdat] = fopen (imedat, "w+")) == NULL){
				printf("Pogreška kod otvaranja datoteke %s", imedat);
				return 1;
			}
			for(i = 0; i < brojaczapisa; i++)
				fputs(redak[i], fpolje[brdat]);
			brdat ++;
		}
		if (!flag)	break;			
	}
	if ((fout = fopen ("out.txt", "w")) == NULL){
		fprintf (stderr, "Pogreška kod otvaranja datoteke out.txt");
		return 1;
	}
	MergeNFile (fpolje, fout, brdat);
	for (i = 0; i < brdat; i++) 
		fclose(fpolje[i]);
	fclose(f);
	fclose(fout);
	free(fpolje);
	return 0;
}	
