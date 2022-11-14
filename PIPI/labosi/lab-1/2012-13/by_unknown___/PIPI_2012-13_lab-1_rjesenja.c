//1.
/*#include <stdio.h>
int main()
{
	int x, i, j;
	scanf("%d", &x);
	if (x < 5 || 20 < x)
	{
		printf("Neispravan broj");
		return 0;
	}
	for (i=0; i<=x; i++)
	{
		printf("%2d. red: ", i);
		for (j=0; j<=i; j++)
			printf("%d ", j);
		printf("\n");
	}
	return 0;
} */ 
//2.
/*#include <stdio.h>
int main()
{
	int x, i;
	float j;
	scanf("%d", &x);
	if (x< 5 || 20 < x)
	{
		printf("Neispravan broj");
		return 0;
	}
	for (i=0; i<=x; i++)
	{
		printf("%2d. red: ", i);
		for (j=0; j<=(float)i/2; j+=0.5)
			printf("%3.1lf ", j/5.);
		printf("\n");
	}
	return 0;
}*/
//3.
/*#include <stdio.h>
int main()
{
	int x, i, j;
	scanf ("%d", &x);
	if (x < 5 || 20 < x)
	{
		printf ("Neispravan broj");
		return 0;
	}
	for (i=0; i<=x; i++)
	{
		printf("%2d. red:", i);
		for (j=0; j<=2*i; j++)
			printf (" ");
		printf("%d\n", i);
	}
	return 0;
}*/
//4.
/*#include <stdio.h>
int main()
{
	int x, i, j;
	scanf ("%d", &x);
	if (x < 5 || 20 < x)
	{
		printf ("Neispravan broj");
		return 0;
	}
	for (i=0; i<=x; i++)
	{
		printf("%2d. red:", i);
		for (j=0; j<=x; j++)
			if (j==i)
				printf("  _");
			else 
				printf("%3d", j);
		printf("\n");
	}
	return 0;
}*/
//5.
/*#include <stdio.h>
int main()
{
	int x, i, j;
	scanf ("%d", &x);
	if (x < 5 || 20 < x)
	{
		printf ("Neispravan broj");
		return 0;
	}
	for (i=0; i<=x; i++)
	{
		printf("%2d. red:", i);
		for (j=0; j<=x; j++)
			if (j==i)

				printf("%3d", j);
			else 

				printf("  _");
		printf("\n");
	}
	return 0;
}*/
//6.
/*#include <stdio.h>
#define MAX 60

int main()
{
	char s[MAX+1];
	int d, i;
	gets(s);
	for (d=0; s[d]; d++);
	if (d<10)
	{
		printf("Prekratak niz");
		return 0;
	}
	for (i=0; i<d; i+=2)
		printf("%c\n", s[i]);
	return 0;
}*/
//7.
/*#include <stdio.h>
#define MAX 60

int main()
{
	char s[MAX+1];
	int d, i;
	gets(s);
	for (d=0; s[d]; d++);
	if (d<10)
	{
		printf("Prekratak niz");
		return 0;
	}
	for (i=0; i<d; i++)
		if('A' <= s[i] && s[i] <= 'Z')
			printf("%c\n", s[i]);
	return 0;
}*/
//8.
/*#include <stdio.h>
#define MAX 60

int main()
{
	char s[MAX+1];
	int d, i;
	gets(s);
	for (d=0; s[d]; d++);
	if (d<10)
	{
		printf("Prekratak niz");
		return 0;
	}
	for (i=d-1; i>=0; i--)
		if('A' <= s[i] && s[i] <= 'Z')
			printf("%c\n", s[i]);
	return 0;
}*/
//9.
/*#include <stdio.h>

int main()
{
	int n, i, P[20];
	while(1)
	{
		scanf("%d", &n);
		if (1<=n && n<=20) break;
		printf("\n");
	}
	for (i=0; i<n; i++)
		scanf("%d", &P[i]);
	for (i=0; i<n; i++)
		if (10 <= P[i] && P[i] <= 20)
			printf("%2d. %d\n", i, P[i]);
	return 0;
}*/
//10.
/*#include <stdio.h>

int main()
{
	int n, i, P[20];
	while(1)
	{
		scanf("%d", &n);
		if (1<=n && n<=20) break;
		printf("\n");
	}
	for (i=0; i<n; i++)
		scanf("%d", &P[i]);
	for (i=n-1; i>=0; i--)
		if (10 <= P[i] && P[i] <= 20)
			printf("%2d. %d\n", i, P[i]);
	return 0;
}*/
//11.
/*#include <stdio.h>

int main()
{
	int n, i;
	float P[20];
	while(1)
	{
		scanf("%d", &n);
		if (1<=n && n<=20) break;
		printf("\n");
	}
	for (i=0; i<n; i++)
		scanf("%f", &P[i]);
	for (i=n-1; i>=0; i--)
		if (6.5 <= P[i] && P[i] <= 10.5)
			printf("%2d.%7.3f\n", i, P[i]);
	return 0;
}*/
//12.
/*#include <stdio.h>
#define PI 3.141593f
int main()
{
	float pi=0.f;
	int n, i;
	while(1)
	{
		scanf("%d", &n);
		if(1<=n && n<=1000) break;
		printf("\n");
	}
	for (i=1; i<=n; i++)
		pi+=1.f/((4*i-1)*(4*i+1));
	pi=pi*-8+4;
	printf("PI = %8.6f\n", pi);
	printf("%8.6f\n", fabs(pi-PI));
	return 0;
}*/
//13.
/*#include <stdio.h>
#include <math.h>
#define PI 3.141593f
int main()
{
	float pi=0.f;
	int n, i;
	while(1)
	{
		scanf("%d", &n);
		if(1<=n && n<=1000) break;
		printf("\n");
	}
	for (i=1; i<=n; i++)
		pi+=pow(-1.,(double)(i-1))*1.f/(2*i-1);
	pi=pi*4.f;
	printf("PI = %8.6f\n", pi);
	printf("%8.6f\n", fabs(pi-PI));
	return 0;
}*/
//14.
/*#include <stdio.h>
#include <math.h>
int main()
{
	float b=0.f;
	int n, i;
	while(1)
	{
		scanf("%d", &n);
		if(1<=n && n<=1000) break;
		printf("\n");
	}
	for (i=1; i<=n; i++)
		b+=1.f/(i*(i+1));
	printf("jedan = %8.6f\n", b);
	printf("%8.6f\n", fabs(b-1.f));
	return 0;
}*/
//15.
/*#include <stdio.h>
#include <math.h>
int main()
{
	float b=0.f;
	int n, i;
	while(1)
	{
		scanf("%d", &n);
		if(1<=n && n<=1000) break;
		printf("\n");
	}
	for (i=1; i<=n; i++)
		b+=1.f/(i*(i+2));
	printf("3/4 = %8.6f\n", b);
	printf("%8.6f\n", fabs(b-0.75f));
	return 0;
}
*/
//16.
/*#include <stdio.h>
#include <math.h>
int main()
{
	float b=0.f;
	int n, i;
	while(1)
	{
		scanf("%d", &n);
		if(1<=n && n<=1000) break;
		printf("\n");
	}
	for (i=1; i<=n; i++)
		b+=1.f/((2*i-1)*(2*i+1));
	printf("1/2 = %8.6f\n", b);
	printf("%8.6f\n", fabs(b-0.5f));
	return 0;
}*/
//17.
/*#include <stdio.h>
#include <math.h>
int main()
{
	float b=0.f;
	int n, i;
	while(1)
	{
		scanf("%d", &n);
		if(1<=n && n<=1000) break;
		printf("\n");
	}
	for (i=1; i<=n; i++)
		b+=1.f/(i*(i+1)*(i+2));
	printf("1/4 = %8.6f\n", b);
	printf("%8.6f\n", fabs(b-0.25f));
	return 0;
}*/
//18.
/*#include <stdio.h>

int main()
{
	char s[20+1];
	int d, b=1, i;
	gets(s);
	for (d=0; s[d]; d++);
	if (d<8)
	{
		printf("Prekratak");
		return 0;
	}
	for (i=0; s[i]; i++)
		if (('A'<=s[i] && s[i]<='Z')||('a'<=s[i] && s[i]<='z'))
			b=0;
	if (b)
	{
		printf("Ne sadrzi slovo");
		return 0;
	}
	printf("Zadovoljava uvjete");
	return 0;
}*/
//19.
/*#include <stdio.h>

int main()
{
	char s[30+1];
	int z=0, b=0, i;
	gets(s);
	
	for (i=0; s[i]; i++)
	{
		if ('a'<=s[i] && s[i]<='z')
			b++;
		if ('0' <= s[i] && s[i]<='9')
			z++;
	}
	if (b>=7 && z>=2)
	{
		printf("Zadovoljava uvjete");
		return 0;
	}
	printf("Ne zadovoljava uvjete");
	return 0;
}*/
//20.
/*#include <stdio.h>

int main()
{
	int n, i, s[30];
	
	while(1)
	{
		scanf("%d", &n);
		if (1<=n && n<=30) break;
		printf("\n");
	}
	for (i=0; i<n; i++)
		scanf("%d", &s[i]);
	printf("Promijenjeno polje:");
	for (i=0; i<n; i++)
	{
		if (-1 <= s[i] && s[i] <= 22)
			s[i]=0;
		printf("  %d",s[i]);
	}
	return 0;
}*/
//21.
/*#include <stdio.h>

int main()
{
	int n, i, s[20],b=0;
	
	while(1)
	{
		scanf("%d", &n);
		if (1<=n && n<=20) break;
		printf("\n");
	}
	for (i=0; i<n; i++)
		scanf("%d", &s[i]);
	for (i=0; i<n; i++)
		if (-10 <= s[i] && s[i] <=10)
		{
			b+=s[i];
			s[i]=0;
			
		}
		
	printf("Zbroj vrijednosti promijenjenih elemenata:  %d",b);
	return 0;
}*/
//22.
/*#include <stdio.h>

int main()
{
	int n, i, s[10],b=0;
	
	while(1)
	{
		scanf("%d", &n);
		if (1<=n && n<=10) break;
		printf("\n");
	}
	for (i=0; i<n; i++)
		scanf("%d", &s[i]);
	for (i=0; i<n; i++)
		if (-20 <= s[i] && s[i] <= 40)
		{
			s[i]=-100;
			b++;
		}
		
	printf("Broj promijenjenih elemenata:  %d",b);
	return 0;
}*/
//23.
/*#include <stdio.h>

int main()
{
	int n, i, s[15],b=-1, z[15];
	
	while(1)
	{
		scanf("%d", &n);
		if (1<=n && n<=15) break;
		printf("\n");
	}
	for (i=0; i<n; i++)
		scanf("%d", &s[i]);
	for (i=0; i<n; i++)
		if (-10 <= s[i] && s[i] <=15)
		{
			b++;
			z[b]=s[i];	
		}
		
	printf("Novo polje:");
	for (i=0; i<=b; i++)
		printf("  %d", z[i]);
	return 0;
}*/
//24.
/*#include <stdio.h>

int main()
{
	int b[100]={0};
	int x;
	while(1)
	{
		scanf("%d", &x);
		if (x < 1 || 100 < x)
		{
			printf("Broj je izvan intervala");
			return 0;
		}
		b[x-1]++;
		if (b[x-1]==5)
		{
			printf ("broj koji se procitao 5 puta: %d", x);
			return 0;
		}
	}
	return 0;
}*/
//25.
/*#include <stdio.h>

int main()
{
	int b[100]={0};
	int x, i=0;
	while(1)
	{
		scanf("%d", &x);
		i++;
		if (x < 1 || 50 < x)
		{
			printf("Broj je izvan intervala");
			return 0;
		}
		b[x-1]++;
		if (b[x-1]==6)
		{
			printf ("Ukupno je procitano %d brojeva", i);
			return 0;
		}
	}
	return 0;
}*/
//26.
/*#include <stdio.h>

int main()
{
	int b[100]={0};
	int x;
	while(1)
	{
		scanf("%d", &x);
		if (x < -30 || 30 < x)
		{
			printf("Broj je izvan intervala");
			return 0;
		}
		b[30+x]++;
		if (b[30+x]==3)
		{
			printf ("Broj koji se procitao barem 3 puta: %d", x);
			return 0;
		}
	}
	return 0;
}*/
//27.
/*#include <stdio.h>

int main()
{
	int b[40]={0};
	int x;
	while(1)
	{
		scanf("%d", &x);
		b[x-1]++;
		if (b[x-1]==4)
			break;
                    	
	}
	for (x=1; x<=40; x++)
		if(b[x-1])
			printf("broj %2d: %d\n", x, b[x-1]);
	return 0;
}*/
//28.
/*#include <stdio.h>

int main()
{
	int b[100]={0};
	int x;
	while(1)
	{
		scanf("%d", &x);
		b[x-1]++;
		if (x<1 || 30 < x)
			break;
                    	
	}
	for (x=1; x<=30; x++)
		if(b[x-1]>=2)
			printf("broj %2d: %d\n", x, b[x-1]);
	return 0;
}*/
//29.
/*#include <stdio.h>

int main()
{
	int b[100]={0}, c[100];
	int x,z=0,i;
	while(1)
	{
		while(1)
		{
			scanf("%d", &x);
			if (1<= x && x<= 30)
				break;
			printf("\n");
		}
		c[z]=x;
		z++;
		b[x-1]++;
		if (b[x-1]==2)
			break;
                    	
	}
	for (i=0; i<z; i++)
		if(c[i]==x)
		{
			printf("Broj %d bio je %d. procitani broj.\n", x, i+1 );
			break;
		}
	printf("Ukupno procitano brojeva: %d", z);
	return 0;
}*/
//30.
/*#include <stdio.h>

int main()
{
	int i=0,j,k, s[1000];
	while(1)
	{
		scanf("%d", &s[i]);
		if(s[i] < 1 || 40 < s[i]) break;
		i++;
	}
	for(j=1; j<=40; j++)
		for(k=0;k<=i ; k++)
			if(s[k]==j)
			{
				printf("Broj %2d : %d\n", j, k+1);
				break;
			}
	return 0;
}*/
//31.
/*#include <stdio.h>

int main()
{
	char s[20+1];
	int d, i,t;
	gets(s);
	for(d=0; s[d]; d++);
	for (i=0; i<d-1; i++)
		if('a' <= s[i] && s[i] <= 'z')
		{
			t=s[i];
			s[i]=s[d-1];
			s[d-1]=t;
			break;
		}
	for (i=0; s[i]; i++)
		printf("%c", s[i]);
	return 0;
}*/
//32.
/*#include <stdio.h>

int main()
{
	char a[30+1], b[30+1];
	int i, t=0;
	gets(a);
	gets(b);
	for (i=0; a[i] && b[i]; i++)
		if(!(i%2))
		{
			a[i]=b[i];
			t++;
		}
	printf("Promijenjeni niz: ");
	for(i=0; a[i]; i++)
		printf("%c", a[i]);
	printf("\n\nPromijenjeno znakova: %d", t);
	return 0;
}*/
//33.
/*#include <stdio.h>

int main()
{
	int x, z[10]={0};
	int i;
	while (1)
	{
		scanf("%d", &x);
		if(100<=x && x<=99999) break;
		printf("\n");
	}
	while (x)
	{
		z[x%10]++;
		x/=10;
	}
	printf("Znamenke u broju %d su:\n\n", x);
	for (i=0; i<=9; i++)
		if(z[i])
			printf(" -  znamenka %d: %d\n", i, z[i]);
	return 0;
}*/
//34.
/*#include <stdio.h>

int main()
{
	int x, z[10]={0};
	int i;
	while (1)
	{
		scanf("%d", &x);
		if(100<=x && x<=99999) break;
		printf("\n");
	}
	printf("U broju %d najveca znamenka je: ", x);
	while (x)
	{
		z[x%10]++;
		x/=10;
	}
	for (i=9; i>=0; i--)
		if(z[i])
		{
			printf("%d", i);
			return 0;
		}
	return 0;
}*/
//35.
/*#include <stdio.h>

int main()
{
	int x, z[10]={0};
	int i=0;
	while (1)
	{
		scanf("%d", &x);
		if(1<=x && x<=99999) break;
		printf("\n");
	}
	printf("Broj %d: prva ", x);
	while(x)
	{
		z[i]=x%10;
		x/=10;
		i++;
		
	}
	if (z[0]>z[i-1])
		printf("znamenka manja od zadnje");
	else if(z[0]<z[i-1])
		printf("znamenka veca od zadnje");
	else
		printf("i zadnja znamenka su jednake");
	return 0;
}*/
//36.
/*#include <stdio.h>

int main()
{
	int x, z[10]={0};
	int i;
	while (1)
	{
		scanf("%d", &x);
		if(1<=x && x<=99999) break;
		printf("\n");
	}
	printf("Broj %d - broj znamenaka koje se jednom pojavljuju: ", x);
	while (x)
	{
		z[x%10]++;
		x/=10;
	}
	for (i=0; i<=9; i++)
		if (z[i]==1)
			x++;
	printf("%d", x);
	return 0;
}	*/
//37.
/*#include <stdio.h>

int main()
{
	int x, z[10]={0};
	int i;
	while (1)
	{
		scanf("%d", &x);
		if(1<=x && x<=99999) break;
		printf("\n");
	}
	printf("Broj %d - suma znamenaka koje se jednom pojavljuju: ", x);
	while (x)
	{
		z[x%10]++;
		x/=10;
	}
	for (i=0; i<=9; i++)
		if (z[i]==1)
			x+=i;
	printf("%d", x);
	return 0;
}	*/
//38.
/*#include <stdio.h>
	
int main()
{
	int x,y,a,i=0;
	int z[3];
	do
	{
		scanf("%d", &x);
		printf("\n");
	}while (x < 100 || 999<x);
	a=x;
	while(a)
	{
		z[i]=a%10;
		a/=10;
		i++;
	}
	y=z[0]*100+z[1]*10+z[2];
	if (y>x)
		printf("Broj %d veci je od ucitanog broja", y);
	else if (y<x)
		printf("Broj %d manji je od ucitanog broja", y);
	else
		printf("Broj %d jednak je ucitanom broju", y);
	return 0;
}*/
//39.
/*#include <stdio.h>

int main()
{
	unsigned int x,a;
	int i=0, n=9;
	int z[20]={0};
	scanf("%u", &x);
	a=x;
	while(a)
	{
		z[i]=a%10;
		if (z[i]<n && z[i])
			n=z[i];
		i++;
		a/=10;
	}
	if (x%n)
		printf("broj %d nije djeljiv sa svojom najmanjom znamenkom %d", x, n);
	else
		printf("broj %d je djeljiv sa svojom najmanjom znamenkom %d", x, n);
	return 0;
}*/
//40.
/*#include <stdio.h>

int main()
{
	char s[10+1];
	int i=0,b=0;
	scanf("%[^\n]",s); //isto kao gets(s)
	while (s[i])
	{
		if((s[i]!='0') && (s[i]!='1'))
		{
			printf("Procitani niz nije ispravno zadan.\n");
			return 0;
		}
		if(s[i]=='1')
			b++;
		i++;
	}
	printf("%d\n", b);
	return 0;
}*/
//41.
/*#include <stdio.h>

int main()
{
	char s[10+1];
	int i=0,b=0;
	gets(s);
	while (s[i])
	{
		if((s[i]!='0') && (s[i]!='1'))
		{
			printf("Procitani niz nije ispravno zadan.\n");
			return 0;
		}
		if(s[i]=='1')
			b=0;
		else
			b++;
		if(b==2)
		{
			printf("Procitani binarni broj sadrzi dvije ili vise uzastopnih znamenki 0");
			return 0;
		}
		i++;
	}
	printf("Procitani binarni broj ne sadrzi dvije ili vise uzastopnih znamenki 0");
	return 0;
}*/
//42.
/*#include <stdio.h>

int main()
{
	char s[10+1];
	int i=0;
	gets(s);
	while (s[i])
	{
		if((s[i]!='0') && (s[i]!='1'))
		{
			printf("Procitani niz nije ispravno zadan.\n");
			return 0;
		}
		i++;
	}
	if(s[i-1]=='0')
		printf("Posljednja znamenka procitanog broja je 0");
	else
		printf("Posljednja znamenka procitanog broja nije 0");
	return 0;
}*/
//43.
/*#include <stdio.h>

int main()
{
	char s[5+1];
	int i=0, b=0;
	gets(s);
	while (s[i])
	{
		if(s[i]<'0' || '7' < s[i])
		{
			printf("Procitani niz nije ispravno zadan.\n");
			return 0;
		}
		if(s[i]=='4')
			b++;
		i++;
	}
	if (b==0)
		printf("Znamenka 4 se ne pojavljuje u broju.");
	else if (b==1)
		printf("Znamenka 4 se pojavljuje 1 put.");
	else 
		printf("Znamenka 4 se pojavljuje %d puta.", b);
	return 0;
}*/
//44.
/*#include <stdio.h>

int main()
{
	char s[5+1];
	int i=0;
	gets(s);
	while (s[i])
	{
		if(s[i]<'0' || '7' < s[i])
		{
			printf("Procitani niz nije ispravno zadan.\n");
			return 0;
		}
		i++;

	}
	printf("Prva znamenka procitanog broja je %c.", s[0]);
	printf("\nPosljednja znamenka procitanog broja je %c.", s[i-1]);
	return 0;
}
*/
//45.
/*#include <stdio.h>

int main()
{
	char s[5+1];
	char n='7';
	int i=0;
	gets(s);
	while (s[i])
	{
		if(s[i]<'0' || '7' < s[i])
		{
			printf("Procitani niz nije ispravno zadan.\n");
			return 0;
		}
		if(s[i]<n)
			n=s[i];
		i++;

	}
	printf("Najmanja oktalna znamenka koja se pojavljuje u procitanom broju je %c", n);
	return 0;
}*/
//46.
/*#include <stdio.h>

int main()
{
	char s[5+1];
	char n='0';
	int i=0;
	gets(s);
	while (s[i])
	{
		if(!(('0'<=s[i] && s[i]<='9')||('a'<=s[i] && s[i]<='f')||('A'<=s[i] && s[i]<='F')))
		{
			printf("Procitani niz nije ispravno zadan.\n");
			return 0;
		}
		if('a'<=s[i] && s[i]<='f')
			s[i]-='a'-'A';
		if (s[i]>n)
			n=s[i];
		i++;

	}
	printf("Najveca heksadekadska znamenka koja se pojavljuje u procitanom broju je %c", n);
	return 0;
}*/
//47.
/*#include <stdio.h>

int main()
{
	char s[5+1];
	char n='F';
	int i=0;
	gets(s);
	while (s[i])
	{
		if(!(('0'<=s[i] && s[i]<='9')||('a'<=s[i] && s[i]<='f')||('A'<=s[i] && s[i]<='F')))
		{
			printf("Procitani niz nije ispravno zadan.\n");
			return 0;
		}
		if('a'<=s[i] && s[i]<='f')
			s[i]-='a'-'A';
		if (s[i]<n)
			n=s[i];
		i++;

	}
	printf("Najmanja heksadekadska znamenka koja se pojavljuje u procitanom broju je %c", n);
	return 0;
}*/
//48.
/*#include <stdio.h>

int main()
{
	int x, n=-1, i=0;
	while(1)
	{
		scanf("%d", &x);
		if(!i && !(0 <= x && x<=100))
		{
			printf("Nije unesen niti jedan broj iz trazenog intervala");
			return 0;
		}
		if (!(1<= x && x<=100))
			break;
		if(!i && (0<= x && x<= 100) && !(x%4))
		{	
			n=x;
			i++;
		}
		i++;
		if (!(x%4) && x<n)
			n=x;
	}
	if (n==-1)
		printf("Nije unesen niti jedan broj djeljiv s 4");
	else
		printf("Najmanji uneseni broj djeljiv s 4 je %d", n);
	return 0;
}*/
//49.
/*#include <stdio.h>

int main()
{
	int x, n=-1, m=-1, i=0;
	while(1)
	{
		scanf("%d", &x);
		if(!i && !(0 <= x && x<=100))
		{
			printf("Nije unesen niti jedan broj iz trazenog intervala");
			return 0;
		}
		if (!(1<= x && x<=100))
			break;
		if(!i && (0<= x && x<= 100) && !(x%4))
		{	
			n=x;
			m=x;
			i++;
		}
		i++;
		if (!(x%4) && x<n)
			n=x;
		if (!(x%4) && x>m)
			m=x;
	}
	if (n==-1)
		printf("Nije unesen niti jedan broj djeljiv s 4");
	else
		printf("Zbroj najveceg i najmanjeg unesenog broja djeljivog s 4 je %d", n+m);
	return 0;
}*/
//50.
/*#include <stdio.h>

int main()
{
	int x, n=-1, m=0, i=0;
	while(1)
	{
		scanf("%d", &x);
		if(!i && !(0 <= x && x<=100))
		{
			printf("Nije unesen niti jedan broj iz trazenog intervala");
			return 0;
		}
		if (!(1<= x && x<=100))
			break;
		if (x<50)
		{
			m+=x;
			n=1;
			i++;
		}
		i++;	
	}
	if (n==-1)
		printf("Nije unesen niti jedan broj manji od 50");
	else
		printf("Zbroj svih brojeva manjih od 50 je %d", m);
	return 0;
}*/
//51.
/*#include <stdio.h>

int main()
{
	int x,  m=0, i=0;
	while(1)
	{
		scanf("%d", &x);
		if(!i && !(0 <= x && x<=100))
		{
			printf("Nije unesen niti jedan broj iz trazenog intervala");
			return 0;
		}
		if (!(1<= x && x<=100))
			break;
		if (x%17==0)
		{
			m++;
			i++;
		}
		i++;	
	}
	printf("Broj unesenih brojeva djeljivih sa 17 je %d", m);
	return 0;
}*/
//52.
/*#include <stdio.h>

int main()
{
	char z[]={'0','1','2','3','4','5','6','7','8','9','a','b','c','d','e','f','A','B','C','D','E','F',' '};
	char x;
	int i,p, b=0, u=0;
	for(;;)
	{
		p=0;
		scanf("%c",&x);
		for(i=0; z[i]; i++)
			if(x==z[i])
			{
				p=1;
				if(i<=7)
					b++;
			}
		if(p==0)
			break;
		u++;
		
	}
	if(u==0)
	{
		printf("Nije unesen niti jedan broj iz trazenog intervala.");
		return 0;
	}
	printf("Broj unesenih oktalnih znamenki %d", b);
	return 0;
}*/
//53.
/*#include <stdio.h>

int main()
{
	char z[]={'0','1','2','3','4','5','6','7','8','9','a','b','c','d','e','f','A','B','C','D','E','F',' 
'};
	char x;
	int i,p, b=0, u=0;
	for(;;)
	{
		p=0;
		scanf("%c",&x);
		for(i=0; z[i]; i++)
			if(x==z[i])
			{
				p=1;
				if(i>7)
					b++;
			}
		if(p==0)
			break;
		u++;
		
	}
	if(u==0)
	{
		printf("Nije unesen niti jedan broj iz trazenog intervala.");
		return 0;
	}
	printf("Broj unesenih hex zn koje nisu dekadske: %d", b);
	return 0;
}*/
//54.
/*#include <stdio.h>

int main()
{
	int m1=0,m2=0, i=0, x, y;
	while(1)
	{
		if(i==0)
		{
			scanf("%d", &x);
			if(x<0 || 100 <x)
			{
				printf("Nije uneseno dovoljno brojeva iz trazenog intervala");
				return 0;
			}
			scanf("%d", &y);
			if(y<0 || 100<y)
			{
				printf("Nije uneseno dovoljno brojeva iz trazenog intervala");
				return 0;
			}
			if(x>y)
			{
				m1=x;
				m2=y;
			}
			else
			{
				m1=y;
				m2=x;
			}
		}
		else
		{
			scanf("%d",&x);
			if(x<0 || 100<x)
				break;
			if (x>m1)
			{
				m2=m1;
				m1=x;
			}
			else if (m2 < x && x<m1)
				m2=x;
		}
		i++;
	}
	if (m2==0)
	{
		printf("Manji maksimum je nula, nema ostatka pri djeljenju");
		return 0;
	}
	printf("Ostatak pri djeljenu %d sa %d je %d", m1, m2, m1%m2);
	return 0;
}*/
//55.
/*#include <stdio.h>

int main()
{
	char s[30+1];
	int i;
	gets(s);
	for(i=0; s[i]; i++)
		if(!(('0'<=s[i] && s[i]<='9') || ('a'<= s[i] && s[i] <='z') || ('A'<= s[i] && s[i]<='Z')))
		{
			printf("Procitani niz nije ispravno zadan");
			return 0;
		}
	for (i=0; s[i]; i++)
	{
		printf("%c",s[i]);
		switch(s[i])
		{
			case 'A': s[i]='0'; break;
			case 'E': s[i]='1'; break;
			case 'I': s[i]='2'; break;
			case 'O': s[i]='3'; break;
			case 'U': s[i]='4'; break;
			default: s[i]=s[i];
		}
	}
	printf("\n");
	for (i=0; s[i]; i++)
		printf("%c",s[i]);
	return 0;
}*/
//56.
/*#include <stdio.h>

int main()
{
	char s[30+1];
	int i;
	gets(s);
	for(i=0; s[i]; i++)
		if(!(('0'<=s[i] && s[i]<='9') || ('a'<= s[i] && s[i] <='z') || ('A'<= s[i] && s[i]<='Z')))
		{
			printf("Procitani niz nije ispravno zadan");
			return 0;
		}
	for (i=0; s[i]; i++)
	{
		printf("%c",s[i]);
		switch(s[i])
		{
			case 'a': s[i]='9'; break;
			case 'e': s[i]='8'; break;
			case 'i': s[i]='7'; break;
			case 'o': s[i]='6'; break;
			case 'u': s[i]='5'; break;
			default: s[i]=s[i];
		}
	}
	printf("\n");
	for (i=0; s[i]; i++)
		printf("%c",s[i]);
	return 0;
}*/
//57.
/*#include <stdio.h>

int main()
{
	char s[30+1];
	int i;
	gets(s);
	for(i=0; s[i]; i++)
		if(!(('0'<=s[i] && s[i]<='9') || ('a'<= s[i] && s[i] <='z') || ('A'<= s[i] && s[i]<='Z')))
		{
			printf("Procitani niz nije ispravno zadan");
			return 0;
		}
	for (i=0; s[i]; i++)
	{
		printf("%c",s[i]);
		switch(s[i])
		{
			case '0': s[i]='A'; break;
			case '1': s[i]='E'; break;
			case '2': s[i]='I'; break;
			case '3': s[i]='O'; break;
			case '4': s[i]='U'; break;
			default: s[i]=s[i];
		}
	}
	printf("\n");
	for (i=0; s[i]; i++)
		printf("%c",s[i]);
	return 0;
}*/
//58.
/*#include <stdio.h>

int main()
{
	char s[30+1];
	int i;
	gets(s);
	for(i=0; s[i]; i++)
		if(!(('0'<=s[i] && s[i]<='9') || ('a'<= s[i] && s[i] <='z') || ('A'<= s[i] && s[i]<='Z')))
		{
			printf("Procitani niz nije ispravno zadan");
			return 0;
		}
	for (i=0; s[i]; i++)
	{
		printf("%c",s[i]);
		switch(s[i])
		{
			case '5': s[i]='a'; break;
			case '6': s[i]='e'; break;
			case '7': s[i]='i'; break;
			case '8': s[i]='o'; break;
			case '9': s[i]='u'; break;
			default: s[i]=s[i];
		}
	}
	printf("\n");
	for (i=0; s[i]; i++)
		printf("%c",s[i]);
	return 0;
}*/




