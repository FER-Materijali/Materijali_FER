//citanje po blokovima

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int hash(char *str, int tableSize) {
    int sum =0;
    
    if (!str) return -1;
    for ( ; *str; str++) sum+=*str;
        printf("%d - %d\n", sum, tableSize);
    return sum % tableSize;

}

int main()
{	
    char ime[20];
    while (1) {
    printf("Unesi ime:");	
    gets(ime);
    printf("Hash vrijednost imena %s je %d\n", ime, hash(ime, 11));
}
    system("PAUSE");
    return 0;
}
