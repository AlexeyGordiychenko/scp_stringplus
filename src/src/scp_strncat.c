#include "../scp_string.h"

char *scp_strncat(char *dest, const char *src, scp_size_t n) {
  /* Добавляет строку, на которую указывает src, в конец строки, на которую
   * указывает dest, длиной до n символов*/
  char *p = dest;
  while (*p != '\0') {  // находим конец строки-назначения
    p++;
  }
  scp_size_t i = 0;
  while (src[i] != '\0' &&
         i < n) {  // копируем символы из строки-источника в строку-назначение
    p[i] = src[i];
    i++;
  }
  p[i] = '\0';  // устанавливаем конец строки-назначения
  return dest;
}