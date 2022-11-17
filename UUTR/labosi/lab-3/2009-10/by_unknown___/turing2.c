#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <malloc.h>

#define M 10000

char ts[4]={'q','0'};

struct novi{
	char shift[2];
	char state[4];
	char entry[2];
	char next[4];
	char nnew[2];
};

struct novi polje[25];

void startsim(void){
	FILE *o,*b;
	int i=0,j,l=0,s;
	char buf[M]="";
	char h[4]="";
	b=fopen("input.txt","r");
	o=fopen("output.txt","w");
	fgets(buf,M,b);
	strcat(buf,"\0");
	strcat(ts,"\0");
	fprintf(o,"%s\n%s\n",ts,buf);
	for(;strcmp(ts,"q11");){
		h[l]=buf[i];
		if(h[l]=='\0'){
			h[l]='B';
		}
		s=0;
		for(;(strcmp(polje[s].state,ts)) || !(polje[s].entry[0]==h[0]);s++);
		for (j=0;j<4;j++)
			ts[j]=polje[s].next[j];
		strcat(ts,"\0");
		buf[i]=polje[s].nnew[0];
		if(polje[s].shift[0]=='L')
			i--;
		else if(polje[s].shift[0]=='R')
			i++;
		fprintf(o,"(%s,%s]>[%s,%s,%s)\n",polje[s].state,polje[s].entry,polje[s].next,polje[s].nnew,polje[s].shift);
		fprintf(o,"%s\n",buf);
		j=0;
	}
	fclose(b);
	fclose(o);
}

void loaddef(void){
	int i,j,l;
	char buf[30]="";
	FILE *s;
	s=fopen("definition.txt","r");
	for(l=0;fgets(buf,20,s);l++){
		for(i=1,j=0;buf[i]!=',';i++,j++)
			polje[l].state[j]=buf[i];
		strcat(polje[l].state,"\0");
		i++;
		for(j=0;buf[i]!=']';i++)
			polje[l].entry[j]=buf[i];
		strcat(polje[l].entry,"\0");
		while(buf[i]!='q')
			++i;
		for(j=0;buf[i]!=',';i++,j++)
			polje[l].next[j]=buf[i];
		strcat(polje[l].next,"\0");
		i++;
		polje[l].nnew[0]=buf[i];
		strcat(polje[l].nnew,"\0");
		i=i+2;
		polje[l].shift[0]=buf[i];
		strcat(polje[l].shift,"\0");
	}
	fclose(s);
}	

int main(void)
{	
	loaddef();
	startsim();
	return 0;
}
