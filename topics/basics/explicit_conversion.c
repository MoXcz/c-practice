/*
 * Explicit conversion:
 * - Cast: Add '(type)' in front of the expression (common for 'void *')
 *
 * For the most part casting is not realy necessary, assignment '=' will, most
 * of the time, perform any and all conversions that most people will need.
 */

#include <stdio.h>

int main(void) {
  int x = 10;
  int *p = &x;
  // the conversion is actually implicit unless explicitly written (it happens
  // whether or not is explicit)
  long int y = (long int)x + 27;

  // not really necessary in this case
  printf("%p\n", (void *)p);
}
