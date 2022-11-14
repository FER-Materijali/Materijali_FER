#include<stdio.h>
#define MAX 99999
#define MIN 100
							
int main(void){

			int i=0, z=0, n=0;
			do{
				printf("Upisi broj iz intervala [100,99999]:");
				scanf("%d", &n);
			}while((n<MIN) || (n>MAX));
			printf("\nU broju %d najveca znamenka je: ", n);
			z=n%10;
			while(n!=0){
						i=n%10;
						if(i>z) z=i;
						n/=10;
			}
			printf("%d", z);
			return 0;
}