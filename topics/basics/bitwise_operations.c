#include <stdio.h>

int main() {
  // bitwise shift
  int x = 1 << 20; // 20 shifts to the left ~1,000,000
  printf("%d\n", x);
  int y = x >> 1; // 1 shift to the right ~500,000
  printf("%d\n", y);

  char a = 0b1010;
  char b = 0b0011;

  printf("%d\n", a); // 10
  printf("%d\n", b); // 3

  printf("%d\n", ~a);    // NOT: -11  | ~00001010 = 11110101
  printf("%d\n", a & b); // AND: 2  | 1010 & 0011 = 0010
  printf("%d\n", a | b); // OR: 11 | 1010 | 0011 = 1011
  printf("%d\n", a ^ b); // XOR: 9 | 1010 | 0011 = 1001
}
