#include <stdio.h>

struct car {
  char *name;
  float price;
  int speed;
};

void increase_price(struct car *c);

int main(void) {
  struct car car = {.name = "Tm", .price = 12.8, .speed = 90};
  struct car a;
  a = car;
  printf("%p: %s\n", &a.name, a.name);
  printf("%p: %s", &car.name, car.name);
}

void increase_price(struct car *c) {
  // getting to the value in a struct with its pointer
  c->price += 10.0;
  (*c).price = 12.0;
}
