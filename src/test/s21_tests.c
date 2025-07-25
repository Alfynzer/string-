#include "s21_tests.h"

void run_testcase(Suite *testcase) {
  static int counter_testcase = 1;

  if (counter_testcase > 1) putchar('\n');
  printf("CURRENT TEST: %d\n", counter_testcase);
  counter_testcase++;

  SRunner *sr = srunner_create(testcase);

  srunner_set_fork_status(sr, CK_NOFORK);
  srunner_run_all(sr, CK_NORMAL);

  srunner_free(sr);
}
void run_tests(void) {
  Suite *list_cases[] = {
      suite_memchr(),   suite_memset(),   suite_strchr(),  suite_strerror(),
      suite_strlen(),   suite_strncat(),  suite_strncmp(), suite_memcmp(),
      suite_memcpy(),   suite_strncpy(),  suite_strpbrk(), suite_strrchr(),
      suite_strstr(),   suite_strtok(),   suite_insert(),  suite_trim(),
      suite_to_upper(), suite_to_lower(), suite_sprintf(), suite_strcspn(),
      suite_sscanf(),   s21_NULL};

  for (Suite **current_testcase = list_cases; *current_testcase != s21_NULL;
       current_testcase++) {
    run_testcase(*current_testcase);
  }
}

int main(void) {
  run_tests();
  return 0;
}
