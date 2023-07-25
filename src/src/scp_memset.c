#include "../scp_string.h"

void *scp_memset(void *str, int c, scp_size_t n) {
  /* Копирует символ c (беззнаковый тип) в первые n символов строки, на которую
   * указывает аргумент str*/
  unsigned char *p = str;
  while (n--) {
    *p++ = (unsigned char)c;
  }
  return str;
}