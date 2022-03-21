global factorial


section .text

;-------------------------------------------------------------------------------
; calculate FACTORIAL of N
; ==================
; Params:
; rdi = N (uint64)
; ==================
; Return:
; rax = FACTORIAL
; ==================
factorial:
	push  	rdx			; save callee-saved

	mov 	rax,	rdi		; move to rax for multiplication
	dec 	rdi			; get next number because N yet in rax

	; for rdi = n-1..1
	;------------------------------
	for_fact:			; {
		mul    	rdi		; calculate on this step
		dec 	rdi		; to next number

	test  	rdi,	rdi
	jnz  	for_fact		; }
	;------------------------------


	pop  	rdx			; restore calle-saved

	ret
;-------------------------------------------------------------------------------
