#include<stdio.h>

struct cvor {
    int y;
    char x; 
};

typedef struct cvor zapis;

int main()
{
    zapis a;

    scanf("%c %d", &a.x, &a.y);

    return 0;
}
