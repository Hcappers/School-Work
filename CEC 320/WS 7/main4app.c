#include <stdio.h>
#include <stdint.h>
#include "unity.h"
#include "hex_o.h"
#include "c_flag_n_shift.h"

void print_ASR_s(void) {
    int A = 0xFFFFFFF8;
    int B = A;
    for (int i = 0; i < 4; i++) {
        set_c_flag();
        B = rrx(B);
    }
    // prints original A and shifted B and their decimal values 
		printf("ASR to the right by 4 bits:\n");
		print_verbose_hex(A,32);
		printf(" ==> ");
		print_verbose_hex_newline(B,32);
		printf("Their values in dec: %d ==> %d\n\n", A,B); 
}

void print_LSR_s(void) {
    int A = 8;
    int B = A;
    for (int i = 0; i < 4; i++) {
        clear_c_flag();
        B = rrx(B);
    }
    // prints original A and shifted B and their decimal values 
		printf("ASR to the right by 4 bits:\n");
		print_verbose_hex(A,32);
		printf(" ==> ");
		print_verbose_hex_newline(B,32);
		printf("Their values in dec: %d ==> %d\n\n", A,B);
}


int main(void) {
    print_ASR_s();
    print_LSR_s();

    while (1);
}
