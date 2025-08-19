/*
 * Note that pointer arithmetic only applies ON THE SAME ARRAY. Trying to
 * operate with these operators when working with spaces of memory that are not
 * assigned next to each other (as it so happens with arrays) produces undefined
 * behavior
 *
 * For all 'b' values under the same array:
 * ->  a[b] == *(a + b)
 * 'b' in this case is the 'jumps' or 'displacements' needed to get a value in
 * the array
 * Under the Spec of C11 §6.5.2.1¶2:
 * ->  E1[E2] is identical to (*((E1)+(E2)))
 * These two are equivalent:
 *  int my_strlen(char *s)
 *  int my_strlen(char s[])
 */
#include <stdio.h>

int p_strlen(char *s) {
  char *p = s;

  while (*p != '\0') {
    p++; // go to the next element in the array of 'char's
  }
  return p - s;
}

int main(void) {
  int arr[5] = {11, 22, 33, 44, 55};
  int *p;
  p = arr;

  for (int i = 0; i < 5; i++) {
    // note that 'arr' could also be used here, because an array is always just
    // a pointer to the first element
    printf("%d\n", *(p + i));
  }
  // the only excepion to the interchange above is: *(arr++).
  // you cannot modify an array variable to point to a different address

  printf("=========\n");
  // the same can be done backwards
  for (int i = 0; i < 5; i++) {
    printf("%d\n", *((p + 4) - i));
  }

  printf("=========\n");
  // strings are also arrays, so the same principle of arithmetic applies
  printf("Length of 'Hello World': %d", p_strlen("Hello World"));
}
