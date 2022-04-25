global _abs, _add


section .text

_abs:
        fld     qword [rsp + 8]
        fabs

        ret


_add:
        mov     rax,    xmm0
        mov     [rsp - 8],  xmm0
        mov     [rsp - 16],  xmm1
        
        fld     qword [rsp - 8]
        fld     qword [rsp - 16]

        faddp
        

        fstp    [rsp - 8]
        mov     [rsp - 8],  xmm0

        ret

