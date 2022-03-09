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
        mov     rsi,    rdi             ; string pointer for outing
        mov     rdi,    1               ; stdout descriptor
        mov     rdx,    rax             ; number of symbols in string
        mov     rax,    rdi             ; code of system call write (1)
        syscall


        ret
;-------------------------------------------------------------------------------
