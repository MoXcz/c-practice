// function take variable number of arguments, at least one?
// Varidadic function is

#include <stdarg.h> // <- need this
#include <stdio.h>

int custom_print(int num, const char *format, ...);

int add(int number_count, ...) {
  int total;
  va_list va; // variable argument list indeed

  // preprocessor magic that starts at the variable after 'number_count'
  va_start(va, number_count);

  for (int i = 0; i < number_count; i++) {
    int n = va_arg(va, int); // get next value, which in this case is an 'int'
    total += n;
  }

  va_end(va); // more preprocessor magic
  return total;
}

// In short: va_start(va, first_var) -> va_arg(va, type) -> va_end(va)
// There's also va_copy() to copy the current state of va

int main(void) {
  int x = add(5, 1, 2, 3, 4, 5);
  // this variadic function uses the '%d' things to count the number of args
  // and their type
  printf("%d\n", x);

  custom_print(0, "%d + %d = 10\n", 5, 5);
  custom_print(1, "%d + %d = 10", 6, 4);
}

// an example where this is used is the 'printf' function, more specifically,
// its 'v' variants:
// vprintf(), vfprintf(), vsprintf(), and vsnprintf()

int custom_print(int num, const char *format, ...) {
  va_list va;
  int rv;

  printf("%d: ", num);
  va_start(va, format);
  rv = vprintf(format, va);
  va_end(va);

  return rv;
}
