#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() 
	{
	FILE *dat, *out;
	int polozaj, i, pogodak=0, vrem=0, bL=0, bD=0,a;
	char stanje[10], p[200], np[200], znak, dstanje[10], novostanje[10], zapis, pomak, dznak;

	printf("Upisi ulazni niz: ");scanf("%s", &p);printf("\n");
	polozaj=0;

    for (i=strlen(p);i<200;i++) p[i]='B'; 
	for (i=0;i<200;i++) np[i]='B'; 
    
    strcpy(stanje,"q0");
	
	if (polozaj>=0) znak=p[polozaj];
	if (polozaj<0) znak=np[0-polozaj-1];
    
    out=fopen("izlaz.txt","w");
	bD=8;
	bL=-3;
    
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
            	fprintf(out,"\n");
                for (i=bL;i<polozaj;i++)
	            {
                if (i<0) fprintf(out,"%c",np[0-i-1]);
                else fprintf(out,"%c",p[i]);
                }
            fprintf(out,"[%s]",stanje);
            for (i=polozaj;i<bD+1;i++)
                {
                if (i<0) fprintf(out,"%c",np[0-i-1]);
                else fprintf(out,"%c",p[i]);
                }
            fprintf(out,"\n");                                
                                            
			fprintf(out,"d(%s,%c)=>(%s,%c,%c)\n", dstanje, dznak, novostanje, zapis, pomak);
			 fprintf(out,"\n");
			pogodak=1;
			vrem++;
			strcpy(stanje, novostanje);
			if (polozaj>=0) p[polozaj]=zapis;
			if (polozaj<0) np[0-polozaj-1]=zapis;
			if (pomak=='L') polozaj--;
			if (pomak=='D') polozaj++;

			if (polozaj>=0) znak=p[polozaj];
			if (polozaj<0) znak=np[0-polozaj-1];
     
			}

		if (pogodak==1) break;
		}

	fclose(dat);
	}	while (pogodak==1);

	
	
		for (i=bL;i<polozaj;i++)
	            {
                if (i<0) fprintf(out,"%c",np[0-i-1]);
                else fprintf(out,"%c",p[i]);
                }
            fprintf(out,"[%s]",stanje);
            for (i=polozaj;i<bD+1;i++)
                {
                if (i<0) fprintf(out,"%c",np[0-i-1]);
                else fprintf(out,"%c",p[i]);
                }
            fprintf(out,"\n");
            
            fprintf(out,"vremenska slozenost ucitanog niza je: %d\n", vrem);
	        fprintf(out,"prostorna slozenost ucitanog niza je: %d\n", bD-bL+1);
	        fprintf(out,"\n");
	
system ("pause");
return 0;


}

 
