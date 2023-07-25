#include "test_scp_string.h"

int main(void) {
  setlocale(LC_ALL, "");

  int failed = 0;
  Suite *scp_string_test[] = {test_memchr(),
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

                              test_sprintf_d(),
                              test_sprintf_c(),
                              test_sprintf_s(),
                              test_sprintf_i(),
                              test_sprintf_e(),
                              test_sprintf_f(),
                              test_sprintf_g(),
                              test_sprintf_o(),
                              test_sprintf_u(),
                              test_sprintf_x1(),
                              test_sprintf_x2(),
                              test_sprintf_p(),
                              test_sprintf_n(),
                              test_sprintf_percent(),

                              test_to_upper(),
                              test_to_lower(),
                              test_insert(),
                              test_trim(),

                              test_sscanf_d(),
                              test_sscanf_c(),
                              test_sscanf_s(),
                              test_sscanf_i(),
                              test_sscanf_o(),
                              test_sscanf_u(),
                              test_sscanf_x(),
                              test_sscanf_p(),
                              test_sscanf_n(),
                              test_sscanf_percent(),
                              test_sscanf_f(),
                              test_sscanf_inc(),

                              NULL};

  for (int i = 0; scp_string_test[i] != NULL; i++) {
    SRunner *sr = srunner_create(scp_string_test[i]);

    srunner_set_fork_status(sr, CK_NOFORK);
    srunner_run_all(sr, CK_NORMAL);

    failed += srunner_ntests_failed(sr);
    srunner_free(sr);
  }
  printf("========= FAILED: %d =========\n", failed);

  return failed == 0 ? 0 : 1;
}