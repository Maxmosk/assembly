; Macro for end of C strings
%define        ENDS        0
; Macro for end of line aka '\n' in C
%define ENDL        10


global _start


extern printf
extern scanf


section .data
scanf_form      db      "%hd %hd %hd %hd", ENDS
printf_form     db      "%hd... %hd... %hd... %hd... I love marine corps!", ENDL, ENDS


section .bss
numbers resw    4


section .text
_start:
        ; scanf for 4 dec
        push    dword numbers + 6
        push    dword numbers + 4
        push    dword numbers + 2
        push    dword numbers
        push    dword scanf_form
        call    scanf
        add     esp,    20
        
        push    word [numbers + 6]
        push    ax
        push    word [numbers + 4]
        push    ax
        push    word [numbers + 2]
        push    ax
        push    word [numbers]
        push    dword printf_form
        call    printf
        add     esp,    12
        
        mov     eax,    1
        xor     ebx,    ebx
        int     0x80
