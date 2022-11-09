#include<iostream>

void _declspec(naked) uvecajza2_asm(float* niz, int duljina) {

	_asm {
		push ebp
		mov ebp, esp
		mov eax, [ebp + 8]
		mov ecx, [ebp + 12]
		mov edx, 0

petlja :	cmp edx, ecx
			je kraj
			fld dword ptr[eax + 4 * edx]
			fld1
			fadd
			fld1
			fadd
			fstp dword ptr[eax + 4 * edx]
			add edx, 1
			jmp petlja

kraj :		pop ebp
			ret

	}
}

void uvecajza2_c(float* niz, int n) {
	for (int i = 0; i < n; i++) {
		*(niz + i) = *(niz + i) + 2;
	}
	return;
}

int main() {
	int i = 0;
	int n = 4;
	__declspec(align(32)) float a[] = { 2.2, -1.2, 3.3, 4.5 };
	__declspec(align(32)) float b[] = { 2.2, -1.2, 3.3, 4.5 };
	uvecajza2_asm(a, n);
	uvecajza2_c(b, n);
	for (i = 0; i < n; i++) {
		printf("%.3f ", *(a + i));
	}
	printf("\n");
	for (i = 0; i < n; i++) {
		printf("%.3f ", *(b + i));
	}
	return 0;
}