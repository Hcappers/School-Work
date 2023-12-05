#include <stdio.h>
#include <stdint.h>
#include "unity.h"
#include "binary_o.h"
#include "load_n_store_ws_c.h"
#include "load_n_store_ws_s.h"

uint8_t p1[32];
uint8_t p2[16];

int main(void) {
    // Store 8-bit numbers with post-indexed addressing.
    init_mem(p1);
    int8_t *p8s = (int8_t *)p1;
    save_8_bit_signed_array_c(p8s); 
    printf("Saved results of `save_8_bit_signed_array`: \n");
    printf("Signed 8-bit: 0x%02X and 0x%02X.\n", *p8s, *(p8s+1));

    // Store 8-bit numbers with register offset-based addressing.
    init_mem(p1);
    uint8_t *p8u = (uint8_t *)p1;
    save_8_bit_unsigned_array_c(p8u);  
    printf("Saved results of `save_8_bit_unsigned_array`: \n");
    printf("Unsigned 8-bit: 0x%02X and 0x%02X.\n", *p8u, *(p8u+1));
    
    // Load, modify, and store 8-bit numbers.
    init_mem(p1);
    int16_t *p16s = (int16_t *)p2;
    load_8_bit_signed_n_save_16_bit_array_c(p8s, p16s); 
    printf("Saved results of `load_8_bit_signed_n_save_16_bit_array`: \n");
    printf("Signed 16-bit: 0x%04X and 0x%04X.\n", *p16s, *(p16s+1));
    
    // Type cast pointers to 8-bit numbers.
    init_mem(p1);
    int32_t *p32s = (int32_t *)p2;
    printf("Saved results of `cast_8_bit_pointer_to_32_n_modify_memory`: \n");
    printf("8-bit mem b4 mod: 0x%02X and 0x%02X.\n", *(p8s+14), *(p8s+15));
    cast_8_bit_pointer_to_32_n_modify_memory_c(p8s, p32s); 
    printf("8-bit mem aft mod: 0x%02X and 0x%02X.\n", *(p8s+14), *(p8s+15));
    printf("Signed 32-bit: 0x%08X and 0x%08X.\n", *p32s, *(p32s+1));


    while (1);
}
