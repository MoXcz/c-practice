#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
  int a;
  time_t b;
  // unix-time
  b = time(NULL);
  // 55 in 2025
  printf("%ld\n", b / 60 / 60 / 24 / 365);
  srand(time(NULL));
  do {
    a = rand() % 100;
    printf("%d\n", a);
  } while (a != 69);
}
