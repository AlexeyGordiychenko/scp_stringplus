#include "../s21_string.h"
#include "s21_common.h"

typedef struct {
  int width;
  int asterisk;
  char length;
  char spec;
} Flag;

void parse_spec(const char **p, Flag *flags);

int s21_sscanf(const char *str, const char *format, ...) {
  va_list args;
  va_start(args, format);
  const char *str_p = str;

  for (const char *p = format; *p != '\0'; ++p) {
    Flag flags = {0};  // ининциализируем или обнуляем структуру флагов
    if (*p == '%') {
      /* парсинг спецификатора */
      parse_spec(&p, &flags);

      // тестовый вывод напарсенных структур
      printf("width = %d, asterisk = %d, length = %c, spec = %c\n", flags.width,
             flags.asterisk, flags.length, flags.spec);
    } else {
      if (*format != *str_p) {
        printf("-=does not match=-");
        break;
      }
      str_p++;
    }
  }

  va_end(args);  // Завершаем работу с переменными аргументами

  //   return str_p - str;
  return 0;
}

void parse_spec(const char **p, Flag *flags) {
  // парсим флаги
  (*p)++;

  if (**p == '*') {
    flags->asterisk = 1;
    (*p)++;
  }
  while (s21_isdigit(**p)) {
    flags->width = flags->width * 10 + (**p - '0');
    (*p)++;
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
      break;
    default:
      printf("Ошибка: Некорректный спецификатор %c\n", **p);
      // exit(0);  // что делаем если некорр. спец?
      break;
  }
}