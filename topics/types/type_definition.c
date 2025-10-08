/*
 * One of the neat things about aliasing existing types is that changing them
 * latter becomes really easy: just change the 'typedef' declaration.
 * 'typedef int num;' -> 'typedef float num;'
 * but this can be easily done with vim so I guess its use in this area is
 * still not precisely known to me.
 * Some types that are better not aliased / 'typedef'd:
 * - Arrays:
 *   typedef int five_ints[5];
 *   five_ints x = {11, 22, 33, 44, 55}; it's not clear that it's an array
 * - Pointers:
 *   typedef int *intptr;
 *   int a = 10;
 *   intptr x = &a; it's not obvious that it's a pointer
 */

// define a 'new name' for an existing type (not really useful)
typedef int num;

struct animal {
  char *name;
  int n_legs;
};

// define an alias for 'struct animal' so that 'animal' can be used
typedef struct animal animal;

// do it all in a single sentence
typedef struct also_animal {
  char *also_name;
  int speed;
} also_animal;

// anonymous struct used with name 'pointer'; 'struct pointer' is not valid
typedef struct {
  int x, y;
} point;

int main(void) {
  num x = 5;

  // both work, 'typedef' is used to create an alias for the 'struct animal'
  struct animal dog;
  animal cat;

  also_animal bird;
}
