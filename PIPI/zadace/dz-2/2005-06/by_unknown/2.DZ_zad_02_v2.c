#include <stdio.h>

int main (){
	int n, i, pom[26];
	char c[20];

	do{
		printf("Unesi n: ");
		scanf("%d", &n);
	}while(n<1 || n>20);
	
	for (i=0;i<n;++i){
		do{
            printf("\nUnesi %2d. znak: ", i+1);
			c[i]=getche();
		}while(c[i]<'a' || c[i]>'z');
		pom[(int)c[i]-97] = 1;
	}
	
	printf("\n\n");
	printf("Slova engleske abecede koja nedostaju:\n");
	
	for(i=0;i<26;++i){
		if(pom[i]==1) continue;
		else printf(" %c", i+97);        //ILI   else putch(i+97);
	}
	
	printf("\n\n");
	return 0;
}



