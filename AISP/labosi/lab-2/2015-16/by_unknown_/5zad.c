#include<stdio.h>
#include<malloc.h>
void spojiNizove(char *A, char *B, char *Rez){
	int i, j;
	for (i = 0, j = 0; A[i] != 0 || B[j] != 0;){
		if (A[i] == 0) Rez[i + j] = B[j++];
		else if (B[j] == 0) Rez[i + j] = A[i++];
		else if (A[i] < B[j]) Rez[i + j] = A[i++];
		else Rez[i + j] = B[j++];
	}
	Rez[i + j] = 0;
}
int main(void){
	int i;
	char A[] = { 'B', 'D', 'a', 'c', 'e', 0};
	char B[] = { 'A', 'C', 'E', 'b', 'd', 0};
	char *R;
	R = (char*)malloc(5 + 5 + 1);
	spojiNizove(A,B,R);
	printf("Spojeni nizovi: \n");
	/*for (i = 0; i <10; i++){
		printf("%c", R[i]);
	}*/
	printf("%s", R);
	return 0;
}