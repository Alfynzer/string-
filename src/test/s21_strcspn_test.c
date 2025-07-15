#include "s21_tests.h"

START_TEST(test_strcspn_basic) {
  ck_assert_uint_eq(s21_strcspn("hello", "l"), strcspn("hello", "l"));
}
END_TEST

START_TEST(strcspn_match_found) {
  const char *str1 = "abcdefg";
  const char *str2 = "xey";
  ck_assert_int_eq(s21_strcspn(str1, str2), strcspn(str1, str2));
}
END_TEST

START_TEST(strcspn_no_match) {
  const char *str1 = "abcdef";
  const char *str2 = "xyz";
  ck_assert_int_eq(s21_strcspn(str1, str2), strcspn(str1, str2));
}
END_TEST

START_TEST(strcspn_first_match) {
  const char *str1 = "apple";
  const char *str2 = "a";
  ck_assert_int_eq(s21_strcspn(str1, str2), strcspn(str1, str2));
}
END_TEST

START_TEST(strcspn_empty_str2) {
  const char *str1 = "abcdef";
  const char *str2 = "";
  ck_assert_int_eq(s21_strcspn(str1, str2), strcspn(str1, str2));
}
END_TEST

START_TEST(strcspn_empty_str1) {
  const char *str1 = "";
  const char *str2 = "abc";
  ck_assert_int_eq(s21_strcspn(str1, str2), strcspn(str1, str2));
}
END_TEST

Suite *suite_strcspn(void) {
  Suite *s = suite_create("s21_strcspn");
  TCase *tc = tcase_create("Core");

  tcase_add_test(tc, test_strcspn_basic);
  tcase_add_test(tc, strcspn_match_found);
  tcase_add_test(tc, strcspn_no_match);
  tcase_add_test(tc, strcspn_first_match);
  tcase_add_test(tc, strcspn_empty_str2);
  tcase_add_test(tc, strcspn_empty_str1);

  suite_add_tcase(s, tc);

  return s;
}
