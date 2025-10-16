#include <stddef.h>
#include <stdint.h>
#include <stdio.h>

/* look at that ugly thing: 'fn' accepts:
 * - 'fn': pointer to a function that returns a float and accepts two ints
 * - two ints: 'x' and 'y' */
float fn(float (*op)(int, int), int x, int y) { return op(x, y); }
// valid function function signature
float div(int x, int y) { return (float)x / y; }

int main(void) {
  // '\0', 0, and '(void *)0' are equivalent
  int *p = NULL;
  /* strict aliasing impedes conversions between pointer types (which is
   * expected) The only valid conversions are between:
   * - 'intptr_t' and 'uintptr_t'
   * - To and from void*
   * - char*, unsigned char* and signed char*
   * - Pointer to struct and its first member
   * Prefer unions to violating strict type aliasing */
  int xs[100];
  int *x20 = xs + 20;
  int *x60 = xs + 60;
  // safely get the difference (otherwise the resulting type might vary)
  ptrdiff_t diff = x60 - x20;
  printf("%td\n", diff);

  float result = fn(div, 6, 3);
  printf("%f\n", result);

  // division is a pointer to 'div', note that '&' it's not necessary
  float (*division)(int, int) = div;
  // notice the parenthesis? They are needed so that '*' affects 'division'

  float res = division(8, 2);
  printf("%f", res);
}
