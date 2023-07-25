#include "../scp_string.h"

void *scp_memchr(const void *str, int c, scp_size_t n) {
  /* Выполняет поиск первого вхождения символа c (беззнаковый тип) в первых n
   * байтах строки, на которую указывает аргумент str.*/
  const unsigned char *p = str;
  for (scp_size_t i = 0; i < n; i++) {
    if (p[i] == c) {
      return (void *)&p[i];
    }
  }
  return SCP_NULL;
}