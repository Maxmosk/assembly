;section .data
;msg:    db      "Fisting", 0
;m       db      "dddddddd"

section .text
;global _start
;_start:
;        mov     rdi,    msg
;        mov     rsi,    m
;        mov     rdx,    5
;        call    string_copy
;        nop
;-------------------------------------------------------------------------------
; get LENGTH of STR
; ==================
; Params:
; rdi = STR (address)
; ==================
; Return:
; rax = LENGTH
; ==================
string_length:
        xor     rax,    rax             ; rax = 0
        
        .while:                         ; while ([rdi] = 0x00)
                                        ; {
                inc     rax             ; inc counter of symbols
                mov     dl,     [rdi]   ; get byte by counter address
                inc     rdi             ; to next symbol
                test    dl,     dl      ; test dl on zero value
        jnz     .while                  ; }

        dec     rax                     ; return on spare count
        

        ret
;-------------------------------------------------------------------------------



;-------------------------------------------------------------------------------
; print STR to stdout
; ==================
; Params:
; rdi = STR (address)
; ==================
print_string:
        push    rdi                     ; save caller-saved
        call    string_length           ; get length of STR to rax
        pop     rdi                     ; restore caller-saved

        ; preparing to syscall
        mov     rdx,    rax             ; number of symbols in string
        mov     rsi,    rdi             ; string pointer for outputing
        mov     rdi,    1               ; stdout descriptor
        mov     rax,    rdi             ; code of system call write (1)
        syscall


        ret
;-------------------------------------------------------------------------------


;-------------------------------------------------------------------------------
; print CHAR to stdout
; ==================
; Params:
; dil = CHAR (address)
; ==================
print_char:

        ; preparing to syscall
        mov     rax,    1               ; code of system call write (1)
        mov     rdx,    rax             ; number of symbols in string
        lea     rsi,    [rsp - 1]       ; string pointer for outputing
        mov     [rsi],  dil             ; local var with CHAR
        mov     rdi,    rax             ; stdout descriptor
        syscall


        ret
;-------------------------------------------------------------------------------


;-------------------------------------------------------------------------------
; print NEW LINE symbol to stdout
print_newline:
        mov     dil,    0x0A            ; code of new line symbol
        call    print_char              ; print this code


        ret
;-------------------------------------------------------------------------------


;-------------------------------------------------------------------------------
; print UINT as unsigned to stdout
; Params:
; rdi = UINT
; ==================
print_uint:
        push    rbp                             ; saving callee-saved
        mov     rbp,    rsp                     ; saving callee-saved
        
        ; make string from 1st param
        ;------------------------------
        mov     rax,    rdi             ; move 1st param to rax to div it
        mov     ecx,    10              ; move 10 to ecx for division on ecx
        mov     r8b,    '0'             ; shift for chars
        lea     rdi,    [rsp - 1]       ; address of last dighit in string
        mov     [rdi],      byte 0      ; move zero to terminate string


        .next_dighit:                   ; while rax != 0
                xor     rdx,    rdx     ; reset to zero higher qword of divisible
                dec     rdi             ; go to real last element of string
                div     rcx             ; division on rcx
                add     dl,     r8b     ; shift number to get char dighit
                mov     [rdi],  dl      ; move new dighit to end of string

        test    rax,    rax
        jnz     .next_dighit            ; to next dighit if rax != 0
        ;------------------------------
        mov     rsp,    rdi

        call    print_string            ; print string from stack

        mov     rsp,    rbp             ; restoring callee-saved
        pop     rbp                     ; restoring callee-saved
        ret
;-------------------------------------------------------------------------------


;-------------------------------------------------------------------------------
; print INT as signed to stdout
; Params:
; rdi = INT
; ==================
print_int:
        ; if 1st param > 0
        test    rdi,    rdi             ; get sign to SF
        jl      .neg_case               ; go to else (SF != 0F)

        ; then
        ;------------------------------
                call    print_uint      ; print as usual uint
                ret
        ;------------------------------

        ; else
        ;------------------------------
        .neg_case:
                push    rdi             ; save caller-saved

                mov     dil,    '-'     ; param for print_char
                call    print_char      ; print sign

                pop     rdi             ; restore caller-saved

                neg     rdi             ; abs of rdi
                call    print_uint      ; print rdi as uint
        ;------------------------------


        ret
;-------------------------------------------------------------------------------


;-------------------------------------------------------------------------------
; copy STR to MEM with length limited by N
; ==================
; Params:
; rdi = STR (address)
; rsi = MEM (address)
; rdx = N (uint)
; ==================
; Return:
; rax = STR if length of STR less then N or 0 in all else
; ==================
string_copy:
        ; get length of source string by existing function and compare with max
        ;------------------------------
        push    rsi                     ; saving caller-saved
        push    rdi
        push    rdx

        call    string_length           ; get length to rax

        pop     rdx                     ; restoring caller-saved
        pop     rdi
        pop     rsi


        cmp     rax,    rdx             ; if length is more then maximal
        jae     .longer                 ; go to returning zero
        ;------------------------------


        mov     rax,    rsi             ; good case return value

        ; copy string
        ;------------------------------
        .while:                         ; while ([rdi] = 0x00)
                                        ; {
                mov     cl,     [rdi]   ; get byte from scource memory
                mov     [rsi],  cl      ; set byte in return memory

                inc     rdi             ; to next symbol
                inc     rsi             ;

                test    cl,     cl      ; test dl on zero value
        jnz     .while                  ; }
        ;------------------------------
        ret
        

        .longer:                        ; case of string of overlength
                xor     rax,    rax     ; null return value
                ret
;-------------------------------------------------------------------------------
