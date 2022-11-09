#include <sys\timeb.h> // gdje je deklarirano
#include <stdio.h>


int main() {
	struct timeb vrijeme1, vrijeme2; 
	long trajanjems;
	
	unsigned long long int i, n = 100;
	
	ftime (&vrijeme1);
	
	for(i = 0; i < n*n*n; ++i) printf(" ");

	ftime (&vrijeme2);

	trajanjems = 1000 * (vrijeme2.time - vrijeme1.time) + vrijeme2.millitm - vrijeme1.millitm;
	
	printf("\nVrijeme: %ld ms\n", trajanjems);
	return 0;
}
