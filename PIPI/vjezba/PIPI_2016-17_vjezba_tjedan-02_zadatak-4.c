#include <stdio.h>
int main (void) {
    double A,B;
    printf("Upisite dividend i divizor: ");
    scanf("%lf%lf",&A,&B);
    printf("\n");
    if(B==0)
        printf("Rezultat operacije nije definiran");
    else
        printf("Rezultat dijeljenja je %.4lf", A/B);

    return 0;
}
