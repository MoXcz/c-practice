#include <stdio.h>
#include <stdlib.h>

// 'argv[argc] == NULL', always
// '**argv' is equivalent to '*argv[]', which is a pointer to a pointer
int main(int argc, char *argv[]) {
  char *err = NULL;

  for (int i = 0; i < argc; i++) {
    printf("arg %d: %s\n", i, argv[i]);
  }

  int total = 0;
  for (int i = 1; i < argc; i++) {
    int val = strtol(argv[i], &err, 10);
    if (*err == '\0') {
      total += val;
    } else {
      // whether to add the partial conversion or not is up to the programmer
      total += val;
      printf("Partial conversion: %d\n", val);
      printf("Invalid character: %c\n", *err);
    }
  }

  /* The same as above, but with '**argv' notation
  (void)argc;
  for (char **p = argv + 1; *p != NULL; p++) {
    int value = atoi(*p); // Use strtol() for better error handling

    total += value;
  }
  */

  printf("Total: %d\n", total);

  return 0;
}
