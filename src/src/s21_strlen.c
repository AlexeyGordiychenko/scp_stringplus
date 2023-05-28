#include "../s21_string.h"

s21_size_t s21_strlen(const char *text) {
<<<<<<< HEAD
  s21_size_t len = 0;
  for (; *(text + len); len++)
    ;
  return len;
=======
    s21_size_t len = 0;
    for (; *(text + len); len++)
        ;
    return len;
>>>>>>> 59c3dac97c6954adb6728af20080dc1213f5a670
}
