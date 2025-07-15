#ifndef S21_STRING_H
#define S21_STRING_H

#include <ctype.h>
#include <limits.h>
#include <stdarg.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

typedef unsigned long s21_size_t;

#define s21_NULL ((void *)0)

int s21_sprintf(char *str, const char *format, ...);

char *s21_strcpy(char *dest, const char *src);
char *s21_strncpy(char *dest, const char *src, s21_size_t n);

char *s21_strcat(char *dest, const char *src);
char *s21_strncat(char *dest, const char *src, s21_size_t n);

int s21_strcmp(const char *str1, const char *str2);
int s21_strncmp(const char *str1, const char *str2, s21_size_t n);

char *s21_strchr(const char *str, int c);
char *s21_strrchr(const char *str, int c);

char *s21_strstr(const char *haystack, const char *needle);

s21_size_t s21_strlen(const char *str);

s21_size_t s21_strcspn(const char *str1, const char *str2);
char *s21_strpbrk(const char *str1, const char *str2);

char *s21_strtok(char *str, const char *delim);

void *s21_memcpy(void *dest, const void *src, s21_size_t n);
void *s21_memmove(void *dest, const void *src, s21_size_t n);

void *s21_memset(void *str, int c, s21_size_t n);
void *s21_memchr(const void *str, int c, s21_size_t n);

int s21_memcmp(const void *str1, const void *str2, s21_size_t n);

int s21_itoa(int value, char *str);
void s21_utoa(unsigned long num, char *str);
void s21_utoa_base(unsigned long num, char *str, int base, int uppercase);

void s21_ftoa(double num, char *str, int precision);
void s21_etoa(double num, char *str, int precision, int uppercase);
void s21_gtoa(double num, char *str, int precision, int uppercase);
void s21_ptoa(void *ptr, char *str);

char *s21_strerror(int errnum);

char *s21_to_upper(const char *str);
char *s21_to_lower(const char *str);

char *s21_trim(const char *src, const char *trim_chars);
char *s21_insert(const char *src, const char *str, size_t start_index);

#endif