#include <stdio.h>
int BinarnoTrazi(int *polje, int n, int x) {
	int DonjaGranica = 0;
	int GornjaGranica = n - 1;
	int median = GornjaGranica / 2;
	do {
		if (x > *(polje + median)) {
			DonjaGranica = median;
			median = DonjaGranica + (GornjaGranica - DonjaGranica) / 2;
		}
		else if (x < *(polje + median)) {
			GornjaGranica = median;
			median = DonjaGranica + (GornjaGranica - DonjaGranica) / 2;
		}
		else return median;
	} 
	while (DonjaGranica != GornjaGranica);
	return -1;
}
int main(void) {
	int x = 4, A[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 }, n;
	n = BinarnoTrazi(A, sizeof(A) / sizeof(int), x);
	if (n == -1) printf("Trazeni broj se ne nalazi u polju\n");
	else printf("Index clana polja trazenog elementa = %d\n", n);
	return 0;
}