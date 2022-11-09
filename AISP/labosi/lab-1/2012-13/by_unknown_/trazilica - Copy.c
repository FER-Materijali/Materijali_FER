#include<stdio.h>
#include<string.h>
typedef struct
{
	int sifra;
	char ost[9];
}zapis;

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


int main()
{
	FILE *ul;
	zapis t,x;
	int key,br=0;
	ul=fopen("hash","rb");
	printf("Unesite indekas: ");
	scanf("%d",&t.sifra);
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
	