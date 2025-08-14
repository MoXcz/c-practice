/*
 * "Everything in C is a file".
 * This phrase is specially useful when understanding how IO write/read
 * functions work, as they operate on 'files'. 'stdin', 'stdout' and 'stderr'
 * are some examples of files that can be used to write to the screen, or to
 * capture input.
 */
#include <stdio.h>

int main(void) {
  // remove file
  remove("output.txt");
  FILE *fp;
  char s[1024];
  int linecount = 0;
  int x = 2;

  fp = fopen("output.txt", "w");

  // write to the file 'fp'
  fputc('b', fp);
  fputs("\nThis is some text\n", fp);
  fprintf(fp, "x = %d", x);

  // get 'string' from the file 'fp'
  while ((fgets(s, sizeof s, fp)) != NULL) {
    printf("%d: %s", ++linecount, s);
  }
  // note that it's good practice to always close files
  fclose(fp);
}
