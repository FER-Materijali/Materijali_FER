#include"funkcije.h"
#include<stdio.h>
#include<string.h>
#define MAX 200

int main(void){
			
			char niz[MAX+1]={0};
			int i=0, br=0, j=0, p=0, l=0;
			printf("Upisi niz:");
			gets(niz);
			l=strlen(niz);
			for(i=0;i<=l;i++){
							printf("%c", niz[i]);
							if((niz[i]=='\0') || (niz[i]==' ')){
																br=sazetak(&niz[p]);
																dodajZnak(&niz[i], br);
																printf("%d ", br);
																for(j=p;j<=i;j++) printf("%c", niz[j]);
																p=i+1;
																printf("\n");
							}
			}
			return 0;
}