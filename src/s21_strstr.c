#include "s21_string.h"

char *s21_strstr(const char *haystack, const char *needle) {
  s21_size_t i = 0, j;

  if (needle[0] == '\0') {
    return (char *)haystack;
  }
  for (i = 0; haystack[i] != '\0'; i++) {
    for (j = 0; haystack[i + j] == needle[j] && needle[j] != '\0'; j++) {
    }
    if (needle[j] == '\0') {
      return (char *)(haystack + i);
    }
  }

  return s21_NULL;
}