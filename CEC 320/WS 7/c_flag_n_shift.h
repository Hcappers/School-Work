#ifndef __C_FLAG_N_SHIFT_H
#define __C_FLAG_N_SHIFT_H

#ifdef __cplusplus
extern "C" {
#endif

////////////////////////////////////////////////
#include <stdint.h>
#include <stdio.h>

// Set the C flag to 1
void set_c_flag(void);
// Clear the C flag to 0
void clear_c_flag(void);
// Read the C flag to an int
int read_c_flag(void);
// Rotate A as if using RRX
// Need to set C flag first; C flag will not change
uint32_t rrx(uint32_t A);
// Rotate A as if is using RRXS.  
// Need to set C flag first; C flag will not change
uint32_t rrxs(uint32_t A);
// Rotate right by n bits w/o using the ROR instruction
// n is between 0 and 32. 
uint32_t rors_func(uint32_t A, int n);

////////////////////////////////////////////////

#ifdef __cplusplus
}
#endif

#endif /* __C_FLAG_N_SHIFT_H */
