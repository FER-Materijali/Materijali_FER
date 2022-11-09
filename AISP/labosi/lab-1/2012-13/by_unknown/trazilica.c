#include<stdio.h>
#include<string.h>
typedef struct
{
	int sifra;
	char ost[9];
}zapis;

int kljuc(zapis t)
{
	int i,rez=0,rez2=1;
	char s[10];
	sprintf(s,"%d",t.sifra);
	for(i=0;i<strlen(s);i++)
	{rez+=s[i];rez2*=s[i];}
    rez+=rez2;
	rez%=160;
	return rez;
}


int main()
{
	FILE *ul;
	zapis t,x;
	int key,br=0;
	ul=fopen("hash","rb");
	scanf("%d%s",&t.sifra,&t.ost);
	key=kljuc(t);
	fseek(ul,512*key,SEEK_SET);
	fread(&x,sizeof(x),1,ul);
	do
	{
	if(x.sifra==t.sifra)
	break;
	else if(x.sifra==0)
	{printf("zapis ne postoji");fclose(ul);return 0;}
	fread(&x,sizeof(x),1,ul);
	br++;
	}while(x.sifra!=t.sifra);
	printf("%d%s na adresi %d",x.sifra,x.ost,key*512+br*sizeof(zapis));	
	fclose(ul);
	return 0;
	}
	