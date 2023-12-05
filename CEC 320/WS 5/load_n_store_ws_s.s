                AREA bitwiselogic, CODE
        
                EXPORT save_8_bit_signed_array_s
                EXPORT save_8_bit_unsigned_array_s
                EXPORT load_8_bit_signed_n_save_16_bit_array_s
                EXPORT cast_8_bit_pointer_to_32_n_modify_memory_s

                ALIGN

; Store 8-bit numbers with post-indexed addressing.
; void save_8_bit_signed_array_c(int8_t *p8s) {
;     int i = 0; 
;     *p8s++ = (int8_t)(++i*4 - 6);
;     *p8s++ = (int8_t)(++i*4 - 6);
; }
; void save_8_bit_signed_array_s(int8_t *p8s);  
; r0 = p8s 
save_8_bit_signed_array_s PROC
				LDR r2, =0
				LDR r3, =6
				ADD r2, #1
				LSL r2, #2
				SUB r1, r2, r3
				STRB r1, [r0], #1
				
				LDR r2, =0
				LDR r3, =6
				ADD r2, #1
				LSL r2, #2
				SUB r1, r3, r2
				STRB r1, [r0], #1

                BX    lr
                ENDP

; Store 8-bit numbers with register offset-based addressing.
; void save_8_bit_unsigned_array_c(uint8_t *p8u) {
;     int i = 0; 
;     *p8u++ = (uint8_t)(++i*4 - 6);
;     *p8u++ = (uint8_t)(++i*4 - 6);
; }
; void save_8_bit_unsigned_array_s(uint8_t *p8u);  
; r0 = p8s 
save_8_bit_unsigned_array_s PROC
	
				LDR r2, =0
				ADD r2, #1
				LSL r2, #2
				SUB r1, r2, #6
				STRB r1, [r0]
				ADD r0, #1
				
				LDR r2, =0
				ADD r2, #1
				LSL r2, #2
				RSB r1, r2, #6
				STRB r1, [r0]
				ADD r0, #1

                BX    lr
                ENDP

                BX    lr
                ENDP

; Load, modify, and store 8-bit numbers.
; void load_8_bit_signed_n_save_16_bit_array_c(int8_t *p8s, int16_t *p16s) {
;     int i = 0; 
;     p8s += 14;
;     *(p16s + i++) = (int16_t)*++p8s;  
;     *(p16s + i++) = (int16_t)*++p8s;  
; } 
; void load_8_bit_signed_n_save_16_bit_array_s(int8_t *p8s, int16_t *p16s); 
; r0 = p8s, r1 = p16s 
load_8_bit_signed_n_save_16_bit_array_s PROC

                BX    lr
                ENDP

; Type cast pointers to 8-bit numbers.
; void cast_8_bit_pointer_to_32_n_modify_memory_c(int8_t *p8s, int32_t *p32s) {
;     p8s += 14;
;     *p32s++ = ++*(int16_t *)p8s++;  
;     *p32s++ = ++*(int16_t *)p8s++;  
; }
; void cast_8_bit_pointer_to_32_n_modify_memory_s(int8_t *p8s, int32_t *p32s); 
; r0 = p8s, r1 = p32s
cast_8_bit_pointer_to_32_n_modify_memory_s PROC

                BX    lr
                ENDP

                END
