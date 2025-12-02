/*
Unicode in C is..., well *it* is. In short, because a `char` is an octet (8 bits
long), working with strings becomes troublesome (due to UTF-8 being variable in
length and UTF-16 and UTF-32 requiring more than an octet).

Due to this C has different method in `wchar.h` (and maybe `stdlib.h`) that
allow the use of *wide character strings*.

Here it's where is necessary to explain the fact that C strings are not *byte*
strings but *multi-byte* strings (abbreviated as `mbs` in functions). Instead of
these *byte* constrained functions *character* functions can be used instead
thanks to *wide character* strings (abbreviated as `wcs` in functions).

Beware that all conversion functions such as `wcstod` for `double` conversion
or `wcstombs`, use `mbstate_t` to keep track of the parsing required for the
conversion, making them not safe for multithreaded work. Variants with an `r`
can be used to use a *restartable* version that uses a `mbstate_t` allowing for
more control.

BUT, C as a language does not implement UTF-8, so all these shenanigans are just
so that it's possible to read and use characters, in the end it depends on the
system locale to work.

The macros `__STDC_UTF_16__` and `__STDC_UTF_32__` specify whether or not
`char16_t` and `char32_t` can use UTF-16 and UTF-32 encoding, respectively.
 */
#include <locale.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <wchar.h>

int main(void) {
  setlocale(LC_ALL, ""); // use system locale

  // normal multibyte strings (mbs onwards)
  char *mb_string = "The cost is \u20ac1.23"; // code point for €
  size_t mb_len = strlen(mb_string);

  // wide character string (wcs onwards)
  wchar_t wc_string[128];

  // conversion, it returns the num of chars for new wcs
  size_t wc_len = mbstowcs(wc_string, mb_string, 128);
  printf("multibyte: \"%s\" (%zu bytes)\n", mb_string, mb_len);
  printf("wide char: \"%ls\" (%zu characters)\n", wc_string, wc_len);

  mbstate_t mbs;               // manual conversion state
  memset(&mbs, 0, sizeof mbs); // initial state to 0

  // restartable versions could potentially fail while reading an invalid
  // character (non-restratable version manage this error themselves)
  // to avoid losing the original string, create a copy
  const char *invalid = mb_string;

  // same as above
  size_t wcr_len = mbsrtowcs(wc_string, &invalid, 128, &mbs);

  if (invalid == NULL) {
    printf("No invalid characters found\n");

    // Print result--note the %ls for wide char strings
    printf("multibyte: \"%s\" (%zu bytes)\n", mb_string, mb_len);
    printf("wide char: \"%ls\" (%zu characters)\n", wc_string, wc_len);
  } else {
    ptrdiff_t offset = invalid - mb_string;
    printf("Invalid character at offset %td\n", offset);
  }
}
