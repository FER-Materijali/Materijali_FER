#include <stdio.h>

int funkcija(char *prva, char *druga, char *izlaz){
    int p[50+1]={0},i=0,j=0;

    if (prva==NULL){
        fcloseall();
        return 1;
    }
    if (druga==NULL){
        fcloseall();
        return 2;
    }
    if (izlaz==NULL){
        fcloseall();
        return 3;
    }
    
    while (fscanf(prva,"%d%3*c%d\n",&i,&j)>0) p[j]+=i;
    while (fscanf(druga,"%d%3*c%d\n",&i,&j)>0) p[j]+=i;

    for(i=50;i>=0;--i) 
		if (p[i]!=0) fprintf(izlaz,"%d*x^%d\n",p[i],i);
    return 0;
}

int main(){
    FILE *d1,*d2,*d3;
    d1=fopen("prva.txt","r");
    d2=fopen("druga.txt","r");
    d3=fopen("izlaz.txt","w");

	printf("Funkcija je vratila vrijednost: %d\n\n",funkcija(d1,d2,d3));

    fclose(d1);
    fclose(d2);
    fclose(d3);
	return 0;
}



/*
#include <stdio.h>

int zbroji(char *prva, char *druga, char *izlaz){
    int p[50+1]={0},i=0,j=0;
    FILE *d1,*d2,*d3;
    
    i=j=0;
    d1=fopen(prva,"r");
    d2=fopen(druga,"r");
    d3=fopen(izlaz,"w");
    if (d1==NULL){
        fcloseall();
        return 1;
    }
    if (d2==NULL){
        fcloseall();
        return 2;
    }
    if (d3==NULL){
        fcloseall();
        return 3;
    }
    
    while (fscanf(d1,"%d%3*c%d\n",&i,&j)>0) p[j]+=i;
    while (fscanf(d2,"%d%3*c%d\n",&i,&j)>0) p[j]+=i;


    for(i=50;i>=0;--i) 
		if (p[i]!=0) fprintf(d3,"%d*x^%d\n",p[i],i);
	fclose(d1);
    fclose(d2);
    fclose(d3);
    return 0;
}

void main(){
    printf("operacija > %d\n",zbroji("prva.txt","druga.txt","izlaz.txt"));
}
*/