#include <stdint.h>
#include <stdio.h>

int main(void) {
  uint32_t num = 0x12345678;
  uint8_t *byte_ptr = (uint8_t *)&num;

  printf("Number (hex): 0x%X\n", num);
  printf("Number (dec): %d\n", num);
  printf("Pointer:      %lu\n", (unsigned long)&num);
  printf("Bytes in memory:\n");

  // print all bytes
  for (int i = 0; i < sizeof(num); i++) {
    printf("byte %d: 0x%02X\n", i, byte_ptr[i]);
  }

  /* if the most significant byte comes last, then the system is little endian
   * and the print statement starts printing at 0x78
   */
  if (byte_ptr[0] == 0x78) {
    printf("System is Little Endian\n");
  } else if (byte_ptr[0] == 0x12) {
    printf("System is Big Endian\n");
  } else {
    printf("Unknown Endianness\n");
  }

  return 0;
}
