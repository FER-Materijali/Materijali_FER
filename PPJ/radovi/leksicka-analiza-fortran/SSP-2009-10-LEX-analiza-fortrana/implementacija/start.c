#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *getsafe(char *buffer, int count){	/* Kažu da je funkcija gets() opasna...*/
	char *result = buffer, *np;
	if ((buffer == NULL) || (count < 1))
		result = NULL;
	else if (count == 1)
		*result = '\0';
	else if ((result = fgets(buffer, count, stdin)) != NULL)
		if (np = strchr(buffer, '\n'))
			*np = '\0';
	return result;
}


int main(){
	char c, exe[1024], ulaz[1024], naredba[2053], buf;
	
	do{
		strcpy(naredba, "");
		printf("Napredne opcije? [D/N] ");
		scanf("%c", &c);
		scanf("%c", &buf);	/* hvatanje znaka LF (ili što god...) */
		
		if(c=='D' || c=='d'){
			printf("Putanja izvršne datoteke: ");
			getsafe(exe, 1024);
			printf("Putanja ulazne datoteke: ");
			getsafe(ulaz, 1024);
		}else{
			strcpy(exe, "analizator");
			strcpy(ulaz, "ulaz.txt");
		}
		
		/* "slaganje" naredbe za pravilno pokretanje programa */
		if(exe[0]!='/' && exe[0]!='.') strcat(naredba, "./");
		strcat(naredba, exe);
		strcat(naredba, " < ");
		strcat(naredba, ulaz);
		
		system(naredba);
		
		printf("Izlaz? [D/N] ");
		scanf("%c", &c);
		scanf("%c", &buf);	/* hvatanje znaka LF (ili što god...) */
	
	} while(c=='N' || c=='n');
	
	return 0;
}
