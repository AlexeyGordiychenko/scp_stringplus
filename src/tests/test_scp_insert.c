#include "test_scp_string.h"

START_TEST(test_insert_1) {
  char s1[30] = "tadam, param!";
  char s3[] = "TADAM, PARAM!";
  char s4[] = "tadam, TADAM, PARAM!param!";
  scp_size_t num = 7;
  char *s2 = scp_insert(s1, s3, num);
  ck_assert_pstr_eq(s4, s2);
  if (s2) free(s2);
}
END_TEST

START_TEST(test_insert_2) {
  char s1[30] = "";
  char s3[] = "";
  char *s4 = SCP_NULL;
  scp_size_t num = 7;
  char *s2 = scp_insert(s1, s3, num);
  ck_assert_pstr_eq(s4, s2);
  if (s2) free(s2);
}
END_TEST

START_TEST(test_insert_3) {
  char *s1 = SCP_NULL;
  char s3[] = "";
  char *s4 = SCP_NULL;
  scp_size_t num = 0;
  char *s2 = scp_insert(s1, s3, num);
  ck_assert_pstr_eq(s4, s2);
  if (s2) free(s2);
}
END_TEST

START_TEST(test_insert_4) {
  char s1[30] = "abcdefghij";
  char s3[] = "...RUSSIAN...'";
  char s4[] = "abc...RUSSIAN...'defghij";
  scp_size_t num = 3;
  char *s2 = scp_insert(s1, s3, num);
  ck_assert_pstr_eq(s4, s2);
  if (s2) free(s2);
}
END_TEST

START_TEST(test_insert_5) {
  char s1[30] = "abc";
  char s3[] = "666";
  char *s4 = SCP_NULL;
  scp_size_t num = 10;
  char *s2 = scp_insert(s1, s3, num);
  ck_assert_pstr_eq(s4, s2);
  if (s2) free(s2);
}
END_TEST

START_TEST(test_insert_6) {
  char s1[30] = "tadam, param!";
  char s3[] = "TADAM, PARAM!";
  char *s4 = SCP_NULL;
  scp_size_t num = -1;
  char *s2 = scp_insert(s1, s3, num);
  ck_assert_pstr_eq(s4, s2);
  if (s2) free(s2);
}
END_TEST

START_TEST(test_insert_7) {
  char *s1 = SCP_NULL;
  char *s3 = SCP_NULL;
  char *s4 = SCP_NULL;
  scp_size_t num = 0;
  char *s2 = scp_insert(s1, s3, num);
  ck_assert_pstr_eq(s4, s2);
  if (s2) free(s2);
}
END_TEST

START_TEST(test_insert_8) {
  char s1[30] = "";
  char s3[] = "";
  char s4[] = "";
  scp_size_t num = 0;
  char *s2 = scp_insert(s1, s3, num);
  ck_assert_pstr_eq(s4, s2);
  if (s2) free(s2);
}
END_TEST

START_TEST(test_insert_9) {
  char s1[] = "hi!";
  char *s3 = SCP_NULL;
  char *s4 = SCP_NULL;
  scp_size_t num = 0;
  char *s2 = scp_insert(s1, s3, num);
  ck_assert_pstr_eq(s4, s2);
  if (s2) free(s2);
}
END_TEST

START_TEST(test_insert_10) {
  char s1[] = "";
  char *s3 = SCP_NULL;
  char *s4 = SCP_NULL;
  scp_size_t num = 0;
  char *s2 = scp_insert(s1, s3, num);
  ck_assert_pstr_eq(s2, s4);
  if (s2) free(s2);
}
END_TEST

Suite *test_insert(void) {
  Suite *s = suite_create("\033[33m-=scp_insert=-\033[0m");
  TCase *tc = tcase_create("insert_tc");

  tcase_add_test(tc, test_insert_1);
  tcase_add_test(tc, test_insert_2);
  tcase_add_test(tc, test_insert_3);
  tcase_add_test(tc, test_insert_4);
  tcase_add_test(tc, test_insert_5);
  tcase_add_test(tc, test_insert_6);
  tcase_add_test(tc, test_insert_7);
  tcase_add_test(tc, test_insert_8);
  tcase_add_test(tc, test_insert_9);
  tcase_add_test(tc, test_insert_10);

  suite_add_tcase(s, tc);
  return s;
}
