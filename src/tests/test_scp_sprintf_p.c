#include "test_scp_string.h"

START_TEST(sprintf_1_pointer) {
  char str1[100] = "";
  char str2[100] = "";
  char* str3 = "!%p!";
  char* val = "0p32";
  ck_assert_int_eq(sprintf(str1, str3, val), scp_sprintf(str2, str3, val));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_2_pointer) {
  char str1[100];
  char str2[100];
  char* str3 = "%p !%p !%p";
  char* val = "0p7a4";
  char* val2 = "0p91ba123f";
  char* val3 = "0p3123";
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3),
                   scp_sprintf(str2, str3, val, val2, val3));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_3_pointer) {
  char str1[100];
  char str2[100];
  char* str3 = "%p !%p !%p";
  char* val = "0p3015";
  char* val2 = "0p712";
  char* val3 = "0p99";
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3),
                   scp_sprintf(str2, str3, val, val2, val3));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_4_pointer) {
  char str1[100];
  char str2[100];
  char* str3 = "%p !%p !%p!%p";
  long int* val = (void*)3088675747373646;
  long long int* val2 = (void*)33030030303;
  unsigned short int* val3 = (void*)22600;
  unsigned char* val4 = (void*)120;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4),
                   scp_sprintf(str2, str3, val, val2, val3, val4));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_5_pointer) {
  char str1[100];
  char str2[100];
  char* str3 = "%3p !%5p !%12p";
  char* val = "3015";
  char* val2 = "01234";
  char* val3 = "99";
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3),
                   scp_sprintf(str2, str3, val, val2, val3));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_6_pointer) {
  char str1[200];
  char str2[200];
  char* str3 = "%6.5p !%.23p !%3.p !%.p";
  char* val = "3015";
  char* val2 = "712";
  char* val3 = "99";
  char* val4 = "38";
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4),
                   scp_sprintf(str2, str3, val, val2, val3, val4));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_7_pointer) {
  char str1[200];
  char str2[200];
  char* str3 = "%-10.5p !%-.4p !%-16p !%-.5p";
  char* val = "3015";
  char* val2 = "712";
  char* val3 = "99";
  char* val4 = "2939";
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4),
                   scp_sprintf(str2, str3, val, val2, val3, val4));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_8_pointer) {
  char str1[200];
  char str2[200];
  char* str3 = "%0p !%0.p !%0.0p !%0p!%.p";
  char* val = "3015";
  char* val2 = "712";
  char* val3 = "99";
  char* val4 = "2939";
  char* val5 = "0123";
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4, val5),
                   scp_sprintf(str2, str3, val, val2, val3, val4, val5));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_9_pointer) {
  char str1[200];
  char str2[200];
  char* str3 = "%+p !%+3.p !%+5.7p !%+10p";
  char* val = "3015";
  char* val2 = "712";
  char* val3 = "99";
  char* val4 = "2939";
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4),
                   scp_sprintf(str2, str3, val, val2, val3, val4));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_10_pointer) {
  char str1[200];
  char str2[200];
  char* str3 = "%p !%3.p !%5.7p !%10p %#p %-p %+p %.p % .p";
  char* val = 0;
  ck_assert_int_eq(
      sprintf(str1, str3, val, val, val, val, val, val, val, val, val),
      scp_sprintf(str2, str3, val, val, val, val, val, val, val, val, val));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_11_pointer) {
  char str1[200];
  char str2[200];
  char* str3 = "% p !% 3.p !% 5.7p !% 10p!%.p";
  char* val = "32";
  char* val2 = "8899";
  char* val3 = "91918";
  char* val4 = "32311";
  char* val5 = "23";
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4, val5),
                   scp_sprintf(str2, str3, val, val2, val3, val4, val5));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_12_pointer) {
  char str1[200];
  char str2[200];
  char* str3 = "%+p !%+3.p !%+5.7p !%+10p!%+.p";
  char* val = "32";
  char* val2 = "8899";
  char* val3 = "91918";
  char* val4 = "32311";
  char* val5 = "3261";
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4, val5),
                   scp_sprintf(str2, str3, val, val2, val3, val4, val5));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_13_pointer) {
  char str1[200];
  char str2[200];
  char* str3 = "%#p !%#3p !%#5.7p !%#.7p ! %#.p";
  char* val = "32";
  char* val2 = "8899";
  char* val3 = "91918";
  char* val4 = "32311";
  char* val5 = "8894";
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4, val5),
                   scp_sprintf(str2, str3, val, val2, val3, val4, val5));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_14_pointer) {
  char str1[200];
  char str2[200];
  char* str3 = "%0p !%06p !%05.7p !%0.7p ! %0.p";
  char* val = "32";
  char* val2 = "8899";
  char* val3 = "91918";
  char* val4 = "32311";
  char* val5 = "8894";
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4, val5),
                   scp_sprintf(str2, str3, val, val2, val3, val4, val5));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_15_pointer) {
  char str1[200];
  char str2[200];
  char* str3 = "%*p !%-*p !%*.*p !%.*p!%.*p";
  char* val = "32";
  char* val2 = "8899";
  char* val3 = "9193112312312";
  char* val4 = "32311";
  char* val5 = "WTF cmon";
  int ast = 2;
  int ast2 = 5;
  int ast3 = 4;
  int ast4 = 10;
  int ast5 = 7;
  int ast6 = 18;
  ck_assert_int_eq(sprintf(str1, str3, ast, val, ast2, val2, ast3, ast4, val3,
                           ast5, val4, ast6, val5),
                   scp_sprintf(str2, str3, ast, val, ast2, val2, ast3, ast4,
                               val3, ast5, val4, ast6, val5));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_16_pointer) {
  char str1[100] = "";
  char str2[100] = "";
  char* str3 = "!%-10p!";
  char* val = 0;
  ck_assert_int_eq(sprintf(str1, str3, val), scp_sprintf(str2, str3, val));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

Suite* test_sprintf_p(void) {
  Suite* s = suite_create("\033[33m-=scp_sprintf_p=-\033[0m");
  TCase* tc = tcase_create("sprintf_tc");

  tcase_add_test(tc, sprintf_1_pointer);
  tcase_add_test(tc, sprintf_2_pointer);
  tcase_add_test(tc, sprintf_3_pointer);
  tcase_add_test(tc, sprintf_4_pointer);
  tcase_add_test(tc, sprintf_5_pointer);
  tcase_add_test(tc, sprintf_6_pointer);
  tcase_add_test(tc, sprintf_7_pointer);
  tcase_add_test(tc, sprintf_8_pointer);
  tcase_add_test(tc, sprintf_9_pointer);
  tcase_add_test(tc, sprintf_10_pointer);
  tcase_add_test(tc, sprintf_11_pointer);
  tcase_add_test(tc, sprintf_12_pointer);
  tcase_add_test(tc, sprintf_13_pointer);
  tcase_add_test(tc, sprintf_14_pointer);
  tcase_add_test(tc, sprintf_15_pointer);
  tcase_add_test(tc, sprintf_16_pointer);

  suite_add_tcase(s, tc);
  return s;
}
