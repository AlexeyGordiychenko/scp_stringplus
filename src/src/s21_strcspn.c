#include "s21_string.h"

s21_size_t s21_strcspn(const char *str1, const char *str2) {
  /* Вычисляет длину начального сегмента str1, который полностью состоит из
   * символов, не входящих в str2*/
  s21_size_t i;
  for (i = 0; str1[i] != '\0'; i++) {
    if (s21_strchr(str2, str1[i]) != S21_NULL) {
      break;
    }
  }
  return i;
}