#include <stdio.h>
#include <stdint.h>
#include "unity.h"
#include "load_n_store_ws_c.h"
#include "load_n_store_ws_s.h"

uint8_t p1[32];
uint8_t p2[16];

void test_save_8_bit_signed_array_c(void) {
    init_mem(p1);
    int8_t exp[] = {0xFE, 0x02};
    int8_t *p8s = (int8_t *)p1;
    int8_t *act = (int8_t *)p1;
    save_8_bit_signed_array_c(p8s); 
    TEST_ASSERT_EQUAL_INT8_ARRAY(exp, act, 2); 
}

void test_save_8_bit_unsigned_array_c(void) {
    init_mem(p1);
    uint8_t exp[] = {0xFE, 0x02};
    uint8_t *p8u = (uint8_t *)p1;
    uint8_t *act = (uint8_t *)p1;
    save_8_bit_unsigned_array_c(p8u); 
    TEST_ASSERT_EQUAL_INT8_ARRAY(exp, act, 2); 
}

void test_load_8_bit_signed_n_save_16_bit_array_c(void) {
    init_mem(p1);
    int16_t exp[] = {0x007E, 0xFF80};
    int8_t *p8s = (int8_t *)p1;
    int16_t *p16s = (int16_t *)p2;
    int16_t *act = (int16_t *)p2;
    load_8_bit_signed_n_save_16_bit_array_c(p8s, p16s);
    TEST_ASSERT_EQUAL_INT16_ARRAY(exp, act, 2); 
}

void test_cast_8_bit_pointer_to_32_n_modify_memory_c(void) {
    init_mem(p1);
    int8_t exp1[] = {0x7D, 0x7F};
    int8_t *p8s = (int8_t *)p1;
    int8_t *act1 = (int8_t *)(p1+14);
    int32_t exp2[] = {0x00007E7D, 0xFFFF807F};
    int32_t *p32s = (int32_t *)p2;
    int32_t *act2 = (int32_t *)p2;
    cast_8_bit_pointer_to_32_n_modify_memory_c(p8s, p32s); 
    TEST_ASSERT_EQUAL_INT8_ARRAY(exp1, act1, 2); 
    TEST_ASSERT_EQUAL_INT32_ARRAY(exp2, act2, 2); 
}

void test_save_8_bit_signed_array_s(void) {
    init_mem(p1);
    int8_t exp[] = {0xFE, 0x02};
    int8_t *p8s = (int8_t *)p1;
    int8_t *act = (int8_t *)p1;
    save_8_bit_signed_array_s(p8s); 
    TEST_ASSERT_EQUAL_INT8_ARRAY(exp, act, 2); 
}

void test_save_8_bit_unsigned_array_s(void) {
    init_mem(p1);
    uint8_t exp[] = {0xFE, 0x02};
    uint8_t *p8u = (uint8_t *)p1;
    uint8_t *act = (uint8_t *)p1;
    save_8_bit_unsigned_array_s(p8u); 
    TEST_ASSERT_EQUAL_INT8_ARRAY(exp, act, 2); 
}

void test_load_8_bit_signed_n_save_16_bit_array_s(void) {
    init_mem(p1);
    int16_t exp[] = {0x007E, 0xFF80};
    int8_t *p8s = (int8_t *)p1;
    int16_t *p16s = (int16_t *)p2;
    int16_t *act = (int16_t *)p2;
    load_8_bit_signed_n_save_16_bit_array_s(p8s, p16s);
    TEST_ASSERT_EQUAL_INT16_ARRAY(exp, act, 2); 
}

void test_cast_8_bit_pointer_to_32_n_modify_memory_s(void) {
    init_mem(p1);
    int8_t exp1[] = {0x7D, 0x7F};
    int8_t *p8s = (int8_t *)p1;
    int8_t *act1 = (int8_t *)(p1+14);
    int32_t exp2[] = {0x00007E7D, 0xFFFF807F};
    int32_t *p32s = (int32_t *)p2;
    int32_t *act2 = (int32_t *)p2;
    cast_8_bit_pointer_to_32_n_modify_memory_s(p8s, p32s); 
    TEST_ASSERT_EQUAL_INT8_ARRAY(exp1, act1, 2); 
    TEST_ASSERT_EQUAL_INT32_ARRAY(exp2, act2, 2); 
}

int main(void) {
    UNITY_BEGIN();

    RUN_TEST(test_save_8_bit_signed_array_c);
    RUN_TEST(test_save_8_bit_unsigned_array_c);
    RUN_TEST(test_load_8_bit_signed_n_save_16_bit_array_c);
    RUN_TEST(test_cast_8_bit_pointer_to_32_n_modify_memory_c);
      
    RUN_TEST(test_save_8_bit_signed_array_s);
    RUN_TEST(test_save_8_bit_unsigned_array_s);
    RUN_TEST(test_load_8_bit_signed_n_save_16_bit_array_s);
    RUN_TEST(test_cast_8_bit_pointer_to_32_n_modify_memory_s);

    UNITY_END();
    
    while (1);
}
