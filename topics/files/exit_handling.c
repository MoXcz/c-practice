// note that 'exit()` typically takes care of deleting temporary files, flushing
// IO and calling 'atexit' handlers
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

void print_exit(void) {
  if (puts("Exit succesful") == EOF) {
    exit(1);
  }
}

void print_q_exit(void) { printf("Exit succesful"); }

int main() {
  atexit(print_exit);          // call before 'exit'
  at_quick_exit(print_q_exit); // call before 'quick_exit'

  exit(0);       // exit, guarantees cleanup
  quick_exit(0); // exit, does not guarantee cleanup
  // force exit, different from above as there's no way to use callbacks as
  // above and it never cleans anything
  _Exit(0); // force exit, doesn't clean anything

  assert(5 > 3); // exit if false
  abort();       // raise SIGABRT
  return EXIT_SUCCESS;
}
