global _sort
extern printf

section .data
printf_spec:    db      "%d", 10, 0

section .text

; ==========================================================
; Function for bubble sortit of array fo 8-byte integers
; Params:
; rdi - start addres
; rsi - size of array in elements
; ==========================================================
_sort:
        .do_while:                                  ; start of sorting cycle
            mov     rax,    0x1                     ; set flag of unsorted array

            ; ==============================================
            xor     rcx,    rcx                     ; set counter to start
            .for:                                   ; cycle for sorting
                    mov     rdx,    [rdi + rcx * 8] ; get current number
                    push    rdi
                    push    rsi
                    push    rcx
                    push    rax
                    push    rdx

                    mov     rdi,    printf_spec
                    mov     rsi,    rdx
                    call    printf

                    pop     rdx
                    pop     rax
                    pop     rcx
                    pop     rsi
                    pop     rdi

            inc     rcx
            cmp     rcx,    rsi
            jl      .for                            ; next iteration if not ended array
            ; ==============================================

        test    rax,    rax                         ; return to start if not sorted
        jz      .do_while
        

        ret
; ==========================================================

