#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

char *zapocinje (char nz, char *zapocinje){
char ucitaninz=0, ucitani=0, *nista=0;
int i=0, g=0;
FILE *dat1;

dat1 = fopen ("produkcije.txt", "r+");
free(zapocinje);
zapocinje = (char *) malloc ((1) * sizeof (char));
fseek (dat1, 0L, SEEK_SET);
while(fscanf (dat1,"%c->%c%[^\n]\n", &ucitaninz, &ucitani,&nista) != EOF){
	if (islower(ucitani)&&(nz==ucitaninz)){
		zapocinje = (char *) realloc (zapocinje, (1+g) * sizeof (char));
		zapocinje[g]=ucitani;
		g++;
	}
}
zapocinje = (char *) realloc (zapocinje, (1+g) * sizeof (char));
zapocinje[g]='\0';
fclose (dat1);
return zapocinje;
}

void postavi_vrijednost (char a, char b, int dzz, int d, char *x){
int i,j;
for (i=dzz+2; i<=d;){
	if (x[i]==a) break;
	else i+=dzz+2;
}
for (j=1;j<=dzz;++j){
	if (x[j]==b)break;
}
x[i+j]='1';
}

int provjeri_vrijednost (char a, char b, int dzz, int d, char *x){
int i,j;
for (i=dzz+2; i<=d;){
	if (x[i]==a) break;
	else i+=dzz+2;
}
for (j=1;j<=dzz;++j){
	if (x[j]==b)break;
}
if (x[i+j]=='1') return 1;
else return 0;
}

int duljina_niza(char *x){
int duljina=0, i=0;
while (x[i]!='\0'){
	duljina++;
	i++;
}
return duljina;
}

int main () {
FILE *dat;
char *POLJENZ, *POLJEZZ ,*ZAPOCINJE, *ZAPOCINJES, *ISPODZNAKA, *REDAKISPODZNAKA;
char ucitani=0; char ucitani2=0; char ucitaninz=0; char *nista; //pomoæne varijable
int inz=0; int izz=0; int i=0; int j=0; int g=0; int postoji=0; //pomoæne varijable
int duljinapolja=0; //velièina relacije IspodZnaka

dat = fopen ("produkcije.txt", "r+");
POLJENZ = (char *) malloc ((1) * sizeof (char));
POLJENZ[0]='\0';
POLJEZZ = (char *) malloc ((1) * sizeof (char));
POLJEZZ[0]='\0';
ZAPOCINJE =(char *) malloc ((1) * sizeof (char));
ZAPOCINJE[0]='\0';
ZAPOCINJES =(char *) malloc ((1) * sizeof (char));
ZAPOCINJES[0]='\0';
ISPODZNAKA =(char *) malloc ((1) * sizeof (char));
ISPODZNAKA[0]='\0';
REDAKISPODZNAKA =(char *) malloc ((1) * sizeof (char));
REDAKISPODZNAKA[0]='\0';
nista =(char *) malloc ((100) * sizeof (char));
nista[0]='\0';

if (fscanf (dat, "%c", &ucitani) == EOF) {
	printf("Ulazna datoteka je prazna!");
	return 0;
}
fseek (dat, 0L, SEEK_SET);
//Prepoznavanje zavrsnih i nezavrsnih znakova
while(fscanf (dat, "%c", &ucitani) != EOF){
       if (islower(ucitani)){
               for (i=0;i<=izz;i++){
                       if (POLJEZZ[i]==ucitani) {postoji=1;break;}
               }
               if (postoji==1) {postoji=0; continue;}
               else {
                       POLJEZZ = (char *) realloc (POLJEZZ, (1+izz) * sizeof (char));
                       POLJEZZ[izz]=ucitani;
                       izz++;
                       }
       }

       else if (isupper(ucitani)){
               for (i=0;i<=inz;i++){
                       if (POLJENZ[i]==ucitani) {postoji=1;break;}
               }
               if (postoji==1) {postoji=0; continue;}
               else {
                       POLJENZ = (char *) realloc (POLJENZ, (1+inz) * sizeof (char));
                       POLJENZ[inz]=ucitani;
                       inz++;
                       }
       }
       else continue;
}
POLJEZZ[izz]='\0';
POLJENZ[inz]='\0';
if (POLJEZZ[0]=='\0') {
	printf("Produkcije nisu dobro zadane jer nema zavrsnih znakova!");
	return 0;
}
//Izrada relacije IspodZnaka
REDAKISPODZNAKA = (char *) realloc (REDAKISPODZNAKA, (duljina_niza(POLJEZZ)+duljina_niza(POLJENZ)+1+1) * sizeof (char));
for (i=0;i<duljina_niza(POLJENZ);++i){
	REDAKISPODZNAKA[i]=POLJENZ[i];
}
for (i=i,j=0;i<(duljina_niza(POLJEZZ)+duljina_niza(POLJENZ));++i,++j){
	REDAKISPODZNAKA[i]=POLJEZZ[j];
}
REDAKISPODZNAKA[i]='T';
REDAKISPODZNAKA[i+1]='\0';

duljinapolja=(duljina_niza(POLJEZZ)+1+1)*(duljina_niza(POLJENZ)+duljina_niza(POLJEZZ)+1+1);
ISPODZNAKA = (char *) realloc (ISPODZNAKA, duljinapolja * sizeof (char));
for(i=0;i<duljinapolja;++i){
	ISPODZNAKA[i]='0';
}
ISPODZNAKA[0]='X';
for(i=1;i<=duljina_niza(POLJEZZ);++i){
	ISPODZNAKA[i]=POLJEZZ[i-1];
}
j=0;
for(i=i;i<=duljinapolja;){
           ISPODZNAKA[i]='\n';
               i+=duljina_niza(POLJEZZ)+2;          
}
for(i=0,j=duljina_niza(POLJEZZ)+2;i<duljina_niza(REDAKISPODZNAKA);++i){
ISPODZNAKA[j]=REDAKISPODZNAKA[i];
j+=duljina_niza(POLJEZZ)+2;
}
printf ("Za zadanu gramatiku:\n");
fseek (dat, 0L, SEEK_SET);
while(fscanf (dat,"%c", &ucitani) != EOF){
       printf ("%c",ucitani);
}
printf ("\n\nTablica relacije IspodZnaka glasi:\n");
fseek (dat, 0L, SEEK_SET);
while(fscanf (dat,"%c", &ucitani) != EOF){
	if ((97<=ucitani&&ucitani<=122)||(65<=ucitani&&ucitani<=90)) {
		if (fscanf (dat,"%c", &ucitani2)!=EOF){
			fseek (dat, -1L, SEEK_CUR);
			if ((97<=ucitani2&&ucitani2<=122))postavi_vrijednost(ucitani, ucitani2, duljina_niza(POLJEZZ), duljinapolja, ISPODZNAKA);
			else if ((65<=ucitani2&&ucitani2<=90)){
			ZAPOCINJE=zapocinje(ucitani2,ZAPOCINJE);
			for(i=0;i<duljina_niza(ZAPOCINJE);++i)
				postavi_vrijednost (ucitani, ZAPOCINJE[i], duljina_niza(POLJEZZ), duljinapolja, ISPODZNAKA);
			}
		}else break;
	}
}
ZAPOCINJE=zapocinje('S',ZAPOCINJE);
for(i=0;i<duljina_niza(ZAPOCINJE);++i)
	 postavi_vrijednost ('T', ZAPOCINJE[i], duljina_niza(POLJEZZ), duljinapolja, ISPODZNAKA);
for(i=0;i<duljinapolja;++i){
	printf ("%c",ISPODZNAKA[i]);
}
printf("\nVrijede relacije:\n");
for (i=0;i<duljina_niza(POLJENZ);++i){
	for (j=0;j<duljina_niza(POLJEZZ);++j){
	if (provjeri_vrijednost(POLJENZ[i],POLJEZZ[j],duljina_niza(POLJEZZ), duljinapolja, ISPODZNAKA)==1)
		printf ("IspodZnaka(%c,%c)\n",POLJENZ[i],POLJEZZ[j]);
	}
}
for (i=0;i<duljina_niza(POLJEZZ);++i){
	for (j=0;j<duljina_niza(POLJEZZ);++j){
	if (provjeri_vrijednost(POLJEZZ[i],POLJEZZ[j],duljina_niza(POLJEZZ), duljinapolja, ISPODZNAKA)==1)
		printf ("IspodZnaka(%c,%c)\n",POLJEZZ[i],POLJEZZ[j]);
	}
}
for (j=0;j<duljina_niza(POLJEZZ);++j){
	if (provjeri_vrijednost('T',POLJEZZ[j],duljina_niza(POLJEZZ), duljinapolja, ISPODZNAKA)==1)
		printf ("IspodZnaka(T,%c)\n",POLJEZZ[j]);
}

fclose (dat);
return 0;
}
