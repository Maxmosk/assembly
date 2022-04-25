global _abs


section .text

_abs:
        fld     tword [rsp + 8]
        fabs

        ret

