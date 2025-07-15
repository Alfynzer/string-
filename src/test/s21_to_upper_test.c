#include "s21_tests.h"

START_TEST(simple_upper_case) {
  const char s21_str[] = "abc";
  char *result = s21_to_upper(s21_str);

  ck_assert_str_eq(result, "ABC");
  free(result);
}
END_TEST

START_TEST(empty_str) {
  const char s21_str[] = "";
  char *result = s21_to_upper(s21_str);

  ck_assert_pstr_eq(result, NULL);
}
END_TEST

START_TEST(letters_and_numbers) {
  const char s21_str[] = "abc123abc";
  char *result = s21_to_upper(s21_str);

  ck_assert_str_eq(result, "ABC123ABC");
  free(result);
}
END_TEST

START_TEST(uppercase) {
  const char s21_str[] = "ABC";
  char *result = s21_to_upper(s21_str);

  ck_assert_str_eq(result, "ABC");
  free(result);
}
END_TEST

Suite *suite_to_upper() {
  Suite *suite = suite_create("to_upper_suite");
  TCase *tcase_core = tcase_create("to_upper_tc");

  tcase_add_test(tcase_core, simple_upper_case);
  tcase_add_test(tcase_core, empty_str);
  tcase_add_test(tcase_core, letters_and_numbers);
  tcase_add_test(tcase_core, uppercase);

  suite_add_tcase(suite, tcase_core);
  return suite;
}