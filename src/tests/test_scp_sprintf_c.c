#include "test_scp_string.h"

START_TEST(sprintf_1_c) {
  char str1[100];
  char str2[100];
  char *str3 = "%c!%c!%c!%c!%c";
  int a = 9;
  int b = 10;
  int c = 17;
  int d = 66;
  int e = 124;
  ck_assert_int_eq(sprintf(str1, str3, a, b, c, d, e),
                   scp_sprintf(str2, str3, a, b, c, d, e));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_2_c) {
  char str1[100];
  char str2[100];
  char *str3 = "%c!%c!%c!%c!%c";
  int a = -6;
  int b = -10;
  int c = -17;
  int d = -66;
  int e = -124;
  ck_assert_int_eq(sprintf(str1, str3, a, b, c, d, e),
                   scp_sprintf(str2, str3, a, b, c, d, e));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_3_c) {
  char str1[100];
  char str2[100];
  char *str3 = "%c!%c!%c!%c!%c";
  int a = 60;
  int b = 50;
  int c = 1744;
  int d = 386;
  int e = 257;
  ck_assert_int_eq(sprintf(str1, str3, a, b, c, d, e),
                   scp_sprintf(str2, str3, a, b, c, d, e));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_4_c) {
  char str1[100];
  char str2[100];
  char *str3 = "%c!%c!%c!%c!%c";
  int a = 60;
  int b = 50;
  int c = 1744;
  int d = 386;
  int e = 257;
  ck_assert_int_eq(sprintf(str1, str3, a, b, c, d, e),
                   scp_sprintf(str2, str3, a, b, c, d, e));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_5_c) {
  char str1[100];
  char str2[100];
  char *str3 = "%c!%c!%c!%c!%c";
  char a = 0;
  ck_assert_int_eq(sprintf(str1, str3, a, a, a, a, a),
                   scp_sprintf(str2, str3, a, a, a, a, a));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_6_c) {
  char str1[100];
  char str2[100];
  char *str3 = "%05c!% 5c!%lc!";
  int a = 70;
  unsigned long int b = 70;
  ck_assert_int_eq(sprintf(str1, str3, a, a, b),
                   scp_sprintf(str2, str3, a, a, b));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_7_c) {
  char str1[100];
  char str2[100];
  char *str3 = "%-010c!% -10c!%-lc";
  int a = 74;
  unsigned long int b = 74;
  ck_assert_int_eq(sprintf(str1, str3, a, a, b),
                   scp_sprintf(str2, str3, a, a, b));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_8_c) {
  char str1[100];
  char str2[100];
  char *str3 = "%+010.5c!% +10.5c!%-10lc!%-10lc!%+10lc";
  char a = 92;
  unsigned long int b = 92;
  unsigned long int c = 92;
  ck_assert_int_eq(sprintf(str1, str3, a, a, b, c, c),
                   scp_sprintf(str2, str3, a, a, b, c, c));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_9_c) {
  char str1[100];
  char str2[100];
  char *str3 = "%6.4c!%-6.4c!%4.10lc!%-4.10lc!%-0lc";
  int a = 10;
  unsigned long int b = 10;
  unsigned long int c = 10;
  ck_assert_int_eq(sprintf(str1, str3, a, a, b, c, c),
                   scp_sprintf(str2, str3, a, a, b, c, c));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_10_c) {
  char str1[100];
  char str2[100];
  char *str3 = "%6.4c!%-6.4c!%4.10lc!%-4.10lc!%-0lc";
  int a = -10;
  unsigned long int b = 10;
  unsigned long int c = 10;
  ck_assert_int_eq(sprintf(str1, str3, a, a, b, c, c),
                   scp_sprintf(str2, str3, a, a, b, c, c));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_11_c) {
  char str1[100];
  char str2[100];
  char *str3 = "%#c!%#c!%#c!%#c!%#c";
  ck_assert_int_eq(sprintf(str1, str3, ' ', 'n', '5', '%', '\\'),
                   scp_sprintf(str2, str3, ' ', 'n', '5', '%', '\\'));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_12_c) {
  char str1[100];
  char str2[100];
  char *str3 = "%c!%c!%c!%c!%c";
  ck_assert_int_eq(sprintf(str1, str3, '\n', '\0', '\0', '\0', 'c'),
                   scp_sprintf(str2, str3, '\n', '\0', '\0', '\0', 'c'));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_13_c) {
  char str1[100];
  char str2[100];
  char *str3 = "%c!%c!%c!%c!%c";
  ck_assert_int_eq(sprintf(str1, str3, 'b', '4', '#', '@', '\0'),
                   scp_sprintf(str2, str3, 'b', '4', '#', '@', '\0'));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_14_c) {
  char str1[100];
  char str2[100];
  char *str3 = "%c!%c!%c!%c!%c";
  ck_assert_int_eq(sprintf(str1, str3, 'Y', 'G', 123, '\0', 'J'),
                   scp_sprintf(str2, str3, 'Y', 'G', 123, '\0', 'J'));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_15_c) {
  char str1[400];
  char str2[400];
  char *str3 = "%.7c!%-7c!%-50c!% 54c!%0188c";
  int a = 112;
  ck_assert_int_eq(sprintf(str1, str3, a, a, a, a, a),
                   scp_sprintf(str2, str3, a, a, a, a, a));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_16_c) {
  char str1[400];
  char str2[400];
  char *str3 = "%.7c!% -.7c!%- 050c!%- 54c!%-0188c";
  int a = 45;
  ck_assert_int_eq(sprintf(str1, str3, a, a, a, a, a),
                   scp_sprintf(str2, str3, a, a, a, a, a));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_17_c) {
  char str1[400];
  char str2[400];
  char *str3 = "%70c!%-90c!%080c!%-065c!%- 60c";
  int a = 255;
  ck_assert_int_eq(sprintf(str1, str3, a, a, a, a, a),
                   scp_sprintf(str2, str3, a, a, a, a, a));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_18_c) {
  char str1[400];
  char str2[400];
  char *str3 = "%70c!%-90c!%080c!%-065c!%- 60c";
  int a = 255;
  ck_assert_int_eq(sprintf(str1, str3, a, a, a, a, a),
                   scp_sprintf(str2, str3, a, a, a, a, a));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_19_c) {
  char str1[100];
  char str2[100];
  char *str3 = "%c!%lc!%hc";
  int a = 3;
  unsigned long int b = 103;
  unsigned short e = 255;
  ck_assert_int_eq(sprintf(str1, str3, a, b, e),
                   scp_sprintf(str2, str3, a, b, e));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_20_c) {
  wchar_t str1[100];
  char str2[100];
  wchar_t str2_w[100];
  char *str3 = "TEST %lc right now\n";
  wchar_t *str3_w = L"TEST %lc right now\n";
  wchar_t a = L'あ';

  int len = swprintf(str1, 100, str3_w, a);
  int len21 = scp_sprintf(str2, str3, a);
  mbstowcs(str2_w, str2, 100);

  ck_assert_int_eq(0, wcscmp(str1, str2_w));
  ck_assert_int_eq(len, len21);
}
END_TEST

START_TEST(sprintf_21_c) {
  wchar_t str1[100];
  char str2[100];
  wchar_t str2_w[100];
  char *str3 = "Welcome is %-5lc%2lc%2lc%2lc%2lc%2lc%2lc%6lc in japanese\n";
  wchar_t *str3_w =
      L"Welcome is %-5lc%2lc%2lc%2lc%2lc%2lc%2lc%6lc in japanese\n";

  wchar_t a = L'い';
  wchar_t b = L'ら';
  wchar_t c = L'っ';
  wchar_t d = L'し';
  wchar_t e = L'ゃ';
  wchar_t f = L'い';
  wchar_t g = L'ま';
  wchar_t h = L'せ';

  int len = swprintf(str1, 100, str3_w, a, b, c, d, e, f, g, h);
  int len21 = scp_sprintf(str2, str3, a, b, c, d, e, f, g, h);
  mbstowcs(str2_w, str2, 100);

  ck_assert_int_eq(0, wcscmp(str1, str2_w));
  ck_assert_int_eq(len, len21);
}
END_TEST

Suite *test_sprintf_c(void) {
  Suite *s = suite_create("\033[33m-=scp_sprintf_c=-\033[0m");
  TCase *tc = tcase_create("sprintf_tc");

  tcase_add_test(tc, sprintf_1_c);
  tcase_add_test(tc, sprintf_2_c);
  tcase_add_test(tc, sprintf_3_c);
  tcase_add_test(tc, sprintf_4_c);
  tcase_add_test(tc, sprintf_5_c);
  tcase_add_test(tc, sprintf_6_c);
  tcase_add_test(tc, sprintf_7_c);
  tcase_add_test(tc, sprintf_8_c);
  tcase_add_test(tc, sprintf_9_c);
  tcase_add_test(tc, sprintf_10_c);
  tcase_add_test(tc, sprintf_11_c);
  tcase_add_test(tc, sprintf_12_c);
  tcase_add_test(tc, sprintf_13_c);
  tcase_add_test(tc, sprintf_14_c);
  tcase_add_test(tc, sprintf_15_c);
  tcase_add_test(tc, sprintf_16_c);
  tcase_add_test(tc, sprintf_17_c);
  tcase_add_test(tc, sprintf_18_c);
  tcase_add_test(tc, sprintf_19_c);
  tcase_add_test(tc, sprintf_20_c);
  tcase_add_test(tc, sprintf_21_c);

  suite_add_tcase(s, tc);
  return s;
}
