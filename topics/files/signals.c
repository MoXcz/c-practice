/*
Signals are, in short, just that 'signals'. They are Unix-specific (Windows uses
them but only as an interface for CLI applications, deep down they do not have
the same signal handling.

So when a signal is raised in a Unix system, its up to the OS, or the program,
to interpret it. Signals usually have a default behavior (`SIG_DFL`), but it can
be changed as seen below.

For the most part these are used by the OS to identify different events, and
programs can use this same interface to work alongside the OS in how to process
and how to interpret them.

Some signals:
- SIGABRT. Abnormal termination ('abort()' or 'assert()' use it)
- SIGTERM. Termination requested
- SIGILL. Illegal instruction
- SIGINT. Interruption
 */

#include <signal.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
  char s[32];

  // ignore signal termination (usually <C-c>)
  signal(SIGINT, SIG_IGN);
  // note that this produces undefined behavior when used with anything other
  // than `SIGINT` or `SIG_DFL`

  fgets(s, 32, stdin);
  if (puts(s) == EOF) {
    return EXIT_FAILURE;
  }
}
