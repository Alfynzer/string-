#include "s21_tests.h"

START_TEST(simple_lower_case) {
  const char s21_str[] = "ABC";
  char *result = s21_to_lower(s21_str);

  ck_assert_str_eq(result, "abc");
  free(result);
}
END_TEST

START_TEST(empty_str) {
  const char s21_str[] = "";
  char *result = s21_to_lower(s21_str);

  ck_assert_pstr_eq(result, NULL);
}
END_TEST

START_TEST(letters_and_numbers) {
  const char s21_str[] = "ABC123ABC";
  char *result = s21_to_lower(s21_str);

  ck_assert_str_eq(result, "abc123abc");
  free(result);
}
END_TEST

START_TEST(lowercase) {
  const char s21_str[] = "abc";
  char *result = s21_to_lower(s21_str);

  ck_assert_str_eq(result, "abc");
  free(result);
}
END_TEST

Suite *suite_to_lower() {
  Suite *suite = suite_create("to_lower_suite");
  TCase *tcase_core = tcase_create("to_lower_tc");

  tcase_add_test(tcase_core, simple_lower_case);
  tcase_add_test(tcase_core, empty_str);
  tcase_add_test(tcase_core, letters_and_numbers);
  tcase_add_test(tcase_core, lowercase);

  suite_add_tcase(suite, tcase_core);
  return suite;
}