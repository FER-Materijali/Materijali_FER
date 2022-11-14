	.file	"z4.cpp"
	.intel_syntax
	.section	.rodata
	.align 4
.LC0:
	.string	"ja sam izvedena implementacija!"
	.text
	.align 2
	.p2align 4,,15
	.type	_ZN35_GLOBAL__N_z4.cpp_00000000_401D50FC7Derived15virtualnaMetodaEv, @function
_ZN35_GLOBAL__N_z4.cpp_00000000_401D50FC7Derived15virtualnaMetodaEv:
.LFB11:
	push	%ebp
.LCFI0:
	mov	%ebp, %esp
.LCFI1:
	sub	%esp, 8
.LCFI2:
	mov	DWORD PTR [%esp], OFFSET FLAT:.LC0
	call	puts
	leave
	ret
.LFE11:
	.size	_ZN35_GLOBAL__N_z4.cpp_00000000_401D50FC7Derived15virtualnaMetodaEv, .-_ZN35_GLOBAL__N_z4.cpp_00000000_401D50FC7Derived15virtualnaMetodaEv
.globl __gxx_personality_v0
	.section	.rodata
.LC1:
	.string	"ja sam bazna implementacija!"
	.text
	.align 2
	.p2align 4,,15
	.type	_ZN35_GLOBAL__N_z4.cpp_00000000_401D50FC4Base15virtualnaMetodaEv, @function
_ZN35_GLOBAL__N_z4.cpp_00000000_401D50FC4Base15virtualnaMetodaEv:
.LFB6:
	push	%ebp
.LCFI3:
	mov	%ebp, %esp
.LCFI4:
	sub	%esp, 8
.LCFI5:
	mov	DWORD PTR [%esp], OFFSET FLAT:.LC1
	call	puts
	leave
	ret
.LFE6:
	.size	_ZN35_GLOBAL__N_z4.cpp_00000000_401D50FC4Base15virtualnaMetodaEv, .-_ZN35_GLOBAL__N_z4.cpp_00000000_401D50FC4Base15virtualnaMetodaEv
	.section	.rodata
.LC2:
	.string	"Metoda kaze: "
	.text
	.align 2
	.p2align 4,,15
	.type	_ZN35_GLOBAL__N_z4.cpp_00000000_401D50FC4Base6metodaEv, @function
_ZN35_GLOBAL__N_z4.cpp_00000000_401D50FC4Base6metodaEv:
.LFB7:
	push	%ebp
.LCFI6:
	mov	%ebp, %esp
.LCFI7:
	sub	%esp, 8
.LCFI8:
	mov	DWORD PTR [%ebp-4], %eax
	mov	DWORD PTR [%esp], OFFSET FLAT:.LC2
	call	printf
	mov	%eax, DWORD PTR [%ebp-4]
	mov	%eax, DWORD PTR [%eax]
	mov	%edx, DWORD PTR [%eax]
	mov	%eax, DWORD PTR [%ebp-4]
	mov	DWORD PTR [%esp], %eax
	call	%edx
	leave
	ret
.LFE7:
	.size	_ZN35_GLOBAL__N_z4.cpp_00000000_401D50FC4Base6metodaEv, .-_ZN35_GLOBAL__N_z4.cpp_00000000_401D50FC4Base6metodaEv
	.align 2
	.p2align 4,,15
	.type	_ZN35_GLOBAL__N_z4.cpp_00000000_401D50FC4BaseC2Ev, @function
_ZN35_GLOBAL__N_z4.cpp_00000000_401D50FC4BaseC2Ev:
.LFB4:
	push	%ebp
.LCFI9:
	mov	%ebp, %esp
.LCFI10:
	sub	%esp, 8
.LCFI11:
	mov	DWORD PTR [%ebp-4], %eax
	mov	%eax, OFFSET FLAT:_ZTVN35_GLOBAL__N_z4.cpp_00000000_401D50FC4BaseE+8
	mov	%edx, DWORD PTR [%ebp-4]
	mov	DWORD PTR [%edx], %eax
	mov	%eax, DWORD PTR [%ebp-4]
	call	_ZN35_GLOBAL__N_z4.cpp_00000000_401D50FC4Base6metodaEv
	leave
	ret
.LFE4:
	.size	_ZN35_GLOBAL__N_z4.cpp_00000000_401D50FC4BaseC2Ev, .-_ZN35_GLOBAL__N_z4.cpp_00000000_401D50FC4BaseC2Ev
	.align 2
	.p2align 4,,15
	.type	_ZN35_GLOBAL__N_z4.cpp_00000000_401D50FC7DerivedC1Ev, @function
_ZN35_GLOBAL__N_z4.cpp_00000000_401D50FC7DerivedC1Ev:
.LFB10:
	push	%ebp
.LCFI12:
	mov	%ebp, %esp
.LCFI13:
	sub	%esp, 8
.LCFI14:
	mov	DWORD PTR [%ebp-4], %eax
	mov	%eax, DWORD PTR [%ebp-4]
	call	_ZN35_GLOBAL__N_z4.cpp_00000000_401D50FC4BaseC2Ev
	mov	%edx, OFFSET FLAT:_ZTVN35_GLOBAL__N_z4.cpp_00000000_401D50FC7DerivedE+8
	mov	%eax, DWORD PTR [%ebp-4]
	mov	DWORD PTR [%eax], %edx
	mov	%eax, DWORD PTR [%ebp-4]
	call	_ZN35_GLOBAL__N_z4.cpp_00000000_401D50FC4Base6metodaEv
	leave
	ret
.LFE10:
	.size	_ZN35_GLOBAL__N_z4.cpp_00000000_401D50FC7DerivedC1Ev, .-_ZN35_GLOBAL__N_z4.cpp_00000000_401D50FC7DerivedC1Ev
.globl _Unwind_Resume
	.align 2
	.p2align 4,,15
	.type	_ZN35_GLOBAL__N_z4.cpp_00000000_401D50FC5main4Ev, @function
_ZN35_GLOBAL__N_z4.cpp_00000000_401D50FC5main4Ev:
.LFB12:
	push	%ebp
.LCFI15:
	mov	%ebp, %esp
.LCFI16:
	push	%ebx
.LCFI17:
	sub	%esp, 52
.LCFI18:
	mov	DWORD PTR [%esp], 4
.LEHB0:
	call	_Znwj
.LEHE0:
	mov	DWORD PTR [%ebp-24], %eax
	mov	%eax, DWORD PTR [%ebp-24]
.LEHB1:
	call	_ZN35_GLOBAL__N_z4.cpp_00000000_401D50FC7DerivedC1Ev
.LEHE1:
	mov	%eax, DWORD PTR [%ebp-24]
	mov	DWORD PTR [%ebp-8], %eax
	mov	%eax, DWORD PTR [%ebp-8]
.LEHB2:
	call	_ZN35_GLOBAL__N_z4.cpp_00000000_401D50FC4Base6metodaEv
	mov	%eax, 0
	mov	DWORD PTR [%ebp-28], %eax
	jmp	.L11
.L14:
	mov	DWORD PTR [%ebp-32], %eax
.L12:
	mov	%ebx, DWORD PTR [%ebp-32]
	mov	%eax, DWORD PTR [%ebp-24]
	mov	DWORD PTR [%esp], %eax
	call	_ZdlPv
	mov	DWORD PTR [%ebp-32], %ebx
	mov	%eax, DWORD PTR [%ebp-32]
	mov	DWORD PTR [%esp], %eax
	call	_Unwind_Resume
.LEHE2:
.L11:
	mov	%eax, DWORD PTR [%ebp-28]
	add	%esp, 52
	pop	%ebx
	pop	%ebp
	ret
.LFE12:
	.size	_ZN35_GLOBAL__N_z4.cpp_00000000_401D50FC5main4Ev, .-_ZN35_GLOBAL__N_z4.cpp_00000000_401D50FC5main4Ev
	.section	.gcc_except_table,"a",@progbits
.LLSDA12:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 .LLSDACSE12-.LLSDACSB12
.LLSDACSB12:
	.uleb128 .LEHB0-.LFB12
	.uleb128 .LEHE0-.LEHB0
	.uleb128 0x0
	.uleb128 0x0
	.uleb128 .LEHB1-.LFB12
	.uleb128 .LEHE1-.LEHB1
	.uleb128 .L14-.LFB12
	.uleb128 0x0
	.uleb128 .LEHB2-.LFB12
	.uleb128 .LEHE2-.LEHB2
	.uleb128 0x0
	.uleb128 0x0
.LLSDACSE12:
	.text
	.section	.rodata
	.align 8
	.type	_ZTVN35_GLOBAL__N_z4.cpp_00000000_401D50FC7DerivedE, @object
	.size	_ZTVN35_GLOBAL__N_z4.cpp_00000000_401D50FC7DerivedE, 12
_ZTVN35_GLOBAL__N_z4.cpp_00000000_401D50FC7DerivedE:
	.long	0
	.long	_ZTIN35_GLOBAL__N_z4.cpp_00000000_401D50FC7DerivedE
	.long	_ZN35_GLOBAL__N_z4.cpp_00000000_401D50FC7Derived15virtualnaMetodaEv
	.weak	_ZTIN35_GLOBAL__N_z4.cpp_00000000_401D50FC7DerivedE
	.section	.gnu.linkonce.r._ZTIN35_GLOBAL__N_z4.cpp_00000000_401D50FC7DerivedE,"a",@progbits
	.align 4
	.type	_ZTIN35_GLOBAL__N_z4.cpp_00000000_401D50FC7DerivedE, @object
	.size	_ZTIN35_GLOBAL__N_z4.cpp_00000000_401D50FC7DerivedE, 12
_ZTIN35_GLOBAL__N_z4.cpp_00000000_401D50FC7DerivedE:
	.long	_ZTVN10__cxxabiv120__si_class_type_infoE+8
	.long	_ZTSN35_GLOBAL__N_z4.cpp_00000000_401D50FC7DerivedE
	.long	_ZTIN35_GLOBAL__N_z4.cpp_00000000_401D50FC4BaseE
	.weak	_ZTSN35_GLOBAL__N_z4.cpp_00000000_401D50FC7DerivedE
	.section	.gnu.linkonce.r._ZTSN35_GLOBAL__N_z4.cpp_00000000_401D50FC7DerivedE,"a",@progbits
	.align 32
	.type	_ZTSN35_GLOBAL__N_z4.cpp_00000000_401D50FC7DerivedE, @object
	.size	_ZTSN35_GLOBAL__N_z4.cpp_00000000_401D50FC7DerivedE, 48
_ZTSN35_GLOBAL__N_z4.cpp_00000000_401D50FC7DerivedE:
	.string	"N35_GLOBAL__N_z4.cpp_00000000_401D50FC7DerivedE"
	.weak	_ZTIN35_GLOBAL__N_z4.cpp_00000000_401D50FC4BaseE
	.section	.gnu.linkonce.r._ZTIN35_GLOBAL__N_z4.cpp_00000000_401D50FC4BaseE,"a",@progbits
	.align 4
	.type	_ZTIN35_GLOBAL__N_z4.cpp_00000000_401D50FC4BaseE, @object
	.size	_ZTIN35_GLOBAL__N_z4.cpp_00000000_401D50FC4BaseE, 8
_ZTIN35_GLOBAL__N_z4.cpp_00000000_401D50FC4BaseE:
	.long	_ZTVN10__cxxabiv117__class_type_infoE+8
	.long	_ZTSN35_GLOBAL__N_z4.cpp_00000000_401D50FC4BaseE
	.weak	_ZTSN35_GLOBAL__N_z4.cpp_00000000_401D50FC4BaseE
	.section	.gnu.linkonce.r._ZTSN35_GLOBAL__N_z4.cpp_00000000_401D50FC4BaseE,"a",@progbits
	.align 32
	.type	_ZTSN35_GLOBAL__N_z4.cpp_00000000_401D50FC4BaseE, @object
	.size	_ZTSN35_GLOBAL__N_z4.cpp_00000000_401D50FC4BaseE, 45
_ZTSN35_GLOBAL__N_z4.cpp_00000000_401D50FC4BaseE:
	.string	"N35_GLOBAL__N_z4.cpp_00000000_401D50FC4BaseE"
	.section	.rodata
	.align 8
	.type	_ZTVN35_GLOBAL__N_z4.cpp_00000000_401D50FC4BaseE, @object
	.size	_ZTVN35_GLOBAL__N_z4.cpp_00000000_401D50FC4BaseE, 12
_ZTVN35_GLOBAL__N_z4.cpp_00000000_401D50FC4BaseE:
	.long	0
	.long	_ZTIN35_GLOBAL__N_z4.cpp_00000000_401D50FC4BaseE
	.long	_ZN35_GLOBAL__N_z4.cpp_00000000_401D50FC4Base15virtualnaMetodaEv
	.section	.eh_frame,"a",@progbits
.Lframe1:
	.long	.LECIE1-.LSCIE1
.LSCIE1:
	.long	0x0
	.byte	0x1
	.string	"zPL"
	.uleb128 0x1
	.sleb128 -4
	.byte	0x8
	.uleb128 0x6
	.byte	0x0
	.long	__gxx_personality_v0
	.byte	0x0
	.byte	0xc
	.uleb128 0x4
	.uleb128 0x4
	.byte	0x88
	.uleb128 0x1
	.align 4
.LECIE1:
.LSFDE1:
	.long	.LEFDE1-.LASFDE1
.LASFDE1:
	.long	.LASFDE1-.Lframe1
	.long	.LFB11
	.long	.LFE11-.LFB11
	.uleb128 0x4
	.long	0x0
	.byte	0x4
	.long	.LCFI0-.LFB11
	.byte	0xe
	.uleb128 0x8
	.byte	0x85
	.uleb128 0x2
	.byte	0x4
	.long	.LCFI1-.LCFI0
	.byte	0xd
	.uleb128 0x5
	.align 4
.LEFDE1:
.LSFDE3:
	.long	.LEFDE3-.LASFDE3
.LASFDE3:
	.long	.LASFDE3-.Lframe1
	.long	.LFB6
	.long	.LFE6-.LFB6
	.uleb128 0x4
	.long	0x0
	.byte	0x4
	.long	.LCFI3-.LFB6
	.byte	0xe
	.uleb128 0x8
	.byte	0x85
	.uleb128 0x2
	.byte	0x4
	.long	.LCFI4-.LCFI3
	.byte	0xd
	.uleb128 0x5
	.align 4
.LEFDE3:
.LSFDE5:
	.long	.LEFDE5-.LASFDE5
.LASFDE5:
	.long	.LASFDE5-.Lframe1
	.long	.LFB7
	.long	.LFE7-.LFB7
	.uleb128 0x4
	.long	0x0
	.byte	0x4
	.long	.LCFI6-.LFB7
	.byte	0xe
	.uleb128 0x8
	.byte	0x85
	.uleb128 0x2
	.byte	0x4
	.long	.LCFI7-.LCFI6
	.byte	0xd
	.uleb128 0x5
	.align 4
.LEFDE5:
.LSFDE7:
	.long	.LEFDE7-.LASFDE7
.LASFDE7:
	.long	.LASFDE7-.Lframe1
	.long	.LFB4
	.long	.LFE4-.LFB4
	.uleb128 0x4
	.long	0x0
	.byte	0x4
	.long	.LCFI9-.LFB4
	.byte	0xe
	.uleb128 0x8
	.byte	0x85
	.uleb128 0x2
	.byte	0x4
	.long	.LCFI10-.LCFI9
	.byte	0xd
	.uleb128 0x5
	.align 4
.LEFDE7:
.LSFDE9:
	.long	.LEFDE9-.LASFDE9
.LASFDE9:
	.long	.LASFDE9-.Lframe1
	.long	.LFB10
	.long	.LFE10-.LFB10
	.uleb128 0x4
	.long	0x0
	.byte	0x4
	.long	.LCFI12-.LFB10
	.byte	0xe
	.uleb128 0x8
	.byte	0x85
	.uleb128 0x2
	.byte	0x4
	.long	.LCFI13-.LCFI12
	.byte	0xd
	.uleb128 0x5
	.align 4
.LEFDE9:
.LSFDE11:
	.long	.LEFDE11-.LASFDE11
.LASFDE11:
	.long	.LASFDE11-.Lframe1
	.long	.LFB12
	.long	.LFE12-.LFB12
	.uleb128 0x4
	.long	.LLSDA12
	.byte	0x4
	.long	.LCFI15-.LFB12
	.byte	0xe
	.uleb128 0x8
	.byte	0x85
	.uleb128 0x2
	.byte	0x4
	.long	.LCFI16-.LCFI15
	.byte	0xd
	.uleb128 0x5
	.byte	0x4
	.long	.LCFI18-.LCFI16
	.byte	0x83
	.uleb128 0x3
	.align 4
.LEFDE11:
	.ident	"GCC: (GNU) 4.2.1 20070719  [FreeBSD]"
