/*
 * Implementation of a single-linked list
 *  - Append O(1)
 *  - Index O(n)
 *  - Delete
 *    - Beginning or End: O(1)
 *    - Anywhere else: O(n)
 *  - Search O(n)
 * Note that the whole pointer shbang could be changed to just reassign the
 * value of 'head' by returning the changed head in each function, which would
 * mean that the function signature of most functions would be
 * 'struct Node name(struct Node head)'
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
  char *val;
  struct Node *next;
};

struct Node *initNode(char *value) {
  size_t len = strlen(value) + 1;
  char *val = malloc(len);
  memcpy(val, value, len);

  struct Node *new = (struct Node *)malloc(sizeof(struct Node));
  new->val = val;
  new->next = NULL;

  return new;
}

void append(struct Node **head, char *value) {
  if (*head == NULL) {
    *head = initNode(value);
    return;
  }

  // TODO: this is O(n), to avoid doing this it could be added a value to the
  // Node struct that points to the end
  struct Node *curr = *head;
  while (curr->next != NULL) {
    curr = curr->next;
  }

  struct Node *new = initNode(value);
  curr->next = new;
}

// TODO: better return an integer when the delete could not be performed, let
// the caller manage that scenario (delete 'printf's)
void delete(struct Node **head, char *value) {
  if (*head == NULL) {
    printf("Error: The list is empty\n");
    return;
  }

  struct Node *tmp = *head; // copy of 'head'
  // 'strcmp' return 0 if the strings/memory are the same
  if (strcmp(tmp->val, value) == 0) {
    struct Node *to_delete = tmp;
    *head = tmp->next;

    free(to_delete->val);
    free(to_delete);
    return;
  }

  while (tmp->next != NULL) {
    if (strcmp(tmp->next->val, value) == 0) {
      break;
    }
    tmp = tmp->next;
  }
  // there should be a better way to handle this...
  if (tmp->next == NULL && strcmp(tmp->val, value) != 0) {
    printf("Error: %s does not exist\n", value);
    return;
  }

  // save node to delete in order to free allocated memory of 'val'
  struct Node *to_delete = tmp->next;
  // remove current 'tmp->next', which is 'value'
  tmp->next = tmp->next->next;

  free(to_delete->val);
  free(to_delete);
}

void search(struct Node **head, char *value) {
  struct Node *tmp = *head; // copy of 'head'
  if (*head == NULL) {
    printf("Error: The list is empty\n");
    return;
  }

  int i = 0;
  while (tmp != NULL) {
    if (strcmp(tmp->val, value) == 0) {
      break;
    }
    tmp = tmp->next;
    i++;
  }
  if (tmp == NULL) {
    printf("Error: %s does not exist\n", value);
    return;
  }
  printf("Value '%s' found at index %d\n", value, i);
}

void printTree(struct Node *head) {
  struct Node *tmp = head;

  while (tmp != NULL) {
    printf("%s -> ", tmp->val);
    tmp = tmp->next;
  }
  printf("NULL\n");
}

int main(void) {
  struct Node *head = initNode("A");
  append(&head, "B");
  append(&head, "C");
  append(&head, "D");
  search(&head, "A");
  search(&head, "B");
  search(&head, "C");
  search(&head, "D");
  search(&head, "N");

  printTree(head);
  delete(&head, "F");
  delete(&head, "D");
  delete(&head, "A");
  delete(&head, "B");
  delete(&head, "C");

  append(&head, "C");
  append(&head, "A");

  printTree(head);
}
