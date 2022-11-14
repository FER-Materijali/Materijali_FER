#include <stdio.h>

int main (void){
	char niz1[100], niz2[100];
	int i=0;
	gets(niz1);	
	gets(niz2);
	while(niz1[i]!='\0'){
	    if((niz1[i]>='a' && niz1[i]<='z') || (niz1[i]>='A' && niz1[i]<='Z'))
	    	if(toupper(niz1[i])==toupper(niz2[i]))
		    	printf("pozicija %d - slova: %c, %c\n", i+1, niz1[i], niz2[i]);
		++i;
	}
	return 0;
}