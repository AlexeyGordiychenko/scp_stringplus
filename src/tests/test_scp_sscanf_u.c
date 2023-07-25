#include "test_scp_string.h"

START_TEST(sscanf_spec_hhu_1) {
  char format[] = "%hhu";
  char str[] = "123";
  unsigned char d1, d2;

  int16_t res1 = scp_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_spec_hhu_2) {
  char format[] = "%hhu";
  char str[] = "-123";
  unsigned char d1, d2;

  int16_t res1 = scp_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_spec_hhu_3) {
  char format[] = "%hhu";
  char str[] = "+123";
  unsigned char d1, d2;

  int16_t res1 = scp_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_spec_hhu_4) {
  char format[] = "%3hhu";
  char str[] = "-123";
  unsigned char d1, d2;

  int16_t res1 = scp_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_spec_hhu_5) {
  char format[] = "%4hhu";
  char str[] = "-123";
  unsigned char d1, d2;

  int16_t res1 = scp_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_spec_hhu_6) {
  char format[] = "%10hhu";
  char str[] = "-123";
  unsigned char d1, d2;

  int16_t res1 = scp_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_spec_hhu_7) {
  char format[] = "%1hhu";
  char str[] = "-123";
  unsigned char d1 = 0, d2 = 0;

  int16_t res1 = scp_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_spec_hhu_8) {
  char format[] = "%3hhu";
  char str[] = "+123";
  unsigned char d1, d2;

  int16_t res1 = scp_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_spec_hhu_9) {
  char format[] = "%4hhu";
  char str[] = "+123";
  unsigned char d1, d2;

  int16_t res1 = scp_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_spec_hhu_10) {
  char format[] = "%10hhu";
  char str[] = "+123";
  unsigned char d1, d2;

  int16_t res1 = scp_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_spec_hhu_11) {
  char format[] = "%1hhu";
  char str[] = "+123";
  unsigned char d1 = 0, d2 = 0;

  int16_t res1 = scp_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_spec_hhu_12) {
  char format[] = "%*1hhu";
  char str[] = "+123";
  unsigned char d1 = 0, d2 = 0;

  int16_t res1 = scp_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_spec_hhu_13) {
  char format[] = "%*hhu";
  char str[] = "123";
  unsigned char d1 = 0, d2 = 0;

  int16_t res1 = scp_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_spec_hhu_14) {
  char format[] = "%hhu";
  char str[] = "2147483647";
  unsigned char d1 = 0, d2 = 0;

  int16_t res1 = scp_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_spec_hhu_15) {
  char format[] = "%hhu";
  char str[] = "+2147483648";
  unsigned char d1 = 0, d2 = 0;

  int16_t res1 = scp_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_spec_hhu_16) {
  char format[] = "%hhu";
  char str[] = "214743483648";
  unsigned char d1 = 0, d2 = 0;

  int16_t res1 = scp_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_spec_hhu_17) {
  char format[] = "%hhu";
  char str[] = "-2147483648";
  unsigned char d1 = 0, d2 = 0;

  int16_t res1 = scp_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_spec_hhu_18) {
  char format[] = "%hhu";
  char str[] = "-2147483649";
  unsigned char d1 = 0, d2 = 0;

  int16_t res1 = scp_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_spec_hhu_19) {
  char format[] = "%hhu";
  char str[] = "-214748364239";
  unsigned char d1 = 0, d2 = 0;

  int16_t res1 = scp_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_spec_hhu_20) {
  char format[] = "%hhu";
  char str[] = "-9223372036854775808";
  unsigned char d1 = 0, d2 = 0;

  int16_t res1 = scp_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_spec_hhu_21) {
  char format[] = "%hhu";
  char str[] = "-9223372036854775809";
  unsigned char d1 = 0, d2 = 0;

  int16_t res1 = scp_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_spec_hhu_22) {
  char format[] = "%hhu";
  char str[] = "-922337203685477582309";
  unsigned char d1 = 0, d2 = 0;

  int16_t res1 = scp_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_spec_hhu_23) {
  char format[] = "%hhu";
  char str[] = "9223372036854775807";
  unsigned char d1 = 0, d2 = 0;

  int16_t res1 = scp_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_spec_hhu_24) {
  char format[] = "%hhu";
  char str[] = "9223372036854775808";
  unsigned char d1 = 0, d2 = 0;

  int16_t res1 = scp_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_spec_hhu_25) {
  char format[] = "%hhu";
  char str[] = "922337203685477582309";
  unsigned char d1 = 0, d2 = 0;

  int16_t res1 = scp_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_spec_hu_1) {
  char format[] = "%hu";
  char str[] = "123";
  unsigned short d1, d2;

  int16_t res1 = scp_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_spec_hu_2) {
  char format[] = "%hu";
  char str[] = "-123";
  unsigned short d1, d2;

  int16_t res1 = scp_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_spec_hu_3) {
  char format[] = "%hu";
  char str[] = "+123";
  unsigned short d1, d2;

  int16_t res1 = scp_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_spec_hu_4) {
  char format[] = "%3hu";
  char str[] = "-123";
  unsigned short d1, d2;

  int16_t res1 = scp_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_spec_hu_5) {
  char format[] = "%4hu";
  char str[] = "-123";
  unsigned short d1, d2;

  int16_t res1 = scp_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_spec_hu_6) {
  char format[] = "%10hu";
  char str[] = "-123";
  unsigned short d1, d2;

  int16_t res1 = scp_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_spec_hu_7) {
  char format[] = "%1hu";
  char str[] = "-123";
  unsigned short d1 = 0, d2 = 0;

  int16_t res1 = scp_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_spec_hu_8) {
  char format[] = "%3hu";
  char str[] = "+123";
  unsigned short d1, d2;

  int16_t res1 = scp_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_spec_hu_9) {
  char format[] = "%4hu";
  char str[] = "+123";
  unsigned short d1, d2;

  int16_t res1 = scp_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_spec_hu_10) {
  char format[] = "%10hu";
  char str[] = "+123";
  unsigned short d1, d2;

  int16_t res1 = scp_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_spec_hu_11) {
  char format[] = "%1hu";
  char str[] = "+123";
  unsigned short d1 = 0, d2 = 0;

  int16_t res1 = scp_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_spec_hu_12) {
  char format[] = "%*1hu";
  char str[] = "+123";
  unsigned short d1 = 0, d2 = 0;

  int16_t res1 = scp_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_spec_hu_13) {
  char format[] = "%*hu";
  char str[] = "123";
  unsigned short d1 = 0, d2 = 0;

  int16_t res1 = scp_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_spec_hu_14) {
  char format[] = "%hu";
  char str[] = "2147483647";
  unsigned short d1 = 0, d2 = 0;

  int16_t res1 = scp_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_spec_hu_15) {
  char format[] = "%hu";
  char str[] = "+2147483648";
  unsigned short d1 = 0, d2 = 0;

  int16_t res1 = scp_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_spec_hu_16) {
  char format[] = "%hu";
  char str[] = "214743483648";
  unsigned short d1 = 0, d2 = 0;

  int16_t res1 = scp_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_spec_hu_17) {
  char format[] = "%hu";
  char str[] = "-2147483648";
  unsigned short d1 = 0, d2 = 0;

  int16_t res1 = scp_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_spec_hu_18) {
  char format[] = "%hu";
  char str[] = "-2147483649";
  unsigned short d1 = 0, d2 = 0;

  int16_t res1 = scp_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_spec_hu_19) {
  char format[] = "%hu";
  char str[] = "-214748364239";
  unsigned short d1 = 0, d2 = 0;

  int16_t res1 = scp_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_spec_hu_20) {
  char format[] = "%hu";
  char str[] = "-9223372036854775808";
  unsigned short d1 = 0, d2 = 0;

  int16_t res1 = scp_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_spec_hu_21) {
  char format[] = "%hu";
  char str[] = "-9223372036854775809";
  unsigned short d1 = 0, d2 = 0;

  int16_t res1 = scp_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_spec_hu_22) {
  char format[] = "%hu";
  char str[] = "-922337203685477582309";
  unsigned short d1 = 0, d2 = 0;

  int16_t res1 = scp_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_spec_hu_23) {
  char format[] = "%hu";
  char str[] = "9223372036854775807";
  unsigned short d1 = 0, d2 = 0;

  int16_t res1 = scp_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_spec_hu_24) {
  char format[] = "%hu";
  char str[] = "9223372036854775808";
  unsigned short d1 = 0, d2 = 0;

  int16_t res1 = scp_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_spec_hu_25) {
  char format[] = "%hu";
  char str[] = "922337203685477582309";
  unsigned short d1 = 0, d2 = 0;

  int16_t res1 = scp_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_spec_u_1) {
  char format[] = "%u";
  char str[] = "123";
  unsigned int d1, d2;

  int16_t res1 = scp_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_spec_u_2) {
  char format[] = "%u";
  char str[] = "-123";
  unsigned int d1, d2;

  int16_t res1 = scp_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_spec_u_3) {
  char format[] = "%u";
  char str[] = "+123";
  unsigned int d1, d2;

  int16_t res1 = scp_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_spec_u_4) {
  char format[] = "%3u";
  char str[] = "-123";
  unsigned int d1, d2;

  int16_t res1 = scp_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_spec_u_5) {
  char format[] = "%4u";
  char str[] = "-123";
  unsigned int d1, d2;

  int16_t res1 = scp_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_spec_u_6) {
  char format[] = "%10u";
  char str[] = "-123";
  unsigned int d1, d2;

  int16_t res1 = scp_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_spec_u_7) {
  char format[] = "%1u";
  char str[] = "-123";
  unsigned int d1 = 0, d2 = 0;

  int16_t res1 = scp_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_spec_u_8) {
  char format[] = "%3u";
  char str[] = "+123";
  unsigned int d1, d2;

  int16_t res1 = scp_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_spec_u_9) {
  char format[] = "%4u";
  char str[] = "+123";
  unsigned int d1, d2;

  int16_t res1 = scp_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_spec_u_10) {
  char format[] = "%10u";
  char str[] = "+123";
  unsigned int d1, d2;

  int16_t res1 = scp_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_spec_u_11) {
  char format[] = "%1u";
  char str[] = "+123";
  unsigned int d1 = 0, d2 = 0;

  int16_t res1 = scp_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_spec_u_12) {
  char format[] = "%*1u";
  char str[] = "+123";
  unsigned int d1 = 0, d2 = 0;

  int16_t res1 = scp_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_spec_u_13) {
  char format[] = "%*u";
  char str[] = "123";
  unsigned int d1 = 0, d2 = 0;

  int16_t res1 = scp_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_spec_u_14) {
  char format[] = "%u";
  char str[] = "2147483647";
  unsigned int d1 = 0, d2 = 0;

  int16_t res1 = scp_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_spec_u_15) {
  char format[] = "%u";
  char str[] = "+2147483648";
  unsigned int d1 = 0, d2 = 0;

  int16_t res1 = scp_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_spec_u_16) {
  char format[] = "%u";
  char str[] = "214743483648";
  unsigned int d1 = 0, d2 = 0;

  int16_t res1 = scp_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_spec_u_17) {
  char format[] = "%u";
  char str[] = "-2147483648";
  unsigned int d1 = 0, d2 = 0;

  int16_t res1 = scp_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_spec_u_18) {
  char format[] = "%u";
  char str[] = "-2147483649";
  unsigned int d1 = 0, d2 = 0;

  int16_t res1 = scp_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_spec_u_19) {
  char format[] = "%u";
  char str[] = "-214748364239";
  unsigned int d1 = 0, d2 = 0;

  int16_t res1 = scp_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_spec_u_20) {
  char format[] = "%u";
  char str[] = "-9223372036854775808";
  unsigned int d1 = 0, d2 = 0;

  int16_t res1 = scp_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_spec_u_21) {
  char format[] = "%u";
  char str[] = "-9223372036854775809";
  unsigned int d1 = 0, d2 = 0;

  int16_t res1 = scp_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_spec_u_22) {
  char format[] = "%u";
  char str[] = "-922337203685477582309";
  unsigned int d1 = 0, d2 = 0;

  int16_t res1 = scp_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_spec_u_23) {
  char format[] = "%u";
  char str[] = "9223372036854775807";
  unsigned int d1 = 0, d2 = 0;

  int16_t res1 = scp_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_spec_u_24) {
  char format[] = "%u";
  char str[] = "9223372036854775808";
  unsigned int d1 = 0, d2 = 0;

  int16_t res1 = scp_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_spec_u_25) {
  char format[] = "%u";
  char str[] = "922337203685477582309";
  unsigned int d1 = 0, d2 = 0;

  int16_t res1 = scp_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_spec_lu_1) {
  char format[] = "%lu";
  char str[] = "123";
  unsigned long int d1, d2;

  int16_t res1 = scp_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_spec_lu_2) {
  char format[] = "%lu";
  char str[] = "-123";
  unsigned long int d1, d2;

  int16_t res1 = scp_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_spec_lu_3) {
  char format[] = "%lu";
  char str[] = "+123";
  unsigned long int d1, d2;

  int16_t res1 = scp_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_spec_lu_4) {
  char format[] = "%3lu";
  char str[] = "-123";
  unsigned long int d1, d2;

  int16_t res1 = scp_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_spec_lu_5) {
  char format[] = "%4lu";
  char str[] = "-123";
  unsigned long int d1, d2;

  int16_t res1 = scp_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_spec_lu_6) {
  char format[] = "%10lu";
  char str[] = "-123";
  unsigned long int d1, d2;

  int16_t res1 = scp_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_spec_lu_7) {
  char format[] = "%1lu";
  char str[] = "-123";
  unsigned long int d1 = 0, d2 = 0;

  int16_t res1 = scp_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_spec_lu_8) {
  char format[] = "%3lu";
  char str[] = "+123";
  unsigned long int d1, d2;

  int16_t res1 = scp_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_spec_lu_9) {
  char format[] = "%4lu";
  char str[] = "+123";
  unsigned long int d1, d2;

  int16_t res1 = scp_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_spec_lu_10) {
  char format[] = "%10lu";
  char str[] = "+123";
  unsigned long int d1, d2;

  int16_t res1 = scp_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_spec_lu_11) {
  char format[] = "%1lu";
  char str[] = "+123";
  unsigned long int d1 = 0, d2 = 0;

  int16_t res1 = scp_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_spec_lu_12) {
  char format[] = "%*1lu";
  char str[] = "+123";
  unsigned long int d1 = 0, d2 = 0;

  int16_t res1 = scp_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_spec_lu_13) {
  char format[] = "%*lu";
  char str[] = "123";
  unsigned long int d1 = 0, d2 = 0;

  int16_t res1 = scp_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_spec_lu_14) {
  char format[] = "%lu";
  char str[] = "2147483647";
  unsigned long int d1 = 0, d2 = 0;

  int16_t res1 = scp_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_spec_lu_15) {
  char format[] = "%lu";
  char str[] = "+2147483648";
  unsigned long int d1 = 0, d2 = 0;

  int16_t res1 = scp_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_spec_lu_16) {
  char format[] = "%lu";
  char str[] = "214743483648";
  unsigned long int d1 = 0, d2 = 0;

  int16_t res1 = scp_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_spec_lu_17) {
  char format[] = "%lu";
  char str[] = "-2147483648";
  unsigned long int d1 = 0, d2 = 0;

  int16_t res1 = scp_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_spec_lu_18) {
  char format[] = "%lu";
  char str[] = "-2147483649";
  unsigned long int d1 = 0, d2 = 0;

  int16_t res1 = scp_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_spec_lu_19) {
  char format[] = "%lu";
  char str[] = "-214748364239";
  unsigned long int d1 = 0, d2 = 0;

  int16_t res1 = scp_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_spec_lu_20) {
  char format[] = "%lu";
  char str[] = "-9223372036854775808";
  unsigned long int d1 = 0, d2 = 0;

  int16_t res1 = scp_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_spec_lu_21) {
  char format[] = "%lu";
  char str[] = "-9223372036854775809";
  unsigned long int d1 = 0, d2 = 0;

  int16_t res1 = scp_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_spec_lu_22) {
  char format[] = "%lu";
  char str[] = "-922337203685477582309";
  unsigned long int d1 = 0, d2 = 0;

  int16_t res1 = scp_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_spec_lu_23) {
  char format[] = "%lu";
  char str[] = "9223372036854775807";
  unsigned long int d1 = 0, d2 = 0;

  int16_t res1 = scp_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_spec_lu_24) {
  char format[] = "%lu";
  char str[] = "9223372036854775808";
  unsigned long int d1 = 0, d2 = 0;

  int16_t res1 = scp_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_spec_lu_25) {
  char format[] = "%lu";
  char str[] = "922337203685477582309";
  unsigned long int d1 = 0, d2 = 0;

  int16_t res1 = scp_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_spec_llu_1) {
  char format[] = "%llu";
  char str[] = "123";
  unsigned long long int d1, d2;

  int16_t res1 = scp_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_spec_llu_2) {
  char format[] = "%llu";
  char str[] = "-123";
  unsigned long long int d1, d2;

  int16_t res1 = scp_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_spec_llu_3) {
  char format[] = "%llu";
  char str[] = "+123";
  unsigned long long int d1, d2;

  int16_t res1 = scp_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_spec_llu_4) {
  char format[] = "%3llu";
  char str[] = "-123";
  unsigned long long int d1, d2;

  int16_t res1 = scp_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_spec_llu_5) {
  char format[] = "%4llu";
  char str[] = "-123";
  unsigned long long int d1, d2;

  int16_t res1 = scp_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_spec_llu_6) {
  char format[] = "%10llu";
  char str[] = "-123";
  unsigned long long int d1, d2;

  int16_t res1 = scp_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_spec_llu_7) {
  char format[] = "%1llu";
  char str[] = "-123";
  unsigned long long int d1 = 0, d2 = 0;

  int16_t res1 = scp_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_spec_llu_8) {
  char format[] = "%3llu";
  char str[] = "+123";
  unsigned long long int d1, d2;

  int16_t res1 = scp_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_spec_llu_9) {
  char format[] = "%4llu";
  char str[] = "+123";
  unsigned long long int d1, d2;

  int16_t res1 = scp_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_spec_llu_10) {
  char format[] = "%10llu";
  char str[] = "+123";
  unsigned long long int d1, d2;

  int16_t res1 = scp_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_spec_llu_11) {
  char format[] = "%1llu";
  char str[] = "+123";
  unsigned long long int d1 = 0, d2 = 0;

  int16_t res1 = scp_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_spec_llu_12) {
  char format[] = "%*1llu";
  char str[] = "+123";
  unsigned long long int d1 = 0, d2 = 0;

  int16_t res1 = scp_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_spec_llu_13) {
  char format[] = "%*llu";
  char str[] = "123";
  unsigned long long int d1 = 0, d2 = 0;

  int16_t res1 = scp_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_spec_llu_14) {
  char format[] = "%llu";
  char str[] = "2147483647";
  unsigned long long int d1 = 0, d2 = 0;

  int16_t res1 = scp_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_spec_llu_15) {
  char format[] = "%llu";
  char str[] = "+2147483648";
  unsigned long long int d1 = 0, d2 = 0;

  int16_t res1 = scp_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_spec_llu_16) {
  char format[] = "%llu";
  char str[] = "214743483648";
  unsigned long long int d1 = 0, d2 = 0;

  int16_t res1 = scp_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_spec_llu_17) {
  char format[] = "%llu";
  char str[] = "-2147483648";
  unsigned long long int d1 = 0, d2 = 0;

  int16_t res1 = scp_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_spec_llu_18) {
  char format[] = "%llu";
  char str[] = "-2147483649";
  unsigned long long int d1 = 0, d2 = 0;

  int16_t res1 = scp_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_spec_llu_19) {
  char format[] = "%llu";
  char str[] = "-214748364239";
  unsigned long long int d1 = 0, d2 = 0;

  int16_t res1 = scp_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_spec_llu_20) {
  char format[] = "%llu";
  char str[] = "-9223372036854775808";
  unsigned long long int d1 = 0, d2 = 0;

  int16_t res1 = scp_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_spec_llu_21) {
  char format[] = "%llu";
  char str[] = "-9223372036854775809";
  unsigned long long int d1 = 0, d2 = 0;

  int16_t res1 = scp_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_spec_llu_22) {
  char format[] = "%llu";
  char str[] = "-922337203685477582309";
  unsigned long long int d1 = 0, d2 = 0;

  int16_t res1 = scp_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_spec_llu_23) {
  char format[] = "%llu";
  char str[] = "9223372036854775807";
  unsigned long long int d1 = 0, d2 = 0;

  int16_t res1 = scp_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_spec_llu_24) {
  char format[] = "%llu";
  char str[] = "9223372036854775808";
  unsigned long long int d1 = 0, d2 = 0;

  int16_t res1 = scp_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_spec_llu_25) {
  char format[] = "%llu";
  char str[] = "922337203685477582309";
  unsigned long long int d1 = 0, d2 = 0;

  int16_t res1 = scp_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

Suite *test_sscanf_u(void) {
  Suite *s = suite_create("\033[33m-=scp_sscanf_u=-\033[0m");
  TCase *tc = tcase_create("sscanf_tc");

  tcase_add_test(tc, sscanf_spec_hhu_1);
  tcase_add_test(tc, sscanf_spec_hhu_2);
  tcase_add_test(tc, sscanf_spec_hhu_3);
  tcase_add_test(tc, sscanf_spec_hhu_4);
  tcase_add_test(tc, sscanf_spec_hhu_5);
  tcase_add_test(tc, sscanf_spec_hhu_6);
  tcase_add_test(tc, sscanf_spec_hhu_7);
  tcase_add_test(tc, sscanf_spec_hhu_8);
  tcase_add_test(tc, sscanf_spec_hhu_9);
  tcase_add_test(tc, sscanf_spec_hhu_10);
  tcase_add_test(tc, sscanf_spec_hhu_11);
  tcase_add_test(tc, sscanf_spec_hhu_12);
  tcase_add_test(tc, sscanf_spec_hhu_13);
  tcase_add_test(tc, sscanf_spec_hhu_14);
  tcase_add_test(tc, sscanf_spec_hhu_15);
  tcase_add_test(tc, sscanf_spec_hhu_16);
  tcase_add_test(tc, sscanf_spec_hhu_17);
  tcase_add_test(tc, sscanf_spec_hhu_18);
  tcase_add_test(tc, sscanf_spec_hhu_19);
  tcase_add_test(tc, sscanf_spec_hhu_20);
  tcase_add_test(tc, sscanf_spec_hhu_21);
  tcase_add_test(tc, sscanf_spec_hhu_22);
  tcase_add_test(tc, sscanf_spec_hhu_23);
  tcase_add_test(tc, sscanf_spec_hhu_24);
  tcase_add_test(tc, sscanf_spec_hhu_25);

  tcase_add_test(tc, sscanf_spec_hu_1);
  tcase_add_test(tc, sscanf_spec_hu_2);
  tcase_add_test(tc, sscanf_spec_hu_3);
  tcase_add_test(tc, sscanf_spec_hu_4);
  tcase_add_test(tc, sscanf_spec_hu_5);
  tcase_add_test(tc, sscanf_spec_hu_6);
  tcase_add_test(tc, sscanf_spec_hu_7);
  tcase_add_test(tc, sscanf_spec_hu_8);
  tcase_add_test(tc, sscanf_spec_hu_9);
  tcase_add_test(tc, sscanf_spec_hu_10);
  tcase_add_test(tc, sscanf_spec_hu_11);
  tcase_add_test(tc, sscanf_spec_hu_12);
  tcase_add_test(tc, sscanf_spec_hu_13);
  tcase_add_test(tc, sscanf_spec_hu_14);
  tcase_add_test(tc, sscanf_spec_hu_15);
  tcase_add_test(tc, sscanf_spec_hu_16);
  tcase_add_test(tc, sscanf_spec_hu_17);
  tcase_add_test(tc, sscanf_spec_hu_18);
  tcase_add_test(tc, sscanf_spec_hu_19);
  tcase_add_test(tc, sscanf_spec_hu_20);
  tcase_add_test(tc, sscanf_spec_hu_21);
  tcase_add_test(tc, sscanf_spec_hu_22);
  tcase_add_test(tc, sscanf_spec_hu_23);
  tcase_add_test(tc, sscanf_spec_hu_24);
  tcase_add_test(tc, sscanf_spec_hu_25);

  tcase_add_test(tc, sscanf_spec_u_1);
  tcase_add_test(tc, sscanf_spec_u_2);
  tcase_add_test(tc, sscanf_spec_u_3);
  tcase_add_test(tc, sscanf_spec_u_4);
  tcase_add_test(tc, sscanf_spec_u_5);
  tcase_add_test(tc, sscanf_spec_u_6);
  tcase_add_test(tc, sscanf_spec_u_7);
  tcase_add_test(tc, sscanf_spec_u_8);
  tcase_add_test(tc, sscanf_spec_u_9);
  tcase_add_test(tc, sscanf_spec_u_10);
  tcase_add_test(tc, sscanf_spec_u_11);
  tcase_add_test(tc, sscanf_spec_u_12);
  tcase_add_test(tc, sscanf_spec_u_13);
  tcase_add_test(tc, sscanf_spec_u_14);
  tcase_add_test(tc, sscanf_spec_u_15);
  tcase_add_test(tc, sscanf_spec_u_16);
  tcase_add_test(tc, sscanf_spec_u_17);
  tcase_add_test(tc, sscanf_spec_u_18);
  tcase_add_test(tc, sscanf_spec_u_19);
  tcase_add_test(tc, sscanf_spec_u_20);
  tcase_add_test(tc, sscanf_spec_u_21);
  tcase_add_test(tc, sscanf_spec_u_22);
  tcase_add_test(tc, sscanf_spec_u_23);
  tcase_add_test(tc, sscanf_spec_u_24);
  tcase_add_test(tc, sscanf_spec_u_25);

  tcase_add_test(tc, sscanf_spec_lu_1);
  tcase_add_test(tc, sscanf_spec_lu_2);
  tcase_add_test(tc, sscanf_spec_lu_3);
  tcase_add_test(tc, sscanf_spec_lu_4);
  tcase_add_test(tc, sscanf_spec_lu_5);
  tcase_add_test(tc, sscanf_spec_lu_6);
  tcase_add_test(tc, sscanf_spec_lu_7);
  tcase_add_test(tc, sscanf_spec_lu_8);
  tcase_add_test(tc, sscanf_spec_lu_9);
  tcase_add_test(tc, sscanf_spec_lu_10);
  tcase_add_test(tc, sscanf_spec_lu_11);
  tcase_add_test(tc, sscanf_spec_lu_12);
  tcase_add_test(tc, sscanf_spec_lu_13);
  tcase_add_test(tc, sscanf_spec_lu_14);
  tcase_add_test(tc, sscanf_spec_lu_15);
  tcase_add_test(tc, sscanf_spec_lu_16);
  tcase_add_test(tc, sscanf_spec_lu_17);
  tcase_add_test(tc, sscanf_spec_lu_18);
  tcase_add_test(tc, sscanf_spec_lu_19);
  tcase_add_test(tc, sscanf_spec_lu_20);
  tcase_add_test(tc, sscanf_spec_lu_21);
  tcase_add_test(tc, sscanf_spec_lu_22);
  tcase_add_test(tc, sscanf_spec_lu_23);
  tcase_add_test(tc, sscanf_spec_lu_24);
  tcase_add_test(tc, sscanf_spec_lu_25);

  tcase_add_test(tc, sscanf_spec_llu_1);
  tcase_add_test(tc, sscanf_spec_llu_2);
  tcase_add_test(tc, sscanf_spec_llu_3);
  tcase_add_test(tc, sscanf_spec_llu_4);
  tcase_add_test(tc, sscanf_spec_llu_5);
  tcase_add_test(tc, sscanf_spec_llu_6);
  tcase_add_test(tc, sscanf_spec_llu_7);
  tcase_add_test(tc, sscanf_spec_llu_8);
  tcase_add_test(tc, sscanf_spec_llu_9);
  tcase_add_test(tc, sscanf_spec_llu_10);
  tcase_add_test(tc, sscanf_spec_llu_11);
  tcase_add_test(tc, sscanf_spec_llu_12);
  tcase_add_test(tc, sscanf_spec_llu_13);
  tcase_add_test(tc, sscanf_spec_llu_14);
  tcase_add_test(tc, sscanf_spec_llu_15);
  tcase_add_test(tc, sscanf_spec_llu_16);
  tcase_add_test(tc, sscanf_spec_llu_17);
  tcase_add_test(tc, sscanf_spec_llu_18);
  tcase_add_test(tc, sscanf_spec_llu_19);
  tcase_add_test(tc, sscanf_spec_llu_20);
  tcase_add_test(tc, sscanf_spec_llu_21);
  tcase_add_test(tc, sscanf_spec_llu_22);
  tcase_add_test(tc, sscanf_spec_llu_23);
  tcase_add_test(tc, sscanf_spec_llu_24);
  tcase_add_test(tc, sscanf_spec_llu_25);

  suite_add_tcase(s, tc);
  return s;
}
