#ifndef SCP_STRING_H
#define SCP_STRING_H

#include <float.h>
#include <limits.h>
#include <math.h>
#include <stdarg.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <wchar.h>

#define SCP_NULL (void *)0
#define scp_size_t unsigned long long

void *scp_memchr(const void *str, int c, scp_size_t n);
int scp_memcmp(const void *str1, const void *str2, scp_size_t n);
void *scp_memcpy(void *dest, const void *src, scp_size_t n);
void *scp_memset(void *str, int c, scp_size_t n);
char *scp_strncat(char *dest, const char *src, scp_size_t n);
char *scp_strchr(const char *str, int c);
int scp_strncmp(const char *str1, const char *str2, scp_size_t n);
char *scp_strncpy(char *dest, const char *src, scp_size_t n);
scp_size_t scp_strspn(const char *str1, const char *str2);
scp_size_t scp_strcspn(const char *str1, const char *str2);
char *scp_strerror(int errnum);
scp_size_t scp_strlen(const char *str);
char *scp_strpbrk(const char *str1, const char *str2);
char *scp_strrchr(const char *str, int c);
char *scp_strstr(const char *haystack, const char *needle);
char *scp_strtok(char *str, const char *delim);

int scp_sscanf(const char *str, const char *format,
               ...);  // считывает форматированный ввод из строки.
int scp_sprintf(char *str, const char *format,
                ...);  // отправляет форматированный вывод в строку, на которую
                       // указывает str.

void *scp_to_upper(const char *str);
void *scp_to_lower(const char *str);
void *scp_insert(const char *src, const char *str, scp_size_t start_index);
void *scp_trim(const char *src, const char *trim_chars);

#endif
