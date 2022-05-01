global _fabs


section .text

; ======================================
; Calculate absolute value of double floating point number
; PARAMS
; xmm0 - number
; RETURN
; xmm0 - fabs(number)
; ======================================
_fabs:
        pslld   xmm0,   1
        psrld   xmm0,   1

        ret

