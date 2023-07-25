#include "../scp_string.h"

scp_size_t scp_strcspn(const char *str1, const char *str2) {
  /* Вычисляет длину начального сегмента str1, который полностью состоит из
   * символов, не входящих в str2*/
  scp_size_t i;
  for (i = 0; str1[i] != '\0'; i++) {
    if (scp_strchr(str2, str1[i]) != SCP_NULL) {
      break;
    }
  }
  return i;
}