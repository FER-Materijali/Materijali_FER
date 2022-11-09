#include <stdio.h>
#include <math.h>
#include <malloc.h>
void f(int *polje, int n) {
	if (n > 0) {
		*(polje + n - 1) = pow(2, n - 1);
		f(polje, n - 1);
	}
	return;

}
int main(void) {
	int n, i;
	int *polje;
	printf ("Unesite velicinu polja:\n");
	scanf ("%d", &n);
	polje = (int*)malloc(n * sizeof(int));
	f(polje, n);
	for (i = 0; i < n; i++) printf("%d ", *(polje + i));
	return 0;
}