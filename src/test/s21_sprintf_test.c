#include "s21_tests.h"

START_TEST(d_simple_int) {
  char s21_buff[100] = "";
  char buff[100] = "";
  int s21 = 5;
  int system = 5;
  s21_sprintf(s21_buff, "This is %d", s21);
  sprintf(buff, "This is %d", system);

  ck_assert_pstr_eq(s21_buff, buff);
}
END_TEST

START_TEST(d_negative_int) {
  char s21_buff[100] = "";
  char buff[100] = "";
  int s21 = -19;
  int system = -19;
  s21_sprintf(s21_buff, "This is %d", s21);
  sprintf(buff, "This is %d", system);

  ck_assert_pstr_eq(s21_buff, buff);
}
END_TEST

START_TEST(d_int_in_middle_of_str) {
  char s21_buff[100] = "";
  char buff[100] = "";
  int s21 = 1024;
  int system = 1024;
  s21_sprintf(s21_buff, "This is %d number", s21);
  sprintf(buff, "This is %d number", system);

  ck_assert_pstr_eq(s21_buff, buff);
}
END_TEST

START_TEST(s_simple_test) {
  char s21_buff[100] = "";
  char buff[100] = "";
  char *s21 = "Hello str";
  char *system = "Hello str";
  s21_sprintf(s21_buff, "This is %s", s21);
  sprintf(buff, "This is %s", system);

  ck_assert_pstr_eq(s21_buff, buff);
}
END_TEST

START_TEST(s_empty_test) {
  char s21_buff[100] = "";
  char buff[100] = "";
  char *s21 = "";
  char *system = "";
  s21_sprintf(s21_buff, "This is %s", s21);
  sprintf(buff, "This is %s", system);

  ck_assert_pstr_eq(s21_buff, buff);
}
END_TEST

START_TEST(s_int_str_test) {
  char s21_buff[100] = "";
  char buff[100] = "";
  char *s21 = "12345";
  char *system = "12345";
  s21_sprintf(s21_buff, "This is %s", s21);
  sprintf(buff, "This is %s", system);

  ck_assert_pstr_eq(s21_buff, buff);
}
END_TEST

START_TEST(s_str_in_middle_of_str) {
  char s21_buff[100] = "";
  char buff[100] = "";
  char *s21 = "my";
  char *system = "my";
  s21_sprintf(s21_buff, "This is %s string", s21);
  sprintf(buff, "This is %s string", system);

  ck_assert_pstr_eq(s21_buff, buff);
}
END_TEST

START_TEST(f_simple) {
  char s21_buff[100] = "";
  char buff[100] = "";
  float s21 = 4.3;
  float system = 4.3;
  s21_sprintf(s21_buff, "This is %f number", s21);
  sprintf(buff, "This is %f number", system);

  ck_assert_pstr_eq(s21_buff, buff);
}
END_TEST

START_TEST(f_simple_zero) {
  char s21_buff[100] = "";
  char buff[100] = "";
  float s21 = 0.34;
  float system = 0.34;
  s21_sprintf(s21_buff, "This is %f number", s21);
  sprintf(buff, "This is %f number", system);

  ck_assert_pstr_eq(s21_buff, buff);
}
END_TEST

START_TEST(f_big_number) {
  char s21_buff[100] = "";
  char buff[100] = "";
  float s21 = 9.3425789;
  float system = 9.3425789;
  s21_sprintf(s21_buff, "This is %f number", s21);
  sprintf(buff, "This is %f number", system);

  ck_assert_pstr_eq(s21_buff, buff);
}
END_TEST

START_TEST(f_big_int_part) {
  char s21_buff[100] = "";
  char buff[100] = "";
  float s21 = 10.3;
  float system = 10.3;
  s21_sprintf(s21_buff, "This is %f number", s21);
  sprintf(buff, "This is %f number", system);

  ck_assert_pstr_eq(s21_buff, buff);
}
END_TEST

START_TEST(f_zero) {
  char s21_buff[100] = "";
  char buff[100] = "";
  float s21 = 0;
  float system = 0;
  s21_sprintf(s21_buff, "This is %f number", s21);
  sprintf(buff, "This is %f number", system);

  ck_assert_pstr_eq(s21_buff, buff);
}
END_TEST

START_TEST(exactness_simple) {
  char s21_buff[100] = "";
  char buff[100] = "";
  float s21 = 2.322;
  float system = 2.322;
  s21_sprintf(s21_buff, "This is %.2f number", s21);
  sprintf(buff, "This is %.2f number", system);

  ck_assert_pstr_eq(s21_buff, buff);
}
END_TEST

START_TEST(exactness_with_simple_rounding) {
  char s21_buff[100] = "";
  char buff[100] = "";
  float s21 = 2.3228;
  float system = 2.3228;
  s21_sprintf(s21_buff, "This is %.3f number", s21);
  sprintf(buff, "This is %.3f number", system);

  ck_assert_pstr_eq(s21_buff, buff);
}
END_TEST

START_TEST(exactness_with_hard_rounding) {
  char s21_buff[100] = "";
  char buff[100] = "";
  float s21 = 2.3228;
  float system = 2.3228;
  s21_sprintf(s21_buff, "This is %.3f number", s21);
  sprintf(buff, "This is %.3f number", system);

  ck_assert_pstr_eq(s21_buff, buff);
}
END_TEST

START_TEST(exactness_with_hard_rounding_minus) {
  char s21_buff[100] = "";
  char buff[100] = "";
  float s21 = -2.3228;
  float system = -2.3228;
  s21_sprintf(s21_buff, "This is %.3f number", s21);
  sprintf(buff, "This is %.3f number", system);

  ck_assert_pstr_eq(s21_buff, buff);
}
END_TEST

START_TEST(c_simple_char) {
  char s21_buff[100] = "";
  char buff[100] = "";
  s21_sprintf(s21_buff, "%c", 'c');
  sprintf(buff, "%c", 'c');

  ck_assert_pstr_eq(s21_buff, buff);
}
END_TEST

START_TEST(c_number_ASCII) {
  char s21_buff[100] = "";
  char buff[100] = "";
  s21_sprintf(s21_buff, "%c", 67);
  sprintf(buff, "%c", 67);

  ck_assert_pstr_eq(s21_buff, buff);
}
END_TEST

START_TEST(c_number_char) {
  char s21_buff[100] = "";
  char buff[100] = "";
  s21_sprintf(s21_buff, "%c", '8');
  sprintf(buff, "%c", '8');
  ck_assert_pstr_eq(s21_buff, buff);
}
END_TEST

START_TEST(c_space_char) {
  char s21_buff[100] = "";
  char buff[100] = "";
  s21_sprintf(s21_buff, "%c", ' ');
  sprintf(buff, "%c", ' ');
  ck_assert_pstr_eq(s21_buff, buff);
}
END_TEST

START_TEST(flag_plus_simple_test) {
  char s21_buff[100] = "";
  char buff[100] = "";
  s21_sprintf(s21_buff, "%+d", 21);
  sprintf(buff, "%+d", 21);
  ck_assert_pstr_eq(s21_buff, buff);
}
END_TEST

START_TEST(flag_plus_negative_number) {
  char s21_buff[100] = "";
  char buff[100] = "";
  s21_sprintf(s21_buff, "%+d", -250);
  sprintf(buff, "%+d", -250);
  ck_assert_pstr_eq(s21_buff, buff);
}
END_TEST

START_TEST(flag_plus_zero) {
  char s21_buff[100] = "";
  char buff[100] = "";
  s21_sprintf(s21_buff, "result: %+d", 0);
  sprintf(buff, "result: %+d", 0);
  ck_assert_pstr_eq(s21_buff, buff);
}
END_TEST

START_TEST(flag_space_simple_test) {
  char s21_buff[100] = "";
  char buff[100] = "";
  s21_sprintf(s21_buff, "result: % d", 25);
  sprintf(buff, "result: % d", 25);
  ck_assert_pstr_eq(s21_buff, buff);
}
END_TEST

START_TEST(flag_space_negative_number) {
  char s21_buff[100] = "";
  char buff[100] = "";
  s21_sprintf(s21_buff, "% d", -1000);
  sprintf(buff, "% d", -1000);

  ck_assert_pstr_eq(s21_buff, buff);
}
END_TEST

START_TEST(flag_space_zero) {
  char s21_buff[100] = "";
  char buff[100] = "";
  s21_sprintf(s21_buff, "% d", 0);
  sprintf(buff, "% d", 0);
  ck_assert_pstr_eq(s21_buff, buff);
}
END_TEST

START_TEST(x_simple_test) {
  char s21_buff[100] = "";
  char buff[100] = "";
  s21_sprintf(s21_buff, "%x", 15);
  sprintf(buff, "%x", 15);
  ck_assert_pstr_eq(s21_buff, buff);
}
END_TEST

START_TEST(X_simple_test) {
  char s21_buff[100] = "";
  char buff[100] = "";
  s21_sprintf(s21_buff, "%X", 11);
  sprintf(buff, "%X", 11);
  ck_assert_pstr_eq(s21_buff, buff);
}
END_TEST

START_TEST(x_big_number) {
  char s21_buff[100] = "";
  char buff[100] = "";
  s21_sprintf(s21_buff, "%x", 1505);
  sprintf(buff, "%x", 1505);
  ck_assert_pstr_eq(s21_buff, buff);
}
END_TEST

START_TEST(X_big_number) {
  char s21_buff[100] = "";
  char buff[100] = "";
  s21_sprintf(s21_buff, "%X", 12345678);
  sprintf(buff, "%X", 12345678);
  ck_assert_pstr_eq(s21_buff, buff);
}
END_TEST

START_TEST(x_zero) {
  char s21_buff[100] = "";
  char buff[100] = "";
  s21_sprintf(s21_buff, "%x", 0);
  sprintf(buff, "%x", 0);
  ck_assert_pstr_eq(s21_buff, buff);
}
END_TEST

START_TEST(X_zero) {
  char s21_buff[100] = "";
  char buff[100] = "";
  s21_sprintf(s21_buff, "%X", 0);
  sprintf(buff, "%X", 0);
  ck_assert_pstr_eq(s21_buff, buff);
}
END_TEST

START_TEST(o_simple_test) {
  char s21_buff[100] = "";
  char buff[100] = "";
  s21_sprintf(s21_buff, "%o", 10);
  sprintf(buff, "%o", 10);
  ck_assert_pstr_eq(s21_buff, buff);
}
END_TEST

START_TEST(o_before_eight) {
  char s21_buff[100] = "";
  char buff[100] = "";
  s21_sprintf(s21_buff, "%o", 7);
  sprintf(buff, "%o", 7);
  ck_assert_pstr_eq(s21_buff, buff);
}
END_TEST

START_TEST(o_zero) {
  char s21_buff[100] = "";
  char buff[100] = "";
  s21_sprintf(s21_buff, "%o", 0);
  sprintf(buff, "%o", 0);
  ck_assert_pstr_eq(s21_buff, buff);
}
END_TEST

START_TEST(o_big_number) {
  char s21_buff[100] = "";
  char buff[100] = "";
  s21_sprintf(s21_buff, "%o", 12345678);
  sprintf(buff, "%o", 12345678);
  ck_assert_pstr_eq(s21_buff, buff);
}
END_TEST

START_TEST(u_uint_max) {
  char s21_buff[100] = "";
  char buff[100] = "";
  unsigned int number = UINT_MAX;
  s21_sprintf(s21_buff, "%u", number);
  sprintf(buff, "%u", number);
  ck_assert_pstr_eq(s21_buff, buff);
}
END_TEST

START_TEST(u_int_max) {
  char s21_buff[100] = "";
  char buff[100] = "";
  int number = INT_MAX;
  s21_sprintf(s21_buff, "%u", number);
  sprintf(buff, "%u", number);
  ck_assert_pstr_eq(s21_buff, buff);
}
END_TEST

START_TEST(u_negative_number) {
  char s21_buff[100] = "";
  char buff[100] = "";
  int number = -100;
  s21_sprintf(s21_buff, "%u", number);
  sprintf(buff, "%u", number);
  ck_assert_pstr_eq(s21_buff, buff);
}
END_TEST

START_TEST(u_int_max_plus_number) {
  char s21_buff[100] = "";
  char buff[100] = "";
  unsigned int number = (unsigned int)INT_MAX + 100;
  s21_sprintf(s21_buff, "%u", number);
  sprintf(buff, "%u", number);
  ck_assert_pstr_eq(s21_buff, buff);
}
END_TEST

START_TEST(u_with_zero) {
  char s21_buff[100] = "";
  char buff[100] = "";
  int number = 0;
  s21_sprintf(s21_buff, "%u", number);
  sprintf(buff, "%u", number);
  ck_assert_pstr_eq(s21_buff, buff);
}
END_TEST

START_TEST(d_width) {
  char s21_buff[100] = "";
  char buff[100] = "";
  s21_sprintf(s21_buff, "%5d", 1568);
  sprintf(buff, "%5d", 1568);
  ck_assert_pstr_eq(s21_buff, buff);
}
END_TEST

START_TEST(f_width) {
  char s21_buff[100] = "";
  char buff[100] = "";
  s21_sprintf(s21_buff, "%4f", 15.15);
  sprintf(buff, "%4f", 15.15);
  ck_assert_pstr_eq(s21_buff, buff);
}
END_TEST

START_TEST(c_width) {
  char s21_buff[100] = "";
  char buff[100] = "";
  s21_sprintf(s21_buff, "%10c", 'z');
  sprintf(buff, "%10c", 'z');
  ck_assert_pstr_eq(s21_buff, buff);
}
END_TEST

START_TEST(s_width) {
  char s21_buff[100] = "";
  char buff[100] = "";
  s21_sprintf(s21_buff, "%3s", "Hello, world!");
  sprintf(buff, "%3s", "Hello, world!");
  ck_assert_pstr_eq(s21_buff, buff);
}
END_TEST

START_TEST(o_width) {
  char s21_buff[100] = "";
  char buff[100] = "";
  s21_sprintf(s21_buff, "%4o", 256);
  sprintf(buff, "%4o", 256);
  ck_assert_pstr_eq(s21_buff, buff);
}
END_TEST

START_TEST(x_width) {
  char s21_buff[100] = "";
  char buff[100] = "";
  s21_sprintf(s21_buff, "%15x", 15);
  sprintf(buff, "%15x", 15);
  ck_assert_pstr_eq(s21_buff, buff);
}
END_TEST

START_TEST(u_width) {
  char s21_buff[100] = "";
  char buff[100] = "";
  s21_sprintf(s21_buff, "%8u", 15678940);
  sprintf(buff, "%8u", 15678940);
  ck_assert_pstr_eq(s21_buff, buff);
}
END_TEST

START_TEST(percent_one) {
  char s21_buff[100] = "";
  char buff[100] = "";
  s21_sprintf(s21_buff, "%% %d", 1);
  sprintf(buff, "%% %d", 1);
  ck_assert_pstr_eq(s21_buff, buff);
}
END_TEST

START_TEST(percent_some) {
  char s21_buff[100] = "";
  char buff[100] = "";
  s21_sprintf(s21_buff, "%%%%%% %f", 1.0);
  sprintf(buff, "%%%%%% %f", 1.0);
  ck_assert_pstr_eq(s21_buff, buff);
}
END_TEST

START_TEST(l_d) {
  char s21_buff[100] = "";
  char buff[100] = "";
  long int d = 1234567890;
  s21_sprintf(s21_buff, "%ld", d);
  sprintf(buff, "%ld", d);
  ck_assert_pstr_eq(s21_buff, buff);
}
END_TEST

START_TEST(l_o) {
  char s21_buff[100] = "";
  char buff[100] = "";
  long int o = 84518;
  s21_sprintf(s21_buff, "%lo", o);
  sprintf(buff, "%lo", o);
  ck_assert_pstr_eq(s21_buff, buff);
}
END_TEST

START_TEST(l_u) {
  char s21_buff[100] = "";
  char buff[100] = "";
  unsigned long int u = 1234567890;
  s21_sprintf(s21_buff, "%lu", u);
  sprintf(buff, "%lu", u);
  ck_assert_pstr_eq(s21_buff, buff);
}
END_TEST

START_TEST(l_x) {
  char s21_buff[100] = "";
  char buff[100] = "";
  long int x = 15;
  s21_sprintf(s21_buff, "%lx", x);
  sprintf(buff, "%lx", x);
  ck_assert_pstr_eq(s21_buff, buff);
}
END_TEST

START_TEST(short_int_uns_oct_hex) {
  char s21_buff[100] = "";
  char buff[100] = "";
  short int y = 16;
  unsigned short int x = 15;
  s21_sprintf(s21_buff, "%hd %hu %ho %hx", y, x, x, x);
  sprintf(buff, "%hd %hu %ho %hx", y, x, x, x);
  ck_assert_pstr_eq(s21_buff, buff);
}
END_TEST

START_TEST(left_justify_plus_short) {
  char s21_buff[100] = "";
  char buff[100] = "";
  short int y = 16;
  unsigned short int x = 15;
  s21_sprintf(s21_buff, "%-10hd %-5hu %-7ho %-2hx", y, x, x, x);
  sprintf(buff, "%-10hd %-5hu %-7ho %-2hx", y, x, x, x);
  ck_assert_pstr_eq(s21_buff, buff);
}
END_TEST

START_TEST(left_justify) {
  char s21_buff[100] = "";
  char buff[100] = "";
  int x = 15;
  s21_sprintf(s21_buff, "%-10d %-5d %-7d %-2d", x, x, x, x);
  sprintf(buff, "%-10d %-5d %-7d %-2d", x, x, x, x);
  ck_assert_pstr_eq(s21_buff, buff);
}
END_TEST

START_TEST(short_border_numbers) {
  char s21_buff[100] = "";
  char buff[100] = "";
  unsigned short x = USHRT_MAX;
  short int y = SHRT_MAX;
  s21_sprintf(s21_buff, "%hd %hu %hx %ho", y, x, x, x);
  sprintf(buff, "%hd %hu %hx %ho", y, x, x, x);
  ck_assert_pstr_eq(s21_buff, buff);
}
END_TEST

START_TEST(e_simple_test) {
  char s21_buff[100] = "";
  char buff[100] = "";
  double num = 123.456;
  s21_sprintf(s21_buff, "%e", num);
  sprintf(buff, "%e", num);
  ck_assert_pstr_eq(s21_buff, buff);
}
END_TEST

START_TEST(E_simple_test) {
  char s21_buff[100] = "";
  char buff[100] = "";
  double num = 123.456;
  s21_sprintf(s21_buff, "%E", num);
  sprintf(buff, "%E", num);
  ck_assert_pstr_eq(s21_buff, buff);
}
END_TEST

START_TEST(e_small_number) {
  char s21_buff[100] = "";
  char buff[100] = "";
  double num = 0.000123;
  s21_sprintf(s21_buff, "%e", num);
  sprintf(buff, "%e", num);
  ck_assert_pstr_eq(s21_buff, buff);
}
END_TEST

START_TEST(e_big_number) {
  char s21_buff[100] = "";
  char buff[100] = "";
  double num = 123456789.0;
  s21_sprintf(s21_buff, "%e", num);
  sprintf(buff, "%e", num);
  ck_assert_pstr_eq(s21_buff, buff);
}
END_TEST

START_TEST(e_negative_number) {
  char s21_buff[100] = "";
  char buff[100] = "";
  double num = -123.456;
  s21_sprintf(s21_buff, "%e", num);
  sprintf(buff, "%e", num);
  ck_assert_pstr_eq(s21_buff, buff);
}
END_TEST

START_TEST(e_zero) {
  char s21_buff[100] = "";
  char buff[100] = "";
  double num = 0.0;
  s21_sprintf(s21_buff, "%e", num);
  sprintf(buff, "%e", num);
  ck_assert_pstr_eq(s21_buff, buff);
}
END_TEST

START_TEST(e_precision) {
  char s21_buff[100] = "";
  char buff[100] = "";
  double num = 123.456789;
  s21_sprintf(s21_buff, "%.2e", num);
  sprintf(buff, "%.2e", num);
  ck_assert_pstr_eq(s21_buff, buff);
}
END_TEST

START_TEST(g_simple_test) {
  char s21_buff[100] = "";
  char buff[100] = "";
  double num = 123.456;
  s21_sprintf(s21_buff, "%g", num);
  sprintf(buff, "%g", num);
  ck_assert_pstr_eq(s21_buff, buff);
}
END_TEST

START_TEST(G_simple_test) {
  char s21_buff[100] = "";
  char buff[100] = "";
  double num = 123.456;
  s21_sprintf(s21_buff, "%G", num);
  sprintf(buff, "%G", num);
  ck_assert_pstr_eq(s21_buff, buff);
}
END_TEST

START_TEST(g_small_number) {
  char s21_buff[100] = "";
  char buff[100] = "";
  double num = 0.0001;
  s21_sprintf(s21_buff, "%g", num);
  sprintf(buff, "%g", num);
  ck_assert_pstr_eq(s21_buff, buff);
}
END_TEST

START_TEST(g_big_number) {
  char s21_buff[100] = "";
  char buff[100] = "";
  double num = 1234567.0;
  s21_sprintf(s21_buff, "%g", num);
  sprintf(buff, "%g", num);
  ck_assert_pstr_eq(s21_buff, buff);
}
END_TEST

START_TEST(g_zero) {
  char s21_buff[100] = "";
  char buff[100] = "";
  double num = 0.0;
  s21_sprintf(s21_buff, "%g", num);
  sprintf(buff, "%g", num);
  ck_assert_pstr_eq(s21_buff, buff);
}
END_TEST

START_TEST(g_precision) {
  char s21_buff[100] = "";
  char buff[100] = "";
  double num = 123.456789;
  s21_sprintf(s21_buff, "%.3g", num);
  sprintf(buff, "%.3g", num);
  ck_assert_pstr_eq(s21_buff, buff);
}
END_TEST

START_TEST(p_simple_test) {
  char s21_buff[100] = "";
  char buff[100] = "";
  int x = 42;
  s21_sprintf(s21_buff, "%p", &x);
  sprintf(buff, "%p", &x);
  ck_assert_pstr_eq(s21_buff, buff);
}
END_TEST

START_TEST(p_null_pointer) {
  char s21_buff[100] = "";
  char buff[100] = "";
  void *ptr = s21_NULL;
  s21_sprintf(s21_buff, "%p", ptr);
  sprintf(buff, "%p", ptr);
  ck_assert_pstr_eq(s21_buff, buff);
}
END_TEST

START_TEST(p_with_width) {
  char s21_buff[100] = "";
  char buff[100] = "";
  int x = 42;
  s21_sprintf(s21_buff, "%20p", &x);
  sprintf(buff, "%20p", &x);
  ck_assert_pstr_eq(s21_buff, buff);
}
END_TEST

START_TEST(hash_flag_x) {
  char s21_buff[100] = "";
  char buff[100] = "";
  s21_sprintf(s21_buff, "%#x", 255);
  sprintf(buff, "%#x", 255);
  ck_assert_pstr_eq(s21_buff, buff);
}
END_TEST

START_TEST(hash_flag_X) {
  char s21_buff[100] = "";
  char buff[100] = "";
  s21_sprintf(s21_buff, "%#X", 255);
  sprintf(buff, "%#X", 255);
  ck_assert_pstr_eq(s21_buff, buff);
}
END_TEST

START_TEST(hash_flag_o) {
  char s21_buff[100] = "";
  char buff[100] = "";
  s21_sprintf(s21_buff, "%#o", 64);
  sprintf(buff, "%#o", 64);
  ck_assert_pstr_eq(s21_buff, buff);
}
END_TEST

START_TEST(hash_flag_x_zero) {
  char s21_buff[100] = "";
  char buff[100] = "";
  s21_sprintf(s21_buff, "%#x", 0);
  sprintf(buff, "%#x", 0);
  ck_assert_pstr_eq(s21_buff, buff);
}
END_TEST

START_TEST(hash_flag_o_zero) {
  char s21_buff[100] = "";
  char buff[100] = "";
  s21_sprintf(s21_buff, "%#o", 0);
  sprintf(buff, "%#o", 0);
  ck_assert_pstr_eq(s21_buff, buff);
}
END_TEST

START_TEST(zero_flag_d) {
  char s21_buff[100] = "";
  char buff[100] = "";
  s21_sprintf(s21_buff, "%08d", 123);
  sprintf(buff, "%08d", 123);
  ck_assert_pstr_eq(s21_buff, buff);
}
END_TEST

START_TEST(zero_flag_negative) {
  char s21_buff[100] = "";
  char buff[100] = "";
  s21_sprintf(s21_buff, "%08d", -123);
  sprintf(buff, "%08d", -123);
  ck_assert_pstr_eq(s21_buff, buff);
}
END_TEST

START_TEST(zero_flag_x) {
  char s21_buff[100] = "";
  char buff[100] = "";
  s21_sprintf(s21_buff, "%08x", 255);
  sprintf(buff, "%08x", 255);
  ck_assert_pstr_eq(s21_buff, buff);
}
END_TEST

START_TEST(zero_flag_f) {
  char s21_buff[100] = "";
  char buff[100] = "";
  s21_sprintf(s21_buff, "%010.2f", 123.45);
  sprintf(buff, "%010.2f", 123.45);
  ck_assert_pstr_eq(s21_buff, buff);
}
END_TEST

START_TEST(width_asterisk) {
  char s21_buff[100] = "";
  char buff[100] = "";
  s21_sprintf(s21_buff, "%*d", 10, 123);
  sprintf(buff, "%*d", 10, 123);
  ck_assert_pstr_eq(s21_buff, buff);
}
END_TEST

START_TEST(width_asterisk_negative) {
  char s21_buff[100] = "";
  char buff[100] = "";
  s21_sprintf(s21_buff, "%*d", -10, 123);
  sprintf(buff, "%*d", -10, 123);
  ck_assert_pstr_eq(s21_buff, buff);
}
END_TEST

START_TEST(width_asterisk_string) {
  char s21_buff[100] = "";
  char buff[100] = "";
  s21_sprintf(s21_buff, "%*s", 15, "hello");
  sprintf(buff, "%*s", 15, "hello");
  ck_assert_pstr_eq(s21_buff, buff);
}
END_TEST

START_TEST(precision_asterisk) {
  char s21_buff[100] = "";
  char buff[100] = "";
  s21_sprintf(s21_buff, "%.*f", 3, 123.456789);
  sprintf(buff, "%.*f", 3, 123.456789);
  ck_assert_pstr_eq(s21_buff, buff);
}
END_TEST

START_TEST(precision_asterisk_string) {
  char s21_buff[100] = "";
  char buff[100] = "";
  s21_sprintf(s21_buff, "%.*s", 3, "hello world");
  sprintf(buff, "%.*s", 3, "hello world");
  ck_assert_pstr_eq(s21_buff, buff);
}
END_TEST

START_TEST(precision_asterisk_negative) {
  char s21_buff[100] = "";
  char buff[100] = "";
  s21_sprintf(s21_buff, "%.*f", -1, 123.456);
  sprintf(buff, "%.*f", -1, 123.456);
  ck_assert_pstr_eq(s21_buff, buff);
}
END_TEST

START_TEST(L_modifier_f) {
  char s21_buff[100] = "";
  char buff[100] = "";
  long double num = 123.456L;
  s21_sprintf(s21_buff, "%Lf", num);
  sprintf(buff, "%Lf", num);
  ck_assert_pstr_eq(s21_buff, buff);
}
END_TEST

START_TEST(L_modifier_e) {
  char s21_buff[100] = "";
  char buff[100] = "";
  long double num = 123.456L;
  s21_sprintf(s21_buff, "%Le", num);
  sprintf(buff, "%Le", num);
  ck_assert_pstr_eq(s21_buff, buff);
}
END_TEST

START_TEST(L_modifier_g) {
  char s21_buff[100] = "";
  char buff[100] = "";
  long double num = 123.456L;
  s21_sprintf(s21_buff, "%Lg", num);
  sprintf(buff, "%Lg", num);
  ck_assert_pstr_eq(s21_buff, buff);
}
END_TEST

START_TEST(combined_flags_width_precision) {
  char s21_buff[100] = "";
  char buff[100] = "";
  s21_sprintf(s21_buff, "%+010.2f", 123.456);
  sprintf(buff, "%+010.2f", 123.456);
  ck_assert_pstr_eq(s21_buff, buff);
}
END_TEST

START_TEST(combined_hash_zero_width) {
  char s21_buff[100] = "";
  char buff[100] = "";
  s21_sprintf(s21_buff, "%#08x", 255);
  sprintf(buff, "%#08x", 255);
  ck_assert_pstr_eq(s21_buff, buff);
}
END_TEST

START_TEST(combined_asterisk_width_precision) {
  char s21_buff[100] = "";
  char buff[100] = "";
  s21_sprintf(s21_buff, "%*.*f", 10, 2, 123.456);
  sprintf(buff, "%*.*f", 10, 2, 123.456);
  ck_assert_pstr_eq(s21_buff, buff);
}
END_TEST

START_TEST(left_justify_zero_flag) {
  char s21_buff[100] = "";
  char buff[100] = "";
  s21_sprintf(s21_buff, "%-8d", 123);
  sprintf(buff, "%-8d", 123);
  ck_assert_pstr_eq(s21_buff, buff);
}
END_TEST

START_TEST(zero_flag_ignored_with_minus) {
  char s21_buff[100] = "";
  char expected_buff[100] = "";

  s21_sprintf(s21_buff, "%-08d", 123);
  sprintf(expected_buff, "%-8d", 123);

  ck_assert_pstr_eq(s21_buff, expected_buff);
}
END_TEST

START_TEST(precision_with_zero_flag) {
  char s21_buff[100] = "";
  char buff[100] = "";
  s21_sprintf(s21_buff, "%08.3d", 123);
  sprintf(buff, "%8.3d", 123);
  ck_assert_pstr_eq(s21_buff, buff);
}
END_TEST

START_TEST(zero_flag_with_precision_ignored) {
  char s21_buff[100] = "";
  char buff[100] = "";

  s21_sprintf(s21_buff, "%08.5d", 123);
  sprintf(buff, "%8.5d", 123);
  ck_assert_pstr_eq(s21_buff, buff);
}
END_TEST

START_TEST(multiple_flags_combination) {
  char s21_buff[100] = "";
  char buff[100] = "";
  s21_sprintf(s21_buff, "%+- 10d", 123);
  sprintf(buff, "%+-10d", 123);
  ck_assert_pstr_eq(s21_buff, buff);
}
END_TEST

START_TEST(test_s21_itoa_zero) {
  char buf[50];
  int len = s21_itoa(0, buf);
  ck_assert_int_eq(len, 1);
  ck_assert_str_eq(buf, "0");
}
END_TEST

START_TEST(test_s21_itoa_positive) {
  char buf[50];
  int len = s21_itoa(12345, buf);
  ck_assert_int_eq(len, 5);
  ck_assert_str_eq(buf, "12345");
}
END_TEST

START_TEST(test_s21_itoa_negative) {
  char buf[50];
  int len = s21_itoa(-9876, buf);
  ck_assert_int_eq(len, 5);
  ck_assert_str_eq(buf, "-9876");
}
END_TEST

START_TEST(test_s21_utoa_zero) {
  char buf[50];
  s21_utoa(0, buf);
  ck_assert_str_eq(buf, "0");
}
END_TEST

START_TEST(test_s21_utoa_large) {
  char buf[50];
  s21_utoa(4294967295UL, buf);
  ck_assert_str_eq(buf, "4294967295");
}
END_TEST

START_TEST(test_s21_utoa_base_hex_lower) {
  char buf[50];
  s21_utoa_base(255, buf, 16, 0);
  ck_assert_str_eq(buf, "ff");
}
END_TEST

START_TEST(test_s21_utoa_base_hex_upper) {
  char buf[50];
  s21_utoa_base(255, buf, 16, 1);
  ck_assert_str_eq(buf, "FF");
}
END_TEST

START_TEST(test_s21_utoa_base_binary) {
  char buf[50];
  s21_utoa_base(5, buf, 2, 0);
  ck_assert_str_eq(buf, "101");
}
END_TEST

START_TEST(test_s21_ftoa_simple) {
  char buf[100];
  s21_ftoa(123.456, buf, 2);
  ck_assert_str_eq(buf, "123.46");
}
END_TEST

START_TEST(test_s21_ftoa_negative) {
  char buf[100];
  s21_ftoa(-123.456, buf, 3);
  printf("s21_ftoa output: '%s'\n", buf);
  ck_assert_str_eq(buf, "-123.456");
}
END_TEST

START_TEST(test_ftoa_rounding_overflow) {
  char buffer[100];
  double num = 1.9999999;

  s21_ftoa(num, buffer, 6);

  ck_assert_str_eq(buffer, "2.000000");
}
END_TEST

START_TEST(test_s21_etoa_rounding_overflow) {
  char str[100];

  double num = 9.999999;
  int precision = 5;
  int uppercase = 0;

  s21_etoa(num, str, precision, uppercase);

  ck_assert(strncmp(str, "1.00000e+01", 11) == 0);

  s21_etoa(num, str, precision, 1);
  ck_assert(strncmp(str, "1.00000E+01", 11) == 0);
}
END_TEST

START_TEST(test_s21_gtoa_negative) {
  char str[100];

  double num = -1234.5678;
  int precision = 6;
  int uppercase = 0;

  s21_gtoa(num, str, precision, uppercase);

  ck_assert(str[0] == '-');

  ck_assert(strstr(str, "e") != NULL || strchr(str, '.') != NULL);
}
END_TEST

START_TEST(test_s21_ptoa_null_pointer) {
  char str[100] = {0};
  s21_ptoa(NULL, str);
  ck_assert_str_eq(str, "(nil)");
}
END_TEST

START_TEST(test_s21_sprintf_u_basic) {
  char buffer[100] = {0};
  s21_sprintf(buffer, "%u", 12345);
  ck_assert_str_eq(buffer, "12345");
}
END_TEST

START_TEST(test_s21_sprintf_u_width) {
  char buffer[100] = {0};
  s21_sprintf(buffer, "%10u", 12345);
  ck_assert_str_eq(buffer, "     12345");
}
END_TEST

START_TEST(test_s21_sprintf_u_width_minus) {
  char buffer[100] = {0};
  s21_sprintf(buffer, "%-10u", 12345);
  ck_assert_str_eq(buffer, "12345     ");
}
END_TEST

START_TEST(test_s21_sprintf_u_precision) {
  char buffer[100] = {0};
  s21_sprintf(buffer, "%.8u", 12345);
  ck_assert_str_eq(buffer, "00012345");
}
END_TEST

START_TEST(test_s21_sprintf_u_width_precision) {
  char buffer[100] = {0};
  s21_sprintf(buffer, "%10.8u", 12345);
  ck_assert_str_eq(buffer, "  00012345");
}
END_TEST

START_TEST(test_s21_sprintf_u_width_precision_minus) {
  char buffer[100] = {0};
  s21_sprintf(buffer, "%-10.8u", 12345);
  ck_assert_str_eq(buffer, "00012345  ");
}
END_TEST

START_TEST(test_s21_sprintf_u_zero_flag) {
  char buffer[100] = {0};
  s21_sprintf(buffer, "%010u", 12345);
  ck_assert_str_eq(buffer, "0000012345");
}
END_TEST

START_TEST(test_s21_sprintf_u_zero_flag_precision) {
  char buffer[100] = {0};
  s21_sprintf(buffer, "%010.8u", 12345);
  ck_assert_str_eq(buffer, "  00012345");
}
END_TEST

START_TEST(test_s21_sprintf_f_precision) {
  char str[100];
  s21_sprintf(str, "%.2f", 123.456);
  ck_assert_str_eq(str, "123.46");
}
END_TEST

/*START_TEST(test_s21_sprintf_f_width) {
  char str[100];
  s21_sprintf(str, "%10f", 123.456);
  ck_assert_str_eq(str, " 123.456000");
}
END_TEST */

/*START_TEST(test_s21_sprintf_f_width_minus) {
  char str[100];
  s21_sprintf(str, "%-10f", 123.456);
  ck_assert_str_eq(str, "123.456000 ");
}
END_TEST*/

START_TEST(test_s21_sprintf_f_plus_flag) {
  char str[100];
  s21_sprintf(str, "%+f", 123.456);
  ck_assert_str_eq(str, "+123.456000");
}
END_TEST

START_TEST(test_s21_sprintf_f_zero_flag) {
  char str[100];
  s21_sprintf(str, "%010.2f", 123.456);
  ck_assert_str_eq(str, "0000123.46");
}
END_TEST

START_TEST(test_s21_sprintf_f_negative) {
  char str[100];
  s21_sprintf(str, "%f", -123.456);
  ck_assert_str_eq(str, "-123.456000");
}
END_TEST

START_TEST(test_s21_sprintf_f_zero_value) {
  char str[100];
  s21_sprintf(str, "%f", 0.0);
  ck_assert_str_eq(str, "0.000000");
}
END_TEST

/*START_TEST(test_s21_sprintf_f_zero_flag_neg_num) {
  char str[100];
  s21_sprintf(str, "%010f", -12.34);
  ck_assert_str_eq(str, "-00012.340000");
}
END_TEST*/

/*START_TEST(test_s21_sprintf_f_plus_zero_flag) {
  char str[100];
  s21_sprintf(str, "%+010f", 12.34);
  ck_assert_str_eq(str, "+00012.340000");
}
END_TEST*/

START_TEST(test_s21_sprintf_f_space_flag_width) {
  char str[100];
  s21_sprintf(str, "% 10f", 12.34);
  ck_assert_str_eq(str, " 12.340000");
}
END_TEST

START_TEST(test_s21_sprintf_f_minus_flag_width) {
  char str[100];
  s21_sprintf(str, "%-10f", 12.34);
  ck_assert_str_eq(str, "12.340000 ");
}
END_TEST

START_TEST(test_s21_sprintf_f_basic) {
  char str[100];
  s21_sprintf(str, "%f", 12.345);
  ck_assert_str_eq(str, "12.345000");
}
END_TEST

/*START_TEST(test_s21_sprintf_f_neg_num_zero_flag_width) {
  char str[100];
  s21_sprintf(str, "%010f", -12.34);
  ck_assert_str_eq(str, "-00012.340000");
}
END_TEST*/

/*START_TEST(test_s21_sprintf_f_plus_flag_zero_flag_width) {
  char str[100];
  s21_sprintf(str, "%+010f", 12.34);
  ck_assert_str_eq(str, "+00012.340000");
}
END_TEST*/

START_TEST(test_s21_sprintf_unknown_specifier) {
  char str[100];

  s21_sprintf(str, "Hello %q world");
  ck_assert_str_eq(str, "Hello %q world");

  s21_sprintf(str, "Percent %% and unknown %z");
  ck_assert_str_eq(str, "Percent % and unknown %z");
}
END_TEST

START_TEST(test_s21_sprintf_octal_basic) {
  char str[100];

  s21_sprintf(str, "%o", 83);
  ck_assert_str_eq(str, "123");

  s21_sprintf(str, "%#o", 83);
  ck_assert_str_eq(str, "0123");

  s21_sprintf(str, "%08o", 83);
  ck_assert_str_eq(str, "00000123");

  s21_sprintf(str, "%.5o", 83);
  ck_assert_str_eq(str, "00123");

  /*s21_sprintf(str, "%#8.5o", 83);
  ck_assert_str_eq(str, "  00123");*/

  s21_sprintf(str, "%#o", 0);
  ck_assert_str_eq(str, "0");

  s21_sprintf(str, "%-8o", 83);
  ck_assert_str_eq(str, "123     ");
}
END_TEST

START_TEST(test_s21_sprintf_hex_basic) {
  char str[100];

  s21_sprintf(str, "%x", 48879);
  ck_assert_str_eq(str, "beef");

  s21_sprintf(str, "%X", 48879);
  ck_assert_str_eq(str, "BEEF");

  s21_sprintf(str, "%#x", 48879);
  ck_assert_str_eq(str, "0xbeef");

  s21_sprintf(str, "%#X", 48879);
  ck_assert_str_eq(str, "0XBEEF");

  s21_sprintf(str, "%08x", 48879);
  ck_assert_str_eq(str, "0000beef");

  s21_sprintf(str, "%#010x", 48879);
  ck_assert_str_eq(str, "0x0000beef");

  s21_sprintf(str, "%.6x", 48879);
  ck_assert_str_eq(str, "00beef");

  s21_sprintf(str, "%#12.6x", 48879);
  ck_assert_str_eq(str, "    0x00beef");

  s21_sprintf(str, "%#x", 0);
  ck_assert_str_eq(str, "0");

  s21_sprintf(str, "%-#12x", 48879);
  ck_assert_str_eq(str, "0xbeef      ");
}
END_TEST

START_TEST(test_s21_sprintf_char_basic) {
  char str[100];

  s21_sprintf(str, "%c", 'A');
  ck_assert_str_eq(str, "A");

  s21_sprintf(str, "%5c", 'B');
  ck_assert_str_eq(str, "    B");

  s21_sprintf(str, "%-5c", 'C');
  ck_assert_str_eq(str, "C    ");
}
END_TEST

START_TEST(test_s21_sprintf_string_basic) {
  char str[100];

  s21_sprintf(str, "%s", "Hello");
  ck_assert_str_eq(str, "Hello");

  s21_sprintf(str, "%10s", "Hi");
  ck_assert_str_eq(str, "        Hi");

  s21_sprintf(str, "%-10s", "Hi");
  ck_assert_str_eq(str, "Hi        ");

  s21_sprintf(str, "%.3s", "abcdef");
  ck_assert_str_eq(str, "abc");

  s21_sprintf(str, "%8.4s", "abcdef");
  ck_assert_str_eq(str, "    abcd");

  s21_sprintf(str, "%s", NULL);
  ck_assert_str_eq(str, "(null)");
}
END_TEST

START_TEST(test_s21_sprintf_pointer_basic) {
  char str[100];
  void *ptr = (void *)0x1234abcd;

  s21_sprintf(str, "%p", ptr);

  ck_assert(strncmp(str, "0x", 2) == 0);
  ck_assert(strlen(str) > 2);

  s21_sprintf(str, "%p", NULL);
  ck_assert_str_eq(str, "(nil)");

  s21_sprintf(str, "%20p", ptr);
  ck_assert(strlen(str) >= 20);

  ck_assert(strstr(str, "0x") != NULL);

  s21_sprintf(str, "%-20p", ptr);
  ck_assert(strlen(str) >= 20);
  ck_assert(strstr(str, "0x") != NULL);

  ck_assert(str[19] == ' ' || str[19] == '\0' || isspace(str[19]));
}
END_TEST

START_TEST(test_s21_sprintf_g_basic) {
  char str[100];

  double val = 123.456;
  s21_sprintf(str, "%g", val);

  ck_assert(strlen(str) > 0);
  ck_assert(strstr(str, "123") != NULL);

  s21_sprintf(str, "%.2g", val);

  ck_assert(strlen(str) > 0);

  s21_sprintf(str, "%10g", val);
  ck_assert(strlen(str) >= 10);

  s21_sprintf(str, "%-10g", val);
  ck_assert(strlen(str) >= 10);

  ck_assert(str[9] == ' ');

  s21_sprintf(str, "%G", 0.0001234);
  ck_assert(strlen(str) > 0);

  // ck_assert(strchr(str, 'E') != NULL);
}
END_TEST

START_TEST(test_s21_sprintf_e_basic) {
  char str[100];

  double val = 12345.6789;

  s21_sprintf(str, "%e", val);
  ck_assert(strlen(str) > 0);
  ck_assert(strchr(str, 'e') != NULL);

  s21_sprintf(str, "%.2e", val);
  ck_assert(strlen(str) > 0);

  s21_sprintf(str, "%15e", val);
  ck_assert(strlen(str) >= 15);

  s21_sprintf(str, "%-15e", val);
  ck_assert(strlen(str) >= 15);
  ck_assert(str[14] == ' ');

  s21_sprintf(str, "%E", val);
  ck_assert(strlen(str) > 0);
  ck_assert(strchr(str, 'E') != NULL);
}
END_TEST

START_TEST(test_s21_sprintf_f_sign_and_padding) {
  char str[100];

  s21_sprintf(str, "%010f", -3.14);
  ck_assert(str[0] == '-');
  ck_assert(strlen(str) == 10);

  s21_sprintf(str, "%+010f", 3.14);
  ck_assert(str[0] == '+');
  ck_assert(strlen(str) == 10);

  s21_sprintf(str, "% 10f", 3.14);
  ck_assert(str[0] == ' ' || str[1] == '3');
  ck_assert(strlen(str) == 10);

  s21_sprintf(str, "%-10f", 3.14);
  ck_assert(str[9] == ' ');
}
END_TEST

/*START_TEST(test_s21_sprintf_f_space_flag) {
  char str[100];

  s21_sprintf(str, "% 10f", 3.14);
  ck_assert(str[0] == ' ');
  ck_assert(strlen(str) == 10);

  s21_sprintf(str, "% 10f", -3.14);
  ck_assert(str[0] == ' ' || str[1] == '-');
  ck_assert(strchr(str, '-') != NULL);

  s21_sprintf(str, "%+ 10f", 3.14);
  ck_assert(str[0] == '+');
}
END_TEST*/

START_TEST(test_s21_sprintf_f_flag_space_complex) {
  char str[100];

  s21_sprintf(str, "% f", 42.5);
  ck_assert_str_eq(str, " 42.500000");

  s21_sprintf(str, "% f", -42.5);
  ck_assert_str_eq(str, "-42.500000");

  s21_sprintf(str, "%+ f", 42.5);
  ck_assert_str_eq(str, "+42.500000");

  /* s21_sprintf(str, "%10 f", 42.5);
   ck_assert_str_eq(str, "  42.500000");*/

  /*s21_sprintf(str, "%-10 f", 42.5);
  ck_assert_str_eq(str, " 42.500000 ");*/

  /* s21_sprintf(str, "% 010f", 42.5);
   ck_assert_str_eq(str, " 00042.500000");*/

  s21_sprintf(str, "% .2f", 42.567);
  ck_assert_str_eq(str, " 42.57");

  s21_sprintf(str, "% f", 0.0);
  ck_assert_str_eq(str, " 0.000000");
}
END_TEST

START_TEST(test_debug_f_format) {
  char buf[256];
  char std_buf[256];

  s21_sprintf(buf, "%010.2f", 12.34);
  sprintf(std_buf, "%010.2f", 12.34);

  ck_assert_str_eq(buf, std_buf);
}
END_TEST

Suite *suite_sprintf() {
  Suite *suite = suite_create("sprintf_suite");
  TCase *tcase_core = tcase_create("sprintf_tc");

  tcase_add_test(tcase_core, test_debug_f_format);
  tcase_add_test(tcase_core, d_simple_int);
  tcase_add_test(tcase_core, d_negative_int);
  tcase_add_test(tcase_core, d_int_in_middle_of_str);
  tcase_add_test(tcase_core, s_simple_test);
  tcase_add_test(tcase_core, s_empty_test);
  tcase_add_test(tcase_core, s_int_str_test);
  tcase_add_test(tcase_core, s_str_in_middle_of_str);
  tcase_add_test(tcase_core, f_simple);
  tcase_add_test(tcase_core, f_simple_zero);
  tcase_add_test(tcase_core, f_big_number);
  tcase_add_test(tcase_core, f_big_int_part);
  tcase_add_test(tcase_core, f_zero);
  tcase_add_test(tcase_core, exactness_simple);
  tcase_add_test(tcase_core, exactness_with_simple_rounding);
  tcase_add_test(tcase_core, exactness_with_hard_rounding);
  tcase_add_test(tcase_core, exactness_with_hard_rounding_minus);
  tcase_add_test(tcase_core, c_simple_char);
  tcase_add_test(tcase_core, c_number_ASCII);
  tcase_add_test(tcase_core, c_number_char);
  tcase_add_test(tcase_core, c_space_char);
  tcase_add_test(tcase_core, flag_plus_simple_test);
  tcase_add_test(tcase_core, flag_plus_negative_number);
  tcase_add_test(tcase_core, flag_plus_zero);
  tcase_add_test(tcase_core, flag_space_simple_test);
  tcase_add_test(tcase_core, flag_space_negative_number);
  tcase_add_test(tcase_core, flag_space_zero);
  tcase_add_test(tcase_core, x_simple_test);
  tcase_add_test(tcase_core, X_simple_test);
  tcase_add_test(tcase_core, x_big_number);
  tcase_add_test(tcase_core, X_big_number);
  tcase_add_test(tcase_core, x_zero);
  tcase_add_test(tcase_core, X_zero);
  tcase_add_test(tcase_core, o_simple_test);
  tcase_add_test(tcase_core, o_before_eight);
  tcase_add_test(tcase_core, o_zero);
  tcase_add_test(tcase_core, o_big_number);
  tcase_add_test(tcase_core, u_uint_max);
  tcase_add_test(tcase_core, u_int_max);
  tcase_add_test(tcase_core, d_width);
  tcase_add_test(tcase_core, f_width);
  tcase_add_test(tcase_core, c_width);
  tcase_add_test(tcase_core, s_width);
  tcase_add_test(tcase_core, o_width);
  tcase_add_test(tcase_core, x_width);
  tcase_add_test(tcase_core, u_width);
  tcase_add_test(tcase_core, percent_one);
  tcase_add_test(tcase_core, percent_some);
  tcase_add_test(tcase_core, l_d);
  tcase_add_test(tcase_core, l_o);
  tcase_add_test(tcase_core, l_u);
  tcase_add_test(tcase_core, l_x);
  tcase_add_test(tcase_core, u_negative_number);
  tcase_add_test(tcase_core, u_int_max_plus_number);
  tcase_add_test(tcase_core, u_with_zero);
  tcase_add_test(tcase_core, short_int_uns_oct_hex);
  tcase_add_test(tcase_core, left_justify);
  tcase_add_test(tcase_core, left_justify_plus_short);
  tcase_add_test(tcase_core, short_border_numbers);
  tcase_add_test(tcase_core, e_simple_test);
  tcase_add_test(tcase_core, E_simple_test);
  tcase_add_test(tcase_core, e_small_number);
  tcase_add_test(tcase_core, e_big_number);
  tcase_add_test(tcase_core, e_negative_number);
  tcase_add_test(tcase_core, e_zero);
  tcase_add_test(tcase_core, e_precision);
  tcase_add_test(tcase_core, g_simple_test);
  tcase_add_test(tcase_core, G_simple_test);
  tcase_add_test(tcase_core, g_small_number);
  tcase_add_test(tcase_core, g_big_number);
  tcase_add_test(tcase_core, g_zero);
  tcase_add_test(tcase_core, g_precision);
  tcase_add_test(tcase_core, p_simple_test);
  tcase_add_test(tcase_core, p_null_pointer);
  tcase_add_test(tcase_core, p_with_width);
  tcase_add_test(tcase_core, hash_flag_x);
  tcase_add_test(tcase_core, hash_flag_X);
  tcase_add_test(tcase_core, hash_flag_o);
  tcase_add_test(tcase_core, hash_flag_x_zero);
  tcase_add_test(tcase_core, hash_flag_o_zero);
  tcase_add_test(tcase_core, zero_flag_d);
  tcase_add_test(tcase_core, zero_flag_negative);
  tcase_add_test(tcase_core, zero_flag_x);
  tcase_add_test(tcase_core, zero_flag_f);
  tcase_add_test(tcase_core, width_asterisk);
  tcase_add_test(tcase_core, width_asterisk_negative);
  tcase_add_test(tcase_core, width_asterisk_string);
  tcase_add_test(tcase_core, precision_asterisk);
  tcase_add_test(tcase_core, precision_asterisk_string);
  tcase_add_test(tcase_core, precision_asterisk_negative);
  tcase_add_test(tcase_core, L_modifier_f);
  tcase_add_test(tcase_core, L_modifier_e);
  tcase_add_test(tcase_core, L_modifier_g);
  tcase_add_test(tcase_core, combined_flags_width_precision);
  tcase_add_test(tcase_core, combined_hash_zero_width);
  tcase_add_test(tcase_core, combined_asterisk_width_precision);
  tcase_add_test(tcase_core, left_justify_zero_flag);
  tcase_add_test(tcase_core, zero_flag_ignored_with_minus);
  tcase_add_test(tcase_core, precision_with_zero_flag);
  tcase_add_test(tcase_core, zero_flag_with_precision_ignored);
  tcase_add_test(tcase_core, multiple_flags_combination);
  tcase_add_test(tcase_core, test_s21_itoa_zero);
  tcase_add_test(tcase_core, test_s21_itoa_positive);
  tcase_add_test(tcase_core, test_s21_itoa_negative);
  tcase_add_test(tcase_core, test_s21_utoa_zero);
  tcase_add_test(tcase_core, test_s21_utoa_large);
  tcase_add_test(tcase_core, test_s21_utoa_base_hex_lower);
  tcase_add_test(tcase_core, test_s21_utoa_base_hex_upper);
  tcase_add_test(tcase_core, test_s21_utoa_base_binary);
  tcase_add_test(tcase_core, test_s21_ftoa_simple);
  tcase_add_test(tcase_core, test_s21_ftoa_negative);
  tcase_add_test(tcase_core, test_s21_ptoa_null_pointer);
  tcase_add_test(tcase_core, test_s21_sprintf_u_basic);
  tcase_add_test(tcase_core, test_s21_sprintf_u_width);
  tcase_add_test(tcase_core, test_s21_sprintf_u_width_minus);
  tcase_add_test(tcase_core, test_s21_sprintf_u_precision);
  tcase_add_test(tcase_core, test_s21_sprintf_u_width_precision);
  tcase_add_test(tcase_core, test_s21_sprintf_u_width_precision_minus);
  tcase_add_test(tcase_core, test_s21_sprintf_u_zero_flag);
  tcase_add_test(tcase_core, test_s21_sprintf_u_zero_flag_precision);
  tcase_add_test(tcase_core, test_ftoa_rounding_overflow);
  tcase_add_test(tcase_core, test_s21_sprintf_f_basic);
  tcase_add_test(tcase_core, test_s21_sprintf_f_precision);
  // tcase_add_test(tcase_core, test_s21_sprintf_f_width);
  // tcase_add_test(tcase_core, test_s21_sprintf_f_width_minus);
  tcase_add_test(tcase_core, test_s21_sprintf_f_plus_flag);
  // tcase_add_test(tcase_core, test_s21_sprintf_f_space_flag);
  tcase_add_test(tcase_core, test_s21_sprintf_f_zero_flag);
  tcase_add_test(tcase_core, test_s21_sprintf_f_negative);
  tcase_add_test(tcase_core, test_s21_sprintf_f_zero_value);
  // tcase_add_test(tcase_core, test_s21_sprintf_f_zero_flag_neg_num);
  // tcase_add_test(tcase_core, test_s21_sprintf_f_plus_zero_flag);
  tcase_add_test(tcase_core, test_s21_sprintf_f_space_flag_width);
  tcase_add_test(tcase_core, test_s21_sprintf_f_minus_flag_width);
  // tcase_add_test(tcase_core, test_s21_sprintf_f_neg_num_zero_flag_width);
  // tcase_add_test(tcase_core, test_s21_sprintf_f_plus_flag_zero_flag_width);
  tcase_add_test(tcase_core, test_s21_etoa_rounding_overflow);
  tcase_add_test(tcase_core, test_s21_gtoa_negative);
  tcase_add_test(tcase_core, test_s21_sprintf_unknown_specifier);
  tcase_add_test(tcase_core, test_s21_sprintf_octal_basic);
  tcase_add_test(tcase_core, test_s21_sprintf_hex_basic);
  tcase_add_test(tcase_core, test_s21_sprintf_char_basic);
  tcase_add_test(tcase_core, test_s21_sprintf_string_basic);
  tcase_add_test(tcase_core, test_s21_sprintf_pointer_basic);
  tcase_add_test(tcase_core, test_s21_sprintf_g_basic);
  tcase_add_test(tcase_core, test_s21_sprintf_e_basic);
  tcase_add_test(tcase_core, test_s21_sprintf_f_sign_and_padding);
  tcase_add_test(tcase_core, test_s21_sprintf_f_flag_space_complex);

  suite_add_tcase(suite, tcase_core);

  return suite;
}