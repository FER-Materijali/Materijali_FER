#include <stdio.h>
int main(void)
{
	char q[20+1];
	int len=0;
	int i=0;
	gets(q);
	while(q[len]!='\0')++len;
	if(len<8)printf("Prekratak.\n");
	else 
	{
	     int slova=0;
	     /*
		 jednica je ako sadrzi barem jedno slovo  malo ili veliko
		 */
		 for(i=0;i<len;++i)
		 {
		 	if( (q[i]>='a' && q[i]<='z') || (q[i]>='A' && q[i]<='Z'))
		 	  slova=1;
		 }
		 if(slova)printf("Zadovoljava uvjete.\n");
		 else printf("Ne sadrzi slovo.\n");
	}
	return 0;
}
