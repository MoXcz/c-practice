#include <stdio.h>

/* Program that removes trailing blanks and tabs from each line of input and
 * deletes entirely blank lines. */

int main() {
  int c;
  char line[100];
  c = 0;
  int i = 0;

  while ((c = getchar()) != EOF) {
    line[i] = c;
    i++;
    if (c == '\n') {
      if (line[0] == '\n') { // Entirely blank line (no content + newline)
        i = 0;
        continue;
      }

      i = i - 2; // subtract \n and additional value due to addition

      while (line[i] == ' ' || line[i] == '\t') {
        line[i + 1] = 0;
        line[i] = '\n';
        i--;
      }

      if (i == -1) { // Entirely blank line (spaces and/or tabs)
        continue;
      }

      printf("\nLine: %s\n", line);

      /* I used this for debugging */
      /* printf("%d", i); */
      /* for (i = i + 1; i >= 0; i--) { */
      /*   printf("%c\n", line[i]); */
      /* } */

      i = 0;
    }
  }
}
