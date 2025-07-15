#include "s21_tests.h"

#ifdef __linux__
#define S21_ERR_COUNT 132
#elif defined(__APPLE__)
#define S21_ERR_COUNT 107
#else
#define S21_ERR_COUNT 100
#endif

START_TEST(all_std_errors) {
  for (int i = -10; i < 150; i++) {
    char *s21_err = s21_strerror(i);

    ck_assert_ptr_nonnull(s21_err);
    ck_assert_int_gt(s21_strlen(s21_err), 0);

    if (i < 0 || i >= S21_ERR_COUNT) {
      ck_assert(s21_strstr(s21_err, "error") != NULL ||
                s21_strstr(s21_err, "Error") != NULL);
    }
  }

  ck_assert_str_eq(s21_strerror(0), "Success");
  ck_assert_str_eq(s21_strerror(-1), "Unknown error -1");
  ck_assert_str_eq(s21_strerror(999), "Unknown error 999");
}
END_TEST

Suite *suite_strerror() {
  Suite *suite = suite_create("strerror_suite");
  TCase *tcase_core = tcase_create("strerror_tc");

  tcase_add_test(tcase_core, all_std_errors);
  suite_add_tcase(suite, tcase_core);

  return suite;
}