// udaljenost.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>

/*definicija gole funkcije - to je zapravo inline nacin pisanja strojnog koda*/
int __declspec(naked) potprogram_asm(float*, float*, int, float*)
{
	/*ovdje slijedi tijelo funkcije u strojnom kodu*/
	_asm
	{
		/* cdecl prolog: */
		push  ebp		/* spremi ebp */
		mov   ebp, esp		/* ubaci esp u ebp */

		push ebx
		push esi
		push edi
		
		xor	eax, eax		/* brojac = 0 */
		mov	ebx, [ebp + 16] /* n */
		mov esi, [ebp + 8]	/* A */
		mov edi, [ebp + 12] /* B */
		mov ecx, [ebp + 20] /* d */
		
LAB:	fld[esi + eax * 4]	/* st = u */
		fld[edi + eax * 4]	/* st = v, st(1) = u */
		fsubr
		fstp st(1) /* pop st */
		fabs
		fadd[ecx] /* st = st + d */
		fstp[ecx] /* d = st, pop st */
		inc eax
		cmp eax, ebx
		jne LAB

		pop edi
		pop esi
		pop ebx

		pop ebp
		ret
	}
}

int main() {
	int n = 4;
	float udaljenost = 0;
	float polje1[] = { -1.0, 3.0, 4.0, 3.0 };
	float polje2[] = { 0.0, 1.0, 2.0, 3.0 };
	potprogram_asm(polje1, polje2, n, &udaljenost);
	std::cout << "Udaljenost: " << udaljenost << std::endl;
	//system("PAUSE");
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
