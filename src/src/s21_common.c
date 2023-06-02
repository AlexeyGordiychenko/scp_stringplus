#include "s21_common.h"

void reverse_string(char *str) {
  int len = s21_strlen(str);
  for (int k = 0; k < len / 2; k++) {
    char buf = str[k];
    str[k] = str[len - 1 - k];
    str[len - 1 - k] = buf;
  }
}

void pos_int_to_string(long long unsigned int number, char *str) {
  if (number == 0) {
    str[0] = '0';
    str[1] = '\0';
    return;
  }

  int i = 0;
  int is_negative = 0;

  //   if (number < 0) {
  //     is_negative = 1;
  //     number = -number;
  //   }

  while (number > 0) {
    int digit = number % 10;
    str[i++] = '0' + digit;
    number /= 10;
  }

  if (is_negative) {
    str[i++] = '-';
  }

  str[i] = '\0';

  // Обратный порядок символов
  reverse_string(str);
}

void pos_int_to_string_octal(long long unsigned int number, char *str) {
  if (number == 0) {
    str[0] = '0';
    str[1] = '\0';
    return;
  }

  int i = 0;
  int is_negative = 0;

  //   if (number < 0) {
  //     is_negative = 1;
  //     number = -number;
  //   }

  while (number > 0) {
    int digit = number % 8;
    str[i++] = '0' + digit;
    number /= 8;
  }

  if (is_negative) {
    str[i++] = '-';
  }

  str[i] = '\0';

  // Обратный порядок символов
  reverse_string(str);
}

void double_to_string(double number, char *str, int precision) {
  if (number == 0.0) {
    str[0] = '0';
    str[1] = '\0';
    return;
  }

  int i = 0;
  int is_negative = 0;

  if (number < 0) {
    is_negative = 1;
    number = -number;
  }

  // Преобразование целой части числа
  int integer_part = (int)number;
  pos_int_to_string(integer_part, str);

  // Добавление десятичной точки
  int len = s21_strlen(str);
  str[len] = '.';
  i = len + 1;

  // Преобразование десятичной части числа
  double decimal_part = number - integer_part;

  while (precision > 0) {
    decimal_part *= 10;
    int digit = (int)decimal_part;
    str[i++] = '0' + digit;
    decimal_part -= digit;
    precision--;
  }

  if (is_negative) {
    str[i++] = '-';
  }

  str[i] = '\0';
}

void string_to_int(char *str, int *number) {
  // проверка на то является ли строка целым числом
  int i = 0;
  char sign;
  if (str[i] == '-') {
    sign = '-';
    i++;
  }
  while (str[i] != '\0') {
    if (str[i] >= '1' && str[i] <= '9') {
      i++;
      continue;
    } else {
      printf("строка не является целым числом\n");
      return;
    }
  }

  // преобразование в число
  i = (sign == '-') ? 1 : 0;  // устанавиливаем позицию для счетчика
  *number = 0;
  while (str[i] != '\0') {
    *number = *number * 10 + (str[i] - '0');
    i++;
  }

  if (sign == '-') *number = -(*number);
}

void string_to_double(char *str, double *number) {
  // проверка на то является ли строка целым числом
  int i = 0;
  char sign;
  int point = 0;

  if (str[i] == '-') {
    sign = '-';
    i++;
  }

  while (str[i] != '\0') {
    if (str[i] >= '1' && str[i] <= '9') {
      i++;
      continue;
    } else if (str[i] == '.' && !point) {
      point = 1;
      i++;
    } else {
      printf("строка не является вещественным числом\n");
      return;
    }
  }
  // преобразовываем в число
  char *int_part, *dec_part;
  int_part = s21_strtok(str, ".");
  dec_part = s21_strtok(NULL, ".");
  int x, y, len_dec = (int)s21_strlen(dec_part);
  string_to_int(int_part, &x);
  printf("%d\n", x);
  string_to_int(dec_part, &y);
  printf("%d\n", y);
  printf("len = %d\n", len_dec);
  if (sign == '-') {
    *number = x - y / pow(10, len_dec);
  } else {
    *number = x + y / pow(10, len_dec);
  }
}

void int_to_hex(unsigned long int number, char *hex, int reg) {
  if (number == 0) {
    hex[0] = '0';
    hex[1] = '\0';
    return;
  }

  int i = 0;

  while (number > 0) {
    int digit = number % 16;
    if (digit < 10) {
      hex[i] = '0' + digit;  // Цифры 0-9
    } else {
      if (reg) {
        hex[i] = 'A' + (digit - 10);  // Буквы A-F
      } else {
        hex[i] = 'a' + (digit - 10);  // Буквы a-f
      }
    }
    number /= 16;
    i++;
  }

  hex[i] = '\0';

  // Обратный порядок символов
  reverse_string(hex);
}

void input_char_left(char *str, char ch) {
  int len = (int)s21_strlen(str);
  for (int i = len + 1; i > 0; i--) {
    str[i] = str[i - 1];
  }
  str[0] = ch;
}

int int_to_str_min_len(long int number, char *str, bool sign, int min_len) {
  char *p = str;
  int len = 0;
  int spec_case = number == LONG_MIN;
  if (number < 0) {
    if (sign) {
      *p++ = '-';
      len++;
    }
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
