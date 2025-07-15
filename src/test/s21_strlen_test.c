#include "s21_tests.h"

START_TEST(test_empty_string) {
  const char *str = "";
  ck_assert_uint_eq(s21_strlen(str), strlen(str));
}

START_TEST(test_single_char) {
  const char *str = "a";
  ck_assert_uint_eq(s21_strlen(str), strlen(str));
}

START_TEST(test_normal_string) {
  const char *str = "Hello, world!";
  ck_assert_uint_eq(s21_strlen(str), strlen(str));
}

START_TEST(test_string_with_spaces) {
  const char *str = "   Spaces   ";
  ck_assert_uint_eq(s21_strlen(str), strlen(str));
}

START_TEST(test_string_with_special_chars) {
  const char *str = "!@#$%^&*()_+";
  ck_assert_uint_eq(s21_strlen(str), strlen(str));
}

START_TEST(test_string_with_numbers) {
  const char *str = "12345";
  ck_assert_uint_eq(s21_strlen(str), strlen(str));
}

START_TEST(test_string_with_escape_sequences) {
  const char *str = "Line1\nLine2\tTabbed";
  ck_assert_uint_eq(s21_strlen(str), strlen(str));
}

START_TEST(test_long_string) {
  char long_str[1000];
  for (int i = 0; i < 999; i++) {
    long_str[i] = 'A' + (i % 26);
  }
  long_str[999] = '\0';
  ck_assert_uint_eq(s21_strlen(long_str), strlen(long_str));
}

START_TEST(test_string_with_null_in_middle) {
  const char str[] = {'H', 'e', 'l', 'l', 'o', '\0',
                      'W', 'o', 'r', 'l', 'd', '\0'};
  ck_assert_uint_eq(s21_strlen(str), strlen(str));
}

START_TEST(test_utf8_string) {
  const char *str = "Hello, 世界!";
  ck_assert_uint_eq(s21_strlen(str), strlen(str));
}

Suite *suite_strlen(void) {
  Suite *s = suite_create("s21_strlen");
  TCase *tc_core = tcase_create("Core");

  tcase_add_test(tc_core, test_empty_string);
  tcase_add_test(tc_core, test_single_char);
  tcase_add_test(tc_core, test_normal_string);
  tcase_add_test(tc_core, test_string_with_spaces);
  tcase_add_test(tc_core, test_string_with_special_chars);
  tcase_add_test(tc_core, test_string_with_numbers);
  tcase_add_test(tc_core, test_string_with_escape_sequences);
  tcase_add_test(tc_core, test_long_string);
  tcase_add_test(tc_core, test_string_with_null_in_middle);
  tcase_add_test(tc_core, test_utf8_string);

  suite_add_tcase(s, tc_core);
  return s;
}
