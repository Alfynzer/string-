#include "s21_tests.h"

int s21_sscanf(const char *str, const char *format, ...);

START_TEST(test_int_decimal) {
  int d = 0;
  int res = s21_sscanf("12345", "%d", &d);
  ck_assert_int_eq(res, 1);
  ck_assert_int_eq(d, 12345);
}
END_TEST

START_TEST(test_int_signed_i) {
  int d = 0;
  int res = s21_sscanf("-42", "%i", &d);
  ck_assert_int_eq(res, 1);
  ck_assert_int_eq(d, -42);
}
END_TEST

START_TEST(test_int_hex_i) {
  int d = 0;
  int res = s21_sscanf("0xFF", "%i", &d);
  ck_assert_int_eq(res, 1);
  ck_assert_int_eq(d, 255);
}
END_TEST

START_TEST(test_int_octal_i) {
  int d = 0;
  int res = s21_sscanf("077", "%i", &d);
  ck_assert_int_eq(res, 1);
  ck_assert_int_eq(d, 63);
}
END_TEST

START_TEST(test_unsigned_decimal) {
  unsigned int u = 0;
  int res = s21_sscanf("4294967295", "%u", &u);
  ck_assert_int_eq(res, 1);
  ck_assert_uint_eq(u, 4294967295U);
}
END_TEST

START_TEST(test_unsigned_octal) {
  unsigned int u = 0;
  int res = s21_sscanf("377", "%o", &u);
  ck_assert_int_eq(res, 1);
  ck_assert_uint_eq(u, 0xFF);
}
END_TEST

START_TEST(test_unsigned_hex_lower) {
  unsigned int u = 0;
  int res = s21_sscanf("deadbeef", "%x", &u);
  ck_assert_int_eq(res, 1);
  ck_assert_uint_eq(u, 0xDEADBEEF);
}
END_TEST

START_TEST(test_unsigned_hex_upper) {
  unsigned int u = 0;
  int res = s21_sscanf("DEADBEEF", "%X", &u);
  ck_assert_int_eq(res, 1);
  ck_assert_uint_eq(u, 0xDEADBEEF);
}
END_TEST

START_TEST(test_float) {
  float f = 0.0f;
  int res = s21_sscanf("3.1415", "%f", &f);
  ck_assert_int_eq(res, 1);
  ck_assert_msg(f > 3.1414f && f < 3.1416f, "f=%.5f", f);
}
END_TEST

START_TEST(test_double) {
  double d = 0.0;
  int res = s21_sscanf("-2.71828", "%lf", &d);
  ck_assert_int_eq(res, 1);
  ck_assert_msg(d > -2.71829 && d < -2.71827, "d=%.6lf", d);
}
END_TEST

START_TEST(test_char) {
  char c = 0;
  int res = s21_sscanf("Z", "%c", &c);
  ck_assert_int_eq(res, 1);
  ck_assert_int_eq(c, 'Z');
}
END_TEST

START_TEST(test_string) {
  char s[20] = {0};
  int res = s21_sscanf("HelloWorld", "%s", s);
  ck_assert_int_eq(res, 1);
  ck_assert_str_eq(s, "HelloWorld");
}
END_TEST

START_TEST(test_string_with_width) {
  char s1[10] = {0};
  char s2[10] = {0};
  int res = s21_sscanf("Hello World", "%5s %5s", s1, s2);
  ck_assert_int_eq(res, 2);
  ck_assert_str_eq(s1, "Hello");
  ck_assert_str_eq(s2, "World");
}
END_TEST

START_TEST(test_pointer) {
  void *p = NULL;
  int res = s21_sscanf("0x1234abcd", "%p", &p);
  ck_assert_int_eq(res, 1);

  ck_assert_ptr_ne(p, NULL);
}
END_TEST

START_TEST(test_n_specifier) {
  char buf[10] = {0};
  int n = 0;
  int res = s21_sscanf("abcde", "%3c%n", buf, &n);
  buf[3] = '\0';
  ck_assert_int_eq(res, 1);
  ck_assert_str_eq(buf, "abc");
  ck_assert_int_eq(n, 3);
}
END_TEST

START_TEST(test_skip_asterisk) {
  int b = 0;
  int res = s21_sscanf("123 456", "%*d %d", &b);
  ck_assert_int_eq(res, 1);
  ck_assert_int_eq(b, 456);
}
END_TEST

START_TEST(test_mismatch) {
  int x = 0;
  int res = s21_sscanf("abc", "%d", &x);
  ck_assert_int_eq(res, 0);
}
END_TEST

START_TEST(test_length_n) {
  int n_int = 0;
  short n_short = 0;
  long n_long = 0;
  long long n_llong = 0;

  char buf[4] = {0};

  int res;

  res = s21_sscanf("abc", "%3c%n", buf, &n_int);
  ck_assert_int_eq(res, 1);
  ck_assert_int_eq(n_int, 3);

  res = s21_sscanf("abc", "%3c%hn", buf, &n_short);
  ck_assert_int_eq(res, 1);
  ck_assert_int_eq(n_short, 3);

  res = s21_sscanf("abc", "%3c%ln", buf, &n_long);
  ck_assert_int_eq(res, 1);
  ck_assert_int_eq(n_long, 3);

  res = s21_sscanf("abc", "%3c%lln", buf, &n_llong);
  ck_assert_int_eq(res, 1);
  ck_assert_int_eq(n_llong, 3);
}
END_TEST

START_TEST(test_long_double) {
  long double ld = 0.0L;
  int res = s21_sscanf("3.14159", "%Lf", &ld);
  ck_assert_int_eq(res, 1);
  ck_assert(ld > 3.14L && ld < 3.15L);
}
END_TEST

START_TEST(test_asterisk_flag) {
  int res = s21_sscanf("123", "%*d");

  ck_assert_int_eq(res, 1);
}
END_TEST

START_TEST(test_parse_char_and_string_width) {
  char c = 0;
  char buf[10] = {0};

  int res1 = s21_sscanf("A", "%c", &c);
  ck_assert_int_eq(res1, 1);
  ck_assert_uint_eq(c, 'A');

  int res2 = s21_sscanf("Hello", "%2s", buf);
  ck_assert_int_eq(res2, 1);
  ck_assert_str_eq(buf, "He");
}
END_TEST

START_TEST(test_parse_ptr) {
  void *ptr = NULL;
  int res = s21_sscanf("0x7fff", "%p", &ptr);
  ck_assert_int_eq(res, 1);
  ck_assert(ptr != NULL);

  void *ptr2 = (void *)0x1234;
  res = s21_sscanf("1234", "%p", &ptr2);
  ck_assert_int_eq(res, 0);
  ck_assert_ptr_eq(ptr2, (void *)0x1234);
}
END_TEST

START_TEST(test_parse_ptr_extended) {
  const char *str = "0x1a2b3c4d";
  void *ptr = NULL;
  int res = s21_sscanf(str, "%p", &ptr);
  ck_assert_ptr_eq(ptr, (void *)0x1a2b3c4d);
  ck_assert_int_eq(res, 1);
}
END_TEST

START_TEST(test_parse_n) {
  const char *str = "test string";
  int count = 0;
  s21_sscanf(str, "%*s%n", &count);
  ck_assert_int_eq(count, 4);
}
END_TEST

START_TEST(test_parse_float_f) {
  const char *str = "123.45";
  float f = 0.0f;
  int res = s21_sscanf(str, "%f", &f);
  ck_assert_float_eq_tol(f, 123.45f, 1e-6);
  ck_assert_int_eq(res, 1);
}
END_TEST

START_TEST(test_parse_double_lf) {
  const char *str = "123.45";
  double d = 0.0;
  int res = s21_sscanf(str, "%lf", &d);
  ck_assert_double_eq_tol(d, 123.45, 1e-12);
  ck_assert_int_eq(res, 1);
}
END_TEST

START_TEST(test_parse_long_double_Lf) {
  const char *str = "123.45";
  long double ld = 0.0L;
  int res = s21_sscanf(str, "%Lf", &ld);
  ck_assert_int_eq(res, 1);
  ck_assert_ldouble_eq_tol(ld, 123.45L, 1e-12);
}
END_TEST

START_TEST(test_parse_hex_x) {
  const char *str = "1a2b3c";
  unsigned int value = 0;
  int res = s21_sscanf(str, "%x", &value);
  ck_assert_uint_eq(value, 0x1a2b3c);
  ck_assert_int_eq(res, 1);
}
END_TEST

START_TEST(test_parse_hex_X) {
  const char *str = "1A2B3C";
  unsigned int value = 0;
  int res = s21_sscanf(str, "%X", &value);
  ck_assert_uint_eq(value, 0x1a2b3c);
  ck_assert_int_eq(res, 1);
}
END_TEST

START_TEST(test_parse_octal_o) {
  const char *str = "123";
  unsigned int value = 0;
  int res = s21_sscanf(str, "%o", &value);
  ck_assert_uint_eq(value, 0123);
  ck_assert_int_eq(res, 1);
}
END_TEST

START_TEST(test_parse_i_auto_base) {
  const char *str1 = "123";
  const char *str2 = "0x1a";
  const char *str3 = "012";

  int val1 = 0, val2 = 0, val3 = 0;

  ck_assert_int_eq(s21_sscanf(str1, "%i", &val1), 1);
  ck_assert_int_eq(val1, 123);

  ck_assert_int_eq(s21_sscanf(str2, "%i", &val2), 1);
  ck_assert_int_eq(val2, 0x1a);

  ck_assert_int_eq(s21_sscanf(str3, "%i", &val3), 1);
  ck_assert_int_eq(val3, 012);
}
END_TEST

START_TEST(test_length_h) {
  const char *str = "32767";
  short val = 0;
  int res = s21_sscanf(str, "%hd", &val);
  ck_assert_int_eq(val, 32767);
  ck_assert_int_eq(res, 1);
}
END_TEST

START_TEST(test_length_l) {
  const char *str = "2147483647";
  long val = 0;
  int res = s21_sscanf(str, "%ld", &val);
  ck_assert_int_eq(val, 2147483647);
  ck_assert_int_eq(res, 1);
}
END_TEST

START_TEST(test_length_ll) {
  const char *str = "9223372036854775807";
  long long val = 0;
  int res = s21_sscanf(str, "%lld", &val);
  ck_assert_int_eq(val, 9223372036854775807LL);
  ck_assert_int_eq(res, 1);
}
END_TEST

START_TEST(test_asterisk_suppression) {
  const char *str = "123 abc";
  char buffer[32] = {0};
  int res = s21_sscanf(str, "%*d %s", buffer);
  ck_assert_str_eq(buffer, "abc");
  ck_assert_int_eq(res, 1);
}
END_TEST

START_TEST(test_char_with_width) {
  const char *str = "abcd";
  char buffer[10] = {0};
  int res = s21_sscanf(str, "%5c", buffer);
  ck_assert_str_eq(buffer, "abcd");
  ck_assert_int_eq(res, 1);
}
END_TEST

START_TEST(test_edge_cases_empty_string) {
  int res = s21_sscanf("", "%d", NULL);
  ck_assert_int_eq(res, 0);
}
END_TEST

START_TEST(test_edge_cases_invalid_input) {
  int val = 0;
  int res = s21_sscanf("abc", "%d", &val);
  ck_assert_int_eq(res, 0);
}
END_TEST

START_TEST(test_parse_float_with_exp) {
  const char *str = "123.45e6";
  float val = 0.0f;
  int res = s21_sscanf(str, "%f", &val);
  ck_assert_int_eq(res, 1);
  ck_assert_double_eq_tol(val, 123450000.0f, 1e-6);
}
END_TEST

START_TEST(test_parse_double_with_exp) {
  const char *str = "123.45E-2";
  double val = 0.0;
  int res = s21_sscanf(str, "%lf", &val);
  ck_assert_int_eq(res, 1);
  ck_assert_double_eq_tol(val, 1.2345, 1e-12);
}
END_TEST

START_TEST(test_parse_long_double_with_exp) {
  const char *str = "-123.45e3";
  long double val = 0.0L;
  int res = s21_sscanf(str, "%Lf", &val);
  ck_assert_int_eq(res, 1);
  ck_assert_ldouble_eq_tol(val, -123450.0L, 1e-12);
}
END_TEST

START_TEST(test_parse_float_g) {
  const char *str = "123.45";
  float f = 0.0f;
  int res = s21_sscanf(str, "%g", &f);
  ck_assert_int_eq(res, 1);
  ck_assert_float_eq_tol(f, 123.45f, 1e-6);
}
END_TEST

START_TEST(test_parse_string_s) {
  const char *str = "hello world";
  char buffer[256] = {0};
  int res = s21_sscanf(str, "%s", buffer);
  ck_assert_int_eq(res, 1);
  ck_assert_str_eq(buffer, "hello");
}
END_TEST

START_TEST(test_parse_float_e) {
  const char *str = "1.2345e2";
  float f = 0.0f;
  int res = s21_sscanf(str, "%f", &f);
  ck_assert_int_eq(res, 1);
  ck_assert_float_eq_tol(f, 123.45f, 1e-6);
}
END_TEST

START_TEST(test_parse_percent_sign_fail) {
  int res = s21_sscanf("x", "%%");
  ck_assert_int_eq(res, 0);
}
END_TEST

START_TEST(test_parse_percent_match) {
  int res = s21_sscanf("%", "%%");
  ck_assert_int_eq(res, 1);
}
END_TEST

START_TEST(test_parse_percent_no_match) {
  int res = s21_sscanf("x", "%%");
  ck_assert_int_eq(res, 0);
}
END_TEST

START_TEST(test_parse_percent_sign_success) {
  int res = s21_sscanf("%%", "%%");
  ck_assert_int_eq(res, 1);
}
END_TEST

Suite *suite_sscanf(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("s21_sscanf");

  tc_core = tcase_create("Core");

  tcase_add_test(tc_core, test_parse_percent_sign_success);
  tcase_add_test(tc_core, test_parse_percent_no_match);
  tcase_add_test(tc_core, test_parse_percent_match);
  tcase_add_test(tc_core, test_parse_percent_sign_fail);
  tcase_add_test(tc_core, test_parse_float_e);
  tcase_add_test(tc_core, test_parse_string_s);
  tcase_add_test(tc_core, test_parse_float_g);
  tcase_add_test(tc_core, test_parse_long_double_with_exp);
  tcase_add_test(tc_core, test_parse_double_with_exp);
  tcase_add_test(tc_core, test_parse_float_with_exp);
  tcase_add_test(tc_core, test_parse_ptr_extended);
  tcase_add_test(tc_core, test_parse_n);
  tcase_add_test(tc_core, test_parse_float_f);
  tcase_add_test(tc_core, test_parse_double_lf);
  tcase_add_test(tc_core, test_parse_long_double_Lf);
  tcase_add_test(tc_core, test_parse_hex_x);
  tcase_add_test(tc_core, test_parse_hex_X);
  tcase_add_test(tc_core, test_parse_octal_o);
  tcase_add_test(tc_core, test_parse_i_auto_base);
  tcase_add_test(tc_core, test_length_h);
  tcase_add_test(tc_core, test_length_l);
  tcase_add_test(tc_core, test_length_ll);
  tcase_add_test(tc_core, test_asterisk_suppression);
  tcase_add_test(tc_core, test_char_with_width);
  tcase_add_test(tc_core, test_edge_cases_empty_string);
  tcase_add_test(tc_core, test_edge_cases_invalid_input);
  tcase_add_test(tc_core, test_int_decimal);
  tcase_add_test(tc_core, test_int_signed_i);
  tcase_add_test(tc_core, test_int_hex_i);
  tcase_add_test(tc_core, test_int_octal_i);
  tcase_add_test(tc_core, test_unsigned_decimal);
  tcase_add_test(tc_core, test_unsigned_octal);
  tcase_add_test(tc_core, test_unsigned_hex_lower);
  tcase_add_test(tc_core, test_unsigned_hex_upper);
  tcase_add_test(tc_core, test_float);
  tcase_add_test(tc_core, test_double);
  tcase_add_test(tc_core, test_char);
  tcase_add_test(tc_core, test_string);
  tcase_add_test(tc_core, test_string_with_width);
  tcase_add_test(tc_core, test_pointer);
  tcase_add_test(tc_core, test_n_specifier);
  tcase_add_test(tc_core, test_skip_asterisk);
  tcase_add_test(tc_core, test_mismatch);
  tcase_add_test(tc_core, test_length_n);
  tcase_add_test(tc_core, test_long_double);
  tcase_add_test(tc_core, test_asterisk_flag);
  tcase_add_test(tc_core, test_parse_char_and_string_width);
  tcase_add_test(tc_core, test_parse_ptr);

  suite_add_tcase(s, tc_core);

  return s;
}
