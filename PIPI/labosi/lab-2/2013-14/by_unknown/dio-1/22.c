#include<stdio.h>
#define MAX 999
#define MIN 100
							
int main(void){

			int p[3]={0}, n=0, i=0, br=0;;
			do{
				printf("Upisi broj iz intervala [100,999]:");
				scanf("%d", &n);
			}while((n<MIN) || (n>MAX));
			br=n;
			while(n!=0){
						p[i]=n%10;
						n/=10;
						i+=1;
			}
			n=(100*p[0])+(10*p[1])+p[2];
			if(br<n) printf("\nBroj %d je veci od ucitanog broja.", n);
			else if(br>n) printf("\nBroj %d je manji od ucitanog broja.", n);
			else printf("\nBroj %d je jednak ucitanom broju.", n);
			return 0;
}