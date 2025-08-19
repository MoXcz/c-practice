/*
 * Memory alignment specifies values pointers need to start with (multiple of)
 * in order for memory access to be fast and efficient. This value depends on
 * the system and functions such as 'malloc', 'calloc', and 'realloc' all return
 * pointers that are already optimized for these purposes.
 *
 * But, there are times (usually in embedded programming) when there's a
 * specific memory alignment that's preferred.
 *
 * The alignment must be a number in the power of 2: 2, 4, 16, 32, 64
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
  // allocate 256 bytes in a 64-boundary
  char *p = aligned_alloc(64, 256);
  strcpy(p, "Hello, World");

  printf("%p\n", p);

  free(p);
}

/*
 * 'realloc' doesn't have any guarantees in memory alignment, so reallocating
 * memory allocated with 'aligned_alloc' it's not as easy as just using
 * 'realloc'.
 */
void *aligned_realloc(void *ptr, size_t old_size, size_t alignment,
                      size_t size) {
  char *new_ptr = aligned_alloc(alignment, size);

  if (new_ptr == NULL)
    return NULL;

  size_t copy_size = old_size < size ? old_size : size; // get min

  if (ptr != NULL)
    // 'memcpy' will preserve memory alignment, as it literally copies the
    // values as they are in memory
    memcpy(new_ptr, ptr, copy_size);

  free(ptr);

  return new_ptr;
}

// Either way, it's best to avoid having to reallocate memory allocated with a
// specific alignment.
