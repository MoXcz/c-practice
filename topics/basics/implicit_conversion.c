/*
 * Usual Arithmetic Conversions:
 * 1. Float? Everything is 'float'
 * 2. Otherwise just convert to big enough 'int'
 *
 * Void:
 * 1. It can be converted to anything.
 */
int main(void) {
  char a = 10, b = 10;
  int x = a + b; // implicit conversion ('int' promotion)

  void *p = &x;
  int *q = p; // implicit conversion of 'void *' to 'int'
}
