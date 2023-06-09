#include "../s21_string.h"
#include "s21_common.h"

typedef struct {
  s21_size_t width;
  bool asterisk;
  char length;
  bool double_len;  // for hh, ll
  char spec;
} SFlags;

void parse_sscanf_spec(const char **p, SFlags *flags);
bool parse_int(const char **str, long long *value, s21_size_t width, int base);
bool parse_uint(const char **str, unsigned long long *value, s21_size_t width,
                int base);
bool parse_float(const char **str, long double *value, s21_size_t width);
bool parse_pre_number(s21_size_t *count, int *sign, s21_size_t width, int *base,
                      const char **str);

bool process_spec(SFlags flags, va_list *args, const char **p, const char **str,
                  s21_size_t *count);
bool process_dio_spec_sscanf(SFlags flags, va_list *args, int base,
                             const char **p);
bool process_ux_spec_sscanf(SFlags flags, va_list *args, int base,
                            const char **p);
bool process_p_spec_sscanf(SFlags flags, va_list *args, const char **p);
bool process_cs_spec_sscanf(SFlags flags, va_list *args, const char **p);
bool process_n_spec_sscanf(SFlags flags, va_list *args, s21_size_t count);
bool process_f_spec_sscanf(SFlags flags, va_list *args, const char **p);

void assign_int_value(SFlags flags, va_list *args, long long value);
void assign_uint_value(SFlags flags, va_list *args, unsigned long long value);
void assign_wchars(SFlags flags, const char **p, va_list *args);
void assign_chars(SFlags flags, const char **p, va_list *args);
void assign_float_value(SFlags flags, va_list *args, long double value);

void skip_chars(SFlags flags, const char **p);
int base16_digit(int c);
int get_digit(const char **str, int base);
bool possible_nan_inf(char c);
bool get_nan_inf(const char **str, s21_size_t width, s21_size_t count, int sign,
                 long double *value);
bool str_to_float_overflow(const char **str, long double *value,
                           s21_size_t width, s21_size_t *count, int *sign,
                           int base);

int s21_sscanf(const char *str, const char *format, ...) {
  va_list args;
  va_start(args, format);
  const char *str_p = str;
  s21_size_t count = 0;
  bool res = true;

  for (const char *p = format; *p != '\0' && res; ++p) {
    SFlags flags = {0};  // ининциализируем или обнуляем структуру флагов
    if (*p == '%') {
      /* парсинг спецификатора */
      parse_sscanf_spec(&p, &flags);
      /* обработка спецификатора */
      res = process_spec(flags, &args, &str_p, &str, &count);
    } else if (s21_isspace(*p)) {
      while (s21_isspace(*str_p)) {
        str_p++;
      }
    } else {
      if (*p != *str_p) {
        res = false;
      }
      str_p++;
    }
  }

  va_end(args);  // Завершаем работу с переменными аргументами

  return count;
}

bool process_spec(SFlags flags, va_list *args, const char **p, const char **str,
                  s21_size_t *count) {
  bool res = true;
  switch (flags.spec) {
    case 'd':
      res = process_dio_spec_sscanf(flags, args, 10, p);
      break;
    case 'i':
      res = process_dio_spec_sscanf(flags, args, 0, p);
      break;
    case 'o':
      res = process_dio_spec_sscanf(flags, args, 8, p);
      break;
    case 'u':
      res = process_ux_spec_sscanf(flags, args, 10, p);
      break;
    case 'x':
    case 'X':
      res = process_ux_spec_sscanf(flags, args, 16, p);
      break;
    case 'f':
    case 'g':
    case 'G':
    case 'e':
    case 'E':
      res = process_f_spec_sscanf(flags, args, p);
      break;
    case 'p':
      res = process_p_spec_sscanf(flags, args, p);
      break;
    case 'c':
    case 's':
      res = process_cs_spec_sscanf(flags, args, p);
      break;
    case 'n':
      process_n_spec_sscanf(flags, args, *p - *str);
      break;
    case '%':
      (*p)++;
      break;
  }
  *count += res && !flags.asterisk && flags.spec != 'n' && flags.spec != '%';
  return res;
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
  if (**p == 'h' || **p == 'l' || **p == 'L') {
    flags->length = **p;
    (*p)++;
    if (flags->length == **p) {
      flags->double_len = true;
      (*p)++;
    }
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

bool parse_int(const char **str, long long *value, s21_size_t width, int base) {
  int sign = 1;
  long long result = 0;
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

bool parse_uint(const char **str, unsigned long long *value, s21_size_t width,
                int base) {
  int sign = 1;
  unsigned long long result = 0;
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

bool parse_float(const char **str, long double *value, s21_size_t width) {
  int sign = 1, base = 10;
  s21_size_t count = 0, decimal_places = 0;
  long double integer_part = 0, decimal_part = 0;
  long long exponent = 0;

  bool res = parse_pre_number(&count, &sign, width, &base, str);
  if (possible_nan_inf(**str)) {
    return get_nan_inf(str, width, count, sign, value);
  }

  res = str_to_float_overflow(str, &integer_part, width, &count, &sign, base) ||
        res;

  if (**str == '.' && (count < width || width == 0)) {
    (*str)++;
    count++;
    decimal_places = count;
    res =
        str_to_float_overflow(str, &decimal_part, width, &count, &sign, base) ||
        res;
    decimal_places = count - decimal_places;
  }

  if ((**str == 'e' || **str == 'E') && (count++ < width || width == 0)) {
    (*str)++;
    parse_int(str, &exponent, width - count, 10);
  }

  *value = sign * ((integer_part + decimal_part / pow(10, decimal_places)) *
                   pow(10, exponent));

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
  long long value = 0;
  bool res = parse_int(p, &value, flags.width, base);
  if (res && !flags.asterisk) {
    assign_int_value(flags, args, value);
  }
  return res;
}

bool process_ux_spec_sscanf(SFlags flags, va_list *args, int base,
                            const char **p) {
  if (**p == '\0') return false;
  unsigned long long value = 0;
  bool res = parse_uint(p, &value, flags.width, base);
  if (res && !flags.asterisk) {
    assign_uint_value(flags, args, value);
  }
  return res;
}

bool process_p_spec_sscanf(SFlags flags, va_list *args, const char **p) {
  if (**p == '\0') return false;
  unsigned long long value = 0;
  bool res = parse_uint(p, &value, flags.width, 16);
  if (res && !flags.asterisk) {
    void **p_value = va_arg(*args, void **);
    *p_value = (void *)value;
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
  return true;
}

bool process_n_spec_sscanf(SFlags flags, va_list *args, s21_size_t count) {
  assign_int_value(flags, args, count);
  return true;
}

bool process_f_spec_sscanf(SFlags flags, va_list *args, const char **p) {
  if (**p == '\0') return false;
  long double value = 0;
  bool res = parse_float(p, &value, flags.width);
  if (res && !flags.asterisk) {
    assign_float_value(flags, args, value);
  }
  return res;
}

void assign_int_value(SFlags flags, va_list *args, long long value) {
  if (flags.double_len) {
    switch (flags.length) {
      case 'l':
        long long *l_value = va_arg(*args, long long *);
        *l_value = value;
        break;
      case 'h':
        signed char *h_value = va_arg(*args, signed char *);
        *h_value = (signed char)value;
        break;
      default:
        int *p_value = va_arg(*args, int *);
        *p_value = (int)value;
        break;
    }
  } else {
    switch (flags.length) {
      case 'l':
        long *l_value = va_arg(*args, long *);
        *l_value = (long)value;
        break;
      case 'h':
        short *h_value = va_arg(*args, short *);
        *h_value = (short)value;
        break;
      default:
        int *p_value = va_arg(*args, int *);
        *p_value = (int)value;
        break;
    }
  }
}

void assign_uint_value(SFlags flags, va_list *args, unsigned long long value) {
  if (flags.double_len) {
    switch (flags.length) {
      case 'l':
        unsigned long long *l_value = va_arg(*args, unsigned long long *);
        *l_value = value;
        break;
      case 'h':
        unsigned char *h_value = va_arg(*args, unsigned char *);
        *h_value = (unsigned char)value;
        break;
      default:
        unsigned int *p_value = va_arg(*args, unsigned int *);
        *p_value = (unsigned int)value;
        break;
    }
  } else {
    switch (flags.length) {
      case 'l':
        unsigned long *l_value = va_arg(*args, unsigned long *);
        *l_value = (unsigned long)value;
        break;
      case 'h':
        unsigned short *h_value = va_arg(*args, unsigned short *);
        *h_value = (unsigned short)value;
        break;
      default:
        unsigned int *p_value = va_arg(*args, unsigned int *);
        *p_value = (unsigned int)value;
        break;
    }
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
    s21_size_t n = mbrtowc(c++, *p, MB_CUR_MAX, S21_NULL);
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

void assign_float_value(SFlags flags, va_list *args, long double value) {
  if (flags.length == 'L') {
    long double *ld_value = va_arg(*args, long double *);
    *ld_value = value;
  } else if (flags.length == 'l') {
    double *d_value = va_arg(*args, double *);
    *d_value = (double)value;
  } else {
    float *p_value = va_arg(*args, float *);
    *p_value = (float)value;
  }
}

void skip_chars(SFlags flags, const char **p) {
  bool is_str = flags.spec == 's';
  bool is_wide = flags.length == 'l' || flags.length == 'L';

  do {
    if (is_wide) {
      s21_size_t n = mbrtowc(S21_NULL, *p, MB_CUR_MAX, S21_NULL);
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

bool possible_nan_inf(char c) {
  return (c == 'n' || c == 'N' || c == 'i' || c == 'I');
}

bool get_nan_inf(const char **str, s21_size_t width, s21_size_t count, int sign,
                 long double *value) {
  bool res = false;
  char tmp[9] = {'\0'};
  char *tmp_lower = s21_to_lower(s21_strncpy(tmp, *str, 8));
  if (count + 3 <= width || width == 0) {
    if (s21_strncmp(tmp_lower, "nan", 3) == 0) {
      (*str) += 3;
      *value = sign * NAN;
      res = true;
    } else if (s21_strncmp(tmp_lower, "inf", 3) == 0) {
      (*str) += 3;
      *value = sign * INFINITY;
      res = true;
    }
  } else if (count + 8 <= width || width == 0) {
    if (s21_strncmp(tmp_lower, "infinity", 8) == 0) {
      (*str) += 8;
      *value = sign * INFINITY;
      res = true;
    }
  }
  free(tmp_lower);
  return res;
}

bool str_to_float_overflow(const char **str, long double *value,
                           s21_size_t width, s21_size_t *count, int *sign,
                           int base) {
  bool res = false, overflow = false;
  while (*count < width || width == 0) {
    int digit = get_digit(str, base);

    if (digit >= 0 && digit < base) {
      res = true;
      (*count)++;
      if (!overflow) {
        if (*value > (DBL_MAX - digit) / base) {
          overflow = true;
          *value = (*sign == 1) ? DBL_MAX : DBL_MIN;
          *sign = 1;
        } else {
          *value = *value * base + digit;
        }
      }
      (*str)++;
    } else {
      break;
    }
  }
  return res;
}