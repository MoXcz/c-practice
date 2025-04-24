#include <stdio.h>

/* Program that reverse input lines */

int reverse(char s[]);
int getln(char line[], int maxline);

int main() {
  int c;
  char line[100];

  while (1) {
    getln(line, 100);
    reverse(line);
    printf("%s", line);
  }
}

// s is an input line string to reverse
int reverse(char s[]) {
  char temp[100];
  int len;
  len = 0;

  for (int i = 0; s[i] != '\n'; i++) {
    temp[i] = s[i];
    len++;

    if (s[i + 1] == '\n') {
      temp[i + 1] = s[i + 1];
      break;
    }
  }

  for (int i = 0; s[i] != '\n'; i++) {
    s[len - i - 1] = temp[i];
  }
  return 0;
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
  return i;
}
