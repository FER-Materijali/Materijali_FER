#include <stdio.h>
void bubble_sort_rek(int *niz, int n, int uzlazno){
	int i, bila_zamjena, pom;
	if(uzlazno){
		bila_zamjena=0;
		for(i=0;i<n-1;i++){
			if(niz[i]>niz[i+1]){
				pom=niz[i];
				niz[i]=niz[i+1];
				niz[i+1]=pom;
				bila_zamjena=1;
			}
		}
	}
	else{
		bila_zamjena=0;
		for(i=0;i<n-1;i++){
			if(niz[i]<niz[i+1]){
				pom=niz[i];
				niz[i]=niz[i+1];
				niz[i+1]=pom;
				bila_zamjena=1;
			}
		}
	}
	if(bila_zamjena)
		bubble_sort_rek(niz, n-1, uzlazno);
}

int main(){
	int polje[10]={1,4,0,3,2,9,5,6,7,8}, n=10, i;
	printf("Pocetni niz\n");
	for(i=0;i<n;i++){
		printf("%d ",polje[i]);
	}
	printf("\n\nUnesite 1 za uzlazno, 0 za silazno sortiranje: ");
	scanf("%d",&i);
	bubble_sort_rek(polje,n,i);
	printf("\nBubble sort rekurzivno\n");
	for(i=0;i<n;i++){
		printf("%d ",polje[i]);
	}
	return 0;
}
