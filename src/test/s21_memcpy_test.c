#include "s21_tests.h"

START_TEST(test_memcpy_normal_string) {
  char src[] = "Hello, world!";
  char dest1[20] = {0};
  char dest2[20] = {0};

  s21_memcpy(dest1, src, strlen(src) + 1);
  memcpy(dest2, src, strlen(src) + 1);

  ck_assert_str_eq(dest1, dest2);
}
END_TEST

START_TEST(test_memcpy_zero_bytes) {
  char src[] = "Hello";
  char dest1[] = "abcdef";
  char dest2[] = "abcdef";

  s21_memcpy(dest1, src, 0);
  memcpy(dest2, src, 0);

  ck_assert_str_eq(dest1, dest2);
}
END_TEST

START_TEST(test_memcpy_partial_string) {
  char src[] = "Hello, world!";
  char dest1[20] = "1234567890";
  char dest2[20] = "1234567890";

  s21_memcpy(dest1, src, 5);
  memcpy(dest2, src, 5);

  ck_assert_mem_eq(dest1, dest2, 10);
}
END_TEST

START_TEST(test_memcpy_binary_data) {
  unsigned char src[] = {0, 255, 128, 64, 32};
  unsigned char dest1[10] = {0};
  unsigned char dest2[10] = {0};

  s21_memcpy(dest1, src, 5);
  memcpy(dest2, src, 5);

  ck_assert_mem_eq(dest1, dest2, 5);
}
END_TEST

START_TEST(test_memcpy_overlapping_buffers) {
  char src[] = "1234567890";
  char dest1[20] = {0};
  char dest2[20] = {0};

  size_t n = strlen(src);

  s21_memcpy(dest1, src, n);
  memcpy(dest2, src, n);

  ck_assert_mem_eq(dest1, dest2, n);
}
END_TEST

START_TEST(test_memcpy_large_buffer) {
  size_t size = 1000;
  char *src = malloc(size);
  char *dest1 = malloc(size);
  char *dest2 = malloc(size);

  ck_assert_ptr_nonnull(src);
  ck_assert_ptr_nonnull(dest1);
  ck_assert_ptr_nonnull(dest2);

  for (size_t i = 0; i < size; i++) {
    src[i] = (char)(i % 256);
    dest1[i] = 0;
    dest2[i] = 0;
  }

  s21_memcpy(dest1, src, size);
  memcpy(dest2, src, size);

  ck_assert_mem_eq(dest1, dest2, size);

  free(src);
  free(dest1);
  free(dest2);
}
END_TEST

Suite *suite_memcpy(void) {
  Suite *s = suite_create("s21_memcpy");
  TCase *tc_core = tcase_create("Core");

  tcase_add_test(tc_core, test_memcpy_normal_string);
  tcase_add_test(tc_core, test_memcpy_zero_bytes);
  tcase_add_test(tc_core, test_memcpy_partial_string);
  tcase_add_test(tc_core, test_memcpy_binary_data);
  tcase_add_test(tc_core, test_memcpy_overlapping_buffers);
  tcase_add_test(tc_core, test_memcpy_large_buffer);

  suite_add_tcase(s, tc_core);
  return s;
}
