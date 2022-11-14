#include <stdio.h>
int main(void) {
	int x1,y1,x2,y2;
	printf("Unesite(x1,y1) (x2,y2) (sa zagradama i zarezima; zagrade medusobno odvojene razmakom)");
	scanf("(%d,%d) (%d,%d)", &x1, &y1, &x2, &y2);
	if (y1==y2)
		printf("Pravac koji prolazi tockama (%d,%d) i (%d,%d) je paralelan sa x osi", x1, y1, x2, y2);
	if (x1==x2)
		printf("Pravac koji prolazi tockama (%d,%d) i (%d,%d) je paralelan sa y osi", x1, y1, x2, y2);
	if ((y1!=y2) && (x1!=x2))
		printf("Pravac koji prolazi tockama (%d,%d) i (%d,%d) nije paralalen ni sa jednom osi", x1, y1, x2, y2);
	return 0;
}
	