#include "s21_string.h"

#include <stdio.h>
#include <stdlib.h>

void s21_strlen_test();
void s21_strcmp_test();
void s21_strcpy_test();
void s21_strcat_test();
void s21_strchr_test();
void s21_strstr_test();
void s21_strtok_test();

int main() {
#ifdef FLAG1
    s21_strlen_test();
#elif FLAG2
    s21_strcmp_test();
#elif FLAG3
    s21_strcpy_test();
#elif FLAG4
    s21_strcat_test();
#elif FLAG5
    s21_strchr_test();
#elif FLAG6
    s21_strstr_test();
#elif FLAG7
    s21_strtok_test();
#endif
    return 0;

    // проверка количества аргументов и их содержимого
    /*   if (argc != 2) {
           printf("Использовано: %s аргумента\n", argv[0]);
           return 1;
       }

       int test_number = atoi(argv[1]); // преобразуем строку в число

       switch (test_number) {
           case 1:
               s21_strlen_test();
               break;
           case 2:
               s21_strcmp_test();
               break;
           case 3:
               s21_strcpy_test();
               break;
           case 4:
               s21_strcat_test();
               break;
           case 5:
               s21_strchr_test();
               break;
           case 6:
               s21_strstr_test();
               break;
           case 7:
               s21_strtok_test();
               break;
           default:
               printf("Неправильный номер теста\n");
               return 1;
       }

       return 0;
       */
}

void s21_strlen_test() {
    char* inputs[] = {"", "a", "abc", "Hello, world!", "1234567890"};
    int expected[] = {0, 1, 3, 13, 10};
    int num_tests = 5;
    int output;

    // проходим по каждому тесту
    for (int i = 0; i < num_tests; i++) {
        // вызываем функцию, которую тестируем
        output = s21_strlen(inputs[i]);

        // проверяем, соответствует ли выход функции ожидаемому значению
        if (output == expected[i]) {
            printf("Test %d: input=\"%s\", output=%d, expected=%d - SUCCESS\n", i + 1, inputs[i], output,
                   expected[i]);
        } else {
            printf("Test %d: input=\"%s\", output=%d, expected=%d - FAIL\n", i + 1, inputs[i], output,
                   expected[i]);
        }
    }
}

void s21_strcmp_test() {
    char* s1 = "Hello, world!";
    char* s2 = "Hello, world!";
    char* s3 = "Hello";
    char* s4 = "world";
    char* s5 = "Hell";
    char* s6 = "Hello, people!";

    printf("Test case 1:\nInput: s1 = \"%s\", s2 = \"%s\"\nOutput: %d\nExpected Output: 0\n", s1, s2,
           s21_strcmp(s1, s2));
    if (s21_strcmp(s1, s2) == 0) {
        printf("SUCCESS\n");
    } else {
        printf("FAIL\n");
    }

    printf("Test case 2:\nInput: s1 = \"%s\", s2 = \"%s\"\nOutput: %d\nExpected Output: 5\n", s3, s4,
           s21_strcmp(s3, s4));
    if (s21_strcmp(s3, s4) == 5) {
        printf("SUCCESS\n");
    } else {
        printf("FAIL\n");
    }

    printf("Test case 3:\nInput: s1 = \"%s\", s2 = \"%s\"\nOutput: %d\nExpected Output: -4\n", s4, s5,
           s21_strcmp(s4, s5));
    if (s21_strcmp(s4, s5) == -4) {
        printf("SUCCESS\n");
    } else {
        printf("FAIL\n");
    }

    printf("Test case 4:\nInput: s1 = \"%s\", s2 = \"%s\"\nOutput: %d\nExpected Output: 6\n", s1, s6,
           s21_strcmp(s1, s6));
    if (s21_strcmp(s1, s6) == 6) {
        printf("SUCCESS\n");
    } else {
        printf("FAIL\n");
    }
}

void s21_strcpy_test() {
    char input[5][20] = {{"Hello World!"}, {"Test string."}, {"Another string"}, {"A"}, {""}};

    char expected[5][20] = {{"Hello World!"}, {"Test string."}, {"Another string"}, {"A"}, {""}};

    char output[5][20];
    int i, test_count = 5, pass_count = 0;

    printf("s21_strcpy_test:\n");

    for (i = 0; i < test_count; i++) {
        s21_strcpy(output[i], input[i]);

        if (s21_strcmp(expected[i], output[i]) == 0) {
            printf("Input: %s\n", input[i]);
            printf("Expected: %s\n", expected[i]);
            printf("Output: %s\n", output[i]);
            printf("Result: SUCCESS\n\n");
            pass_count++;
        } else {
            printf("Input: %s\n", input[i]);
            printf("Expected: %s\n", expected[i]);
            printf("Output: %s\n", output[i]);
            printf("Result: FAIL\n\n");
        }
    }

    printf("Test cases passed: %d/%d\n", pass_count, test_count);
}

void s21_strcat_test() {
    char input1[5][20] = {{"Hello "}, {"Test string. "}, {"Another string"}, {"A"}, {""}};

    char input2[5][20] = {{"World!"}, {"123"}, {"\n"}, {"B"}, {""}};

    char expected[5][40] = {{"Hello World!"}, {"Test string. 123"}, {"Another string\n"}, {"A"}, {""}};

    char output[5][40];
    int i, test_count = 5, pass_count = 0;

    printf("s21_strcat_test:\n");

    for (i = 0; i < test_count; i++) {
        s21_strcpy(output[i], input1[i]);
        s21_strcat(output[i], input2[i]);

        if (s21_strcmp(expected[i], output[i]) == 0) {
            printf("Input1: %s\n", input1[i]);
            printf("Input2: %s\n", input2[i]);
            printf("Expected: %s\n", expected[i]);
            printf("Output: %s\n", output[i]);
            printf("Result: SUCCESS\n\n");
            pass_count++;
        } else {
            printf("Input1: %s\n", input1[i]);
            printf("Input2: %s\n", input2[i]);
            printf("Expected: %s\n", expected[i]);
            printf("Output: %s\n", output[i]);
            printf("Result: FAIL\n\n");
        }
    }

    printf("Test cases passed: %d/%d\n", pass_count, test_count);
}

void s21_strchr_test() {
    char str1[] = "hello";
    char ch1 = 'l';
    char* result;

    result = s21_strchr(str1, ch1);
    printf("Input: \"%s\", '%c'\n", str1, ch1);
    printf("Expected: \"%s\"\n", "lo");
    printf("Output: \"%s\"\n", result);
    printf("Result: %s\n", (result != NULL && s21_strcmp(result, "lo") == 0) ? "SUCCESS" : "FAIL");
    printf("\n");

    char str2[] = "hello";
    char ch2 = 'x';
    result = s21_strchr(str2, ch2);
    printf("Input: \"%s\", '%c'\n", str2, ch2);
    printf("Expected: \"%s\"\n", "NULL");
    printf("Output: \"%p\"\n", result);
    printf("Result: %s\n", (result == NULL) ? "SUCCESS" : "FAIL");
    printf("\n");

    char str3[] = "hello world";
    char ch3 = 'g';
    result = s21_strchr(str3, ch3);
    printf("Input: \"%s\", '%c'\n", str3, ch3);
    printf("Expected: \"%s\"\n", "g world");
    printf("Output: \"%s\"\n", result);
    printf("Result: %s\n", (result != NULL && s21_strcmp(result, "g world") == 0) ? "SUCCESS" : "FAIL");
    printf("\n");
}

void s21_strstr_test() {
    const char* inputs[][2] = {
        {"Hello world!", "world"},
        {"This is a test string.", "test"},
        {"This is a test string.", "abc"},
    };
    const char* expected[] = {"world!", "test string.", NULL};
    const int num_tests = sizeof(inputs) / sizeof(inputs[0]);

    int num_passed = 0;
    for (int i = 0; i < num_tests; i++) {
        const char* input1 = inputs[i][0];
        const char* input2 = inputs[i][1];
        const char* result = s21_strstr(input1, input2);
        if ((result == NULL && expected[i] == NULL) ||
            (result != NULL && expected[i] != NULL && s21_strcmp(result, expected[i]) == 0)) {
            printf("Input1: %s\nInput2: %s\nExpected: %s\nOutput: %s\nResult: SUCCESS\n\n", input1, input2,
                   expected[i], result);
            num_passed++;
        } else {
            printf("Input1: %s\nInput2: %s\nExpected: %s\nOutput: %s\nResult: FAIL\n\n", input1, input2,
                   expected[i], result);
        }
    }

    printf("s21_strstr_test: %d/%d tests passed\n", num_passed, num_tests);
}

void s21_strtok_test() {
    char input[5][20] = {{"Hello,world!"}, {"Test,string."}, {"Another,string"}, {"A,"}, {"abc def ghi"}};
    char* delim = ",";
    char* expected[5][3] = {{"Hello", "world!", NULL},
                            {"Test", "string.", NULL},
                            {"Another", "string", NULL},
                            {"A", NULL, NULL},
                            {"abc", "def", "ghi"}};

    char* token;
    int i, j, test_count = 5, pass_count = 0;

    printf("s21_strtok_test:\n");

    for (i = 0; i < test_count; i++) {
        j = 0;
        token = s21_strtok(input[i], delim);
        while (token != NULL && j < 3) {
            if (s21_strcmp(expected[i][j], token) == 0) {
                printf("Test %d.%d: input=\"%s\", expected=\"%s\", output=\"%s\" - SUCCESS\n", i + 1, j + 1,
                       input[i], expected[i][j], token);
                pass_count++;
            } else {
                printf("Test %d.%d: input=\"%s\", expected=\"%s\", output=\"%s\" - FAIL\n", i + 1, j + 1,
                       input[i], expected[i][j], token);
            }
            j++;
            token = s21_strtok(NULL, delim);
        }
        if (j == 0) {
            printf("Test %d: input=\"%s\", expected=NULL, output=NULL - SUCCESS\n", i + 1, input[i]);
            pass_count++;
        }
    }

    printf("Total: %d/%d tests passed\n", pass_count, test_count * 3);
}
