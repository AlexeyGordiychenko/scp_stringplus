#include "../scp_string.h"

char *scp_strchr(const char *str, int c) {
  /* Выполняет поиск первого вхождения символа c (беззнаковый тип) в строке, на
   * которую указывает аргумент str*/
  while (*str != '\0') {
    if (*str == c) {
      return (char *)str;
    }
    str++;
  }
  if (*str == c) {
    return (char *)str;
  }
  return SCP_NULL;
}