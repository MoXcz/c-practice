/*
 * 'Wrapping' happens with 'unsigned' and 'signed' numbers due to values being
 * dropped, that is, a 16-bit number '0x1234' looks like '0x0034' as an 8-bit
 * number, which seems like it 'dropped' the high-order part (it 'wraps')
 *
 * 'true' is 1, anything else is 'false'
 */
#include <stdbool.h>
#include <stdio.h>
int main(void) {
  char a = '5';
  int x = 5;
  // ascii code of '0' is 48, so add/subtract that to any ascii number from 0 to
  // 9 and get its value as a char/integer
  printf("%d\n", a - '0'); // '5' as integr
  printf("%d\n", x + '0'); // 5 as char
}
