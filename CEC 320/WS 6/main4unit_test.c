#include <stdio.h>
#include <stdint.h>
#include "unity.h"
#include "ws_if_switch_c.h"
#include "ws_if_switch_s.h"


void test_ws_acrl_c(void) {
    int arr[] = {10, 2, -16}; 
    int exp[] = {8, 2, 0};
    arr[0] = ws_acrl_c(arr[0]);
    arr[1] = ws_acrl_c(arr[1]);
    arr[2] = ws_acrl_c(arr[2]);
    TEST_ASSERT_EQUAL_INT32_ARRAY(exp, arr, 3); 
}

void test_ws_acrl_cmp_s(void) {
    int arr[] = {10, 2, -16}; 
    int exp[] = {8, 2, 0};
    arr[0] = ws_acrl_cmp_s(arr[0]);
    arr[1] = ws_acrl_cmp_s(arr[1]);
    arr[2] = ws_acrl_cmp_s(arr[2]);
    TEST_ASSERT_EQUAL_INT32_ARRAY(exp, arr, 3); 
}

void test_ws_acrl_cex_s(void) {
    int arr[] = {10, 2, -16}; 
    int exp[] = {8, 2, 0};
    arr[0] = ws_acrl_cex_s(arr[0]);
    arr[1] = ws_acrl_cex_s(arr[1]);
    arr[2] = ws_acrl_cex_s(arr[2]);
    TEST_ASSERT_EQUAL_INT32_ARRAY(exp, arr, 3); 
}

void test_ws_dcrl_orr_c(void) {
    int arr[] = {-1, 0, 1, 7, 8, 9}; 
    int exp[] = { 0, 1, 1, 1, 0, 0};
    for (int i = 0; i < 6; i++) {
        arr[i] = ws_dcrl_orr_c(arr[i]);
    }
    TEST_ASSERT_EQUAL_INT32_ARRAY(exp, arr, 6); 
}

void test_ws_dcrl_orr_s(void) {
    int arr[] = {-1, 0, 1, 7, 8, 9}; 
    int exp[] = { 0, 1, 1, 1, 0, 0};
    for (int i = 0; i < 6; i++) {
        arr[i] = ws_dcrl_orr_s(arr[i]);
    }
    TEST_ASSERT_EQUAL_INT32_ARRAY(exp, arr, 6); 
}

void test_ws_dcrl_and_c(void) {
    int arr[] = {-1, 0, 1, 7, 8, 9}; 
    int exp[] = { 0, 1, 1, 1, 0, 0};
    for (int i = 0; i < 6; i++) {
        arr[i] = ws_dcrl_and_c(arr[i]);
    }
    TEST_ASSERT_EQUAL_INT32_ARRAY(exp, arr, 6); 
}

void test_ws_dcrl_and_s(void) {
    int arr[] = {-1, 0, 1, 7, 8, 9}; 
    int exp[] = { 0, 1, 1, 1, 0, 0};
    for (int i = 0; i < 6; i++) {
        arr[i] = ws_dcrl_and_s(arr[i]);
    }
    TEST_ASSERT_EQUAL_INT32_ARRAY(exp, arr, 6); 
}


int main(void) {
    UNITY_BEGIN();

    RUN_TEST(test_ws_acrl_c);
    RUN_TEST(test_ws_acrl_cmp_s);
    RUN_TEST(test_ws_acrl_cex_s);

    RUN_TEST(test_ws_dcrl_orr_c);
    RUN_TEST(test_ws_dcrl_orr_s);

    RUN_TEST(test_ws_dcrl_and_c);
    RUN_TEST(test_ws_dcrl_and_s);

    UNITY_END();
    
    while (1);
}
