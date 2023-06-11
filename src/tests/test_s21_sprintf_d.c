#include "test_s21_string.h"

START_TEST(sprintf_1_d) {
  char str1[100] = "";
  char str2[100] = "";
  char *str3 = "malenaro %d malenaro";
  int val = -12;
  ck_assert_int_eq(sprintf(str1, str3, val), s21_sprintf(str2, str3, val));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_2_d) {
  char str1[100];
  char str2[100];
  char *str3 = "%d malenaro %d malenaro %d";
  int val = 012;
  int val2 = -017;
  int val3 = 07464;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3),
                   s21_sprintf(str2, str3, val, val2, val3));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_3_d) {
  char str1[100];
  char str2[100];
  char *str3 = "%d malenaro %d malenaro %d";
  int val = 3015;
  int val2 = 712;
  int val3 = 99;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3),
                   s21_sprintf(str2, str3, val, val2, val3));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_4_d) {
  char str1[100];
  char str2[100];
  char *str3 = "%ld malenaro %ld malenaro %hd malenaro %hd";
  long int val = 3088675747373646;
  long val2 = 33030030303;
  short int val3 = 22600;
  short val4 = -120;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4),
                   s21_sprintf(str2, str3, val, val2, val3, val4));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_5_d) {
  char str1[100];
  char str2[100];
  char *str3 = "%3d malenaro %5d malenaro %10d";
  int val = -3015;
  int val2 = -11234;
  int val3 = -99;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3),
                   s21_sprintf(str2, str3, val, val2, val3));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_6_d) {
  char str1[200];
  char str2[200];
  char *str3 = "%6.5d malenaro %.23d malenaro %3.d malenaro %.d %.6d";
  int val = -3015;
  int val2 = -712;
  int val3 = -99;
  int val4 = -38;
  int val5 = -100;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4, val5),
                   s21_sprintf(str2, str3, val, val2, val3, val4, val5));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_7_d) {
  char str1[200];
  char str2[200];
  char *str3 = "%-10.5d malenaro %-.8d malenaro %-7d malenaro %-.d";
  int val = -3015;
  int val2 = -712;
  int val3 = -99;
  int val4 = -2939;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4),
                   s21_sprintf(str2, str3, val, val2, val3, val4));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_8_d) {
  char str1[200];
  char str2[200];
  char *str3 = "%0d malenaro %0.d malenaro %0.0d malenaro %0d malenaro %.d";
  int val = -3015;
  int val2 = -712;
  int val3 = -99;
  int val4 = -2939;
  int val5 = -0123;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4, val5),
                   s21_sprintf(str2, str3, val, val2, val3, val4, val5));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_9_d) {
  char str1[200];
  char str2[200];
  char *str3 = "%+d malenaro %+3.d malenaro %+5.7d malenaro %+10d";
  int val = -3015;
  int val2 = -712;
  int val3 = -99;
  int val4 = -2939;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4),
                   s21_sprintf(str2, str3, val, val2, val3, val4));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_10_d) {
  char str1[200];
  char str2[200];
  char *str3 =
      "%d malenaro %3.d malenaro %5.7d malenaro %10d %#d %-d %+d %.d % .d";
  int val = 0;
  ck_assert_int_eq(
      sprintf(str1, str3, val, val, val, val, val, val, val, val, val),
      s21_sprintf(str2, str3, val, val, val, val, val, val, val, val, val,
                  val));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_11_d) {
  char str1[200];
  char str2[200];
  char *str3 = "% d malenaro % 3.d malenaro % 5.7d malenaro % 10d malenaro %.d";
  int val = -32;
  int val2 = -8899;
  int val3 = -91918;
  int val4 = -32311;
  int val5 = -23;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4, val5),
                   s21_sprintf(str2, str3, val, val2, val3, val4, val5));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_12_d) {
  char str1[200];
  char str2[200];
  char *str3 =
      "%+d malenaro %+3.d malenaro %+5.7d malenaro %+10d malenaro %+.d";
  int val = -32;
  int val2 = -8899;
  int val3 = 91918;
  int val4 = -32311;
  int val5 = 3261;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4, val5),
                   s21_sprintf(str2, str3, val, val2, val3, val4, val5));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_13_d) {
  char str1[200];
  char str2[200];
  char *str3 = "%#d malenaro %#3d malenaro %#5.7d malenaro %#.7d malenaro %#.d";
  int val = -32;
  int val2 = 8899;
  int val3 = -91918;
  int val4 = 32311;
  int val5 = -8894;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4, val5),
                   s21_sprintf(str2, str3, val, val2, val3, val4, val5));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_14_d) {
  char str1[200];
  char str2[200];
  char *str3 = "%0d malenaro %06d malenaro %05.7d malenaro %0.7d malenaro %0.d";
  int val = -32;
  int val2 = 8899;
  int val3 = -91918;
  int val4 = -32311;
  int val5 = -8894;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4, val5),
                   s21_sprintf(str2, str3, val, val2, val3, val4, val5));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_15_d) {
  char str1[200];
  char str2[200];
  char *str3 = "%*d malenaro %-*d malenaro %*.*d malenaro %.*d";
  int val = 32;
  int val2 = 8899;
  int val3 = -919;
  int val4 = 32311;
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

START_TEST(sprintf_16_d) {
  char str1[100] = "";
  char str2[100] = "";
  char *str3 = "%d";
  int val = 12;
  ck_assert_int_eq(sprintf(str1, str3, val), s21_sprintf(str2, str3, val));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_17_d) {
  char str1[1024] = "";
  char str2[1024] = "";
  int val = -75;
  sprintf(str1, "malenaro %d %023d", val, val);
  s21_sprintf(str2, "malenaro %d %023d", val, val);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_18_d) {
  char str1[300];
  char str2[300];
  char *str3 =
      "%ld malenaro %ld malenaro %hd malenaro %hd malenaro %d malenaro %d";
  long int val = LONG_MAX;
  long val2 = LONG_MIN;
  short int val3 = SHRT_MAX;
  short val4 = SHRT_MIN;
  int val5 = INT_MAX;
  int val6 = INT_MIN;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4, val5, val6),
                   s21_sprintf(str2, str3, val, val2, val3, val4, val5, val6));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_19_d) {
  char str1[200];
  char str2[200];
  char *str3 = "%- d malenaro %- 15d malenaro %- 15d malenaro %- d";
  int val = -3231;
  int val2 = -3231;
  int val3 = 3231;
  int val4 = 3231;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4),
                   s21_sprintf(str2, str3, val, val2, val3, val4));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_20_d) {
  char str1[400];
  char str2[400];
  char *str3 = "malenaro: %ld!\n";
  long double num = INFINITY;
  ck_assert_int_eq(sprintf(str1, str3, num), s21_sprintf(str2, str3, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_21_d) {
  char str1[400];
  char str2[400];
  char *str3 = "malenaro: %ld!";
  long double num = NAN;
  long double num1 = 1.;
  ck_assert_int_eq(sprintf(str1, str3, num, num1),
                   s21_sprintf(str2, str3, num, num1));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_22_d) {
  char str1[400];
  char str2[400];
  char *str3 = "test: %ld!\n";
  long double num = -INFINITY;
  ck_assert_int_eq(sprintf(str1, str3, num), s21_sprintf(str2, str3, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

Suite *test_sprintf_d(void) {
  Suite *s = suite_create("\033[33m-=s21_sprintf_d=-\033[0m");
  TCase *tc = tcase_create("sprintf_tc");

  tcase_add_test(tc, sprintf_1_d);
  tcase_add_test(tc, sprintf_2_d);
  tcase_add_test(tc, sprintf_3_d);
  tcase_add_test(tc, sprintf_4_d);
  tcase_add_test(tc, sprintf_5_d);
  tcase_add_test(tc, sprintf_6_d);
  tcase_add_test(tc, sprintf_7_d);
  tcase_add_test(tc, sprintf_8_d);
  tcase_add_test(tc, sprintf_9_d);
  tcase_add_test(tc, sprintf_10_d);
  tcase_add_test(tc, sprintf_11_d);
  tcase_add_test(tc, sprintf_12_d);
  tcase_add_test(tc, sprintf_13_d);
  tcase_add_test(tc, sprintf_14_d);
  tcase_add_test(tc, sprintf_15_d);
  tcase_add_test(tc, sprintf_16_d);
  tcase_add_test(tc, sprintf_17_d);
  tcase_add_test(tc, sprintf_18_d);
  tcase_add_test(tc, sprintf_19_d);
  tcase_add_test(tc, sprintf_20_d);
  tcase_add_test(tc, sprintf_21_d);
  tcase_add_test(tc, sprintf_22_d);

  suite_add_tcase(s, tc);
  return s;
}
