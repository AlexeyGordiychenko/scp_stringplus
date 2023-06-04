#include <locale.h>

#include "test_s21_string.h"

START_TEST(sscanf_spec_c_2) {
  char format[] = "%c";
  char str[] = "\t\n\n  1 \n  \t";
  char c1, c2;

  int16_t res1 = s21_sscanf(str, format, &c1);
  int16_t res2 = sscanf(str, format, &c2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(c1, c2);
}
END_TEST

START_TEST(sscanf_spec_c_3) {
  char format[] = "%8c";
  char str[] = "\t\n\n  123 \n  \t";
  char c1[9] = {'\0'};
  char c2[9] = {'\0'};

  int16_t res1 = s21_sscanf(str, format, c1);
  int16_t res2 = sscanf(str, format, c2);
  ck_assert_int_eq(res1, res2);
  ck_assert_pstr_eq(c1, c2);
}
END_TEST

START_TEST(sscanf_spec_c_4) {
  char format[] = " %c";
  char str[] = "\t\n\n   \n  \ta";
  char c1, c2;
  int16_t res1 = s21_sscanf(str, format, &c1);
  int16_t res2 = sscanf(str, format, &c2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(c1, c2);
}
END_TEST

START_TEST(sscanf_spec_c_5) {
  char format[] = "%c%c%c";
  char str[] = "\t\n\n  123 \n  \t";
  char c11, c12, c13, c21, c22, c23;

  int16_t res1 = s21_sscanf(str, format, &c11, &c12, &c13);
  int16_t res2 = sscanf(str, format, &c21, &c22, &c23);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(c11, c21);
  ck_assert_int_eq(c12, c22);
  ck_assert_int_eq(c13, c23);
}
END_TEST

START_TEST(sscanf_spec_c_6) {
  char format[] = "%c %c \t%c";
  char str[] = "\t\n\n  1    2 3 \n  \t";
  char c11, c12, c13, c21, c22, c23;

  int16_t res1 = s21_sscanf(str, format, &c11, &c12, &c13);
  int16_t res2 = sscanf(str, format, &c21, &c22, &c23);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(c11, c21);
  ck_assert_int_eq(c12, c22);
  ck_assert_int_eq(c13, c23);
}
END_TEST

START_TEST(sscanf_spec_c_7) {
  char format[] = "%c %c \t%c";
  char str[] = "\t\n\n  123 \n  \t";
  char c11, c12, c13, c21, c22, c23;

  int16_t res1 = s21_sscanf(str, format, &c11, &c12, &c13);
  int16_t res2 = sscanf(str, format, &c21, &c22, &c23);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(c11, c21);
  ck_assert_int_eq(c12, c22);
  ck_assert_int_eq(c13, c23);
}
END_TEST

START_TEST(sscanf_spec_c_8) {
  char format[] = "%c %*c \t%c";
  char str[] = "\t\n\n  123 \n  \t";
  char c11, c12, c21, c22;

  int16_t res1 = s21_sscanf(str, format, &c11, &c12);
  int16_t res2 = sscanf(str, format, &c21, &c22);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(c11, c21);
  ck_assert_int_eq(c12, c22);
}
END_TEST

START_TEST(sscanf_spec_c_9) {
  char format[] = "%c %5c \t%c";
  char str[] = "\t\n\n  1 2 3 \n  \t";
  char c11, c13, c21, c23;
  char c12[6] = {'\0'};
  char c22[6] = {'\0'};

  int16_t res1 = s21_sscanf(str, format, &c11, c12, &c13);
  int16_t res2 = sscanf(str, format, &c21, c22, &c23);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(c11, c21);
  ck_assert_pstr_eq(c12, c22);
  ck_assert_int_eq(c13, c23);
}
END_TEST

START_TEST(sscanf_spec_c_10) {
  char format[] = "%c %*c %2c \t%c";
  char str[] = "\t\n\n  123 \n  \t";
  char c11, c12, c14, c21, c22, c24;
  char c13[3] = {'\0'};
  char c23[3] = {'\0'};

  int16_t res1 = s21_sscanf(str, format, &c11, &c12, c13, &c14);
  int16_t res2 = sscanf(str, format, &c21, &c22, c23, &c24);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(c11, c21);
  ck_assert_int_eq(c12, c22);
  ck_assert_pstr_eq(c13, c23);
  ck_assert_int_eq(c14, c24);
}
END_TEST

START_TEST(sscanf_spec_wc_2) {
  setlocale(LC_ALL, "");

  char *format1 = "%lc";
  wchar_t *format2 = L"%lc";

  char *str1 = "\t\n\n  ら \n  \t";
  wchar_t *str2 = L"\t\n\n  ら \n  \t";

  wchar_t c1, c2;

  int res1 = s21_sscanf(str1, format1, &c1);
  int res2 = swscanf(str2, format2, &c2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(1, c1 == c2);
}
END_TEST

START_TEST(sscanf_spec_wc_3) {
  setlocale(LC_ALL, "");

  char *format1 = "%4lc %lc %lc";
  wchar_t *format2 = L"%4lc %lc %lc";

  char *str1 = "いらっし\t\n\n ゃ \tいませ!";
  wchar_t *str2 = L"いらっし\t\n\n ゃ \tいませ!";

  wchar_t c11[5] = {'\0'};
  wchar_t c21[5] = {'\0'};
  wchar_t c12, c13, c22, c23;

  int res1 = s21_sscanf(str1, format1, c11, &c12, &c13);
  int res2 = swscanf(str2, format2, c21, &c22, &c23);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(0, wcscmp(c11, c21));
  ck_assert_int_eq(1, c12 == c22);
  ck_assert_int_eq(1, c13 == c23);
}
END_TEST

START_TEST(sscanf_spec_wc_4) {
  setlocale(LC_ALL, "");

  char *format1 = "%lc";
  wchar_t *format2 = L"%lc";

  char *str1 = "\t\n\n   \n  \tま";
  wchar_t *str2 = L"\t\n\n   \n  \tま";

  wchar_t c1, c2;

  int res1 = s21_sscanf(str1, format1, &c1);
  int res2 = swscanf(str2, format2, &c2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(1, c1 == c2);
}
END_TEST

START_TEST(sscanf_spec_wc_5) {
  setlocale(LC_ALL, "");

  char *format1 = "%lc%lc%lc";
  wchar_t *format2 = L"%lc%lc%lc";

  char *str1 = "\t\n\n  歡迎환 \n  \t";
  wchar_t *str2 = L"\t\n\n  歡迎환 \n  \t";

  wchar_t c11, c12, c13, c21, c22, c23;

  int res1 = s21_sscanf(str1, format1, &c11, &c12, &c13);
  int res2 = swscanf(str2, format2, &c21, &c22, &c23);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(1, c11 == c21);
  ck_assert_int_eq(1, c12 == c22);
  ck_assert_int_eq(1, c13 == c23);
}
END_TEST

START_TEST(sscanf_spec_wc_6) {
  setlocale(LC_ALL, "");

  char *format1 = "%lc %lc \t%lc";
  wchar_t *format2 = L"%lc %lc \t%lc";

  char *str1 = "\t\n\n  영    欢 迎 \n  \t";
  wchar_t *str2 = L"\t\n\n  영    欢 迎 \n  \t";

  wchar_t c11, c12, c13, c21, c22, c23;

  int res1 = s21_sscanf(str1, format1, &c11, &c12, &c13);
  int res2 = swscanf(str2, format2, &c21, &c22, &c23);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(1, c11 == c21);
  ck_assert_int_eq(1, c12 == c22);
  ck_assert_int_eq(1, c13 == c23);
}
END_TEST

START_TEST(sscanf_spec_wc_7) {
  setlocale(LC_ALL, "");

  char *format1 = "%lc %lc \t%lc";
  wchar_t *format2 = L"%lc %lc \t%lc";

  char *str1 = "\t\n\n  ゃいせ \n  \t";
  wchar_t *str2 = L"\t\n\n  ゃいせ \n  \t";

  wchar_t c11, c12, c13, c21, c22, c23;

  int res1 = s21_sscanf(str1, format1, &c11, &c12, &c13);
  int res2 = swscanf(str2, format2, &c21, &c22, &c23);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(1, c11 == c21);
  ck_assert_int_eq(1, c12 == c22);
  ck_assert_int_eq(1, c13 == c23);
}
END_TEST

START_TEST(sscanf_spec_wc_8) {
  setlocale(LC_ALL, "");

  char *format1 = "%lc %*lc \t%lc";
  wchar_t *format2 = L"%lc %*lc \t%lc";

  char *str1 = "\t\n\n  らっし \n  \t";
  wchar_t *str2 = L"\t\n\n  らっし \n  \t";

  wchar_t c11, c12, c21, c22;

  int res1 = s21_sscanf(str1, format1, &c11, &c12);
  int res2 = swscanf(str2, format2, &c21, &c22);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(1, c11 == c21);
  ck_assert_int_eq(1, c12 == c22);
}
END_TEST

START_TEST(sscanf_spec_wc_9) {
  setlocale(LC_ALL, "");

  char *format1 = "%lc %2lc \t%4lc";
  wchar_t *format2 = L"%lc %2lc \t%4lc";

  char *str1 = "\t\n\n  환영    歡迎欢迎 \n  \t";
  wchar_t *str2 = L"\t\n\n  환영    歡迎欢迎 \n  \t";

  wchar_t c12[3] = {'\0'};
  wchar_t c22[3] = {'\0'};
  wchar_t c13[5] = {'\0'};
  wchar_t c23[5] = {'\0'};
  wchar_t c11, c21;

  int res1 = s21_sscanf(str1, format1, &c11, c12, c13);
  int res2 = swscanf(str2, format2, &c21, c22, c23);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(1, c11 == c21);
  ck_assert_int_eq(0, wcscmp(c12, c22));
  ck_assert_int_eq(0, wcscmp(c13, c23));
}
END_TEST

START_TEST(sscanf_spec_wc_10) {
  setlocale(LC_ALL, "");

  char *format1 = "%lc %2lc %*lc \t%4lc";
  wchar_t *format2 = L"%lc %2lc %*lc \t%4lc";

  char *str1 = "\n\t\n  歡迎 환 \n\t 歡迎欢迎 \n  \t";
  wchar_t *str2 = L"\n\t\n  歡迎 환 \n\t 歡迎欢迎 \n  \t";

  wchar_t c12[3] = {'\0'};
  wchar_t c22[3] = {'\0'};
  wchar_t c13[5] = {'\0'};
  wchar_t c23[5] = {'\0'};
  wchar_t c11, c21;

  int res1 = s21_sscanf(str1, format1, &c11, c12, c13);
  int res2 = swscanf(str2, format2, &c21, c22, c23);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(1, c11 == c21);
  ck_assert_int_eq(0, wcscmp(c12, c22));
  ck_assert_int_eq(0, wcscmp(c13, c23));
}
END_TEST

Suite *test_sscanf_c(void) {
  Suite *s = suite_create("\033[45m-=S21_SSCANF_C=-\033[0m");
  TCase *tc = tcase_create("sscanf_tc");

  tcase_add_test(tc, sscanf_spec_c_2);
  tcase_add_test(tc, sscanf_spec_c_3);
  tcase_add_test(tc, sscanf_spec_c_4);
  tcase_add_test(tc, sscanf_spec_c_5);
  tcase_add_test(tc, sscanf_spec_c_6);
  tcase_add_test(tc, sscanf_spec_c_7);
  tcase_add_test(tc, sscanf_spec_c_8);
  tcase_add_test(tc, sscanf_spec_c_9);
  tcase_add_test(tc, sscanf_spec_c_10);
  tcase_add_test(tc, sscanf_spec_wc_2);
  tcase_add_test(tc, sscanf_spec_wc_3);
  tcase_add_test(tc, sscanf_spec_wc_4);
  tcase_add_test(tc, sscanf_spec_wc_5);
  tcase_add_test(tc, sscanf_spec_wc_6);
  tcase_add_test(tc, sscanf_spec_wc_7);
  tcase_add_test(tc, sscanf_spec_wc_8);
  tcase_add_test(tc, sscanf_spec_wc_9);
  tcase_add_test(tc, sscanf_spec_wc_10);

  suite_add_tcase(s, tc);
  return s;
}
