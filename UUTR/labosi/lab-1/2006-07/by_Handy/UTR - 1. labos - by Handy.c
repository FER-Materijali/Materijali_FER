#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>
#include <ctype.h>

int main(){
        FILE *ulaz;
		char polje[512];
		char trenutni;
		int duljina,i,novo_stanje,staro_stanje, pom;
		int automat  [24][8]={ {0,23,23,23,1,2,3,0},
                              {1,4,5,6,23,23,23,0},
                              {2,7,8,9,23,23,23,0},
                              {3,10,11,12,23,23,23,0},
                              {4,23,23,23,23,13,14,1},
                              {5,23,23,23,23,23,15,1},
                              {6,23,23,23,23,16,14,1},
                              {7,23,23,23,17,23,18,1},
                              {8,23,23,23,23,23,23,1},
                              {9,23,23,23,19,23,20,1},
                              {10,23,23,23,21,13,23,1},
                              {11,23,23,23,22,23,23,1},
                              {12,23,23,23,21,16,23,1},
                              {13,23,23,9,23,23,23,0},
                              {14,23,11,23,23,23,23,0},
                              {15,10,23,12,23,23,23,0},
                              {16,7,23,23,23,23,23,0},
                              {17,23,23,6,23,23,23,0},
                              {18,23,23,12,23,23,23,0},
                              {19,4,23,23,23,23,23,0},
                              {20,10,23,23,23,23,23,0},
                              {21,23,5,23,23,23,23,0},
                              {22,4,23,6,23,23,23,0},
                              {23,23,23,23,23,23,23,0}};




   if ((ulaz = fopen ("ulazx.txt","r")) == NULL){
			printf ("Datoteka nije dobro dohvacena!!\n");
		       exit(1);}

	while ((fscanf (ulaz, "%s", &polje))!=EOF){
                         duljina=(int) strlen (polje);
			 i=0;             
			 staro_stanje=0;

			 printf ("Primljeni niz: %s",polje);

			 while (i<duljina){
				 trenutni=polje[i];
				 if (isdigit(trenutni))pom=(int)trenutni-48;
				 else pom= toupper(trenutni)-61;
				
				 novo_stanje=automat[staro_stanje][pom];

				 printf ("\nUlazni znak: %c\n",trenutni);
				 printf ("Trenutno stanje: q%d\n",staro_stanje);
				 printf ("Prijelaz: (q%d,%c)=q%d\n",staro_stanje, trenutni,novo_stanje);
				 printf ("Novo stanje: q%d\n",novo_stanje);

				if(automat[novo_stanje][7]) printf ("Dosadasnji niz se prihvaca\n");
				else printf ("Dosadasnji niz se ne prihvaca!\n");

				if (novo_stanje==23){
					 printf ("\nNiz nije prihvacen!!\n");
					 break;}
				staro_stanje=novo_stanje;
				i++;}
			 printf ("\n\n\n");
			 printf ("------------------------");
			 printf ("\n\n\n");

	}

		

	printf ("\nNema vise nizova!!\n\n");

	printf ("Hvala na koristenju,\nVas Automat!\n\n");
return 0;}