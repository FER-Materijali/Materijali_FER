#include<stdio.h>
#define MAX 99999
#define MIN 1
							
int main(void){

			int p=0, z=0, n=0;
			do{
				printf("Upisi broj iz intervala [1,99999]:");
				scanf("%d", &n);
			}while((n<MIN) || (n>MAX));
			printf("\nBroj %d: ", n);
			z=n%10;
			while(n!=0){
						p=n%10;
						n/=10;
			}
			if(p>z) printf("prva znamenka veca od zadnje");
			else if(p==z) printf("prva i zadnja znamenka su jednake");
			else printf("prva znamenka manja od zadnje");
			return 0;
}