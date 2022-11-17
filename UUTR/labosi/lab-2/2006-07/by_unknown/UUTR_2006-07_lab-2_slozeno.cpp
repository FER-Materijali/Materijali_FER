#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>
#include <ctype.h>

int main () {
	FILE *dat;
	char polje [512];
	char * ulaz;
	char * stogPOLJE;
	char tren,TREN,hop,prih;
    int dohvacen,k;
	int i,j;
	int brojl1; //0-9
	int brojl2;  // 3,9,2,5
	int STANJE, stanje,STOG,stog,NIZ,niz,kraj,rek,proslo,p,s;


	   if ((dat = fopen ("ulazx.txt","r")) == NULL){
			printf ("Datoteka nije dobro dohvacena!!\n");
		    exit(1);}

   	while ((fscanf (dat, "%s", &polje))!=EOF){
		brojl1=0;
		brojl2=0;
		dohvacen=(int)strlen (polje);
		

		for (i=0;i<dohvacen;i++){
			if (isdigit(polje[i]))brojl1++;    // broj brojcanih znamenaka
			if (polje[i]=='3' || polje [i]== '9' || polje [i]=='2' ||polje [i]=='5') brojl2++;}   // broj 2-ki,3-ki,9-ki i 5-ca
            
			stogPOLJE = (char*) malloc (sizeof(char)* (brojl2+2)); //puta brojl2 ali moramo dodati i K i prazan niz;
            ulaz = (char*) malloc (sizeof (char)* (brojl1+1));

			for (i=0,j=0;i<dohvacen;i++)  // filtrirano polje (samo brojevi 0-9)
				if (isdigit(polje[i])) {
					ulaz[j]=polje [i];
					j++;}
				ulaz[j]='X'; // -> kraj niza

         STANJE=stanje=STOG=stog=NIZ=niz=i=kraj=rek=0;
         stogPOLJE[0] = 'X';
		 stogPOLJE[1] ='K';
		 ulaz[brojl1]='X';
          stanje=3;
		  stog=1;
		  i=0;
		  prih='N';

		  p=5;

//STANJE-> pamti stanje u kojem se nalazi PA, kod ulaska rekurzije vraca PA u stanje prije rekurzije, kad nije u rek. onda pamti novo stanje na kraju 1. IF-a
//STOG->pamti index sa stoka prilikom ulaska u rekurziju, na kraju prvog IF-a STOG postaje novi stog no tek nakon što se napravi ispis
//NIZ-> pamti index u nizu ulaznih znakova pri ulasku u rek, na kraju prvog IF-a NIZ postaje novi niz,
//TREN-> pamti ulazni znak, ako se ulazi u rekurziju TREB postaje tren, još doradi
//rek-> govori while-u kako da se ponaša, ako je nula i dode u nedeterminizam koji ulazi u rekurziju onda postane 1, ako rekurzija nije dobra onda 
//      postaje 2 i govori prvom IF-u da nastavi dalje deterministicni sa stavljanjem na stog 
//DETERMINISTICKI PRIJELAZ-> 1.ako brojka nije 3,9,2 ili 5 onda samo povecaj i i niz, ispiši prijelaz koji je isti, stog se ne mijenja,NIZ=niz!!!
//2. ako brojka 3,9,2 ili 5 onda povecaj stog,u stogPOLJE[stog] stavi znak za tu brojku, povecaj i i niz, ispis pa STOG jednak novi stog,NIZ=niz !!! 
//ULAZAK U REKURZIJU-> spremi STANJE, STOG,NIZ,TREN, postavi stanje u odgovarajuce stanje s q1, smanji  stog, postavi rek u 1, niz ne treba smanjit 
//        jer on nastavlja dalje s citanjem ulaznog niza, NIZ==niz
//		->povecavati i uvijek 
		   printf ("brojl1=%d, brojl2=%d \n\n " ,brojl1,brojl2);

		 while (i<brojl1+1){  
                    tren=ulaz[niz];
					proslo=stanje;
					s=stog;
					
					if(rek==0 || rek ==2){	
						switch (stanje){
						case  3: 
							      if (tren == '0' || tren == '1'  || tren == '4'|| tren == '6' || tren == '7' || tren ==  '8'  )
					                {i++;
					               niz++;} 
								  else if (tren == '5' ){ stanje= 13;
								    stog++;
									stogPOLJE [stog]= 'D';
								    i++;
					               niz++;}

								  else kraj=1;
								  
								  break;

						case  13: if (tren == '0' || tren == '1' || tren == '4' || tren == '6' || tren == '7' || tren ==  '8'  ){
					                     i++;
					                     niz++;} 
								  else if (tren == '3' || tren == '9' ||tren == '2' ){
									  stog++;
									  if (tren== '3')stogPOLJE[stog]= 'A';
									  if (tren== '9')stogPOLJE[stog]= 'B';
									  if (tren== '2')stogPOLJE[stog]= 'C';
									  niz++;
									  i++;
									  stanje= 23;
								    prih='N';
		                            }								  

								  else if (rek==0 && stogPOLJE[stog]=='D' && tren=='5'){ // nedeterminizam -> 5 + D na stogu -> p1,q1
							           STANJE= stanje;
								       STOG =stog;
								       TREN=tren;
									   NIZ=niz;  
							           stanje = 14;
								       niz++;
								       stog--;
								       rek=1;
								       i++;
								    prih='N';}
							  else if (rek==2 && stogPOLJE[stog]=='D' && tren=='5' ){
									  stog++;
									  stogPOLJE [stog]= 'D';
								      i++;
					                  niz++;
								     rek=0;
								    prih='N';}
							  else kraj=1;
							   break;
    					case 23: if (tren == '0' || tren == '1'  || tren == '4' || tren == '6'|| tren == '7' || tren ==  '8'  ){
					                     i++;
					                     niz++;} 
								 else if (tren=='5'){
								 stog++;
								 stogPOLJE [stog] = 'D';
								 i++;
								 niz++;
								 stanje=13;
								    prih='N';}                                 
								 else if (rek==0 && stogPOLJE[stog]=='A' && tren=='3'){
									 STANJE= stanje;
								       STOG =stog;
								       TREN=tren;
									   NIZ=niz;
							           stanje = 24;
								       niz++;
								       stog--;
								       rek=1;
								       i++;
								    prih='N';}
								 else if ((rek ==0 ||rek==2) && tren=='3' ){
									  stog++;
									  stogPOLJE [stog]= 'A';
								      i++;
					                  niz++;
								     rek=0;
								    prih='N';}
								 else if (rek==0 && stogPOLJE[stog]=='B' && tren=='9'){
									 STANJE= stanje;
								       STOG =stog;
								       TREN=tren;
									   NIZ=niz;
							           stanje = 24;
									   niz++;
								       stog--;
								       i++;
									   rek=1;
								    prih='N';}
								 else if ( (rek ==0 ||rek==2) && tren=='9' ){
									  stog++;
									  stogPOLJE [stog]= 'B';
								      i++;
					                  niz++;
								     rek=0;
								    prih='N';}
								 else if (rek==0 && stogPOLJE[stog]=='C' && tren=='2'){
									 STANJE= stanje;
								       STOG =stog;
								       TREN=tren;
									   NIZ=niz;
							           stanje = 24;
								       niz++;
								       stog--;
								       rek=1;
								       i++;
								    prih='N';}
								 else if ((rek ==0 ||rek==2)&& tren=='2' ){
									  stog++;
									  stogPOLJE [stog]= 'C';
								      i++;
					                  niz++;
								     rek=0;
									 prih='N';}
								 else kraj=1;
								 break;}
								 

					}

 
					
					
					else {switch(stanje)	{
					  
						case  14:
							if (tren == '0' || tren == '1'  || tren == '4' || tren == '6' || tren == '7' || tren ==  '8'  ){
									  i++;
									  niz++;}
								 else if (stogPOLJE[stog]=='D' && tren=='5' ){
											   
								       //stanje = 14;   -- ne mijenja se stanje
								       niz++;
								       stog--;
								       i++;
								    prih='N';}
								 else if (stogPOLJE[stog]=='A' && tren=='3'){
									 stanje=24;
									 niz++;
								     stog--;
								     i++;
								    prih='N';}
								 else if (stogPOLJE[stog]=='B' && tren=='9'){
									 stanje=24;
									 niz++;
								     stog--;
								     i++;
								    prih='N';}
								 else if (stogPOLJE[stog]=='C' && tren=='2'){
									 stanje=24;
									 niz++;
								     stog--;
								     i++;
								    prih='N';}
								 
								 else if (tren=='X' && stogPOLJE[stog]=='K'){
									 		  prih='D';
											  	stog--;
								          
										  kraj=2;

								 }
								 
								 else { if (stogPOLJE[stog]== 'K'){ 
									          prih='D';
											  
								            }              
									 rek=2;
									 stog=STOG;
								     stanje=STANJE;
									 niz=NIZ;
									 tren=TREN;
									 i=NIZ;}
								     break;
                            
   				
	
						  case 24: 
							  if (tren == '0' || tren == '1'  || tren == '4' || tren == '6' || tren == '7' || tren ==  '8'  ){
									  i++;
									  niz++;}
							  else if (stogPOLJE[stog]=='D' && tren=='5'){
											   
								       stanje = 14;   
								       niz++;
								       stog--;
								       i++;
							           prih='N';}
							  else if (stogPOLJE[stog]=='A' && tren=='3'){
									 stanje=24;
									 niz++;
								     stog--;
								     i++;
							         prih='N';}
							  else if (stogPOLJE[stog]=='B' && tren=='9'){
									 stanje=24;
									 niz++;
								     stog--;
								     i++;
							         prih='N';}
								 else if (stogPOLJE[stog]=='C' && tren=='2'){
									 stanje=24;
									 niz++;
								     stog--;
								     i++;
								     prih='N';}
								 else {									 
									 rek=2;
									 stog=STOG;
								     stanje=STANJE;
									 niz=NIZ;
									 tren=TREN;
									 i=NIZ;
								    prih='N';}

							         break;



						} }   

			scanf("%c",&hop);						


   if (!(stanje%10-3==1))for (k=stog,p=5;k>0 || (p>=k && p>0);k--){ //problem oko k


	   if(kraj!=1){if (k<5)k=p;
	   
	   if (rek==1) printf ("\t\t");
	   if (p>=k)p--;
	   if (k <=s )printf("|%c|",stogPOLJE[k]);
	   else printf ("| |");


	   

	   if (p>4)printf ("                                       ");
       switch (p){
	   case 4:    printf ("Trenutni znak na ulazu: %c              ",tren);
		           break; 
	   
	   case 3:   printf ("Trenutno stanje: [p%d,q%d]               ", (int)proslo/10, proslo%10 -3);
		           break;


	   case 2: 	if (stanje%10 -3==1)printf ("Prijelaz: ([p%d,q%d],%c, %c) -> ([p%d,q%d],e)",(int)proslo/10, proslo%10 -3, tren,stogPOLJE[s], (int)stanje/10, stanje%10 -3); 
		        else printf ("Prijelaz: ([p%d,q%d],%c, %c) -> ([p%d,q%d],%c)",(int)proslo/10, proslo%10 -3, tren,stogPOLJE[s], (int)stanje/10, stanje%10 -3,stogPOLJE[stog]);	
		        break;   
	   case 1:      printf ("Novo stanje: [p%d,q%d]                   ", (int)stanje/10, stanje%10 -3);
		            break;
	   case 0: 
		   if (prih=='N')printf ("Trenutni niz se NE PRIHVACA!!          ");
		   else printf ("Trenutni niz se PRIHVACA!!             ");
		   break;
	   }}		   
		   
	   if(kraj==1) {printf ("Ne postoji prijelaz! Niz nije prihvacen!");
		   break;}
	   
	   if (k<=stog)printf("|%c|",stogPOLJE[k]);
	   else printf ("| |");
	   printf ("\n");
   
   
	  
   }

   else for (k=s,p=5;k>0 || (p>=k && p>0);k--){ //problem oko k
	   //printf ("\n\n");


	   if(kraj!=1){if (k<5)k=p;
	   
	   if (rek==1) printf ("\t\t");
	   if (p>=k)p--;
	   if (k <=s )printf("|%c|",stogPOLJE[k]);
	   else printf ("| |");


	   
 //ispis starog stoga
	   if (p>4)printf ("                                       ");
       switch (p){
	   case 4:    printf ("Trenutni znak na ulazu: %c              ",tren);
		           break; 
	   
	   case 3:   printf ("Trenutno stanje: [p%d,q%d]               ", (int)proslo/10, proslo%10 -3);
		           break;


	   case 2: 	if (stanje%10 -3==1)printf ("Prijelaz: ([p%d,q%d],%c, %c) -> ([p%d,q%d],e)",(int)proslo/10, proslo%10 -3, tren,stogPOLJE[s], (int)stanje/10, stanje%10 -3); 
		        else printf ("Prijelaz: ([p%d,q%d],%c, %c) -> ([p%d,q%d],%c)",(int)proslo/10, proslo%10 -3, tren,stogPOLJE[s], (int)stanje/10, stanje%10 -3,stogPOLJE[stog]);	
		        break;   
	   case 1:      printf ("Novo stanje: [p%d,q%d]                   ", (int)stanje/10, stanje%10 -3);
		            break;
	   case 0: 
		   if (prih=='N')printf ("Trenutni niz se NE PRIHVACA!!          ");
		   else printf ("Trenutni niz se PRIHVACA!!             ");
		   break;
	   }}		   
		   
	   if(kraj==1) {printf ("Ne postoji prijelaz! Niz nije prihvacen!");
		   break;}
	   
	   if (k<=stog)printf("|%c|",stogPOLJE[k]);
	   else printf ("| |");
	   printf ("\n");
   
   
	  
   }


  if (kraj!=0)break;
   }
   
   
   free (stogPOLJE);
   free (ulaz);

   printf ("\n\n----------------------------------------------\n\n");
   printf ("Nastaviti ucitavati nizove? D|N");
   do {scanf ("%c",&tren);} while(!(toupper(tren)== 'D' || toupper(tren)== 'N'));
   if (toupper(tren)=='D') break;
   
   }
   printf ("\nKRAJ!!\n");
   



   return 0;}









  
