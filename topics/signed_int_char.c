/*
 * 'unsigned' variants allow for more permutation of possible numbers by not
 * using, roughly, half of the possible numbers for +/- representations.
 *
 * 1 byte != 8 bits; the sequence of 8 bits it's an octet.
 * The size of a byte is actually 'implementation-dependent', meaning that it
 * can change. Though, this change will basically never happen in the modern
 * world, as this flexibility is passed down from the early days of computers.
 *
 * Two's Component:
 * - Signed range: -2^(n - 1) to 2^(n-1) - 1
 * - Unsigned range: 0 to 2^(n) - 1
 *
 * 'char' (1 byte):
 * - Signed range: -128 to 127
 * - Unsigned range: 0 to 255
 *
 * 'char' is actually a 1-byte 'int' (remember! The size of a byte is
 * implementation-dependent). This means that operations like '+' are valid, for
 * as long as they don't exceed 'char' small range
 *
 * Also, 'char' character representation (e.g. 'A') is defined (usually) by the
 * ASCII character set (another common option is Unicode, but here's a list:
 * https://en.wikipedia.org/wiki/List_of_information_system_character_sets)
 */
int main(void) {
  int a;          // signed
  signed int b;   // signed
  signed c;       // signed, "shorthand" for "int" or "signed int", rare
  unsigned int d; // unsigned
  unsigned e;     // unsigned, shorthand for "unsigned int"

  char c_a;          // Could be signed or unsigned (depends on the compiler)
  signed char c_b;   // Definitely signed
  unsigned char c_c; // Definitely unsigned
}
