#include <stdio.h>

/* Program to print a histogram of the lenght of words in its input with
 * horizontal bars */

int main() {
  int c, size_w;
  c = size_w = 0;

  while ((c = getchar()) != EOF) {
    if ((c == ' ' || c == '\n' || c == '\t') && size_w > 0) {
      for (int i = 0; i < size_w; i++)
        printf("-");
      printf("\n");
      size_w = 0;
    } else if (c != ' ' && c != '\n' && c != '\t')
      size_w++;
  }
}
