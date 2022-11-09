#include <stdio.h>
#include <stdlib.h>
#include <math.h>
void f(int *polje,int N,int M){
        if(N==0){
            *(polje + N)=pow(M,N);
            return;
        }
        else{
            *(polje + N)=pow(M,N);
            return f(polje,N-1,M);
        }

}
int main(void){
    int n,m,*A,i=0;
    printf("Unesite veličinu polja: ");
    scanf("%d",&n);
    printf("Unesite broj");
    scanf("%d",&m);
    A=malloc(n * sizeof(int));

    f(A,n-1,m);
    for(i=0;i<n;++i){
        printf("%d ",*(A+i));
    }
    return 0;
}
