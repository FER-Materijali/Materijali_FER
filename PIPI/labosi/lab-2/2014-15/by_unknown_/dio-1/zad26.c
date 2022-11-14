#include<stdio.h>
int main(void){
	int broj1, broj2, manji;
	manji=0;
	printf("Upisi dva prirodna broja:");
	scanf("%d %d", &broj1, &broj2);
	if ((broj1%2==0) && (broj2%2==0)){
		if (broj1<broj2)
			manji = broj1;
		else
			manji = broj2;
	}
	else if ((broj1%2==0) && (broj2%2!=0))
		manji = broj1;
	else if ((broj1%2!=0) && (broj2%2==0))
		manji = broj2;
	else
		manji = 0;
	if (manji==0)
		printf("Niti jedan broj nije paran.");
	else 
		printf("Manji parni broj je: %d.", manji);
		
	return 0;
}