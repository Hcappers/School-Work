#ifndef __LOAD_N_STORE_WS_S_H
#define __LOAD_N_STORE_WS_S_H

#ifdef __cplusplus
 extern "C" {
#endif /* __cplusplus */

#include <stdint.h>
#include <stdbool.h>

// Store 8-bit numbers with post-indexed addressing.
void save_8_bit_signed_array_s(int8_t *p8s);  
// Store 8-bit numbers with register offset-based addressing.
void save_8_bit_unsigned_array_s(uint8_t *p8u);  
// Load, modify, and store 8-bit numbers.
void load_8_bit_signed_n_save_16_bit_array_s(int8_t *p8s, int16_t *p16s); 
// Type cast pointers to 8-bit numbers.
void cast_8_bit_pointer_to_32_n_modify_memory_s(int8_t *p8s, int32_t *p32s); 

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* __LOAD_N_STORE_WS_S_H */
