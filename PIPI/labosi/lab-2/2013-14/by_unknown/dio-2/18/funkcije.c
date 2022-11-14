#include"funkcije.h"

void prosjek(int *p, int n, int max, float *pr, float *ps){
													int i=0, j=0;
													for(i=0;i<n;++i){
														for(j=0;j<n;++j){
																		pr[i]+=*(p+i*max+j);
														}
														pr[i]/=(float)n;
													}
													for(j=0;j<n;++j){
														for(i=0;i<n;++i){
																		ps[j]+=*(p+i*max+j);
														}
														ps[j]/=(float)n;
													}
}