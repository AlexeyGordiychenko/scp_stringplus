#include "../s21_string.h"

void *s21_memset(void *str, int c, s21_size_t n) {
  /* Копирует символ c (беззнаковый тип) в первые n символов строки, на которую
   * указывает аргумент str*/
  unsigned char *p = str;
  while (n--) {
    *p++ = (unsigned char)c;
  }
  return str;
}