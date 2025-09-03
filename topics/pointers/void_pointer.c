/*
 * It's important to understand that the size of 'int' changes depending on the
 * system, so specifying its size with the 'sizeof' makes sure that no matter
 * the machine, it always produces the same result
 *
 * The way 'memcpy' works under the hood is that it uses a 'void *' to point to
 * any kind of data (without it a 'memcpy' function for every type would be
 * needed
 *
 * Just note that a 'void *':
 * - cannot do pointer arithmetic
 * - cannot be dereferenced
 * - cannot use the arrow operator, since it’s also a dereference
 * - cannot use array notation, since it’s also a dereference, as well
 * Why? Because the point of 'void *' is that the size is not known, and any
 * dereference operation relies on the size of the object
 *
 * So 'void *' ends up being used in situations where a generic type is needed
 * and then converted to a different type before used.
 *
 * Data is always in bytes. The data type just tells the computer to 'interpret
 * it differently)
 */
#include <stdio.h>
#include <string.h>

void *my_memcpy(void *dest, void *src, int byte_count) {
  // convert 'void *' to 'char *'
  char *s = src, *d = dest;

  while (byte_count--) {
    *d++ = *s++;
  }

  return dest;
}

int main(void) {
  char s[] = "Hello";
  void *t = s;
  char s_copy[100];

  // size specified directly because 'sizeof(char)' is always 1.
  // So 5 'char's + '\0' = 6.
  my_memcpy(s_copy, t, 6); // 'memcpy' would also work
  // Note that even though 't' is 'void *', there's no error, because 'memcpy'
  // is copying the bytes, not their interpretation

  printf("%s\n", s_copy);

  int nums[] = {1, 2, 3, 4, 5};
  int nums_copy[3];

  // copy only the first three 'int's
  memcpy(nums_copy, nums, sizeof(int) * 3);
  printf("%d", nums_copy[0]);
}
