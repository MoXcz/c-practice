#include <stdio.h>

/* This is a program that replaces a string of one or more blanks by a single
 * blank */

int main() {
  int c;

  while ((c = getchar()) != EOF) {
    if (c == ' ') {
      putchar(c);
      for (; c == ' '; c = getchar())
        ;
    }
    putchar(c);
  }
}
