/* A pointer is just a number that represents a memory address to a variable.
 * This means that a pointer itself is also a variable, whose value just happens
 * to be the memory address of another variable!

pp -> p -> x

 * There's really no limit to how deep the 'pointer to pointer' chain can get,
 * noting only that '*' can be used as many times as needed (i.e. '**pp'), but
 * '&' can only be used once (each pointing to the memory of the variable)
 *
 * Also note that 'int *const' applies to each level in the 'pointer to pointer'
 * chain. Meaning that 'int *const *' is not the same as 'int *const *const'.
 * The first case is a pointer to a constant pointer value, while the second is
 * a constant pointer to a constant pointer value.
 *
 * It's also important to note that an address obtained with '&' is the first
 * byte of the objects (multibyte values
 */

#include <stdio.h>

int main(void) {
  int x = 12;
  // pointer to an int
  int *p = &x;
  // pointer to a pointer to an int
  int **pp = &p;
  printf("%d %d\n", *p, **pp);

  printf("1. pp = Stored in: %p (Val: %p) -> \n2. p  = Stored in: %p (Val: %p) "
         "-> \n3. x  = Stored in: %p (Val: %d)",
         &pp, pp, &p, p, &x, x);

  int *const a = &x; // the value of 'a' cannot change
  int **b = &a;      // this discards the 'const' qualifier above
  // this does not discard the 'const' qualifier, as it respects it
  int *const *c = &a;
  // this makes the pointer 'd' to be constant, just as 'a' is
  int *const *const d = &a;
}

void *my_memcpy(void *dest, const void *src, size_t n) {
  const unsigned char *s = src;
  unsigned char *d = dest;

  while (n-- > 0) // For the given number of bytes
    *d++ = *s++;  // Copy source byte to dest byte

  // Most copy functions return a pointer to the dest as a convenience
  // to the caller

  return dest;
}
