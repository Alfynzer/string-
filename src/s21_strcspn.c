#include "s21_string.h"

size_t s21_strcspn(const char *str1, const char *str2) {
  s21_size_t i = 0;
  s21_size_t j;

  for (; str1[i] != '\0'; i++) {
    for (j = 0; str2[j] != '\0'; j++) {
      if (str1[i] == str2[j]) {
        return i;
      }
    }
  }
  return i;
}