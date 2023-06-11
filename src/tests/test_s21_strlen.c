#include "test_s21_string.h"

START_TEST(strlen_1) {
  char str[] = "Param, taram!";
  ck_assert_int_eq(strlen(str), s21_strlen(str));
}
END_TEST

START_TEST(strlen_2) {
  char str[] =
      "213145346758697808-9704=3524-1309876289403-5=6576=432=-31044253=60931 "
      "21";
  ck_assert_int_eq(strlen(str), s21_strlen(str));
}
END_TEST

START_TEST(strlen_3) {
  char str[] = "Param, taram!";
  ck_assert_int_eq(strlen(str), s21_strlen(str));
}
END_TEST

START_TEST(strlen_4) { ck_assert_int_eq(strlen("\0"), s21_strlen("\0")); }
END_TEST

START_TEST(strlen_5) {
  ck_assert_int_eq(
      strlen("Po plyam, po polyam, siniy traktor edet k nam!"),
      s21_strlen("Po plyam, po polyam, siniy traktor edet k nam!"));
}
END_TEST

START_TEST(strlen_6) { ck_assert_int_eq(strlen(""), s21_strlen("")); }
END_TEST

START_TEST(strlen_7) {
  ck_assert_int_eq(
      strlen("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890"),
      s21_strlen(
          "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890"));
}
END_TEST

START_TEST(strlen_8) {
  ck_assert_int_eq(strlen("          00000000           ......  "),
                   s21_strlen("          00000000           ......  "));
}
END_TEST

START_TEST(strlen_9) {
  ck_assert_int_eq(strlen("\n\n\n\n\n\n\n\n\nparam\n\n\n\n\n"),
                   s21_strlen("\n\n\n\n\n\n\n\n\nparam\n\n\n\n\n"));
}
END_TEST

START_TEST(strlen_10) {
  ck_assert_int_eq(strlen("\0\0\0\0\n"), s21_strlen("\0\0\0\0\n"));
}
END_TEST

START_TEST(strlen_11) { ck_assert_int_eq(strlen(""), s21_strlen("")); }
END_TEST

START_TEST(strlen_12) { ck_assert_int_eq(strlen("\t\t"), s21_strlen("\t\t")); }
END_TEST

START_TEST(strlen_13) {
  ck_assert_int_eq(strlen("\0elidacon"), s21_strlen("\0elidacon"));
}
END_TEST

START_TEST(strlen_14) {
  ck_assert_int_eq(strlen("peace \0 peace"), s21_strlen("peace \0 peace"));
}
END_TEST

Suite *test_strlen(void) {
  Suite *s = suite_create("\033[33m-=s21_strlen=-\033[0m");
  TCase *tc = tcase_create("strlen_tc");

  tcase_add_test(tc, strlen_1);
  tcase_add_test(tc, strlen_2);
  tcase_add_test(tc, strlen_3);
  tcase_add_test(tc, strlen_4);
  tcase_add_test(tc, strlen_5);
  tcase_add_test(tc, strlen_6);
  tcase_add_test(tc, strlen_7);
  tcase_add_test(tc, strlen_8);
  tcase_add_test(tc, strlen_9);
  tcase_add_test(tc, strlen_10);
  tcase_add_test(tc, strlen_11);
  tcase_add_test(tc, strlen_12);
  tcase_add_test(tc, strlen_13);
  tcase_add_test(tc, strlen_14);

  suite_add_tcase(s, tc);
  return s;
}
