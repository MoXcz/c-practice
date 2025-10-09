#include <stdio.h>
#include <threads.h>

void countdown(void);

int main(void) {
  // most common escape sequences (backslash)
  printf("\' \" \\ \\n \n \t");

  // alert
  printf("Hi!\a\n");
  // backspace
  printf("Hi! \ba\n");
  // formfeed: next 'page', though it can behave like '\v' on modern systems
  printf("Hi! \fa\n");
  // vertical tab
  printf("Hi! \va\n");
  // return: beginning of current line
  printf("Hi! \ra\n");

  // this trigraph may be converted to'|', to avoid that using '\?' might be
  // necessary (run with `gcc -o t espace_sequences.c -trigraphs && ./t`)
  printf("Trigraphs??!\n");
  printf("Trigraphs?\?!\n");
  printf("Emoji: \u2620\n"); // this is an emoji (unicode)

  printf("\xE2\x80\xA2 Bullet\n");
  printf("\u2022 Bullet as well\n");
  countdown();
}

void countdown(void) {
  for (int i = 10; i >= 0; i--) {
    // the '\r' helps in printing the text on the same line
    printf("\r%d \b", i);
    fflush(stdout); // flush terminal (do not wait for '\n')
    // Sleep for 1 second
    thrd_sleep(&(struct timespec){.tv_sec = 1}, NULL);
  }

  printf("\rEnd!\n");
}
