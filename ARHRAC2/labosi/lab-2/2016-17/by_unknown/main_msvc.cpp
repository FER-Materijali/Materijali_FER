#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <stdlib.h>


//C solution
int C_method(int n) {
	int sum = 0;
	for (int i = 0; i < n; i++) {
		sum += i;
	}
	return sum;
}

//ASSEMBLER solution
int _declspec (naked) ASM_method(int n) {

	_asm {

		push ebp
		mov ebp, esp

		mov edx, [esp + 8] //border
		mov ecx, 0 //counter
		mov eax, 0 //sum

PETLJA:	cmp ecx, edx
		jl EX
		pop ebp
		ret

EX:		add eax, ecx
		add ecx, 1
		jmp PETLJA
	}
}


/*MAIN method*/

int main() {
	std::cout << "ASM: " << ASM_method(7) << std::endl;
	std::cout << "C++: " << C_method(7) << std::endl;
}