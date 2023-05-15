#include "s21_string.h"

s21_size_t s21_strlen(const char *text) {
  /* Вычисляет длину строки str, не включая завершающий нулевой символ */
  s21_size_t len = 0;
  while (*text != '\0') {
    len++;
    text++;
  }
  return len;
}