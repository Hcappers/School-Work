#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include "unity.h"
#include "jf_flow_control_c.h"
//#include "jf_flow_control_s.h"


//-----------------------------------------------
void test_load_based_on_x_c(void) {
uint8_t arr[] = {0, 1, 2, 3, 4, 5, 6, 7};
uint16_t *ptrA = (uint16_t *)arr;
uint32_t *ptrB = (uint32_t *)arr;
int32_t exp[] = {3080, 29458753, 3080};
int32_t act[3];
act[0] = load_based_on_x_c(15, ptrA, ptrB);
act[1] = load_based_on_x_c(22, ptrA, ptrB);
act[2] = load_based_on_x_c(30, ptrA, ptrB);
TEST_ASSERT_EQUAL_INT32_ARRAY(exp, act, 3);
}
//-----------------------------------------------
void test_sum_arr_index_for_c(void) {
int16_t arr[] = {0, 1, 2, 3, 4, 5, 6, 7};
int32_t exp[] = {1, 140};
int32_t act[2];
act[0] = sum_arr_index_for_c(arr, 2);
act[1] = sum_arr_index_for_c(arr, 8);
TEST_ASSERT_EQUAL_INT32_ARRAY(exp, act, 2);
}
//-----------------------------------------------
void test_sum_arr_index_whl_c(void) {
int16_t arr[] = {0, 1, 2, 3, 4, 5, 6, 7};
int32_t exp[] = {1, 140};
int32_t act[2];
act[0] = sum_arr_index_whl_c(arr, 2);
act[1] = sum_arr_index_whl_c(arr, 8);
TEST_ASSERT_EQUAL_INT32_ARRAY(exp, act, 2);
}
//-----------------------------------------------
void test_set_parity_bit_u16_c(void) {
uint16_t data[] = {0, 1, 3};
uint16_t exp_odd[] = {32768, 1, 32771};
uint16_t exp_even[] = {0, 32769, 3};
uint16_t act[3];
for (int i = 0; i < 3; i++) {
act[i] = set_parity_bit_u16_c(data[i], 1); // odd
}
TEST_ASSERT_EQUAL_INT16_ARRAY(exp_odd, act, 3);
for (int i = 0; i < 3; i++) {
act[i] = set_parity_bit_u16_c(data[i], 0); // even
}
TEST_ASSERT_EQUAL_INT16_ARRAY(exp_even, act, 3);
}

int main(void) {
UNITY_BEGIN();
RUN_TEST(test_load_based_on_x_c);
RUN_TEST(test_sum_arr_index_for_c);
RUN_TEST(test_sum_arr_index_whl_c);
RUN_TEST(test_set_parity_bit_u16_c);
UNITY_END();
while (1);
}