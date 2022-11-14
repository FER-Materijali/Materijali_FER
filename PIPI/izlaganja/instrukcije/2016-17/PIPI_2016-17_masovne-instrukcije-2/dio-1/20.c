#include <stdio.h>

int main(void) {
	int broj, lenBroja;
	int polje[4], i, broj_tmp;
	do {
		printf("unesi broj iz intervala [1, 99999]: \n");
		scanf("%d", &broj);
	} while ((broj < 1) || (broj > 99999));
	/*broj_tmp je varijabla za usporedbu na kraju */
	broj_tmp = broj;
	/*prepiši broj u polje */

	for (i = 0; i <5; i++) {
		if (broj==0) break;
		polje[i] = broj%10;
		broj/=10;
	}
	
	lenBroja=i;
	
	/*broj je u memoriju zapisan naopako*/
	
	if (polje[0] < polje[lenBroja-1]) {
		printf("Broj %d: prva znamenka veća od zadnje\n", broj_tmp);
		return 0;
	}
	if (polje[0] > polje[lenBroja-1]) {
		printf("Broj %d: prva znamenka manja od zadnje\n", broj_tmp);
		return 0;
	} else {
		printf("Broj %d: prva znamenka jednaka kao zadnja\n", broj_tmp);
	}
 	return 0;
}