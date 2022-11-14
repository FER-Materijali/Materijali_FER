#include <stdio.h>
int main(void){
    int x;
    scanf("%d",&x);
    printf("Ucitan je broj %5d\n", x);
    if(x<0)
        printf("Broj je negativan\n");
    if(x%2==0)
        printf("Broj je paran\n");
    else
        printf("Broj je neparan\n");
    return 0;

}
