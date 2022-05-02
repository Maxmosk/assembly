global _start


section .text

_start:
        ; common paramters of syscalls
        lea     rsi,    [rsp - 1]
        mov     rdx,    1


        .read_again:
                xor     rdi,    rdi     ; 1 to 0 fd
                xor     rax,    rax     ; code of read syscall
                syscall                 ; read 1 byte from stdin to buffer in stack

                inc     rdi
                inc     rax
                syscall
        cmp     rax,    rdx
        jz      .read_again
        
        test    rax,    rax
        jnz     .done
                mov     rdi,    1
                call    exit
        .done:
        
        mov     rdi,    0
        call    exit 


; exit from process with code in rdi register
exit:
        mov     rax,    0x3c
        syscall
