#include "s21_string.h"

char *s21_strtok(char *str, const char *delim) {
  static char *next_token = s21_NULL;

  if (str != s21_NULL) {
    next_token = str;
  }

  if (next_token == s21_NULL) {
    return s21_NULL;
  }

  while (*next_token) {
    int is_delim = 0;
    for (int i = 0; delim[i] != '\0'; i++) {
      if (*next_token == delim[i]) {
        is_delim = 1;
        break;
      }
    }
    if (!is_delim) break;
    next_token++;
  }

  if (*next_token == '\0') {
    next_token = s21_NULL;
    return s21_NULL;
  }

  char *token_start = next_token;

  while (*next_token) {
    int is_delim = 0;
    for (int i = 0; delim[i] != '\0'; i++) {
      if (*next_token == delim[i]) {
        is_delim = 1;
        break;
      }
    }
    if (is_delim) {
      *next_token = '\0';
      next_token++;
      return token_start;
    }
    next_token++;
  }

  next_token = s21_NULL;
  return token_start;
}