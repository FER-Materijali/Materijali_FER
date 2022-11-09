#include "asp_massh.h"
#include <stdio.h>

struct struktura1 {
	int a;
	int b;
};

typedef struct {
	char a;
	char b;
} struktura2;

void ispis(struct struktura1 str) {
	ispisiVarijablu(str.a);
	ispisiVarijablu(str.b);
}

int main() {
	struct struktura1 a = {5, 7}, c;
	struktura2 b = {'a', 'b'};
	a = c;
	a.a++;
	b.b++;
	ispis(a);
	return 0;
}
