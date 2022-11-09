re#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define MAXIME 20

typedef struct {
	int ID;
	char prezime[MAXIME+1];
	char ime[MAXIME+1];
	float stanje;
}zapis;

#define BLOK 512L		 					// velicina bloka
#define N 10000				                // Ocekivani broj zapisa    
#define C ((int) (BLOK / sizeof (zapis)))	// Broj zapisa u pretincu
#define M ((int) ((N / C) *1.2))            // Broj pretinaca
#define ADRESA Adresa3




zapis pretinac[C];

void PraznjenjeTablice (FILE *ispis) {
  int i;
  for (i = 0; i < C; i++) pretinac[i].ID = 0;
  for (i = 0; i < M; i++) {
    fseek (ispis, i*BLOK, SEEK_SET);
    fwrite (pretinac, sizeof (pretinac), 1, ispis);
  }
  //printf ("Tablica ispraznjena N=%d, C=%d, M=%d\n", N, C, M);
  //printf ("Velicina pretinca = %d\n", sizeof (pretinac));

}

void Pogreska (char *poruka) {
  fputs (poruka, stderr); 
  fputs ("\n", stderr);
  exit (1);
}
int Adresa1 (int ID, int prim) {
	int lijevi, srednji, desni;
	lijevi= ID/10000;
	srednji=(ID/100)%1000;
	desni=ID%100;
	lijevi= lijevi/10 + (lijevi % 10)*10;
	desni= desni/10 + (desni%10)*10;
	return((lijevi+srednji+desni)%M);
}
int Adresa2 (int ID, int prim) {
	return ID % prim;
}
int Adresa3 (int ID, int prim){
	int i, rez=0;
	for (i=0;i<7;i++) rez+=((ID%(int)(pow(10,i)))*pow(8,i)); //promjena baze 10 u bazu 8
	return rez%prim;
}
int OdrediPrim (int m) {
  int i, prim, kraj;
//	printf ("Trazenje najveceg prim broja <= %d\n", m);
  prim = m+1;
  do {
    prim--;
    kraj = (int) pow ((double) prim, (double) 0.5);
    for (i = kraj; i > 0; i--) {
      //printf ("%d/%d ", prim, i);
      if (prim % i == 0) break;
    }
  } while (i != 1);
 // printf("prim je %d\n",prim);
  return prim;
}
int DodajZapis (zapis pod,FILE *stream,int prim) {
	int pr_upisa,namj_pr,i; 						//pretinac upisa, namjenjeni pretinac
	namj_pr = pr_upisa = ADRESA(pod.ID, prim);      //pretvorenu adresu spremamo
	do{
		fseek (stream,pr_upisa*BLOK,SEEK_SET);
		fread(pretinac,sizeof(pretinac),1,stream);  
		for(i=0;i<C;i++){
			if(pretinac[i].ID==0){ 					//nadjeno prazno mjesto: upisujem zapis
				
				pretinac[i]=pod;	          		//prvi podatak
				fseek (stream,pr_upisa*BLOK,SEEK_SET);
				fwrite(pretinac,sizeof(pretinac),1,stream); //upisujem pretinac u datoteku
		
				return 1;		
			}								//nije nadjeno prazno mjesto: idem na iduce mjesto
		}											//pretinac pun, prijelaz na sljedecega
		pr_upisa=(pr_upisa+1)%M; 					//mod zato da se vrti u krug
	}while(pr_upisa!=namj_pr);
	return 0;
}
int brprelj(FILE *stream, int prim){
	int i,j,preljev=0;
	fseek(stream,0,SEEK_SET);
	for(i=0;i<M;i++){
			fread(pretinac,sizeof(pretinac),1,stream);
			for(j=0;j<C;j++){
				if(pretinac[j].ID==0) break;
				if(i!=(ADRESA((pretinac[j].ID), prim) ))preljev++;
			}
	}
return preljev;
}
int brzap(FILE *stream, int prim){

	int i,j,max,zapisi[M]; //upuceni zapisi
	for (i=0;i<M;i++) zapisi[i]=0;
	fseek(stream,0,SEEK_SET);
	
	
	for(i=0;i<M;i++){
	fseek(stream,i*BLOK,SEEK_SET);
	fread(pretinac,sizeof(pretinac),1,stream);
	
		for(j=0;j<C;j++){
			if(pretinac[j].ID==0) break;
		
			zapisi[ADRESA((pretinac[j].ID), prim)]++;
		
		}
	}
	max=zapisi[0];
	for (i=1;i<prim;i++) {
		if (zapisi[i]>max) max=zapisi[i];
	}
	return (max);
}

int main(void)

{
	int prim;
	zapis pod;
	FILE *podaci, *ispis, *rezz;
	rezz=fopen("rezultati.txt", "a");
	if((podaci=fopen("podaci.dat", "r"))==NULL)
	{
		exit(1);
		Pogreska("Ne mogu otvoriti datoteku \"podaci\"");
	}
	if((ispis=fopen("ispis.txt", "wb+"))==NULL)
	{
		exit(1);
		Pogreska("Ne mogu stvoriti datoteku \"ispis\"");
	}
	PraznjenjeTablice(ispis);
	prim = OdrediPrim(M);
	while(fscanf(podaci, "%d;%[^;];%[^;];%f\n", &pod.ID, pod.prezime, pod.ime, &pod.stanje)!=EOF)
	{
		DodajZapis(pod, ispis, prim);	
	}
	
	printf("Broj preljeva je: %d \nmaksimalni broj upucenih zapisa je: %d\n",brprelj(ispis, prim),brzap(ispis, prim));
	fprintf(rezz, "%d %d\n", brprelj(ispis, prim),brzap(ispis, prim));

	fclose(podaci);
	fclose(ispis);
	fclose(rezz);
return 0;
}
