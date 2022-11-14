#include<stdio.h>

int main(void){
			
			unsigned int x, y;
			scanf("%u %u", &x, &y);
			if(y>59){
					printf("\r\n Neispravan broj sekundi.");
					return 0;
			}
			printf("\r\n sekunde: %u; sati: %.3f", y+(x*60), ((float)(y+(x*60))/3600));
			return 0;
}