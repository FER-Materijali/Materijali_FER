#include<iostream>
#include<windows.h>
#include<ctime>
#include<stdio.h>
using namespace std;

int main(void)
{

int n;

int polje[500];

scanf("%d",&n);


for (int x=0;x<n;++x)
{

    scanf("%d",polje+x);

}


int i,j,korak;
int tmp;

for (korak=n/2;korak>0;korak/=2)
{
    for (i=korak;i<n;++i)
    {
    tmp=polje[i];
    
    for (j=i;j>=korak && tmp<polje[j-korak];j-=korak)
        polje[j]=polje[j-korak];
    
    polje[j]=tmp;
    
    }

for (int x=0;x<n;++x)
    printf("%d ",polje[x]);

printf("\n");

}


//printf("\n");


}
