	.file	"file.cpp"
	.intel_syntax
	.section	.gnu.linkonce.t._ZN9CoolClass3setEi,"ax",@progbits
	.align 2
	.p2align 4,,15
	.weak	_ZN9CoolClass3setEi
	.type	_ZN9CoolClass3setEi, @function
_ZN9CoolClass3setEi:
.LFB3:
	push	%ebp
.LCFI0:
	mov	%ebp, %esp
.LCFI1:
	mov	%edx, DWORD PTR [%ebp+8]
	mov	%eax, DWORD PTR [%ebp+12]
	mov	DWORD PTR [%edx+4], %eax
	pop	%ebp
	ret
.LFE3:
	.size	_ZN9CoolClass3setEi, .-_ZN9CoolClass3setEi
.globl __gxx_personality_v0
	.section	.gnu.linkonce.t._ZN9CoolClass3getEv,"ax",@progbits
	.align 2
	.p2align 4,,15
	.weak	_ZN9CoolClass3getEv
	.type	_ZN9CoolClass3getEv, @function
_ZN9CoolClass3getEv:
.LFB4:
	push	%ebp
.LCFI2:
	mov	%ebp, %esp
.LCFI3:
	mov	%eax, DWORD PTR [%ebp+8]
	mov	%eax, DWORD PTR [%eax+4]
	pop	%ebp
	ret
.LFE4:
	.size	_ZN9CoolClass3getEv, .-_ZN9CoolClass3getEv
	.section	.gnu.linkonce.t._ZN13PlainOldClass3setEi,"ax",@progbits
	.align 2
	.p2align 4,,15
	.weak	_ZN13PlainOldClass3setEi
	.type	_ZN13PlainOldClass3setEi, @function
_ZN13PlainOldClass3setEi:
.LFB5:
	push	%ebp
.LCFI4:
	mov	%ebp, %esp
.LCFI5:
	mov	%edx, DWORD PTR [%ebp+8]
	mov	%eax, DWORD PTR [%ebp+12]
	mov	DWORD PTR [%edx], %eax
	pop	%ebp
	ret
.LFE5:
	.size	_ZN13PlainOldClass3setEi, .-_ZN13PlainOldClass3setEi
	.section	.gnu.linkonce.t._ZN4BaseC2Ev,"ax",@progbits
	.align 2
	.p2align 4,,15
	.weak	_ZN4BaseC2Ev
	.type	_ZN4BaseC2Ev, @function
_ZN4BaseC2Ev:
.LFB10:
	push	%ebp
.LCFI6:
	mov	%ebp, %esp
.LCFI7:
	mov	%edx, OFFSET FLAT:_ZTV4Base+8
	mov	%eax, DWORD PTR [%ebp+8]
	mov	DWORD PTR [%eax], %edx
	pop	%ebp
	ret
.LFE10:
	.size	_ZN4BaseC2Ev, .-_ZN4BaseC2Ev
	.section	.gnu.linkonce.t._ZN9CoolClassC1Ev,"ax",@progbits
	.align 2
	.p2align 4,,15
	.weak	_ZN9CoolClassC1Ev
	.type	_ZN9CoolClassC1Ev, @function
_ZN9CoolClassC1Ev:
.LFB13:
	push	%ebp
.LCFI8:
	mov	%ebp, %esp
.LCFI9:
	sub	%esp, 8
.LCFI10:
	mov	%eax, DWORD PTR [%ebp+8]
	mov	DWORD PTR [%esp], %eax
	call	_ZN4BaseC2Ev
	mov	%edx, OFFSET FLAT:_ZTV9CoolClass+8
	mov	%eax, DWORD PTR [%ebp+8]
	mov	DWORD PTR [%eax], %edx
	leave
	ret
.LFE13:
	.size	_ZN9CoolClassC1Ev, .-_ZN9CoolClassC1Ev
	.text
	.align 2
	.p2align 4,,15
.globl main
	.type	main, @function
main:
.LFB7:
	lea	%ecx, [%esp+4]
.LCFI11:
	and	%esp, -16
	push	DWORD PTR [%ecx-4]
.LCFI12:
	push	%ebp
.LCFI13:
	mov	%ebp, %esp
.LCFI14:
	push	%ebx
.LCFI15:
	push	%ecx
.LCFI16:
	sub	%esp, 32
.LCFI17:
	mov	DWORD PTR [%esp], 4
	call	_Znwj
	mov	DWORD PTR [%ebp-16], %eax
	mov	DWORD PTR [%esp], 8
	call	_Znwj
	mov	%ebx, %eax
	mov	DWORD PTR [%esp], %ebx
	call	_ZN9CoolClassC1Ev
	mov	DWORD PTR [%ebp-12], %ebx
	mov	DWORD PTR [%esp+4], 42
	mov	%eax, DWORD PTR [%ebp-16]
	mov	DWORD PTR [%esp], %eax
	call	_ZN13PlainOldClass3setEi
	mov	%eax, DWORD PTR [%ebp-12]
	mov	%eax, DWORD PTR [%eax]
	mov	%edx, DWORD PTR [%eax]
	mov	DWORD PTR [%esp+4], 42
	mov	%eax, DWORD PTR [%ebp-12]
	mov	DWORD PTR [%esp], %eax
	call	%edx
	mov	%eax, 0
	add	%esp, 32
	pop	%ecx
	pop	%ebx
	pop	%ebp
	lea	%esp, [%ecx-4]
	ret
.LFE7:
	.size	main, .-main
	.weak	_ZTV9CoolClass
	.section	.gnu.linkonce.r._ZTV9CoolClass,"a",@progbits
	.align 8
	.type	_ZTV9CoolClass, @object
	.size	_ZTV9CoolClass, 16
_ZTV9CoolClass:
	.long	0
	.long	_ZTI9CoolClass
	.long	_ZN9CoolClass3setEi
	.long	_ZN9CoolClass3getEv
	.weak	_ZTI9CoolClass
	.section	.gnu.linkonce.r._ZTI9CoolClass,"a",@progbits
	.align 4
	.type	_ZTI9CoolClass, @object
	.size	_ZTI9CoolClass, 12
_ZTI9CoolClass:
	.long	_ZTVN10__cxxabiv120__si_class_type_infoE+8
	.long	_ZTS9CoolClass
	.long	_ZTI4Base
	.weak	_ZTS9CoolClass
	.section	.gnu.linkonce.r._ZTS9CoolClass,"a",@progbits
	.type	_ZTS9CoolClass, @object
	.size	_ZTS9CoolClass, 11
_ZTS9CoolClass:
	.string	"9CoolClass"
	.weak	_ZTI4Base
	.section	.gnu.linkonce.r._ZTI4Base,"a",@progbits
	.align 4
	.type	_ZTI4Base, @object
	.size	_ZTI4Base, 8
_ZTI4Base:
	.long	_ZTVN10__cxxabiv117__class_type_infoE+8
	.long	_ZTS4Base
	.weak	_ZTS4Base
	.section	.gnu.linkonce.r._ZTS4Base,"a",@progbits
	.type	_ZTS4Base, @object
	.size	_ZTS4Base, 6
_ZTS4Base:
	.string	"4Base"
	.weak	_ZTV4Base
	.section	.gnu.linkonce.r._ZTV4Base,"a",@progbits
	.align 8
	.type	_ZTV4Base, @object
	.size	_ZTV4Base, 16
_ZTV4Base:
	.long	0
	.long	_ZTI4Base
	.long	__cxa_pure_virtual
	.long	__cxa_pure_virtual
	.section	.eh_frame,"a",@progbits
.Lframe1:
	.long	.LECIE1-.LSCIE1
.LSCIE1:
	.long	0x0
	.byte	0x1
	.string	"zP"
	.uleb128 0x1
	.sleb128 -4
	.byte	0x8
	.uleb128 0x5
	.byte	0x0
	.long	__gxx_personality_v0
	.byte	0xc
	.uleb128 0x4
	.uleb128 0x4
	.byte	0x88
	.uleb128 0x1
	.align 4
.LECIE1:
.LSFDE11:
	.long	.LEFDE11-.LASFDE11
.LASFDE11:
	.long	.LASFDE11-.Lframe1
	.long	.LFB7
	.long	.LFE7-.LFB7
	.uleb128 0x0
	.byte	0x4
	.long	.LCFI11-.LFB7
	.byte	0xc
	.uleb128 0x1
	.uleb128 0x0
	.byte	0x9
	.uleb128 0x4
	.uleb128 0x1
	.byte	0x4
	.long	.LCFI12-.LCFI11
	.byte	0xc
	.uleb128 0x4
	.uleb128 0x4
	.byte	0x4
	.long	.LCFI13-.LCFI12
	.byte	0xe
	.uleb128 0x8
	.byte	0x85
	.uleb128 0x2
	.byte	0x4
	.long	.LCFI14-.LCFI13
	.byte	0xd
	.uleb128 0x5
	.byte	0x4
	.long	.LCFI16-.LCFI14
	.byte	0x84
	.uleb128 0x4
	.byte	0x83
	.uleb128 0x3
	.align 4
.LEFDE11:
	.ident	"GCC: (GNU) 4.2.1 20070719  [FreeBSD]"
