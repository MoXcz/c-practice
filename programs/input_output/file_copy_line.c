#include <stdio.h>

/* This is a program that copies its input to its output one word per line */

int main() {
  int c;

  while ((c = getchar()) != EOF) {
    if (c == ' ' || c == '\t') {
      printf("%c", '\n');
      for (; c == ' ' || c == '\t'; c = getchar())
        ;
    }
    putchar(c);
  }
}
