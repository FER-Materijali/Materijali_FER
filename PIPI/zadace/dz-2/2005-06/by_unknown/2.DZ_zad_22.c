#include <stdio.h>
#define MAX 1000

int main(){
	int a,b, uvjet=0, i, k;
	int mat1[MAX], mat2[MAX];

	do{
		printf("Unesi duljinu prvog polja u intervalu [1,1000]: ");
		scanf("%d", &a);
		printf("\nUnesi duljinu drugog polja u intervalu [1,1000]: ");
		scanf("%d", &b);
	}while(a<1 || a>1000 || b<1 || b>1000);

	for(i=0;i<a;++i){
		printf("\nUnesi %2d. element prvog polja: ", i+1);
		mat1[i]=getche();
	}
	for(i=0;i<b;++i){
		printf("\nUnesi %2d. element drugog polja: ", i+1);
		mat2[i]=getche();
		for(k=0;k<a;++k){
			if(mat2[i]==mat1[k]) uvjet=1;
		}
	}

	if(uvjet)printf("\n\nPolja imaju zajednickih elemenata.\n\n");
	else printf("\n\nPolja nemaju zajednickih elemanta.\n\n");

	return 0;
}



