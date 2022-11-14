#include <stdio.h>

int main (void){
	char niz[9+1], znak;
	int duljina, broj=1;
	gets(niz);
	duljina=strlen(niz);
	for(i=0; i<duljina; ++i){
		if(niz[i]>='0' && niz[i]<='9'){
			broj=broj*10+(niz[i]-'0');
			continue;
		}
		else{
			nije=1;
			break;
		}
	}
	if(nije==0)
		printf("%d, %.2f", broj, sqrt(broj));
	else
		printf("dopustene samo dekadske znamenke");
	return 0;
}