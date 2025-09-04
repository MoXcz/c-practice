#include "./add.h" // include from current directory
#include <stdio.h>

static int x; // this will not be visible in other source files
extern int b; // this is accesing an 'extern' variable (from another file)

int main(void) { printf("%d\n", add(1, 3)); }

/*
 * Produces a single executionable from multiple files:
 *   gcc -o out main.c add.c

 * Create the object files first, then link them together
 *   gcc -c main.c   creates 'main.o'
 *   gcc -c add.c    creates 'add.o'
 *   gcc -o out main.o add.o

 * This is where 'make' shines, as usually Makefiles contain 'clean' and 'run'
 * commands to build only the object files of file that changed ('run') and
 * clean them all ('clean') when a clean build is needed (build object files
 * of everything again).

 * The reason this is usfeul is because linking is fast, but compiling is slow,
 * so saving as much compiling as possible will always be better.
 */
