#include <stdio.h>

#define MAXSTOG1 10 // maksimalna velicina stoga
#define MAXSTOG2 10 // maksimalna velicina stoga
#define ISTO 1

int stavi (int stavka, int stog[], int n, int *vrh) {
  if (*vrh >= n-1) return 0;
  (*vrh)++;		
  stog[*vrh] = stavka;
  return 1;
}
int skini (int *stavka, int Stog[], int *vrh) {
  if (*vrh < 0) return 0; // stog je prazan
  *stavka = Stog[*vrh];
  (*vrh)--;
  return 1;
}
void premjesti(int stog1[],int n1,int *vrh1,int stog2[],int n2, int *vrh2 ) {
  int element;
  if (skini(&element,stog1, vrh1)) {
#if ISTO
    premjesti (stog1,n1,vrh1, stog2,n2,vrh2);
    stavi(element,stog2,n2,vrh2);
#else
    stavi(element,stog2,n2,vrh2);
    premjesti (stog1,n1,vrh1, stog2,n2,vrh2);
#endif
  }
}

int main(){
  int stog1[MAXSTOG1];
  int stog2[MAXSTOG2];
  int vrh1=-1, vrh2=-1;
  int i;
  for (i=0; i<10; i++) stavi(i,stog1,MAXSTOG1, &vrh1);
  printf ("\nPrvi stog\n");
  for (i=0; i<=vrh1;i++) printf("%d\n", stog1[i]); 

  premjesti(stog1, MAXSTOG1, &vrh1, stog2, MAXSTOG2, &vrh2);

  printf ("\nDrugi stog nakon premijestanja\n");
  for (i=0; i<=vrh2;i++) printf("%d\n", stog2[i]); 
  return 0;}
