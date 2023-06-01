#include "test_s21_string.h"

int main(void) {
  int failed = 0;
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
                              test_sprintf_o(),
                              test_sprintf_hex(),
                              test_sprintf_HEX(),
                              test_sprintf_n(),
                              test_sprintf_percent(),
                              test_sprintf_u(),
                              test_sprintf_p(),
                              test_sprintf_i(),
                              test_sprintf_f(),
                              NULL};

  for (int i = 0; s21_string_test[i] != NULL; i++) { 
    SRunner *sr = srunner_create(s21_string_test[i]);

    srunner_set_fork_status(sr, CK_NOFORK);
    srunner_run_all(sr, CK_VERBOSE);

    failed += srunner_ntests_failed(sr);
    srunner_free(sr);
  }
  printf("========= FAILED: %d =========\n", failed);

  return failed == 0 ? 0 : 1;
}