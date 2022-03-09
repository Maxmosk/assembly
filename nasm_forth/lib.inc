section .text
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
        mov     [rsp - 1],      dil     ; local var with CHAR

        ; preparing to syscall
        mov     rax,    1               ; code of system call write (1)
        mov     rdx,    rax             ; number of symbols in string
        mov     rdi,    rax             ; stdout descriptor
        mov     rsi,    rsp             ; string pointer for outputing
        dec     rsi                     ; moving pointer to 1st byte in red-zone
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
