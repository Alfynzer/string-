#include "s21_string.h"

typedef enum {
  FLAG_NONE = 0,
  FLAG_ASTERISK = 1 << 0,
  FLAG_WIDTH = 1 << 1
} sscanf_flags;

typedef enum {
  LENGTH_NONE,
  LENGTH_h,
  LENGTH_l,
  LENGTH_L,
  LENGTH_ll
} length_specifier;

typedef struct {
  sscanf_flags flags;
  int width;
  length_specifier length;
  char specifier;
} sscanf_spec;

static int is_space(char c) {
  return c == ' ' || c == '\t' || c == '\n' || c == '\r' || c == '\f' ||
         c == '\v';
}

static void skip_whitespace(const char **str) {
  while (is_space(**str)) {
    (*str)++;
  }
}

static int parse_specifier(const char **format, sscanf_spec *spec) {
  spec->flags = FLAG_NONE;
  spec->width = 0;
  spec->length = LENGTH_NONE;
  spec->specifier = '\0';
  if (**format != '%') return 0;
  (*format)++;
  if (**format == '*') {
    spec->flags |= FLAG_ASTERISK;
    (*format)++;
  }
  if (isdigit(**format)) {
    spec->flags |= FLAG_WIDTH;
    while (isdigit(**format)) {
      spec->width = spec->width * 10 + (**format - '0');
      (*format)++;
    }
  }
  if (**format == 'h') {
    spec->length = LENGTH_h;
    (*format)++;
  } else if (**format == 'l') {
    spec->length = LENGTH_l;
    (*format)++;
    if (**format == 'l') {
      spec->length = LENGTH_ll;
      (*format)++;
    }
  } else if (**format == 'L') {
    spec->length = LENGTH_L;
    (*format)++;
  }
  if (s21_strchr("diuoxXfFeEgGcspn%", **format)) {
    spec->specifier = **format;
    (*format)++;
    return 1;
  }
  return 0;
}

static int parse_int(const char **str, int width, int *num) {
  const char *start = *str;
  int sign = 1;
  int value = 0;
  int digits = 0;
  skip_whitespace(str);
  if (width == 0) width = INT_MAX;
  if (**str == '-') {
    sign = -1;
    (*str)++;
    width--;
  } else if (**str == '+') {
    (*str)++;
    width--;
  }
  while (width > 0 && isdigit(**str)) {
    value = value * 10 + (**str - '0');
    (*str)++;
    width--;
    digits++;
  }
  if (digits == 0) {
    *str = start;
    return 0;
  }
  if (num) *num = sign * value;
  return 1;
}

static int parse_long_long(const char **str, int width, long long *num) {
  const char *start = *str;
  int sign = 1;
  long long value = 0;
  int digits = 0;
  skip_whitespace(str);
  if (width == 0) width = INT_MAX;
  if (**str == '-') {
    sign = -1;
    (*str)++;
    width--;
  } else if (**str == '+') {
    (*str)++;
    width--;
  }
  while (width > 0 && isdigit(**str)) {
    value = value * 10 + (**str - '0');
    (*str)++;
    width--;
    digits++;
  }
  if (digits == 0) {
    *str = start;
    return 0;
  }
  if (num) *num = sign * value;
  return 1;
}

static int parse_uint(const char **str, int width, unsigned int *num,
                      int base) {
  const char *start = *str;
  unsigned int value = 0;
  int digits = 0;
  skip_whitespace(str);
  if (width == 0) width = INT_MAX;
  if (**str == '+') {
    (*str)++;
    width--;
  }
  if (base == 16 && width >= 2 && **str == '0' &&
      (*(*str + 1) == 'x' || *(*str + 1) == 'X')) {
    *str += 2;
    width -= 2;
  }
  while (width > 0) {
    int digit;
    if (isdigit(**str)) {
      digit = **str - '0';
    } else if (base > 10 && isalpha(**str)) {
      digit = tolower(**str) - 'a' + 10;
    } else {
      break;
    }
    if (digit >= base) break;
    value = value * base + digit;
    (*str)++;
    width--;
    digits++;
  }
  if (digits == 0) {
    *str = start;
    return 0;
  }
  if (num) *num = value;
  return 1;
}

static int parse_float(const char **str, int width, long double *num) {
  const char *start = *str;
  int sign = 1;
  long double value = 0.0L;
  long double fraction = 1.0L;
  int exponent = 0;
  int digits = 0;

  skip_whitespace(str);

  if (width == 0) width = INT_MAX;

  if (**str == '-') {
    sign = -1;
    (*str)++;
    width--;
  } else if (**str == '+') {
    (*str)++;
    width--;
  }

  while (width > 0 && isdigit(**str)) {
    value = value * 10.0L + (**str - '0');
    (*str)++;
    width--;
    digits++;
  }

  if (width > 0 && **str == '.') {
    (*str)++;
    width--;

    while (width > 0 && isdigit(**str)) {
      fraction *= 0.1L;
      value += (**str - '0') * fraction;
      (*str)++;
      width--;
      digits++;
    }
  }

  if (width > 0 && (**str == 'e' || **str == 'E')) {
    (*str)++;
    width--;

    // Объявляем exponent_sign только если встретили 'e'/'E'
    int exponent_sign = 1;

    if (width > 0 && (**str == '-' || **str == '+')) {
      exponent_sign = (**str == '-') ? -1 : 1;
      (*str)++;
      width--;
    }

    while (width > 0 && isdigit(**str)) {
      exponent = exponent * 10 + (**str - '0');
      (*str)++;
      width--;
      digits++;
    }

    if (exponent != 0) {
      long double power = 1.0L;
      for (int i = 0; i < exponent; i++) {
        power *= 10.0L;
      }

      if (exponent_sign > 0) {
        value *= power;
      } else {
        value /= power;
      }
    }
  }

  if (digits == 0) {
    *str = start;
    return 0;
  }

  if (num) *num = sign * value;
  return 1;
}
static int parse_char(const char **str, int width, char *ch) {
  if (!ch) return 0;
  if (width == 0) width = 1;
  if (**str == '\0') return 0;
  for (int i = 0; i < width && **str != '\0'; i++) {
    ch[i] = **str;
    (*str)++;
  }
  return 1;
}

static int parse_string(const char **str, int width, char *s) {
  if (!s) return 0;
  skip_whitespace(str);
  if (width == 0) width = INT_MAX;
  int count = 0;
  while (width > 0 && **str != '\0' && !is_space(**str)) {
    *s++ = **str;
    (*str)++;
    width--;
    count++;
  }
  if (count > 0) {
    *s = '\0';
    return 1;
  }
  return 0;
}

static int parse_hex(const char **str, int width, unsigned int *num) {
  return parse_uint(str, width, num, 16);
}

static int parse_oct(const char **str, int width, unsigned int *num) {
  return parse_uint(str, width, num, 8);
}

static int parse_ptr(const char **str, void **ptr) {
  if (!ptr) return 0;
  skip_whitespace(str);
  if (**str != '0' || *(*str + 1) != 'x') return 0;
  *str += 2;
  unsigned long value = 0;
  while (isxdigit(**str)) {
    int digit;
    if (isdigit(**str)) {
      digit = **str - '0';
    } else {
      digit = tolower(**str) - 'a' + 10;
    }
    value = value * 16 + digit;
    (*str)++;
  }
  *ptr = (void *)(uintptr_t)value;
  return 1;
}

static int parse_n(const char *start, const char *current, void *arg,
                   length_specifier length) {
  if (!arg) return 0;
  ptrdiff_t count = current - start;
  switch (length) {
    case LENGTH_h:
      *(short *)arg = (short)count;
      break;
    case LENGTH_l:
      *(long *)arg = (long)count;
      break;
    case LENGTH_ll:
      *(long long *)arg = (long long)count;
      break;
    default:
      *(int *)arg = (int)count;
      break;
  }
  return 1;
}

int s21_sscanf(const char *str, const char *format, ...) {
  if (!str || !format) return -1;
  va_list args;
  va_start(args, format);
  const char *start = str;
  int matched = 0;
  int any_success = 0;
  while (*format) {
    if (is_space(*format)) {
      skip_whitespace(&format);
      skip_whitespace(&str);
      continue;
    }
    if (*format != '%') {
      if (*str != *format) break;
      str++;
      format++;
      continue;
    }
    sscanf_spec spec;
    if (!parse_specifier(&format, &spec)) {
      if (*format == '%' && *str == '%') {
        str++;
        format++;
      }
      continue;
    }
    if (spec.specifier == 'n') {
      if (!(spec.flags & FLAG_ASTERISK)) {
        void *arg = va_arg(args, void *);
        parse_n(start, str, arg, spec.length);
      }
      continue;
    }
    if (*str == '\0') break;
    int success = 0;
    if (!(spec.flags & FLAG_ASTERISK)) {
      switch (spec.specifier) {
        case 'd':
        case 'i': {
          if (spec.length == LENGTH_ll) {
            long long *arg = va_arg(args, long long *);
            if (!arg) goto end;
            success = parse_long_long(&str, spec.width, arg);
          } else {
            int *arg = va_arg(args, int *);
            if (!arg) goto end;
            if (spec.specifier == 'i') {
              if (str[0] == '0' && (str[1] == 'x' || str[1] == 'X')) {
                unsigned int value;
                success = parse_hex(&str, spec.width, &value);
                *arg = (int)value;
              } else if (*str == '0') {
                unsigned int value;
                success = parse_oct(&str, spec.width, &value);
                *arg = (int)value;
              } else {
                success = parse_int(&str, spec.width, arg);
              }
            } else {
              success = parse_int(&str, spec.width, arg);
            }
          }
          break;
        }
        case 'u': {
          unsigned int *arg = va_arg(args, unsigned int *);
          if (!arg) goto end;
          success = parse_uint(&str, spec.width, arg, 10);
          break;
        }
        case 'o': {
          unsigned int *arg = va_arg(args, unsigned int *);
          if (!arg) goto end;
          success = parse_oct(&str, spec.width, arg);
          break;
        }
        case 'x':
        case 'X': {
          unsigned int *arg = va_arg(args, unsigned int *);
          if (!arg) goto end;
          success = parse_hex(&str, spec.width, arg);
          break;
        }
        case 'f':
        case 'F':
        case 'e':
        case 'E':
        case 'g':
        case 'G': {
          if (spec.length == LENGTH_L) {
            long double *arg = va_arg(args, long double *);
            success = parse_float(&str, spec.width, arg);
          } else if (spec.length == LENGTH_l) {
            double *arg = va_arg(args, double *);
            long double value;
            success = parse_float(&str, spec.width, &value);
            *arg = (double)value;
          } else {
            float *arg = va_arg(args, float *);
            long double value;
            success = parse_float(&str, spec.width, &value);
            *arg = (float)value;
          }
          break;
        }
        case 'c': {
          char *arg = va_arg(args, char *);
          if (!arg) goto end;
          if (spec.width > 1) {
            for (int i = 0; i < spec.width && *str != '\0'; i++) {
              arg[i] = *str++;
            }
            success = 1;
          } else {
            success = parse_char(&str, spec.width, arg);
          }
          break;
        }
        case 's': {
          char *arg = va_arg(args, char *);
          if (!arg) goto end;
          success = parse_string(&str, spec.width, arg);
          break;
        }
        case 'p': {
          void **arg = va_arg(args, void **);
          if (!arg) goto end;
          success = parse_ptr(&str, arg);
          break;
        }
        case '%': {
          if (*str != '%') goto end;
          str++;
          success = 1;
          break;
        }
        default:
          goto end;
      }
    } else {
      switch (spec.specifier) {
        case 'd':
        case 'i': {
          int dummy;
          success = parse_int(&str, spec.width, &dummy);
          break;
        }
        case 'u': {
          unsigned int dummy;
          success = parse_uint(&str, spec.width, &dummy, 10);
          break;
        }
        case 'o': {
          unsigned int dummy;
          success = parse_oct(&str, spec.width, &dummy);
          break;
        }
        case 'x':
        case 'X': {
          unsigned int dummy;
          success = parse_hex(&str, spec.width, &dummy);
          break;
        }
        case 'f':
        case 'F':
        case 'e':
        case 'E':
        case 'g':
        case 'G': {
          long double dummy;
          success = parse_float(&str, spec.width, &dummy);
          break;
        }
        case 'c': {
          char dummy;
          success = parse_char(&str, spec.width, &dummy);
          break;
        }
        case 's': {
          char dummy[256];
          success = parse_string(&str, spec.width, dummy);
          break;
        }
        case 'p': {
          void *dummy;
          success = parse_ptr(&str, &dummy);
          break;
        }
        case '%': {
          if (*str != '%') goto end;
          str++;
          success = 1;
          break;
        }
        default:
          goto end;
      }
    }
    if (!success) break;
    if (!(spec.flags & FLAG_ASTERISK)) {
      matched++;
    }
    any_success = 1;
  }
end:
  va_end(args);
  return any_success ? (matched > 0 ? matched : 1) : 0;
}