#include <stdio.h>

int main () {
	char string[1024], znak;
	FILE *datoteka;
	int brojac, prijasnje_stanje, sadasnje_stanje, stupac;
	int tablica[24][8] = { {0 , 0 , 2 , 3 , 4 , 1 , 1 , 1 },
	                       {1 , 0 , 1 , 1 , 1 , 1 , 1 , 1 },
	                       {2 , 0 , 1 , 1 , 1 , 5 , 6 , 7 },
	                       {3 , 0 , 1 , 1 , 1 , 8 , 9 , 10},
	                       {4 , 0 , 1 , 1 , 1 , 11, 12, 13},
	                       {5 , 1 , 1 , 14, 15, 1 , 1 , 1 },
	                       {6 , 1 , 1 , 1 , 16, 1 , 1 , 1 },
	                       {7 , 1 , 1 , 17, 15, 1 , 1 , 1 },
	                       {8 , 1 , 18, 1 , 19, 1 , 1 , 1 },
	                       {9 , 1 , 1 , 1 , 1 , 1 , 1 , 1 },
	                       {10, 1 , 20, 1 , 21, 1 , 1 , 1 },
	                       {11, 1 , 22, 14, 1 , 1 , 1 , 1 },
	                       {12, 1 , 23, 1 , 1 , 1 , 1 , 1 },
	                       {13, 1 , 22, 17, 1 , 1 , 1 , 1 },
	                       {14, 0 , 1 , 1 , 1 , 1 , 1 , 10},
	                       {15, 0 , 1 , 1 , 1 , 1 , 12, 1 },
	                       {16, 0 , 1 , 1 , 1 , 11, 1 , 13},
	                       {17, 0 , 1 , 1 , 1 , 8 , 1 , 1 },
	                       {18, 0 , 1 , 1 , 1 , 1 , 1 , 7 },
	                       {19, 0 , 1 , 1 , 1 , 1 , 1 , 13},
	                       {20, 0 , 1 , 1 , 1 , 5 , 1 , 1 },
	                       {21, 0 , 1 , 1 , 1 , 11, 1 , 1 },
	                       {22, 0 , 1 , 1 , 1 , 1 , 6 , 1 },
	                       {23, 0 , 1 , 1 , 1 , 5 , 1 , 7 }
	                     };
	
	if (!(datoteka = fopen("niz.txt", "r"))) {
		fprintf(stderr, "Ne mogu otvoriti datoteku\n");
		system("PAUSE");
		exit(1);
	}
	
	while (fscanf(datoteka, "%s", &string) != EOF) {
		brojac = prijasnje_stanje = 0;
		printf("Primio sam niz: %s", string);
		
		while (brojac < strlen(string)) {
			znak = string[brojac++];
			stupac = znak < \\'A\\' ? znak - \\'1\\' + 5 : znak - \\'A\\' + 2;
			
			if ((znak >= \\'A\\' && znak <= \\'C\\') || (znak >= \\'1\\' && znak <=\\'3\\'))
				sadasnje_stanje = tablica[prijasnje_stanje][stupac];
			else
				sadasnje_stanje = 1;
			
			printf("\nZnak na ulazu: %c\n", znak);
			printf("Trenutno stanje: q%d\n", prijasnje_stanje);
			printf("Prijelaz: (q%d, %c) = q%d\n", prijasnje_stanje, znak, sadasnje_stanje);
			printf("Novo stanje: q%d\n", sadasnje_stanje);
			printf("Dosadasnji niz se %sprihvaca!\n", tablica[sadasnje_stanje][1] ? "" : "ne ");
			
			prijasnje_stanje = sadasnje_stanje;
		}
		printf("\n\nUlazni niz %sje prihvacen!\n", prijasnje_stanje == 1 ? "ni" : "");
		printf("_______\n\n");
	}
	fclose(datoteka);
	printf("\nKraj datoteke!!!\n\n");
	system("PAUSE");
	return 0;
}