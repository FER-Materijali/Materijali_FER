#include <stdio.h>
#include <string.h>
#define MAX 100

void puni(int *M, char *Z, char *c, int r, int s);
void ispisi_cm(int *M, int r, int s);
void ispisi_zm(char *Z, int r, int s);
void cezar(char *Z, int r, int s);

int main() {

    int M[MAX][MAX], s/*Broj stupaca*/, r/*Broj redaka*/, i, j /*Brojaèi for petlji*/, max_index/*Broj elemenata znakovnog niza*/;
    char c[MAX+1], Z[MAX][MAX];
    printf("Unesite znakovni niz: ");

	while(1){
    gets(c);
    max_index=strlen(c);
    printf("\n%d\n", max_index);
	if(max_index<MAX) break;
	}



    do{
        printf("Zadajte broj redaka matrice iz intervala %d: ",MAX);
        scanf("%d",&r);
        printf("Zadajte broj stupaca matrice iz intervala %d: ",MAX);
        scanf("%d",&s);
    }while(!(r>0 && r<=MAX && s>0 && s<=MAX));

    for(i=0; i<r; i++) {
        for(j=0; j<s; j++) {

         do{
            printf("M(%d, %d)=",i,j);
            scanf("%d",&M[i][j]);
         }while(M[i][j]<0 || M[i][j]>=max_index);


        }
    }
    
    printf( "\n" );
    ispisi_cm(&M[0][0], r, s); //ispis cjelobrojne matrice


    printf( "\n" );
	puni(&M[0][0], &Z[0][0], &c[0], r, s);

	printf("\n");
    ispisi_zm(&Z[0][0], r, s); //ispis znakovne matrice

	printf("\n");
	cezar(&Z[0][0], r, s); //ispis znakovne matrice šifrirane cezarovom šifrom

    getchar();
    getchar();


	return 0;
}

void puni(int *M, char *Z, char *c, int r, int s) {
	int i, j;
	for(i=0; i<r; i++) {
        for(j=0; j<s; j++) {
			*(Z+i*MAX+j)=*(c+*(M+i*MAX+j));
		}
	}
}

void ispisi_cm(int *M, int r, int s) {
	int i, j;
	for(i=0; i<r; i++) {
        for(j=0; j<s; j++) {
			printf("%d ",*(M+i*MAX+j));
		}
		printf("\n");
	}
}

void ispisi_zm(char *Z, int r, int s) {
	int i, j;
	for(i=0; i<r; i++) {
        for(j=0; j<s; j++) {
			printf("%c ",*(Z+i*MAX+j));
		}
		printf("\n");
	}
}

void cezar(char *Z, int r, int s) {
	int i, j;
	char c;
	for(i=0; i<r; i++) {
        for(j=0; j<s; j++) {
                 c=*(Z+i*MAX+j);
                 if(c>=65 && c<=88 || c>=97 && c<=120) c+=3;
                 else if(c==89 || c==90 || c==121 && c==122) c-=23;
			     printf("%c ",c);
		}
		printf("\n");
	}
}

