#include "../s21_string.h"

s21_size_t s21_strspn(const char *str1, const char *str2) {
  /* Вычисляет длину начального сегмента str1, который полностью состоит из
   * символов, не входящих в str2*/
<<<<<<< HEAD
  size_t i, j;
=======
  s21_size_t i, j;
>>>>>>> 59c3dac97c6954adb6728af20080dc1213f5a670

  // Проверяем каждый символ в строке s до тех пор, пока не найдем символ,
  // который не принадлежит набору символов accept или не достигнем конца строки
  // s
  for (i = 0; str1[i] != '\0'; i++) {
    for (j = 0; str2[j] != '\0'; j++) {
      if (str1[i] == str2[j]) {
        break;
      }
    }
    if (str2[j] == '\0') {
      // Если s[i] не принадлежит набору символов accept,
      // возвращаем количество найденных символов
      return i;
    }
  }

  // Если все символы в строке s принадлежат набору символов accept,
  // возвращаем длину строки s
  return i;
}
