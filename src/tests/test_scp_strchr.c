#include "test_scp_string.h"

START_TEST(strchr_1) {
  char s[] = "Param, taram!";
  int ch = 'h';
  ck_assert_pstr_eq(strchr(s, ch), scp_strchr(s, ch));
}
END_TEST

START_TEST(strchr_2) {
  char s[] = "Param, taram!";
  int ch = '\0';
  ck_assert_pstr_eq(strchr(s, ch), scp_strchr(s, ch));
}
END_TEST

START_TEST(strchr_3) {
  char s[] = "Param, taram!";
  int ch = ',';
  ck_assert_pstr_eq(strchr(s, ch), scp_strchr(s, ch));
}
END_TEST

START_TEST(strchr_4) {
  char s[] = "Param, taram!";
  int ch = 33;
  ck_assert_pstr_eq(strchr(s, ch), scp_strchr(s, ch));
}
END_TEST

START_TEST(strchr_5) {
  char s[] = "Param, Polina!";
  int ch = 'P';
  ck_assert_pstr_eq(strchr(s, ch), scp_strchr(s, ch));
}
END_TEST

START_TEST(strchr_6) {
  char s[] = "Param, taram!";
  int ch = 'w';
  ck_assert_pstr_eq(strchr(s, ch), scp_strchr(s, ch));
}
END_TEST

START_TEST(strchr_7) {
  char s[] = "Param, taram!";
  int ch = '0';
  ck_assert_pstr_eq(strchr(s, ch), scp_strchr(s, ch));
}
END_TEST

START_TEST(strchr_8) {
  char s[] = "Param, taram!";
  int ch = 'm';
  ck_assert_pstr_eq(strchr(s, ch), scp_strchr(s, ch));
}
END_TEST

Suite *test_strchr(void) {
  Suite *s = suite_create("\033[33m-=scp_strchr=-\033[0m");
  TCase *tc = tcase_create("strchr_tc");

  suite_add_tcase(s, tc);
  tcase_add_test(tc, strchr_1);
  tcase_add_test(tc, strchr_2);
  tcase_add_test(tc, strchr_3);
  tcase_add_test(tc, strchr_4);
  tcase_add_test(tc, strchr_5);
  tcase_add_test(tc, strchr_6);
  tcase_add_test(tc, strchr_7);
  tcase_add_test(tc, strchr_8);

  suite_add_tcase(s, tc);
  return s;
}
