#include "test_scp_string.h"

START_TEST(sprintf_1_o) {
  char str1[100] = "";
  char str2[100] = "";
  char *str3 = "!%o!";
  int val = 012;
  ck_assert_int_eq(sprintf(str1, str3, val), scp_sprintf(str2, str3, val));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_2_o) {
  char str1[100];
  char str2[100];
  char *str3 = "%o !%o !%o";
  int val = 012;
  int val2 = 017;
  int val3 = 07464;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3),
                   scp_sprintf(str2, str3, val, val2, val3));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_3_o) {
  char str1[100];
  char str2[100];
  char *str3 = "%o !%o !%o";
  int val = 3015;
  int val2 = 712;
  int val3 = 99;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3),
                   scp_sprintf(str2, str3, val, val2, val3));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_4_o) {
  char str1[100];
  char str2[100];
  char *str3 = "%lo !%lo !%ho ! %ho";
  long int val = 3088675747373646;
  unsigned long int val2 = 33030030303;
  unsigned short int val3 = 22600;
  unsigned short val4 = 120;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4),
                   scp_sprintf(str2, str3, val, val2, val3, val4));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_5_o) {
  char str1[100];
  char str2[100];
  char *str3 = "%3o !%5o !%10o";
  int val = 3015;
  int val2 = 01234;
  int val3 = 99;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3),
                   scp_sprintf(str2, str3, val, val2, val3));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_6_o) {
  char str1[200];
  char str2[200];
  char *str3 = "%6.5o !%.23o !%3.o !%.o";
  int val = 3015;
  int val2 = 712;
  int val3 = 99;
  int val4 = 38;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4),
                   scp_sprintf(str2, str3, val, val2, val3, val4));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_7_o) {
  char str1[200];
  char str2[200];
  char *str3 = "%-10.5o !%-.8o !%-7o !%-.o";
  int val = 3015;
  int val2 = 712;
  int val3 = 99;
  int val4 = 2939;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4),
                   scp_sprintf(str2, str3, val, val2, val3, val4));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_8_o) {
  char str1[200];
  char str2[200];
  char *str3 = "%0o !%0.o !%0.0o !%0o ! %.o";
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

START_TEST(sprintf_9_o) {
  char str1[200];
  char str2[200];
  char *str3 = "%+o !%+3.o !%+5.7o !%+10o";
  int val = 3015;
  int val2 = 712;
  int val3 = 99;
  int val4 = 2939;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4),
                   scp_sprintf(str2, str3, val, val2, val3, val4));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_10_o) {
  char str1[200];
  char str2[200];
  char *str3 = "%o !%3.o !%5.7o !%10o %#o %-o %+o %.o % .o";
  int val = 0;
  ck_assert_int_eq(
      sprintf(str1, str3, val, val, val, val, val, val, val, val, val),
      scp_sprintf(str2, str3, val, val, val, val, val, val, val, val, val));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_11_o) {
  char str1[200];
  char str2[200];
  char *str3 = "% o !% 3.o !% 5.7o !% 10o ! %.o";
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

START_TEST(sprintf_12_o) {
  char str1[200];
  char str2[200];
  char *str3 = "%+o !%+3.o !%+5.7o !%+10o ! %+.o";
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

START_TEST(sprintf_13_o) {
  char str1[200];
  char str2[200];
  char *str3 = "%#o !%#3o !%#5.7o !%#.7o ! %#.o";
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

START_TEST(sprintf_14_o) {
  char str1[200];
  char str2[200];
  char *str3 = "%0o !%06o !%05.7o !%0.7o ! %0.o";
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

START_TEST(sprintf_15_o) {
  char str1[200];
  char str2[200];
  char *str3 = "%*o !%-*o !%*.*o !%.*o";
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

START_TEST(sprintf_16_o) {
  char str1[100] = "";
  char str2[100] = "";
  char *str3 = "%o";
  int val = 012;
  ck_assert_int_eq(sprintf(str1, str3, val), scp_sprintf(str2, str3, val));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_17_o) {
  char str1[200];
  char str2[200];
  char *str3 = "%- o !%- 15o ! %- 15o ! %- o";
  int val = -3231;
  int val2 = -3231;
  int val3 = 3231;
  int val4 = 3231;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4),
                   scp_sprintf(str2, str3, val, val2, val3, val4));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_18_o) {
  char str1[200];
  char str2[200];
  char *str3 = "!! %lo";
  long int val = ULONG_MAX;
  ck_assert_int_eq(sprintf(str1, str3, val), scp_sprintf(str2, str3, val));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST
/*
START_TEST(sprintf_19_o) {
  char str1[400];
  char str2[400];
  char *str3 = "! %lo!";
  long double num = INFINITY;
  ck_assert_int_eq(sprintf(str1, str3, num), scp_sprintf(str2, str3, num));
  ck_assert_pstr_eq(str1, str2);
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_20_o) {
  char str1[400];
  char str2[400];
  char *str3 = "! %lo!";
  long double num = NAN;
  ck_assert_int_eq(sprintf(str1, str3, num),
                   scp_sprintf(str2, str3, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_21_o) {
  char str1[400];
  char str2[400];
  char *str3 = "! %lo!";
  long double num = -INFINITY;
  ck_assert_int_eq(sprintf(str1, str3, num), scp_sprintf(str2, str3, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST
*/
Suite *test_sprintf_o(void) {
  Suite *s = suite_create("\033[33m-=scp_sprintf_o=-\033[0m");
  TCase *tc = tcase_create("sprintf_tc");

  tcase_add_test(tc, sprintf_1_o);
  tcase_add_test(tc, sprintf_2_o);
  tcase_add_test(tc, sprintf_3_o);
  tcase_add_test(tc, sprintf_4_o);
  tcase_add_test(tc, sprintf_5_o);
  tcase_add_test(tc, sprintf_6_o);
  tcase_add_test(tc, sprintf_7_o);
  tcase_add_test(tc, sprintf_8_o);
  tcase_add_test(tc, sprintf_9_o);
  tcase_add_test(tc, sprintf_10_o);
  tcase_add_test(tc, sprintf_11_o);
  tcase_add_test(tc, sprintf_12_o);
  tcase_add_test(tc, sprintf_13_o);
  tcase_add_test(tc, sprintf_14_o);
  tcase_add_test(tc, sprintf_15_o);
  tcase_add_test(tc, sprintf_16_o);
  tcase_add_test(tc, sprintf_17_o);
  tcase_add_test(tc, sprintf_18_o);
  /*
  tcase_add_test(tc, sprintf_19_o);
  tcase_add_test(tc, sprintf_20_o);
  tcase_add_test(tc, sprintf_21_o);
*/
  suite_add_tcase(s, tc);
  return s;
}
