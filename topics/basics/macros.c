/*
 * '#pragma' can be used to give the compiler directive on how it should behave
 * on certain scenarios (such as contexts where there exist multiple threads)
 * There are also some pragma's defined in the standard:
 * - '#pragma STDC FP_CONTRACT OFF'. Contract float expression into a single
 * operation
 * - '#pragma STDC CX_LIMITED_RANGE ON'. Skip overflow with complex arithmetic
 */
#include <math.h>
#include <stdio.h>
/* Note that this is not C, so it's not parsed with any kind of precedence
 * - #define SQRT(x) x * x.
 *   Expands (3 + 2) into 3 + 2 * 3 + 2, instead of (3 + 2) * (3 + 2)
 * - #define SQRT(x) ((x) * (x))
 *   Expands to ((3 + 2) * (3 + 2))
 */
#define SQRT(x) ((x) * (x))

// quadratic formula macro
#define QUADP(a, b, c) ((-(b) + sqrt((b) * (b) - 4 * (a) * (c))) / (2 * (a)))
#define QUADM(a, b, c) ((-(b) - sqrt((b) * (b) - 4 * (a) * (c))) / (2 * (a)))
#define QUAD(a, b, c) QUADP(a, b, c), QUADM(a, b, c)

// variable arguments (perimeter of a circle + some text)
#define P_CIRCLE(r, pi, ...) (2 * (pi * pi)), __VA_ARGS__

// variable arguments replaced as strings
#define STRING(...) #__VA_ARGS__

// print/format variable declarations
#define PRINT_INT_VAR(x) printf("%s = %d\n", #x, x)

// concatenation
#define CAT(a, b) a##b

// multi-line macros, the do while loop is just there to run the code once and
// avoid trailing ';' when calling macros with ';'
#define ITER_PRINT(a, b)                                                       \
  do {                                                                         \
    int product = (a) * (b);                                                   \
    for (int i = 0; i < product; i++) {                                        \
      printf("%d\n", i);                                                       \
    }                                                                          \
  } while (0)

int main(void) {
  printf("2x^2 + 10x + 5 = 0\n");
  printf("x = %f or x = %f\n", QUAD(2, 10, 5));
  printf("%f %s %d\n", P_CIRCLE(5, 3.14, "Hi!", 12));
  printf("%s\n", STRING(1, 2)); // formatted as strings

  int a = 2;
  PRINT_INT_VAR(a); // replaced by 'printf("%s = %d\n", "a", 2);'
  ITER_PRINT(2, 4);
}
