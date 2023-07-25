#include "test_scp_string.h"

START_TEST(sprintf_1_X2) {
  char str1[100] = "";
  char str2[100] = "";
  char *str3 = "!%X!";
  int val = 0X32;
  ck_assert_int_eq(sprintf(str1, str3, val), scp_sprintf(str2, str3, val));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_2_X2) {
  char str1[100];
  char str2[100];
  char *str3 = "%X!%X!%X";
  int val = 0X7a4;
  int val2 = 0X9112312f;
  int val3 = 0X3123;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3),
                   scp_sprintf(str2, str3, val, val2, val3));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_3_X2) {
  char str1[100];
  char str2[100];
  char *str3 = "%X!%X!%X";
  int val = 0X3015;
  int val2 = 0X712;
  int val3 = 0X99;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3),
                   scp_sprintf(str2, str3, val, val2, val3));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_4_X2) {
  char str1[100];
  char str2[100];
  char *str3 = "%lX!%lX!%hX!%hX";
  unsigned long int val = 3088675747373646;
  unsigned long int val2 = 33030030303;
  unsigned short int val3 = 22600;
  unsigned short val4 = 120;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4),
                   scp_sprintf(str2, str3, val, val2, val3, val4));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_5_X2) {
  char str1[100];
  char str2[100];
  char *str3 = "%3X!%5X!%10X";
  int val = 3015;
  int val2 = 01234;
  int val3 = 99;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3),
                   scp_sprintf(str2, str3, val, val2, val3));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_6_X2) {
  char str1[200];
  char str2[200];
  char *str3 = "%6.5X!%.23X!%3.X!%.X";
  int val = 3015;
  int val2 = 712;
  int val3 = 99;
  int val4 = 38;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4),
                   scp_sprintf(str2, str3, val, val2, val3, val4));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_7_X2) {
  char str1[200];
  char str2[200];
  char *str3 = "%-10.5X!%-.8X!%-7X!%-.X";
  int val = 3015;
  int val2 = 712;
  int val3 = 99;
  int val4 = 2939;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4),
                   scp_sprintf(str2, str3, val, val2, val3, val4));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_8_X2) {
  char str1[200];
  char str2[200];
  char *str3 = "%0X!%0.X!%0.0X!%0X!%.X";
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

START_TEST(sprintf_9_X2) {
  char str1[200];
  char str2[200];
  char *str3 = "%+X!%+3.X!%+5.7X!%+10X";
  int val = 3015;
  int val2 = 712;
  int val3 = 99;
  int val4 = 2939;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4),
                   scp_sprintf(str2, str3, val, val2, val3, val4));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_10_X2) {
  char str1[200];
  char str2[200];
  char *str3 = "%X!%3.X!%5.7X!%10X %#X %-X %+X %.X % .X";
  int val = 0;
  ck_assert_int_eq(
      sprintf(str1, str3, val, val, val, val, val, val, val, val, val),
      scp_sprintf(str2, str3, val, val, val, val, val, val, val, val, val));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_11_X2) {
  char str1[200];
  char str2[200];
  char *str3 = "% X!% 3.X!% 5.7X!% 10X!%.X";
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

START_TEST(sprintf_12_X2) {
  char str1[200];
  char str2[200];
  char *str3 = "%+X!%+3.X!%+5.7X!%+10X!%+.X";
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

START_TEST(sprintf_13_X2) {
  char str1[200];
  char str2[200];
  char *str3 = "%#X!%#3X!%#5.7X!%#.7X!%#.X";
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

START_TEST(sprintf_14_X2) {
  char str1[200];
  char str2[200];
  char *str3 = "%0X!%06X!%05.7X!%0.7X!%0.X";
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

START_TEST(sprintf_15_X2) {
  char str1[200];
  char str2[200];
  char *str3 = "%*X!%-*X!%*.*X!%.*X";
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

START_TEST(sprintf_16_X2) {
  char str1[200];
  char str2[200];
  char *str3 = "%- X!%- 15X!%- 15X!%- X";
  int val = -3231;
  int val2 = -3231;
  int val3 = 3231;
  int val4 = 3231;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4),
                   scp_sprintf(str2, str3, val, val2, val3, val4));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

Suite *test_sprintf_x2(void) {
  Suite *s = suite_create("\033[33m-=scp_sprintf_x2=-\033[0m");
  TCase *tc = tcase_create("sprintf_tc");

  tcase_add_test(tc, sprintf_1_X2);
  tcase_add_test(tc, sprintf_2_X2);
  tcase_add_test(tc, sprintf_3_X2);
  tcase_add_test(tc, sprintf_4_X2);
  tcase_add_test(tc, sprintf_5_X2);
  tcase_add_test(tc, sprintf_6_X2);
  tcase_add_test(tc, sprintf_7_X2);
  tcase_add_test(tc, sprintf_8_X2);
  tcase_add_test(tc, sprintf_9_X2);
  tcase_add_test(tc, sprintf_10_X2);
  tcase_add_test(tc, sprintf_11_X2);
  tcase_add_test(tc, sprintf_12_X2);
  tcase_add_test(tc, sprintf_13_X2);
  tcase_add_test(tc, sprintf_14_X2);
  tcase_add_test(tc, sprintf_15_X2);
  tcase_add_test(tc, sprintf_16_X2);

  suite_add_tcase(s, tc);
  return s;
}
