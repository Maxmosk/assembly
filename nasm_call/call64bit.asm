; Macro for end of C strings
%define	ENDS	0
; Macro for end of line aka '\n' in C
%define	ENDL	10


default rel


global _start


extern printf
extern scanf


section .data
printf_form	db	"%hd... %hd... %hd... %hd... I love marine corps!", ENDL, ENDS
scanf_form	db	"%hd %hd %hd %hd", ENDS


section .bss
numbers	resw	4


section .text
_start:
	mov	rdi,	scanf_form
	lea	rsi,	[numbers]
	lea	rdx,	[numbers + 2]
	lea	rcx,	[numbers + 4]
	lea	r8,	[numbers + 6]
	call	scanf
	
	mov	rdi,	printf_form
	mov	si,	[numbers]
	mov	dx,	[numbers + 2]
	mov	cx,	[numbers + 4]
	mov	r8w,	[numbers + 6]
	call	printf

	mov	rax,	0x3c
	xor	rdi,	rdi
        syscall

