/* TODO: Write a program to remove all comments from a C program. Don't forget
 * to handle quoted strings and character constants properly. C comments don't
 * nest. */

// //comment "//not comment"

#include <stdio.h>

#define MAX 100

int getln(char s[], int lim);

int main() {
  int c, max, pos;
  char line[MAX];
  c = max = 0;

  while ((max = getln(line, MAX)) > 0) {
    if (line[0] == '/' && line[1] == '/') {
      continue;
    }
    printf("%s", line);
  }
  for (int i = 0; line[i] != '\0'; i++) {
    if (line[i] == '/' && line[i + 1] == '*') {
      pos = i;
      for (int i = 0; line[i] != '\n'; i++) {
        if (line[i] != '\n') {
          if (line[i - 1] == '/' && line[i - 2] == '*')
        }
      }
    }
  }
}

int getln(char s[], int lim) {
  int c, i;
  for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
    s[i] = c;
  if (c == '\n') {
    s[i] = c;
    ++i;
  }
  s[i] = '\0';
  return 1;
}
