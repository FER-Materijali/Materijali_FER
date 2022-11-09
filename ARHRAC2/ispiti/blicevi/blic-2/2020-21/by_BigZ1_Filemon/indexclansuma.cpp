#include<iostream>

void _declspec(naked) zbrojindexclan_asm(int* niz, int duljina) {

	_asm {
			push ebp
			mov ebp, esp
			mov ebx, [ebp + 12]
			mov eax, [ebp + 8]
			mov ecx, 0

	petlja:	cmp ecx, ebx
			je kraj
			mov edx, [eax+4*ecx]
			add edx,ecx
			mov [eax+4*ecx],edx
			add ecx, 1
			jmp petlja

	kraj :	pop ebp
			ret

	}
}

void zbrojindexclan_c(int* niz, int duljina) {
	for (int i = 0; i < duljina; i++) {
		*(niz + i) = *(niz + i) + i;
	}
	return;
}

int main() {
	int a[] = { 2,3,8,7,1 };
	int b[] = { 2,3,8,7,1 };
	int n = 5;
	zbrojindexclan_asm(a, n);
	zbrojindexclan_c(b, n);
	for (int i = 0; i < n; i++) {
		printf("%d ", *(a + i));
	}
	printf("\n");
	for (int i = 0; i < n; i++) {
		printf("%d ", *(b + i));
	}
	printf("\n");
	return 0;
}