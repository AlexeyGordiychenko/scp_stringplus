#include "../s21_string.h"

void reverse_string(char *str);
void pos_int_to_string(long long unsigned int number, char *str);
int int_to_str_min_len(long int number, char *str, bool sign, int min_len);
void double_to_string(double number, char *str, int precision);
void string_to_int(char *str, int *number);
void string_to_double(char *str, double *number);
void int_to_hex(unsigned long int number, char *hex, int reg);
void input_char_left(char *str, char ch);
void pos_int_to_string_octal(long long unsigned int number, char *str);
int put_wchar(char **p, wchar_t wchar);
bool s21_isdigit(int a);
bool s21_isspace(int c);