// DotProduct.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>


int __declspec(naked) dotproduct_asm(float*, float*, int, float*)
{
	/*ovdje slijedi tijelo funkcije u strojnom kodu*/
	_asm
	{
		/* cdecl prolog: */
		push  ebp		/* spremi ebp */
		mov   ebp, esp		/* ubaci esp u ebp */
							/* zauzmi 8*n bajtova za lokalne varijable */

		push ebx
		push esi
		push edi

		xor eax, eax	/* eax = 0 */
		mov esi, [ebp + 8]		/* a */
		mov edi, [ebp + 12]		/* b */
		mov ebx, [ebp + 16]		/* n */
		mov ecx, [ebp + 20]		/* rez */

PETLJA:	fld DWORD PTR [esi + eax*4]		/* st = a[i] */
		fld DWORD PTR [edi + eax*4]		/* st = b[i], st(1) = a[i] */
		fmulp	st(1), st(0)				/* st = a[i] * b[i], pop st(1) */
		fld DWORD PTR [ecx]		/* st = rez, st(1) = a[i]* b[i] */
		faddp	st(1), st(0)				/* st = rez + a[i] * b[i] */
		fstp DWORD PTR [ecx]
		inc eax
		cmp eax, ebx
		jne PETLJA

		pop edi
		pop esi
		pop ebx

		pop ebp
		ret
	}
}

int main()
{
	int n = 3;
	float a[] = { 1.0, -2.0, 1.0 };
	float b[] = { 3.0, 2.0, -2.0 };
	float rezultat = 0.0;
	dotproduct_asm(a, b, n, &rezultat);
	printf("%f\n", rezultat);
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
