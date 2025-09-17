/*
 * Implementation of a single-linked list
 *  - Append O(1)
 *  - Index O(n)
 *  - Delete
 *    - Beginning or End: O(1)
 *    - Anywhere else: O(n)
 *  - Search O(n)
 * Note that the whole pointer shbang could be changed to reassigning the
 * value of 'head' by returning the changed head in each function, which would
 * mean that the function signature of most functions would be
 * 'struct Node name(struct Node head)'
 */
#include "linked_list.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct List *initialize_list(char *value) {
  struct List *list = (struct List *)malloc(sizeof(struct List));
  struct Node *new = create_node(value);

  list->head = new;
  list->tail = new;

  return list;
}

struct Node *create_node(char *value) {
  size_t len = strlen(value) + 1;
  char *val = malloc(len);
  memcpy(val, value, len);

  struct Node *new = (struct Node *)malloc(sizeof(struct Node));
  new->val = val;
  new->next = NULL;

  return new;
}

void append_node(struct List *list, char *value) {
  struct Node *new = create_node(value);
  if ((list->head) == NULL) {
    list->head = new;
    list->tail = new;
  } else {
    list->tail->next = new;
    // update 'tail' to new final node
    list->tail = new;
  }
}

/*
 * Search for an element before the one being searched for:
 * A -> B -> C
 *      |
 * Stop at 'A' so that 'A.next' can be changed to 'C'
 *
 * returns:
 * - '-1' when is empty
 * - '0' when element does not exist
 * - '1' when elements was deleted
 */
int delete_node(struct List *list, char *value) {
  struct Node *tmp = list->head;
  if (tmp == NULL) {
    return -1;
  }

  // 'strcmp' return 0 if the strings/memory are the same
  if (strcmp(tmp->val, value) == 0) {
    list->head = list->head->next;

    free(tmp->val);
    free(tmp);
    return 1;
  }

  while (tmp->next != NULL) {
    if (strcmp(tmp->next->val, value) == 0) {
      break;
    }
    tmp = tmp->next;
  }
  // there should be a better way to handle this...
  if (tmp->next == NULL && strcmp(tmp->val, value) != 0) {
    return 0;
  }

  // save node to delete in order to free allocated memory of 'val'
  struct Node *to_delete = tmp->next;
  // remove current 'tmp->next', which is 'value'
  tmp->next = tmp->next->next;

  free(to_delete->val);
  free(to_delete);
  return 1;
}

void searchNode(struct List *list, char *value) {
  struct Node *head = list->head; // copy of 'head'
  if (head == NULL) {
    printf("Error: The list is empty\n");
    return;
  }

  int i = 0;
  while (head != NULL) {
    if (strcmp(head->val, value) == 0) {
      break;
    }
    head = head->next;
    i++;
  }
  if (head == NULL) {
    printf("Error: %s does not exist\n", value);
    return;
  }
  printf("Value '%s' found at index %d\n", value, i);
}

void print_list(struct List *list) {
  struct Node *tmp = list->head;

  while (tmp != NULL) {
    printf("%s -> ", tmp->val);
    tmp = tmp->next;
  }
  printf("NULL\n");
}
