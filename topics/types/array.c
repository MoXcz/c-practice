#include <stdio.h>

void double_all(int *a, int len) {
  for (int i = 0; i < len; i++) {
    a[i] *= 2;
  }
}

int main(void) {
  int a[12] = {1, 2, 3, 4, 5, 6, 7, 8};
  a[0] = 2;
  a[1] = 4;
  // a is a pointer to the first element in the array
  printf("%d\n", *(a + 1));

  /* the program does not store any information about the lenght of the array
   * but its size can be determined (unless it's a struct with padding) by
   * dividing the 'sizeof' the array by the 'sizeof' the types of the element
   * in the array
   */
  printf("%ld\n", sizeof(a) / sizeof(int));
  // this would return the 'sizeof' the array given 12 'double'-type elements
  printf("%ld\n", sizeof(double[12]));

  int *p;
  p = a;

  /* passing an array actually just passes a copy of the pointer to the first
   * element, which also means that the 'sizeof' operator would no longer work
   * (it would return the size of the pointer), which is of usually of 64 bits
   */
  double_all(a, sizeof(a) / sizeof(int));

  /* because 'p' is a pointer to 'a', and 'a' is already a pointer to the first
   * element in the array, 'p' now can be used as 'a'
   */
  printf("%d\n", *(p + 1));

  for (int i = 0; i < 6; i++) {
    printf("\n");
    for (int j = 0; j < 6; j++) {
      (i == j) ? printf("1  ") : printf("0  ");
    }
  }
}
