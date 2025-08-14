/*
 * Binary files refer to files that store 'bytes' directly without any
 * interpretation this results in files with apparent nonsense.
 * To properly read the files a hex decoder (such as 'hexdump -C <file>') can
 * be used to get the hexadecimal interpretation of the bytes.
 */
#include <stdio.h>

int main(void) {
  FILE *fp;
  // array to store 'bytes' (each unsigned char is 8 bits)
  unsigned char bytes[6] = {12, 64, 91, 1, 2, 3};
  // to store the 'bytes' read
  unsigned char c;

  // open file to write in binary 'wb'
  fp = fopen("output.bin", "wb");
  fwrite(bytes, sizeof(char), 6, fp);

  fclose(fp);

  // open file to read in binary 'rb'
  fp = fopen("output.bin", "rb");
  while (fread(&c, sizeof(char), 1, fp) > 0)
    printf("%d\n", c);

  fclose(fp);
}
