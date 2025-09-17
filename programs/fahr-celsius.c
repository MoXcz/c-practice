#include <stdio.h>
// Program that prints a Fahrenheit-Celsius table

#define LOWER -20 // Lower limit of table
#define UPPER 150 // Upper limit of table
#define STEP 10   // Step size

float fahrenheit_to_celsius(float fahrenheit_tmp);
float celsius_to_fahrenheit(float celsius_temp);

int main() {
  float fahrenheit_temp, celsius_temp;
  float lower_limit_temp, upper_limit_temp, step_size;

  lower_limit_temp = 0;
  upper_limit_temp = 300;
  step_size = 20;

  printf("Fahrenheit-Celsius Table %.2f to %.2f\n", lower_limit_temp,
         upper_limit_temp);
  printf("--------------------------------------\n");
  fahrenheit_temp = lower_limit_temp;

  while (fahrenheit_temp <= upper_limit_temp) {
    celsius_temp = fahrenheit_to_celsius(fahrenheit_temp);
    printf("Fahrenheit: %3.0f\tCelsius: %6.1f\n", fahrenheit_temp,
           celsius_temp);
    fahrenheit_temp = fahrenheit_temp + step_size;
  }

  printf("\n");
  printf("Fahrenheit-Celsius Table %d to %d\n", UPPER, LOWER);
  printf("--------------------------------------\n");
  for (celsius_temp = UPPER; celsius_temp >= LOWER;
       celsius_temp = celsius_temp - STEP) {
    printf("Celsius: %3.0f\tFahrenheit: %6.1f\n", celsius_temp,
           celsius_to_fahrenheit(celsius_temp));
  }
}

float fahrenheit_to_celsius(float fahrenheit_temp) {
  float celsius_temp;
  celsius_temp = (5.0 / 9.0) * (fahrenheit_temp - 32.0);
  return celsius_temp;
}

float celsius_to_fahrenheit(float celsius_temp) {
  float fahrenheit_temp;
  fahrenheit_temp = (9.0 / 5.0) * (celsius_temp + 32.0);
  return fahrenheit_temp;
}
