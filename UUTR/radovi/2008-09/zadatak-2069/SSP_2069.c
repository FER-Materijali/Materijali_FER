#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() 
	{
	FILE *dat;
	int polozaj, i, pogodak=0, vrem=0, bL=0, bD=0,a;
	char stanje[10], p[200], np[200], znak, dstanje[10], novostanje[10], zapis, pomak, dznak;

	printf("Upisi ulazni niz: ");scanf("%s", &p);printf("\n");
	polozaj=0;

    for (i=strlen(p);i<200;i++) p[i]='B'; 
	for (i=0;i<200;i++) np[i]='B'; 
    
    strcpy(stanje,"q0");
	
	if (polozaj>=0) znak=p[polozaj];
	if (polozaj<0) znak=np[0-polozaj-1];
	    
	bD=polozaj;
	bL=polozaj;
    
  //  dat=fopen("prijelazi.txt","r");
   // while (fscanf(dat, "%[^?]?%c?%[^?]?%c?%c\n", &dstanje, &dznak, &novostanje, &zapis, &pomak)==5) printf("d(%s,%c)=>(%s,%c,%c)\n", dstanje, dznak, novostanje, zapis, pomak);
  //  fclose(dat);
    
	do
		{
		pogodak=0;

		dat=fopen("prijelazi.txt","r");

		while (fscanf(dat, "%[^?]?%c?%[^?]?%c?%c\n", &dstanje, &dznak, &novostanje, &zapis, &pomak)==5) 
			{
			if ((strcmp(dstanje,stanje)==0) && dznak==znak) {
			printf("d(%s,%c)=>(%s,%c,%c)\n", dstanje, dznak, novostanje, zapis, pomak);
			pogodak=1;
			vrem++;
			strcpy(stanje, novostanje);
			if (polozaj>=0) p[polozaj]=zapis;
			if (polozaj<0) np[0-polozaj-1]=zapis;
			if (pomak=='L') polozaj--;
			if (pomak=='D') polozaj++;
			
			if (polozaj>bD) bD=polozaj;
			if (polozaj<bL) bL=polozaj;

			if (polozaj>=0) znak=p[polozaj];
			if (polozaj<0) znak=np[0-polozaj-1];
     
			}

		if (pogodak==1) break;
		}

	fclose(dat);
	}	while (pogodak==1);

    printf("\n");
	printf("vremenska slozenost ucitanog niza je: %d\n", vrem);
	printf("prostorna slozenost ucitanog niza je: %d\n", bD-bL+1);
	printf("\n");
	
		for (i=bL;i<polozaj;i++)
	            {
                if (i<0) printf("%c",np[0-i-1]);
                else printf("%c",p[i]);
                }
            printf("[%s]",stanje);
            for (i=polozaj;i<bD+1;i++)
                {
                if (i<0) printf("%c",np[0-i-1]);
                else printf("%c",p[i]);
                }
            printf("\n");
            
	printf("\n");
	
system ("pause");
return 0;


}

 
