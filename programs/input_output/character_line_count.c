#include <stdio.h>

/* Count character, lines in input */

int main() {
  long nc; // number characters
  nc = 0;
  int c, nl; // number lines
  nl = 0;

  while ((c = getchar()) != EOF) {
    ++nc;
    if (c == '\n') // if it's the end of the line, add 1
      ++nl;
  }

  printf("%ld\n", nc);
  printf("%d\n", nl);
}
