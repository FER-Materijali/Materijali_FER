#include <stdio.h>
#define BRCLAN 5
 
void spojiNizove(char *A, char *B, char *Rez){
	int i=0, j=0, k=0;
	while (*(A+i)!='\0' && *(B+j)!='\0'){
		if(*(A+i)>*(B+j)){
			*(Rez+k)=*(A+i);
			i++;
			k++;
		} else {
			*(Rez+k)=*(B+j);
			j++;
			k++;
		}

		}
	if(*(B+j)=='\0')
		while(*(A+i)!='\0'){
			*(Rez+k)=*(A+i);
			k++;
			i++;
		}
	else if(*(A+i)=='\0')
		while(*(B+j)!='\0'){
			*(Rez+k)=*(B+j);
			k++;
			j++;
		}
	*(Rez+k)='\0';
}

int main(void){
	char A[BRCLAN+1]="ecaDB", B[BRCLAN+1]="dbECA", Rez[2*BRCLAN+1];
	spojiNizove(A, B, Rez);
	printf("%s", Rez);
	return 0;
}