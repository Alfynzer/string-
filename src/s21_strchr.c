#include "s21_string.h"

char *s21_strchr(const char *str, int c) {
  const char *s = str;
  s21_size_t i;
  for (i = 0;; i++) {
    if (s[i] == (unsigned char)c) {
      return (char *)(s + i);
    }
    if (s[i] == '\0') {
      return s21_NULL;
    }
  }
  return s21_NULL;
}