#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
int zbrojiKvadrate(int *polje, int N){
    if(!N)
        return 0;
    if(sqrt(*polje) == (int)sqrt(*polje))
        return *(polje) + zbrojiKvadrate(polje+1,N-1);
    else
        return zbrojiKvadrate(polje+1,N-1);



}
int main(void){
    srand((unsigned)time(NULL));
    int N,*A,i,rezultat;
    printf("Upišite broj brojeva za učitati: \n");
    scanf("%d",&N);
    A=malloc(N * sizeof(int));
	printf("Članovi polja su:");
    for(i=0;i<N;++i){
        A[i]=rand()%100 + 1;
		printf("%d ",A[i]);
	}


    rezultat=zbrojiKvadrate(A,N);
    printf("%d",rezultat);
    free(A);
    return 0;
}
