typedef void (*SortPtr)(int* , int , int ); //pokazivac na sort funkciju


// -1 ako je greska
// 1 ako je uspjeh
int test_sort(SortPtr sptr, int kraj, int agreg, int start, int korak, int silazazno, const char* datoteka_u, const char* datoteka_i);

int test_permute(int kraj, int agreg, int start, int korak, int silazazno, const char* datoteka_u, const char* datoteka_i);
