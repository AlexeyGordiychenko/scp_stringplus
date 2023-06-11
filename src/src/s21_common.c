#include "s21_common.h"

void reverse_string(char *str) {
  int len = s21_strlen(str);
  for (int k = 0; k < len / 2; k++) {
    char buf = str[k];
    str[k] = str[len - 1 - k];
    str[len - 1 - k] = buf;
  }
}

void pos_int_to_string(long long unsigned int number, char *str, int base,
                       bool reg) {
  if (number == 0) {
    str[0] = '0';
    str[1] = '\0';
    return;
  }

  int i = 0;

  while (number > 0) {
    int digit = number % base;
    if (base == 16 && digit >= 10) {
      str[i++] = ((reg) ? 'A' : 'a') + (digit - 10);
    } else {
      str[i++] = '0' + digit;
    }
    number /= base;
  }

  str[i] = '\0';

  // Обратный порядок символов
  reverse_string(str);
}

void double_to_string(long double number, char *buffer, Flag flags) {
  char sign = '\0';
  // считывание знака и приведение к положительному
  if (number < 0) {
    sign = '-';
    number = -number;
  }

  //  разделение на целую и дробную часть
  long double int_part = 0;
  long double frac_part = modfl(number, &int_part);

  // округление целого при нулевой точности
  if (frac_part == 0 || flags.precision == 0) {
    if (round(frac_part) == 1) int_part++;
  }

  // занесение целой части в строку
  pos_int_to_string((long long unsigned int)int_part, buffer, 10, false);

  // обработка дробной части числа
  if ((flags.spec != 'g' || flags.spec != 'G')) {
    if (flags.precision != 0) {
      int i = (int)s21_strlen(buffer);
      buffer[i++] = '.';

      while (flags.precision > 0) {
        double int_frac_part = 0;
        frac_part = modf(frac_part * 10, &int_frac_part);
        buffer[i++] = '0' + (int)int_frac_part;
        flags.precision--;
      }
      buffer[i] = '\0';

      // добавляем разряд если оставшаяся часть больше 0.5
      int plus_one = 0;
      if (frac_part >= 0.5) {
        plus_one = 1;
        i--;  // возвращаемся в позицию последнего
      }

      while (plus_one == 1) {
        if (i == 0) {
          if (buffer[i] == '9') {
            buffer[i] = '0';
          } else {
            buffer[i]++;
            plus_one = 0;
          }
          break;
        } else if (buffer[i] == '9') {
          buffer[i--] = '0';
        } else if (buffer[i] == '.') {
          i--;
        } else {
          buffer[i--]++;
          plus_one = 0;
        }
      }

      if (plus_one) {
        input_char_left(buffer, '1');
      }
    }
  }

  // добавление знака
  if (sign == '-') {
    input_char_left(buffer, sign);
  }

  // откидываем нули дробной части для gG
  if (!flags.prefix && (flags.spec == 'g' || flags.spec == 'G') &&
      s21_strchr(buffer, '.')) {
    int i = (int)s21_strlen(buffer);
    while (buffer[i - 1] == '0' || buffer[i - 1] == '.') {
      if (buffer[i - 1] == '.') {
        buffer[i - 1] = '\0';
        break;
      } else {
        buffer[i - 1] = '\0';
        i--;
      }
    }
  }
}

void pointer_to_string(void *ptr, char *buffer) {
  uintptr_t value = (uintptr_t)ptr;  // Преобразуем указатель в целое число

  int i = 0;
  while (value != 0) {
    int digit = value & 0xF;  // Получаем младшую четырехбитную цифру
    /*Строка int digit = value & 0xF; выполняет побитовую операцию "И" (AND)
между значением value и шаблоном 0xF.

Шаблон 0xF представляет собой 4 бита, установленных в единицу: 0000 1111 в
двоичном представлении. Этот шаблон используется для выделения младшей
четырехбитной цифры из значения value.

Побитовая операция "И" между двоичными значениями выполняется побитово: каждый
бит в результирующем значении будет равен 1, только если соответствующие биты
в обоих операндах равны 1. В противном случае, если хотя бы один из битов
равен 0, соответствующий бит в результирующем значении будет равен 0.

Таким образом, строка int digit = value & 0xF; сохраняет младшую четырехбитную
цифру из значения value в переменной digit*/

    buffer[i++] = (digit < 10) ? ('0' + digit) : ('a' + digit - 10);
    value >>= 4;  // Сдвигаем число на 4 бита вправо
  }

  if (i == 0) {
    buffer[i++] = '0';  // Если указатель равен нулю, добавляем цифру 0
  }
  buffer[i] = '\0';
  reverse_string(buffer);
}

void input_char_left(char *str, char ch) {
  int len = (int)s21_strlen(str);
  for (int i = len + 1; i > 0; i--) {
    str[i] = str[i - 1];
  }
  str[0] = ch;
}

int int_to_str_min_len(long int number, char *str, int min_len) {
  char *p = str;
  int len = 0;
  int spec_case = number == LONG_MIN;
  if (number < 0) {
    number = (spec_case) ? LONG_MAX : -number;
  }

  long int temp = number;
  do {
    p++;
    temp /= 10;
  } while (temp);

  int leading_zeros = min_len - (p - str);
  if (leading_zeros > 0) {
    p += leading_zeros;
  } else {
    leading_zeros = 0;
  }

  *p = '\0';

  do {
    *--p = '0' + (number % 10) + spec_case;
    spec_case = 0;
    number /= 10;
    len++;
  } while (number);

  len += leading_zeros;

  while (leading_zeros > 0) {
    *--p = '0';
    leading_zeros--;
  }

  return len;
}

int put_wchar(char **p, wchar_t wchar) {
  int res = 0;
  int bytes_written = wctomb(*p, wchar);
  if (bytes_written > 0) {
    (*p) += bytes_written;
    res = bytes_written - 1;
  }
  return res;
}

bool s21_isdigit(int a) { return (a >= '0' && a <= '9'); }

bool s21_isspace(int c) {
  return (c == ' ' || c == '\t' || c == '\n' || c == '\r' || c == '\f' ||
          c == '\v');
}

int char_to_digit(char c, int base) {
  int digit = -1;
  if (s21_isdigit(c)) {
    digit = c - '0';
  } else if (base == 16) {
    if (c >= 'a' && c <= 'f') {
      digit = c - 'a' + 10;
    } else if (c >= 'A' && c <= 'F') {
      digit = c - 'A' + 10;
    }
  }
  return digit;
}

bool str_to_int(const char **str, long long *value, s21_size_t width,
                int base) {
  int sign = 1;
  long long result = 0;
  bool overflow = false;
  s21_size_t count = 0;

  bool res = parse_pre_number(&count, &sign, width, &base, str);

  while (count++ < width || width == 0) {
    int digit = char_to_digit(**str, base);

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

bool str_to_uint(const char **str, unsigned long long *value, s21_size_t width,
                 int base) {
  int sign = 1;
  unsigned long long result = 0;
  bool overflow = false;
  s21_size_t count = 0;

  bool res = parse_pre_number(&count, &sign, width, &base, str);

  while (count++ < width || width == 0) {
    int digit = char_to_digit(**str, base);

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

bool str_to_float(const char **str, long double *value, s21_size_t width) {
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
    str_to_int(str, &exponent, width - count, 10);
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

bool possible_nan_inf(char c) {
  return (c == 'n' || c == 'N' || c == 'i' || c == 'I');
}

bool get_nan_inf(const char **str, s21_size_t width, s21_size_t count, int sign,
                 long double *value) {
  bool res = false;
  char tmp[9] = {'\0'};
  char *tmp_lower = s21_to_lower(s21_strncpy(tmp, *str, 8));
  if ((count + 8 <= width || width == 0) &&
      s21_strncmp(tmp_lower, "infinity", 8) == 0) {
    (*str) += 8;
    *value = sign * INFINITY;
    res = true;
  } else if (count + 3 <= width || width == 0) {
    if (s21_strncmp(tmp_lower, "nan", 3) == 0) {
      (*str) += 3;
      *value = sign * NAN;
      res = true;
    } else if (s21_strncmp(tmp_lower, "inf", 3) == 0) {
      (*str) += 3;
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
    int digit = char_to_digit(**str, base);

    if (digit >= 0 && digit < base) {
      res = true;
      (*count)++;
      if (!overflow) {
        if (*value > (LDBL_MAX - digit) / base) {
          overflow = true;
          *value = (*sign == 1) ? LDBL_MAX : LDBL_MIN;
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
