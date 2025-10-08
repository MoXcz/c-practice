/*
 * Type punning is a topic related to union types, due to them enabling them,
 * promoting them even. A union type will have different 'interpretations' that
 * can be written and read to, this is type punning.
 *
 * A union enables a method for type conversion that it's outside the type
 * system of C.
 *
 * Note: Unlike most modern programming language (e.g., Python, JavaScript)
 * structs and unions are not passed as a reference, but as a value, this "pass
 * by reference' needs to be explicit which enables things like:

printf("%d %d\n", f().x, f().y);

 * Where each function call returns a copy of the value.
 */
#include <stdio.h>

// all values ('interpretations') of the type start at the same place in memory
union union_types {
  int a;
  float b;
  char c;
};

struct a {
  int x;
};

struct b {
  int x;
};

// the same concept applies to union 'structs' the initial sequences are the
// same in both ('int x' is found at the beginning on both, resulting in the
// same initial memory arrangement)
union union_struct {
  struct a sa;
  struct b sb;
};

// this can be implemented using some sort of 'common' type that is shared in
// order to check if that first value in the sequence is a 1, 2, 3, etc.,
// depending on the value (also with some '#define' to prevent magic numbers)
void print_animal(union union_struct *x) {
  switch (x->sa.x) {
  case 1:
    printf("Antelope: loudness=%d\n", x->sa.x);
    break;

  case 2:
    printf("Octopus : sea_creature=%d\n", x->sb.x);
    break;

  default:
    printf("Unknown animal type\n");
  }
}

// anonymous 'structs' can also be used inside union types.
union union_unnamed_struct {
  struct {
    int x;
  };

  struct {
    int y;
  };
};

int main(void) {
  union union_types x;
  // 4!, this is not a 'struct' it's size depends on the biggest one
  printf("%zu\n", sizeof(x));
  x.a = 2;
  // the results may vary due to data being interpeted both as an 'int'
  printf("%d\n", x.a);
  // and a 'float'
  printf("%f\n", x.b);

  x.b = 3.1459;
  // note that this variable IS NOT a 'float' but it's assuming that it is
  float *x_p_float = (float *)&x;

  printf("%f\n", x.b);
  // and because it is in fact a 'float' then it's printed as a float
  printf("%f\n", *x_p_float);

  // the 'reinterpretation' can then be 'reinterpreted' into its original union
  // type
  union union_types *y = (union union_types *)&x_p_float;
}

/*
 * See: https://en.wikipedia.org/wiki/Type_punning
 *
 * "type punning is any programming technique that subverts or circumvents the
 * type system of a programming language in order to achieve an effect that
 * would be difficult or impossible to achieve within the bounds of the formal
 * language."

struct sockaddr_in sa = {0};
int sockfd = ...;
sa.sin_family = AF_INET;
sa.sin_port = htons(port);
bind(sockfd, (struct sockaddr *)&sa, sizeof sa);

 * This is an example of type punning due to interpreting a 'sockaddr_in' as a
 * 'sockaddr' (note that this works due to both of them having the exact same
 * memory layout, misusing them could become punning indeed.
 */
