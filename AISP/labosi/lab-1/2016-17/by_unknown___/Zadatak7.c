#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int *nasumicniKvadrati(int *A,int N){
    int i,pomocna,*novopolje;
    novopolje = malloc(N* sizeof(int));
    for(i=0;i<N;++i){
        pomocna=*(A+rand()%N);
        *(novopolje + i)=pomocna*pomocna;
    }
    return novopolje;
}
int main(void){
    srand((unsigned)time(NULL));
    int *rezultat,i,n,*brojke;
    printf("Unesite veličinu polja:");
    scanf("%d",&n);

    brojke=malloc(n*sizeof(int));
    for(i=0;i<n;++i)
        scanf("%d",brojke +i);

    rezultat=nasumicniKvadrati(brojke,n);

    for(i=0;i<n;++i)
        printf("%d ",*(rezultat+i));


    return 0;
}
