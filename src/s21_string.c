#include "s21_string.h"
#include "s21_errno.h"

void *s21_memchr(const void *str, int c, s21_size_t n) {
/* Выполняет поиск первого вхождения символа c (беззнаковый тип) в первых n байтах строки, на которую указывает аргумент str.*/
    const unsigned char *p = str;
    for (s21_size_t i = 0; i < n; i++) {
        if (p[i] == c) {
            return (void *)&p[i];
        }
    }
    return S21_NULL;
}

int s21_memcmp(const void *str1, const void *str2, s21_size_t n) {
/* Сравнивает первые n байтов str1 и str2 */
    const unsigned char* p1 = str1;
    const unsigned char* p2 = str2;
    int res = 0;
    for (s21_size_t i = 0; i < n; ++i) {
        if (p1[i] < p2[i]) {
            res = -1;
        } else if (p1[i] > p2[i]) {
            res = 1;
        }
    }
    return res;
}

void *s21_memcpy(void *dest, const void *src, s21_size_t n) {
/* Копирует n символов из src в dest*/
    char *dest_ptr = dest;
    const char *src_ptr = src;

    for (s21_size_t i = 0; i < n; i++) {
        dest_ptr[i] = src_ptr[i];
    }
    return dest;
}

void *s21_memset(void *str, int c, s21_size_t n) {
/* Копирует символ c (беззнаковый тип) в первые n символов строки, на которую указывает аргумент str*/
    unsigned char *p = str;
    while(n--) {
        *p++ = (unsigned char)c;
    }
    return str;
}

s21_size_t s21_strlen(const char* text) {
/* Вычисляет длину строки str, не включая завершающий нулевой символ */
    s21_size_t len = 0;
    while (*text != '\0') {
        len++;
        text++;
    }
    return len;
}

char *s21_strncat(char *dest, const char *src, s21_size_t n) {
/* Добавляет строку, на которую указывает src, в конец строки, на которую указывает dest, длиной до n символов*/
    char* p = dest;
    while (*p != '\0') {  // находим конец строки-назначения
        p++;
    }
    s21_size_t i = 0;
    while (src[i] != '\0' && i < n) {  // копируем символы из строки-источника в строку-назначение
        p[i] = src[i];
        i++;
    }
    p[i] = '\0';  // устанавливаем конец строки-назначения
    return dest;
}

char *s21_strcat(char *dest, const char *src) {
    return s21_strncat(dest, src, SIZE_MAX);
}

char *s21_strchr(const char* str, int c) {
/* Выполняет поиск первого вхождения символа c (беззнаковый тип) в строке, на которую указывает аргумент str*/
    while (*str != '\0') {
        if (*str == c) {
            return (char*)str;
        }
        str++;
    }
    if (*str == c) {
        return (char*)str;
    }
    return S21_NULL;
}

int s21_strncmp(const char* s1, const char* s2, s21_size_t n) {
/* Сравнивает не более первых n байтов str1 и str2 */
    for (s21_size_t i = 0; i < n; i++) {
        if (s1[i] != s2[i]) {
            return s1[i] - s2[i];
        }
        if (s1[i] == '\0') { // Если достигнут конец первой строки
            return 0;
        }
    }
    return 0;
}

int s21_strcmp(const char* s1, const char* s2) {
    return s21_strncmp(s1, s2, SIZE_MAX); // без ограничения длины
}

char* s21_strncpy(char* dest, const char* src, s21_size_t n) {
/* Копирует до n символов из строки, на которую указывает src, в dest */
    s21_size_t i;
    for (i = 0; i < n && src[i] != '\0'; i++) {
        dest[i] = src[i];
    }
    for ( ; i < n; i++) { // заполнение /0 до указанной длины
        dest[i] = '\0';
    }
    return dest;
}

char *s21_strcpy(char* dest, const char* src) {
   return s21_strncpy(dest, src, SIZE_MAX); 
}

s21_size_t s21_strspn(const char *str1, const char *str2) {
/* Вычисляет длину начального сегмента str1, который полностью состоит из символов, не входящих в str2*/
      size_t i, j;

  // Проверяем каждый символ в строке s до тех пор, пока не найдем символ, 
  // который не принадлежит набору символов accept или не достигнем конца строки s
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

s21_size_t s21_strcspn(const char *str1, const char *str2) {
/* Вычисляет длину начального сегмента str1, который полностью состоит из символов, не входящих в str2*/
    s21_size_t i, j;
    for (i = 0; str1[i] != '\0'; i++) {
        for (j = 0; str2[j] != '\0'; j++) {
            if (str1[i] == str2[j]) {
                break;
            }
        }
        if (str2[j] == '\0') {
            return i;
        }
    }
    return i;
    }

char *s21_strerror(int errnum) {
/* Выполняет поиск во внутреннем массиве номера ошибки errnum и возвращает указатель на строку с сообщением об ошибке. Нужно объявить макросы, содержащие массивы сообщений об ошибке для операционных систем mac и linux. Описания ошибок есть в оригинальной библиотеке. Проверка текущей ОС осуществляется с помощью директив */
      switch(errnum) {

#ifdef __linux__
        case S21_EPERM:
            return "Operation not permitted";
        case S21_ENOENT:
            return "No such file or directory";
        case S21_ESRCH:
            return "No such process";
        case S21_EINTR:
            return "Interrupted system call";
        case S21_EIO:
            return "I/O error";
        case S21_ENXIO:
            return "No such device or address";
        case S21_E2BIG:
            return "Argument list too long";
        case S21_ENOEXEC:
            return "Exec format error";
        case S21_EBADF:
            return "Bad file descriptor";
        case S21_ECHILD:
            return "No child processes";
        // и так далее для остальных возможных ошибок
#endif /* __linux__ */

#ifdef __APPLE__
        case S21_EPERM:
            return "Operation not permitted";
        case S21_ENOENT:
            return "No such file or directory";
        case S21_ESRCH:
            return "No such process";
        case S21_EINTR:
            return "Interrupted system call";
        case S21_EIO:
            return "I/O error";
        case S21_ENXIO:
            return "No such device or address";
        case S21_E2BIG:
            return "Argument list too long";
        case S21_ENOEXEC:
            return "Exec format error";
        case S21_EBADF:
            return "Bad file descriptor";
        case S21_ECHILD:
            return "No child processes";
        // и так далее для остальных возможных ошибок
#endif /* __APPLE__ */

        default:
            return "Unknown error";
    }  
}

char *s21_strstr(const char* haystack, const char* needle) {
/* Находит первое вхождение всей строки needle (не включая завершающий нулевой символ), которая появляется в строке haystack*/
    if (*needle == '\0') {
        return (char*)haystack;
    }

    const char *p1 = haystack;
    
    while (*p1 != '\0') {
        const char* p1_start = p1;
        const char* p2 = needle;
        while (*p1 != '\0' && *p2 != '\0' && *p1 == *p2) {
            p1++;
            p2++;
        }
        if (*p2 == '\0') {
            return (char*)p1_start;
        }
        p1 = p1_start + 1;
    }
    return S21_NULL;
}

char *s21_strpbrk(const char *str1, const char *str2) {
/* Находит первый символ в строке str1, который соответствует любому символу, указанному в str2 */
    while (*str1 != '\0') {    // Перебираем все символы строки s
        const char* a = str2;
        while (*a != '\0') {    // Перебираем все символы строки accept
            if (*str1 == *a) {    // Если символ из строки s равен символу из строки accept
                return (char*)str1;    // Возвращаем указатель на найденный символ в строке s
            }
            a++;
        }
        str1++;
    }
    return S21_NULL;    // Символы из строки accept не найдены в строке s
}

char *s21_strrchr(const char *str, int c) {
/* Выполняет поиск последнего вхождения символа c (беззнаковый тип) в строке, на которую указывает аргумент str*/
    char *last = S21_NULL;
    while (*str) {
        if (*str == c) {
            last = (char *)str;
        }
        str++;
    }
    if (*str == c) {
        last = (char *)str;
    }
    return last;
}

char *s21_strtok(char *str, const char *delim) {
/* Разбивает строку str на ряд токенов, разделенных delim */
    static char* saveptr = S21_NULL; // сохраняет состояние между вызовами функции

    if (str != S21_NULL) { // если указатель на строку не равен NULL
        saveptr = str; // обновляем указатель на начало строки
    } else {
        if (saveptr == S21_NULL) { // если строка закончилась и нет сохраненного указателя
            return S21_NULL; // возвращаем NULL
        }
        str = saveptr; // начинаем обработку той же строки, с которой закончили
    }

    str += s21_strspn(str, delim); // пропускаем символы-разделители

    if (*str == '\0') { // если строка закончилась
        saveptr = S21_NULL; // обнуляем указатель на следующий токен
        return S21_NULL; // возвращаем NULL
    }

    char* end = str + s21_strcspn(str, delim); // находим конец текущего токена
    if (*end == '\0') { // если строка закончилась
        saveptr = S21_NULL; // обнуляем указатель на следующий токен
    } else {
        *end = '\0'; // ставим символ конца строки в конец текущего токена
        saveptr = end + 1; // обновляем указатель на начало следующего токена
    }

    return str; // возвращаем указатель на текущий токен
}

int main(){
    
}