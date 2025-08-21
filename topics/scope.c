/*
 * Visible context.
 * - Block scope (commonly referred to as function scope in other languages)
 * makes variables visible in 'blocks' delimited by '{ }'
 * - File scope (commonly referred to as global scope in other languages) makes
 * the variables visible in the whole file
 *
 * Historical fact: Before C99 all variables needed to be defined before any
 * code in the block
 */

int shared = 10;

void add_to_shared(void) { shared += 10; }

#include <stdio.h>
int main(void) {
  int a = 2;
  if (a == 2) {
    int b = 3, a = 5;
    // inner scope takes precedence; it 'hides' the outer scope value
    printf("%d\n", a);
  }

  // a single block with no statement such as 'if' or 'for'
  {
    int a = 6;
    printf("%d\n", a);
  }

  // 'b' is out of scope here, 'b' is still 'alive'
  printf("%d\n", a);
  // printf("%d\n", b); undeclared identifier
  add_to_shared(); // 'shared' has a value of 20 here
}
