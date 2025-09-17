/* Write a program to "fold" long input lines into two or more shorter lines
 * after the last non-blank character that occurs before the n-th column of
 * input. Make sure your program does something intelligent with very long
 * lines, and if there are no blanks or tabs before the specified column. */

#include <stdio.h>
#define MAXLINE 50 // n-th colum of input

int main() {
  int c, current_line;
  c = current_line = 0;
  while (1) {
    for (; ((c = getchar()) != EOF) &&
           (current_line < MAXLINE || (c != ' ' && c != '\t'));
         current_line++) {
      printf("%c", c);
    }
    printf("\n");
    current_line = 0;
  }
}
