#include "s21_string.h"

char *s21_strncpy(char *dest, const char *src, s21_size_t n) {
  /* Копирует до n символов из строки, на которую указывает src, в dest */
  s21_size_t i;
  for (i = 0; i < n && src[i] != '\0'; i++) {
    dest[i] = src[i];
  }
  for (; i < n; i++) {  // заполнение /0 до указанной длины
    dest[i] = '\0';
  }
  return dest;
}