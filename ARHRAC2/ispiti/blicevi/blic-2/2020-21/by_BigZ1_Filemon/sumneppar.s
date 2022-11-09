.intel_syntax noprefix
.global sumneppar_asm

sumneppar_asm:
	push ebp
	pop esp
	mov ebx,[ebp+8]
	mov ecx,0
	mov edx,0
	
parni:
	cmp ecx,ebx
	je kraj
	add eax,ecx
	add ecx,1

neparni:

	cmp ecx,ebx
	je kraj
	sub eax,ecx
	add ecx,1
	jmp parni
	
kraj:
	pop ebp
	ret
