#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){
    int stanje=0, n, i, j=0,pozicija=1,prihvatljivost=0, prijelaz;
    char *glavna_traka, *sporedna_traka, ulaz[100];
    
    printf("Unesi niz u formatu br1#br2#br3 ");
    gets(ulaz);
    n=strlen(ulaz)+2;
    if ((glavna_traka=(char*)malloc((n)*sizeof(char)))==NULL)
    {
     printf ("Ne mogu stvoriti polje!");
     exit (-1);
    }
    if ((sporedna_traka=(char*)malloc((n)*sizeof(char)))==NULL)
    {
     printf ("Ne mogu stvoriti polje!");
     exit (-1);
    }
    glavna_traka[0]='B';
    sporedna_traka[0]='B';
    for (i=1;i<n-1;i++) {
        glavna_traka[i]=ulaz[j++];
        sporedna_traka[i]='B';
        }
    glavna_traka[n-1]='B';
    sporedna_traka[n-1]='B';
    while(1){
             prijelaz=0;
             switch(stanje){
               case 0: 
               if ((glavna_traka[pozicija]=='0')&&(sporedna_traka[pozicija]=='B')) {
               stanje=0;
               glavna_traka[pozicija]='0';
               sporedna_traka[pozicija]='0';
               pozicija++;
               prijelaz=1;
               break;
               }
               if ((glavna_traka[pozicija]=='#')&&(sporedna_traka[pozicija]=='B')) {
               stanje=1;
               glavna_traka[pozicija]='#';
               sporedna_traka[pozicija]='#';
               pozicija++;
               prijelaz=1;
               break;
               }
               break;
               
               case 1:
               if ((glavna_traka[pozicija]=='0')&&(sporedna_traka[pozicija]=='B')) {
               stanje=1;
               glavna_traka[pozicija]='0';
               sporedna_traka[pozicija]='0';
               pozicija++;
               prijelaz=1;
               break;
               }
               if ((glavna_traka[pozicija]=='#')&&(sporedna_traka[pozicija]=='B')) {
               stanje=2;
               glavna_traka[pozicija]='#';
               sporedna_traka[pozicija]='#';
               pozicija++;
               prijelaz=1;
               break;
               }
               break;
               
               case 2:
               if ((glavna_traka[pozicija]=='0')&&(sporedna_traka[pozicija]=='B')) {
               stanje=2;
               glavna_traka[pozicija]='0';
               sporedna_traka[pozicija]='0';
               pozicija++;
               prijelaz=1;
               break;
               }
               if ((glavna_traka[pozicija]=='B')&&(sporedna_traka[pozicija]=='B')) {
               stanje=3;
               glavna_traka[pozicija]='B';
               sporedna_traka[pozicija]='B';
               pozicija--;
               prijelaz=1;
               break;
               }
               break;
               
               case 3:
               if ((glavna_traka[pozicija]=='0')&&(sporedna_traka[pozicija]=='0')) {
               stanje=4;
               glavna_traka[pozicija]='0';
               sporedna_traka[pozicija]='X';
               pozicija--;
               prijelaz=1;
               break;
               }
               if ((glavna_traka[pozicija]=='0')&&(sporedna_traka[pozicija]=='X')) {
               stanje=3;
               glavna_traka[pozicija]='0';
               sporedna_traka[pozicija]='X';
               pozicija++;
               prijelaz=1;
               break;
               }
               if ((glavna_traka[pozicija]=='B')&&(sporedna_traka[pozicija]=='B')) {
               stanje=8;
               glavna_traka[pozicija]='B';
               sporedna_traka[pozicija]='B';
               pozicija--;
               prijelaz=1;
               break;
               }
               break;
               
               case 4:
               if ((glavna_traka[pozicija]=='0')&&(sporedna_traka[pozicija]=='0')) {
               stanje=4;
               glavna_traka[pozicija]='0';
               sporedna_traka[pozicija]='0';
               pozicija--;
               prijelaz=1;
               break;
               }
               if ((glavna_traka[pozicija]=='#')&&(sporedna_traka[pozicija]=='#')) {
               stanje=5;
               glavna_traka[pozicija]='#';
               sporedna_traka[pozicija]='#';
               pozicija--;
               prijelaz=1;
               break;
               }
               break;
               
               case 5:
               if ((glavna_traka[pozicija]=='0')&&(sporedna_traka[pozicija]=='0')) {
               stanje=6;
               glavna_traka[pozicija]='0';
               sporedna_traka[pozicija]='X';
               pozicija++;
               prijelaz=1;
               break;
               }
               if ((glavna_traka[pozicija]=='#')&&(sporedna_traka[pozicija]=='#')) {
               stanje=7;
               glavna_traka[pozicija]='#';
               sporedna_traka[pozicija]='#';
               pozicija--;
               prijelaz=1;
               break;
               }
               if ((glavna_traka[pozicija]=='0')&&(sporedna_traka[pozicija]=='X')) {
               stanje=5;
               glavna_traka[pozicija]='0';
               sporedna_traka[pozicija]='X';
               pozicija--;
               prijelaz=1;
               break;
               }
               break;
               
               case 6:
               if ((glavna_traka[pozicija]=='#')&&(sporedna_traka[pozicija]=='#')) {
               stanje=3;
               glavna_traka[pozicija]='#';
               sporedna_traka[pozicija]='#';
               pozicija++;
               prijelaz=1;
               break;
               }
               if ((glavna_traka[pozicija]=='0')&&(sporedna_traka[pozicija]=='X')) {
               stanje=6;
               glavna_traka[pozicija]='0';
               sporedna_traka[pozicija]='X';
               pozicija++;
               prijelaz=1;
               break;
               }
               break;
               
               case 7:
               if ((glavna_traka[pozicija]=='0')&&(sporedna_traka[pozicija]=='0')) {
               stanje=8;
               glavna_traka[pozicija]='0';
               sporedna_traka[pozicija]='X';
               pozicija--;
               prijelaz=1;
               break;
               }
               break;
               
               case 8:
               if ((glavna_traka[pozicija]=='0')&&(sporedna_traka[pozicija]=='0')) {
               stanje=9;
               glavna_traka[pozicija]='0';
               sporedna_traka[pozicija]='X';
               pozicija++;
               prijelaz=1;
               break;
               }
               if ((glavna_traka[pozicija]=='#')&&(sporedna_traka[pozicija]=='#')) {
               stanje=8;
               glavna_traka[pozicija]='#';
               sporedna_traka[pozicija]='#';
               pozicija--;
               prijelaz=1;
               break;
               }
               if ((glavna_traka[pozicija]=='0')&&(sporedna_traka[pozicija]=='X')) {
               stanje=8;
               glavna_traka[pozicija]='0';
               sporedna_traka[pozicija]='X';
               pozicija--;
               prijelaz=1;
               break;
               }
               if ((glavna_traka[pozicija]=='B')&&(sporedna_traka[pozicija]=='B')) {
               stanje=10;
               glavna_traka[pozicija]='B';
               sporedna_traka[pozicija]='B';
               pozicija++;
               prijelaz=1;
               break;
               }
               break;
               
               case 9:
               if ((glavna_traka[pozicija]=='0')&&(sporedna_traka[pozicija]=='0')) {
               stanje=8;
               glavna_traka[pozicija]='0';
               sporedna_traka[pozicija]='X';
               pozicija--;
               prijelaz=1;
               break;
               }
               if ((glavna_traka[pozicija]=='#')&&(sporedna_traka[pozicija]=='#')) {
               stanje=9;
               glavna_traka[pozicija]='#';
               sporedna_traka[pozicija]='#';
               pozicija++;
               prijelaz=1;
               break;
               }
               if ((glavna_traka[pozicija]=='0')&&(sporedna_traka[pozicija]=='X')) {
               stanje=9;
               glavna_traka[pozicija]='0';
               sporedna_traka[pozicija]='X';
               pozicija++;
               prijelaz=1;
               break;
               }
               if ((glavna_traka[pozicija]=='B')&&(sporedna_traka[pozicija]=='B')) {
               stanje=11;
               glavna_traka[pozicija]='B';
               sporedna_traka[pozicija]='B';
               pozicija--;
               prijelaz=1;
               break;
               }
               break;
               
               case 11:
               if ((glavna_traka[pozicija]=='0')&&(sporedna_traka[pozicija]=='X')) {
               stanje=12;
               glavna_traka[pozicija]='0';
               sporedna_traka[pozicija]='B';
               pozicija--;
               prijelaz=1;
               break;
               }
               break;
               
               case 12:
               if ((glavna_traka[pozicija]=='0')&&(sporedna_traka[pozicija]=='0')) {
               stanje=12;
               glavna_traka[pozicija]='0';
               sporedna_traka[pozicija]='0';
               pozicija--;
               prijelaz=1;
               break;
               }
               if ((glavna_traka[pozicija]=='0')&&(sporedna_traka[pozicija]=='X')) {
               stanje=12;
               glavna_traka[pozicija]='0';
               sporedna_traka[pozicija]='0';
               pozicija--;
               prijelaz=1;
               break;
               }
               if ((glavna_traka[pozicija]=='#')&&(sporedna_traka[pozicija]=='#')) {
               stanje=13;
               glavna_traka[pozicija]='#';
               sporedna_traka[pozicija]='0';
               pozicija--;
               prijelaz=1;
               break;
               }
               break;
               
               case 13:
               if ((glavna_traka[pozicija]=='0')&&(sporedna_traka[pozicija]=='0')) {
               stanje=13;
               glavna_traka[pozicija]='0';
               sporedna_traka[pozicija]='0';
               pozicija--;
               prijelaz=1;
               break;
               }
               if ((glavna_traka[pozicija]=='0')&&(sporedna_traka[pozicija]=='X')) {
               stanje=13;
               glavna_traka[pozicija]='0';
               sporedna_traka[pozicija]='0';
               pozicija--;
               prijelaz=1;
               break;
               }
               if ((glavna_traka[pozicija]=='#')&&(sporedna_traka[pozicija]=='#')) {
               stanje=16;
               glavna_traka[pozicija]='#';
               sporedna_traka[pozicija]='#';
               pozicija--;
               prijelaz=1;
               break;
               }
               break;
               
               case 14:
               if ((glavna_traka[pozicija]=='0')&&(sporedna_traka[pozicija]=='B')) {
               stanje=10;
               glavna_traka[pozicija]='0';
               sporedna_traka[pozicija]='B';
               pozicija--;
               prijelaz=1;
               break;
               }
               if ((glavna_traka[pozicija]=='#')&&(sporedna_traka[pozicija]=='0')) {
               stanje=15;
               glavna_traka[pozicija]='#';
               sporedna_traka[pozicija]='X';
               pozicija--;
               prijelaz=1;
               break;
               }
               if ((glavna_traka[pozicija]=='#')&&(sporedna_traka[pozicija]=='X')) {
               stanje=14;
               glavna_traka[pozicija]='#';
               sporedna_traka[pozicija]='X';
               pozicija++;
               prijelaz=1;
               break;
               }
               if ((glavna_traka[pozicija]=='#')&&(sporedna_traka[pozicija]=='#')) {
               stanje=14;
               glavna_traka[pozicija]='#';
               sporedna_traka[pozicija]='#';
               pozicija++;
               prijelaz=1;
               break;
               }
               if ((glavna_traka[pozicija]=='0')&&(sporedna_traka[pozicija]=='0')) {
               stanje=15;
               glavna_traka[pozicija]='0';
               sporedna_traka[pozicija]='X';
               pozicija--;
               prijelaz=1;
               break;
               }
               if ((glavna_traka[pozicija]=='0')&&(sporedna_traka[pozicija]=='X')) {
               stanje=14;
               glavna_traka[pozicija]='0';
               sporedna_traka[pozicija]='X';
               pozicija++;
               prijelaz=1;
               break;
               }
               break;
               
               case 15:
               if ((glavna_traka[pozicija]=='0')&&(sporedna_traka[pozicija]=='0')) {
               stanje=14;
               glavna_traka[pozicija]='0';
               sporedna_traka[pozicija]='X';
               pozicija++;
               prijelaz=1;
               break;
               }
               if ((glavna_traka[pozicija]=='#')&&(sporedna_traka[pozicija]=='#')) {
               stanje=15;
               glavna_traka[pozicija]='#';
               sporedna_traka[pozicija]='#';
               pozicija--;
               prijelaz=1;
               break;
               }
               if ((glavna_traka[pozicija]=='#')&&(sporedna_traka[pozicija]=='X')) {
               stanje=15;
               glavna_traka[pozicija]='#';
               sporedna_traka[pozicija]='X';
               pozicija--;
               prijelaz=1;
               break;
               }
               if ((glavna_traka[pozicija]=='0')&&(sporedna_traka[pozicija]=='X')) {
               stanje=15;
               glavna_traka[pozicija]='0';
               sporedna_traka[pozicija]='X';
               pozicija--;
               prijelaz=1;
               break;
               }
               if ((glavna_traka[pozicija]=='B')&&(sporedna_traka[pozicija]=='B')) {
               stanje=20;
               glavna_traka[pozicija]='B';
               sporedna_traka[pozicija]='B';
               pozicija++;
               prijelaz=1;
               break;
               }
               break;
               
               case 16:
               if ((glavna_traka[pozicija]=='0')&&(sporedna_traka[pozicija]=='X')) {
               stanje=16;
               glavna_traka[pozicija]='0';
               sporedna_traka[pozicija]='0';
               pozicija--;
               prijelaz=1;
               break;
               }
               if ((glavna_traka[pozicija]=='B')&&(sporedna_traka[pozicija]=='B')) {
               stanje=17;
               glavna_traka[pozicija]='B';
               sporedna_traka[pozicija]='B';
               pozicija++;
               prijelaz=1;
               break;
               }
               break;
               
               case 17:
               if ((glavna_traka[pozicija]=='0')&&(sporedna_traka[pozicija]=='0')) {
               stanje=17;
               glavna_traka[pozicija]='0';
               sporedna_traka[pozicija]='0';
               pozicija++;
               prijelaz=1;
               break;
               }
               if ((glavna_traka[pozicija]=='#')&&(sporedna_traka[pozicija]=='#')) {
               stanje=14;
               glavna_traka[pozicija]='#';
               sporedna_traka[pozicija]='#';
               pozicija++;
               prijelaz=1;
               break;
               }
               break;
               
               case 20:
               prihvatljivost=1;
               break;
    }
    for(i=0;i<n;i++) printf("%c", glavna_traka[i]);
    printf("\n");
    for(i=0;i<n;i++) printf("%c", sporedna_traka[i]);
    printf("\n\n");
    if (prijelaz==0) break;
}
    printf("\n\n");
    if (prihvatljivost==1) printf("stranice sa zadanim duljinama TVORE trokut!");
    else printf("stranice sa zadanim duljinama NE TVORE trokut");
    
    scanf("%%");
    return 0;
}
