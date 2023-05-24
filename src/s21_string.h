#ifndef S21_STRING_H
#define S21_STRING_H

#include <limits.h>
#include <stdarg.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
// #include <string.h>
#include <math.h>

#define S21_NULL (void *)0
#define s21_size_t unsigned long long

typedef struct {
  int minus;
  int sign;
  int space;
  int prefix;
  int zero;
  int width;
  int precision;
  char length;
  char spec;
} Flag;

void *s21_memchr(const void *str, int c, s21_size_t n);             // Done
int s21_memcmp(const void *str1, const void *str2, s21_size_t n);   // Done
void *s21_memcpy(void *dest, const void *src, s21_size_t n);        // Done
void *s21_memset(void *str, int c, s21_size_t n);                   // Done
char *s21_strncat(char *dest, const char *src, s21_size_t n);       // Done
char *s21_strchr(const char *str, int c);                           // Done
int s21_strncmp(const char *str1, const char *str2, s21_size_t n);  // Done
char *s21_strncpy(char *dest, const char *src, s21_size_t n);       // Done
s21_size_t s21_strspn(const char *str1, const char *str2);
s21_size_t s21_strcspn(const char *str1, const char *str2);  // Done
char *s21_strerror(int errnum);                              // Done
s21_size_t s21_strlen(const char *str);                      // Done
char *s21_strpbrk(const char *str1, const char *str2);       // Done
char *s21_strrchr(const char *str, int c);                   // Done
char *s21_strstr(const char *haystack, const char *needle);  // Done
char *s21_strtok(char *str, const char *delim);              // Done

int s21_sscanf(const char *str, const char *format,
               ...);  // считывает форматированный ввод из строки.
int s21_sprintf(char *str, const char *format,
                ...);  // отправляет форматированный вывод в строку, на которую
                       // указывает str.
/*str − Это С-строка, которую функция обрабатывает в качестве источника для
извлечения данных; format − это С-строка, содержащая один или несколько
следующих элементов: пробельный символ, непробельный символ и спецификаторы
формата. Спецификатор формата для печатающих функций следует прототипу:
%[флаги][ширина][.точность][длина]спецификатор. Спецификатор формата для
сканирующих функций следует прототипу: %[*][ширина][длина]спецификатор.*/

void *s21_to_upper(
    const char *str);  //	Возвращает копию строки (str), преобразованной в
                       // верхний регистр. В случае какой-либо ошибки следует
                       // вернуть значение NULL
void *s21_to_lower(
    const char *str);  // Возвращает копию строки (str), преобразованной в
                       // нижний регистр. В случае какой-либо ошибки следует
                       // вернуть значение NULL
void *s21_insert(
    const char *src, const char *str,
    s21_size_t start_index);  // Возвращает новую строку, в которой указанная
                              // строка (str) вставлена в указанную позицию
                              // (start_index) в данной строке (src). В случае
                              // какой-либо ошибки следует вернуть значение NULL
void *s21_trim(
    const char *src,
    const char
        *trim_chars);  // Возвращает новую строку, в которой удаляются все
                       // начальные и конечные вхождения набора заданных
                       // символов (trim_chars) из данной строки (src). В случае
                       // какой-либо ошибки следует вернуть значение NULL

void parse_spec(const char *format, int *ind, Flag *flags);

void reverse_string(char *str);
void int_to_string(int number, char *str);
void double_to_string(double number, char *str, int precision);
void string_to_int(char *str, int *number);
void string_to_double(char *str, double *number);
void int_to_hex(int number, char *hex, int reg);
void input_char(char *str, char ch);

void execute_X(char *str, int *ind, int number, Flag *flags);
void execute_percent(char *str, int *ind);
void execute_n(int *ind, int *count);

#endif