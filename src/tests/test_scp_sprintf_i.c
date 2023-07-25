#include "test_scp_string.h"

START_TEST(sprintf_1_i) {
  char str1[100] = "";
  char str2[100] = "";
  char *str3 = "!%d!";
  int val = -12;
  ck_assert_int_eq(sprintf(str1, str3, val), scp_sprintf(str2, str3, val));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_2_i) {
  char str1[100];
  char str2[100];
  char *str3 = "%d!%d!%d";
  int val = 012;
  int val2 = -017;
  int val3 = 07464;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3),
                   scp_sprintf(str2, str3, val, val2, val3));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_3_i) {
  char str1[100];
  char str2[100];
  char *str3 = "%i!%i!%i";
  int val = 3015;
  int val2 = 712;
  int val3 = 99;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3),
                   scp_sprintf(str2, str3, val, val2, val3));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_4_i) {
  char str1[100];
  char str2[100];
  char *str3 = "%li!%li!%hi!%hi";
  long int val = 3088675747373646;
  signed long val2 = -125;
  short int val3 = -22600;
  short val4 = 120;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4),
                   scp_sprintf(str2, str3, val, val2, val3, val4));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_5_i) {
  char str1[100];
  char str2[100];
  char *str3 = "%3i!%5i!%10i";
  int val = -3015;
  int val2 = -11234;
  int val3 = -99;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3),
                   scp_sprintf(str2, str3, val, val2, val3));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_6_i) {
  char str1[200];
  char str2[200];
  char *str3 = "%6.5i!%.23i!%3.i!%.i";
  int val = -3015;
  int val2 = -712;
  int val3 = -99;
  int val4 = -38;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4),
                   scp_sprintf(str2, str3, val, val2, val3, val4));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_7_i) {
  char str1[200];
  char str2[200];
  char *str3 = "%-10.5i!%-.8i!%-7i!%-.i";
  int val = -3015;
  int val2 = -712;
  int val3 = -99;
  int val4 = -2939;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4),
                   scp_sprintf(str2, str3, val, val2, val3, val4));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_8_i) {
  char str1[200];
  char str2[200];
  char *str3 = "%0i!%0.i!%0.0i!%0i!%.i";
  int val = -3015;
  int val2 = -712;
  int val3 = -99;
  int val4 = -2939;
  int val5 = -0123;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4, val5),
                   scp_sprintf(str2, str3, val, val2, val3, val4, val5));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_9_i) {
  char str1[200];
  char str2[200];
  char *str3 = "%+i!%+3.i!%+5.7i!%+10i";
  int val = -3015;
  int val2 = -712;
  int val3 = -99;
  int val4 = -2939;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4),
                   scp_sprintf(str2, str3, val, val2, val3, val4));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_10_i) {
  char str1[200];
  char str2[200];
  char *str3 = "%i!%3.i!%5.7i!%10i %#i %-i %+i %.i % .i";
  int val = 0;
  ck_assert_int_eq(
      sprintf(str1, str3, val, val, val, val, val, val, val, val, val),
      scp_sprintf(str2, str3, val, val, val, val, val, val, val, val, val,
                  val));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_11_i) {
  char str1[200];
  char str2[200];
  char *str3 = "% i!% 3.i!% 5.7i!% 10i!%.i";
  int val = -32;
  int val2 = -8899;
  int val3 = -91918;
  int val4 = -32311;
  int val5 = -23;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4, val5),
                   scp_sprintf(str2, str3, val, val2, val3, val4, val5));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_12_i) {
  char str1[200];
  char str2[200];
  char *str3 = "%+i!%+3.i!%+5.7i!%+10i!%+.i";
  int val = -32;
  int val2 = -8899;
  int val3 = 91918;
  int val4 = -32311;
  int val5 = 3261;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4, val5),
                   scp_sprintf(str2, str3, val, val2, val3, val4, val5));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_13_i) {
  char str1[200];
  char str2[200];
  char *str3 = "%#i!%#3i!%#5.7i!%#.7i!%#.i";
  int val = -32;
  int val2 = 8899;
  int val3 = -91918;
  int val4 = 32311;
  int val5 = -8894;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4, val5),
                   scp_sprintf(str2, str3, val, val2, val3, val4, val5));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_14_i) {
  char str1[200];
  char str2[200];
  char *str3 = "%0d!%06i!%05.7i!%0.7i!%0.i";
  int val = -32;
  int val2 = 8899;
  int val3 = -91918;
  int val4 = -32311;
  int val5 = -8894;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4, val5),
                   scp_sprintf(str2, str3, val, val2, val3, val4, val5));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_15_i) {
  char str1[200];
  char str2[200];
  char *str3 = "%*i!%-*i!%*.*i!%.*i";
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
      scp_sprintf(str2, str3, ast, val, ast2, val2, ast3, ast4, val3, ast5,
                  val4));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_16_i) {
  char str1[100] = "";
  char str2[100] = "";
  char *str3 = "%i";
  int val = 12;
  ck_assert_int_eq(sprintf(str1, str3, val), scp_sprintf(str2, str3, val));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_17_i) {
  char str1[200];
  char str2[200];
  char *str3 = "%- i!%- 15i!%- 15i!%- i";
  int val = -3231;
  int val2 = -3231;
  int val3 = 3231;
  int val4 = 3231;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4),
                   scp_sprintf(str2, str3, val, val2, val3, val4));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

Suite *test_sprintf_i(void) {
  Suite *s = suite_create("\033[33m-=scp_sprintf_i=-\033[0m");
  TCase *tc = tcase_create("sprintf_tc");

  tcase_add_test(tc, sprintf_1_i);
  tcase_add_test(tc, sprintf_2_i);
  tcase_add_test(tc, sprintf_3_i);
  tcase_add_test(tc, sprintf_4_i);
  tcase_add_test(tc, sprintf_5_i);
  tcase_add_test(tc, sprintf_6_i);
  tcase_add_test(tc, sprintf_7_i);
  tcase_add_test(tc, sprintf_8_i);
  tcase_add_test(tc, sprintf_9_i);
  tcase_add_test(tc, sprintf_10_i);
  tcase_add_test(tc, sprintf_11_i);
  tcase_add_test(tc, sprintf_12_i);
  tcase_add_test(tc, sprintf_13_i);
  tcase_add_test(tc, sprintf_14_i);
  tcase_add_test(tc, sprintf_15_i);
  tcase_add_test(tc, sprintf_16_i);
  tcase_add_test(tc, sprintf_17_i);

  suite_add_tcase(s, tc);
  return s;
}
