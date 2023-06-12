#include "../s21_string.h"
#include "s21_common.h"

void parse_sprintf_spec(const char **p, Flag *flags, va_list *args);
void apply_flags(char *str, Flag flags);
void double_to_exp(char *buffer, long double number, Flag flags);

void execute_x(char **p, va_list *args, Flag flags);
void execute_u(char **p, va_list *args, Flag flags);
void execute_percent(char **str);
void execute_o(char **p, va_list *args, Flag flags);
void execute_n(int *var, int count);
void execute_p(char **p, va_list *args, Flag flags);
void process_d_spec(Flag flags, va_list *args, char **p);
void apply_flags(char *str, Flag flags);
int process_c_spec(Flag flags, va_list *args, char **p);
int process_s_spec(Flag flags, va_list *args, char **p);
void execute_f(char **p, va_list *args, Flag flags);
void execute_e(char **p, va_list *args, Flag flags);
void execute_g(char **p, va_list *args, Flag flags);

int s21_sprintf(char *str, const char *format, ...) {
  va_list args;
  va_start(args, format);
  char *str_p = str;
  bool is_spec = false;
  // compensation value for len with wide chars
  int wchar_comp = 0;

  for (const char *p = format; *p != '\0'; ++p) {
    Flag flags = {0};  // ининциализируем или обнуляем структуру флагов
    if (is_spec) {
      is_spec = false;
      /* парсинг спецификатора */
      parse_sprintf_spec(&p, &flags, &args);

      // обработка спецификатора и аргумента
      switch (flags.spec) {
        case '%':
          execute_percent(&str_p);
          break;
        case 'f':
          execute_f(&str_p, &args, flags);
          break;
        case 'e':
        case 'E':
          execute_e(&str_p, &args, flags);
          break;
        case 'g':
        case 'G':
          execute_g(&str_p, &args, flags);
          break;
        case 'n':
          execute_n(va_arg(args, int *), (str_p - str));
          break;
        case 'u':
          execute_u(&str_p, &args, flags);
          break;
        case 'o':
          execute_o(&str_p, &args, flags);
          break;
        case 'x':
        case 'X':
          execute_x(&str_p, &args, flags);
          break;
        case 'p':
          execute_p(&str_p, &args, flags);
          break;
        case 'd':
        case 'i':
          process_d_spec(flags, &args, &str_p);
          break;
        case 'c':
          wchar_comp += process_c_spec(flags, &args, &str_p);
          break;
        case 's':
          wchar_comp += process_s_spec(flags, &args, &str_p);
          break;
      }
    } else if (*p == '%') {
      is_spec = true;
    } else {
      // вывод результата в строку
      *str_p++ = *p;
    }
  }
  *str_p = '\0';  // Добавляем нулевой символ в конце строки

  va_end(args);  // Завершаем работу с переменными аргументами

  return str_p - str - wchar_comp;
}

void parse_sprintf_spec(const char **p, Flag *flags, va_list *args) {
  // первоначальное значение -1, т.к. 0 - валидное значение
  flags->precision = -1;

  // парсим флаги
  while (**p != '\0') {
    if (**p == '-') {
      flags->minus = 1;
    } else if (**p == '+') {
      flags->sign = 1;
    } else if (**p == ' ') {
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
  if (s21_isdigit(**p)) {
    while (s21_isdigit(**p)) {
      flags->width = flags->width * 10 + (**p - '0');
      (*p)++;
    }
  } else if (**p == '*') {
    flags->width = va_arg(*args, int);  // значение для считывание из аргумента
    (*p)++;
  }

  // парсим точность
  if (**p == '.') {
    (*p)++;
    flags->precision = 0;
    if (s21_isdigit(**p)) {
      while (s21_isdigit(**p)) {
        flags->precision = flags->precision * 10 + (**p - '0');
        (*p)++;
      }
    } else if (**p == '*') {
      flags->precision =
          va_arg(*args, int);  // значение для считывание из аргумента
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
  }

  // to not go over the format string
  if (**p == '\0') (*p)--;
}

void execute_x(char **p, va_list *args, Flag flags) {
  char hex[50];

  unsigned long int number;
  // обрабатываем длину
  if (flags.length == 'l') {
    number = va_arg(*args, unsigned long int);
  } else if (flags.length == 'h') {
    number = (unsigned short int)va_arg(*args, int);
  } else {
    number = (unsigned int)va_arg(*args, int);
  }

  // переводим в 16ый формат и записываем в строку
  if (flags.spec == 'x') pos_int_to_string(number, hex, 16, false);
  if (flags.spec == 'X') pos_int_to_string(number, hex, 16, true);

  apply_flags(hex, flags);

  int hex_len = (int)s21_strlen(hex);
  s21_strncpy(*p, hex, hex_len);
  (*p) += hex_len;
}

void execute_percent(char **p) {
  **p = '%';
  (*p)++;
}

void execute_n(int *var, int count) { *var = count; }

void process_d_spec(Flag flags, va_list *args, char **p) {
  long int value;
  if (flags.length == 'l') {
    value = va_arg(*args, long int);

  } else if (flags.length == 'h') {
    value = (short)va_arg(*args, int);
  } else {
    value = va_arg(*args, int);
  }

  // approximately 20 signs for the long int number (with sign) plus \0
  // plus precision, plus some margin
  int temp_size = 25 + ((flags.precision < 0) ? 0 : flags.precision);
  char temp[temp_size];
  s21_memset(temp, '\0', temp_size);
  int len = 0;
  if (flags.precision != 0 || value != 0) {
    len = int_to_str_min_len(value, temp, flags.precision);
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

void apply_flags(char *str, Flag flags) {
  // обработка +
  if (flags.sign && str[0] != '-' &&
      (flags.spec == 'f' || flags.spec == 'e' || flags.spec == 'E' ||
       flags.spec == 'g' || flags.spec == 'G')) {
    input_char_left(str, '+');
  }

  if (!flags.sign && str[0] != '-' && flags.space &&
      (flags.spec == 'f' || flags.spec == 'e' || flags.spec == 'E' ||
       flags.spec == 'g' || flags.spec == 'G')) {
    input_char_left(str, ' ');
  }

  // точность для не десятичных
  if (flags.precision != -1 && flags.spec != 'f' && flags.spec != 'g' &&
      flags.spec != 'G') {  // точность, дополняем нулями слева

    if (flags.precision == 0 && !s21_strncmp(str, "0", 1)) {
      str[0] = '\0';
    } else {
      int for_prefix = 0;

      if (flags.prefix &&
          flags.spec == 'o') {  // у восьмеричных ведущий ноль играет в точности
        for_prefix = 1;
      }
      while ((int)s21_strlen(str) < flags.precision - for_prefix) {
        input_char_left(str, '0');
      }
    }
  }

  // обработка #
  if ((flags.prefix && s21_strncmp(str, "0", 2) && str[0] != '\0') ||
      flags.spec == 'p') {  // флаг #
    if (flags.spec == 'x' || flags.spec == 'p') {
      input_char_left(str, 'x');
      input_char_left(str, '0');
      if (!flags.sign && flags.space) input_char_left(str, ' ');
      if (flags.sign) input_char_left(str, '+');
    }
    if (flags.spec == 'X') {
      input_char_left(str, 'X');
      input_char_left(str, '0');
      if (!flags.sign && flags.space) input_char_left(str, ' ');
      if (flags.sign) input_char_left(str, '+');
    }
    if (flags.spec == 'o') {
      input_char_left(str, '0');
    }
    if ((flags.spec == 'f') && !s21_strchr(str, '.')) {
      int len = s21_strlen(str);
      str[len] = '.';
      str[len + 1] = '\0';
    }

    if ((flags.spec == 'E' || flags.spec == 'e' || flags.spec == 'G' ||
         flags.spec == 'g') &&
        !s21_strchr(str, '.')) {
      char *position = {0};
      if (flags.spec == 'e' || flags.spec == 'g')
        position = s21_strchr(str, 'e');
      if (flags.spec == 'E' || flags.spec == 'G')
        position = s21_strchr(str, 'E');

      if (position != S21_NULL) {
        int index = position - str;  // Вычисляем индекс первого вхождения
        int len = (int)s21_strlen(str);

        for (int i = len; i > index; i--) {
          str[i] = str[i - 1];  // Сдвигаем символы вправо на 1 позицию
        }

        str[index] = '.';  // Вставляем точку перед первым вхождением
      }
    }
  }

  if (flags.width != 0 && !flags.minus) {
    char ch = ' ';
    if (flags.zero) ch = '0';
    while ((int)s21_strlen(str) < flags.width) {
      input_char_left(str, ch);
    }

  } else if (flags.width != 0 && flags.minus) {
    while ((int)s21_strlen(str) < flags.width) {
      int len = (int)s21_strlen(str);
      str[len] = ' ';
      str[len + 1] = '\0';
    }
  }

  // костыль для префикса у десятичных
  char search_chars[] = {'-', '+', ' '};
  int i = 0;

  if (str[0] == '0' &&
      (flags.spec == 'f' || flags.spec == 'E' || flags.spec == 'e' ||
       flags.spec == 'G' || flags.spec == 'g')) {
    while (str[i] != '\0' && str[i] != 'E' && str[i] != 'e') {
      for (int j = 0; j < 3; j++) {
        if (str[i] == search_chars[j]) {
          char temp = str[i];
          str[i] = str[0];
          str[0] = temp;
        }
      }
      i++;
    }
  }
}

void execute_u(char **p, va_list *args, Flag flags) {
  char udigit[50];

  long unsigned int number;
  // обрабатываем длину
  if (flags.length == 'l') {
    number = va_arg(*args, long unsigned int);
  } else if (flags.length == 'h') {
    number = (unsigned short int)va_arg(*args, int);
  } else {
    number = (unsigned int)va_arg(*args, int);
  }

  // переводим в 10ый формат и записываем в строку
  pos_int_to_string(number, udigit, 10, false);

  apply_flags(udigit, flags);

  int udigit_len = (int)s21_strlen(udigit);
  s21_strncpy(*p, udigit, udigit_len);
  (*p) += udigit_len;
}

void execute_o(char **p, va_list *args, Flag flags) {
  char udigit[50];

  long unsigned int number;
  // обрабатываем длину
  if (flags.length == 'l') {
    number = va_arg(*args, long unsigned int);
  } else if (flags.length == 'h') {
    number = (unsigned short int)va_arg(*args, int);
  } else {
    number = (unsigned int)va_arg(*args, int);
  }

  // переводим в 8ый формат и записываем в строку
  pos_int_to_string(number, udigit, 8, false);

  apply_flags(udigit, flags);

  int udigit_len = (int)s21_strlen(udigit);
  s21_strncpy(*p, udigit, udigit_len);
  (*p) += udigit_len;
}

int process_c_spec(Flag flags, va_list *args, char **p) {
  int len = 1;
  int res = 0;
  if (flags.width > len && !flags.minus) {
    s21_memset(*p, ' ', flags.width - len);
    (*p) += flags.width - len;
  }

  if (flags.length == 'l') {
    wchar_t wide_char = (wchar_t)va_arg(*args, int);
    res = put_wchar(p, wide_char);
  } else {
    char c = va_arg(*args, int);
    **p = c;
    (*p)++;
  }

  if (flags.width > len && flags.minus) {
    s21_memset(*p, ' ', flags.width - len);
    (*p) += flags.width - len;
  }
  return res;
}

int process_s_spec(Flag flags, va_list *args, char **p) {
  s21_size_t len = 0;
  s21_size_t width = (s21_size_t)flags.width;
  s21_size_t precision =
      (flags.precision < 0) ? 0 : (s21_size_t)flags.precision;
  bool wchar = (flags.length == 'l') ? true : false;
  bool null_line = false;
  int res = 0;

  wchar_t *wline = S21_NULL;
  const char *line = S21_NULL;

  if (wchar) {
    wline = va_arg(*args, wchar_t *);
    if (wline == S21_NULL) {
      wline = L"(null)";
      null_line = true;
    }
    len = wcslen(wline);
  } else {
    line = va_arg(*args, const char *);
    if (line == S21_NULL) {
      line = "(null)";
      null_line = true;
    }
    len = s21_strlen(line);
  }

  if (flags.precision >= 0 && precision < len) {
    len = (null_line) ? 0 : precision;
  }

  if (width > len && !flags.minus) {
    s21_memset(*p, ' ', width - len);
    (*p) += width - len;
  }

  if (wchar) {
    for (s21_size_t i = 0; i < len; i++) {
      res += put_wchar(p, wline[i]);
    }
  } else {
    s21_strncpy(*p, line, len);
    (*p) += len;
  }

  if (width > len && flags.minus) {
    s21_memset(*p, ' ', width - len);
    (*p) += width - len;
  }
  return res;
}

void execute_p(char **p, va_list *args, Flag flags) {
  char buffer[50];
  void *ptr = va_arg(*args, void *);
#ifdef __linux__

#elif __APPLE__

#endif
  // переводим указатель в строку
  pointer_to_string(ptr, buffer);

  // дополняем флагами и префиксом
  apply_flags(buffer, flags);

#ifdef __linux__
  if (ptr == 0) {
    s21_strncpy(buffer, "(nil)", 5);
    buffer[5] = '\0';
    if (flags.width != 0 && !flags.minus) {
      char ch = ' ';
      if (flags.zero) ch = '0';
      while ((int)s21_strlen(buffer) < flags.width) {
        input_char_left(buffer, ch);
      }

    } else if (flags.width != 0 && flags.minus) {
      while ((int)s21_strlen(buffer) < flags.width) {
        int len = (int)s21_strlen(buffer);
        buffer[len] = ' ';
        buffer[len + 1] = '\0';
      }
    }
  }

#endif

  int buffer_len = (int)s21_strlen(buffer);
  s21_strncpy(*p, buffer, buffer_len);
  (*p) += buffer_len;
}

void execute_f(char **p, va_list *args, Flag flags) {
  long double number;
  char buffer[200] = {0};

  // обработка длины
  if (flags.length == 'L') {
    number = va_arg(*args, long double);
  } else {
    number = va_arg(*args, double);
  }
  if (isnan(number)) {
    s21_strncpy(buffer, "nan", 3);
  } else if (isinf(number) > 0) {
    s21_strncpy(buffer, "inf", 3);
  } else if (isinf(number) < 0) {
    s21_strncpy(buffer, "-inf", 4);
  } else {
    // устанавливаем точность
    if (flags.precision == -1) flags.precision = 6;

    // преобразуем число в строку с заданной точностью
    double_to_string(number, buffer, flags);
  }

  apply_flags(buffer, flags);

  int buffer_len = (int)s21_strlen(buffer);
  s21_strncpy(*p, buffer, buffer_len);
  (*p) += buffer_len;
}

void execute_e(char **p, va_list *args, Flag flags) {
  long double number;
  char buffer[200] = {0};

  // обработка длины
  if (flags.length == 'L') {
    number = va_arg(*args, long double);
  } else {
    number = va_arg(*args, double);
  }
  if (isnan(number)) {
    s21_strncpy(buffer, "nan", 3);
  } else if (isinf(number) > 0) {
    s21_strncpy(buffer, "inf", 3);
  } else if (isinf(number) < 0) {
    s21_strncpy(buffer, "-inf", 4);
  } else {
    // приводим к экспоненциальному формату
    double_to_exp(buffer, number, flags);
  }
  // применяем флаги
  apply_flags(buffer, flags);

  // записываем результат в основную строку
  int buffer_len = (int)s21_strlen(buffer);
  s21_strncpy(*p, buffer, buffer_len);
  (*p) += buffer_len;
}

void execute_g(char **p, va_list *args, Flag flags) {
  char buffer[200] = {0};
  long double number;

  // обработка длины
  if (flags.length == 'L') {
    number = va_arg(*args, long double);
  } else {
    number = va_arg(*args, double);
  }

  if (isnan(number)) {
    s21_strncpy(buffer, "nan", 3);
  } else if (isinf(number) > 0) {
    s21_strncpy(buffer, "inf", 3);
  } else if (isinf(number) < 0) {
    s21_strncpy(buffer, "-inf", 4);
  } else if (number == 0.0) {
    buffer[0] = '0';
    buffer[1] = '\0';
  } else {
    // определяем вывод
    int q = 0;
    if (flags.precision == -1)
      q = 6;
    else if (flags.precision == 0)
      q = 1;
    else
      q = flags.precision;
    long double temp = number;
    int exp_count = 0;
    while (fabsl(temp) < 1.0) {
      temp *= 10;
      exp_count--;
    }
    while (fabsl(roundl((temp * pow(10, flags.precision)) /
                        pow(10, flags.precision))) >= 10.0) {
      temp = temp / 10;
      exp_count++;
    }

    // делаем самый сложный выбор в жизни
    if (q > exp_count && exp_count >= -4) {
      flags.precision = q - (exp_count + 1);
      double_to_string(number, buffer, flags);
    } else {
      flags.precision = q - 1;
      double_to_exp(buffer, number, flags);
    }
  }

  // применяем флаги
  apply_flags(buffer, flags);

  // записываем результат в основную строку
  int buffer_len = (int)s21_strlen(buffer);
  s21_strncpy(*p, buffer, buffer_len);
  (*p) += buffer_len;
}

void double_to_exp(char *buffer, long double number, Flag flags) {
  // устанавливаем точность
  if (flags.precision == -1) flags.precision = 6;

  // приводим разрядность к экспоненциальной форме и фиксируем смещение
  int exp_count = 0;
  while (fabsl(number) < 1.0) {
    number *= 10;
    exp_count--;
  }

  while (fabsl(roundl((number * pow(10, flags.precision)) /
                      pow(10, flags.precision))) >= 10.0) {
    number = number / 10;
    exp_count++;
  }

  // преобразуем число в строку с заданной точностью
  double_to_string(number, buffer, flags);

  // преобразуем коэффициент в строку
  char exp_count_string[20] = {0};
  char sign = '+';
  if (exp_count < 0) sign = '-';
  pos_int_to_string(abs(exp_count), exp_count_string, 10, false);
  if ((int)s21_strlen(exp_count_string) < 2) {
    input_char_left(exp_count_string, '0');
  }
  input_char_left(exp_count_string, sign);

  // собираем строку
  char exp_char = {0};
  if (flags.spec == 'e' || flags.spec == 'g') exp_char = 'e';
  if (flags.spec == 'E' || flags.spec == 'G') exp_char = 'E';

  int i = s21_strlen(buffer);
  buffer[i] = exp_char;
  buffer[i + 1] = '\0';
  s21_strncat(buffer, exp_count_string, sizeof(exp_count_string));
}