#include"funkcije.h"
#include<stdio.h>
#include<string.h>

void brLijevihiDesnihGranicnika(char *znNiz, char lijevi, char desni, int *brLijevih, int *brDesnih){
																									int i=0;
																									*brLijevih=0;
																									*brDesnih=0;
																									for(i=0;i<strlen(znNiz);++i){
																																if(znNiz[i]==lijevi) *brLijevih+=1;
																																else if(znNiz[i]==desni) *brDesnih+=1;
																									}
}

int izrazJeIspravan(int brLijevih, int brDesnih){
												if((brLijevih==brDesnih) && (brLijevih!=0) && (brDesnih!=0)) return 1;
												else return 0;
}