#include "test_scp_string.h"

START_TEST(sprintf_1_u) {
  char str1[100] = "";
  char str2[100] = "";
  char *str3 = "!%u!";
  unsigned int val = 012;
  ck_assert_int_eq(sprintf(str1, str3, val), scp_sprintf(str2, str3, val));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_2_u) {
  char str1[100];
  char str2[100];
  char *str3 = "%u !%u !%u";
  unsigned int val = 012;
  unsigned int val2 = 017;
  unsigned int val3 = 07464;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3),
                   scp_sprintf(str2, str3, val, val2, val3));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_3_u) {
  char str1[100];
  char str2[100];
  char *str3 = "%u !%u !%u";
  unsigned int val = 3015;
  unsigned int val2 = 712;
  unsigned int val3 = 99;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3),
                   scp_sprintf(str2, str3, val, val2, val3));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_4_u) {
  char str1[100];
  char str2[100];
  char *str3 = "%lu !%lu !%hu!%hu";
  long unsigned int val = 3088675747373646;
  long unsigned val2 = 33030030303;
  unsigned short val3 = 22600;
  unsigned short val4 = 120;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4),
                   scp_sprintf(str2, str3, val, val2, val3, val4));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_5_u) {
  char str1[100];
  char str2[100];
  char *str3 = "%3u !%5u !%10u";
  unsigned int val = 3015;
  unsigned int val2 = 01234;
  unsigned int val3 = 99;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3),
                   scp_sprintf(str2, str3, val, val2, val3));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_6_u) {
  char str1[200];
  char str2[200];
  char *str3 = "%6.5u !%.23u !%3.u !%.u";
  unsigned int val = 3015;
  unsigned int val2 = 712;
  unsigned int val3 = 99;
  unsigned int val4 = 38;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4),
                   scp_sprintf(str2, str3, val, val2, val3, val4));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_7_u) {
  char str1[200];
  char str2[200];
  char *str3 = "%-10.5u !%-.8u !%-7u !%-.u";
  unsigned int val = 3015;
  unsigned int val2 = 712;
  unsigned int val3 = 99;
  unsigned int val4 = 2939;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4),
                   scp_sprintf(str2, str3, val, val2, val3, val4));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_8_u) {
  char str1[200];
  char str2[200];
  char *str3 = "%0u !%0.u !%0.0u !%0u!%.u";
  unsigned int val = 3015;
  unsigned int val2 = 712;
  unsigned int val3 = 99;
  unsigned int val4 = 2939;
  unsigned int val5 = 0123;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4, val5),
                   scp_sprintf(str2, str3, val, val2, val3, val4, val5));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_9_u) {
  char str1[200];
  char str2[200];
  char *str3 = "%+u !%+3.u !%+5.7u !%+10u";
  unsigned int val = 3015;
  unsigned int val2 = 712;
  unsigned int val3 = 99;
  unsigned int val4 = 2939;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4),
                   scp_sprintf(str2, str3, val, val2, val3, val4));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_10_u) {
  char str1[200];
  char str2[200];
  char *str3 = "%u !%3.u !%5.7u !%10u %#u %-u %+u %.u % .u";
  unsigned int val = 0;
  sprintf(str1, str3, val, val, val, val, val, val, val, val, val);
  scp_sprintf(str2, str3, val, val, val, val, val, val, val, val, val);
  ck_assert_int_eq(
      sprintf(str1, str3, val, val, val, val, val, val, val, val, val),
      scp_sprintf(str2, str3, val, val, val, val, val, val, val, val, val));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_11_u) {
  char str1[200];
  char str2[200];
  char *str3 = "% u !% 3.u !% 5.7u !% 10u!%.u";
  unsigned int val = 32;
  unsigned int val2 = 8899;
  unsigned int val3 = 91918;
  unsigned int val4 = 32311;
  unsigned int val5 = 23;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4, val5),
                   scp_sprintf(str2, str3, val, val2, val3, val4, val5));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_12_u) {
  char str1[200];
  char str2[200];
  char *str3 = "%+u !%+3.u !%+5.7u !%+10u!%+.u";
  unsigned int val = 32;
  unsigned int val2 = 8899;
  unsigned int val3 = 91918;
  unsigned int val4 = 32311;
  unsigned int val5 = 3261;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4, val5),
                   scp_sprintf(str2, str3, val, val2, val3, val4, val5));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_13_u) {
  char str1[200];
  char str2[200];
  char *str3 = "%#u !%#3u !%#5.7u !%#.7u!%#.u";
  unsigned int val = 32;
  unsigned int val2 = 8899;
  unsigned int val3 = 91918;
  unsigned int val4 = 32311;
  unsigned int val5 = 8894;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4, val5),
                   scp_sprintf(str2, str3, val, val2, val3, val4, val5));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_14_u) {
  char str1[200];
  char str2[200];
  char *str3 = "%0u !%06u !%05.7u !%0.7u!%0.u";
  unsigned int val = 32;
  unsigned int val2 = 8899;
  unsigned int val3 = 91918;
  unsigned int val4 = 32311;
  unsigned int val5 = 8894;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4, val5),
                   scp_sprintf(str2, str3, val, val2, val3, val4, val5));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_15_u) {
  char str1[200];
  char str2[200];
  char *str3 = "%*u !%-*u !%*.*u !%.*u";
  unsigned int val = 32;
  unsigned int val2 = 8899;
  unsigned int val3 = 919;
  unsigned int val4 = 32311;
  unsigned int ast = 2;
  unsigned int ast2 = 5;
  unsigned int ast3 = 4;
  unsigned int ast4 = 10;
  unsigned int ast5 = 7;
  ck_assert_int_eq(
      sprintf(str1, str3, ast, val, ast2, val2, ast3, ast4, val3, ast5, val4),
      scp_sprintf(str2, str3, ast, val, ast2, val2, ast3, ast4, val3, ast5,
                  val4));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_16_u) {
  char str1[200];
  char str2[200];
  char *str3 = "!%lu";
  unsigned long int val = ULONG_MAX;
  ck_assert_int_eq(sprintf(str1, str3, val), scp_sprintf(str2, str3, val));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_17_u) {
  char str1[200];
  char str2[200];
  char *str3 = "%- u !%- 15u!%- 15u ! %- u";
  unsigned int val = -3231;
  unsigned int val2 = -3231;
  unsigned int val3 = 3231;
  unsigned int val4 = 3231;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4),
                   scp_sprintf(str2, str3, val, val2, val3, val4));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST
/*
START_TEST(sprintf_18_u) {
  char str1[400];
  char str2[400];
  char *str3 = "!%lu!";
  long double num = INFINITY;
  ck_assert_int_eq(sprintf(str1, str3, num), scp_sprintf(str2, str3, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_19_u) {
  char str1[400];
  char str2[400];
  char *str3 = "!%lu!";
  long double num = NAN;
  ck_assert_int_eq(sprintf(str1, str3, num), scp_sprintf(str2, str3, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_20_u) {
  char str1[400];
  char str2[400];
  char *str3 = "!%lu!";
  long double num = -INFINITY;
  ck_assert_int_eq(sprintf(str1, str3, num), scp_sprintf(str2, str3, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST
*/
Suite *test_sprintf_u(void) {
  Suite *s = suite_create("\033[33m-=scp_sprintf_u=-\033[0m");
  TCase *tc = tcase_create("sprintf_tc");

  tcase_add_test(tc, sprintf_1_u);
  tcase_add_test(tc, sprintf_2_u);
  tcase_add_test(tc, sprintf_3_u);
  tcase_add_test(tc, sprintf_4_u);
  tcase_add_test(tc, sprintf_5_u);
  tcase_add_test(tc, sprintf_6_u);
  tcase_add_test(tc, sprintf_7_u);
  tcase_add_test(tc, sprintf_8_u);
  tcase_add_test(tc, sprintf_9_u);
  tcase_add_test(tc, sprintf_10_u);
  tcase_add_test(tc, sprintf_11_u);
  tcase_add_test(tc, sprintf_12_u);
  tcase_add_test(tc, sprintf_13_u);
  tcase_add_test(tc, sprintf_14_u);
  tcase_add_test(tc, sprintf_15_u);
  tcase_add_test(tc, sprintf_16_u);
  tcase_add_test(tc, sprintf_17_u);
  /*
  tcase_add_test(tc, sprintf_18_u);
  tcase_add_test(tc, sprintf_19_u);
  tcase_add_test(tc, sprintf_20_u);
*/
  suite_add_tcase(s, tc);
  return s;
}
