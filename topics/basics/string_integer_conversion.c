/*
 * Conversions from strings to numbers use a family of functions called 'atoi'
 * (ascii to integer, though in modern times it's not really only ascii anymore)
 * and 'strtol' (string to long)

atoi  String to int
atof  String to float
atol  String to long int
atoll String to long long int

strtol   String to long int
strtoll  String to long long int
strtoul  String to unsigned long int
strtoull String to unsigned long long int
strtof   String to float
strtod   String to double
strtold  String to long double

 * 'strtol' can be used with different bases (base 2, 8, 10, etc.)
 */
#include <stdio.h>
#include <stdlib.h>

int main(void) {
  float pi = 3.14159;
  float pi_copy;
  char pi_string[32];
  char *s = "34x90"; // hex number
  char *err = NULL;

  sprintf(pi_string, "%f", pi);
  // snprintf(pi_string, 10, "%f", pi); the same, but limiting the number of
  // bytes

  printf("%s\n", pi_string);
  pi_copy = atof(pi_string);
  printf("%f\n", pi_copy);

  // it's better to use the 'strtol' family of functions because they behavior
  // is more defined (0 on error, and the second parameter can be a 'char *' for
  // error msg
  float x = strtof(pi_string, NULL);
  printf("%f\n", x);

  unsigned long int ul_x =
      strtoul(s, &err, 10); // error will have a value != '\0'
  if (*err == '\0') {
    printf("Success! %lu\n", ul_x);
  } else {
    printf("Partial conversion: %lu\n", ul_x);
    printf("Invalid character: %c\n", *err);
  }
}
