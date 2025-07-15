#include "s21_string.h"

static int force_malloc_fail = 0;

void set_force_malloc_fail(int val) { force_malloc_fail = val; }

char *s21_insert(const char *src, const char *str, size_t start_index) {
  if (src == s21_NULL || str == s21_NULL) {
    return s21_NULL;
  }

  s21_size_t src_len = s21_strlen(src);
  s21_size_t str_len = s21_strlen(str);

  if (start_index > src_len) {
    return s21_NULL;
  }

  char *res = s21_NULL;
  if (!force_malloc_fail) {
    res = malloc((src_len + str_len + 1) * sizeof(char));
  }
  if (res == s21_NULL) {
    return s21_NULL;
  }

  s21_memcpy(res, src, start_index);
  s21_memcpy(res + start_index, str, str_len);
  s21_memcpy(res + start_index + str_len, src + start_index,
             src_len - start_index);
  res[src_len + str_len] = '\0';

  return res;
}
