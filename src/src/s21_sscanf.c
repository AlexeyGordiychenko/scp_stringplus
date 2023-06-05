#include "../s21_string.h"
#include "s21_common.h"

typedef struct {
  s21_size_t width;
  bool asterisk;
  char length;
  char spec;
} Flag;

void parse_sscanf_spec(const char **p, Flag *flags);
bool parse_int(const char **str, long *value, Flag flags);
bool process_d_spec_sscanf(Flag flags, va_list *args, const char **p);
bool process_cs_spec_sscanf(Flag flags, va_list *args, const char **p);

void skip_chars(Flag flags, const char **p);
void assign_wchars(Flag flags, const char **p, va_list *args);
void assign_chars(Flag flags, const char **p, va_list *args);

int s21_sscanf(const char *str, const char *format, ...) {
  va_list args;
  va_start(args, format);
  const char *str_p = str;
  s21_size_t count = 0;

  for (const char *p = format; *p != '\0' && *str_p != '\0'; ++p) {
    Flag flags = {0};  // ининциализируем или обнуляем структуру флагов
    if (*p == '%') {
      /* парсинг спецификатора */
      parse_sscanf_spec(&p, &flags);

      // тестовый вывод напарсенных структур
      // printf("width = %lld, asterisk = %d, length = %c, spec = %c\n",
      //        flags.width, flags.asterisk, flags.length, flags.spec);
      switch (flags.spec) {
        case 'd':
          count += process_d_spec_sscanf(flags, &args, &str_p);
          break;
        case 'c':
        case 's':
          count += process_cs_spec_sscanf(flags, &args, &str_p);
          break;
      }
    } else if (s21_isspace(*p)) {
      while (s21_isspace(*str_p)) {
        str_p++;
      }
    } else {
      if (*p != *str_p) {
        // printf("-=does not match=-");
        break;
      }
      str_p++;
    }
  }

  va_end(args);  // Завершаем работу с переменными аргументами

  return count;
}

void parse_sscanf_spec(const char **p, Flag *flags) {
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

bool parse_int(const char **str, long *value, Flag flags) {
  int sign = 1;
  long result = 0;
  bool overflow = false, res = false;
  s21_size_t count = 0;

  // skip whitespace
  while (s21_isspace(**str)) {
    (*str)++;
  }

  // handle sign
  if (**str == '-' || **str == '+') {
    if (**str == '-') sign = -1;
    (*str)++;
    count++;
  }

  // parse digits
  while (s21_isdigit(**str) && (count++ < flags.width || flags.width == 0)) {
    res = true;
    if (!overflow) {
      result = result * 10 + (**str - '0');
      if (result < 0) {
        overflow = true;
        result = (sign == 1) ? LONG_MAX : LONG_MIN;
        sign = 1;
      }
    }
    (*str)++;
  }

  *value = sign * result;

  return res;
}

bool process_d_spec_sscanf(Flag flags, va_list *args, const char **p) {
  long value;
  bool res = parse_int(p, &value, flags);
  if (!flags.asterisk) {
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
  } else {
    res = false;
  }
  return res;
}

bool process_cs_spec_sscanf(Flag flags, va_list *args, const char **p) {
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

void skip_chars(Flag flags, const char **p) {
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

void assign_wchars(Flag flags, const char **p, va_list *args) {
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

void assign_chars(Flag flags, const char **p, va_list *args) {
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