#include <stdio.h>

struct square {
  int x;
  int y;
};

struct figure {
  struct square sq;
};

struct figures {
  struct square sqs[5];
};

/* using anonymous struct to 'typedef'd a 'figure'-named struct.
 * note that using 'figure' or 'struct figure' are, in essence, the same, so
 * it's mainly a question of preference in whether be explicit with the
 * 'struct' keyword or not
 */
typedef struct {
  struct square sq;
} figure;

// or, just quickly created the variables of the struct type, not really that
// useful tbh
struct {
  struct square sq;
} a;

int get_fig_area(struct figure figs) { return figs.sq.x * figs.sq.y; }

int main() {
  // initialize nested struct values
  struct figure figs = {
      .sq.x = 5,
      .sq.y = 4,
  };

  // iniitializing an array with multiple nested struct values
  struct figures figs2 = {
      .sqs =
          {
              [0].x = 5,
              [0].y = 4,
              [1] = {.x = 10, .y = 12},
          },
  };

  printf("%d", get_fig_area(figs));
}
