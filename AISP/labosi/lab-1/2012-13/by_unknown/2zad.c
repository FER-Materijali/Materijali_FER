#include<stdio.h>
#include<string.h>
typedef struct
{
	int sifra;
	char ost[9];
}zapis;

void init(FILE *tok)
{
	char nula=0;
	int gr=(4871+((int)(0.3*4871)))*sizeof(zapis);
	fseek(tok,gr,SEEK_SET);
	fwrite(&nula,sizeof(nula),1,tok);
	return;
	}
	
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
	FILE *ul,*iz;
	zapis t,x;
	int key,brojac[247]={0},i,br=0;
	ul=fopen("prosjek.txt","r");
	iz=fopen("hash","w+b");
	init(iz);
	while((fscanf(ul,"%d%s",&t.sifra,&t.ost))==2)
	{
		key=kljuc(t);
		fseek(iz,512*key,SEEK_SET);
		fread(&x,sizeof(x),1,iz);
		//printf("%d%c%f%c%d \n",x.sifra,x.prekid1,x.prosjek,x.prekid2,x.dop);

		if(!(x.sifra))
		{
		fseek(iz,(-1)*sizeof(x),SEEK_CUR);
		fwrite(&t,sizeof(t),1,iz);
		}
		else do
		{
			fread(&x,sizeof(x),1,iz);
			}while(x.sifra);
		fseek(iz,(-1)*sizeof(x),SEEK_CUR);
		fwrite(&t,sizeof(t),1,iz);
		brojac[key]++;
		br++;
		printf("%d\n",br);
	}
	for(i=0;i<247;i++)
	printf("%d\n",brojac[i]);
	fclose(ul);
	fclose(iz);
	return 0;
}