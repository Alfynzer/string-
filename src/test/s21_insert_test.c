#include "s21_tests.h"

void set_force_malloc_fail(int val);

char *s21_insert(const char *src, const char *str, size_t start_index);

START_TEST(insert_in_empty_str) {
  char s21_str[] = "Hi";
  char s21_src[] = "";
  s21_size_t index = 3;

  ck_assert_ptr_eq(s21_insert(s21_src, s21_str, index), s21_NULL);
}
END_TEST

START_TEST(simple_test) {
  char s21_str[] = "my ";
  char s21_src[] = "Hello world";
  s21_size_t index = 6;

  char *res = s21_insert(s21_src, s21_str, index);
  ck_assert_str_eq(res, "Hello my world");
  free(res);
}
END_TEST

START_TEST(insert_in_empty) {
  char s21_str[] = "my";
  char s21_src[] = "";
  s21_size_t index = 0;

  char *res = s21_insert(s21_src, s21_str, index);
  ck_assert_str_eq(res, "my");
  free(res);
}
END_TEST

START_TEST(insert_in_end) {
  char s21_str[] = " job";
  char s21_src[] = "Good";
  s21_size_t index = 4;

  char *res = s21_insert(s21_src, s21_str, index);
  ck_assert_str_eq(res, "Good job");
  free(res);
}
END_TEST

START_TEST(insert_in_start) {
  char s21_str[] = "School";
  char s21_src[] = "21";
  s21_size_t index = 0;

  char *res = s21_insert(s21_src, s21_str, index);
  ck_assert_str_eq(res, "School21");
  free(res);
}
END_TEST

START_TEST(insert_NULL) {
  char *s21_str = s21_NULL;
  char s21_src[] = "Some text";
  s21_size_t index = 0;

  ck_assert_ptr_eq(s21_insert(s21_src, s21_str, index), s21_NULL);
}
END_TEST

START_TEST(insert_in_NULL) {
  char s21_str[] = "Some text";
  char *s21_src = s21_NULL;
  s21_size_t index = 0;

  ck_assert_ptr_eq(s21_insert(s21_src, s21_str, index), s21_NULL);
}
END_TEST

START_TEST(insert_in_middle) {
  char s21_str[] = "ret";
  char s21_src[] = "consectetur";
  s21_size_t index = 6;

  char *res = s21_insert(s21_src, s21_str, index);
  ck_assert_str_eq(res, "consecrettetur");
  free(res);
}
END_TEST

START_TEST(insert_middle) {
  char *res = s21_insert("123456", "abc", 3);
  ck_assert_str_eq(res, "123abc456");
  free(res);
}
END_TEST

START_TEST(insert_at_start) {
  char *res = s21_insert("456", "abc", 0);
  ck_assert_str_eq(res, "abc456");
  free(res);
}
END_TEST

START_TEST(insert_at_end) {
  char *res = s21_insert("abc", "XYZ", 3);
  ck_assert_str_eq(res, "abcXYZ");
  free(res);
}
END_TEST

START_TEST(insert_invalid_index) {
  char *res = s21_insert("abc", "XYZ", 10);
  ck_assert_ptr_eq(res, s21_NULL);
}
END_TEST

START_TEST(insert_null_src) {
  char *res = s21_insert(s21_NULL, "abc", 0);
  ck_assert_ptr_eq(res, s21_NULL);
}
END_TEST

START_TEST(insert_null_str) {
  char *res = s21_insert("abc", s21_NULL, 1);
  ck_assert_ptr_eq(res, s21_NULL);
}
END_TEST

START_TEST(insert_empty_str) {
  char *res = s21_insert("abc", "", 1);
  ck_assert_str_eq(res, "abc");
  free(res);
}
END_TEST

START_TEST(insert_into_empty) {
  char *res = s21_insert("", "abc", 0);
  ck_assert_str_eq(res, "abc");
  free(res);
}
END_TEST

START_TEST(insert_malloc_fail) {
  set_force_malloc_fail(1);
  char *res = s21_insert("abc", "XYZ", 1);
  ck_assert_ptr_eq(res, s21_NULL);
  set_force_malloc_fail(0);
}
END_TEST

Suite *suite_insert() {
  Suite *suite = suite_create("insert_suite");
  TCase *tcase_core = tcase_create("insert_tc");

  tcase_add_test(tcase_core, insert_in_empty_str);
  tcase_add_test(tcase_core, simple_test);
  tcase_add_test(tcase_core, insert_in_empty);
  tcase_add_test(tcase_core, insert_in_end);
  tcase_add_test(tcase_core, insert_in_start);
  tcase_add_test(tcase_core, insert_NULL);
  tcase_add_test(tcase_core, insert_in_NULL);
  tcase_add_test(tcase_core, insert_in_middle);
  tcase_add_test(tcase_core, insert_middle);
  tcase_add_test(tcase_core, insert_at_start);
  tcase_add_test(tcase_core, insert_at_end);
  tcase_add_test(tcase_core, insert_invalid_index);
  tcase_add_test(tcase_core, insert_null_src);
  tcase_add_test(tcase_core, insert_null_str);
  tcase_add_test(tcase_core, insert_empty_str);
  tcase_add_test(tcase_core, insert_into_empty);
  tcase_add_test(tcase_core, insert_malloc_fail);

  suite_add_tcase(suite, tcase_core);
  return suite;
}
