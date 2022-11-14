	.file	"5.zad.cpp"
	.intel_syntax noprefix
	.section	.text$_ZN4BaseC2Ev,"x"
	.linkonce discard
	.align 2
	.globl	_ZN4BaseC2Ev
	.def	_ZN4BaseC2Ev;	.scl	2;	.type	32;	.endef
	.seh_proc	_ZN4BaseC2Ev
_ZN4BaseC2Ev:
.LFB16:
	push	rbp
	.seh_pushreg	rbp
	mov	rbp, rsp
	.seh_setframe	rbp, 0
	sub	rsp, 32
	.seh_stackalloc	32
	.seh_endprologue
	mov	QWORD PTR 16[rbp], rcx		//rcx je adresa objekta
	mov	rax, QWORD PTR 16[rbp]
	lea	rdx, _ZTV4Base[rip+16]		//postavljanje virtualne tablice za base
	mov	QWORD PTR [rax], rdx
	mov	rcx, QWORD PTR 16[rbp]
	call	_ZN4Base6metodaEv		//poziv metode
	nop
	add	rsp, 32
	pop	rbp
	ret
	.seh_endproc
	.section .rdata,"dr"
.LC0:
	.ascii "ja sam bazna implementacija!\0"
	.section	.text$_ZN4Base15virtualnaMetodaEv,"x"
	.linkonce discard
	.align 2
	.globl	_ZN4Base15virtualnaMetodaEv
	.def	_ZN4Base15virtualnaMetodaEv;	.scl	2;	.type	32;	.endef
	.seh_proc	_ZN4Base15virtualnaMetodaEv
_ZN4Base15virtualnaMetodaEv:
.LFB18:
	push	rbp
	.seh_pushreg	rbp
	mov	rbp, rsp
	.seh_setframe	rbp, 0
	sub	rsp, 32
	.seh_stackalloc	32
	.seh_endprologue
	mov	QWORD PTR 16[rbp], rcx
	lea	rcx, .LC0[rip]
	call	puts
	nop
	add	rsp, 32
	pop	rbp
	ret
	.seh_endproc
	.section .rdata,"dr"
.LC1:
	.ascii "Metoda kaze: \0"
	.section	.text$_ZN4Base6metodaEv,"x"
	.linkonce discard
	.align 2
	.globl	_ZN4Base6metodaEv
	.def	_ZN4Base6metodaEv;	.scl	2;	.type	32;	.endef
	.seh_proc	_ZN4Base6metodaEv
_ZN4Base6metodaEv:
.LFB19:
	push	rbp
	.seh_pushreg	rbp
	mov	rbp, rsp
	.seh_setframe	rbp, 0
	sub	rsp, 32
	.seh_stackalloc	32
	.seh_endprologue
	mov	QWORD PTR 16[rbp], rcx		//rcx je adresa objekta
	lea	rcx, .LC1[rip]
	call	printf
	mov	rax, QWORD PTR 16[rbp]		
	mov	rax, QWORD PTR [rax]		//u rax je sada adresa virtualne tablice
	mov	rax, QWORD PTR [rax]		//u rax je sad adresa metode
	mov	rcx, QWORD PTR 16[rbp]
	call	rax				//poziv metode iz virtualne tablice klase objekta
	nop
	add	rsp, 32
	pop	rbp
	ret
	.seh_endproc
	.section	.text$_ZN7DerivedC1Ev,"x"
	.linkonce discard
	.align 2
	.globl	_ZN7DerivedC1Ev
	.def	_ZN7DerivedC1Ev;	.scl	2;	.type	32;	.endef
	.seh_proc	_ZN7DerivedC1Ev
_ZN7DerivedC1Ev:
.LFB22:
	push	rbp
	.seh_pushreg	rbp
	mov	rbp, rsp
	.seh_setframe	rbp, 0
	sub	rsp, 32
	.seh_stackalloc	32
	.seh_endprologue
	mov	QWORD PTR 16[rbp], rcx
	mov	rax, QWORD PTR 16[rbp]
	mov	rcx, rax
	call	_ZN4BaseC2Ev
	mov	rax, QWORD PTR 16[rbp]
	lea	rdx, _ZTV7Derived[rip+16]
	mov	QWORD PTR [rax], rdx
	mov	rax, QWORD PTR 16[rbp]
	mov	rcx, rax
	call	_ZN4Base6metodaEv		//poziv bazne metode
	nop
	add	rsp, 32
	pop	rbp
	ret
	.seh_endproc
	.section .rdata,"dr"
	.align 8
.LC2:
	.ascii "ja sam izvedena implementacija!\0"
	.section	.text$_ZN7Derived15virtualnaMetodaEv,"x"
	.linkonce discard
	.align 2
	.globl	_ZN7Derived15virtualnaMetodaEv
	.def	_ZN7Derived15virtualnaMetodaEv;	.scl	2;	.type	32;	.endef
	.seh_proc	_ZN7Derived15virtualnaMetodaEv
_ZN7Derived15virtualnaMetodaEv:
.LFB23:
	push	rbp
	.seh_pushreg	rbp
	mov	rbp, rsp
	.seh_setframe	rbp, 0
	sub	rsp, 32
	.seh_stackalloc	32
	.seh_endprologue
	mov	QWORD PTR 16[rbp], rcx		//adresa objekta
	lea	rcx, .LC2[rip]
	call	puts				//ispis derived metode
	nop
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
.LFB24:
	push	rbp
	.seh_pushreg	rbp
	push	rsi
	.seh_pushreg	rsi
	push	rbx
	.seh_pushreg	rbx
	mov	rbp, rsp
	.seh_setframe	rbp, 0
	sub	rsp, 48
	.seh_stackalloc	48
	.seh_endprologue
	call	__main
	mov	ecx, 8 			//velièina virtualne tablice
.LEHB0:
	call	_Znwy			//stvaranje prvog objekta
.LEHE0:
	mov	rbx, rax		//rax je adresa objekta
	mov	rcx, rbx
.LEHB1:
	call	_ZN7DerivedC1Ev		//poziv konstruktora klase Derived
.LEHE1:
	mov	QWORD PTR -8[rbp], rbx
	mov	rax, QWORD PTR -8[rbp]
	mov	rcx, rax
.LEHB2:
	call	_ZN4Base6metodaEv	//poziva metodu
	mov	eax, 0
	jmp	.L10
.L9:
	mov	rsi, rax
	mov	rcx, rbx
	call	_ZdlPv
	mov	rax, rsi
	mov	rcx, rax
	call	_Unwind_Resume
.LEHE2:
.L10:
	add	rsp, 48
	pop	rbx
	pop	rsi
	pop	rbp
	ret
	.def	__gxx_personality_seh0;	.scl	2;	.type	32;	.endef
	.seh_handler	__gxx_personality_seh0, @unwind, @except
	.seh_handlerdata
.LLSDA24:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 .LLSDACSE24-.LLSDACSB24
.LLSDACSB24:
	.uleb128 .LEHB0-.LFB24
	.uleb128 .LEHE0-.LEHB0
	.uleb128 0
	.uleb128 0
	.uleb128 .LEHB1-.LFB24
	.uleb128 .LEHE1-.LEHB1
	.uleb128 .L9-.LFB24
	.uleb128 0
	.uleb128 .LEHB2-.LFB24
	.uleb128 .LEHE2-.LEHB2
	.uleb128 0
	.uleb128 0
.LLSDACSE24:
	.text
	.seh_endproc
	.globl	_ZTV7Derived
	.section	.rdata$_ZTV7Derived,"dr"
	.linkonce same_size
	.align 16
_ZTV7Derived:					//virtualna tablica klase Derived
	.quad	0
	.quad	_ZTI7Derived
	.quad	_ZN7Derived15virtualnaMetodaEv
	.globl	_ZTV4Base
	.section	.rdata$_ZTV4Base,"dr"
	.linkonce same_size
	.align 16
_ZTV4Base:					//virtualna tablica klase Base
	.quad	0
	.quad	_ZTI4Base
	.quad	_ZN4Base15virtualnaMetodaEv
	.globl	_ZTS7Derived
	.section	.rdata$_ZTS7Derived,"dr"
	.linkonce same_size
_ZTS7Derived:
	.ascii "7Derived\0"
	.globl	_ZTI7Derived
	.section	.rdata$_ZTI7Derived,"dr"
	.linkonce same_size
	.align 16
_ZTI7Derived:
	.quad	_ZTVN10__cxxabiv120__si_class_type_infoE+16
	.quad	_ZTS7Derived
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
	.def	puts;	.scl	2;	.type	32;	.endef
	.def	printf;	.scl	2;	.type	32;	.endef
	.def	_Znwy;	.scl	2;	.type	32;	.endef
	.def	_ZdlPv;	.scl	2;	.type	32;	.endef
	.def	_Unwind_Resume;	.scl	2;	.type	32;	.endef
