/* Data structure Alignment is a very important concept to understand the
 * phenomenon of this program (the sum of individual 'sizeof's it not the same
 * as the 'sizeof' the struct).
 *
 * The reason this padding is added and why all four values in 'padding' use 4
 * bytes (instead of the expected 1 for 'char') is because of how 'words' are
 * read by the CPU (this is typically due to x86 wizardry).
 *
 * If the CPU reads 4-byte words, then that 1 byte 'char' would hold also hold 3
 * bytes of the following 'int', making it so that the CPU now would have to
 * (presumably) read two bytes to get the whole 'int'; one for the 3 bytes
 * stored alongside the 'char' and a second time for the single byte left on the
 * next 4 bytes.
 *
 * Following this alignment would result in very weirdly store structs with
 * bytes spread haphazardly in different 4-byte words.
 *
 * Also not that because computers operate in binary (easy to record low/high
 * voltage on/off), alignment occurs in powers of two. A byte being 8 bits is
 * just convenience, as long as the size is a power of 2 a byte could be
 * whatever number (but it became common for bytes to be 8 bits, and there's no
 * really any reason to change it).
 *
 * This is also why something like:
 * #pragma pack(push, 3)
 * ... Defined structures
 * #pragma pack(pop)
 * Would not work, as it's trying to push the alignment value to be a non-binary
 * number, essentially expecting the computer to be able to interpret a value
 * out of 3 possible states (on/off/something else).
 *
 * See:
 *  https://stackoverflow.com/questions/11770451/what-is-the-meaning-of-attribute-packed-aligned4
 *  https://www.geeksforgeeks.org/c/structure-member-alignment-padding-and-data-packing/
 *  https://beej.us/guide/bgc/html/split/structs-ii-more-fun-with-structs.html
 *  https://stackoverflow.com/questions/11667181/why-does-padding-have-to-be-a-power-of-two
 */
#include <stddef.h>
#include <stdio.h>

struct padding {
  char a;
  int b;
  char c;
  int d;
};

typedef struct {
  char a;
  int b;
  char c;
  int d;

} __attribute__((packed, aligned(1))) padding;

int main(void) {
  printf("Expected size: %zu\n",
         sizeof(int) + sizeof(char) + sizeof(int) + sizeof(char));

  printf("a: %zu\n", offsetof(struct padding, a));
  printf("b: %zu\n", offsetof(struct padding, b));
  printf("c: %zu\n", offsetof(struct padding, c));
  printf("d: %zu\n", offsetof(struct padding, d));

  printf("Padded struct: %zu\n", sizeof(struct padding));

  // 10, the '__attribute__' thing above signals GCC (compiler-specific
  // addition) to not pad the 'struct'
  printf("Not padded struct: %zu\n", sizeof(padding));
}
