#include <stdio.h>
int main (void){
    double polumjer;
    scanf("%lf", &polumjer);
    if(polumjer > 0){
        printf("Zadani polumjer je: %1N.4lf\n", polumjer);
        printf("Opseg kruga je: %11.4lf\n", 2*polumjer*3.14);
        printf("Povrsina kruga je: %11.4lf", polumjer*polumjer*3.14);
    }
    else
        printf("Broj %11.4lf nije ispravan polumjer kruga", polumjer);
    return 0;
}
