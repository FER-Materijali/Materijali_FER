#include<iostream>
#include<math.h>

int _declspec(naked) max_abs_asm(int* niz, int duljina) {

	_asm {
		push ebp
		mov ebp, esp
		mov esi, [ebp + 8]
		mov edx, [ebp + 12]
		mov eax[esi]
		xor ecx,ecx
		//napravi abs abs(eax)
		//testira se jel broj manji od nule i onda se ovo napravi
		//napravi se obicni dvojni komplement
		//xor sa FFFF i onda +1

		inc ecx

	petlja :
		mov ebx[esi + ecx * 4]
		abs(ebx)
		cmp ebx,eax /* veæi, spremi u eax */
			/* manji, jmp petlja */
		jl manji
		mov eax,ebx

manji:	inc ecx
		cmp edx,ecx
		jne petlja

	kraj:	pop ebp
			ret
	}
}

int max_abs_c(int* niz, int n) {
	int max = *(niz);
	for (int i = 1; i < n; i++) {
		if (max < abs(*(niz + i))) {
			max = abs(*(niz + i));
		}
	}
	return max;
}

int main() {
	int n = 5;
		int a[] = { 1,-3,2,5,-8 };
		int b[] = { 1,-3,2,5,-8 };
		max_abs_asm(a, n);
	max_abs_c(b, n);
	for (int i = 0; i < n; i++) {
		printf("%d ", *(a + i));
	}
	printf("\n");
	for (int i = 0; i < n; i++) {
		printf("%d ", *(b + i));
	}
	return 0;
}