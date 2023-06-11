#include "../s21_string.h"

char *change_case(const char *c, int offset);

void *s21_to_upper(const char *str) {
  /*Возвращает копию строки (str), преобразованной в верхний регистр. В
   * случае какой-либо ошибки следует вернуть значение NULL*/
  return change_case(str, 'a' - 'A');
}

void *s21_to_lower(const char *str) {
  /*Возвращает копию строки (str), преобразованной в нижний регистр. В
   * случае какой-либо ошибки следует вернуть значение NULL*/
  return change_case(str, 'A' - 'a');
}

char *change_case(const char *str, int offset) {
  char *new_str = S21_NULL;

  if (str != S21_NULL) {
    const char *p = str;
    new_str = malloc(sizeof(char) * s21_strlen(str) + 1);
    if (new_str != S21_NULL) {
      char *p_new = new_str;
      int left = (offset < 0) ? 'A' : 'a';
      int rigth = (offset < 0) ? 'Z' : 'z';
      for (; *p != '\0'; p++) {
        if (*p >= left && *p <= rigth) {
          *p_new++ = *p - offset;
        } else {
          *p_new++ = *p;
        }
      }
      *p_new = '\0';
    }
  }
  return new_str;
}
void *s21_insert(const char *src, const char *str, s21_size_t start_index) {
  if (src == S21_NULL || str == S21_NULL) return S21_NULL;

  s21_size_t src_len = s21_strlen(src);
  if (start_index > src_len) return S21_NULL;

  s21_size_t str_len = s21_strlen(str);
  size_t new_str_len = src_len + str_len + 1;
  char *new_str = malloc(sizeof(char) * new_str_len);

  if (new_str != S21_NULL) {
    s21_memcpy(new_str, src, start_index);
    s21_memcpy(new_str + start_index, str, str_len);
    s21_memcpy(new_str + start_index + str_len, src + start_index,
               src_len - start_index);
    new_str[new_str_len - 1] = '\0';
  }
  return new_str;
}

void *s21_trim(const char *src, const char *trim_chars) {
  if (src == S21_NULL) return S21_NULL;
  if (trim_chars == S21_NULL || trim_chars[0] == '\0') {
    return s21_trim(src, " \t\n\r\f\v");
  }

  const char *start = src;
  const char *end;

  // Trim leading characters
  while (*start && trim_chars != S21_NULL &&
         s21_strchr(trim_chars, *start) != S21_NULL) {
    start++;
  }

  // Trim trailing characters
  end = src + s21_strlen(src) - 1;
  while (end > start && trim_chars != S21_NULL &&
         s21_strchr(trim_chars, *end) != S21_NULL) {
    end--;
  }

  // Create a new string and copy the trimmed content
  size_t trimmed_len = end - start + 1;
  char *trimmed = (char *)malloc(trimmed_len + 1);
  s21_strncpy(trimmed, start, trimmed_len);
  trimmed[trimmed_len] = '\0';

  return trimmed;
}
