#include "s21_string.h"

char *s21_strncat(char *dest, const char *src, s21_size_t n) {
  char *d = dest;

  while (*d != '\0') {
    d++;
  }
  s21_size_t i;
  for (i = 0; i < n && src[i] != '\0'; i++) {
    d[i] = src[i];
  }
  d[i] = '\0';
  return dest;
}