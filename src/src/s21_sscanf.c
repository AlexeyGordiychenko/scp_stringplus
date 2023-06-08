#include "../s21_string.h"
#include "s21_common.h"

typedef struct {
  s21_size_t width;
  bool asterisk;
  char length;
  char spec;
} SFlags;

void parse_sscanf_spec(const char **p, SFlags *flags);
bool parse_int(const char **str, long *value, s21_size_t width, int base);
bool parse_uint(const char **str, unsigned long *value, s21_size_t width,
                int base);
bool parse_pre_number(s21_size_t *count, int *sign, s21_size_t width, int *base,
                      const char **str);
bool process_dio_spec_sscanf(SFlags flags, va_list *args, int base,
                             const char **p);
bool process_ux_spec_sscanf(SFlags flags, va_list *args, int base,
                            const char **p);
bool process_p_spec_sscanf(SFlags flags, va_list *args, const char **p);
bool process_cs_spec_sscanf(SFlags flags, va_list *args, const char **p);
bool process_n_spec_sscanf(SFlags flags, va_list *args, s21_size_t count);
void assign_int_value(SFlags flags, va_list *args, long value);
void assign_uint_value(SFlags flags, va_list *args, long value);
void assign_wchars(SFlags flags, const char **p, va_list *args);
void assign_chars(SFlags flags, const char **p, va_list *args);

void skip_chars(SFlags flags, const char **p);
int base16_digit(int c);
int get_digit(const char **str, int base);

int s21_sscanf(const char *str, const char *format, ...) {
  va_list args;
  va_start(args, format);
  const char *str_p = str;
  s21_size_t count = 0;

  for (const char *p = format; *p != '\0'; ++p) {
    SFlags flags = {0};  // ининциализируем или обнуляем структуру флагов
    if (*p == '%') {
      /* парсинг спецификатора */
      parse_sscanf_spec(&p, &flags);

      // тестовый вывод напарсенных структур
      // printf("width = %lld, asterisk = %d, length = %c, spec = %c\n",
      //        flags.width, flags.asterisk, flags.length, flags.spec);
      switch (flags.spec) {
        case 'd':
          count += process_dio_spec_sscanf(flags, &args, 10, &str_p);
          break;
        case 'i':
          count += process_dio_spec_sscanf(flags, &args, 0, &str_p);
          break;
        case 'o':
          count += process_dio_spec_sscanf(flags, &args, 8, &str_p);
          break;
        case 'u':
          count += process_ux_spec_sscanf(flags, &args, 10, &str_p);
          break;
        case 'x':
        case 'X':
          count += process_ux_spec_sscanf(flags, &args, 16, &str_p);
          break;
        case 'p':
          count += process_p_spec_sscanf(flags, &args, &str_p);
          break;
        case 'c':
        case 's':
          count += process_cs_spec_sscanf(flags, &args, &str_p);
          break;
        case 'n':
          process_n_spec_sscanf(flags, &args, str_p - str);
          break;
      }
    } else if (s21_isspace(*p)) {
      while (s21_isspace(*str_p)) {
        str_p++;
      }
    } else {
      if (*p != *str_p) {
        break;
      }
      str_p++;
    }
  }

  va_end(args);  // Завершаем работу с переменными аргументами

  return count;
}

void parse_sscanf_spec(const char **p, SFlags *flags) {
  // парсим флаги
  (*p)++;

  if (**p == '*') {
    flags->asterisk = true;
    (*p)++;
  }
  while (s21_isdigit(**p)) {
    flags->width = flags->width * 10 + (**p - '0');
    (*p)++;
  }

  // Парсим длину
  while (**p == 'h' || **p == 'l' || **p == 'L') {
    flags->length = **p;
    (*p)++;
  }

  // Парсим спецификатор
  switch (**p) {
    case 'c':
    case 'd':
    case 'i':
    case 'e':
    case 'E':
    case 'f':
    case 'g':
    case 'G':
    case 'o':
    case 's':
    case 'u':
    case 'x':
    case 'X':
    case 'p':
    case 'n':
    case '%':
      flags->spec = **p;
      break;
    default:
      printf("Ошибка: Некорректный спецификатор %c\n", **p);
      // exit(0);  // что делаем если некорр. спец?
      break;
  }
}

bool parse_int(const char **str, long *value, s21_size_t width, int base) {
  int sign = 1;
  long result = 0;
  bool overflow = false;
  s21_size_t count = 0;

  bool res = parse_pre_number(&count, &sign, width, &base, str);

  while (count++ < width || width == 0) {
    int digit = get_digit(str, base);

    if (digit >= 0 && digit < base) {
      res = true;
      if (!overflow) {
        if (result > (LONG_MAX - digit) / base) {
          overflow = true;
          result = (sign == 1) ? LONG_MAX : LONG_MIN;
          sign = 1;
        } else {
          result = result * base + digit;
        }
      }
      (*str)++;
    } else {
      break;
    }
  }
  *value = sign * result;

  return res;
}

bool parse_uint(const char **str, unsigned long *value, s21_size_t width,
                int base) {
  int sign = 1;
  unsigned long result = 0;
  bool overflow = false;
  s21_size_t count = 0;

  bool res = parse_pre_number(&count, &sign, width, &base, str);

  while (count++ < width || width == 0) {
    int digit = get_digit(str, base);

    if (digit >= 0 && digit < base) {
      res = true;
      if (!overflow) {
        if (result > (ULONG_MAX - digit) / base) {
          overflow = true;
          result = ULONG_MAX;
          sign = 1;
        } else {
          result = result * base + digit;
        }
      }
      (*str)++;
    } else {
      break;
    }
  }
  *value = sign * result;

  return res;
}

bool parse_pre_number(s21_size_t *count, int *sign, s21_size_t width, int *base,
                      const char **str) {
  bool res = false;

  // skip whitespace
  while (s21_isspace(**str)) {
    (*str)++;
  }

  // handle sign
  if (**str == '-' || **str == '+') {
    if (**str == '-') *sign = -1;
    (*str)++;
    (*count)++;
    if (width == 1) {
      while (**str) (*str)++;
    }
  }

  // handle base
  if (*base == 0 || *base == 16) {
    int new_base = 10;
    if (**str == '0' && ((*count)++ < width || width == 0)) {
      res = true;
      new_base = 8;
      (*str)++;
      if ((**str == 'x' || **str == 'X') &&
          ((*count)++ < width || width == 0)) {
        new_base = 16;
        (*str)++;
      }
    }
    if (*base == 0) {
      *base = new_base;
    }
  }
  return res;
}

bool process_dio_spec_sscanf(SFlags flags, va_list *args, int base,
                             const char **p) {
  if (**p == '\0') return false;
  long value;
  bool res = parse_int(p, &value, flags.width, base);
  if (!flags.asterisk) {
    assign_int_value(flags, args, value);
  } else {
    res = false;
  }
  return res;
}

bool process_ux_spec_sscanf(SFlags flags, va_list *args, int base,
                            const char **p) {
  if (**p == '\0') return false;
  unsigned long value;
  bool res = parse_uint(p, &value, flags.width, base);
  if (!flags.asterisk) {
    assign_uint_value(flags, args, value);
  } else {
    res = false;
  }
  return res;
}

bool process_p_spec_sscanf(SFlags flags, va_list *args, const char **p) {
  if (**p == '\0') return false;
  unsigned long value;
  bool res = parse_uint(p, &value, flags.width, 16);
  if (!flags.asterisk) {
    void **p_value = va_arg(*args, void **);
    *p_value = (void *)value;
  } else {
    res = false;
  }
  return res;
}

bool process_cs_spec_sscanf(SFlags flags, va_list *args, const char **p) {
  if (**p == '\0') return false;
  if (flags.spec == 's') {
    // skip whitespace
    while (s21_isspace(**p)) {
      (*p)++;
    }
  }

  if (flags.asterisk) {  // move the **p, but don't assign to the variable
    skip_chars(flags, p);
  } else {
    if (flags.length == 'l' || flags.length == 'L') {
      assign_wchars(flags, p, args);
    } else {
      assign_chars(flags, p, args);
    }
  }
  return !flags.asterisk;
}

bool process_n_spec_sscanf(SFlags flags, va_list *args, s21_size_t count) {
  assign_int_value(flags, args, count);
  // int *p_value = va_arg(*args, int *);
  // *p_value = count;
  return count != 0;
}

void assign_int_value(SFlags flags, va_list *args, long value) {
  if (flags.length == 'l' || flags.length == 'L') {
    long *p_value = va_arg(*args, long *);
    *p_value = value;
  } else if (flags.length == 'h') {
    short *p_value = va_arg(*args, short *);
    *p_value = (short)value;
  } else {
    int *p_value = va_arg(*args, int *);
    *p_value = (int)value;
  }
}

void assign_uint_value(SFlags flags, va_list *args, long value) {
  if (flags.length == 'l' || flags.length == 'L') {
    unsigned long *p_value = va_arg(*args, unsigned long *);
    *p_value = value;
  } else if (flags.length == 'h') {
    unsigned short *p_value = va_arg(*args, unsigned short *);
    *p_value = (unsigned short)value;
  } else {
    unsigned int *p_value = va_arg(*args, unsigned int *);
    *p_value = (unsigned int)value;
  }
}

void assign_wchars(SFlags flags, const char **p, va_list *args) {
  bool is_str = flags.spec == 's';
  s21_size_t width = flags.width;
  if (!is_str && width == 0) width = 1;

  wchar_t *c = va_arg(*args, wchar_t *);
  s21_size_t i = 0;
  for (; (i < width || width == 0) && ((is_str) ? !s21_isspace(**p) : 1) &&
         **p != '\0';
       i++) {
    s21_size_t n = mbrtowc(c++, *p, MB_CUR_MAX, NULL);
    (*p) += n;
  }
  if (is_str) {
    *c-- = '\0';
    for (; i != 0 && s21_isspace(*c); i--, c--) {
      *c = '\0';
    }
  }
}

void assign_chars(SFlags flags, const char **p, va_list *args) {
  bool is_str = flags.spec == 's';
  s21_size_t width = flags.width;
  if (!is_str && width == 0) width = 1;

  char *c = va_arg(*args, char *);
  s21_size_t i = 0;
  for (; (i < width || width == 0) && ((is_str) ? !s21_isspace(**p) : 1) &&
         **p != '\0';
       i++) {
    *c++ = **p;
    (*p)++;
  }
  if (is_str) {
    *c-- = '\0';
    for (; i != 0 && s21_isspace(*c); i--, c--) {
      *c = '\0';
    }
  }
}

void skip_chars(SFlags flags, const char **p) {
  bool is_str = flags.spec == 's';
  bool is_wide = flags.length == 'l' || flags.length == 'L';

  do {
    if (is_wide) {
      s21_size_t n = mbrtowc(NULL, *p, MB_CUR_MAX, NULL);
      (*p) += n;
    } else {
      (*p)++;
    }
  } while (**p != '\0' && ((is_str) ? !s21_isspace(**p) : 0));
}

int base16_digit(int c) {
  int res = -1;
  if (c >= '0' && c <= '9') {
    res = c - '0';
  } else if (c >= 'a' && c <= 'f') {
    res = c - 'a' + 10;
  } else if (c >= 'A' && c <= 'F') {
    res = c - 'A' + 10;
  }
  return res;
}

int get_digit(const char **str, int base) {
  int digit = -1;
  if (s21_isdigit(**str)) {
    digit = **str - '0';
  } else if (base == 16) {
    digit = base16_digit(**str);
  }
  return digit;
}
