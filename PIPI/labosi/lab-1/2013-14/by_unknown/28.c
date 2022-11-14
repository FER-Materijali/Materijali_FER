#include<stdio.h>

int main(void){
		
			unsigned int x1, x2, y1, y2;
			scanf("%u %u %u %u", &x1, &y1, &x2, &y2);
			if(y1==y2) printf("\r\n Pravac koji prolazi tockama (%u,%u) i (%u,%u) je paralelan s x osi.", x1, y1, x2, y2);
			else if(x1==x2) printf("\r\n Pravac koji prolazi tockama (%u,%u) i (%u,%u) je paralelan s y osi.", x1, y1, x2, y2);
			else printf("\r\n Pravac koji prolazi tockama (%u,%u) i (%u,%u) nije paralelan ni s jednom osi.", x1, y1, x2, y2);
			return 0;
}