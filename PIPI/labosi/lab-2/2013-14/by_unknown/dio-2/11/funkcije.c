#include"funkcije.h"
#include<stdio.h>

char *nadjiPodniz(char *ulaz, char *uzorak){
											int i=0, j=0, l1=0, l2=0, z=0;
											for(i=0;ulaz[i]!='\0';++i) l1+=1;
											for(i=0;uzorak[i]!='\0';++i) l2+=1;
											for(i=0;i<l1;++i){
															z=0;
															for(j=0;j<l2;++j){
																			if(ulaz[i+j]==uzorak[j]) z+=1;
																			else break;
															}
															if(z==l2) return &ulaz[i];
											}
											return NULL;
}

int izbaci(char *ulaz, char *uzorak){
									int i=0, l1=0, l2=0;
									char *p=nadjiPodniz(ulaz, uzorak);
									if(p==NULL) return 0;
									for(i=0;ulaz[i]!='\0';++i) l1+=1;
									for(i=0;uzorak[i]!='\0';++i) l2+=1;
									for(i=0;i<l1;++i) *(p+i)=*(p+l2+i);
									return 1;
}