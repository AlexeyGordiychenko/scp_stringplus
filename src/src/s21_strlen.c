#include "../s21_string.h"

s21_size_t s21_strlen(const char *text) {
    s21_size_t len = 0;
    for (; *(text + len); len++)
        ;
    return len;
}
