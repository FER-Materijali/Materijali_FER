#include<stdio.h>
#include<stdlib.h>
#include<time.h>
char generirajZnak(int znak){
	switch(znak){
		case 1:
			srand((unsigned)rand());
			znak=rand()%52;
			if(znak>25)
				znak=znak-26+'A';
			else
				znak+='a';
			break;
		case 2:
			srand((unsigned)rand());
			znak=rand()%10+'0';
			break;
		case 3:
			srand((unsigned)rand());
			znak=rand()%3;		
			switch(znak){
				case 0:
					znak='/';
					break;
				case 1:
					znak='?';
					break;
				case 2:
					znak='!';
					break;
		}
	}
	return znak;
}
void generirajLozinku(int ns, int nb, int nz, char izl[]){
	int j,i;
	i=ns+nb+nz;
	for (j=0;j<ns;j++){
	
		izl[getIndex(i,izl)]=generirajZnak(1);
	
	}
	for (j=0;j<nb;j++){
		
		izl[getIndex(i,izl)]=generirajZnak(2);
		
	}
	for (j=0;j<nz;j++){
		
		izl[getIndex(i,izl)]=generirajZnak(3);
		
	}
	puts(izl);
}
int getIndex(int i, char izl[]){
	int index=0;
	srand((unsigned)time(NULL));
	do{
		index=rand()%i;
	}while(*(izl+index)!=0);
	return index;
}