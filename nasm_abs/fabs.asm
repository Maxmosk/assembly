global _fabs


section .text

_fabs:
        pslld   xmm0,   1
        psrld   xmm0,   1

        ret

