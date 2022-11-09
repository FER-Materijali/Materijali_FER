#include <stdio.h>
#include <stdlib.h>

double expo(double x,int n, int *fakt, double *xpot){
    if(n==0)
        return 1;
    else{
        return expo(x,n-1,fakt,xpot) + (*(xpot+n))/(*(fakt+n));

    }



}
int main(void){
    int N,i,*faktorijeli;
    double X;
    double *potencije;
    float *A;
    printf("Unesite veličinu polja: ");
    scanf("%d",&N);

    A = malloc(N * sizeof(float));
    printf("Unesite broj x: ");
    scanf("%lf",&X);

    faktorijeli = malloc(N * sizeof(int));
    faktorijeli[0]=1;
    faktorijeli[1]=1;

    potencije = malloc(N * sizeof(double));
    potencije[0]=1;
    potencije[1]=X;

    for(i=2;i<N;++i){
        potencije[i]= potencije[i-1] * potencije[1];
        faktorijeli[i]=i*faktorijeli[i-1];
    }
    for(i=0;i<N;++i){
        A[i]=expo(X,i,faktorijeli,potencije);
        printf("%f ",A[i]);
    }
    free(A);
    free(faktorijeli);
    free(potencije);
    return 0;
}
