//#include <locale.h>

#include "test_s21_string.h"

START_TEST(sprintf_1_s) {
  char str1[100] = "";
  char str2[100] = "";
  char *str3 = "Test %s Test";
  char *val = "Why am I here?!";
  ck_assert_int_eq(sprintf(str1, str3, val), s21_sprintf(str2, str3, val));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_2_s) {
  char str1[100];
  char str2[100];
  char *str3 = "%s Test %s Test %s";
  char *val = "I'm so tired";
  char *val2 = "Who invented this?";
  char *val3 = "This project gave me hemmoroids";
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3),
                   s21_sprintf(str2, str3, val, val2, val3));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_3_s) {
  char str1[100];
  char str2[100];
  char *str3 = "%s Test %s Test %s";
  char *val = "Don't need this test";
  char *val2 = "Just for the kicks";
  char *val3 = "Lol";
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3),
                   s21_sprintf(str2, str3, val, val2, val3));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_4_s) {
  char str1[100];
  char str2[100];
  char *str3 = "Test %ls Test2";
  wchar_t *val = L"3wtf80";
  ck_assert_int_eq(sprintf(str1, str3, val), s21_sprintf(str2, str3, val));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_5_s) {
  char str1[200];
  char str2[200];
  char *str3 = "%3s Test %5s Test %10s";
  char *val = "WHAT IS THIS";
  char *val2 = "i don't care anymore";
  char *val3 = "PPAP";
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3),
                   s21_sprintf(str2, str3, val, val2, val3));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_6_s) {
  char str1[200];
  char str2[200];
  char *str3 = "%6.5s Test %.23s Test %3.s TEST %.s";
  char *val = "WHAT IS THIS";
  char *val2 = "i don't care anymore, really";
  char *val3 = "PPAP";
  char *val4 = "I don't feel so good";
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4),
                   s21_sprintf(str2, str3, val, val2, val3, val4));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_7_s) {
  char str1[200];
  char str2[200];
  char *str3 = "%-10.5s Test %-.8s Test %-7s TEST %-.s";
  char *val = "WHAT IS THIS";
  char *val2 = "i don't care anymore, really";
  char *val3 = "PPAP";
  char *val4 = "I don't feel so good";
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4),
                   s21_sprintf(str2, str3, val, val2, val3, val4));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_8_s) {
  char str1[200];
  char str2[200];
  char *str3 = "%0s Test %0.s Test %0.0s TEST %0s GOD %.s";
  char *val = "WHAT IS THIS";
  char *val2 = "i don't care anymore, really";
  char *val3 = "PPAP";
  char *val4 = "I don't feel so good";
  char *val5 = "What is lovin'?!";
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4, val5),
                   s21_sprintf(str2, str3, val, val2, val3, val4, val5));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_9_s) {
  char str1[200];
  char str2[200];
  char *str3 = "%+s Test %+3.s Test %5.7s TEST %10s";
  char *val = "WHAT IS THIS";
  char *val2 = "i don't care anymore, really";
  char *val3 = "abcd";
  char *val4 = "I don't feel so good";
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4),
                   s21_sprintf(str2, str3, val, val2, val3, val4));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_10_s) {
  char str1[200];
  char str2[200];
  char *str3 = "%s Test %3.s Test %5.7s TEST %10s %#s %-s %+s %.s % .s";
  char *val = NULL;
  ck_assert_int_eq(
      sprintf(str1, str3, val, val, val, val, val, val, val, val, val),
      s21_sprintf(str2, str3, val, val, val, val, val, val, val, val, val));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_11_s) {
  char str1[200];
  char str2[200];
  char *str3 = "% s Test % 3.s Test % 5.7s TEST % 10s GOD %.s";
  char *val = "WHAT IS THIS";
  char *val2 = "i don't care anymore, really";
  char *val3 = "PPAP";
  char *val4 = "I don't feel so good";
  char *val5 = "What is lovin'?!";
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4, val5),
                   s21_sprintf(str2, str3, val, val2, val3, val4, val5));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_12_s) {
  char str1[200];
  char str2[200];
  char *str3 = "%+s Test %+3.s Test %+5.7s TEST %+10s GOD %+.s";
  char *val = "WHAT IS THIS";
  char *val2 = "i don't care anymore, really";
  char *val3 = "PPAP";
  char *val4 = "I don't feel so good";
  char *val5 = "What is lovin'?!";
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4, val5),
                   s21_sprintf(str2, str3, val, val2, val3, val4, val5));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_13_s) {
  char str1[200];
  char str2[200];
  char *str3 = "%#s Test %#3s Test %#5.7s TEST %#.7s Oof %#.s";
  char *val = "WHAT IS THIS";
  char *val2 = "i don't care anymore, really";
  char *val3 = "PPAP";
  char *val4 = "I don't feel so good";
  char *val5 = "What is lovin'?!";
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4, val5),
                   s21_sprintf(str2, str3, val, val2, val3, val4, val5));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_14_s) {
  char str1[200];
  char str2[200];
  char *str3 = "%0s Test %06s Test %05.7s TEST %0.7s Oof %0.s";
  char *val = "WHAT IS THIS";
  char *val2 = "idx";
  char *val3 = "PPAP";
  char *val4 = "I don't";
  char *val5 = "What is lovin'?!";
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4, val5),
                   s21_sprintf(str2, str3, val, val2, val3, val4, val5));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_15_s) {
  char str1[200];
  char str2[200];
  char *str3 = "%*s Test %-*s Test %*.*s TEST %.*s";
  char *val = "WHAT IS THIS";
  char *val2 = "i don't care anymore, really";
  char *val3 = "PPAP";
  char *val4 = "I don't feel so good";
  int ast = 2;
  int ast2 = 5;
  int ast3 = 4;
  int ast4 = 10;
  int ast5 = 7;
  ck_assert_int_eq(
      sprintf(str1, str3, ast, val, ast2, val2, ast3, ast4, val3, ast5, val4),
      s21_sprintf(str2, str3, ast, val, ast2, val2, ast3, ast4, val3, ast5,
                  val4));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_16_s) {
  char str1[100];
  char str2[100];
  char *str3 = "%s %s %s %% %d";
  char *val = "This";
  char *val2 = "\0";
  int val3 = 65;
  char *val4 = "string";
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val4, val3),
                   s21_sprintf(str2, str3, val, val2, val4, val3));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_17_s) {
  char str1[1024];
  char str2[1024];
  char *str3 =
      "%0.0s %1.0s %2.0s %3.0s %5.0s %6.0s %7.0s %0.3s %0.7s %3.2s %3.7s %7.3s";
  char *val = NULL;
  ck_assert_int_eq(s21_sprintf(str2, str3, val, val, val, val, val, val, val,
                               val, val, val, val, val),
                   sprintf(str1, str3, val, val, val, val, val, val, val, val,
                           val, val, val, val));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_18_s) {
  //setlocale(LC_ALL, "");

  wchar_t str1[1024];
  char str2[1024];
  wchar_t str2_w[1024];
  char *str3 = "%ls %ls %ls %ls";
  wchar_t *str3_w = L"%ls %ls %ls %ls";
  wchar_t *val = L"いらっしゃいませ";
  wchar_t *val1 = L"歡迎";
  wchar_t *val2 = L"환영";
  wchar_t *val3 = L"欢迎";

  int len21 = s21_sprintf(str2, str3, val, val1, val2, val3);
  int len = swprintf(str1, 1024, str3_w, val, val1, val2, val3);

  mbstowcs(str2_w, str2, 1024);

  ck_assert_int_eq(0, wcscmp(str1, str2_w));
  ck_assert_int_eq(len, len21);
}
END_TEST

START_TEST(sprintf_19_s) {
  //setlocale(LC_ALL, "");

  wchar_t str1[1024];
  char str2[1024];
  wchar_t str2_w[1024];
  char *str3 = "%3.5ls %10.1ls %.8ls %-.0ls";
  wchar_t *str3_w = L"%3.5ls %10.1ls %.8ls %-.0ls";
  wchar_t *val = L"いらっしゃいませ";
  wchar_t *val1 = L"歡迎";
  wchar_t *val2 = L"환영";
  wchar_t *val3 = L"欢迎";

  int len21 = s21_sprintf(str2, str3, val, val1, val2, val3);
  int len = swprintf(str1, 1024, str3_w, val, val1, val2, val3);

  mbstowcs(str2_w, str2, 1024);

  ck_assert_int_eq(0, wcscmp(str1, str2_w));
  ck_assert_int_eq(len, len21);
}
END_TEST

START_TEST(sprintf_20_s) {
  //setlocale(LC_ALL, "");

  wchar_t str1[1024];
  char str2[1024];
  wchar_t str2_w[1024];
  char *str3 = "%#ls %+.*ls %06ls %*.*ls";
  wchar_t *str3_w = L"%#ls %+.*ls %06ls %*.*ls";
  wchar_t *val = L"いらっしゃいませ";
  wchar_t *val1 = L"歡迎";
  wchar_t *val2 = L"환영";
  wchar_t *val3 = L"欢迎";
  int val4 = 10;

  int len21 = s21_sprintf(str2, str3, val, val4, val1, val2, val4, val4, val3);
  int len =
      swprintf(str1, 1024, str3_w, val, val4, val1, val2, val4, val4, val3);

  mbstowcs(str2_w, str2, 1024);

  ck_assert_int_eq(0, wcscmp(str1, str2_w));
  ck_assert_int_eq(len, len21);
}
END_TEST

Suite *test_sprintf_s(void) {
  Suite *s = suite_create("\033[33m-=s21_sprintf_s=-\033[0m");
  TCase *tc = tcase_create("sprintf_tc");

  tcase_add_test(tc, sprintf_1_s);
  tcase_add_test(tc, sprintf_2_s);
  tcase_add_test(tc, sprintf_3_s);
  tcase_add_test(tc, sprintf_4_s);  // WCHAR
  tcase_add_test(tc, sprintf_5_s);
  tcase_add_test(tc, sprintf_6_s);
  tcase_add_test(tc, sprintf_7_s);
  tcase_add_test(tc, sprintf_8_s);
  tcase_add_test(tc, sprintf_9_s);
  tcase_add_test(tc, sprintf_10_s);
  tcase_add_test(tc, sprintf_11_s);
  tcase_add_test(tc, sprintf_12_s);
  tcase_add_test(tc, sprintf_13_s);
  tcase_add_test(tc, sprintf_14_s);
  tcase_add_test(tc, sprintf_15_s);
  tcase_add_test(tc, sprintf_16_s);
  tcase_add_test(tc, sprintf_17_s);
  tcase_add_test(tc, sprintf_18_s);
  tcase_add_test(tc, sprintf_19_s);
  tcase_add_test(tc, sprintf_20_s);

  suite_add_tcase(s, tc);
  return s;
}
