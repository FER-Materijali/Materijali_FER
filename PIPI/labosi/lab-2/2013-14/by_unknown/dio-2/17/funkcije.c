#include"funkcije.h"
#include<stdio.h>
#include<math.h>

void kvadrat(int *p, int r, int s, int max){
											int i=0, j=0;
											for(i=0;i<r;++i)
												for(j=0;j<s;++j) *(p+i*max+j)=pow(*(p+i*max+j), 2);
}

void minStupac(int *p, int r, int s, int max, int *pm){
													int i=0, j=0;
													for(j=0;j<s;++j){
														pm[j]=*(p+j);
														for(i=0;i<r;++i){
																		if(*(p+j)<=pm[j]) pm[j]=*(p+j);
														}
													}
}