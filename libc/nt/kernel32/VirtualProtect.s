.include "o/libc/nt/codegen.inc"
.imp	kernel32,__imp_VirtualProtect,VirtualProtect,0

	.text.windows
__VirtualProtect:
	push	%rbp
	mov	%rsp,%rbp
	.profilable
	mov	__imp_VirtualProtect(%rip),%rax
	jmp	__sysv2nt
	.endfn	__VirtualProtect,globl
	.previous
