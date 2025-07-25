#ifndef SRC_S21_TESTS_H_
#define SRC_S21_TESTS_H_

#include <check.h>

#include "s21_string.h"

#define ck_assert_sign_eq(expr1, expr2)            \
  do {                                             \
    int __res1 = (expr1);                          \
    int __res2 = (expr2);                          \
    ck_assert_int_eq((__res1 > 0) - (__res1 < 0),  \
                     (__res2 > 0) - (__res2 < 0)); \
  } while (0)

Suite *suite_insert(void);
Suite *suite_memchr(void);
Suite *suite_memcmp(void);
Suite *suite_memcpy(void);
Suite *suite_memset(void);
Suite *suite_sprintf(void);
Suite *suite_strchr(void);
Suite *suite_strerror(void);
Suite *suite_strlen(void);
Suite *suite_strncat(void);
Suite *suite_strncmp(void);
Suite *suite_strncpy(void);
Suite *suite_strpbrk(void);
Suite *suite_strrchr(void);
Suite *suite_strstr(void);
Suite *suite_strtok(void);
Suite *suite_to_upper(void);
Suite *suite_to_lower(void);
Suite *suite_trim(void);
Suite *suite_strcspn(void);
Suite *suite_sscanf(void);

void run_tests(void);
void run_testcase(Suite *testcase);

#endif