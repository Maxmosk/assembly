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
        xor     rax,    rax     ; rax = 0
        
        .while:                 ; while ([rdi] = 0x00)
                inc     rax     ; inc counter of symbols
                inc     rdi     ; to next symbol
        jnz     .while          ; while end


        ret
;-------------------------------------------------------------------------------
