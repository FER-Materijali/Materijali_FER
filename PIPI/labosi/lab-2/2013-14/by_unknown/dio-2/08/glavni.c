#include"funkcije.h"
#include<stdio.h>
#include<string.h>
#define MAX 200

int main(void){

			int nn=0, ni=0, brl=0, brd=0;
			char niz[MAX+1], lijevi='\0', desni='\0', p='\0';
			memset(niz, '\0', MAX);
			printf("Upisi niz:");
			gets(niz);
			while(1){
					printf("\nUpisi lijevi i desni granicnik:");
					scanf("%c%c%c", &lijevi, &desni, &p);
					if((lijevi=='\\') || (desni=='\\')) break;
					brLijevihiDesnihGranicnika(niz, lijevi, desni, &brl, &brd);
					if(izrazJeIspravan(brl, brd)==1){
													ni+=1;
													printf("\nIzraz %s JE ispravan s obzirom na granicnike %c %c.", niz, lijevi, desni);
					}else{
						nn+=1;
						printf("\nIzraz %s NIJE ispravan s obzirom na granicnike %c %c.", niz, lijevi, desni);
					}
			}
			if(nn==0) printf("\nIzraz %s je potpuno ispravan.", niz);
			else if(ni==0) printf("\nIzraz %s je potpuno neispravan.", niz);
			else printf("\nIzraz %s je djelomicno ispravan: ispravan obzirom na %d granicnik(a); neispravan obzirom na %d granicnik(a).", niz, ni, nn);
			return 0;
}