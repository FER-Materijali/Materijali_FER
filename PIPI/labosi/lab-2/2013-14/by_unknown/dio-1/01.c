#include<stdio.h>
#define MAX 20
#define MIN 5

int main(void){

			int x=0, i=0, j=0;
			float p[MAX+1]={0}, br=0;
			printf("Upisi cijeli broj iz intervala[5,20]:");
			scanf("%d", &x);
			if((x<MIN) || (x>MAX)){
								printf("\nNeispravan broj.");
								return 0;
			}
			for(i=1;i<=MAX;++i){
								p[i]=br+0.1f;
								br=br+0.1f;
			}
			for(i=0;i<=x;++i){
				for(j=0;j<=i;++j){
								printf("%.1f ", p[j]);
								}
			printf("\n");
			}
			return 0;
}