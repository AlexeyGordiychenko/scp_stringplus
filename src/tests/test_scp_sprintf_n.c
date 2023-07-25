#include "test_scp_string.h"

START_TEST(sprintf_1_n) {
  char str1[100] = "";
  char str2[100] = "";
  char *str3 = "prikol%nvnature";
  int valn1 = 0, valn2 = 0;
  ck_assert_int_eq(sprintf(str1, str3, &valn1),
                   scp_sprintf(str2, str3, &valn2));
  ck_assert_pstr_eq(str1, str2);
  ck_assert_int_eq(valn1, valn2);
}
END_TEST

START_TEST(sprintf_2_n) {
  char str1[100];
  char str2[100];
  char *str3 = "prikolT%n!!!%n";
  int valn1 = 0, valn2 = 0, valn3 = 0, valn4 = 0;
  ck_assert_int_eq(sprintf(str1, str3, &valn1, &valn3),
                   scp_sprintf(str2, str3, &valn2, &valn4));
  ck_assert_pstr_eq(str1, str2);
  ck_assert_int_eq(valn1, valn2);
  ck_assert_int_eq(valn3, valn4);
}
END_TEST

START_TEST(sprintf_3_n) {
  char str1[100];
  char str2[100];
  char *str3 = "%d prikol%d!!%-+#n!!!%d";
  int val = 3015;
  int val2 = 712;
  int val3 = 99;
  int valn1 = 0, valn2 = 0;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, &valn1, val3),
                   scp_sprintf(str2, str3, val, val2, &valn2, val3));
  ck_assert_pstr_eq(str1, str2);
  ck_assert_int_eq(valn1, valn2);
}
END_TEST

START_TEST(sprintf_4_n) {
  char str1[100];
  char str2[100];
  char *str3 = "%d prikol%d prikol%d%34.23n";
  long int val = 308;
  unsigned long int val2 = 303;
  unsigned short int val3 = 600;
  int valn1 = 0, valn2 = 0;

  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, &valn1),
                   scp_sprintf(str2, str3, val, val2, val3, &valn2));
  ck_assert_pstr_eq(str1, str2);
  ck_assert_int_eq(valn1, valn2);
}
END_TEST

Suite *test_sprintf_n(void) {
  Suite *s = suite_create("\033[33m-=scp_sprintf_n=-\033[0m");
  TCase *tc = tcase_create("sprintf_tc");

  tcase_add_test(tc, sprintf_1_n);
  tcase_add_test(tc, sprintf_2_n);
  tcase_add_test(tc, sprintf_3_n);
  tcase_add_test(tc, sprintf_4_n);

  suite_add_tcase(s, tc);
  return s;
}
