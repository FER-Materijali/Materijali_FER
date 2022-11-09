#include<stdio.h>
#include<string.h>
#include<math.h>
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
	int i,rez=0,rez2=1,prim,prim2,prim3,polje[]={730,641,1337,7921,121,135,233};//28,19,55,46,37,730,641,1337,7921,121,135,233,291,35
	char s[10];
	sprintf(s,"%d",t.sifra);
	sscanf(s+4,"%d",&prim);
	for(i=0;i<strlen(s);i++)
	rez+=s[i]*polje[i];
	s[2]=0;
	sscanf(s,"%d",&prim2);
	s[6]=0;
	sscanf(s+4,"%d",&prim3);
	if(!prim)prim=prim2;
	/*rez2=prim*prim2;
	rez+=rez2+prim2-prim3;*/
	rez%=197;    
	//printf("rez:%d prim=%d\n",rez,prim);getch();
	return rez;
}
int kljuc2(zapis t)
{	
	int i,rez=0,rez2=1,prim,prim2,prim3,polje[]={28,19,55,46,37,730,641};
	char s[10];
	sprintf(s,"%d",t.sifra);
	sscanf(s+4,"%d",&prim);
	s[2]=0;
	sscanf(s,"%d",&prim2);
	s[6]=0;
	sscanf(s+4,"%d",&prim3);
	if(!prim)prim=prim3;
	//rez2=prim*prim2;
	rez=prim*prim2;
	rez%=197;    
	//printf("rez:%d prim=%d\n",rez,prim);getch();
	return rez;
	}


int main()
{
	FILE *ul,*iz;
	zapis t,x;
	int key,brojac[250]={0},i,br=0,prelev=0,upisano=0;
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
	for(i=0;i<197;i++){
	printf("%d. %d\n",i,brojac[i]);
	if(brojac[i]>32)
	{prelev+=brojac[i]-32;}
	upisano+=brojac[i];
	}
	printf("Preljev: %d Upisano: %d\n",prelev,upisano);
	fclose(ul);
	fclose(iz);
	return 0;
}