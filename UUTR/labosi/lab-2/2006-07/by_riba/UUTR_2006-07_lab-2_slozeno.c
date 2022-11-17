#include <stdio.h>
#include <string.h>

FILE *d;
int p, lj;
int table[4][6] = {0,1,2,3,1,2,
                   1,2,0,1,2,3,
                   2,3,1,2,0,1,
                   0,1,2,3,1,2};

void Rekurz(int _stanje, char _stog[], int _pokaz){
 char pi = fgetc(d), stog[20]; int i, PozUDat, K;
 PozUDat = ftell(d);

 printf("------\nUcitani znak: \\'%c\\'\nStanje: Q%d\nStog prije: ", pi, _stanje);
 for (i=0; i<_pokaz +1; i++) stog[i] = _stog[i];
 for (i=0; i<_pokaz +1; i++) printf("%c", stog[i]);
 printf("\n");

 if(pi == \\' \\' && _pokaz == 0) {
   printf("Prijelaz: d(Q%d, \\'X\\', \\'e\\') = {(Q%d, \\'e\\')}\n", _stanje, _stanje);
   printf("Stog poslije: \nStanje poslije: Q%d\n", _stanje);
   if (_stanje != 1) printf("NE");
   printf("PRIHVATLJIVI NIZ!\n\n");
  p=1; lj = ftell(d);}
 if(pi == \\' \\' && _pokaz != 0 && p!=1) {
   printf("Prijelaz: d(Q%d, \\'X\\', \\'e\\') = {(Q%d, \\'e\\')}\n", _stanje, _stanje);
   printf("Stog poslije: ");
   for (i=0; i<_pokaz+1; i++) printf("%c", stog[i]);
   printf("\nStanje poslje: Q%d\n", _stanje);
   printf("\nNEPRIHVATLJIVI NIZ!\n\n");
   lj = ftell(d); p=2;
 }

 if (pi != \\' \\' && (pi==\\' \\' || pi==\\' \\' || pi==\\' \\' || pi==\\' \\') && p!=1 && p!=2) {

   if ((stog[_pokaz]) == pi - \\'0\\' + \\'A\\') {
   K = (table[_stanje / 2][(pi - \\'0\\') % 6])*2;
   printf("Prijelaz: d(Q%d, \\'%c\\', \\'%c\\') = {(Q%d, \\'e\\')}\n", _stanje, pi, stog[_pokaz], K+1);
   printf("Stanje poslije: Q%d\n", K+1);
   printf("Stog poslije: ");
   for (i=0; i<_pokaz; i++) printf("%c", stog[i]);
   printf("\n");
   Rekurz(K+1, stog, _pokaz-1);
 }

 fseek(d, PozUDat, SEEK_SET);

 if ((_stanje % 2) == 0 && p!=1 && p!=2) {
     K = (table[_stanje / 2][(pi - \\'0\\') % 6])*2;
     printf("Prijelaz: d(Q%d, \\'%c\\', \\'%c\\') = {(Q%d, \\'%c%c\\')}\n", _stanje, pi, stog[_pokaz], K,stog[_pokaz],pi - \\'0\\' + \\'A\\');
     printf("Stanje poslije: Q%d\n", K);
     printf("Stog poslije: ");
     stog[_pokaz+1] = pi - \\'0\\' + \\'A\\';
     for (i=0; i<_pokaz+2; i++) printf("%c", stog[i]);
     printf("\n");
     Rekurz(K, stog, _pokaz+1);
     }
}

else if (pi != \\' \\' && p!=1 && p!=2) {
  K = (table[_stanje / 2][(pi - \\'0\\') % 6])*2;
  printf("Prijelaz: d(Q%d, \\'%c\\', \\'%c\\') = {(Q%d, \\'%c\\')}\n", _stanje , pi, stog[_pokaz], K+ (_stanje % 2),stog[_pokaz]);
  printf("Stanje poslije: Q%d\n", K + (_stanje % 2));
  printf("Stog poslije: ");
  for (i=0; i<_pokaz+1; i++) printf("%c", stog[i]);
  printf("\n");
  Rekurz(K + (_stanje % 2), stog, _pokaz);
}



}

int main()
{
  char stog[20];
  int i;
  d = fopen("NDPA.txt", "r");
  for (i=0; i<26; i++) stog[i] = \\' \\';
  stog[0] = \\'X\\';
  while (fgetc(d) != EOF) {
    lj=0;
    printf("\n\n\nNIZ:\n\n\n");
    p=0;
    fseek(d, -1, SEEK_CUR);
    Rekurz(0, stog, 0);
    fseek(d, lj, SEEK_SET);
  }
  system("PAUSE");
  return 0;
}