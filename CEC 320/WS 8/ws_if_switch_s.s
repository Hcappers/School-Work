 AREA bitwiselogic, CODE

                EXPORT ws_acrl_cmp_s
				EXPORT ws_acrl_cex_s
                EXPORT ws_dcrl_orr_s
                EXPORT ws_dcrl_and_s

                ALIGN


; The if-else-if-else statement------------------
; int ws_acrl_c(int x) {
;     if (x < 0) {
;         x = 0;
;     } else if (x >= 8) { // else if 1
;         x = 8;
;     }
;     return x;  
; }
; int ws_acrl_cmp_s(int x);
ws_acrl_cmp_s   PROC 
                CMP r0, #0 
                BGE acrl_else_ifcmp 	;Bxx acrl_else_ifcmp
acrl_then_cmp   	MOV r0, #0 
				B   acrl_end_cmp
acrl_else_ifcmp CMP r0, #8
                BLT acrl_end_cmp	;Byy acrl_end_cmp
					MOV r0, #8	
acrl_end_cmp    BX  lr
                ENDP 

; int ws_acrl_cex_s(int x);
ws_acrl_cex_s   PROC 
                CMP r0, #0 
				BLT acrl_then_cex
acrl_else_ifcex CMP r0, #8
                BGE acrl_then_ifcex
				B   acrl_end_cex
acrl_then_cex   	MOV r0, #0
				B 	acrl_end_cex
acrl_then_ifcex		MOV r0, #8
				B   acrl_end_cex
acrl_end_cex    BX  lr
                ENDP 

; Compound if-else statements--------------------

; int ws_dcrl_orr_s(int x);
ws_dcrl_orr_s   PROC 
                CMP r0, #0 
				BLT dcrl_orr_then
                ;Bxx dcrl_orr_then
                CMP r0, #8
				BLT dcrl_orr_else
                ;Bxx dcrl_orr_else
dcrl_orr_then   LDR r0, =0    ;...
                B   dcrl_orr_end
dcrl_orr_else   LDR r0, =1     ;...
dcrl_orr_end    BX  lr
                ENDP 

; int ws_dcrl_and_s(int x);
ws_dcrl_and_s   PROC 
                CMP r0, #0 
                BLT dcrl_and_else	;Bxx dcrl_and_else
                CMP r0, #8
                BGE dcrl_and_else	;Byy dcrl_and_else
dcrl_and_then   LDR r0, =1	;...
                B   dcrl_and_end
dcrl_and_else   LDR r0, =0	;...
dcrl_and_end    BX  lr
                ENDP 


                END

