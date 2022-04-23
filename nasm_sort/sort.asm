global sort


section .text

; ==========================================================
; Function for bubble sortit of array fo 8-byte integers
; Params:
; rdi - start addres
; rsi - size of array in elements
; ==========================================================
sort:
        test    rsi,    rsi             ; if size is zero, return from function
        jnz     .size_ok
        ret
        .size_ok:                       ; else execute sorting

        test    rdi,    rdi             ; if address if NULL-pointer, return
        jnz     .addr_ok
        ret
        .addr_ok:                       ; else execute sort


`       dec     rsi                     ; set last index of 1st element


        .do_while:                      ; start of sorting cycle
                mov     rax,    0x1     ; set flag of unsorted array


                ; ==============================================
                xor     rcx,    rcx     ; set counter to start
                .for:                   ; cycle for sorting
                        ; get current and next number
                        mov     rdx,    [rdi + rcx * 8]
                        mov     r8,     [rdi + 8 + rcx * 8]

                        ; swap elements if it is in reverse order
                        cmp     r8,     rdx
                        jae     .done_if
                                mov     [rdi + rcx * 8 + 8],    rdx
                                mov     [rdi + rcx * 8],    r8

                                ; set flag to not sorted
                                xor     rax,    rax
                        .done_if:

                inc     rcx
                cmp     rcx,    rsi
                jl      .for            ; next iteration if not ended array
                ; ==============================================

        test    rax,    rax             ; return to start if not sorted
        jz     .do_while
        

        ret
; ==========================================================

