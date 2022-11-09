#include <iostream>
#include <string.h>
using namespace std;
struct osoba {
   int sifra;
   char prezime[20 + 1];
};
int cmpFloatDesc(const void *a, const void *b) {
   return *(float *)b - *(float *)a;
}
int cmpOsobaPrezime(const void *a, const void *b) {
   return strcmp(((osoba *)a)->prezime, ((osoba *)b)->prezime);
}
int main(void) {
   float a[5] = {1, 2, 3, 4, 5};
   osoba o[5] = {
       {1, "Peric"}, {2, "Anic"}, {3, "Horvat"}, {4, "Kovac"}, {5, "Babic"}};
   qsort(a, 5, sizeof(float), cmpFloatDesc);
   for (int i = 0; i < 5; i++)
      cout << a[i] << " ";
   cout << endl;
   qsort(o, 5, sizeof(osoba), cmpOsobaPrezime);
   for (int i = 0; i < 5; i++)
      cout << o[i].prezime << " ";
   cout << endl;
   return 0;
}