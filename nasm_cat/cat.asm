global _start


section .text

; read bytes from srdin and write to stdout
_start:
        ; common paramters of syscalls
        lea     rsi,    [rsp - 1]       ; buffer address
        mov     edx,    1               ; size of buffer


        .read_again:
                xor     rdi,    rdi     ; 1 to 0 fd
                xor     rax,    rax     ; code of read syscall
                syscall                 ; read 1 byte from stdin to buffer in stack

                ; end reading of bytes if was error or EOF
                cmp     rax,    rdx
                jne     .end_reading


                inc     rdi
                ;inc     rax
                syscall                 ; write 1 byte to stdout from buffer in stack
        cmp     rax,    rdx
        je      .read_again
        .end_reading:


        ; exit with code 1 if was error in read or write
        test    rax,    rax
        jz      .done
                mov     rdi,    1
                call    exit
        .done:
        
        ; exit with code 0 if all is OK
        mov     rdi,    0
        call    exit 


; exit from process with code in rdi register
exit:
        mov     rax,    0x3c
        syscall

