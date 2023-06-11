#include "test_s21_string.h"

START_TEST(sscanf_inc_1) {
  char format[] = "%d";
  char str[] = "";
  int v1 = 0, v2 = 0;

  int16_t res1 = s21_sscanf(str, format, &v1);
  int16_t res2 = sscanf(str, format, &v2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sscanf_inc_2) {
  char format[] = "%d";
  char str[] = "     ";
  int v1 = 0, v2 = 0;

  int16_t res1 = s21_sscanf(str, format, &v1);
  int16_t res2 = sscanf(str, format, &v2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sscanf_inc_3) {
  char format[] = "%d";
  char str[] = "\n";
  int v1 = 0, v2 = 0;

  int16_t res1 = s21_sscanf(str, format, &v1);
  int16_t res2 = sscanf(str, format, &v2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sscanf_inc_4) {
  char format[] = "%d";
  char str[] = "\t";
  int v1 = 0, v2 = 0;

  int16_t res1 = s21_sscanf(str, format, &v1);
  int16_t res2 = sscanf(str, format, &v2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sscanf_inc_5) {
  char format[] = "%d";
  char str[] = "\t\n\n   \n  \t";
  int v1 = 0, v2 = 0;

  int16_t res1 = s21_sscanf(str, format, &v1);
  int16_t res2 = sscanf(str, format, &v2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sscanf_inc_6) {
  char format[] = "";
  char str[] = "\t\n\n   \n  \t";
  int v1 = 0, v2 = 0;

  int16_t res1 = s21_sscanf(str, format, &v1);
  int16_t res2 = sscanf(str, format, &v2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sscanf_inc_7) {
  char format[] = "\t";
  char str[] = "\t\n\n   \n  \t";
  int v1 = 0, v2 = 0;

  int16_t res1 = s21_sscanf(str, format, &v1);
  int16_t res2 = sscanf(str, format, &v2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sscanf_inc_8) {
  char format[] = "%q";
  char str[] = "wwerw";
  int v1 = 0, v2 = 0;

  int16_t res1 = s21_sscanf(str, format, &v1);
  int16_t res2 = sscanf(str, format, &v2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sscanf_inc_9) {
  char format[] = "%10hq";
  char str[] = "werwer";
  int v1 = 0, v2 = 0;

  int16_t res1 = s21_sscanf(str, format, &v1);
  int16_t res2 = sscanf(str, format, &v2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

Suite *test_sscanf_inc(void) {
  Suite *s = suite_create("\033[33m-=s21_sscanf_incorrect=-\033[0m");

  TCase *tc = tcase_create("sscanf_tc");

  tcase_add_test(tc, sscanf_inc_1);
  tcase_add_test(tc, sscanf_inc_2);
  tcase_add_test(tc, sscanf_inc_3);
  tcase_add_test(tc, sscanf_inc_4);
  tcase_add_test(tc, sscanf_inc_5);
  tcase_add_test(tc, sscanf_inc_6);
  tcase_add_test(tc, sscanf_inc_7);
  tcase_add_test(tc, sscanf_inc_8);
  tcase_add_test(tc, sscanf_inc_9);

  suite_add_tcase(s, tc);
  return s;
}
