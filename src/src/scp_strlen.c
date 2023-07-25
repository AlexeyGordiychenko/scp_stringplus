#include "../scp_string.h"

scp_size_t scp_strlen(const char *text) {
  scp_size_t len = 0;
  for (; *(text + len); len++)
    ;
  return len;
}
