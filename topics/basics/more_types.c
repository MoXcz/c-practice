/*
 * Some suffixes to 'guarantee' the type, noting that C will always try to fit
 * constant numbers in the smallest representation possible (if it fits in
 * 'int', then it's an 'int').

int           x = 1234;
long int      x = 1234L;
long long int x = 1234LL

unsigned int           x = 1234U;
unsigned long int      x = 1234UL;
unsigned long long int x = 1234ULL;

 * Floating point constants on the other hand default to 'double' and not
 * 'float'.

float x       = 3.14f;
double x      = 3.14;
long double x = 3.14L;

 * This is actually a 'double':
float x = 3.14;
 */

#include <float.h>
#include <stdio.h>

int main(void) {
  // decimal digits encoded in 'float'
  printf("float:       %d\n", FLT_DECIMAL_DIG);
  // decimal digits encoded in 'double'
  printf("double:      %d\n", DBL_DECIMAL_DIG);
  // decimal digits encoded in 'double long'
  printf("double long: %d\n", LDBL_DECIMAL_DIG);
  // widest encoding (same as 'LDBL_DECIMAL_DIG')
  printf("max:         %d\n", DECIMAL_DIG);

  int hex_a = 0x1A2B;    // Hexadecimal
  int hex_b = 0x1a2b;    // Case doesn't matter for hex digits
  printf("%x\n", hex_a); // Print a hex number, "1a2b"

  int oct_a = 012;
  printf("%o\n", hex_a); // Print an octal number, "12"

  // unofficial (not part of the spec)
  int x = 0b101010;  // Binary 101010
  printf("%d\n", x); // Prints 42 decimal (no binary format specifier)

  // Scientific notation
  double e_x = 123.456e+3;  // 123456
  printf("%e\n", e_x);      // Prints 1.234560e+05
  printf("%e\n", 123456.0); // Prints 1.234560e+05

  // Hexadecimal floating point numbers
  double hex_e_x = 0xa.1p3; // change 'e' to 'p' and append '0x'
  printf("%a\n", hex_e_x);  // 0x1.42p+6
  printf("%f\n", hex_e_x);  // 80.500000
}
