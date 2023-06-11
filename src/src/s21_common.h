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

void reverse_string(char *str);
void pos_int_to_string(long long unsigned int number, char *str, int base,
                       bool reg);
void double_to_string(long double number, char *buffer, Flag flags);
void pointer_to_string(void *ptr, char *buffer);
void input_char_left(char *str, char ch);
int int_to_str_min_len(long int number, char *str, int min_len);
int put_wchar(char **p, wchar_t wchar);
bool s21_isdigit(int a);
bool s21_isspace(int c);
int char_to_digit(char c, int base);
bool str_to_int(const char **str, long long *value, s21_size_t width, int base);
bool str_to_uint(const char **str, unsigned long long *value, s21_size_t width,
                 int base);
bool str_to_float(const char **str, long double *value, s21_size_t width);
bool parse_pre_number(s21_size_t *count, int *sign, s21_size_t width, int *base,
                      const char **str);
bool possible_nan_inf(char c);
bool get_nan_inf(const char **str, s21_size_t width, s21_size_t count, int sign,
                 long double *value);
bool str_to_float_overflow(const char **str, long double *value,
                           s21_size_t width, s21_size_t *count, int *sign,
                           int base);
