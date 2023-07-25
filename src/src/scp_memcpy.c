#include "../scp_string.h"

void *scp_memcpy(void *dest, const void *src, scp_size_t n) {
  /* Копирует n символов из src в dest*/
  char *dest_ptr = dest;
  const char *src_ptr = src;

  for (scp_size_t i = 0; i < n; i++) {
    dest_ptr[i] = src_ptr[i];
  }
  return dest;
}