#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void napuni(int *polje,int g,int d,int n)
{
	int i;
	srand(time(NULL));
	for(i=0;i<n;i++)
		polje[i]=(rand()%(g-d+1))+d;
	return;
}
int *novo(int *stari,int *novi,int n,int *m)
{
	int i,k=0;
	for(i=0;i<n;i++)
	if(!(stari[i]%2))
	{
		novi=(int*)realloc(novi,(k+1)*sizeof(int));
		novi[k]=stari[i];
		k++;
	}
    *m=k;
	return novi;
}
void ispis(int *niz,int n)
{
	int i;
	for(i=0;i<n;i++)
		printf("%d ",niz[i]);
	printf("n=%d\n",n);
	return;
}
	
int main()
{
	int *niz=NULL,*novi=NULL,n,m,g,d,i;
	printf("Unesi broj elemenata ");
	scanf("%d",&n);
		niz=(int*)malloc(n*sizeof(int));
	printf("Unesi gornju i donju granicu ");
	scanf("%d %d",&g,&d);
		napuni(niz,g,d,n);
	novi=novo(niz,novi,n,&m);
	printf("STARI: ");
		ispis(niz,n);
	printf("NOVI: ");
		ispis(novi,m);
	
	return 0;
	}