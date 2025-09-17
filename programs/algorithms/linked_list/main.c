#include "linked_list.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ASSERT(c, m)                                                           \
  do {                                                                         \
    if (!(c)) {                                                                \
      fprintf(stderr, __FILE__ ":%d: assertion %s failed: %s\n", __LINE__, #c, \
              m);                                                              \
      exit(1);                                                                 \
    }                                                                          \
  } while (0)

int main(void) {
  struct List *list = initialize_list("A");

  append_node(list, "B");
  append_node(list, "C");
  print_list(list);

  ASSERT((strcmp(list->head->val, "A") == 0), "head should be 'A'");

  ASSERT((delete_node(list, "L") == 0), "Value should not exist");
  ASSERT((delete_node(list, "A") == 1), "Element should have been deleted");

  ASSERT((strcmp(list->head->val, "B") == 0), "head should be 'B'");

  ASSERT((delete_node(list, "B") == 1), "Element should have been deleted");
  ASSERT((delete_node(list, "A") == 0), "Value should not exist");
  ASSERT((delete_node(list, "C") == 1), "Element should have been deleted");
  ASSERT((delete_node(list, "C") == -1), "List should be empty");

  print_list(list);
}
