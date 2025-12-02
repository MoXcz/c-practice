// VLAs are optional in C11+, but were mandatory on C99. This macro determines
// whether or not VLAs are present
#if __STDC_NO_VLA__ == 1
// VLAs not present! (though GCC nor Clang define this macro)
#endif

#include <stdio.h>
#include <stdlib.h>

int main(void) {
  int n;
  char buf[32];

  printf("Enter a number: ");
  fflush(stdout);
  fgets(buf, sizeof buf, stdin);
  n = strtoul(buf, NULL, 10);

  // the size of 'vla' is not known until the value of 'n' is determined at
  // runtime.
  int vla[n];
  int v[10];

  for (int i = 0; i < n; i++)
    vla[i] = i * 10;

  for (int i = 0; i < n; i++)
    printf("v[%d] = %d\n", i, vla[i]);
}

// Note that the use of VLAs is banned from the Linux kernel, and should be in
// most programs where there's no need to use a VLA (variabl-lenght arrays).
// The example above is a good example of when NOT to use it, as the size of the
// buffer is maxed at 32, there's little reason to dinamically allocate the size
// of 'vla'.
