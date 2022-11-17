#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>

//strukura koja mi sadrzi broj za oznacavanje ulice i string za ime ulice
struct ulica{
       int v;
       char ime[100];
       };
       
// funkcija koja mi iz zadane txt datoteka napravi matricu koja ce mi predstavljat grad
void ulice(struct ulica m[100][100],char ul[100][100]){     //m mi je matrica grada, ul je matrica ulica
     FILE *f;
     char u[100];
     int x0,y0,x1,y1;
     int i,j,p,h,v,k;
     k=1;
     if ( (f=fopen("ulice1.txt","r"))== NULL){
                                        printf("datoteka ne postoji");
                                        exit(-1);
                                        }
     //dakle citam iz datoteka
     while(fscanf(f,"%[^,], %d, %d, %d, %d\n",u,&x0,&y0,&x1,&y1)!=EOF){            //prvo ime ulice, pa pocetne pa zavrsne koordinate
                        if (x0>x1){p=x0;x0=x1,x1=p;}                               //ako su koordinate zadane obrnuto 
                        if (y0>y1){p=y0;y0=y1,y1=p;}                               //zamjenim ih 
                        for (i=(x0/50);i<=(x1/50);i++)                             //tu sam ulicu kratio sa 50 tako da mi je ulica velicine 300 ustvari velicine 6
                            for (j=(y0/50);j<=(y1/50);j++){
                                m[j+1][i+1].v+=1;                                  //i grad sam radion na taj nacin da sam svugdje gdje mi ulica prolazi povecao broj sa 1
                                if (m[j+1][i+1].v == 1)strcpy(m[j+1][i+1].ime,u);  //sto znaci ako je raskrizje moze biti i 2 ako se 2 ulice sjeku ili 3 ili 4 ako se cak 4
                                else { strcat (m[j+1][i+1].ime,", ");              //razlicite ulice sjeku
                                       strcat (m[j+1][i+1].ime,u);                 //za imena raskrzija sam samo copirao na kraj jednog imena druga imena 
                                } 
                         }                                                         //matricu sam krenuo ustvari od 1,1 jer cu na 0,0 staviti stanje greske, pa mi je cijeli prvi red i stupac slobodan
     }
     for (i=0;i<100;i++)                                                           //ovdje prebrajam kolko ima ulica i to stavljam u matricu ul 
         for (j=0;j<100;j++){                                                      //da mogu kansije imati ispise
             h=1;                                                                  //dakle na ul[1] mi se nalazi ime prve ulice, ul[2] ime druge itd
           for (v=0;v<100;v++)
               if (strcmp(m[i][j].ime,ul[v])==0) h=0;
           if(h) { strcpy(ul[k],m[i][j].ime);
                   k++;
                   }
         }
         strcpy(ul[0],"stanje pogreske");                                          //stanje 0 ce mi biti stanje greske
     for (i=0;i<20;i++){                                                           //ovo je samo ispis te matrice grada
         for (j=0;j<20;j++)
             printf("%d ",m[i][j].v);
         printf("\n");
     }              
            for (i=0;i<10;i++) printf ("%d %s\n",i,ul[i]);                         //ispis svih ulica koje postoje
}

//fukcija automat generira matricu stanja iz zadane matrice
//e sad ja sam si ovak zamislio to: auto se uvijek nalazi u nekom dijelu grada, i zamislio sam da njegovu poziciju oznacavam sa
// x i y, dakle koordinatama. e sad ak se krece u desno njegove ce koordinate biti +x i +y, u lijevo -x -y, gore -x +y, dolje +x -y
//tako da u svakom trenutku znam u kojem se smjeru krece auto i da znam u koje slijedece stanje mora auto ic

//automat je graden od 9 stupaca,
//prva dva ([0] i [1] stupac) su q(x,y), tj ime tog stanja  
//druga dva ([2] i [3]) su L(x,y) tj stanje u koje auto ide ako skrene lijevo
//treca dva ([4]i[5]) su D(x,y) tj stanje u koje auto ide ako skrene desno
//predzadnja dva ([6]i[7]) su P(x,y) tj stanje ako je auto prosao jos 100m
//i zadnji [8] je izlaz tog stanja, tj ime ulice ili raskrizja
void automat(struct ulica m[100][100], int a[500][9],char ul[100][100]){
     int i,j,k,l=1;
     for(i=1;i<100;i++)                    //dakle prolazim kroz cijlu matricu grada
         for(j=1;j<100;j++){
                            if(m[i][j].v == 1){    //i kad naidem na nesto sto je 1 dakle oznacava samo ulicu a ne i raskrzije
                                 for (k=0;k<100;k++) if (strcmp(ul[k],m[i][j].ime)== 0) break;     //prvo pronadem kako se zove ta ulica,i na kojem je mjestu u matrici imena ulica
                                 a[l][0]=j;                                          //i onda krecem sa rademnjem automata
                                 a[l][1]=i;                                          //prvo stvaram stanja za kad auto se gleda u desnom smjeru 
                                 if( m[i][j+2].v){                                   //postavim [0] i [1]  na x i y
                                     a[l][6]=j+2;                                    //[6] i [7] na x+2, y ako se auto moze pomaknuti za 100m
                                     a[l][7]=i;                                      
                                     }                                               
                                 if (m[i][j+1].v >= 2 && m[i][j+1].v <= 4){          //ako je auto ispred raskrizja (dakle 50 metara do raskrizja)
                                     a[l][2]=-(j+1);                                 //onda ako mu dodje L ili D pretpostaljat ce se da je auto napravio 50 metara i skrenuo
                                     a[l][3]=i;                                      //stoga na taj nacin i postaljvam L(x,y) i D(x,y)
                                     a[l][4]=j+1;                                    //[2] i [3] stavim na -(x+1) i y jer ce se auto pomaknut za 50 metara i gledat gore
                                     a[l][5]=(-i);                                   //a [4] i [5] na x+1 i -y jer ce se auto opet pomaknut za 50 metara i gledat ce prema dolje
                                     }
                                 a[l][8]=k;                                          //u [8] stavim redni broj ulice tako da mogu poslije usporedit s matricom imena ulica
                                 l++;                                                // i idemo u novi redak :)
                                 a[l][0]=(-j);                                       //ovo gore ponovim za svaki slucaj... dakle ovo je kada auto gleda u lijevo
                                 a[l][1]=(-i);
                                 if( m[i][j-2].v){
                                     a[l][6]=(-(j-2));
                                     a[l][7]=((-i));
                                     }
                                 if (m[i][j+1].v >= 2 && m[i][j+1].v <= 4){
                                     a[l][2]=j-1;
                                     a[l][3]=(-i);
                                     a[l][4]=(-(j-1));
                                     a[l][5]=i;
                                     }
                                 a[l][8]=k;
                                 l++;
                                 a[l][0]=j;                                          //ovo kad auto gleda gore
                                 a[l][1]=(-i);
                                 if( m[i+2][j].v){
                                     a[l][6]=j;
                                     a[l][7]=(-(i+2));
                                     }
                                 if (m[i][j+1].v >= 2 && m[i][j+1].v <= 4){
                                     a[l][2]=j;
                                     a[l][3]=i+1;
                                     a[l][4]=(-j);
                                     a[l][5]=(-(i+1));
                                     }
                                 a[l][8]=k;
                                 l++;
                                 a[l][0]=(-j);
                                 a[l][1]=i;
                                 if( m[i-2][j].v){                                   //i ovo kad auto gleda dolje
                                     a[l][6]=(-j);
                                     a[l][7]=i-2;
                                     }
                                 if (m[i][j+1].v >= 2 && m[i][j+1].v <= 4){
                                     a[l][2]=j;
                                     a[l][3]=i-1;
                                     a[l][4]=(-j);
                                     a[l][5]=(-(i-1));
                                     }
                                 a[l][8]=k;
                                 l++;                
                                 }
                            else if (m[i][j].v >=2 && m[i][j].v<=4){                 //ovdje ide ista situacija samo sa raskrizjima
                                 for (k=0;k<100;k++) if (strcmp(ul[k],m[i][j].ime)== 0) break;   //prvo pornalazim redni broj ulice u matrici imena ulica
                                 a[l][0]=j;                                          //auto ulaskom na raskrizje gleda desno
                                 a[l][1]=i;
                                 if (((i+j) % 2) == 0){                              //e sad, ovaj dio je tu zato sto sam skuzio da ako se ulica nalazi
                                    if (m[i][j+2].v){                                //ovjem partim ili objem neparnim koordinatama tj (ako je x=100 i y=200 ili x=50 i y=250)
                                       a[l][6]=j+2;                                  //onda ce auto u to raskrizje ziher doci tako da je prvo proso 100 metara
                                       a[l][7]=i;                                    //stoga ce iz tog raskrizja sa oznakom P proci jos 100 metara
                                    }                                                //i na taj nacin punim redak automata        
                                    }
                                 else if (m[i][j+1].v){                              //ovi ifovi su tu zato da mi bezveze ne napravi stanje u kojem se mogu okrenut u smjeru
                                       a[l][6]=j+1;                                  //gdje mi se ulica ne nastavlja (ovo isto tako onemogucuje kruzno okretanje)
                                       a[l][7]=i;  
                                       }
                                 if (m[i-1][j].v){                                                
                                    a[l][2]=(-j);
                                    a[l][3]=i;
                                 }
                                 if (m[i+1][j].v){
                                    a[l][4]=j;   
                                    a[l][5]=(-i);
                                    }
                                 a[l][8]=k;
                                 l++;                                              
                                 a[l][0]=(-j);                                     //auto ulaskom na raskrizje gleda ljievo
                                 a[l][1]=(-i);
                                 if (((i+j) % 2) == 0){
                                    if (m[i][j-2].v){
                                       a[l][6]=(-(j-2));
                                       a[l][7]=(-i); 
                                       }
                                       }
                                 else if (m[i][j-1].v){
                                       a[l][6]=(-(j-1));
                                       a[l][7]=(-i);  
                                       }
                                 if (m[i+1][j].v){
                                    a[l][2]=(j);
                                    a[l][3]=(-i);
                                 }
                                 if (m[i-1][j].v){
                                    a[l][4]=(-j);   
                                    a[l][5]=(i);
                                    }
                                 a[l][8]=k;
                                 l++;
                                 a[l][0]=(-j);                                     //auto ulaskom na raskrizje gleda gore
                                 a[l][1]=i;
                                 if (((i+j) % 2) == 0){
                                    if (m[i-2][j].v){
                                       a[l][6]=(-j);
                                       a[l][7]=i-2;  
                                       }
                                       }
                                 else if (m[i-1][j].v){
                                       a[l][6]=(-j);
                                       a[l][7]=i-1;  
                                       }
                                 if (m[i][j-1].v){
                                    a[l][2]=(-j);
                                    a[l][3]=(-i);
                                 }
                                 if (m[i][j+1].v){
                                    a[l][4]=j;   
                                    a[l][5]=i;
                                    }
                                 a[l][8]=k;
                                 l++;
                                 a[l][0]=j;                                        //auto ulaskom na raskrizje gleda dolje
                                 a[l][1]=(-i);
                                 if (((i+j) % 2) == 0){                                 
                                    if (m[i+2][j].v){
                                       a[l][6]=j;
                                       a[l][7]=(-(i+2));  
                                       }
                                    }
                                 else if (m[i+1][j].v){
                                         a[l][6]=j;
                                         a[l][7]=(-(i+1));  
                                         }
                                 if (m[i][j+1].v){
                                    a[l][2]=(j);
                                    a[l][3]=i;
                                 }
                                 if (m[i][j-1].v){
                                    a[l][4]=(-j);   
                                    a[l][5]=(-i);
                                    }
                                 a[l][8]=k;
                                 l++;
                                 }
                                 }
         for(i=0;i<l;i++){                                //ispis tog naseg automata
              for(j=0;j<9;j++)
                           printf("%4d",a[i][j]);
                           printf("\n");
                           }

}

//ovo je funkcija koja mi simulira taj moj automat
void autic(int a[500][9],char ul[100][100]){
     int i,j,k;
     int px,py,nx,ny;
     char ulaz[100];
     px=1;                                        //pocetno stnaje je meni q(1,1)
     py=1;
     k=0;
     i=1;
     printf("upisite ulazni niz ");               //dakle upisujemo neki niz znakova tipa PPLPDP itd...
     scanf("%s",ulaz);
     do{                                          //i za svaki character tog stringa provjeravamo:
              for(j=0;j<9;j++){                   //ovo mi je ispis za provjeru u kojem se stanju trenutno nalazimo
                           printf("%4d",a[i][j]);
                           }
              printf("\n%c\n",ulaz[k]);          //isis trenutnog ulaza
              if (ulaz[k] == 'P' || ulaz[k] == 'p'){               //ako je ulazni znak P onda naravno it trenutnog stnja idemo idemo u P(x,y)
                 nx = a[i][6];
                 ny = a[i][7];
              }
              if (ulaz[k] == 'L' || ulaz[k] == 'l'){               //ako je L onda u L(x,y)
                 nx = a[i][2];
                 ny = a[i][3];
              }      
              if (ulaz[k] == 'D' || ulaz[k] == 'd'){               //ako je D onda u D(x,y)
                 nx = a[i][4];
                 ny = a[i][5];
              }
              if ((nx==0) && (ny==0)){                             //ako je to novo stanje q(0,0) znaci da se nalazimo u stnju greske
                        printf("%s\n",ul[0]);                      //i to ispisujemo i izlazimo van iz simulatora
                        break;
              }
              px=nx;                                               //prijasnje stanje postaje novo stnaje
              py=ny;
              for (i=0;i<1000;i++) if ((px == a[i][0]) && (py == a[i][1]))break;      //i tu pretrazujem automat za tim novim stanjem i u "i" mi se nalazi
              printf("nx: %d, ny: %d\n",nx,ny);                                       //redak tog naseg novog stanja
              printf("%s\n",ul[a[i][8]]);                                             //i ispisujemo ime ulice gdje se trenutno nalazi nas autic
              k++;
     }while(ulaz[k]);                                               //to ponavljamo sve dok imamo ulazne znakove                 
}

//i u main fukcniji jednostavno samo pokrecem te sve brojne fukcije :)
int main(int argc, char *argv[])
{
    struct ulica m[100][100];   //m mi je matrica ulica tj grada
    int a[500][9];              //a mi je automat
    char ul[100][100];          //ul mi je matrica imena ulica
    ulice(m,ul);
    automat(m,a,ul);
    autic(a,ul);
    system("PAUSE");	
    return 0;
}
