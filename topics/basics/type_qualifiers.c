/*
 * Type Qualifiers
 * - 'const'. Useful in function definitions to hint to the compiler 'this value
 *   won't change'

 * - 'restrict'. Hint to the compiler that a value will only be accessed by a
 *   single pointer, otherwise undefined behavior happens (optimizations of
 *   write *   operations). *   This is useful for functions where it's
 *   GUARANTEED that a value will not be pointer to by another pointer:
int printf(const char * restrict format, ...);
void foo(int p[restrict]) // less common for array notation
                          //
 * - 'volatile'. Hints the compiler that a value might change behind its back,
 *   that is, outside the program. This kind of behavior only happens when
 *   working with hardware directly, as it so happens with microcontrollers.
 *   This prevents the compiler from trying to optimize a variable's value by
 *   storing it in a register and ensure that the memory address is always read
 */
int main(void) {
  int y = 5;
  const int x = 2; // value CANNOT change
  // x = 10; is not valid code

  const int *p = &x; // value of pointer points to CANNOT change
  int const *q = &x; // same as above
  p++;
  // *p = 30; is not valid code

  int *const m = &y; // value of pointer CANNOT change
  // m++; not valid code
  *m = 30; // value it points to CAN change

  // nothing can change; not the pointer or the value pointer points to
  const int *const n = &y;

  const int not_const_x = 20;
  // this will remove the 'const' above producing undefined behavior (DONT'T DO)
  int *remove_const_p = &not_const_x;

  // value will not be optimized
  volatile int *vol_p;
}
