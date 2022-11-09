// VectorLength.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>

int __declspec(naked) duljina_vektora_asm(float*, int, float*)
{
	/*ovdje slijedi tijelo funkcije u strojnom kodu*/
	_asm
	{
		/* cdecl prolog: */
		push  ebp		/* spremi ebp */
		mov   ebp, esp		/* ubaci esp u ebp */

		push esi

		mov esi, [ebp + 8]	/* polje */
		mov edx, [ebp + 12] /* n */
		mov ecx, [ebp + 16]	/* length */
		xor eax, eax
		fld [esi]
		inc eax
		
LAB:	fld [esi + eax * 4]	/* st = polje[i] */
		faddp st(1), st(0)
		inc eax
		cmp eax, edx
		jne LAB
		fstp [ecx]
		
		pop esi
		
		pop ebp
		ret
	}
}
int main()
{
	int n = 4;
	float duljina;
	float niz[] = { -0.5, 1.0, 2.0, 3.0 };

	duljina_vektora_asm(niz, n, &duljina);
	std::cout << "Duljina vektora je: " << duljina;
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
