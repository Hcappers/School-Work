#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include "arm_math.h"

#define N 10 

float f[N];         // values in float
q31_t vq31[N];      // values coded in q31_t
q31_t rq31[N];      // operational results coded in q31_t
q15_t vq15[N];      // values coded in q15_t
q15_t rq15[N];      // operational results coded in q15_t
bool newline_printed = false;


void assign_value_to_f(float *f, int n) {
    for (int i = 0; i < n; i++) {
        *f++ = 0.5 / (1u << i); 
    }
}

void print_real_numbers(float *y, int n, int columns) {
    for (int i = 0; i < n; i++) {
        if ((i % columns) == columns - 1) {
            printf("%15.12f\n", y[i]);
            newline_printed = true;
        } else {
            printf("%15.12f ", y[i]);
            newline_printed = false;
        }
    }
    if (!newline_printed) printf("\n");
}

void print_q31_as_real_numbers(q31_t *y, int n, int columns) {
    for (int i = 0; i < n; i++) {
        if ((i % columns) == columns-1) {
            printf("%15.12f\n", (float)y[i]/0X80000000U);
            newline_printed = true;
        } else {
            printf("%15.12f ", (float)y[i]/0X80000000U);
            newline_printed = false;
        }
    }
    if (!newline_printed) printf("\n");
}

void print_q31_as_hex_numbers(q31_t *y, int n, int columns) {
    for (int i = 0; i < n; i++) {
        if ((i % columns) == columns-1) {
            printf("0x%08X\n", y[i]);
            newline_printed = true;
        } else {
            printf("0x%08X ", y[i]);
            newline_printed = false;
        }
    }
    if (!newline_printed) printf("\n");
}

void print_q15_as_real_numbers(q15_t *y, int n, int columns) {
    for (int i = 0; i < n; i++) {
        if ((i % columns) == columns-1) {
            printf("%11.8f\n", (float)y[i]/0X8000U);
            newline_printed = true;
        } else {
            printf("%11.8f ", (float)y[i]/0X8000U);
            newline_printed = false;
        }
    }
    if (!newline_printed) printf("\n");
}

void print_q15_as_hex_numbers(q15_t *y, int n, int columns) {
    for (int i = 0; i < n; i++) {
        if ((i % columns) == columns-1) {
            printf("0x%04X\n", y[i]);
            newline_printed = true;
        } else {
            printf("0x%04X ", y[i]);
            newline_printed = false;
        }
    }
    if (!newline_printed) printf("\n");
}
// CMSIS DSP has arm_mult_q31 function. Here we write it directly
q31_t mult_q31(q31_t x, q31_t y) {
    q63_t prod = (q63_t)x * y;
    return (q31_t) (prod >> 31); 
}

void f_to_vq15(float *f, q15_t* vq){
	arm_float_to_q15(f,vq, N);
}

q15_t mult_q15(q15_t x, q15_t y){
	q63_t prod = (q63_t)x * y;
	return (q15_t) (prod >> 15);
}

void mult_and_accumulation(q15_t *rq15, q15_t *vq15){
	
		for (int i =0; i < N; i++){
			rq15[i] = mult_q15(vq15[0], vq15[i]) + mult_q15(vq15[1], vq15[i]);
		
		}

}

void print_verbose_hex(q63_t x, int n){
	
	if (n == 16){
		printf("0x");
	for (int i =0; i < 4; i++){
		int y = 48 - (i*16);
		int shifting_number =x >> y;
		
		if (i==0){
			printf("%04X", (uint16_t) shifting_number);
		}
		else{
			printf("_%04X",(uint16_t) shifting_number);
			}
	
		}
	}
	else if(n ==8){
		printf("0x");
		
	for (int i =0; i < 2; i++){
		if (i==0){
			printf("%04X", (uint16_t) (x>>16));
		}
		else{
			printf("_%04X",(uint16_t) (x));
			}
	
		}
	}	
	
}

void print_verbose_hex_newline(q63_t x, int n){
    print_verbose_hex(x, n);
		printf("\n");

}

int main(void) {
	
  // Print out the fictional +1.0 in q31
  printf("The true value of -1.0 of q31 is %d in decimal.\n", 0x80000000);
	printf("A fictional value of 1.0 of q31 is %u in decimal.\n", 0x80000000);
	// Assign special values to the float array
  assign_value_to_f(f, N);

	f_to_vq15(f,vq15);
	
	printf("\n PT1. Decoded values of vq15 array in 5 columns:\n");
	print_q15_as_real_numbers(vq15, N, 5);
	
	printf("\n PT1. Encoded values of vq15 array in 5 columns:\n");
	print_q15_as_hex_numbers(vq15,N,5);	
	
	printf("\n PT2. Multiplication and Accumulation of vq15 in 5 columns:\n");
	mult_and_accumulation(rq15, vq15);
	print_q15_as_real_numbers(rq15, N ,5);
	
	printf("\n PT3. Program verbose hexadecimal print out.\n");
	printf("   --- to be tested with PT 4 below. ---\n");
	
	printf("\n PT4. Test -1.0 x -1.0 in Q31 with help of PT 3.\n");
	
	q31_t x[] = {0X80000000L, 0, 0X80000001L, 0}; //Task 4, prints out results from multiplying -1.0 x -1.0
  
	q63_t xsquare = (q63_t)x[0] * x[0];  //64 bit printing 
	printf("64-bit xsquare value in hex: ");
	print_verbose_hex_newline(xsquare, 16);
	
  x[1] = (q31_t) (xsquare >> 31);
	printf("32-bit xsquare value in hex: "); //32 bit printing
	print_verbose_hex_newline(x[1], 8);
  
	xsquare = (q63_t)x[2] * x[2]; //64 bit printing
	printf("64-bit xsquare value in hex: ");
	print_verbose_hex_newline(xsquare, 16);
  
	x[3] = (q31_t) (xsquare >> 31); //32 bit printing
	printf("32-bit xsquare value in hex: ");
	print_verbose_hex_newline(x[3], 8);
	
	printf("Notice the issue of -1.0 x -1.0 = -1.0 below: \n");
  
	print_q31_as_real_numbers(x, 4, 4);

    while (1);
}

