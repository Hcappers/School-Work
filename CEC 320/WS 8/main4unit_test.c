
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include "unity.h"
#include "caesar_cipher_c.h"
//-----------------------------------------------
void test_return_of_caesar_shift_c(void) {
uint8_t text[] = "Hello8";
int exp[] = {-1, 5, -1, 5};
int act[4];
act[0] = caesar_shift_c(text, 101);
act[1] = caesar_shift_c(text, 100);
act[2] = caesar_shift_c(text, -101);
act[3] = caesar_shift_c(text, -100);
TEST_ASSERT_EQUAL_INT32_ARRAY(exp, act, 4);
}
//-----------------------------------------------
void test_encoding_1_c(void) {
uint8_t text[] = "Hello8";
uint8_t exp[] = "Ifmmp8";
caesar_shift_c(text, 1);
TEST_ASSERT_EQUAL_INT8_ARRAY(exp, text, 6);
}
void test_encoding_2_c(void) {
uint8_t text[] = "Hello8";
uint8_t exp[] = "Ifmmp8";
caesar_shift_c(text, 79);
TEST_ASSERT_EQUAL_INT8_ARRAY(exp, text, 6);
}
void test_encoding_3_c(void) {
uint8_t text[] = "Hello8";
uint8_t exp[] = "Gdkkn8";
caesar_shift_c(text, -1);
TEST_ASSERT_EQUAL_INT8_ARRAY(exp, text, 6);
}
void test_encoding_4_c(void) {
uint8_t text[] = "Hello8";
uint8_t exp[] = "Gdkkn8";
caesar_shift_c(text, -79);
TEST_ASSERT_EQUAL_INT8_ARRAY(exp, text, 6);
}
int main(void) {
UNITY_BEGIN();
RUN_TEST(test_return_of_caesar_shift_c);
RUN_TEST(test_encoding_1_c);
RUN_TEST(test_encoding_2_c);
RUN_TEST(test_encoding_3_c);
RUN_TEST(test_encoding_4_c);
UNITY_END();
while (1);
}