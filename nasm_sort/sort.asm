section .text

; =========================================================
; Function for bubble sortit of array fo 8-byte integers
; Params:
; rdi - start addres
; rsi - size of array in elements
; =========================================================
sort:
        .do_while:                  ; start of sorting cicle
        mov     rax,    0x1         ; set flag of unsorted array
        xor     rcx,    rcx         ; set counter to start
        
        test    rax,    rax
        jz      .do_while

; =========================================================

