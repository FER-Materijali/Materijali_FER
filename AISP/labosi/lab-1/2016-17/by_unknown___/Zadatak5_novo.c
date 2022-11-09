#include <stdio.h>
#include <stdlib.h>
int binarnoTrazi(float *polje, int velicina,float x){
    int donjagranica=0,gornjagranica=velicina-1,sredina;

    while(donjagranica < gornjagranica){
        sredina=(gornjagranica+donjagranica)/2;
        if(*(polje + sredina) >= x)
            gornjagranica=sredina;
        else
            donjagranica=sredina+1;
    }
    if(*(polje + donjagranica)==x)
        return donjagranica;
    return -1;

}



int main(void){
    int n,i,rjesenje;
    float *A,x;
    printf("Unesite veličinu polja: ");
    scanf("%d",&n);
    printf("Koji broj tražite u polju?");
    scanf("%f",&x);
    A=malloc(n * sizeof(float));
    for(i=0;i<n;++i){
        A[i]=i*1.1;
        printf("%f ",A[i]);
    }
    rjesenje=binarnoTrazi(A,n,x);
    if(rjesenje!=-1)
        printf("\nTraženi element nalazi se na indeksu: %d",rjesenje);
    else
        printf("Broj se ne nalazi u polju");
    free(A);

    return 0;
}
