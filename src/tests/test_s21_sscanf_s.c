#include "test_s21_string.h"

START_TEST(sscanf_spec_s_2) {
  char format[] = "%s";
  char str[] =
      "\t\n\n lorem ipsum dolor sit amet, consectetur adipiscing elit \n  \t";
  char c1[100];
  char c2[100];

  int16_t res1 = s21_sscanf(str, format, c1);
  int16_t res2 = sscanf(str, format, c2);
  ck_assert_int_eq(res1, res2);
  ck_assert_pstr_eq(c1, c2);
}
END_TEST

START_TEST(sscanf_spec_s_3) {
  char format[] = "%8s";
  char str[] =
      "\t\n\n  lorem ipsum dolor sit amet, consectetur adipiscing elit \n  \t";
  char c1[100];
  char c2[100];

  int16_t res1 = s21_sscanf(str, format, c1);
  int16_t res2 = sscanf(str, format, c2);
  ck_assert_int_eq(res1, res2);
  ck_assert_pstr_eq(c1, c2);
}
END_TEST

START_TEST(sscanf_spec_s_4) {
  char format[] = " %s";
  char str[] =
      "\t\n\n   \n  \tlorem ipsum dolor sit amet, consectetur adipiscing elit";
  char c1[100];
  char c2[100];

  int16_t res1 = s21_sscanf(str, format, c1);
  int16_t res2 = sscanf(str, format, c2);
  ck_assert_int_eq(res1, res2);
  ck_assert_pstr_eq(c1, c2);
}
END_TEST

START_TEST(sscanf_spec_s_5) {
  char format[] = "%s%s%s";
  char str[] =
      "\t\n\n  lorem ipsum dolor sit amet, consectetur adipiscing elit \n  \t";
  char c11[100];
  char c12[100];
  char c13[100];
  char c21[100];
  char c22[100];
  char c23[100];

  int16_t res1 = s21_sscanf(str, format, c11, c12, c13);
  int16_t res2 = sscanf(str, format, c21, c22, c23);

  ck_assert_int_eq(res1, res2);
  ck_assert_pstr_eq(c11, c21);
  ck_assert_pstr_eq(c12, c22);
  ck_assert_pstr_eq(c13, c23);
}
END_TEST

START_TEST(sscanf_spec_s_6) {
  char format[] = "%s %s \t%s";
  char str[] =
      "\t\n\n  lorem   \n   ipsum \t\t  dolor\nsit amet, consectetur "
      "adipiscing elit \n  \t";
  char c11[100];
  char c12[100];
  char c13[100];
  char c21[100];
  char c22[100];
  char c23[100];

  int16_t res1 = s21_sscanf(str, format, c11, c12, c13);
  int16_t res2 = sscanf(str, format, c21, c22, c23);

  ck_assert_int_eq(res1, res2);
  ck_assert_pstr_eq(c11, c21);
  ck_assert_pstr_eq(c12, c22);
  ck_assert_pstr_eq(c13, c23);
}
END_TEST

START_TEST(sscanf_spec_s_7) {
  char format[] = "%s %s \t%s";
  char str[] =
      "\t\n\n  lorem \tipsum \tdolor sit amet, consectetur adipiscing elit \n  "
      "\t";
  char c11[100];
  char c12[100];
  char c13[100];
  char c21[100];
  char c22[100];
  char c23[100];

  int16_t res1 = s21_sscanf(str, format, c11, c12, c13);
  int16_t res2 = sscanf(str, format, c21, c22, c23);

  ck_assert_int_eq(res1, res2);
  ck_assert_pstr_eq(c11, c21);
  ck_assert_pstr_eq(c12, c22);
  ck_assert_pstr_eq(c13, c23);
}
END_TEST

START_TEST(sscanf_spec_s_8) {
  char format[] = "%s %*s \t%s";
  char str[] =
      "\t\n\n  lorem \tipsum \ndolor sit amet, consectetur adipiscing elit \n  "
      "\t";
  char c11[100];
  char c12[100];
  char c21[100];
  char c22[100];

  int16_t res1 = s21_sscanf(str, format, c11, c12);
  int16_t res2 = sscanf(str, format, c21, c22);

  ck_assert_int_eq(res1, res2);
  ck_assert_pstr_eq(c11, c21);
  ck_assert_pstr_eq(c12, c22);
}
END_TEST

START_TEST(sscanf_spec_s_9) {
  char format[] = "%s %2s \t%s";
  char str[] =
      "\t\n\n  lorem ipsum dolor sit amet, consectetur adipiscing elit \n  \t";
  char c11[100];
  char c12[100];
  char c13[100];
  char c21[100];
  char c22[100];
  char c23[100];

  int16_t res1 = s21_sscanf(str, format, c11, c12, c13);
  int16_t res2 = sscanf(str, format, c21, c22, c23);

  ck_assert_int_eq(res1, res2);
  ck_assert_pstr_eq(c11, c21);
  ck_assert_pstr_eq(c12, c22);
  ck_assert_pstr_eq(c13, c23);
}
END_TEST

START_TEST(sscanf_spec_s_10) {
  char format[] = "%s %*s %2s \t%s";
  char str[] =
      "\t\n\n  lorem ipsum dolor sit amet, consectetur adipiscing elit \n  \t";
  char c11[100];
  char c12[100];
  char c13[100];
  char c21[100];
  char c22[100];
  char c23[100];

  int16_t res1 = s21_sscanf(str, format, c11, c12, c13);
  int16_t res2 = sscanf(str, format, c21, c22, c23);

  ck_assert_int_eq(res1, res2);
  ck_assert_pstr_eq(c11, c21);
  ck_assert_pstr_eq(c12, c22);
  ck_assert_pstr_eq(c13, c23);
}
END_TEST

START_TEST(sscanf_spec_ws_2) {
  char *format1 = "%ls";
  wchar_t *format2 = L"%ls";

  char *str1 = "\t\n\n  いらっしゃいませ 歡迎 환영 欢迎 \n  \t";
  wchar_t *str2 = L"\t\n\n  いらっしゃいませ 歡迎 환영 欢迎 \n  \t";

  wchar_t c1[100];
  wchar_t c2[100];

  int res1 = s21_sscanf(str1, format1, c1);
  int res2 = swscanf(str2, format2, c2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(0, wcscmp(c1, c2));
}
END_TEST

START_TEST(sscanf_spec_ws_3) {
  char *format1 = "%4ls %ls %ls";
  wchar_t *format2 = L"%4ls %ls %ls";

  char *str1 = "\t\n\n  いらっしゃいませ \t\t 歡迎 \n환영 欢迎 \n  \t";
  wchar_t *str2 = L"\t\n\n  いらっしゃいませ \t\t 歡迎 \n환영 欢迎 \n  \t";

  wchar_t c11[100];
  wchar_t c12[100];
  wchar_t c13[100];
  wchar_t c21[100];
  wchar_t c22[100];
  wchar_t c23[100];

  int res1 = s21_sscanf(str1, format1, c11, c12, c13);
  int res2 = swscanf(str2, format2, c21, c22, c23);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(0, wcscmp(c11, c21));
  ck_assert_int_eq(0, wcscmp(c12, c22));
  ck_assert_int_eq(0, wcscmp(c13, c23));
}
END_TEST

START_TEST(sscanf_spec_ws_4) {
  char *format1 = "%150ls";
  wchar_t *format2 = L"%150ls";

  char *str1 = "\t\n\n  いらっしゃいませ \t\t 歡迎 \n환영 欢迎 \n  \t";
  wchar_t *str2 = L"\t\n\n  いらっしゃいませ \t\t 歡迎 \n환영 欢迎 \n  \t";

  wchar_t c1[100];
  wchar_t c2[100];

  int res1 = s21_sscanf(str1, format1, c1);
  int res2 = swscanf(str2, format2, c2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(0, wcscmp(c1, c2));
}
END_TEST

START_TEST(sscanf_spec_ws_5) {
  char *format1 = "%ls%ls%ls";
  wchar_t *format2 = L"%ls%ls%ls";

  char *str1 =
      "\t\n\n \t\n\n  いらっしゃいませ \t\t 歡迎 \n환영 欢迎 \n  \t \n  \t";
  wchar_t *str2 =
      L"\t\n\n \t\n\n  いらっしゃいませ \t\t 歡迎 \n환영 欢迎 \n  \t \n  \t";

  wchar_t c11[100];
  wchar_t c12[100];
  wchar_t c13[100];
  wchar_t c21[100];
  wchar_t c22[100];
  wchar_t c23[100];

  int res1 = s21_sscanf(str1, format1, c11, c12, c13);
  int res2 = swscanf(str2, format2, c21, c22, c23);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(0, wcscmp(c11, c21));
  ck_assert_int_eq(0, wcscmp(c12, c22));
  ck_assert_int_eq(0, wcscmp(c13, c23));
}
END_TEST

START_TEST(sscanf_spec_ws_6) {
  char *format1 = "%ls %ls \t%ls";
  wchar_t *format2 = L"%ls %ls \t%ls";

  char *str1 = "\t\n  いらっしゃいませ \t\t 歡迎 \n환영 欢迎 \t";
  wchar_t *str2 = L"\t\n  いらっしゃいませ \t\t 歡迎 \n환영 欢迎 \t";

  wchar_t c11[100];
  wchar_t c12[100];
  wchar_t c13[100];
  wchar_t c21[100];
  wchar_t c22[100];
  wchar_t c23[100];

  int res1 = s21_sscanf(str1, format1, c11, c12, c13);
  int res2 = swscanf(str2, format2, c21, c22, c23);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(0, wcscmp(c11, c21));
  ck_assert_int_eq(0, wcscmp(c12, c22));
  ck_assert_int_eq(0, wcscmp(c13, c23));
}
END_TEST

START_TEST(sscanf_spec_ws_7) {
  char *format1 = "%ls %ls \t%ls";
  wchar_t *format2 = L"%ls %ls \t%ls";

  char *str1 = "\t\n  いらっしゃいませ \t";
  wchar_t *str2 = L"\t\n  いらっしゃいませ \t";

  wchar_t c11[100] = {'\0'};
  wchar_t c12[100] = {'\0'};
  wchar_t c13[100] = {'\0'};
  wchar_t c21[100] = {'\0'};
  wchar_t c22[100] = {'\0'};
  wchar_t c23[100] = {'\0'};

  int res1 = s21_sscanf(str1, format1, c11, c12, c13);
  int res2 = swscanf(str2, format2, c21, c22, c23);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(0, wcscmp(c11, c21));
  ck_assert_int_eq(0, wcscmp(c12, c22));
  ck_assert_int_eq(0, wcscmp(c13, c23));
}
END_TEST

START_TEST(sscanf_spec_ws_8) {
  char *format1 = "%ls %*ls \t%ls";
  wchar_t *format2 = L"%ls %*ls \t%ls";

  char *str1 = "\t\n  いらっしゃいませ \t\t 歡迎 \n환영 欢迎 \t";
  wchar_t *str2 = L"\t\n  いらっしゃいませ \t\t 歡迎 \n환영 欢迎 \t";

  wchar_t c11[100];
  wchar_t c12[100];
  wchar_t c21[100];
  wchar_t c22[100];

  int res1 = s21_sscanf(str1, format1, c11, c12);
  int res2 = swscanf(str2, format2, c21, c22);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(0, wcscmp(c11, c21));
  ck_assert_int_eq(0, wcscmp(c12, c22));
}
END_TEST

START_TEST(sscanf_spec_ws_9) {
  char *format1 = "%2ls %ls \t%4ls";
  wchar_t *format2 = L"%2ls %ls \t%4ls";

  char *str1 = "\t\n  いらっしゃいませ \t\t 歡迎 \n환영欢迎歡迎 \t";
  wchar_t *str2 = L"\t\n  いらっしゃいませ \t\t 歡迎 \n환영欢迎歡迎 \t";

  wchar_t c11[100];
  wchar_t c12[100];
  wchar_t c13[100];
  wchar_t c21[100];
  wchar_t c22[100];
  wchar_t c23[100];

  int res1 = s21_sscanf(str1, format1, c11, c12, c13);
  int res2 = swscanf(str2, format2, c21, c22, c23);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(0, wcscmp(c11, c21));
  ck_assert_int_eq(0, wcscmp(c12, c22));
  ck_assert_int_eq(0, wcscmp(c13, c23));
}
END_TEST

START_TEST(sscanf_spec_ws_10) {
  char *format1 = "%ls %2ls %*ls \t%4ls";
  wchar_t *format2 = L"%ls %2ls %*ls \t%4ls";

  char *str1 = "\t\n  いらっしゃいませ \t\t 歡迎 \n환영欢迎歡迎 \t";
  wchar_t *str2 = L"\t\n  いらっしゃいませ \t\t 歡迎 \n환영欢迎歡迎 \t";

  wchar_t c11[100];
  wchar_t c12[100];
  wchar_t c13[100] = {'\0'};
  wchar_t c21[100];
  wchar_t c22[100];
  wchar_t c23[100] = {'\0'};

  int res1 = s21_sscanf(str1, format1, c11, c12, c13);
  int res2 = swscanf(str2, format2, c21, c22, c23);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(0, wcscmp(c11, c21));
  ck_assert_int_eq(0, wcscmp(c12, c22));
  ck_assert_int_eq(0, wcscmp(c13, c23));
}
END_TEST

Suite *test_sscanf_s(void) {
  Suite *s = suite_create("\033[33m-=s21_sscanf_s=-\033[0m");
  TCase *tc = tcase_create("sscanf_tc");

  tcase_add_test(tc, sscanf_spec_s_2);
  tcase_add_test(tc, sscanf_spec_s_3);
  tcase_add_test(tc, sscanf_spec_s_4);
  tcase_add_test(tc, sscanf_spec_s_5);
  tcase_add_test(tc, sscanf_spec_s_6);
  tcase_add_test(tc, sscanf_spec_s_7);
  tcase_add_test(tc, sscanf_spec_s_8);
  tcase_add_test(tc, sscanf_spec_s_9);
  tcase_add_test(tc, sscanf_spec_s_10);
  tcase_add_test(tc, sscanf_spec_ws_2);
  tcase_add_test(tc, sscanf_spec_ws_3);
  tcase_add_test(tc, sscanf_spec_ws_4);
  tcase_add_test(tc, sscanf_spec_ws_5);
  tcase_add_test(tc, sscanf_spec_ws_6);
  tcase_add_test(tc, sscanf_spec_ws_7);
  tcase_add_test(tc, sscanf_spec_ws_8);
  tcase_add_test(tc, sscanf_spec_ws_9);
  tcase_add_test(tc, sscanf_spec_ws_10);

  suite_add_tcase(s, tc);
  return s;
}
