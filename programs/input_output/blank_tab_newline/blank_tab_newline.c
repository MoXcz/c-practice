#include <stdio.h>

/* Program to count the number of blanks, tabs and newlines */

int main() {
  int nb, nt, nl; // number blanks, tabs, newlines
  nb = 0, nt = 0, nl = 0;

  int c;
  while ((c = getchar()) != EOF) {
    if (c == ' ')
      ++nb;
    if (c == '\t')
      ++nt;
    if (c == '\n')
      ++nl;
  }

  printf("Blanks: %d\nTabs: %d\nNewlines: %d\n", nb, nt, nl);
}
