#include "s21_string.h"

s21_size_t s21_strlen(const char* text) {
    s21_size_t len = 0;
    while (*text != '\0') {
        len++;
        text++;
    }
    return len;
}

int s21_strncmp(const char* s1, const char* s2, s21_size_t n) {
    for (s21_size_t i = 0; i < n; i++) {
        if (s1[i] != s2[i]) {
            return s1[i] - s2[i];
        }
        if (s1[i] == '\0') { // Если достигнут конец первой строки
            return 0;
        }
    }
    return 0;
}

int s21_strcmp(const char* s1, const char* s2) {
    return s21_strncmp(s1, s2, SIZE_MAX); // без ограничения длины
}

char* s21_strcpy(char* dest, const char* src) {
    char* dest_ptr = dest;
    const char* src_ptr = src;

    // Копируем символы из src в dest, пока не встретим символ '\0'
    while (*src_ptr != '\0') {
        *dest_ptr = *src_ptr;
        dest_ptr++;
        src_ptr++;
    }

    // Добавляем в dest завершающий нулевой символ
    *dest_ptr = '\0';

    return dest;
}

char* s21_strcat(char* dest, const char* src1, const char* src2) {
    char* dest_ptr = dest;
    const char* src1_ptr = src1;
    const char* src2_ptr = src2;

    // Находим конец dest
    while (*dest_ptr != '\0') {
        dest_ptr++;
    }

    // Копируем символы из src1 в dest
    while (*src1_ptr != '\0') {
        *dest_ptr = *src1_ptr;
        dest_ptr++;
        src1_ptr++;
    }

    // Копируем символы из src2 в dest
    while (*src2_ptr != '\0') {
        *dest_ptr = *src2_ptr;
        dest_ptr++;
        src2_ptr++;
    }

    // Добавляем в dest завершающий символ
    *dest_ptr = '\0';

    return dest;
}

char* s21_strchr(char* s, const char c) {
    while (*s != '\0') {
        if (*s == c) {
            return s;
        }
        ++s;
    }

    if (c == '\0') {
        return s;
    }

    return NULL;
}

char* s21_strstr(const char* haystack, const char* needle) {
    if (*needle == '\0') {
        return (char*)haystack;
    }

    const char* p1 = haystack;
    while (*p1 != '\0') {
        const char* p1_start = p1;
        const char* p2 = needle;
        while (*p1 != '\0' && *p2 != '\0' && *p1 == *p2) {
            p1++;
            p2++;
        }
        if (*p2 == '\0') {
            return (char*)p1_start;
        }
        p1 = p1_start + 1;
    }

    return NULL;
}

char* s21_strtok(char* str, const char* delim) {
    static char* last_str = NULL;
    if (str != NULL) {
        last_str = str;
    } else if (last_str == NULL) {
        return NULL;
    }

    char* token_start = last_str;
    char* token_end = NULL;

    while (*last_str != '\0') {
        const char* d = delim;
        while (*d != '\0') {
            if (*last_str == *d) {
                token_end = last_str;
                *token_end = '\0';
                last_str++;
                return token_start;
            }
            d++;
        }
        last_str++;
    }

    if (token_start != NULL) {
        return token_start;
    } else {
        return NULL;
    }
}
