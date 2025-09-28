#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* 'malloc' can be used to allocate more than those 8 hardcoded bytes, but only
 * because 'data' is at the end of the 'struct'. See this:
 * ┌────────────────────────────────────────────────────────┐
 * │ len │ data │ overflow or malloc │ true overflow here   │
 * └──────────────────┬─────────────────────────────────────┘
 *                    ▼
 * because we already allocated memory with 'malloc', this 'overflow' does not
 * really affect the result, as part of that overflow is conserved by 'malloc'
 * Still, accessing an out-of-bounds index is still undefined behavior, so do
 * not do this, even if it seems appealing to do so
 */
struct len_string {
  int len;
  char data[8];
};

// This is preferable to the shenanigans performed above (part of C99(
struct len_string2 {
  int len;
  char data[]; // incomplete type (still has to be the last member of the strut)
};

struct len_string2 *len_string_from_c_string(char *s) {
  int len = strlen(s);

  // reserve the extra 'len' space for the defined 'struct'
  struct len_string2 *ls = malloc(sizeof *ls + len);
  ls->len = len;
  memcpy(ls->data, s, len);

  return ls;
}

int main(void) {
  struct len_string2 *str = len_string_from_c_string("Hello, World!");
  printf("%s\n", str->data);
  printf("%d\n", str->len);
}
