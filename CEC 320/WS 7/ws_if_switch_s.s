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
                CMP r0, #0 			;sets up condition;
                BGE acrl_else_ifcmp ;if greater than->go to end;
acrl_then_cmp   	MOV r0, #0   	;if less than->set x to 0 and end;
				B   acrl_end_cmp
acrl_else_ifcmp CMP r0, #8 			;sets up new condition;
                BLT acrl_end_cmp	;if less then->go to end;
					MOV r0, #8		;if greater than->set x to 8 and end;
acrl_end_cmp    BX  lr
                ENDP 

; int ws_acrl_cex_s(int x);
ws_acrl_cex_s   PROC 				
                CMP r0, #0 			;sets up condition;
				BLT acrl_then_cex	;if less than->go to then block;
acrl_else_ifcex CMP r0, #8			;sets up new conditions;
                BGE acrl_then_ifcex	;if greater then->go to then-if block;
				B   acrl_end_cex	;go to end;
acrl_then_cex   	MOV r0, #0		;set x to 0;
				B 	acrl_end_cex	;go to end;
acrl_then_ifcex		MOV r0, #8		;set x to 8;
				B   acrl_end_cex	;go to end;
acrl_end_cex    BX  lr
                ENDP 

; Compound if-else statements--------------------

; int ws_dcrl_orr_s(int x);
ws_dcrl_orr_s   PROC 
                CMP r0, #0 
                ;Bxx dcrl_orr_then
                CMP r0, #8
                ;Bxx dcrl_orr_else
dcrl_orr_then        ;...
                B   dcrl_orr_end
dcrl_orr_else        ;...
dcrl_orr_end    BX  lr
                ENDP  

; int ws_dcrl_and_s(int x);
ws_dcrl_and_s   PROC 
                CMP r0, #0 
                ;Bxx dcrl_and_else
                CMP r0, #8
                ;Byy dcrl_and_else
dcrl_and_then   ;...
                B   dcrl_and_end
dcrl_and_else   ;...
dcrl_and_end    BX  lr
                ENDP 


                END
