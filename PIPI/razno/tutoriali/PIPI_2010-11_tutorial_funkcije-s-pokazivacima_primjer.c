#include<stdio.h>
#include<stdlib.h>

int f(int x, int y, int *z){
    int s;
    s=x+y;   
    *z=(x)*(y);    
return s;
}

main(){
       int a, b, sum, um;
       
       printf("\nUpisi 2 broja: \n");
       scanf("%d %d", &a, &b);
       sum=f(a, b, &um);
       printf("\nSuma je %d, a umnozak %d", sum, um);
        
printf("\n");       
system("pause");
return 0;
}
