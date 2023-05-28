#include "test_s21_string.h"

int main(void) {
  int failed = 0;
<<<<<<< HEAD
  Suite *s21_string_test[] = {test_memchr(),
                              test_memcmp(),
                              test_memcpy(),
                              test_memset(),
                              test_strncat(),
                              test_strchr(),
                              test_strncmp(),
                              test_strncpy(),
                              test_strcspn(),
                              test_strerror(),
                              test_strlen(),
                              test_strpbrk(),
                              test_strrchr(),
                              test_strstr(),
                              test_strtok(),
                              test_sprintf_signed(),
                              test_sprintf_hex(),
                              test_sprintf_HEX(),
                              //test_sprintf_n(),
                              test_sprintf_percent(),
                              NULL};
=======
  Suite *s21_string_test[] = {
      test_memchr(),  test_memcmp(),   test_memcpy(),  test_memset(),
      test_strncat(), test_strchr(),   test_strncmp(), test_strncpy(),
      test_strcspn(), test_strerror(), test_strlen(),  test_strpbrk(),
      test_strrchr(), test_strstr(),   test_strtok(),  NULL};
>>>>>>> 59c3dac97c6954adb6728af20080dc1213f5a670

  for (int i = 0; s21_string_test[i] != NULL; i++) {  // (&& failed == 0)
    SRunner *sr = srunner_create(s21_string_test[i]);

    srunner_set_fork_status(sr, CK_NOFORK);
    srunner_run_all(sr, CK_VERBOSE);

    failed += srunner_ntests_failed(sr);
    srunner_free(sr);
  }
  printf("========= FAILED: %d =========\n", failed);

  return failed == 0 ? 0 : 1;
}