#include <stdio.h>
#define MAX 50

int main(){
	int n, i, br_sug=0;
	char c;

	printf("Unesi n iz intervala [20,50]: ");
	scanf("%d", &n);

	if(n<20 || n>50) return 0;

	for(i=0;i<n;++i){
		printf("\nUnesi %2d. znak: ", i+1);
		c = getche();
		if((c>='a' && c<='z') || (c>='A' && c<='Z')){
			if(c<='Z') c+=32;
			switch (c){
				case 'a':
				case 'e':
				case 'i':
				case 'o':
				case 'u': break;
				default: ++br_sug; break;
			}
		}
	}
	printf("\n\nMedu ucitanim znakovima ima %d suglasnika.\n", br_sug);
	return 0;
}
