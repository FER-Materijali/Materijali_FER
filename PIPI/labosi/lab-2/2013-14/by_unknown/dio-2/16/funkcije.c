#include"funkcije.h"
#include<stdio.h>

void minMax(int *polje, int r, int s, int *min, int *max, int MAX){
														int i=0, j=0;
														*min=*polje;
														*max=*polje;
														for(i=0;i<r;++i){
															for(j=0;j<s;++j){
																			if(polje[i*MAX+j]>*max) *max=polje[i*MAX+j];
																			if(polje[i*MAX+j]<*min) *min=polje[i*MAX+j];
															}
														}
}

int dobreDimenzije(int r, int s, int mr, int ms){
												if(((r<0) || (r>mr)) || ((s<0) || (s>ms))) return 0;
												return 1;
}

