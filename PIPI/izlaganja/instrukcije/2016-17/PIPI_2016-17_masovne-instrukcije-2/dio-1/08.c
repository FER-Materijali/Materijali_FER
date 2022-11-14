#include <stdio.h>

int main (void) {
	char string[30];
	int slovo=0, broj=0, i=0;
	printf("unesi string\n");
	gets(string);

	while (string[i] != '\0') {
		if ((string[i] >= 'a') && (string[i] <= 'z')) slovo++;
		if ((string[i] >= '0') && (string[i] <= '9')) broj++;
		i++;
	}
	if ((slovo < 7) || (broj < 2)) printf("Ne zadovoljava uvjete\n");
	else printf("zadovoljava uvjete\n");
	return 0;
}