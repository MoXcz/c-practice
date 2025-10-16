#include <stdio.h>

struct rectangle {
  char width;
  int height;
};

int main(void) {
  struct rectangle x = {0x12, 0x12345678};
  // object representation should be iterated with an 'unsigned char'
  unsigned char *p = (unsigned char *)&x;

  // a similar kind of loop can be done for any pointer to get the 'object
  // representation' of any value
  for (size_t i = 0; i < sizeof x; i++) {
    if (i == 0)
      printf("x.width = ");
    if (i == 4) {
      printf("padding above (non-initialized, Odin does zero-initialize it)\n");
      printf("x.height starts at (78 litle endian, 12 big endian): \n");
    }
    printf("%02X\n", p[i]);
  }
}
