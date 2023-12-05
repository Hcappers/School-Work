#include "caesar_cipher_c.h"
#include <stdio.h>

int caesar_shift_c(uint8_t *text, int shift)
{
	if (shift < -100 || shift > 100) return -1;
	
		int i = 0;
		int bites = 0;
		
		shift = shift % 26;
	
		while (text[i] != 0) {
    if (text[i] >= 48 && text[i]<= 57) {
        
		}
		else{
			uint8_t character = text[i];
			character += shift;
        text[i] = character;
				bites++;
    }
    i++;
  }
  //printf("%s", text);
	return bites;
}
	
	
	
	
	
	
	
	

	
	
	
	
	
		
