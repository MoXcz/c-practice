#ifndef LINKED_LIST_H
#define LINKED_LIST_H

struct Node {
  char *val;
  struct Node *next;
};

struct List {
  struct Node *head;
  struct Node *tail;
};

struct Node *create_node(char *value);
struct List *initialize_list(char *value);
void append_node(struct List *list, char *value);

// returns:
// - '-1' when is empty
// - '0' when element does not exist
// - '1' when elements was deleted
int delete_node(struct List *list, char *value);
void search_node(struct List *list, char *value);
void print_list(struct List *list);

#endif // !LINKED_LIST_H
