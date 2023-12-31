#include "../scp_string.h"

char *scp_strpbrk(const char *str1, const char *str2) {
  /* Находит первый символ в строке str1, который соответствует любому символу,
   * указанному в str2 */
  while (*str1 != '\0') {  // Перебираем все символы строки s
    const char *a = str2;
    while (*a != '\0') {  // Перебираем все символы строки accept
      if (*str1 ==
          *a) {  // Если символ из строки s равен символу из строки accept
        return (
            char *)str1;  // Возвращаем указатель на найденный символ в строке s
      }
      a++;
    }
    str1++;
  }
  return SCP_NULL;  // Символы из строки accept не найдены в строке s
}