#include <stdio.h>
#include <math.h>

int main(){
	int n, a, b, y, br=0, i=1;
	int k=0;

	printf("Unesi broj n: ");
	scanf("%d", &n);
	printf("Unesi koje znamenke treba izbaciti iz broja n: ");
	scanf("%d %d", &a, &b);

    y = n;
	if(a!=0 && b!=0){
		if (a<b) b--;
		else a--;
	}

	while(n>0){
		if((i==a) || (i==b)) n/=10;
		br += n%10*(int)(pow(10,(i-1)));
		i++;
		n/=10;
	}
	printf("\n\nKada broju %d izbacimo %d. i %d. znamenku dobijemo broj: %d\n\n", y, a, b, br);
	return 0;
}


