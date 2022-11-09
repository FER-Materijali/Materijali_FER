#include <stdio.h>
#include <stdlib.h>

double pi(int n){
    if(n==-1)
        return 0;
    if(n%2==0)
        return 4*1./(1+n*2) + pi(n-1);
    else
        return 4*-1./(1+n*2) + pi(n-1);

}
int main(void){
    float *A;
    int N,i;
    printf("Upišite broj izračunavanja reda: ");
    scanf("%d",&N);
    A=malloc(N * sizeof(float));
    for(i=0;i<N;++i){
        A[i]=pi(i);
        printf("%f\n",A[i]);
    }
    free(A);
    return 0;
}
