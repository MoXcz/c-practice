#include <stdio.h>

// note that bit-fields need to be adjacent to one another to work (otherwise
// they are just plainly ignored by the compiler, no amount of pretty-pleases
// will work in that case)
struct bit_fields {
  int a : 3; // pretty-please be 3 bits long
  int b : 5; // pretty-please be 5 bits long
};

// useful for data that's not used directly (i.e. used by hardware)
struct foo {
  unsigned char a : 2;
  unsigned char : 5; // <-- unnamed bit-field
  unsigned char b : 1;
};

int main() {
  // this would originally be 8 bytes: 4 bytes per 'int', but the bit-field
  // makes it possible for both to be stored in a single 'int' (4 bytes)
  printf("%zu\n", sizeof(struct bit_fields));
  // becuase 'a' is 3 bits long its maximum value is 3 (range of 0-to-3, plus
  // sign bit)
  struct bit_fields test = {.a = 3, .b = 4};
  printf("%d\n", test.a);
}
