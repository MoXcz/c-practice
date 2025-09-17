/*
 * Preprocessing is basically another language built on top of C that gets
 * 'preprocessed' into the actual C code that gets compiled
 * Other macro similar to '#else' is '#elifdef', which is essentially an alias
 * for '#if defined'
 */
#include <stdio.h>

// 'macro' that gets 'expanded' into 3.1416
#define PI 3.1416
#define PRINT
//  #define HELLO ; if this is defined, the 'Hello, World!' doesn't get printed
#define HP 0

// '#undef' undefines a macro
#define TMP 8080
#undef TMP
// TMP cannot be used any longer

int main(void) {

#ifndef HELLO
  printf("Hello, World!\n");
#endif /* ifndef HELLO */

#ifdef PRINT
  printf("%f\n", PI);
#else
  printf("%f", 3.1416);
#endif /* ifdef PRINT */

#if HP == 0
  printf("0\n");
#elif HP == 1
  printf("1");
#else
  printf("other");
#endif

#if defined HI
  printf("other");
#elif defined PRINT
  printf("other\n");
#endif

  // some already defined macros
  printf("This function: %s\n", __func__);
  printf("This file: %s\n", __FILE__);
  printf("This line: %d\n", __LINE__);
  printf("Compiled on: %s %s\n", __DATE__, __TIME__);
  printf("C Version: %ld\n", __STDC_VERSION__);
}
