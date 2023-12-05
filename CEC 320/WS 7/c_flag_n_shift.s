                AREA c_flag_n_shift, CODE
        
                EXPORT set_c_flag
                EXPORT clear_c_flag
                EXPORT read_c_flag
                EXPORT rrx
                EXPORT rrxs
                EXPORT rors_func

                ALIGN

; void set_c_flag(void)
set_c_flag      PROC
                LDR   r0, =1
                LSRS  r0, #1
                BX    lr
                ENDP

; void clear_c_flag(void)
clear_c_flag    PROC
                LDR   r0, =0
                LSRS  r0, #1
                BX    lr
                ENDP

; Bits of APSR:
; 31, 30, 29, 28, 27:
;  N,  Z,  C,  V,  Q
; int read_c_flag(void)
read_c_flag     PROC
                MRS   r0, apsr
                LSR   r0, #29
                AND   r0, #1
                BX    lr
                ENDP

; uint32_t rrx(uint32_t A)
rrx             PROC
                RRX   r0, r0 
                BX    lr
                ENDP

; uint32_t rrxs(uint32_t A)
rrxs            PROC
                RRXS  r0, r0 
                BX    lr
                ENDP

; Rotate right by n bits w/o using the ROR instruction
; n is between 0 and 32. 
; uint32_t rors_func(uint32_t A, int n)
rors_func       PROC
				RSB   r2, r1, #32
				LSL   r3, r0, r2
				LSRS  r0, r1
				ADD   r0, r0, r3
                BX    lr
                ENDP

                END
