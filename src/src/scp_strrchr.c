#include "../scp_string.h"

char *scp_strrchr(const char *str, int c) {
  /* Выполняет поиск последнего вхождения символа c (беззнаковый тип) в строке,
   * на которую указывает аргумент str*/
  char *last = SCP_NULL;
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