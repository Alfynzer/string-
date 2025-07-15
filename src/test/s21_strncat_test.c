#include "s21_tests.h"

START_TEST(strncat_basic) {
  char s21_buf[50] = "Hello, ";
  char std_buf[50] = "Hello, ";

  s21_strncat(s21_buf, "world!", 6);
  s21_strncat(std_buf, "world!", 6);

  ck_assert_str_eq(s21_buf, std_buf);
}
END_TEST

START_TEST(strncat_n_zero) {
  char s21_buf[50] = "Hello";
  char std_buf[50] = "Hello";

  s21_strncat(s21_buf, "World", 0);
  s21_strncat(std_buf, "World", 0);

  ck_assert_str_eq(s21_buf, std_buf);
}
END_TEST

START_TEST(strncat_partial) {
  char s21_buf[50] = "123";
  char std_buf[50] = "123";

  s21_strncat(s21_buf, "456789", 3);
  s21_strncat(std_buf, "456789", 3);

  ck_assert_str_eq(s21_buf, std_buf);
}
END_TEST

START_TEST(strncat_zero_n) {
  char s21_buf[50] = "abc";
  char std_buf[50] = "abc";

  s21_strncat(s21_buf, "XYZ", 0);
  s21_strncat(std_buf, "XYZ", 0);

  ck_assert_str_eq(s21_buf, std_buf);
}
END_TEST

START_TEST(strncat_empty_src) {
  char s21_buf[50] = "prefix";
  char std_buf[50] = "prefix";

  s21_strncat(s21_buf, "", 5);
  s21_strncat(std_buf, "", 5);

  ck_assert_str_eq(s21_buf, std_buf);
}
END_TEST

START_TEST(strncat_empty_dest) {
  char s21_buf[50] = "";
  char std_buf[50] = "";

  s21_strncat(s21_buf, "abc", 3);
  s21_strncat(std_buf, "abc", 3);

  ck_assert_str_eq(s21_buf, std_buf);
}
END_TEST

START_TEST(strncat_less_than_src_len) {
  char s21_buf[50] = "abc";
  char std_buf[50] = "abc";

  s21_strncat(s21_buf, "defghijkl", 4);
  s21_strncat(std_buf, "defghijkl", 4);

  ck_assert_str_eq(s21_buf, std_buf);
}
END_TEST

START_TEST(strncat_n_bigger_than_src) {
  char s21_buf[50] = "abc";
  char std_buf[50] = "abc";

  s21_strncat(s21_buf, "XY", 10);
  s21_strncat(std_buf, "XY", 10);

  ck_assert_str_eq(s21_buf, std_buf);
}
END_TEST

START_TEST(strncat_dest_ends_midway) {
  char s21_buf[50] = {'H', 'e', 'l', 'l', 'o', '\0', 'x', 'x'};
  char std_buf[50] = {'H', 'e', 'l', 'l', 'o', '\0', 'x', 'x'};

  s21_strncat(s21_buf, "!", 1);
  s21_strncat(std_buf, "!", 1);

  ck_assert_str_eq(s21_buf, std_buf);
}
END_TEST

START_TEST(strncat_src_has_null_inside) {
  char s21_buf[50] = "start";
  char std_buf[50] = "start";
  char s21_src[10] = {'A', 'B', '\0', 'C'};
  char std_src[10] = {'A', 'B', '\0', 'C'};

  s21_strncat(s21_buf, s21_src, 5);
  s21_strncat(std_buf, std_src, 5);

  ck_assert_str_eq(s21_buf, std_buf);
}
END_TEST

START_TEST(strncat_only_one_char) {
  char s21_buf[50] = "x";
  char std_buf[50] = "x";

  s21_strncat(s21_buf, "Y", 1);
  s21_strncat(std_buf, "Y", 1);

  ck_assert_str_eq(s21_buf, std_buf);
}
END_TEST

START_TEST(strncat_large_buffer_small_data) {
  char s21_buf[1000] = "a";
  char std_buf[1000] = "a";

  s21_strncat(s21_buf, "bc", 2);
  s21_strncat(std_buf, "bc", 2);

  ck_assert_str_eq(s21_buf, std_buf);
}
END_TEST

Suite *suite_strncat(void) {
  Suite *s = suite_create("s21_strncat");
  TCase *tc = tcase_create("Core");

  tcase_add_test(tc, strncat_basic);
  tcase_add_test(tc, strncat_partial);
  tcase_add_test(tc, strncat_zero_n);
  tcase_add_test(tc, strncat_empty_src);
  tcase_add_test(tc, strncat_empty_dest);
  tcase_add_test(tc, strncat_less_than_src_len);
  tcase_add_test(tc, strncat_n_zero);
  tcase_add_test(tc, strncat_n_bigger_than_src);
  tcase_add_test(tc, strncat_dest_ends_midway);
  tcase_add_test(tc, strncat_src_has_null_inside);
  tcase_add_test(tc, strncat_only_one_char);
  tcase_add_test(tc, strncat_large_buffer_small_data);
  suite_add_tcase(s, tc);
  return s;
}
