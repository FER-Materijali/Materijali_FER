#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>

#define MAX_SIZE 50
#define ST_DULJINA 10
#define MAX_POZ 100

FILE *f;

void trazi_desno ( int *pozicija, int *pocetak, char traka[], int *pom_glave, int lista_poz[], int *br_polja);
void trazi_lijevo ( int *pozicija, int *pocetak, char traka[], int *pom_glave, int lista_poz[], int *br_polja);
void prijelazi (FILE *f, int *pozicija, char traka[], int *pom_glave, int lista_poz[], int *br_polja, char *zn, char tr_stanje[]);    

int main (){
    
    char ulaz [MAX_SIZE];                                                       //ulazni niz Turingovog stroja
    int pozicija=0, poc=0, i=0, p=0, j=0;
    char *traka;                                                                //znakovno polje koji ce predstavljati traku
    size_t size;                                                                //velicina polja
    int lista_poz[MAX_POZ];                                                     //lista pozicija na traci koje smo koristili
    
    char stanje[ST_DULJINA], novo_stanje[ST_DULJINA];                           //imena stanja zapisujemo u stringove
    char znak, novi_znak, pomak;                                                
    char tr_stanje[ST_DULJINA], zn;                                             //imamo i pomocni string za zapis trenutnog stanja
        
    int pom_glave=0;                                                            //brojac pomaka glave (vremenska slozenost)
    int br_polja=0;                                                             //brojac ukupnog broja polja po kojima se 
                                                                                //glava pomicala (prostorna slozenost)
    
    if( (f  = fopen( "ulaz.txt", "r" )) == NULL ) {                             //otvaranje datoteke sa popisom funkcija prijelaza
          printf( "Ne mogu otvoriti datoteku s prijelazima!\n" );
          exit(1);   
    }
    
    printf("Unesi ulazni niz:");                                                //unosimo ulazni niz
    scanf ("%s", ulaz);              
        
    printf ("\nUnesi pocetni polozaj glave:");                                  //unosimo odmak glave od pocetka niza
    scanf ("%d", &pozicija);
    
    if ( (traka = (char *)malloc( 10 * abs(pozicija) + MAX_SIZE )) == NULL ) {  // alocira se polje duljine (10 odmaka glave +
         printf ("Greska pri alociranju polja \n");                             //maksimalna duljina ulaznog niza)
         exit( 1 );  
    }
   
    size = _msize(traka);                                                       
    p =  size / 2;
    poc = p;
    
    printf( "\nVelicina trake je %u\n", size );
    printf ("Pocetni znak ulaznog niza se upisuje na mjesto %d \n", poc);
    
    for (i=0; i<p;i++)                                                          //ulazni niz zapisujemo na sredinu trake
        traka[i]='B';                                                           //ostatak trake se prepisuje s 'B'

    for (i=0; i<strlen(ulaz);i++){                                              
        traka[p] = ulaz[i];
        ++p;
    }

    for (i=p;i<size;i++)
        traka[i]='B';
     
    for (i=0;i<size;i++)
    printf ("%c", traka[i]);

    printf ("\n\n");
    
    pozicija +=poc;

    printf ("Na pocetku rada glava se nalazi na poziciji %d \n", pozicija) ;
    
    
    // postupak pozicioniranja:
                
    if (pozicija != poc){                                                       //prvo provjerimo nalazi li se glava iznad nekog
       printf ("Pozicioniranje glave na pocetak niza:\n");                      //od znakova ulaznog niza
       
       if ((traka[pozicija])=='B'){                                             //ako se ne nalazi, na prazno polje upisujemo '$',
          traka[pozicija]='$';                                                  // stavimo to polje trake u listu iskoristenih polja
          lista_poz[br_polja] = pozicija;                                       //i pomaknemo glavu udesno
          ++br_polja;                                                           
          ++pom_glave;         
          ++pozicija;                                                          
          
          trazi_desno(&pozicija, &poc, traka, &pom_glave, lista_poz, &br_polja);
       }   
       else {
            printf ("\nGlava se nalazi iznad ulaznog niza!!!\n");
            lista_poz[br_polja] = pozicija;                               
            ++br_polja;          
       }
       
       if (pozicija > poc){                                                       //ako je iznad nekog znaka ulaznog niza, ali ne na prvom znaku
            while ( pozicija != poc-1){                                           //pronadji prvi znak
                  --pozicija;                                                   
                  ++pom_glave;
                  lista_poz[br_polja] = pozicija;                               //i upisi sve pozicije preko kojih si prosao
                  ++br_polja;                                                   // u listu
                  
            }
            ++pozicija;
            ++pom_glave;
       }
    }
    
    printf("br_polja:%d\n", br_polja);         
    printf("pozicija:%d\n", pozicija);         
    
    printf ("\nGlava je pozicionirana na prvi znak ulaznog niza, %c, koji se nalazi na poziciji %d \n\n", traka[pozicija], pozicija);
    
    for (i=0;i<size;i++){
       printf ("%c", traka[i]);
    }
    printf ("\n\n");

    fseek( f, 0L, SEEK_SET);                                                    // pozicioniranje na pocetak datoteke
    fscanf (f," %10[^\n]", tr_stanje);                                          // procitaj pocetno stanje
    zn = traka[pozicija];                                                       // u zn upisi znak sa trenutne pozicije trake
    printf ("Pocetno stanje %s \n\n", tr_stanje);
    
    printf ("Do pronalaska niza glava se pomakla ukupno %d puta preko %d polja ulazne trake. \n", pom_glave, br_polja); 
    
    printf("br_polja:%d\n", br_polja);         
    printf("pozicija:%d\n", pozicija);         
    
    prijelazi (f, &pozicija, traka, &pom_glave, lista_poz, &br_polja, &zn, tr_stanje);   //izvrsi f-je prijelaza             
    
    printf("br_polja:%d\n", br_polja);                                          //na kraju ispisi ukupni broj polja
    printf("pozicija:%d\n", pozicija);                                          //i trenutnu poziciju glave
 
    printf ("\nProstorna slozenost: %d\n",br_polja);                            
    printf ("Vremenska slozenost: %d\n\n",pom_glave);           
       
    if(f){                                                                       //zatvaranje ulazne datoteke
       if (fclose(f)){
          printf( "Zatvaranje datoteke 'ulaz.txt' nije moguce napraviti!\n" );
      }
   }
   printf ("Konacni izgled trake:\n\n");
   for (i=0;i<size;i++){
      printf ("%c", traka[i]);
   }
/*   printf ("\n\n");
   for (i=0;i<br_polja;i++){
      printf ("Lista_poz na polju %d ima poziciju %d \n\n  ", i, lista_poz[i]); //moze se pogledati kako su spremana pozicije u listu 
   }
   */
   
   free(traka);                                                                 //oslobadjanje polja iz memorije
   
   return 0;
}

void trazi_desno ( int *pozicija, int *pocetak, char traka[], int *pom_glave, int lista_poz[], int *br_polja){
                 
    if ((traka[*pozicija])=='B'){                                               //nakon prvog pomaka udesno gledamo je li pronadjen niz
               ++(*pozicija);                                                   // ako nije, pomaknemo se jos jednom ulijevo
               ++(*pom_glave);
                     
               if ((traka[*pozicija])=='B'){                                    //ako ni nakon drugog pomaka nije nadjen ulazni niz
                  traka[*pozicija]='$';                                         //na prazno mjesto upisemo '$'
                  --*pozicija;                                                  //upisi prethodnu poziciju u listu
                  lista_poz[*br_polja] = (*pozicija);
                  ++(*br_polja);                                                
                  ++(*pozicija);                                                
                  lista_poz[*br_polja] = (*pozicija);                           //pa zatim trenutnu poziciju u listu
                  ++(*br_polja);                                                
                  
                  ++(*pom_glave);                                               //pocni kretanje ulijevo
                  --(*pozicija);                                                //i trazi ulazni niz
                  
                  trazi_lijevo (pozicija, pocetak, traka, pom_glave, lista_poz, br_polja); 
               }
               else if ((traka[*pozicija])=='$'){                               //ako je nakon drugog pomaka udesno procitan '$',
                    ++(*pom_glave);                                             //znaci da smo taj dio niza vec jednom prosli.
                    ++(*pozicija);                                              //Nastavi se kretati udesno i ponovi gore navedeni postupak
                    trazi_desno (pozicija, pocetak, traka, pom_glave, lista_poz, br_polja);
               }
               else {                                                           //ako je procitan bilo koji drugi znak, pronasli smo ulazni niz!
                  printf ("\n Pronasao niz!!! \n"); 
                  --*pozicija;                                                  //upisi prethodnu poziciju u listu
                  lista_poz[*br_polja] = (*pozicija);                           
                  ++(*br_polja);                                                
                  ++(*pozicija);                                                
                  lista_poz[*br_polja] = (*pozicija);                           //pa zatim trenutnu poziciju u listu
                  ++(*br_polja);                     
                  printf ("\nGlava je pozicionirana na prvi znak ulaznog niza\n");
               }    
      }
    else {                                                                      //ako je nakon prvog pomaka desno pronadjen ulazni niz
         printf ("\n Pronasao niz!!! \n");                                      //upisi poziciju u listu
         lista_poz[*br_polja] = *pozicija;
         ++(*br_polja);                    
    }
}

void trazi_lijevo ( int *pozicija, int *pocetak, char traka[], int *pom_glave, int lista_poz[], int *br_polja){
           
    if ((traka[*pozicija])=='B'){                                               //nakon prvog pomaka ulijevo gledamo je li pronadjen ulazni niz
               --(*pozicija);                                                   //ako nije, pomakni se za jedno mjesto ulijevo
               ++(*pom_glave);
    
               if ((traka[*pozicija])=='B'){                                    //ako ni nakon drugog pomaka ulijevo nije pronadjen ulazni niz
                 traka[*pozicija]='$';                                          //stavi oznaku '$'
                 ++*pozicija;                                                   //upisi prethodnu poziciju u listu
                 lista_poz[*br_polja] = (*pozicija);          
                 ++(*br_polja);                                                
                 --(*pozicija);                                                 //pa zatim trenutnu poziciju  listu
                 lista_poz[*br_polja] = (*pozicija);                           
                 ++(*br_polja);                                                                 
                 ++(*pom_glave);                                                       
                 ++(*pozicija);                                                 //i kreni traziti udesno
                 trazi_desno (pozicija, pocetak, traka, pom_glave, lista_poz, br_polja);
               }
               
               else if ((traka[*pozicija])=='$'){                               //ako nakon drugog pomaka procita '$'
               ++(*pom_glave);                                                  //taj dio niza smo vec prosli
               --(*pozicija);                                                   //nastavi traziti ulijevo
               trazi_lijevo (pozicija, pocetak, traka, pom_glave, lista_poz, br_polja);
               }
               else {
                  printf ("\n Pronasao niz!!! \n");                             //Ako je nakon drugog pomaka pronadjen ulazni niz
                  ++*pozicija;                                                   //upisi prethodnu poziciju u listu
                 lista_poz[*br_polja] = (*pozicija);          
                 ++(*br_polja);                                                
                 --(*pozicija);                                                 //pa zatim trenutnu poziciju  listu
                 lista_poz[*br_polja] = (*pozicija);                           
                 ++(*br_polja);                                                                 
                 ++(*pom_glave);                                                       
               }    
    }
    else {
         printf ("\n Pronasao niz!!! \n");                                      //ako je nakon prvog pomaka pronadjen ulazni niz
        lista_poz[*br_polja] = *pozicija;                                       //upisi poziciju u listu
        ++(*br_polja);               
    }
}

void prijelazi (FILE *f, int *pozicija, char traka[], int *pom_glave, int lista_poz[], int *br_polja, char *zn, char tr_stanje[]){
    
    char pocetni[ST_DULJINA];

    int flag=0, i=0, ima=0;
    fseek( f, 0L, SEEK_SET);                                                    // pozicioniranje na pocetak datoteke
    fscanf (f," %10[^\n]", pocetni);                                            // ovdje nam pocetno stanje vise ne treba,
                                                                                // pa ga samo preskocimo
    char stanje[ST_DULJINA], novo_stanje[ST_DULJINA];
    char znak, novi_znak, pomak;
                                                                                //dok ima prijelaza zapisanih u datoteci
    while ( fscanf (f, " %10[^#]#%c#%10[^#]#%c#%c\n", stanje, &znak, novo_stanje, &novi_znak, &pomak)>0){

                   if ( (strncmp (stanje, tr_stanje, ST_DULJINA+1)) == 0 ){     //ako trenutno stanje odgovara stanju u f-ji prijelaza 
                      if (znak == *zn){                                         //i ako znak na traci odgovara znaku u f-ji prijelaza
                               printf ("\n%s#%c#%s#%c#%c\n", stanje, znak, novo_stanje, novi_znak, pomak);//ispisi f-ju
                               strcpy (tr_stanje, novo_stanje);                 //zamijeni znak na traci novim znakom
                               traka[*pozicija] = novi_znak;
                               ++flag;                                          //povecaj zastavicu flag
                               
                               for (i=0;i<(*br_polja)+1;i++){                     //ako pronadjes trenutnu poziciju u listi pozicija
                                   if (lista_poz[i] == *pozicija){               //povecaj zastavicu ima
                                      ++ima;
                                   }
                               }
                               if (ima == 0) {                                    //ako je zastavica ima = 0, znaci da pozicija nije pronadjena
                                  lista_poz[*br_polja] = *pozicija;              //u listi pozicija, pa je dodaj u listu
                                  ++(*br_polja);
                               }
                               if ( pomak == 'L') {
                                  --(*pozicija);
                               }                                                //pomakni se lijevo ili desno (ovisno o f-ji prijelaza)
                               else ++(*pozicija);
                               
                               *zn = traka[*pozicija];                          //upisi novi znak sa trake u varijablu zn
                               ++(*pom_glave);
                               ima=0;
                               
                               printf("br_polja:%d\n", *br_polja);              
                               printf("pozicija:%d\n", *pozicija);         
                      }         
                   }
    }
    
    if (flag>0) prijelazi (f, pozicija, traka, pom_glave, lista_poz, br_polja, zn, tr_stanje); // ako je bila izvrsena neka f-ja prijelaza
    else printf ("\nNema vise definiranih prijelaza!\n\n");                                    // onda se vrati na pocetak datoteke i
                                                                                               // ponovo trazi novu f-ju prijelaza
                                                                                               //inace zavrsi trazenje
}

















