global _solver

section .data
flt:    dt  0.1


section .text

_solver:
        fld     tword [rbp + 10]
        fld     tword [rbp + 20]
        fadd
        fld1
        fwait


        ret

