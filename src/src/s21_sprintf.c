#include <math.h>
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
    char length;
    char spec;
} Flag;

int s21_sprintf(char *str, const char *format, ...);
void parse_spec(const char *format, int *ind, Flag *flags);
void execute_percent(char *str, int *ind);
void execute_n(int *ind, int *count);
void reverse_string(char *str);
void int_to_string(int number, char *str);
void double_to_string(double number, char *str, int precision);
void string_to_int(char *str, int *number);
void string_to_double(char *str, double *number);



int main() {
    char str1[] = "23.32", str2[] = "-34.98", str3[] = "Privet"; 
    //printf("just test");
    //sprintf(str1, "hello friend");
    double x;
    double y;
    string_to_double(str1, &x);
    printf("x в текст получилось: %f\n", x);
    string_to_double(str2, &y);
    printf("y в текст получилось: %f\n", y);
    reverse_string(str3);
    printf("Перевернутая строка: %s\n", str3);
    //s21_sprintf(str2, "he%%llo%n friend", &x);
    //printf("Строка:%s\nДлина:%d\nСтрока:%s\nДлина:%d\n", str1, (int)strlen(str1), str2, (int)strlen(str2));
    //printf("x = %d, %p", x, &x);
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
            switch (flags.spec) {
                case '%':
                    execute_percent(str, &s_ind);
                    break;
                case 'n':
                    execute_n(&s_ind, va_arg(args, int *)); 
                    break;
            }
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
        } else if (format[*ind] == ' ' && !flags->sign) {
            flags->space = 1;
        } else if (format[*ind] == '#') {
            flags->prefix = 1;
        } else if (format[*ind] == '0' && !flags->minus) {
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
    } else if (format[*ind] == '*') {
        flags->width = -1; // значение для считывание из аргумента
        (*ind)++;
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
    } else if (format[*ind] == '*') {
        flags->precision = -1; // значение для считывание из аргумента
        (*ind)++;
    }

    // Парсим длину
    switch (format[*ind]) {
        case 'h':
        case 'l':
        case 'L':        
            flags->length = format[*ind];
            (*ind)++;
            break;
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

void reverse_string(char *str) {
    int len = strlen(str);
    for(int k = 0; k < len / 2; k++) {
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
    int len = strlen(str);
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

void execute_percent(char *str, int *ind){
    str[*ind] = '%';
}

void execute_n(int *ind, int *count) {
    *count = *ind;
    (*ind)--;
}

void string_to_int(char *str, int *number) {
    // проверка на то является ли строка целым числом
    int i = 0;
    char sign;
    if (str[i] == '-') {
        sign = '-';
        i++;
    } 
    while(str[i] != '\0') {
        if (str[i] >= '1' && str[i] <= '9' ) {
            i++;
            continue;
        }
        else {
            printf("строка не является целым числом\n");
            return;
        } 
    }

    // преобразование в число
    i = (sign == '-') ? 1 : 0; // устанавиливаем позицию для счетчика
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

    while(str[i] != '\0') {
        if (str[i] >= '1' && str[i] <= '9' ) {
            i++;
            continue;
        } else if (str[i] == '.'&& !point) {
            point = 1;
            i++;
        } else {
            printf("строка не является вещественным числом\n");
            return;
        } 
    }
    // преобразовываем в число
    char *int_part, *dec_part;
    int_part = strtok(str, ".");
    dec_part = strtok(NULL, ".");
    int x,y, len_dec = (int)strlen(dec_part);
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
