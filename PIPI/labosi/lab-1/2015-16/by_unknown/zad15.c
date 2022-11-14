#include <stdio.h>
int main(void) {
	int a;
	printf("Unesite vrijeme u sekundama\n");
	scanf("%d", &a);
	if (a<60)
		printf("sekunde: %d = sati-minute-sekunde 0-0-%d", a, a);
	if (a<3600 && a>=60)
		printf("sekunde: %d = sati-minute-sekunde 0-%d-%d", a, a/60, (a-(a/60)*60));
	if (a>=3600)
		printf("sekunde: %d = sati-minute-sekunde %d-%d-%d", a, a/3600, (a/60)%60, a%60);
	return 0;
}

	