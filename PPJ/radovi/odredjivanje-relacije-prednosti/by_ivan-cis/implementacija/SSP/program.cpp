#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
 	
//funkcija_1: za zavrsni znak kao lijevi operand, traze se svi moguci prijelazi nezavrsnog(desnog operanda) s lijeva nadesno u svakom retku datoteke
void funkcija_1(int zavrsni, int nezavrsni, int *brojac_retka, char *pzz, int broj_zavrsnih){ 
	FILE *citanje; 
	char linija[20];
	char prijelaz[20] = {'\0'}; //inicijalizacija polja
	int duljina_reda=0;
	int duljina_prijelaza=0;
	int zastavica = 0;
	int brojac = -1; //brojac znaka u prijelazu produkcije
	int indeks_retka=0;
	int indeks_stupca=0;
	int j=*brojac_retka; 
	citanje = fopen("produkcije.txt", "r");
	
	if (*brojac_retka==0){ fgets(linija, 20, citanje);}
	else{
		for(*brojac_retka; j>=1; j--){ //petlja kojom se prolazi kroz sve redove dok se ne dolazi do zeljenog
			if (fgets(linija, 20, citanje)==NULL){
				fclose(citanje); 
				return;
			}
		}
	}

	if (linija[0] == '<'){			
		if (linija[1] != nezavrsni) {
			int (*brojac_retka)++;
			fclose(citanje);
			funkcija_1(zavrsni, nezavrsni, brojac_retka, pzz, broj_zavrsnih);
			return; //zavrsetak funkcije, nakon što završi pozvana funkcija
		}
		printf("---funkcija_1");
		duljina_reda = strlen(linija);
		printf("\nduljina reda: %d\n", duljina_reda);
		duljina_prijelaza = duljina_reda-6; //od 6. znaka poèinje prijelaz, 5 prvih znakova + zadnji \n koji je pretvoren u \0
		strncpy(prijelaz, &linija[5], duljina_prijelaza);
		printf("prijelaz produkcije: %s\n",prijelaz);
	
		while((brojac<duljina_prijelaza-3) || (duljina_prijelaza==1)){ //mora biti ispred <veliko_slovo>
			brojac++;
			//printf("broj znaka: %d ",brojac);
			if(prijelaz[brojac] != '-' && prijelaz[brojac] != '<' && prijelaz[brojac] != '>'  && (prijelaz[brojac]<'A' || prijelaz[brojac]>'Z')) //promjeniti u poptrogram_3 da nema razmaka//post-oduzimanje
				{printf("azuriranje tablice sa: %c \n",prijelaz[brojac]); 
				
				//azuriranje tablice prednosti
				indeks_retka=0;
				indeks_stupca=0;	
				while(pzz[indeks_retka]!=char(zavrsni)){ //odreðivanje lijevog operanda
					indeks_retka++;
				}
				while(pzz[indeks_stupca]!=char(prijelaz[brojac])){	//odredjivanje desnog operanda
				indeks_stupca++;
				}
				printf("indeks retka - %d, indeks stupca - %d\n",indeks_retka, indeks_stupca);
				pzz[(indeks_retka+1)*broj_zavrsnih+(indeks_stupca)]='<'; //indeks_retka+1: prvih broj_zavrsnih je polje zavrsnih znakova
				printf("prednost: %c < %c\n", zavrsni, int (prijelaz[brojac]));
				zastavica = 1; //gotov redak, prelazak na sljedeci, sa *brojac_retka
				int (*brojac_retka)++;
				break; 
			}
		}
		
		if (zastavica == 0){ //ako nije nadjen zavrsni znak u trenutnom redu 
			int (*brojac_retka)++; 
			fclose(citanje);
			j=*brojac_retka;
			*brojac_retka=0; //trazi se nezavrsni znak s lijeve strane produkcije, od pocetka datoteke prema dolje
			funkcija_1(zavrsni, linija[duljina_reda-3], brojac_retka, pzz, broj_zavrsnih); //rekurzija s najdesnijim nezavrsnim znakom, - \0 i -1 za predzadnji znak (veliko_slovo) i -1 jer indeks polja krece od 0
			//printf("potprogram se poziva sa nezavrsni= %s i zavrsni: %c", linija[duljina_reda-2], zavrsni);
			*brojac_retka=j;
		}
		
			fclose(citanje);
			funkcija_1(zavrsni, nezavrsni, brojac_retka, pzz, broj_zavrsnih); //nova funkcija pretražuje od sljedeæeg retka
	}
	else{
		fclose(citanje);
		return ;
	}
}
void funkcija_2(int broj_zavrsnih, char *pzz){ //odredjuje relacije jednakosti tako da proðe cijeli file i traži po pravilima za jednakost
	FILE *citanje;
	char linija[20];
	int duljina_reda=0;
	int duljina_prijelaza=0;
	int i=0;
	int indeks_retka=0;
	int indeks_stupca=0;
		
	citanje = fopen("produkcije.txt", "r");
	
	while(fgets(linija, 20, citanje)!=NULL){
	char prijelaz[20] = {'\0'}; // inicijalizacija polja
		if (linija[0] == '<'){
			duljina_reda = strlen(linija);
			duljina_prijelaza = duljina_reda-6;	//od 6. znaka poèinje prijelaz, 5 prvih znakova + zadnji znak: \0
			strncpy(prijelaz, &linija[5], duljina_prijelaza);
			printf("prijelaz produkcije: %s\n",prijelaz);
			i=0;
			while(duljina_prijelaza>0){
				duljina_prijelaza--;
				if(prijelaz[i] != '-' && prijelaz[i] != '<' && prijelaz[i] != '>' && (prijelaz[i]<'A' || prijelaz[i]>'Z')){ //procitan znak je zavrsen
					if(prijelaz[i+1] != '-' && prijelaz[i+1] != '<' && prijelaz[i+1] != '>' && (prijelaz[i+1]<'A' || prijelaz[i+1]>'Z')&& prijelaz[i+1] != '\0'){ //znak poslije procitanog je zavrsen
						//azuriranje tablice prednosti
						while(pzz[indeks_retka]!=prijelaz[i]){ //lijevi operand
						indeks_retka++;
						}
						while(pzz[indeks_stupca]!=prijelaz[i+1]){ //desni operand
						indeks_stupca++;
						}
						//printf("indeks retka - %d, indeks stupca - %d\n",indeks_retka, indeks_stupca);
						pzz[(indeks_retka+1)*broj_zavrsnih+(indeks_stupca)]='='; 
					}
					else if(prijelaz[i+4] != '-' && prijelaz[i+4] != '<' && prijelaz[i+4] != '>' && (prijelaz[i+4]<'A' || prijelaz[i+4]>'Z')&& prijelaz[i+4] != '\0'){
						//azuriranje tablice prednosti
						while(pzz[indeks_retka]!=prijelaz[i]){ //lijevi operand
						indeks_retka++;
						}
						while(pzz[indeks_stupca]!=prijelaz[i+4]){ //desni operand
						indeks_stupca++;
						}
						//printf("indeks retka - %d, indeks stupca - %d\n",indeks_retka, indeks_stupca);
						pzz[(indeks_retka+1)*broj_zavrsnih+(indeks_stupca)]='='; 
					}
				}
				i++;
			}
		}
		else{
			fclose(citanje);	
			return ;
		}
	}
	fclose(citanje);
	return ;
}
//funkcija_3: za zavrsni kao desni operand, traze se svi moguci prijelazi nezavrsnog(lijevog operanda) s desna nalijevo u svakom retku datoteke
void funkcija_3(int zavrsni, int nezavrsni, int *brojac_retka, char *pzz, int broj_zavrsnih){ 
	FILE *citanje;
	char linija[20];
	char prijelaz[20] = {'\0'}; //inicijalizacija polja
	int duljina_reda=0;
	int duljina_prijelaza=0;
	int zastavica = 0;
	int j=*brojac_retka; 
	int indeks_retka=0;
	int indeks_stupca=0;

	citanje = fopen("produkcije.txt", "r");
			
	if (*brojac_retka==0){ fgets(linija, 20, citanje);}
	else{
		for(*brojac_retka; j>=1; j--){ 
			if (fgets(linija, 20, citanje)==NULL){
				fclose(citanje); 
				return;
			}
		}
	}
				
	if (linija[0] == '<'){
		if (linija[1] != nezavrsni){ //ako nije nezavrseni u tom redu
			int (*brojac_retka)++;
			funkcija_3(zavrsni, nezavrsni, brojac_retka, pzz, broj_zavrsnih);
			fclose(citanje);
			return; //zavrsetak funkcije koja poziva drugu funkciju
		}
		printf("---funkcija_3");
		duljina_reda = strlen(linija);
		printf("\nduljina reda: %d\n", duljina_reda);
		duljina_prijelaza = duljina_reda-6; //od 6. znaka poèinje prijelaz, 5 prvih znakova + zadnji \n koji je pretvoren u \0
		strncpy(prijelaz, &linija[5], duljina_prijelaza);
		printf("prijelaz produkcije: %s\n",prijelaz);

		while(duljina_prijelaza>0){
			duljina_prijelaza--;
			if(prijelaz[duljina_prijelaza] != '-' && prijelaz[duljina_prijelaza] != '<' && prijelaz[duljina_prijelaza] != '>' && (prijelaz[duljina_prijelaza]<'A' || prijelaz[duljina_prijelaza]>'Z')) {
				printf("azuriranje tablice sa: %c \n",prijelaz[duljina_prijelaza]);
				
				//azuriranje tablice
				indeks_retka=0;
				indeks_stupca=0;	
				while(pzz[indeks_stupca]!=char(zavrsni)){ //lijevi operand
					indeks_stupca++;
				}
				while(pzz[indeks_retka]!=char(prijelaz[duljina_prijelaza])){ //desni operand
					indeks_retka++;
				}
				printf("indeks retka - %d, indeks stupca - %d\n",indeks_retka, indeks_stupca);
				pzz[(indeks_retka+1)*broj_zavrsnih+(indeks_stupca)]='>'; //indeks_retka+1: prvih "broj_zavrsnih" je polje zavrsnih znakova
				printf("prednost: %c < %c\n", zavrsni, int (prijelaz[duljina_prijelaza]));
				zastavica = 1; //gotovo
				int (*brojac_retka)++;
				break; 
				}
		}
		
		if (zastavica == 0){ //ako nisi našao završni znak s desna nalijevo onda trazi zavrsni znak u sljedecem redu
			int (*brojac_retka)++; 
			j=*brojac_retka;
			*brojac_retka=0;
			fclose(citanje); //gasenje toka podataka podprograma koji poziva sljedeci potprogram
			funkcija_3(zavrsni, linija[6], brojac_retka, pzz, broj_zavrsnih); //rekurzija sa sljedecim nezavrsnim znakom
			*brojac_retka=j;// ako se nezavrsni znak nalazi u ostatku teksta na dolje, jer se sigurno ne nalazi iznad u datoteci
		}
		fclose(citanje); 	//gasenenje toka podataka funkcije koja poziva sljedecu funkciju
		funkcija_3(zavrsni, nezavrsni, brojac_retka, pzz, broj_zavrsnih); //potprogram prolazi datoteku od sljedeæeg retka
	}
	else{
		fclose(citanje);
		return ;
	}
}


int main(){ //na kraju niza linije nalaze se zadnja 2 znaka /0 i \n !!!!!!!!!!!!!!!!
	char linija[20]; //polje za pohranu retka ulazne datoteke, na cijem se kraju nalazi \0 i \n
	int i = 0;
	int j = 0;
	int br_retka = 1;
	int najduza_produkcija = 0;
	int najduzi_prijelaz = 0;
	int broj_zavrsnih = 0;
	int *brojac_retka = &br_retka; //pokazuje na broj retka koji su procitani, koristeno kako bi se danom broju retka moglo pristupiti iz svih funkcija
	
	FILE *citanje;
	FILE *citanje2;
	FILE *pisanje;
	citanje = fopen("produkcije.txt", "r");
	citanje2 = fopen("produkcije.txt", "r");
	pisanje = fopen("tablica relacija prednosti.txt", "w");
	
	if (citanje == NULL){
	printf("Ulazna datoteka, produkcije.txt, nije prilozena uz kod. \n");
		fclose(pisanje);
		fclose(citanje);
		fclose(citanje2);
		return 0;
	}
	
	char *pzz; //za realocirajuce polje tj. za niz znakova u koje se pohranjuju svi zavrsni znakovi gramatike
	pzz = (char *) malloc(1);
	while(fgets(linija, 20, citanje) != NULL){ //petlja odreduje velicinu polja za najduzu produkciju, najduzi prijelaz i broj zavrsnih znakova
		i=0;
		while(i<int (strlen(linija))-1){ //duljina niza -1(na kraju je \n), < jer indeks kreæe od 0
				if(linija[i] != '-' && linija[i] != '<' && linija[i] != '>' && (linija[i]<'A' || linija[i]>'Z')){//za svaki zavrsni znak
				broj_zavrsnih++;
				pzz = (char *) realloc (pzz, broj_zavrsnih*broj_zavrsnih+broj_zavrsnih); //prosirujem polje zavrsnih znakova s novim zavrsnim znakom
				
				//nuliranje realociranog znakovnog niza
				while(j<broj_zavrsnih*broj_zavrsnih+broj_zavrsnih){
				pzz[j]='\0';
				j++;
				}

				pzz[broj_zavrsnih-1]=linija[i]; //prvih "broj_zavrsnih" su zavrsni znakovi, "broj_zavrsnih*broj_zavrsnih" -> char mjesta su za prednosti
				}
				i++;
		}
		if (najduza_produkcija < int (strlen(linija))){ //moraju biti istog formata
			najduza_produkcija = int (strlen(linija));
			najduzi_prijelaz = int (strlen(linija))-6;
		}
	}
		
	printf("Za zadanu gramatiku, najduza produkcija: %d, najduzi prijelaz: %d, broj zavrsnih znakova: %d. \n", najduza_produkcija, najduzi_prijelaz, broj_zavrsnih); 
	printf("Svi zavrsni znakovi u zadanoj gramatici: ");
	i=0;
	while(i<broj_zavrsnih){
	printf("%c, ",pzz[i]);
	i++;
	}
	
	//petlja obilaska kroz datoteku "produkcije.txt", s  tokom podataka citanje2
	while (fgets(linija, 20, citanje2)!=NULL){ 
		i=5;
		while(linija[i] != '\n'){ //linija[i] => lijevi_operand
			//printf("linija[i]   = %c\n", linija[i]);
			//printf("linija[i+1] = %c\n\n", linija[i+1]);
			if (linija[6] == '\n') break; //skenirati sljedeci red, jer je u ovom samo jedan (zavrsni) znak u prijelazu
			if (linija[8] == '\n') break; //skenirati sljedeci red, jer je u ovom samo jedan (nezavrsni) znak u prijelazu
			if(linija[i] != '-' && linija[i] != '<' && linija[i] != '>' && (linija[i]<'A' || linija[i]>'Z')){ //ako je lijevi operand zavrsni
				if(linija[i+1] == '<'){
					br_retka = 1;
					*brojac_retka=0; //nezavrsni znak trazi se s lijeve strane produkcije, od prvog retka datoteke 
					funkcija_1(linija[i], linija[i+2], brojac_retka, pzz, broj_zavrsnih); //argumenti:(zavrsni, nezavrsni...)
				}
			}
			if(i>=8){ //ako je lijevi operand nezavrsni, prvi desni operand moze biti zavrsni, tek iza 8. mjesta u produkciji tj. poslije znaka ">"
				if(linija[i] != '-' && linija[i] != '<' && linija[i] != '>' && (linija[i]<'A' || linija[i]>'Z')){
					if((linija[i-2]>='A' && linija[i-2]<='Z'))//ako je znak prije zavrsnog nezavrsni
					{
					//printf("-pozvan funkcija_3 %c,%c ",linija[i], linija[i-2]);
					*brojac_retka=0; //nezavrsni znak trazi se s lijeve strane produkcije, od prvog retka datoteke 
					funkcija_3(linija[i], linija[i-2], brojac_retka, pzz, broj_zavrsnih); //argumenti:(zavrsni, nezavrsni...)
					}		
				}	
			}
		i++;		
		}
	}
	
	funkcija_2(broj_zavrsnih, pzz); //poziva se nakon svih zvanja funkcija: funkcija_1 i funkcija_3, kako bi se odredila relacija jednakosti

	//ispis tablice relacija prednosti u datoteku "tablica relacija prednosti.txt"
	i=0;
	fputc(' ', pisanje); // pocetni odmak
	fputc(' ', pisanje); // pocetni odmak
	
	while(i<broj_zavrsnih*broj_zavrsnih+broj_zavrsnih){
		fputc(pzz[i], pisanje);
		fputc(' ', pisanje);
		i++;
		if(i%broj_zavrsnih==0 && i<broj_zavrsnih*broj_zavrsnih+broj_zavrsnih){
			if(i==broj_zavrsnih)fputc('K', pisanje); //kraj ulaznog niza
			if(i!=broj_zavrsnih)fputc('>', pisanje);
			fputc('\n', pisanje);
			fputc(pzz[(i/broj_zavrsnih)-1], pisanje);
			fputc(' ', pisanje);
		}
	}
	fputc('>', pisanje);
	fputc('\n', pisanje);
	fputc('D', pisanje); //dno stoga
	fputc(' ', pisanje);
	i=0;
	while(i<broj_zavrsnih){
		fputc('<', pisanje);
		fputc(' ', pisanje);
		i++;
	}
	printf("\n");
	
	free(pzz);
	fclose(pisanje);
	fclose(citanje);
	fclose(citanje2);
	return 0;
} 