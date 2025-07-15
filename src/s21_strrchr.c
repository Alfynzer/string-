#include "s21_string.h"

char *s21_strrchr(const char *str, int c) {
  char *mem = 0;
  s21_size_t i;

  for (i = 0; str[i] != '\0'; i++) {
    if (str[i] == (char)c) {
      mem = (char *)(str + i);
    }
  }
  if ((char)c == '\0') {
    return (char *)(str + i);
  }

  return mem;
}