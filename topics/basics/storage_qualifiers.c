/*
 * Storage-Class Specifiers

 * - 'auto'. The default value for block scope variables, meaning that the
 *   object has automatic storage duration (deallocated when exiting scope).

 * - 'static'. In block scope will make sure that there's a single instance of
 *   the variable, meaning that the value is shared between calls, which is
 *   initialized to 0 at a program's start. Just note that the variable makes
 *   concurrency-unsafe.
 *   In file scope on the other hand makes the variable only visible in the
 *   current file, meaning that it cannot be 'exported'.

 * - 'extern'. Refer to variables outside the current file. 'static' file-scoped
 *   variables cannot be 'extern'ed

 * - 'register'. Hints the compiler that this variable will be used many times,
 *   so its access should be made as fast as possible. Though modern compiler
 *   are already quite adept at this, so it's common to see it.
 *   And, this will not allow any pointers to the value (due to its values
 *   having higher chance to being saved in a register).
 *   It can also help avoid the removal of 'const' when refercing 'const'
 *   variables.
 *
 *   - '_Thread_local'. Make copy of the value, useful when working with
 *     multiple threads.
 */

#include <stdio.h>

extern int b; // reference variable that exists in another file

void counter(void) {
  static int a = 1; // a single initialization, so it's not 'rewritten'
  printf("%d\n", a);
  a++;
}

int main(void) {
  int a;
  // auto int a; same as above

  counter(); // 1
  counter(); // 2! The variable was not initialized again

  // will only hint to the compiler
  register int b;
  // int *p = &b; not valid
}
