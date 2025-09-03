/*
 * Important to note that allocated memory in the 'heap' is filled with garbage
 * if not treated. 'Heap' is a term used to refer to memory that lives beyond
 * its local scope, referred to as the 'stack' ('int' and 'char' are allocated
 * in the 'stack').
 *
 * A common pattern to allocate memory is to initialize the pointer to NULL and
 * 'realloc' it without needing to check the first 'malloc'. For the rest of
 * 'realloc's is convention to double the last size and to work on number in the
 * power of 2:
 *   - 2 -> 4 -> 16 -> 32 -> 64...
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
  int *p = malloc(sizeof(int));
  // allocation functions return 'NULL' if the memory could not be allocated
  if (p == NULL) {
    printf("Error allocating memory\n");
  }

  // and a pointer to the allocated space in memory if the allocation worked
  *p = 12;
  printf("%d\n", *p);
  free(p);
  // free(p); -> ERROR!
  // printf("%d", *p); -> Undefined behavior

  int *s = malloc(256); // allocate 256 bytes, which is the same as 256 'char's
  memset(s, 0, 256 * sizeof(char)); // set all 256 bytes with '0's
  s[0] = 54;          // set first value in the array of 'int's to '54'
  printf("%d\n", *s); // '54'

  // same as 'malloc', except that it initializes memory to '0'
  int *q = calloc(10, sizeof(int));
  // reallocate memory; depending on the size it may copy the memory over to a
  // new space in memory
  int *new_q = realloc(q, 5 * sizeof(int));
  if (new_q == NULL) {
    printf("Error reallocating memory\n");
    return 1;
  }

  // memory succesfully allocated; there's no need to free 'new_q', it points to
  // the same space in memory
  p = new_q;

  int *x;
  // all in the same line
  if ((x = malloc(sizeof(int) * 10)) == NULL) {
    printf("Error allocating 10 ints\n");
    // handle the case where no memory could be allocated
  }
  return 0;
}
