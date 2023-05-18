#include "../s21_string.h"

char *s21_strstr(const char *haystack, const char *needle) {
  /* Находит первое вхождение всей строки needle (не включая завершающий нулевой
   * символ), которая появляется в строке haystack*/
  if (*needle == '\0') {
    return (char *)haystack;
  }

  const char *p1 = haystack;

  while (*p1 != '\0') {
    const char *p1_start = p1;
    const char *p2 = needle;
    while (*p1 != '\0' && *p2 != '\0' && *p1 == *p2) {
      p1++;
      p2++;
    }
    if (*p2 == '\0') {
      return (char *)p1_start;
    }
    p1 = p1_start + 1;
  }
  return S21_NULL;
}