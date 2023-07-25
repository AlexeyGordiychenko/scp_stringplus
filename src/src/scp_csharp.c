#include "../scp_string.h"

char *change_case(const char *c, int offset);

void *scp_to_upper(const char *str) {
  /*Возвращает копию строки (str), преобразованной в верхний регистр. В
   * случае какой-либо ошибки следует вернуть значение NULL*/
  return change_case(str, 'a' - 'A');
}

void *scp_to_lower(const char *str) {
  /*Возвращает копию строки (str), преобразованной в нижний регистр. В
   * случае какой-либо ошибки следует вернуть значение NULL*/
  return change_case(str, 'A' - 'a');
}

char *change_case(const char *str, int offset) {
  char *new_str = SCP_NULL;

  if (str != SCP_NULL) {
    const char *p = str;
    new_str = malloc(sizeof(char) * scp_strlen(str) + 1);
    if (new_str != SCP_NULL) {
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
void *scp_insert(const char *src, const char *str, scp_size_t start_index) {
  if (src == SCP_NULL || str == SCP_NULL) return SCP_NULL;

  scp_size_t src_len = scp_strlen(src);
  if (start_index > src_len) return SCP_NULL;

  scp_size_t str_len = scp_strlen(str);
  size_t new_str_len = src_len + str_len + 1;
  char *new_str = malloc(sizeof(char) * new_str_len);

  if (new_str != SCP_NULL) {
    scp_memcpy(new_str, src, start_index);
    scp_memcpy(new_str + start_index, str, str_len);
    scp_memcpy(new_str + start_index + str_len, src + start_index,
               src_len - start_index);
    new_str[new_str_len - 1] = '\0';
  }
  return new_str;
}

void *scp_trim(const char *src, const char *trim_chars) {
  if (src == SCP_NULL) return SCP_NULL;
  if (trim_chars == SCP_NULL || trim_chars[0] == '\0') {
    return scp_trim(src, " \t\n\r\f\v");
  }

  const char *start = src;
  const char *end;

  // Trim leading characters
  while (*start && trim_chars != SCP_NULL &&
         scp_strchr(trim_chars, *start) != SCP_NULL) {
    start++;
  }

  // Trim trailing characters
  end = src + scp_strlen(src) - 1;
  while (end > start && trim_chars != SCP_NULL &&
         scp_strchr(trim_chars, *end) != SCP_NULL) {
    end--;
  }

  // Create a new string and copy the trimmed content
  size_t trimmed_len = end - start + 1;
  char *trimmed = (char *)malloc(trimmed_len + 1);
  scp_strncpy(trimmed, start, trimmed_len);
  trimmed[trimmed_len] = '\0';

  return trimmed;
}
