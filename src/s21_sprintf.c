#include "s21_string.h"

typedef size_t s21_size_t;

int s21_itoa(int value, char *str) {
  if (value == 0) {
    str[0] = '0';
    str[1] = '\0';
    return 1;
  }

  int i = 0;
  int is_negative = value < 0;
  unsigned int uval;

  if (is_negative) {
    uval =
        (value == INT_MIN) ? (unsigned int)INT_MAX + 1 : (unsigned int)(-value);
  } else {
    uval = (unsigned int)value;
  }

  char temp[12];
  do {
    temp[i++] = (uval % 10) + '0';
    uval /= 10;
  } while (uval > 0);

  int j = 0;
  if (is_negative) str[j++] = '-';
  while (i > 0) str[j++] = temp[--i];
  str[j] = '\0';
  return j;
}

void s21_utoa(unsigned long num, char *str) {
  if (num == 0) {
    str[0] = '0';
    str[1] = '\0';
    return;
  }
  int i = 0;
  char temp[21];
  while (num > 0) {
    temp[i++] = (num % 10) + '0';
    num /= 10;
  }
  for (int j = 0; j < i; j++) str[j] = temp[i - j - 1];
  str[i] = '\0';
}

void s21_utoa_base(unsigned long num, char *str, int base, int uppercase) {
  if (num == 0) {
    str[0] = '0';
    str[1] = '\0';
    return;
  }
  char digits[] = "0123456789abcdef";
  char digits_upper[] = "0123456789ABCDEF";
  char temp[65];
  int i = 0;
  while (num > 0) {
    int digit = num % base;
    temp[i++] = uppercase ? digits_upper[digit] : digits[digit];
    num /= base;
  }
  for (int j = 0; j < i; j++) str[j] = temp[i - j - 1];
  str[i] = '\0';
}

void s21_ftoa(double num, char *str, int precision) {
  if (precision < 0) precision = 6;

  int is_negative = num < 0;
  if (is_negative) num = -num;

  long long int_part = (long long)num;
  double frac = num - int_part;

  double rounding = 0.5;
  for (int i = 0; i < precision; i++) rounding /= 10;
  frac += rounding;

  if (frac >= 1.0) {
    int_part++;
    frac -= 1.0;
  }

  int pos = 0;
  if (is_negative) str[pos++] = '-';

  char int_str[20];
  s21_itoa(int_part, int_str);
  for (int i = 0; int_str[i]; i++) str[pos++] = int_str[i];

  if (precision > 0) {
    str[pos++] = '.';
    for (int i = 0; i < precision; i++) {
      frac *= 10;
      int digit = (int)frac;
      str[pos++] = '0' + digit;
      frac -= digit;
    }
  }
  str[pos] = '\0';
}

void s21_etoa(double num, char *str, int precision, int uppercase) {
  if (precision < 0) precision = 6;

  int is_negative = num < 0;
  if (is_negative) num = -num;

  int exponent = 0;
  if (num != 0.0) {
    while (num >= 10.0) {
      num /= 10.0;
      exponent++;
    }
    while (num < 1.0) {
      num *= 10.0;
      exponent--;
    }
  }

  double rounding = 0.5;
  for (int i = 0; i < precision; i++) rounding /= 10;
  num += rounding;

  if (num >= 10.0) {
    num /= 10.0;
    exponent++;
  }

  int pos = 0;
  if (is_negative) str[pos++] = '-';

  int digit = (int)num;
  str[pos++] = digit + '0';
  num -= digit;

  if (precision > 0) {
    str[pos++] = '.';
    for (int i = 0; i < precision; i++) {
      num *= 10;
      digit = (int)num;
      str[pos++] = digit + '0';
      num -= digit;
    }
  }

  str[pos++] = uppercase ? 'E' : 'e';
  str[pos++] = exponent >= 0 ? '+' : '-';
  if (exponent < 0) exponent = -exponent;

  if (exponent < 10) str[pos++] = '0';

  char exp_str[10];
  s21_itoa(exponent, exp_str);
  for (int i = 0; exp_str[i]; i++) str[pos++] = exp_str[i];

  str[pos] = '\0';
}

void s21_gtoa(double num, char *str, int precision, int uppercase) {
  if (precision <= 0) precision = 1;

  double abs_num = num < 0 ? -num : num;

  if (abs_num == 0.0) {
    str[0] = '0';
    str[1] = '\0';
    return;
  }

  int exponent = 0;
  double temp = abs_num;
  if (temp >= 1.0) {
    while (temp >= 10.0) {
      temp /= 10.0;
      exponent++;
    }
  } else {
    while (temp < 1.0) {
      temp *= 10.0;
      exponent--;
    }
  }

  if (exponent >= -4 && exponent < precision) {
    int f_precision = precision - 1 - exponent;
    if (f_precision < 0) f_precision = 0;
    s21_ftoa(abs_num, str, f_precision);

    int len = s21_strlen(str);
    while (len > 1 && str[len - 1] == '0' && str[len - 2] != '.') {
      str[--len] = '\0';
    }
    if (len > 1 && str[len - 1] == '.') str[--len] = '\0';
  } else {
    s21_etoa(abs_num, str, precision - 1, uppercase);
  }

  if (num < 0) {
    int len = s21_strlen(str);
    for (int i = len; i >= 0; i--) str[i + 1] = str[i];
    str[0] = '-';
  }
}

void s21_ptoa(void *ptr, char *str) {
  if (ptr == NULL) {
    s21_strncpy(str, "(nil)", 6);
    return;
  }

  unsigned long addr = (unsigned long)ptr;
  str[0] = '0';
  str[1] = 'x';
  s21_utoa_base(addr, str + 2, 16, 0);
}

int s21_sprintf(char *str, const char *format, ...) {
  va_list args;
  va_start(args, format);
  int pos = 0;

  for (int i = 0; format[i] != '\0'; i++) {
    if (format[i] == '%' && format[i + 1]) {
      i++;

      int flag_minus = 0, flag_plus = 0, flag_space = 0, flag_hash = 0,
          flag_zero = 0;
      while (format[i] == '-' || format[i] == '+' || format[i] == ' ' ||
             format[i] == '#' || format[i] == '0') {
        if (format[i] == '-')
          flag_minus = 1;
        else if (format[i] == '+')
          flag_plus = 1;
        else if (format[i] == ' ')
          flag_space = 1;
        else if (format[i] == '#')
          flag_hash = 1;
        else if (format[i] == '0')
          flag_zero = 1;
        i++;
      }

      int width = 0;
      if (format[i] == '*') {
        width = va_arg(args, int);
        i++;
      } else {
        while (format[i] >= '0' && format[i] <= '9') {
          width = width * 10 + (format[i++] - '0');
        }
      }
      if (width < 0) {
        flag_minus = 1;
        width = -width;
      }

      int precision = -1;
      if (format[i] == '.') {
        i++;
        if (format[i] == '*') {
          precision = va_arg(args, int);
          i++;
        } else {
          precision = 0;
          while (format[i] >= '0' && format[i] <= '9') {
            precision = precision * 10 + (format[i++] - '0');
          }
        }
      }

      int length_h = 0, length_l = 0, length_L = 0;
      if (format[i] == 'h') {
        length_h = 1;
        i++;
      } else if (format[i] == 'l') {
        length_l = 1;
        i++;
      } else if (format[i] == 'L') {
        length_L = 1;
        i++;
      }

      char buffer[1000] = {0};
      int len = 0;

      switch (format[i]) {
        case 'd': {
          long val = length_l   ? va_arg(args, long)
                     : length_h ? (short)va_arg(args, int)
                                : va_arg(args, int);

          int is_neg = val < 0;
          if (is_neg) val = -val;

          s21_itoa(val, buffer);
          const char *num_str = buffer;
          len = s21_strlen(num_str);

          int pad_zeros = (precision > len) ? (precision - len) : 0;

          char sign_char = 0;
          if (is_neg)
            sign_char = '-';
          else if (flag_plus)
            sign_char = '+';
          else if (flag_space)
            sign_char = ' ';

          int total_len = len + pad_zeros + (sign_char ? 1 : 0);

          if (!flag_minus && width > total_len) {
            if (flag_zero && precision < 0) {
              if (sign_char) str[pos++] = sign_char;

              for (int j = 0; j < width - total_len; j++) str[pos++] = '0';

              for (int j = 0; j < pad_zeros; j++) str[pos++] = '0';

              for (int j = 0; j < len; j++) str[pos++] = num_str[j];
            } else {
              for (int j = 0; j < width - total_len; j++) str[pos++] = ' ';

              if (sign_char) str[pos++] = sign_char;

              for (int j = 0; j < pad_zeros; j++) str[pos++] = '0';

              for (int j = 0; j < len; j++) str[pos++] = num_str[j];
            }
          } else {
            if (sign_char) str[pos++] = sign_char;

            for (int j = 0; j < pad_zeros; j++) str[pos++] = '0';

            for (int j = 0; j < len; j++) str[pos++] = num_str[j];

            if (flag_minus && width > total_len)
              for (int j = 0; j < width - total_len; j++) str[pos++] = ' ';
          }
          break;
        }

        case 'u': {
          unsigned long val = length_l ? va_arg(args, unsigned long)
                              : length_h
                                  ? (unsigned short)va_arg(args, unsigned int)
                                  : va_arg(args, unsigned int);
          s21_utoa(val, buffer);
          len = s21_strlen(buffer);

          int pad_zeros = (precision > len) ? precision - len : 0;
          int total_len = len + pad_zeros;

          if (!flag_minus && width > total_len) {
            char fill_char = (flag_zero && precision < 0) ? '0' : ' ';
            for (int j = 0; j < width - total_len; j++) str[pos++] = fill_char;
          }

          for (int j = 0; j < pad_zeros; j++) str[pos++] = '0';
          for (int j = 0; j < len; j++) str[pos++] = buffer[j];

          if (flag_minus && width > total_len)
            for (int j = 0; j < width - total_len; j++) str[pos++] = ' ';
          break;
        }
        case 'f': {
          double num =
              length_L ? va_arg(args, long double) : va_arg(args, double);
          int is_neg = num < 0;
          if (precision < 0) precision = 6;
          s21_ftoa(is_neg ? -num : num, buffer, precision);
          len = s21_strlen(buffer);

          int sign_len = 0;
          char sign_char = 0;
          if (is_neg)
            sign_char = '-';
          else if (flag_plus)
            sign_char = '+';
          else if (flag_space)
            sign_char = ' ';
          if (sign_char) sign_len = 1;

          int total_len = len + sign_len;

          if (!flag_minus && width > total_len) {
            if (flag_zero) {
              if (sign_char) str[pos++] = sign_char;
              for (int j = 0; j < width - total_len; j++) str[pos++] = '0';
              for (int j = 0; j < len; j++) str[pos++] = buffer[j];
            } else {
              for (int j = 0; j < width - total_len; j++) str[pos++] = ' ';
              if (sign_char) str[pos++] = sign_char;
              for (int j = 0; j < len; j++) str[pos++] = buffer[j];
            }
          } else {
            if (sign_char) str[pos++] = sign_char;
            for (int j = 0; j < len; j++) str[pos++] = buffer[j];
            if (flag_minus && width > total_len)
              for (int j = 0; j < width - total_len; j++) str[pos++] = ' ';
          }
          break;
        }
        case 'e':
        case 'E': {
          double num =
              length_L ? va_arg(args, long double) : va_arg(args, double);
          if (precision < 0) precision = 6;
          s21_etoa(num, buffer, precision, format[i] == 'E');
          len = s21_strlen(buffer);

          if (!flag_minus && width > len) {
            char fill_char = (flag_zero && precision < 0) ? '0' : ' ';
            for (int j = 0; j < width - len; j++) str[pos++] = fill_char;
          }

          for (int j = 0; j < len; j++) str[pos++] = buffer[j];

          if (flag_minus && width > len)
            for (int j = 0; j < width - len; j++) str[pos++] = ' ';
          break;
        }
        case 'g':
        case 'G': {
          double num =
              length_L ? va_arg(args, long double) : va_arg(args, double);
          if (precision < 0) precision = 6;
          s21_gtoa(num, buffer, precision, format[i] == 'G');
          len = s21_strlen(buffer);

          if (!flag_minus && width > len) {
            char fill_char = (flag_zero && precision < 0) ? '0' : ' ';
            for (int j = 0; j < width - len; j++) str[pos++] = fill_char;
          }

          for (int j = 0; j < len; j++) str[pos++] = buffer[j];

          if (flag_minus && width > len)
            for (int j = 0; j < width - len; j++) str[pos++] = ' ';
          break;
        }
        case 'p': {
          void *ptr = va_arg(args, void *);
          s21_ptoa(ptr, buffer);
          len = s21_strlen(buffer);

          if (!flag_minus && width > len) {
            for (int j = 0; j < width - len; j++) str[pos++] = ' ';
          }

          for (int j = 0; j < len; j++) str[pos++] = buffer[j];

          if (flag_minus && width > len) {
            for (int j = 0; j < width - len; j++) str[pos++] = ' ';
          }

          break;
        }
        case 's': {
          const char *s = va_arg(args, char *);
          if (!s) s = "(null)";
          len = s21_strlen(s);
          if (precision >= 0 && precision < len) len = precision;

          if (!flag_minus && width > len)
            for (int j = 0; j < width - len; j++) str[pos++] = ' ';

          for (int j = 0; j < len; j++) str[pos++] = s[j];

          if (flag_minus && width > len)
            for (int j = 0; j < width - len; j++) str[pos++] = ' ';
          break;
        }
        case 'c': {
          char c = (char)va_arg(args, int);
          if (!flag_minus && width > 1)
            for (int j = 0; j < width - 1; j++) str[pos++] = ' ';
          str[pos++] = c;
          if (flag_minus && width > 1)
            for (int j = 0; j < width - 1; j++) str[pos++] = ' ';
          break;
        }
        case '%':
          str[pos++] = '%';
          break;

        case 'x':
        case 'X': {
          unsigned long val = length_l ? va_arg(args, unsigned long)
                              : length_h
                                  ? (unsigned short)va_arg(args, unsigned int)
                                  : va_arg(args, unsigned int);
          s21_utoa_base(val, buffer, 16, format[i] == 'X');
          len = s21_strlen(buffer);

          int pad_zeros = (precision > len) ? precision - len : 0;
          int total_len = len + pad_zeros;

          int prefix_len = 0;
          if (flag_hash && val != 0) prefix_len = 2;
          total_len += prefix_len;

          if (!flag_minus && width > total_len) {
            if (flag_zero && precision < 0) {
              if (flag_hash && val != 0) {
                str[pos++] = '0';
                str[pos++] = format[i] == 'X' ? 'X' : 'x';
              }
              for (int j = 0; j < width - total_len; j++) str[pos++] = '0';
            } else {
              for (int j = 0; j < width - total_len; j++) str[pos++] = ' ';
              if (flag_hash && val != 0) {
                str[pos++] = '0';
                str[pos++] = format[i] == 'X' ? 'X' : 'x';
              }
            }
          } else {
            if (flag_hash && val != 0) {
              str[pos++] = '0';
              str[pos++] = format[i] == 'X' ? 'X' : 'x';
            }
          }

          for (int j = 0; j < pad_zeros; j++) str[pos++] = '0';
          for (int j = 0; j < len; j++) str[pos++] = buffer[j];

          if (flag_minus && width > total_len)
            for (int j = 0; j < width - total_len; j++) str[pos++] = ' ';
          break;
        }

        case 'o': {
          unsigned long val = length_l ? va_arg(args, unsigned long)
                              : length_h
                                  ? (unsigned short)va_arg(args, unsigned int)
                                  : va_arg(args, unsigned int);

          s21_utoa_base(val, buffer, 8, 0);
          len = s21_strlen(buffer);

          int pad_zeros = (precision > len) ? (precision - len) : 0;

          int prefix_len = 0;
          char prefix[2] = {0};

          if (flag_hash && val != 0) {
            prefix[0] = '0';
            prefix_len = 1;
          }

          int total_len = prefix_len + pad_zeros + len;

          if (!flag_minus && width > total_len) {
            if (flag_zero && precision < 0) {
              for (int j = 0; j < prefix_len; j++) str[pos++] = prefix[j];
              for (int j = 0; j < width - total_len; j++) str[pos++] = '0';
            } else {
              for (int j = 0; j < width - total_len; j++) str[pos++] = ' ';
              for (int j = 0; j < prefix_len; j++) str[pos++] = prefix[j];
            }
          } else {
            for (int j = 0; j < prefix_len; j++) str[pos++] = prefix[j];
          }

          for (int j = 0; j < pad_zeros; j++) str[pos++] = '0';

          for (int j = 0; j < len; j++) str[pos++] = buffer[j];

          if (flag_minus && width > total_len) {
            for (int j = 0; j < width - total_len; j++) str[pos++] = ' ';
          }
          break;
        }

        default:
          str[pos++] = '%';
          str[pos++] = format[i];
          break;
      }
    } else {
      str[pos++] = format[i];
    }
  }

  str[pos] = '\0';
  va_end(args);
  return pos;
}