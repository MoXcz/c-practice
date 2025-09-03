/*
 * An address can be informally imagined as a huge array in virtual memory.
 * Meaning that it does not interface directly with the computer memory, but
 * uses an extra layer that manages this interaction
 */
#include <stdio.h>
void increment(int *p);

int main(void) {
  int value = 2;
  // a pointer is a variable that stores the 'address' of another variable
  int *p = &value;
  printf("%d\n", value);

  // pointers can be used to modify the value in the 'address'
  increment(p);
  printf("%d\n", value);

  size_t a = sizeof(p);
  // usually 64 bits
  printf("%zu", a);

  // 'NULL' pointers cannot be dereferenced
  p = NULL;
  if (p != NULL) {
    *p = 12;
  }
}

void increment(int *p) { *p += 1; }
