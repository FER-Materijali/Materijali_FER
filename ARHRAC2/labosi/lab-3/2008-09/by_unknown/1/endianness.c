#include <stdio.h>

int main(){
 int i = 0x11abcd22;
 char *p = (char *)&i;

 printf("---> test number: 0x%x\n\n", i);

 printf("addr - 3 | %p | %x |\n", (p-3), *(p-3));
 printf("addr - 2 | %p | %x |\n", (p-2), *(p-2));
 printf("addr - 1 | %p | %x |\n", (p-1), *(p-1));
 printf("addr     | %p | %x |\n", (p), *(p));
 printf("addr + 1 | %p | %x |\n", (p+1), *(p+1));
 printf("addr + 2 | %p | %x |\n", (p+2), *(p+2));
 printf("addr + 3 | %p | %x |\n", (p+3), *(p+3));

 if (*p == 0x11) printf ("\n---> Big endian\n");
 if (*p == 0x22) printf ("\n---> Little endian\n");

 return 0;
}
