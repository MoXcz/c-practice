/*
 * The only real specified return value is 0, which is considered to be a
 * success. Any other value (!= 0) is an error value
 */
#include <stdio.h>
#include <stdlib.h>

// int main(int argc, char **argv, char **env)

// note that this is only part of the POSIX standard, so it's not as compatible
// (not part of the C standard)
extern char **environ;

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: exit [ENV]\n");
    return EXIT_FAILURE;
  }
  char *env = getenv(argv[1]);

  if (env == NULL) {
    printf("Env variable '%s' not set\n", argv[1]);
    return 0;
  }
  printf("Value of '%s': %s\n", argv[1], env);

  // print all env variables (from 'environ')
  for (int i = 0; environ[i] != NULL; i++) {
    printf("%s\n", environ[i]);
  }

  return 0; // same as EXIT_SUCCESS
}
