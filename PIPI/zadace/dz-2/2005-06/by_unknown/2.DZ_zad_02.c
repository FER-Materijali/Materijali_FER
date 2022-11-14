#include <stdio.h>

int main (){
	int n, i;
	char c[20], z[26];          

	do{
		printf("Unesi n: ");
		scanf("%d", &n);
	}while(n<1 || n>20);
	
	for (i=0;i<n;++i){
		do{
            printf("\nUnesi %d. znak: ", i+1);
			c[i]=getche();
		}while(c[i]<'a' || c[i]>'z');
		z[c[i]-'a'] = 1;
	}
	
	printf("\n\n");
	printf("Slova engleske abecede koja nedostaju:\n");
	
	for(i=0;i<26;++i){
		if(z[i]==1) continue;
		else printf(" %c", i+97);
	}
	
	printf("\n\n");
	return 0;
}



