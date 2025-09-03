/*
 * 'limits.h' defines the maximum and minimum values for types to hold defined
 * by the specification. One of the main differences with these specified max
 * and min values is that the min value in signed 'char' variables is -127,
 * instead of the expected two's complement -128. This is due to how this just
 * specifies the 'minimum and maximum' required
 */

#include <float.h>
#include <stdio.h>

int main(void) {
  // These two lines are equivalent:
  long long int a;
  long long b;

  // And so are these:
  short int c;
  short d;

  float f_a;       // 4 bytes
  double f_b;      // 8 bytes; more precision
  double long f_c; // 16 bytes; even more precision

  printf("%zu\n", sizeof(double long));
  // these macros defined the mimimum significant decmial digits displayed, so
  // it's guaranteed that the decimal part will reach these values

  printf("%d\n", FLT_DIG);  // so if a 'float': anything beyond 0.1234567 just
                            // doesn't work as expcted
  printf("%d\n", DBL_DIG);  // 'double'
  printf("%d\n", LDBL_DIG); // 'double long'
  printf("%f", 0.12345678);

  float f = 3.14159f;
  float g = 0.00000265358f;

  printf("%.5f\n", f);  // 3.14159       -- correct!
  printf("%.11f\n", g); // 0.00000265358 -- correct!

  f += g; // 3.14159265358 is what f should be

  printf("%.11f\n", f); // 3.14159274101 -- wrong!
}
