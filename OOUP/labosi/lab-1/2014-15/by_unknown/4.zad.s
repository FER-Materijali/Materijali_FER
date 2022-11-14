	.file	"4.zad.cpp"
	.intel_syntax noprefix
	.section	.text$_ZN9CoolClass3setEi,"x"
	.linkonce discard
	.align 2
	.globl	_ZN9CoolClass3setEi
	.def	_ZN9CoolClass3setEi;	.scl	2;	.type	32;	.endef
	.seh_proc	_ZN9CoolClass3setEi
_ZN9CoolClass3setEi:
.LFB0:
	push	rbp
	.seh_pushreg	rbp
	mov	rbp, rsp
	.seh_setframe	rbp, 0
	.seh_endprologue
	mov	QWORD PTR 16[rbp], rcx			//u rcx se nalazi adresa objekta klase CoolClass
	mov	DWORD PTR 24[rbp], edx
	mov	rax, QWORD PTR 16[rbp]
	mov	edx, DWORD PTR 24[rbp]
	mov	DWORD PTR 8[rax], edx			//vrijednost _x se nalazi u edx i stavljamo ju na adresu rax+8 (moglo je biti i rcx+8)
	pop	rbp
	ret
	.seh_endproc
	.section	.text$_ZN9CoolClass3getEv,"x"
	.linkonce discard
	.align 2
	.globl	_ZN9CoolClass3getEv
	.def	_ZN9CoolClass3getEv;	.scl	2;	.type	32;	.endef
	.seh_proc	_ZN9CoolClass3getEv
_ZN9CoolClass3getEv:
.LFB1:
	push	rbp
	.seh_pushreg	rbp
	mov	rbp, rsp
	.seh_setframe	rbp, 0
	.seh_endprologue
	mov	QWORD PTR 16[rbp], rcx			//u rcx se nalazi adresa od objekta klase CoolClass
	mov	rax, QWORD PTR 16[rbp]
	mov	eax, DWORD PTR 8[rax]			//na adresi objekta+8 (rax+8) se nalazi _x (moglo je biti i rcx+8)
	pop	rbp
	ret
	.seh_endproc
	.section	.text$_ZN13PlainOldClass3setEi,"x"
	.linkonce discard
	.align 2
	.globl	_ZN13PlainOldClass3setEi
	.def	_ZN13PlainOldClass3setEi;	.scl	2;	.type	32;	.endef
	.seh_proc	_ZN13PlainOldClass3setEi
_ZN13PlainOldClass3setEi:
.LFB2:
	push	rbp
	.seh_pushreg	rbp
	mov	rbp, rsp
	.seh_setframe	rbp, 0
	.seh_endprologue
	mov	QWORD PTR 16[rbp], rcx 			//rcx ima adresu _x iz poc
	mov	DWORD PTR 24[rbp], edx
	mov	rax, QWORD PTR 16[rbp]			//rax ima adresu _x iz poc
	mov	edx, DWORD PTR 24[rbp]
	mov	DWORD PTR [rax], edx			//broj 42 iz rdx stavljamo na adresu od _x
	pop	rbp
	ret
	.seh_endproc
	.section	.text$_ZN4BaseC2Ev,"x"
	.linkonce discard
	.align 2
	.globl	_ZN4BaseC2Ev
	.def	_ZN4BaseC2Ev;	.scl	2;	.type	32;	.endef
	.seh_proc	_ZN4BaseC2Ev
_ZN4BaseC2Ev:
.LFB7:
	push	rbp
	.seh_pushreg	rbp
	mov	rbp, rsp
	.seh_setframe	rbp, 0
	.seh_endprologue
	mov	QWORD PTR 16[rbp], rcx
	mov	rax, QWORD PTR 16[rbp]
	lea	rdx, _ZTV4Base[rip+16]
	mov	QWORD PTR [rax], rdx
	pop	rbp
	ret
	.seh_endproc
	.section	.text$_ZN9CoolClassC1Ev,"x"
	.linkonce discard
	.align 2
	.globl	_ZN9CoolClassC1Ev
	.def	_ZN9CoolClassC1Ev;	.scl	2;	.type	32;	.endef
	.seh_proc	_ZN9CoolClassC1Ev
_ZN9CoolClassC1Ev:
.LFB10:
	push	rbp
	.seh_pushreg	rbp
	mov	rbp, rsp
	.seh_setframe	rbp, 0
	sub	rsp, 32
	.seh_stackalloc	32
	.seh_endprologue
	mov	QWORD PTR 16[rbp], rcx		//rcx je adresa objekta CoolClass-a
	mov	rax, QWORD PTR 16[rbp]
	mov	rcx, rax
	call	_ZN4BaseC2Ev			//poziv baznog konstruktora
	mov	rax, QWORD PTR 16[rbp]
	lea	rdx, _ZTV9CoolClass[rip+16]	//stavlja adresu virtualne tablice CoolClass-a u rdx
	mov	QWORD PTR [rax], rdx		//sprema adresu virtualne tablice na prvo mjesto u objektu (adresa je u rax)
	add	rsp, 32
	pop	rbp
	ret
	.seh_endproc
	.def	__main;	.scl	2;	.type	32;	.endef
	.text
	.globl	main
	.def	main;	.scl	2;	.type	32;	.endef
	.seh_proc	main
main:
.LFB4:
	push	rbp
	.seh_pushreg	rbp
	push	rbx
	.seh_pushreg	rbx
	sub	rsp, 56
	.seh_stackalloc	56
	lea	rbp, 128[rsp]
	.seh_setframe	rbp, 128
	.seh_endprologue
	call	__main
	mov	ecx, 4
	call	_Znwy				//stvaranje prvog objekta
	mov	QWORD PTR -88[rbp], rax		//u rax je adresa od _x PlainOldClass-a 
	mov	ecx, 16
	call	_Znwy				// stvaranje drugog objekta tj. klase CoolClass => u rax stavlja njegovu adresu
	mov	rbx, rax
	mov	rcx, rbx
	call	_ZN9CoolClassC1Ev		//konstruktor CoolClass-a => poziv konstruktora plain klase ne postoji jer ne radi ništa pametno pa ga assembly ne prikaže
	mov	QWORD PTR -96[rbp], rbx		
	mov	rax, QWORD PTR -88[rbp]		//dajemo adresu _x iz PlainOldClass
	mov	edx, 42				//priprema broja 42 u data reg za stavljanje u plainOldClass
	mov	rcx, rax			//u rax je adresa objekta CoolClass-a
	call	_ZN13PlainOldClass3setEi	//poziv settera za PlainOldClass
	mov	rax, QWORD PTR -96[rbp]		//rbp-96 je adresa objekta CoolClass-a
	mov	rax, QWORD PTR [rax]		//u na prvom mjestu unutar objekta je adresa virtualne tablice CoolClass-a
	mov	rax, QWORD PTR [rax]		//na virtualnoj tablici na prvom mjestu (rax) se nalazi adresa settera za CoolClass
	mov	rcx, QWORD PTR -96[rbp]
	mov	edx, 42				//pripremamo 42 za spremanje u var _x CoolClass-a
	call	rax				//pozivamo setter cija je adresa u rax
	mov	eax, 0
	add	rsp, 56
	pop	rbx
	pop	rbp
	ret
	.seh_endproc
	.globl	_ZTV9CoolClass
	.section	.rdata$_ZTV9CoolClass,"dr"
	.linkonce same_size
	.align 32
_ZTV9CoolClass:						//virtualna tablica CoolClassa
	.quad	0
	.quad	_ZTI9CoolClass
	.quad	_ZN9CoolClass3setEi
	.quad	_ZN9CoolClass3getEv
	.globl	_ZTV4Base
	.section	.rdata$_ZTV4Base,"dr"
	.linkonce same_size
	.align 32
_ZTV4Base:						//virtualna tablica bazne klase
	.quad	0
	.quad	_ZTI4Base
	.quad	__cxa_pure_virtual
	.quad	__cxa_pure_virtual
	.globl	_ZTS9CoolClass
	.section	.rdata$_ZTS9CoolClass,"dr"
	.linkonce same_size
_ZTS9CoolClass:
	.ascii "9CoolClass\0"
	.globl	_ZTI9CoolClass
	.section	.rdata$_ZTI9CoolClass,"dr"
	.linkonce same_size
	.align 16
_ZTI9CoolClass:
	.quad	_ZTVN10__cxxabiv120__si_class_type_infoE+16
	.quad	_ZTS9CoolClass
	.quad	_ZTI4Base
	.globl	_ZTS4Base
	.section	.rdata$_ZTS4Base,"dr"
	.linkonce same_size
_ZTS4Base:
	.ascii "4Base\0"
	.globl	_ZTI4Base
	.section	.rdata$_ZTI4Base,"dr"
	.linkonce same_size
	.align 16
_ZTI4Base:
	.quad	_ZTVN10__cxxabiv117__class_type_infoE+16
	.quad	_ZTS4Base
	.ident	"GCC: (tdm64-2) 4.8.1"
	.def	_Znwy;	.scl	2;	.type	32;	.endef
	.def	__cxa_pure_virtual;	.scl	2;	.type	32;	.endef
