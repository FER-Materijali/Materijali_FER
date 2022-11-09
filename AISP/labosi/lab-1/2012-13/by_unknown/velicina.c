#include<stdio.h>
typedef struct
{
	int sifra;
	char ost[9];
}zapis;

int main()
{
int d=4871+((int)(0.3*4871));
 printf("%d %d",sizeof(zapis),d);
 return 0;
 }