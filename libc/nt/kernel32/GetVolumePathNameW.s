.include "o/libc/nt/codegen.inc"
.imp	kernel32,__imp_GetVolumePathNameW,GetVolumePathNameW,0

	.text.windows
GetVolumePathName:
	push	%rbp
	mov	%rsp,%rbp
	.profilable
	mov	__imp_GetVolumePathNameW(%rip),%rax
	jmp	__sysv2nt
	.endfn	GetVolumePathName,globl
	.previous
