#include "../s21_string.h"

typedef struct {
  int minus;
  int sign;
  int space;
  int prefix;
  int zero;
  int width;
  int precision;
  char length;
  char spec;
} Flag;

void parse_spec(const char **p, Flag *flags, va_list args);

void reverse_string(char *str);
void int_to_string(int number, char *str);
int int_to_str_min_len(long int number, char *str, bool sign, int min_len);
void double_to_string(double number, char *str, int precision);
void string_to_int(char *str, int *number);
void string_to_double(char *str, double *number);
void int_to_hex(int number, char *hex, int reg);
void input_char(char *str, char ch);

void execute_x(char **p, int number, Flag flags);
void execute_percent(char **str);
void execute_n(int *var, int count);
void process_d_spec(Flag flags, va_list args, char **p);

int s21_sprintf(char *str, const char *format, ...) {
  va_list args;
  va_start(args, format);
  char *str_p = str;

  for (const char *p = format; *p != '\0'; ++p) {
    Flag flags = {0};  // ининциализируем или обнуляем структуру флагов
    if (*p == '%') {
      /* парсинг спецификатора */
      parse_spec(&p, &flags, args);

      // тестовый вывод напарсенных структур
      /*      printf(
                "minus = %d, sign = %d, space = %d, prefix = %d, zero = %d,
         width = "
                "%d, precison = %d, spec = %c\n",
                flags.minus, flags.sign, flags.space, flags.prefix, flags.zero,
                flags.width, flags.precision, flags.spec);
      */
      // обработка спецификатора и аргумента
      switch (flags.spec) {
        case '%':
          execute_percent(&str_p);
          break;
        case 'n':
          execute_n(va_arg(args, int *), (str_p - str));
          break;
        case 'x':
        case 'X':
          execute_x(&str_p, va_arg(args, int), flags);
          break;
        case 'd':
          process_d_spec(flags, args, &str_p);
      }
      // вывод результата в строку
    } else {
      *str_p++ = *p;
    }
  }
  *str_p = '\0';  // Добавляем нулевой символ в конце строки

  va_end(args);  // Завершаем работу с переменными аргументами

  return str_p - str;
}

void parse_spec(const char **p, Flag *flags, va_list args) {
  // первоначальное значение -1, т.к. 0 - валидное значение
  flags->precision = -1;

  // парсим флаги
  (*p)++;
  while (true) {
    if (**p == '-') {
      flags->minus = 1;
    } else if (**p == '+') {
      flags->sign = 1;
    } else if (**p == ' ' && !flags->sign) {
      flags->space = 1;
    } else if (**p == '#') {
      flags->prefix = 1;
    } else if (**p == '0') {
      flags->zero = 1;
    } else {
      break;
    }
    (*p)++;
  }

  // парсим ширину
  if (**p >= '1' && **p <= '9') {
    while (**p >= '0' && **p <= '9') {
      flags->width = flags->width * 10 + (**p - '0');
      (*p)++;
    }
  } else if (**p == '*') {
    flags->width = va_arg(args, int);  // значение для считывание из аргумента
    (*p)++;
  }

  // парсим точность
  if (**p == '.') {
    (*p)++;
    flags->precision = 0;
    if (**p >= '0' && **p <= '9') {
      while (**p >= '0' && **p <= '9') {
        flags->precision = flags->precision * 10 + (**p - '0');
        (*p)++;
      }
    } else if (**p == '*') {
      flags->precision =
          va_arg(args, int);  // значение для считывание из аргумента
      (*p)++;
    }
  }

  // Парсим длину
  switch (**p) {
    case 'h':
    case 'l':
    case 'L':
      flags->length = **p;
      (*p)++;
      break;
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
      // (*p)++;
      break;
    default:
      printf("Ошибка: Некорректный спецификатор %c\n", **p);
      // exit(0);  // что делаем если некорр. спец?
      break;
  }
}

void reverse_string(char *str) {
  int len = s21_strlen(str);
  for (int k = 0; k < len / 2; k++) {
    char buf = str[k];
    str[k] = str[len - 1 - k];
    str[len - 1 - k] = buf;
  }
}

void int_to_string(int number, char *str) {
  if (number == 0) {
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
  int_to_string(integer_part, str);

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

void int_to_hex(int number, char *hex, int reg) {
  if (number == 0) {
    hex[0] = '0';
    hex[1] = '\0';
    return;
  }

  int i = 0;
  // int minus = 0;
  if (number < 0) {
    //    minus = 1;
    number = -number;
  }

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
  /* эту часть отключаю, т.к. у нас по заданию на вход идут только положительные
  числа if (minus) { hex[i] = '-'; // Добавляем знак минуса i++;
  }*/
  hex[i] = '\0';

  // Обратный порядок символов
  reverse_string(hex);
}

void input_char(char *str, char ch) {
  int len = (int)s21_strlen(str);
  for (int i = len + 1; i > 0; i--) {
    str[i] = str[i - 1];
  }
  str[0] = ch;
}

void execute_x(char **p, int number, Flag flags) {
  char hex[1000];
  if (flags.spec == 'x') int_to_hex(number, hex, 0);
  if (flags.spec == 'X') int_to_hex(number, hex, 1);

  // обработка флагов
  if (flags.prefix) {  // флаг #
    if (flags.spec == 'x') input_char(hex, 'x');
    if (flags.spec == 'X') input_char(hex, 'X');
    input_char(hex, '0');
  }

  if (flags.precision != 0) {  // точность, дополняем нулями слева
    while ((int)s21_strlen(hex) < flags.precision) {
      input_char(hex, '0');
    }
  }

  if (flags.width != 0 && !flags.minus) {
    char ch = ' ';
    if (flags.zero) ch = '0';
    while ((int)s21_strlen(hex) < flags.width) {
      input_char(hex, ch);
    }
  }

  int hex_len = (int)s21_strlen(hex);
  s21_strncat(*p, hex, hex_len + 1);
  (*p) += hex_len;
}

void execute_percent(char **p) {
  /*
 пока комментирую, т.к. непонятно, нужно это или нет
 void execute_percent(char *str, int *ind, Flag *flags) {

   char percent[1000] = "%";

   if (flags->precision != 0) {  // точность, дополняем нулями слева
     while ((int)s21_strlen(percent) < flags->precision) {
       input_char(percent, '0');
     }
   }
   if (flags->width != 0 && !flags->minus) {
     char ch = ' ';
     if (flags->zero) ch = '0';
     while ((int)s21_strlen(percent) < flags->width) {
       input_char(percent, ch);
     }
   }
   int percent_len = (int)s21_strlen(percent);
   s21_strncat(str, percent, percent_len + 1);
   *ind = *ind + percent_len;
 */
  **p = '%';
  (*p)++;
}

void execute_n(int *var, int count) { *var = count; }

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

void process_d_spec(Flag flags, va_list args, char **p) {
  long int value;
  if (flags.length == 'l') {
    value = va_arg(args, long int);

  } else if (flags.length == 'h') {
    value = (short)va_arg(args, int);
  } else {
    value = va_arg(args, int);
  }

  // approximately 20 signs for the long int number (with sign) plus \0
  // plus precision, plus some margin
  int temp_size = 25 + ((flags.precision < 0) ? 0 : flags.precision);
  char temp[temp_size];
  s21_memset(temp, '\0', temp_size);
  int len = 0;
  if (flags.precision != 0 || value != 0) {
    len = int_to_str_min_len(value, temp, false, flags.precision);
  }
  char sign = '\0';
  if (flags.sign || value < 0) {
    len++;
    sign = (value < 0) ? '-' : '+';
  } else if (flags.space) {
    len++;
    sign = ' ';
  }

  if (flags.zero && sign != '\0') {
    **p = sign;
    (*p)++;
  }
  if (flags.width > len && !flags.minus) {
    s21_memset(*p, (flags.zero) ? '0' : ' ', flags.width - len);
    (*p) += flags.width - len;
  }

  if (!flags.zero && sign != '\0') {
    **p = sign;
    (*p)++;
  }

  s21_strncpy(*p, temp, temp_size);
  (*p) += len - ((sign == '\0') ? 0 : 1);
  if (flags.width > len && flags.minus) {
    s21_memset(*p, ' ', flags.width - len);
    (*p) += flags.width - len;
  }
}
