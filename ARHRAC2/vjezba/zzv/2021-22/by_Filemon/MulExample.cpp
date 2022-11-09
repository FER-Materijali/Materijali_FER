// MulExample.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
int _declspec(naked) mnozi_float_asm(float*, float*, float*, int) {
	_asm {
		/* cdecl prolog: */ 
		push ebp /* spremi ebp */ 
		mov ebp, esp /* ubaci esp u ebp */ 
		
		push esi /* ove registre stavljamo na stog */ 
		push edi

		xor eax, eax /* eax = 0, brojac */ 
		mov edx, [ebp + 20] /* duljina polja n*/ 
		mov esi, [ebp + 8] /* polje u */ 
		mov edi, [ebp + 12] /* polje v */ 
		mov ecx, [ebp + 16] /* polje w */
		
PETLJA:	fld DWORD PTR[esi + eax * 4] /* st = u[i] */ 
		fld DWORD PTR[edi + eax * 4] /* st = v[i], st(1) = u[i] */
		fmulp st(1), st(0) /* st = u[i]*v[i], pop st(1) */ 
		fstp DWORD PTR[ecx + eax * 4] /* w[i] = st, pop st */
		
		inc eax /* i = i + 1 */ 
		cmp eax, edx /* i < n ?*/ 
		jne PETLJA 
		
		pop edi /* dohvacamo stare vrijednosti */ 
		pop esi 
		
		/* cdecl epilog: */ 
		pop ebp /* umjesto 'add esp,4, pop ebp' može biti 'leave'*/
		ret /* povratak iz potprograma */

	}
}

int main()
{
	int n = 8; 
	float u[8] = { 1,2,3,4,5,6,7,8 }; 
	float v[8] = { -1,0,5,2,3,6,11,5 }; 
	float w[8];
	//broji pripadne elemente polja u i v duljine n (rezultat je polje w) 
	mnozi_float_asm(u,v,w,n);
	for (int i = 0; i < n; ++i) { 
		std::cout << w[i] << " "; 
	}

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
