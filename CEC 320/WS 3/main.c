#include <stdio.h>
#include <stdint.h>
#include "arithmetic_n_print_dec.h"
#include "arithmetic_cflag_dec.h"

rcv_t rcv; 
int8_t x, y;
int N = 4;      // number of bits in a group

int main(void) { 

    x=0x38, y=0x29; // Addition should be 0x61 (with lower to upper carry)
    int8_t xpy = x_plus_y_two_group(&rcv, x, y, N);
    printf("Two-group hex addition 0x%X + 0x%X = 0x%X = %d\n", x, y, xpy, xpy);
    printf("Lower group to upper group carry is %d \n", rcv.c_f);

    x_plus_y(&rcv, x, y, 2*N);
    xpy = rcv.r_s;
    printf("Direct hex addition 0x%X + 0x%X = 0x%X = %d\n\n", x, y, xpy, xpy);
    
    x=0xCD, y=0x32; // Addition should be 0xFF (w/o lower to upper carry)
    xpy = x_plus_y_two_group(&rcv, x, y, N);
    printf("Two-group hex addition 0x%X + 0x%X = 0x%X = %d\n", x, y, xpy, xpy);
    printf("Lower group to upper group carry is %d \n", rcv.c_f);
    
    x_plus_y(&rcv, x, y, 2*N);
    xpy = rcv.r_s;
    printf("Direct hex addition 0x%X + 0x%X = 0x%X = %d\n\n", x, y, xpy, xpy);
    
    x=0x38, y=0x29; // Subtraction should be 0x0F (with lower to upper borrow)
    int8_t xmy = x_minus_y_two_group(&rcv, x, y, N);
    printf("Two-group hex subtrn 0x%X - 0x%X = 0x%X = %d\n", x, y, xmy, xmy);
    printf("Lower group to upper group borrow is %d \n", 1-rcv.c_f);

    x_minus_y(&rcv, x, y, 2*N);
    xmy = rcv.r_s;
    printf("Direct hex subtrn 0x%X - 0x%X = 0x%X = %d\n\n", x, y, xmy, xmy);
    
    x=0xCD, y=0x32; // Subtraction should be 0x9B (w/o lower to upper borrow)
    xmy = x_minus_y_two_group(&rcv, x, y, N);
    printf("Two-group hex subtrn 0x%X - 0x%X = 0x%X = %d\n", x, y, xmy, xmy);
    printf("Lower group to upper group carry is %d \n", rcv.c_f);
    
    x_minus_y(&rcv, x, y, 2*N);
    xmy = rcv.r_s;
    printf("Direct hex subtrn 0x%X - 0x%X = 0x%X = %d\n\n", x, y, xmy, xmy);
    
    while (1);
}
