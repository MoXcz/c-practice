/* Write a program to "fold" long input lines into two or more shorter lines
 * after the last non-blank character that occurs before the n-th column of
 * input. Make sure your program does something intelligent with very long
 * lines, and if there are no blanks or tabs before the specified column. All
 * this while storing the longest registered line and justifying text with
 * spaces*/

#include <stdio.h>
#define MAXLINE 50 // n-th colum of input

int main() {
  int c, current_line, longest_line;
  c = current_line = longest_line = 0;
  while (1) {
    for (; ((c = getchar()) != EOF) &&
           (current_line < MAXLINE || (c != ' ' && c != '\t'));
         current_line++) {
      longest_line++;
      printf("%c", c);
    }
    if (current_line > longest_line)
      longest_line = current_line;
    printf("\n");
    current_line = 0;
  }
}

// array -> for -> add space to after word
