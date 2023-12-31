#include "test_scp_string.h"

START_TEST(sprintf_1_x1) {
  char str1[100] = "";
  char str2[100] = "";
  char *str3 = "!%x!";
  int val = 0x32;
  ck_assert_int_eq(sprintf(str1, str3, val), scp_sprintf(str2, str3, val));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_2_x1) {
  char str1[100];
  char str2[100];
  char *str3 = "%x!%x!%x";
  int val = 0x7a4;
  int val2 = 0x91ba123f;
  int val3 = 0x3123;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3),
                   scp_sprintf(str2, str3, val, val2, val3));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_3_x1) {
  char str1[100];
  char str2[100];
  char *str3 = "%x!%x!%x";
  int val = 0x3015;
  int val2 = 0x712;
  int val3 = 0x99;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3),
                   scp_sprintf(str2, str3, val, val2, val3));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_4_x1) {
  char str1[100];
  char str2[100];
  char *str3 = "%lx!%lx!%hx!%hx";
  long int val = 3088675747373646;
  long val2 = 33030030303;
  unsigned short int val3 = 22600;
  unsigned short val4 = 120;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4),
                   scp_sprintf(str2, str3, val, val2, val3, val4));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_5_x1) {
  char str1[100];
  char str2[100];
  char *str3 = "%3x!%5x!%10x";
  int val = 3015;
  int val2 = 01234;
  int val3 = 99;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3),
                   scp_sprintf(str2, str3, val, val2, val3));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_6_x1) {
  char str1[200];
  char str2[200];
  char *str3 = "%6.5x!%.23x!%3.x!%.x";
  int val = 3015;
  int val2 = 712;
  int val3 = 99;
  int val4 = 38;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4),
                   scp_sprintf(str2, str3, val, val2, val3, val4));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_7_x1) {
  char str1[200];
  char str2[200];
  char *str3 = "%-10.5x!%-.8x!%-7x!%-.x";
  int val = 3015;
  int val2 = 712;
  int val3 = 99;
  int val4 = 2939;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4),
                   scp_sprintf(str2, str3, val, val2, val3, val4));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_8_x1) {
  char str1[200];
  char str2[200];
  char *str3 = "%0x!%0.x!%0.0x!%0x!%.x";
  int val = 3015;
  int val2 = 712;
  int val3 = 99;
  int val4 = 2939;
  int val5 = 0123;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4, val5),
                   scp_sprintf(str2, str3, val, val2, val3, val4, val5));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_9_x1) {
  char str1[200];
  char str2[200];
  char *str3 = "%+x!%+3.x!%+5.7x!%+10x";
  int val = 3015;
  int val2 = 712;
  int val3 = 99;
  int val4 = 2939;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4),
                   scp_sprintf(str2, str3, val, val2, val3, val4));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_10_x1) {
  char str1[200];
  char str2[200];
  char *str3 = "%x!%3.x!%5.7x!%10x %#x %-x %+x %.x % .x";
  int val = 0;
  ck_assert_int_eq(
      sprintf(str1, str3, val, val, val, val, val, val, val, val, val),
      scp_sprintf(str2, str3, val, val, val, val, val, val, val, val, val));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_11_x1) {
  char str1[200];
  char str2[200];
  char *str3 = "% x!% 3.x!% 5.7x!% 10x!%.x";
  int val = 32;
  int val2 = 8899;
  int val3 = 91918;
  int val4 = 32311;
  int val5 = 23;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4, val5),
                   scp_sprintf(str2, str3, val, val2, val3, val4, val5));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_12_x1) {
  char str1[200];
  char str2[200];
  char *str3 = "%+x!%+3.x!%+5.7x!%+10x!%+.x";
  int val = 32;
  int val2 = 8899;
  int val3 = 91918;
  int val4 = 32311;
  int val5 = 3261;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4, val5),
                   scp_sprintf(str2, str3, val, val2, val3, val4, val5));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_13_x1) {
  char str1[200];
  char str2[200];
  char *str3 = "%#x!%#3x!%#5.7x!%#.7x!%#.x";
  int val = 32;
  int val2 = 8899;
  int val3 = 91918;
  int val4 = 32311;
  int val5 = 8894;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4, val5),
                   scp_sprintf(str2, str3, val, val2, val3, val4, val5));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_14_x1) {
  char str1[200];
  char str2[200];
  char *str3 = "%0x!%06x!%05.7x!%0.7x!%0.x";
  int val = 32;
  int val2 = 8899;
  int val3 = 91918;
  int val4 = 32311;
  int val5 = 8894;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4, val5),
                   scp_sprintf(str2, str3, val, val2, val3, val4, val5));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_15_x1) {
  char str1[200];
  char str2[200];
  char *str3 = "%*x!%-*x!%*.*x!%.*x";
  int val = 32;
  int val2 = 8899;
  int val3 = 919;
  int val4 = 32311;
  int ast = 2;
  int ast2 = 5;
  int ast3 = 4;
  int ast4 = 10;
  int ast5 = 7;
  ck_assert_int_eq(
      sprintf(str1, str3, ast, val, ast2, val2, ast3, ast4, val3, ast5, val4),
      scp_sprintf(str2, str3, ast, val, ast2, val2, ast3, ast4, val3, ast5,
                  val4));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_16_x1) {
  char str1[200];
  char str2[200];
  char *str3 = "%- x!%- 15x!%- 15x!%- x";
  int val = -3231;
  int val2 = -3231;
  int val3 = 3231;
  int val4 = 3231;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4),
                   scp_sprintf(str2, str3, val, val2, val3, val4));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_17_x1) {
  char str1[200];
  char str2[200];
  char *str3 = "!%lx";
  long int val = ULONG_MAX;
  ck_assert_int_eq(sprintf(str1, str3, val), scp_sprintf(str2, str3, val));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST
/*
START_TEST(sprintf_18_x1) {
  char str1[400];
  char str2[400];
  char *str3 = "!%lx!";
  long double num = INFINITY;
  ck_assert_int_eq(sprintf(str1, str3, num), scp_sprintf(str2, str3, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_19_x1) {
  char str1[400];
  char str2[400];
  char *str3 = "!%lx!";
  long double num = NAN;
  ck_assert_int_eq(sprintf(str1, str3, num),
                   scp_sprintf(str2, str3, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_20_x1) {
  char str1[400];
  char str2[400];
  char *str3 = "!%lx!";
  long double num = -INFINITY;
  ck_assert_int_eq(sprintf(str1, str3, num), scp_sprintf(str2, str3, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST
*/
Suite *test_sprintf_x1(void) {
  Suite *s = suite_create("\033[33m-=scp_sprintf_x1=-\033[0m");
  TCase *tc = tcase_create("sprintf_tc");

  tcase_add_test(tc, sprintf_1_x1);
  tcase_add_test(tc, sprintf_2_x1);
  tcase_add_test(tc, sprintf_3_x1);
  tcase_add_test(tc, sprintf_4_x1);
  tcase_add_test(tc, sprintf_5_x1);
  tcase_add_test(tc, sprintf_6_x1);
  tcase_add_test(tc, sprintf_7_x1);
  tcase_add_test(tc, sprintf_8_x1);
  tcase_add_test(tc, sprintf_9_x1);
  tcase_add_test(tc, sprintf_10_x1);
  tcase_add_test(tc, sprintf_11_x1);
  tcase_add_test(tc, sprintf_12_x1);
  tcase_add_test(tc, sprintf_13_x1);
  tcase_add_test(tc, sprintf_14_x1);
  tcase_add_test(tc, sprintf_15_x1);
  tcase_add_test(tc, sprintf_16_x1);
  tcase_add_test(tc, sprintf_17_x1);
  /*
  tcase_add_test(tc, sprintf_18_x1);
  tcase_add_test(tc, sprintf_19_x1);
  tcase_add_test(tc, sprintf_20_x1);
*/
  suite_add_tcase(s, tc);
  return s;
}
