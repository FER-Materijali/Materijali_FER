#include <stdio.h>
void f(int **ppa, int *novaAdresa){
	*ppa = novaAdresa;
}
int main(){
	int a=1, b=2;
	int *pa; 
	pa = &a;
	printf("\n &pa=%p pa=%p *pa=%d", &pa, pa, *pa);
	f(&pa, &b);
	printf("\n &pa=%p pa=%p *pa=%d\n", &pa, pa, *pa);
	return 0;
}
