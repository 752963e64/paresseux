.include "o/libc/nt/codegen.inc"
.imp	kernel32,__imp_FindClose,FindClose,0

	.text.windows
__FindClose:
	push	%rbp
	mov	%rsp,%rbp
	.profilable
	mov	%rdi,%rcx
	sub	$32,%rsp
	call	*__imp_FindClose(%rip)
	leave
	ret
	.endfn	__FindClose,globl
	.previous
