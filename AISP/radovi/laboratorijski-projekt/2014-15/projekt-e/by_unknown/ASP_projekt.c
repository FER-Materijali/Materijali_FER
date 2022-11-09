#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define BLOK 512L		// Blok na disku
#define N 1000				// Ocekivani broj zapisa:    
#define C ((int) (BLOK / sizeof (zapis)))	// Broj zapisa u pretincu
#define M ((int) (N / C *1.3))
typedef struct {
		int sifra;
		char ime[20+1];
		char prezime[20+1];
		int ukupno;
		int brpolozenih;
	}zapis;
	zapis spremi,svizapisi[N];
int adresa(int sifra){
	return (sifra%M);
}
void Merge (zapis A [], zapis PomPolje [], int LPoz, int DPoz, int DesniKraj) {
  int i, LijeviKraj, BrojClanova, PomPoz;
  LijeviKraj = DPoz - 1;
  PomPoz = LPoz;
  BrojClanova = DesniKraj - LPoz + 1;
  // glavna pelja
  while (LPoz <= LijeviKraj && DPoz <= DesniKraj) {
    if (A [LPoz].ukupno >= A [DPoz].ukupno)
      PomPolje [PomPoz++] = A [LPoz++];
    else 
	  PomPolje [PomPoz++] = A [DPoz++];
  }
  while (LPoz <= LijeviKraj)
    // Kopiraj ostatak prve polovice
    PomPolje [PomPoz++] = A [LPoz++];
  while (DPoz <= DesniKraj)
    // Kopiraj ostatak druge polovice
    PomPolje [PomPoz++] = A [DPoz++];
  for (i = 0; i < BrojClanova; i++, DesniKraj--)
    A [DesniKraj] = PomPolje [DesniKraj];
}


void MSort (zapis A [], zapis PomPolje[], int lijevo, int desno ) {
  int sredina;
  if (lijevo < desno) {
    sredina = (lijevo + desno) / 2;
    MSort (A, PomPolje, lijevo, sredina);
    MSort (A, PomPolje, sredina + 1, desno);
    Merge (A, PomPolje, lijevo, sredina + 1, desno);
  }
}

void MergeSort (zapis A [], int broj) {
  zapis *PomPolje;
  PomPolje = malloc (broj * sizeof (zapis));
  if (PomPolje != NULL) {
    MSort (A, PomPolje, 0, N - 1);
    free (PomPolje);
  } else 
	printf("Nema mjesta za PomPolje!");
}
int dodaj(FILE *f, zapis novi) {
	int adr, i, j;
	zapis pretinac[C];
	i = adr = adresa(novi.sifra);
	do {
		fseek (f, i*BLOK, SEEK_SET);
		fread (pretinac, sizeof (pretinac), 1, f);
		for (j = 0; j < C; j++) {
			if (pretinac[j].sifra == 0) {
				pretinac[j] = novi;
				fseek (f, i*BLOK, SEEK_SET);
				fwrite (pretinac, sizeof (pretinac), 1, f);
				if (i == adr) return 1;
				else return -1;
			}
		}
		i = (i + 1) % M;
	} while (i != adr);
	return 0;
}

int main(void){
	FILE *dat_pristupnici,*dat_ispiti,*datoteke,*bin_pristupnici;
	struct{
		int sifra;
		char ime[20+1];
		char prezime[20+1];
	}pristupnici;
	struct{
		char datoteka[20+1];
		int prag;
	}ispiti;
	struct{
		int sifra;
		int bodovi;
	}rezultati;
	char hashtag;
	dat_pristupnici=fopen("pristupnici.txt","r");
	if(dat_pristupnici==NULL){
		printf("Ne mogu otvoriti datoteku pristupnici.txt");
		exit(1);
	}
	dat_ispiti=fopen("ispiti.txt","r");
	if(dat_pristupnici==NULL){
		printf("Ne mogu otvoriti datoteku ispiti.txt");
		exit(2);
	}
	bin_pristupnici=fopen("pristupnici.bin","wb+");
	while(fscanf(dat_pristupnici,"%d%c%[^#]%c%[^\n]",&pristupnici.sifra,&hashtag,pristupnici.ime,&hashtag,pristupnici.prezime)==5){
		spremi.ukupno=0;
		spremi.brpolozenih=0;
		fseek(dat_ispiti,0,SEEK_SET);
		while(fscanf(dat_ispiti,"%[^#]%c%d\n",ispiti.datoteka,&hashtag,&ispiti.prag)==3){      //Idemo prvo po ispitima; 
			datoteke=fopen(ispiti.datoteka,"r"); 				 //Otvaramo redom datoteke s podacima o pojedinom ispitu;
			if (datoteke==NULL){
				printf("Ne mogu otvoriti datoteku %s.",*datoteke);
				exit(3);
			}
			while(fscanf(datoteke,"%d%c%d",&rezultati.sifra,&hashtag,&rezultati.bodovi)==3){ //Citamo podatke iz pojedinog ispita;
				if(pristupnici.sifra==rezultati.sifra){    	//Ako smo pronasli pravog studenta;
					if(rezultati.bodovi>=ispiti.prag){		//Gledamo je li polozio i povecavamo brojac ako jest;
						spremi.brpolozenih++;
						spremi.ukupno+=rezultati.bodovi;
					}										//Spremamo njegove bodove;
				break;
				}
			}
		fclose(datoteke);
		}	
	spremi.sifra=pristupnici.sifra;	
	strcpy(spremi.ime,pristupnici.ime);
	strcpy(spremi.prezime,pristupnici.prezime);
	dodaj(bin_pristupnici,spremi);
	}
	fclose(dat_ispiti);
	fclose(dat_pristupnici);
	fclose(bin_pristupnici);
	//Rijesili smo upis u .bin file. Sad slijedi sortiranje.;
	FILE *diskv,*ranglista;
	diskv=fopen("diskvalifikacije.txt","w+");
	ranglista=fopen("ranglista.txt","w+");
	bin_pristupnici=fopen("pristupnici.bin","rb");
	int i, j,brojac=0;
	zapis ladica[C];
	for (i = 0; i < M; i++) {
		fseek (bin_pristupnici, i*BLOK, SEEK_SET);
		fread (ladica, sizeof (ladica), 1, bin_pristupnici);
		for (j = 0; j < C; j++) {
			if(ladica[j].sifra!=0&&isalpha(ladica[j].ime[0])){
				svizapisi[brojac]=ladica[j];
				brojac++;
			}
		}
	}
	j=0;
	MergeSort(&svizapisi[0],N);
	for(i=0;i<N;++i)
		if(svizapisi[i].brpolozenih<3)
			fprintf(diskv,"%d%c%s%c%s%c%d\n",svizapisi[i].sifra,hashtag,svizapisi[i].ime,hashtag,svizapisi[i].prezime,hashtag,svizapisi[i].brpolozenih);
		else{
			fprintf(ranglista,"%d%c%s%c%s%c%d\n",j+1,hashtag,svizapisi[i].ime,hashtag,svizapisi[i].prezime,hashtag,svizapisi[i].ukupno);
			j++;
		}
	fclose(diskv);
	fclose(ranglista);
	fclose(bin_pristupnici);
	return 0;
}