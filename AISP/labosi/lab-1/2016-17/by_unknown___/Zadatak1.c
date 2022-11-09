#include <stdio.h>
#include <stdlib.h>
void ispis(float *polje, int n){
    if(n>0){
        ispis(polje,n-1);
        if(*(polje+n-1)<0)
            printf("%f ",*(polje + n -1));
    }
    else if(n==0){
        if((*polje)<0)
            printf("%.2f ",*(polje + n -1));
        return;
    }
}
int main(void){
    int n,i;
    float *A;
    printf("Unesite veličinu polja: ");
    scanf("%d",&n);
    A=malloc(n*sizeof(float));
    if(A==NULL)
        printf("Nema dovoljno memorije");

    else{
        for(i=0;i<n;++i)
        scanf("%f",A+i);
        ispis(A,n);
    }
    free(A);
    return 0;

}
