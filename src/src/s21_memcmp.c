#include "s21_string.h"

int s21_memcmp(const void *str1, const void *str2, s21_size_t n) {
  /* Сравнивает первые n байтов str1 и str2 */
  const unsigned char *p1 = str1;
  const unsigned char *p2 = str2;
  int res = 0;
  for (s21_size_t i = 0; i < n; ++i) {
    if (p1[i] < p2[i]) {
      res = -1;
    } else if (p1[i] > p2[i]) {
      res = 1;
    }
  }
  return res;
}