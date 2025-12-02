#include <locale.h>
#include <stdio.h>

int main() {
  // define the locale `locale -a`
  setlocale(LC_ALL, ""); // let system decide localization

  // get the struct containing the locale fields
  struct lconv *a = localeconv();

  // some locale fields
  printf("%d\n", *(a->currency_symbol)); // "" by default
  printf("%d\n", *(a->int_curr_symbol)); // "" by default
  printf("%d\n", a->frac_digits);
}
