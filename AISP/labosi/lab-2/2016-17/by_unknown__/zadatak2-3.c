#include <stdio.h>
#include <malloc.h>

struct zapis{
	int sifra;
	char naziv[50+1];
};

void zamjeni(struct zapis *a, struct zapis *b){
	struct zapis pom = *a;
	*a = *b;
	*b = pom;
}

void obicanBubbleSort(struct zapis *A, int n, char smjer){
	int i, j;
	if (smjer == '0'){
		for(i=0;i<n-1;i++)
			for(j=0;j<n-i-1;j++)
				if((A+j+1)->sifra < (A+j)->sifra) zamjeni(A+j+1, A+j);
	} else {
		for(i=0;i<n-1;i++)
			for(j=0;j<n-i-1;j++)
				if((A+j+1)->sifra > (A+j)->sifra) zamjeni(A+j+1, A+j);
	}
}

int main(void){
	struct zapis *polje;
	int	i, n;
	char smjer;
	printf("Unesite broj jela koja zelite sortirati (najvise 10) > ");
	do{
		scanf("%d", &n);
	}while(n>10);
	polje = malloc(n*sizeof(struct zapis));
	printf("\nUnesite zapise u obliku: sifra naziv > ");
	for(i=0;i<n;i++)
		scanf("%d %[^\n]", &(polje+i)->sifra, (polje+i)->naziv);
	printf("\nUnesite smjer sortiranja: 0 - uzlazno, 1 - silazno > ");
	scanf(" %c", &smjer);
	obicanBubbleSort(polje, n, smjer);
	printf("\nSortirano polje:\n");
	for(i=0;i<n;i++)
		printf("%d %s\n", (polje+i)->sifra, (polje+i)->naziv);
	free(polje);
	return 0;
}