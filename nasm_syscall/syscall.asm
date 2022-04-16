global __syscall__


; Function for system calls in x86_64 linux systems
__syscall__:
        ; Saving registers, that can be killed by syscall
        push    rcx
        push    r11

        ; Moving params to registers for system calls
        mov     rax,    rdi
        mov     rdi,    rsi
        mov     rsi,    rdx
        mov     rdx,    rcx
        mov     r10,    r8
        mov     r8,     r9
        mov     r9,     [rsp + 8]
        syscall

        ; Recovering registers, that can be killed by syscall
        pop     r11
        pop     rcx

        ret
