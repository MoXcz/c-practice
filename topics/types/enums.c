#include <stdio.h>

// generally preferred over '#define' statements when the values can be integers
enum enum_type {
  ZERO, // start counting at 0 (similar to '= iota' in Go)
  ONE,
  TWO,
  FOUR = 4,
  FIVE, // value is 5
};

// it can also be aliased (though I do like the explicitness of 'enum <name')
typedef enum enum_type enum_t;

int main(void) {
  // the debugger actually knows 'ONE' is an 'enum', while with '#define' the
  // debugger all that it sees is its literal values
  printf("%d\n", ONE);

  enum enum_type a = FIVE;
  a == TWO ? printf("%d", TWO) : printf("Not a TWO: %d", a);
}
