#include <stdarg.h>
#include <string.h>
#include <stdbool.h>
#include "../s21_string.h"


typedef struct {
    int minus;
    int sign;
    int space;
    int prefix;
    int zero;
    int width;
    int precision;
    char spec;
} Flag;

int s21_sprintf(char *str, const char *format, ...);
void parse_spec(const char *format, int *ind, Flag *flags);



int main() {
    char str1[100], str2[100]; 
    //sprintf(str1, "hello friend");
    s21_sprintf(str2, "hello%-2f friend %+-2.3d");
    //printf("Строка:%s\nДлина:%d\nСтрока:%s\nДлина:%d\n", str1, (int)strlen(str1), str2, (int)strlen(str2));
}

int s21_sprintf(char *str, const char *format, ...){

    va_list args;
    va_start(args, format);
    int f_ind = 0; // переменная для отслеживания форматной строки
    int s_ind = 0; // переменная для отслеживания строки вывода

    while (format[f_ind] != '\0') {
        Flag flags = {0}; // ининциализируем или обнуляем структуру флагов
        if (format[f_ind] == '%') {
            /* парсинг спецификатора */
            parse_spec(format, &f_ind, &flags);

            // тестовый вывод напарсенных структур
            printf("minus = %d, sign = %d, space = %d, prefix = %d, zero = %d, width = %d, precison = %d, spec = %c\n", flags.minus, flags.sign, flags.space, flags.prefix, flags.zero, flags.width, flags.precision, flags.spec);
            
            //обработка спецификатора и аргумента
            //вывод результата в строку
        } else {
            str[s_ind] = format[f_ind];
        }
        f_ind++;
        s_ind++; 
    }
    str[s_ind] = '\0'; // Добавляем нулевой символ в конце строки

    va_end(args); // Завершаем работу с переменными аргументами

    return s_ind;
}

void parse_spec(const char *format, int *ind, Flag *flags) {
    // парсим флаги
    (*ind)++;
    while(true) {
        if (format[*ind] == '-') {
            flags->minus = 1;
        } else if (format[*ind] == '+') {
            flags->sign = 1;
        } else if (format[*ind] == ' ') {
            flags->space = 1;
        } else if (format[*ind] == '#') {
            flags->prefix = 1;
        } else if (format[*ind] == '0') {
            flags->zero = 1;
        } else {
            break;
        }
        (*ind)++;        
    }
    // парсим ширину
    if (format[*ind] >= '1' && format[*ind] <= '9') {
        while (format[*ind] >= '0' && format[*ind] <= '9') {
            flags->width = flags->width * 10 + (format[*ind] - '0');
            (*ind)++;
        }
    }
    // парсим точность
    if (format[*ind] == '.') {
        (*ind)++;
        if (format[*ind] >= '1' && format[*ind] <= '9') {
            while (format[*ind] >= '0' && format[*ind] <= '9') {
                flags->precision = flags->precision * 10 + (format[*ind] - '0');
                (*ind)++;
            }
        }
    }
    // Парсим спецификатор
    switch (format[*ind]) {
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
            flags->spec = format[*ind];
            break;
        default:
            printf("Ошибка: Некорректный спецификатор %c\n", format[*ind]);
            exit(0); // что делаем если некорр. спец?
            break;
    }
}