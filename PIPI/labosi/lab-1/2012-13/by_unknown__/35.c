#include<stdio.h>
int main()
{
			int n,a[10]={0},i,max,k=0;
			do
			{
						scanf("%d",&n);
						}while(n<100 || n>10000);
						int t=n;
						int zadnja=n%10,prva;
						while(n>0)
						{
							
							if(!(n/10))
							prva=n%10;
							n/=10;
							
							
							}
						if(zadnja>prva)
						printf("U broju %d: zadnja je veca od prve",t);
						else if(prva>zadnja)
						printf("U broju %d: prva je veca od zadnje",t);
						else if(prva==zadnja)
						printf("U broju %d: prva je jednaka zadnjoj",t);
						return 0;
}
						