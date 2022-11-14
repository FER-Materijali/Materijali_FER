#include"funkcije.h"
#include<stdio.h>
#define MAX 20

void unija(int n1, int *s1, int n2, int *s2, int nrez, int *rez){
																int i=0, j=0, n=0, p=0, pom[2*MAX]={0};
																for(i=0;i<n1;++i) pom[i]=s1[i];
																for(i=n1;i<(n2+n1);++i) pom[i]=s2[i-n1];
																n=i;
																for(i=0;i<n;++i){
																	for(j=i+1;j<n;++j){
																					if(pom[i]>pom[j]){
																									p=pom[i];
																									pom[i]=pom[j];
																									pom[j]=p;
																					}
																	}
																}
																for(i=0;i<n;++i){
																	for(j=i+1;j<n;++j){
																					if(pom[i]==pom[j]) pom[j]=0;
																	}
																}
																for(i=0;i<nrez;++i) if(pom[i]>0) rez[i]=pom[i];
																printf("Unija: ");
																for(i=0;i<nrez;++i){
																					if(rez[i]>0) printf("%d ", rez[i]);
																}
}

int je_podskup(int npodskup, int *podskup, int nskup, int *skup){
																int i=0, j=0, p=0;
																if(nskup<npodskup) return 0;
																for(i=0;i<nskup;++i){
																	for(j=i+1;j<nskup;++j){
																					if(skup[i]>skup[j]){
																									p=skup[i];
																									skup[i]=skup[j];
																									skup[j]=p;
																					}
																	}
																}
																for(i=0;i<npodskup;++i){
																	for(j=i+1;j<npodskup;++j){
																					if(podskup[i]>podskup[j]){
																									p=podskup[i];
																									podskup[i]=podskup[j];
																									podskup[j]=p;
																					}
																	}
																}
																p=0;
																for(i=0;i<npodskup;++i){
																	for(j=0;j<nskup;++j){
																						if(podskup[i]==skup[j]){
																												p+=1;
																												break;
																						}
																	}
																}
																if(p==npodskup) return 1;
																else return 0;
}
