.include "o/libc/nt/codegen.inc"
.imp	kernel32,__imp_CreateThread,CreateThread,0

	.text.windows
__CreateThread:
	push	%rbp
	mov	%rsp,%rbp
	.profilable
	mov	__imp_CreateThread(%rip),%rax
	jmp	__sysv2nt6
	.endfn	__CreateThread,globl
	.previous
