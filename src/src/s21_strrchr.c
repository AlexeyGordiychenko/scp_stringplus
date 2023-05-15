#include "s21_string.h"

char *s21_strrchr(const char *str, int c) {
  /* Выполняет поиск последнего вхождения символа c (беззнаковый тип) в строке,
   * на которую указывает аргумент str*/
  char *last = S21_NULL;
  while (*str) {
    if (*str == c) {
      last = (char *)str;
    }
    str++;
  }
  if (*str == c) {
    last = (char *)str;
  }
  return last;
}