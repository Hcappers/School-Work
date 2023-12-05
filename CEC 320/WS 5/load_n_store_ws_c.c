#include "load_n_store_ws_c.h"

void init_mem(uint8_t *p) {
    for (int i = 0; i < 32; i++) {
        *p++ = 0x60 + (i << 1);
    }
}

// Store 8-bit numbers with post-indexed addressing.
void save_8_bit_signed_array_c(int8_t *p8s) {
    int i = 0; 
    *p8s++ = (int8_t)(++i*4 - 6);
    *p8s++ = (int8_t)(++i*4 - 6);
}

// Store 8-bit numbers with register offset-based addressing.
void save_8_bit_unsigned_array_c(uint8_t *p8u) {
    int i = 0; 
    *p8u++ = (uint8_t)(++i*4 - 6);
    *p8u++ = (uint8_t)(++i*4 - 6);
}

// Load, modify, and store 8-bit numbers.
void load_8_bit_signed_n_save_16_bit_array_c(int8_t *p8s, int16_t *p16s) {
    int i = 0; 
    p8s += 14;
    *(p16s + i++) = (int16_t)*++p8s;  
    *(p16s + i++) = (int16_t)*++p8s;  
} 

// Type cast pointers to 8-bit numbers.
void cast_8_bit_pointer_to_32_n_modify_memory_c(int8_t *p8s, int32_t *p32s) {
    p8s += 14;
    *p32s++ = ++*(int16_t *)p8s++;  
    *p32s++ = ++*(int16_t *)p8s++;  
} 
