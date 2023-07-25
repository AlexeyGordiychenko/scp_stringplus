#include "../scp_string.h"
#include "scp_common.h"

typedef struct {
  scp_size_t width;
  bool asterisk;
  char length;
  bool double_len;  // for hh, ll
  char spec;
} SFlags;

void parse_sscanf_spec(SFlags *flags, const char **p);

bool process_spec_sscanf(SFlags flags, va_list *args, const char **p,
                         const char **str, int *count);
bool process_dio_spec_sscanf(SFlags flags, va_list *args, int base,
                             const char **p);
bool process_ux_spec_sscanf(SFlags flags, va_list *args, int base,
                            const char **p);
bool process_p_spec_sscanf(SFlags flags, va_list *args, const char **p);
bool process_cs_spec_sscanf(SFlags flags, va_list *args, const char **p);
bool process_n_spec_sscanf(SFlags flags, va_list *args, scp_size_t count);
bool process_f_spec_sscanf(SFlags flags, va_list *args, const char **p);

void assign_int_value(SFlags flags, va_list *args, long long value);
void assign_uint_value(SFlags flags, va_list *args, unsigned long long value);
void assign_wchars(SFlags flags, va_list *args, const char **p);
void assign_chars(SFlags flags, va_list *args, const char **p);
void assign_float_value(SFlags flags, va_list *args, long double value);

void skip_chars(SFlags flags, const char **p);

int scp_sscanf(const char *str, const char *format, ...) {
  va_list args;
  va_start(args, format);
  const char *str_p = str;
  int count = 0;
  bool res = true;

  for (const char *p = format; *p != '\0' && res; ++p) {
    SFlags flags = {0};  // ининциализируем или обнуляем структуру флагов
    if (*p == '%') {
      /* парсинг спецификатора */
      parse_sscanf_spec(&flags, &p);
      /* обработка спецификатора */
      res = process_spec_sscanf(flags, &args, &str_p, &str, &count);
    } else if (scp_isspace(*p)) {
      while (scp_isspace(*str_p)) {
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

bool process_spec_sscanf(SFlags flags, va_list *args, const char **p,
                         const char **str, int *count) {
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
    default:
      res = false;
      break;
  }
  *count += res && !flags.asterisk && flags.spec != 'n' && flags.spec != '%';
  if (*count == 0 && **p == '\0' && !res) {
    *count = -1;
  }
  return res;
}

void parse_sscanf_spec(SFlags *flags, const char **p) {
  // парсим флаги
  (*p)++;

  if (**p == '*') {
    flags->asterisk = true;
    (*p)++;
  }
  while (scp_isdigit(**p)) {
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
  }
}

bool process_dio_spec_sscanf(SFlags flags, va_list *args, int base,
                             const char **p) {
  if (**p == '\0') return false;
  long long value = 0;
  bool res = str_to_int(p, &value, flags.width, base);
  if (res && !flags.asterisk) {
    assign_int_value(flags, args, value);
  }
  return res;
}

bool process_ux_spec_sscanf(SFlags flags, va_list *args, int base,
                            const char **p) {
  if (**p == '\0') return false;
  unsigned long long value = 0;
  bool res = str_to_uint(p, &value, flags.width, base);
  if (res && !flags.asterisk) {
    assign_uint_value(flags, args, value);
  }
  return res;
}

bool process_p_spec_sscanf(SFlags flags, va_list *args, const char **p) {
  if (**p == '\0') return false;
  unsigned long long value = 0;
  bool res = str_to_uint(p, &value, flags.width, 16);
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
    while (scp_isspace(**p)) {
      (*p)++;
    }
  }

  if (flags.asterisk) {  // move the **p, but don't assign to the variable
    skip_chars(flags, p);
  } else {
    if (flags.length == 'l' || flags.length == 'L') {
      assign_wchars(flags, args, p);
    } else {
      assign_chars(flags, args, p);
    }
  }
  return true;
}

bool process_n_spec_sscanf(SFlags flags, va_list *args, scp_size_t count) {
  assign_int_value(flags, args, count);
  return true;
}

bool process_f_spec_sscanf(SFlags flags, va_list *args, const char **p) {
  if (**p == '\0') return false;
  long double value = 0;
  bool res = str_to_float(p, &value, flags.width);
  if (res && !flags.asterisk) {
    assign_float_value(flags, args, value);
  }
  return res;
}

void assign_int_value(SFlags flags, va_list *args, long long value) {
  if (flags.double_len) {
    switch (flags.length) {
      case 'l': {
        long long *l_value;
        l_value = va_arg(*args, long long *);
        *l_value = value;
        break;
      }
      case 'h': {
        signed char *h_value;
        h_value = va_arg(*args, signed char *);
        *h_value = (signed char)value;
        break;
      }
    }
  } else {
    switch (flags.length) {
      case 'l': {
        long *l_value;
        l_value = va_arg(*args, long *);
        *l_value = (long)value;
        break;
      }
      case 'h': {
        short *h_value;
        h_value = va_arg(*args, short *);
        *h_value = (short)value;
        break;
      }
      default: {
        int *p_value;
        p_value = va_arg(*args, int *);
        *p_value = (int)value;
        break;
      }
    }
  }
}

void assign_uint_value(SFlags flags, va_list *args, unsigned long long value) {
  if (flags.double_len) {
    switch (flags.length) {
      case 'l': {
        unsigned long long *l_value;
        l_value = va_arg(*args, unsigned long long *);
        *l_value = value;
        break;
      }
      case 'h': {
        unsigned char *h_value;
        h_value = va_arg(*args, unsigned char *);
        *h_value = (unsigned char)value;
        break;
      }
    }
  } else {
    switch (flags.length) {
      case 'l': {
        unsigned long *l_value;
        l_value = va_arg(*args, unsigned long *);
        *l_value = (unsigned long)value;
        break;
      }
      case 'h': {
        unsigned short *h_value;
        h_value = va_arg(*args, unsigned short *);
        *h_value = (unsigned short)value;
        break;
      }
      default: {
        unsigned int *p_value;
        p_value = va_arg(*args, unsigned int *);
        *p_value = (unsigned int)value;
        break;
      }
    }
  }
}

void assign_wchars(SFlags flags, va_list *args, const char **p) {
  bool is_str = flags.spec == 's';
  scp_size_t width = flags.width;
  if (!is_str && width == 0) width = 1;

  wchar_t *c = va_arg(*args, wchar_t *);
  scp_size_t i = 0;
  for (; (i < width || width == 0) && ((is_str) ? !scp_isspace(**p) : 1) &&
         **p != '\0';
       i++) {
    scp_size_t n = mbrtowc(c++, *p, MB_CUR_MAX, SCP_NULL);
    (*p) += n;
  }
  if (is_str) {
    *c-- = '\0';
  }
}

void assign_chars(SFlags flags, va_list *args, const char **p) {
  bool is_str = flags.spec == 's';
  scp_size_t width = flags.width;
  if (!is_str && width == 0) width = 1;

  char *c = va_arg(*args, char *);
  scp_size_t i = 0;
  for (; (i < width || width == 0) && ((is_str) ? !scp_isspace(**p) : 1) &&
         **p != '\0';
       i++) {
    *c++ = **p;
    (*p)++;
  }
  if (is_str) {
    *c-- = '\0';
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
      scp_size_t n = mbrtowc(SCP_NULL, *p, MB_CUR_MAX, SCP_NULL);
      (*p) += n;
    } else {
      (*p)++;
    }
  } while (**p != '\0' && ((is_str) ? !scp_isspace(**p) : 0));
}
