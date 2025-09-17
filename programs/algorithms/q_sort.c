#include <stdio.h>
#include <stdlib.h>

// a simple example struct
struct animal {
  char *name;
  int legs;
  int speed;
};

/* the 'compar' function accepts any type, but it converts it to an 'animal'
 * struct type. The reason the function must accept a 'void *' is becuse the
 * function signature for 'compar' defined in 'qsort' requires the type to be
 * 'void *'.
 * This allow the function to not assume anything about the type and to be
 * composable for any kind of comparison
 */
int compar(const void *animal1, const void *animal2) {
  // convert to the specific type
  const struct animal *a = animal1;
  const struct animal *b = animal2;

  // sort ascending
  if (a->speed > b->speed)
    // return negative if first argument 'a' is greater than the second 'b'
    return -1;
  if (a->speed < b->speed)
    // return positive if the first argument 'a' is less than the second 'b'
    return 1;
  // return 0 if they are equal
  return 0;
}

/* note*
 * To sort in descending order just invert the operation to return negative if
 * the first argument is less than the second, and positive if the first
 * argument is greater than the second
 */

int main() {
  struct animal list_animals[4] = {
      {.speed = 120, .legs = 4, .name = "Not bird"},
      {.speed = 10, .legs = 2, .name = "Definetly a bird"},
      {.speed = 500, .legs = 10, .name = "Monster"},
  };

  qsort(list_animals, 3, sizeof(struct animal), compar);

  // struct is now oredred
  for (int i = 0; i < 3; i++) {
    printf("Animal: %s\n", list_animals[i].name);
    printf("Speed: %d\n", list_animals[i].speed);
    printf("Legs: %d\n", list_animals[i].legs);
    printf("=====\n");
  }
  return 0;
}
