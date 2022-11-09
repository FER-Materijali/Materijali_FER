#include <stdio.h>
#include <stdlib.h>
double f(double z, int k){
    double kvadPot=z*z*-1;
    if(k==0){
        return z;
    }
    else if(k>0){

        return (kvadPot)/((k+k+1)*(k+k)) * f(z,k-1);
    }


}
int main(void){
    int K;
    double Z,rj;
    printf("Upišite broj k a zatim broj z: ");
    scanf("%d %lf",&K,&Z);
    rj=f(Z,K);
    printf("%lf",rj);
    return 0;
}
