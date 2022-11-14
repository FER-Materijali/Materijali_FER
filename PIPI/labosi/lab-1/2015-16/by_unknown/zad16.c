#include <stdio.h>
int main(void) {
	int m,s;
	printf("Unesite minute i sekunde: ");
	scanf("%d %d", &m, &s);
	if (s>=60)
		printf("Neispravan broj sekundi");
	else {
		float h=((float)(m*60 + s)/3600);
		printf("Sekunde %d ; sati %.3f", (m*60 + s), h);
	}
	return 0;
}
	