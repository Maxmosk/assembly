; Macro for end of C strings
%define        ENDS        0
; Macro for end of line aka '\n' in C
%define ENDL        10


default rel


global _start


extern printf


section .data
printf_form     db      "Fisting", ENDL, ENDS


section .text
_start:
	mov	rdi,	printf_form
	call	printf	

	mov	rax,	0x3c
	xor	rdi,	rdi
        syscall
