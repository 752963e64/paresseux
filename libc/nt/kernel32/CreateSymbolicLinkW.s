.include "o/libc/nt/codegen.inc"
.imp	kernel32,__imp_CreateSymbolicLinkW,CreateSymbolicLinkW,0

	.text.windows
__CreateSymbolicLink:
	push	%rbp
	mov	%rsp,%rbp
	.profilable
	mov	__imp_CreateSymbolicLinkW(%rip),%rax
	jmp	__sysv2nt
	.endfn	__CreateSymbolicLink,globl
	.previous
