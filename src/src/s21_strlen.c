#include "../s21_string.h"

size_t s21_strlen(const char *text) {
    size_t len = 0;
    for (; *(text + len); len++)
        ;
    return len;
}
