#include "s21_string.h"

int s21_strncmp(const char *s1, const char *s2, s21_size_t n) {
  /* Сравнивает не более первых n байтов str1 и str2 */
  for (s21_size_t i = 0; i < n; i++) {
    if (s1[i] != s2[i]) {
      return s1[i] - s2[i];
    }
    if (s1[i] == '\0') {  // Если достигнут конец первой строки
      return 0;
    }
  }
  return 0;
}