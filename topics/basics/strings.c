#include <stdio.h>
#include <string.h>

int main(void) {
  char *s = "This is a string, and it continues to be";
  char *c;
  strcpy(c, s);
  printf("%s\n", s);
  printf("%s\n", c);
  printf("with len: %zu\n", strlen(s));

  // count strings by identifying the null-terminator character '\0'. This is
  // why C does not store the length of strings, they are optimized by using an
  // extra character, and not extra memory
  int count = 0;
  while (s[count] != '\0') {
    count += 1;
  }
  printf("%d", count);
}

// everything is a pointer in C!!
