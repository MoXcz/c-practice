#include <stdio.h>

/* This is a program that copies its input to its output */

int main() {
  int out;
  out = getchar() != EOF;
  printf("%d \t %d\n", out, EOF); // out = 1, EOF = -1

  int c;

  while ((c = getchar()) != EOF) {
    putchar(c);
  }
}
