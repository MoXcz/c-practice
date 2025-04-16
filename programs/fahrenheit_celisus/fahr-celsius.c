#include <stdio.h>
// Program that prints a Fahrenheit-Celsius table

float fahrenheit_to_celsius(float fahrenheit_tmp);

int main() {
  float fahrenheit_temp, celsius_temp;
  float lower_limit_temp, upper_limit_temp, step_size;

  lower_limit_temp = 0;
  upper_limit_temp = 300;
  step_size = 20;

  printf("Fahrenheit-Celsius Table %.2f - %.2f\n", lower_limit_temp,
         upper_limit_temp);
  printf("--------------------------------------\n");
  fahrenheit_temp = lower_limit_temp;

  while (fahrenheit_temp <= upper_limit_temp) {
    celsius_temp = fahrenheit_to_celsius(fahrenheit_temp);
    printf("Fahrenheit: %3.0f\tCelsius: %6.1f\n", fahrenheit_temp,
           celsius_temp);
    fahrenheit_temp = fahrenheit_temp + step_size;
  }
}

float fahrenheit_to_celsius(float fahrenheit_temp) {
  float celsius_temp;
  celsius_temp = (5.0 / 9.0) * (fahrenheit_temp - 32.0);
  return celsius_temp;
}
